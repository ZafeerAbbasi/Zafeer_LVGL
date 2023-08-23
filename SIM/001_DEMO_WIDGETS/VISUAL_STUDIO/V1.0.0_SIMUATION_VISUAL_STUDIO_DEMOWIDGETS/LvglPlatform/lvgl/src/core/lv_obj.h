/**
 * @file lv_obj.h
 *
 */

#ifndef LV_OBJ_H
#define LV_OBJ_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../lv_conf_internal.h"

#include <stddef.h>
#include <stdbool.h>
#include "../misc/lv_style.h"
#include "../misc/lv_types.h"
#include "../misc/lv_area.h"
#include "../misc/lv_color.h"
#include "../misc/lv_assert.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

struct _lv_obj_t;

/**
 * Possible states of a widget.
 * OR-ed values are possible
 */
enum _lv_state_t {
    LV_STATE_DEFAULT     =  0x0000,
    LV_STATE_CHECKED     =  0x0001,
    LV_STATE_FOCUSED     =  0x0002,
    LV_STATE_FOCUS_KEY   =  0x0004,
    LV_STATE_EDITED      =  0x0008,
    LV_STATE_HOVERED     =  0x0010,
    LV_STATE_PRESSED     =  0x0020,
    LV_STATE_SCROLLED    =  0x0040,
    LV_STATE_DISABLED    =  0x0080,

    LV_STATE_USER_1      =  0x1000,
    LV_STATE_USER_2      =  0x2000,
    LV_STATE_USER_3      =  0x4000,
    LV_STATE_USER_4      =  0x8000,

    LV_STATE_ANY = 0xFFFF,    /**< Special value can be used in some functions to target all states*/
};

#ifdef DOXYGEN
typedef _lv_state_t lv_state_t;
#else
typedef uint16_t lv_state_t;
#endif /*DOXYGEN*/

/**
 * The possible parts of widgets.
 * The parts can be considered as the internal building block of the widgets.
 * E.g. slider = background + indicator + knob
 * Not all parts are used by every widget
 */

enum _lv_part_t {
    LV_PART_MAIN         = 0x000000,   /**< A background like rectangle*/
    LV_PART_SCROLLBAR    = 0x010000,   /**< The scrollbar(s)*/
    LV_PART_INDICATOR    = 0x020000,   /**< Indicator, e.g. for slider, bar, switch, or the tick box of the checkbox*/
    LV_PART_KNOB         = 0x030000,   /**< Like handle to grab to adjust the value*/
    LV_PART_SELECTED     = 0x040000,   /**< Indicate the currently selected option or section*/
    LV_PART_ITEMS        = 0x050000,   /**< Used if the widget has multiple similar elements (e.g. table cells)*/
    LV_PART_TICKS        = 0x060000,   /**< Ticks on scale e.g. for a chart or meter*/
    LV_PART_CURSOR       = 0x070000,   /**< Mark a specific place e.g. for text area's cursor or on a chart*/

    LV_PART_CUSTOM_FIRST = 0x080000,    /**< Extension point for custom widgets*/

    LV_PART_ANY          = 0x0F0000,    /**< Special value can be used in some functions to target all parts*/
};

#ifdef DOXYGEN
typedef _lv_part_t lv_part_t;
#else
typedef uint32_t lv_part_t;
#endif /*DOXYGEN*/

/**
 * On/Off features controlling the object's behavior.
 * OR-ed values are possible
 */
typedef enum {
    LV_OBJ_FLAG_HIDDEN          = (1L << 0),  /**< Make the object hidden. (Like it wasn't there at all)*/
    LV_OBJ_FLAG_CLICKABLE       = (1L << 1),  /**< Make the object clickable by the input devices*/
    LV_OBJ_FLAG_CLICK_FOCUSABLE = (1L << 2),  /**< Add focused state to the object when clicked*/
    LV_OBJ_FLAG_CHECKABLE       = (1L << 3),  /**< Toggle checked state when the object is clicked*/
    LV_OBJ_FLAG_SCROLLABLE      = (1L << 4),  /**< Make the object scrollable*/
    LV_OBJ_FLAG_SCROLL_ELASTIC  = (1L << 5),  /**< Allow scrolling inside but with slower speed*/
    LV_OBJ_FLAG_SCROLL_MOMENTUM = (1L << 6),  /**< Make the object scroll further when "thrown"*/
    LV_OBJ_FLAG_SCROLL_ONE      = (1L << 7),  /**< Allow scrolling only one snappable children*/
    LV_OBJ_FLAG_SCROLL_CHAIN_HOR = (1L << 8), /**< Allow propagating the horizontal scroll to a parent*/
    LV_OBJ_FLAG_SCROLL_CHAIN_VER = (1L << 9), /**< Allow propagating the vertical scroll to a parent*/
    LV_OBJ_FLAG_SCROLL_CHAIN     = (LV_OBJ_FLAG_SCROLL_CHAIN_HOR | LV_OBJ_FLAG_SCROLL_CHAIN_VER),
    LV_OBJ_FLAG_SCROLL_ON_FOCUS = (1L << 10),  /**< Automatically scroll object to make it visible when focused*/
    LV_OBJ_FLAG_SCROLL_WITH_ARROW  = (1L << 11), /**< Allow scrolling the focused object with arrow keys*/
    LV_OBJ_FLAG_SNAPPABLE       = (1L << 12), /**< If scroll snap is enabled on the parent it can snap to this object*/
    LV_OBJ_FLAG_PRESS_LOCK      = (1L << 13), /**< Keep the object pressed even if the press slid from the object*/
    LV_OBJ_FLAG_EVENT_BUBBLE    = (1L << 14), /**< Propagate the events to the parent too*/
    LV_OBJ_FLAG_GESTURE_BUBBLE  = (1L << 15), /**< Propagate the gestures to the parent*/
    LV_OBJ_FLAG_ADV_HITTEST     = (1L << 16), /**< Allow performing more accurate hit (click) test. E.g. consider rounded corners.*/
    LV_OBJ_FLAG_IGNORE_LAYOUT   = (1L << 17), /**< Make the object position-able by the layouts*/
    LV_OBJ_FLAG_FLOATING        = (1L << 18), /**< Do not scroll the object when the parent scrolls and ignore layout*/
    LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS = (1L << 19), /**< Send `LV_EVENT_DRAW_TASK_ADDED` events*/

    LV_OBJ_FLAG_LAYOUT_1        = (1L << 23), /**< Custom flag, free to use by layouts*/
    LV_OBJ_FLAG_LAYOUT_2        = (1L << 24), /**< Custom flag, free to use by layouts*/

    LV_OBJ_FLAG_WIDGET_1        = (1L << 25), /**< Custom flag, free to use by widget*/
    LV_OBJ_FLAG_WIDGET_2        = (1L << 26), /**< Custom flag, free to use by widget*/
    LV_OBJ_FLAG_USER_1          = (1L << 27), /**< Custom flag, free to use by user*/
    LV_OBJ_FLAG_USER_2          = (1L << 28), /**< Custom flag, free to use by user*/
    LV_OBJ_FLAG_USER_3          = (1L << 29), /**< Custom flag, free to use by user*/
    LV_OBJ_FLAG_USER_4          = (1L << 30), /**< Custom flag, free to use by user*/
} _lv_obj_flag_t;

#ifdef DOXYGEN
typedef _lv_obj_flag_t lv_obj_flag_t;
#else
typedef uint32_t lv_obj_flag_t;
#endif /*DOXYGEN*/


#include "lv_obj_tree.h"
#include "lv_obj_pos.h"
#include "lv_obj_scroll.h"
#include "lv_obj_style.h"
#include "lv_obj_draw.h"
#include "lv_obj_class.h"
#include "lv_obj_event.h"
#include "lv_group.h"

/**
 * Make the base object's class publicly available.
 */
extern const lv_obj_class_t lv_obj_class;

/**
 * Special, rarely used attributes.
 * They are allocated automatically if any elements is set.
 */
typedef struct {
    struct _lv_obj_t ** children;       /**< Store the pointer of the children in an array.*/
    uint32_t child_cnt;                 /**< Number of children*/
    lv_group_t * group_p;
    lv_event_list_t event_list;

    lv_point_t scroll;                  /**< The current X/Y scroll offset*/

    lv_coord_t ext_click_pad;           /**< Extra click padding in all direction*/
    lv_coord_t ext_draw_size;           /**< EXTend the size in every direction for drawing.*/

    lv_scrollbar_mode_t scrollbar_mode : 2; /**< How to display scrollbars*/
    lv_scroll_snap_t scroll_snap_x : 2;     /**< Where to align the snappable children horizontally*/
    lv_scroll_snap_t scroll_snap_y : 2;     /**< Where to align the snappable children vertically*/
    lv_dir_t scroll_dir : 4;                /**< The allowed scroll direction(s)*/
    uint8_t layer_type : 2;    /**< Cache the layer type here. Element of @lv_intermediate_layer_type_t */
} _lv_obj_spec_attr_t;

typedef struct _lv_obj_t {
    const lv_obj_class_t * class_p;
    struct _lv_obj_t * parent;
    _lv_obj_spec_attr_t * spec_attr;
    _lv_obj_style_t * styles;
#if LV_OBJ_STYLE_CACHE
    uint32_t style_main_prop_is_set;
    uint32_t style_other_prop_is_set;
#endif
    void * user_data;
    lv_area_t coords;
    lv_obj_flag_t flags;
    lv_state_t state;
    uint16_t layout_inv : 1;
    uint16_t scr_layout_inv : 1;
    uint16_t skip_trans : 1;
    uint16_t style_cnt  : 6;
    uint16_t h_layout   : 1;
    uint16_t w_layout   : 1;
} lv_obj_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a base object (a rectangle)
 * @param parent    pointer to a parent object. If NULL then a screen will be created.
 * @return          pointer to the new object
 */
lv_obj_t * lv_obj_create(lv_obj_t * parent);


/*=====================
 * Setter functions
 *====================*/

/**
 * Set one or more flags
 * @param obj   pointer to an object
 * @param f     R-ed values from `lv_obj_flag_t` to set.
 */
void lv_obj_add_flag(lv_obj_t * obj, lv_obj_flag_t f);

/**
 * Clear one or more flags
 * @param obj   pointer to an object
 * @param f     OR-ed values from `lv_obj_flag_t` to set.
 */
void lv_obj_clear_flag(lv_obj_t * obj, lv_obj_flag_t f);


/**
 * Add one or more states to the object. The other state bits will remain unchanged.
 * If specified in the styles, transition animation will be started from the previous state to the current.
 * @param obj       pointer to an object
 * @param state     the states to add. E.g `LV_STATE_PRESSED | LV_STATE_FOCUSED`
 */
void lv_obj_add_state(lv_obj_t * obj, lv_state_t state);

/**
 * Remove one or more states to the object. The other state bits will remain unchanged.
 * If specified in the styles, transition animation will be started from the previous state to the current.
 * @param obj       pointer to an object
 * @param state     the states to add. E.g `LV_STATE_PRESSED | LV_STATE_FOCUSED`
 */
void lv_obj_clear_state(lv_obj_t * obj, lv_state_t state);

/**
 * Set the user_data field of the object
 * @param obj   pointer to an object
 * @param user_data   pointer to the new user_data.
 */
static inline void lv_obj_set_user_data(lv_obj_t * obj, void * user_data)
{
    obj->user_data = user_data;
}

/*=======================
 * Getter functions
 *======================*/

/**
 * Check if a given flag or all the given flags are set on an object.
 * @param obj   pointer to an object
 * @param f     the flag(s) to check (OR-ed values can be used)
 * @return      true: all flags are set; false: not all flags are set
 */
bool lv_obj_has_flag(const lv_obj_t * obj, lv_obj_flag_t f);

/**
 * Check if a given flag or any of the flags are set on an object.
 * @param obj   pointer to an object
 * @param f     the flag(s) to check (OR-ed values can be used)
 * @return      true: at lest one flag flag is set; false: none of the flags are set
 */
bool lv_obj_has_flag_any(const lv_obj_t * obj, lv_obj_flag_t f);

/**
 * Get the state of an object
 * @param obj   pointer to an object
 * @return      the state (OR-ed values from `lv_state_t`)
 */
lv_state_t lv_obj_get_state(const lv_obj_t * obj);

/**
 * Check if the object is in a given state or not.
 * @param obj       pointer to an object
 * @param state     a state or combination of states to check
 * @return          true: `obj` is in `state`; false: `obj` is not in `state`
 */
bool lv_obj_has_state(const lv_obj_t * obj, lv_state_t state);

/**
 * Get the group of the object
 * @param       obj pointer to an object
 * @return      the pointer to group of the object
 */
lv_group_t * lv_obj_get_group(const lv_obj_t * obj);

/**
 * Get the user_data field of the object
 * @param obj   pointer to an object
 * @return      the pointer to the user_data of the object
 */
static inline void * lv_obj_get_user_data(lv_obj_t * obj)
{
    return obj->user_data;
}

/*=======================
 * Other functions
 *======================*/

/**
 * Allocate special data for an object if not allocated yet.
 * @param obj   pointer to an object
 */
void lv_obj_allocate_spec_attr(lv_obj_t * obj);

/**
 * Check the type of obj.
 * @param obj       pointer to an object
 * @param class_p   a class to check (e.g. `lv_slider_class`)
 * @return          true: `class_p` is the `obj` class.
 */
bool lv_obj_check_type(const lv_obj_t * obj, const lv_obj_class_t * class_p);

/**
 * Check if any object has a given class (type).
 * It checks the ancestor classes too.
 * @param obj       pointer to an object
 * @param class_p   a class to check (e.g. `lv_slider_class`)
 * @return          true: `obj` has the given class
 */
bool lv_obj_has_class(const lv_obj_t * obj, const lv_obj_class_t * class_p);

/**
 * Get the class (type) of the object
 * @param obj   pointer to an object
 * @return      the class (type) of the object
 */
const lv_obj_class_t * lv_obj_get_class(const lv_obj_t * obj);

/**
 * Check if any object is still "alive".
 * @param obj       pointer to an object
 * @return          true: valid
 */
bool lv_obj_is_valid(const lv_obj_t * obj);

/**********************
 *      MACROS
 **********************/

#if LV_USE_ASSERT_OBJ
#  define LV_ASSERT_OBJ(obj_p, obj_class)                                                               \
    do {                                                                                                \
        LV_ASSERT_MSG(obj_p != NULL, "The object is NULL");                                             \
        LV_ASSERT_MSG(lv_obj_has_class(obj_p, obj_class) == true, "Incompatible object type.");         \
        LV_ASSERT_MSG(lv_obj_is_valid(obj_p)  == true, "The object is invalid, deleted or corrupted?"); \
    } while(0)
# else
#  define LV_ASSERT_OBJ(obj_p, obj_class) do{}while(0)
#endif

#if LV_USE_LOG && LV_LOG_TRACE_OBJ_CREATE
#  define LV_TRACE_OBJ_CREATE(...) LV_LOG_TRACE(__VA_ARGS__)
#else
#  define LV_TRACE_OBJ_CREATE(...)
#endif


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_OBJ_H*/
