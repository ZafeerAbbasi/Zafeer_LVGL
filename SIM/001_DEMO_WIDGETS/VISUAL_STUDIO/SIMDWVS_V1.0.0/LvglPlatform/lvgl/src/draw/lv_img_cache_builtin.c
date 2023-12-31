/**
 * @file lv_img_cache_builtin.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_img_cache.h"
#include "lv_img_cache_builtin.h"
#include "lv_img_decoder.h"
#include "lv_draw_img.h"
#include "../tick/lv_tick.h"
#include "../misc/lv_assert.h"
#include "../misc/lv_gc.h"

/*********************
 *      DEFINES
 *********************/

/** Count the cache entries's life. Add `time_to_open` to `life` when the entry is used.
 * Decrement all lifes by one every in every ::lv_img_cache_open.
 * If life == 0 the entry can be reused*/
#define CACHE_GET_LIFE(entry) ((lv_intptr_t)((entry)->user_data))
#define CACHE_SET_LIFE(entry, v) ((entry)->user_data = (void*)((lv_intptr_t)(v)))

/*Decrement life with this value on every open*/
#define LV_IMG_CACHE_AGING 1

/*Boost life by this factor (multiply time_to_open with this value)*/
#define LV_IMG_CACHE_LIFE_GAIN 1

/*Don't let life to be greater than this limit because it would require a lot of time to
 * "die" from very high values*/
#define LV_IMG_CACHE_LIFE_LIMIT 1000

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static _lv_img_cache_entry_t * _lv_img_cache_open_builtin(const void * src, lv_color_t color, int32_t frame_id);
static void lv_img_cache_set_size_builtin(uint16_t new_entry_cnt);
static void lv_img_cache_invalidate_src_builtin(const void * src);

#if LV_IMG_CACHE_DEF_SIZE
    static bool lv_img_cache_match(const void * src1, const void * src2);
#endif

/**********************
 *  STATIC VARIABLES
 **********************/
#if LV_IMG_CACHE_DEF_SIZE
    static uint16_t entry_cnt;
#endif

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void _lv_img_cache_builtin_init(void)
{
#if LV_IMG_CACHE_DEF_SIZE
    lv_img_cache_set_size_builtin(LV_IMG_CACHE_DEF_SIZE);
#endif

    lv_img_cache_manager_t manager;
    lv_img_cache_manager_init(&manager);
    manager.open_cb = _lv_img_cache_open_builtin;
    manager.set_size_cb = lv_img_cache_set_size_builtin;
    manager.invalidate_src_cb = lv_img_cache_invalidate_src_builtin;
    lv_img_cache_manager_apply(&manager);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Open an image using the image decoder interface and cache it.
 * The image will be left open meaning if the image decoder open callback allocated memory then it will remain.
 * The image is closed if a new image is opened and the new image takes its place in the cache.
 * @param src source of the image. Path to file or pointer to an `lv_img_dsc_t` variable
 * @param color color The color of the image with `LV_IMG_CF_ALPHA_...`
 * @return pointer to the cache entry or NULL if can open the image
 */
static _lv_img_cache_entry_t * _lv_img_cache_open_builtin(const void * src, lv_color_t color, int32_t frame_id)
{
    /*Is the image cached?*/
    _lv_img_cache_entry_t * cached_src = NULL;

#if LV_IMG_CACHE_DEF_SIZE
    if(entry_cnt == 0) {
        LV_LOG_WARN("the cache size is 0");
        return NULL;
    }

    _lv_img_cache_entry_t * cache = LV_GC_ROOT(_lv_img_cache_array);

    /*Decrement all lifes. Make the entries older*/
    uint16_t i;
    for(i = 0; i < entry_cnt; i++) {
        int32_t life = CACHE_GET_LIFE(&cache[i]);
        if(life > INT32_MIN + LV_IMG_CACHE_AGING) {
            CACHE_SET_LIFE(&cache[i], life - LV_IMG_CACHE_AGING);
        }
    }

    for(i = 0; i < entry_cnt; i++) {
        if(lv_color_eq(color, cache[i].dec_dsc.color) &&
           frame_id == cache[i].dec_dsc.frame_id &&
           lv_img_cache_match(src, cache[i].dec_dsc.src)) {
            /*If opened increment its life.
             *Image difficult to open should live longer to keep avoid frequent their recaching.
             *Therefore increase `life` with `time_to_open`*/
            cached_src = &cache[i];
            int32_t life = CACHE_GET_LIFE(cached_src);
            CACHE_SET_LIFE(cached_src, life + cached_src->dec_dsc.time_to_open * LV_IMG_CACHE_LIFE_GAIN);
            if(CACHE_GET_LIFE(cached_src) > LV_IMG_CACHE_LIFE_LIMIT) CACHE_SET_LIFE(cached_src, LV_IMG_CACHE_LIFE_LIMIT);
            LV_LOG_TRACE("image source found in the cache");
            break;
        }
    }

    /*The image is not cached then cache it now*/
    if(cached_src) return cached_src;

    /*Find an entry to reuse. Select the entry with the least life*/
    cached_src = &cache[0];
    for(i = 1; i < entry_cnt; i++) {
        if(CACHE_GET_LIFE(&cache[i]) < CACHE_GET_LIFE(cached_src)) {
            cached_src = &cache[i];
        }
    }

    /*Close the decoder to reuse if it was opened (has a valid source)*/
    if(cached_src->dec_dsc.src) {
        lv_img_decoder_close(&cached_src->dec_dsc);
        LV_LOG_INFO("image draw: cache miss, close and reuse an entry");
    }
    else {
        LV_LOG_INFO("image draw: cache miss, cached to an empty entry");
    }
#else
    cached_src = &LV_GC_ROOT(_lv_img_cache_single);
#endif
    /*Open the image and measure the time to open*/
    uint32_t t_start  = lv_tick_get();
    lv_res_t open_res = lv_img_decoder_open(&cached_src->dec_dsc, src, color, frame_id);
    if(open_res == LV_RES_INV) {
        LV_LOG_WARN("Image draw cannot open the image resource");
        lv_memzero(cached_src, sizeof(_lv_img_cache_entry_t));
        CACHE_SET_LIFE(cached_src, INT32_MIN); /*Make the empty entry very "weak" to force its us*/
        return NULL;
    }

    CACHE_SET_LIFE(cached_src, 0);

    /*If `time_to_open` was not set in the open function set it here*/
    if(cached_src->dec_dsc.time_to_open == 0) {
        cached_src->dec_dsc.time_to_open = lv_tick_elaps(t_start);
    }

    if(cached_src->dec_dsc.time_to_open == 0) cached_src->dec_dsc.time_to_open = 1;

    return cached_src;
}

/**
 * Set the number of images to be cached.
 * More cached images mean more opened image at same time which might mean more memory usage.
 * E.g. if 20 PNG or JPG images are open in the RAM they consume memory while opened in the cache.
 * @param new_entry_cnt number of image to cache
 */
static void lv_img_cache_set_size_builtin(uint16_t new_entry_cnt)
{
#if LV_IMG_CACHE_DEF_SIZE == 0
    LV_UNUSED(new_entry_cnt);
    LV_LOG_WARN("Can't change cache size because it's disabled by LV_IMG_CACHE_DEF_SIZE = 0");
#else
    if(LV_GC_ROOT(_lv_img_cache_array) != NULL) {
        /*Clean the cache before free it*/
        lv_img_cache_invalidate_src_builtin(NULL);
        lv_free(LV_GC_ROOT(_lv_img_cache_array));
    }

    /*Reallocate the cache*/
    LV_GC_ROOT(_lv_img_cache_array) = lv_malloc(sizeof(_lv_img_cache_entry_t) * new_entry_cnt);
    LV_ASSERT_MALLOC(LV_GC_ROOT(_lv_img_cache_array));
    if(LV_GC_ROOT(_lv_img_cache_array) == NULL) {
        entry_cnt = 0;
        return;
    }
    entry_cnt = new_entry_cnt;

    /*Clean the cache*/
    lv_memzero(LV_GC_ROOT(_lv_img_cache_array), entry_cnt * sizeof(_lv_img_cache_entry_t));
#endif
}

/**
 * Invalidate an image source in the cache.
 * Useful if the image source is updated therefore it needs to be cached again.
 * @param src an image source path to a file or pointer to an `lv_img_dsc_t` variable.
 */
static void lv_img_cache_invalidate_src_builtin(const void * src)
{
    LV_UNUSED(src);
#if LV_IMG_CACHE_DEF_SIZE
    _lv_img_cache_entry_t * cache = LV_GC_ROOT(_lv_img_cache_array);

    uint16_t i;
    for(i = 0; i < entry_cnt; i++) {
        if(src == NULL || lv_img_cache_match(src, cache[i].dec_dsc.src)) {
            if(cache[i].dec_dsc.src != NULL) {
                lv_img_decoder_close(&cache[i].dec_dsc);
            }

            lv_memzero(&cache[i], sizeof(_lv_img_cache_entry_t));
        }
    }
#endif
}

#if LV_IMG_CACHE_DEF_SIZE
static bool lv_img_cache_match(const void * src1, const void * src2)
{
    lv_img_src_t src_type = lv_img_src_get_type(src1);
    if(src_type == LV_IMG_SRC_VARIABLE)
        return src1 == src2;
    if(src_type != LV_IMG_SRC_FILE)
        return false;
    if(lv_img_src_get_type(src2) != LV_IMG_SRC_FILE)
        return false;
    return strcmp(src1, src2) == 0;
}
#endif
