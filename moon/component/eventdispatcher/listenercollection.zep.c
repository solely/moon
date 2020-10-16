
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * FileName: ListenerCollectionZephir.php
 * User: solely
 * DateTime: 2020年10月7日15:16:33
 * Description:
 *
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerCollection) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\EventDispatcher, ListenerCollection, moon, component_eventdispatcher_listenercollection, moon_component_eventdispatcher_listenercollection_method_entry, 0);

	/**
	 * @var array
	 *
	 * An indexed array of arrays of Item entries. The key is the priority, the value is an array of Items.
	 */
	zend_declare_property_null(moon_component_eventdispatcher_listenercollection_ce, SL("items"), ZEND_ACC_PROTECTED);

	/**
	 * @var ListenerItems[]
	 *
	 * A list of the items in the collection indexed by ID. Order is undefined.
	 */
	zend_declare_property_null(moon_component_eventdispatcher_listenercollection_ce, SL("itemLookup"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(moon_component_eventdispatcher_listenercollection_ce, SL("sorted"), 0, ZEND_ACC_PROTECTED);

	/** @var array */
	zend_declare_property_null(moon_component_eventdispatcher_listenercollection_ce, SL("toPrioritize"), ZEND_ACC_PROTECTED);

	/**
	 * $items 的索引节点
	 * @var int
	 */
	zend_declare_property_long(moon_component_eventdispatcher_listenercollection_ce, SL("itemPriority"), 0, ZEND_ACC_PRIVATE);

	zend_declare_property_long(moon_component_eventdispatcher_listenercollection_ce, SL("currentItemPriority"), 0, ZEND_ACC_PRIVATE);

	/**
	 * $items[$itemPriority] 数组的索引节点
	 * @var int
	 */
	zend_declare_property_long(moon_component_eventdispatcher_listenercollection_ce, SL("itemPosition"), 0, ZEND_ACC_PRIVATE);

	zend_declare_property_long(moon_component_eventdispatcher_listenercollection_ce, SL("currentItemPosition"), 0, ZEND_ACC_PRIVATE);

	/**
	 * 给迭代器返回索引专用的属性
	 * @var int
	 */
	zend_declare_property_long(moon_component_eventdispatcher_listenercollection_ce, SL("itemIndex"), 0, ZEND_ACC_PRIVATE);

	moon_component_eventdispatcher_listenercollection_ce->create_object = zephir_init_properties_Moon_Component_EventDispatcher_ListenerCollection;

	zend_class_implements(moon_component_eventdispatcher_listenercollection_ce, 1, zend_ce_iterator);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, rewind) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _2, _3, _4, _5, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("sorted"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "prioritizependingitems", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_MAKE_REF(&_1$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "krsort", NULL, 168, &_1$$3);
		ZEPHIR_UNREF(&_1$$3);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("sorted"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("sorted"), &__$false);
		}
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(&_2, &_3);
	ZEPHIR_MAKE_REF(&_2);
	ZEPHIR_CALL_FUNCTION(&_4, "array_shift", NULL, 169, &_2);
	ZEPHIR_UNREF(&_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("itemPriority"), &_4);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(&_5, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("itemPosition"), &_5);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(&_5, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("itemIndex"), &_5);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, next) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, valid) {

	zend_bool flag = 0, res = 0, _2$$3;
	zval lItem, _0$$3, _1$$3, _3$$3, _4$$3, _5$$3, _18$$3, _6$$4, _7$$4, _8$$4, _9$$4, _10$$5, _11$$5, _12$$5, _13$$5, _14$$6, _15$$6, _16$$7, _17$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&lItem);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$8);

	ZEPHIR_MM_GROW();

	res = 0;
	flag = 1;
	while (1) {
		if (!(flag)) {
			break;
		}
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("itemPriority"), PH_NOISY_CC | PH_READONLY);
		_2$$3 = zephir_array_isset(&_0$$3, &_1$$3);
		if (_2$$3) {
			zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&_4$$3);
			ZEPHIR_OBS_NVAR(&_5$$3);
			zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("itemPriority"), PH_NOISY_CC);
			zephir_array_fetch(&_4$$3, &_3$$3, &_5$$3, PH_NOISY, "moon/Component/EventDispatcher/ListenerCollection.zep", 77);
			_2$$3 = !(ZEPHIR_IS_EMPTY(&_4$$3));
		}
		if (_2$$3) {
			zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&_8$$4);
			zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("itemPriority"), PH_NOISY_CC);
			zephir_array_fetch(&_7$$4, &_6$$4, &_8$$4, PH_READONLY, "moon/Component/EventDispatcher/ListenerCollection.zep", 78);
			zephir_read_property(&_9$$4, this_ptr, ZEND_STRL("itemPosition"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_7$$4, &_9$$4)) {
				zephir_read_property(&_10$$5, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_12$$5);
				zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("itemPriority"), PH_NOISY_CC);
				zephir_array_fetch(&_11$$5, &_10$$5, &_12$$5, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerCollection.zep", 79);
				ZEPHIR_OBS_NVAR(&_13$$5);
				zephir_read_property(&_13$$5, this_ptr, ZEND_STRL("itemPosition"), PH_NOISY_CC);
				zephir_array_fetch(&lItem, &_11$$5, &_13$$5, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerCollection.zep", 79);
				if (zephir_instance_of_ev(&lItem, moon_component_eventdispatcher_listeneritems_ce)) {
					flag = 0;
					res = 1;
					zephir_read_property(&_14$$6, this_ptr, ZEND_STRL("itemPriority"), PH_NOISY_CC | PH_READONLY);
					zephir_update_property_zval(this_ptr, ZEND_STRL("currentItemPriority"), &_14$$6);
					zephir_read_property(&_15$$6, this_ptr, ZEND_STRL("itemPosition"), PH_NOISY_CC | PH_READONLY);
					zephir_update_property_zval(this_ptr, ZEND_STRL("currentItemPosition"), &_15$$6);
				}
				RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("itemPosition")));
			} else {
				RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("itemPriority")));
				ZEPHIR_INIT_ZVAL_NREF(_16$$7);
				ZVAL_LONG(&_16$$7, 0);
				zephir_update_property_zval(this_ptr, ZEND_STRL("itemPosition"), &_16$$7);
			}
		} else {
			RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("itemPriority")));
			ZEPHIR_INIT_ZVAL_NREF(_17$$8);
			ZVAL_LONG(&_17$$8, 0);
			zephir_update_property_zval(this_ptr, ZEND_STRL("itemPosition"), &_17$$8);
		}
		zephir_read_property(&_18$$3, this_ptr, ZEND_STRL("itemPriority"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_LT_LONG(&_18$$3, 0)) {
			flag = 0;
		}
	}
	RETURN_MM_BOOL(res);

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, current) {

	zval lItem, _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&lItem);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("itemIndex")));
	zephir_read_property(&_0, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("currentItemPriority"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerCollection.zep", 110);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("currentItemPosition"), PH_NOISY_CC);
	zephir_array_fetch(&lItem, &_1, &_3, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerCollection.zep", 110);
	ZEPHIR_OBS_VAR(&_4);
	zephir_read_property(&_4, &lItem, ZEND_STRL("item"), PH_NOISY_CC);
	RETURN_CCTOR(&_4);

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, key) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "itemIndex");

}

/**
 * Adds an item to the collection with a given priority.  (Higher numbers come first.)
 *
 * @param $item
 *   The item to add. May be any data type.
 * @param int $priority
 *   The priority order of the item. Higher numbers will come first.
 * @param string $id
 *   An opaque string ID by which this item should be known. If it already exists a counter suffix will be added.
 * @return string
 *   An opaque ID string uniquely identifying the item for future reference.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, addItem) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval id;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *item = NULL, item_sub, *priority_param = NULL, *id_param = NULL, __$true, __$false, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&id);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &item, &priority_param, &id_param);

	ZEPHIR_SEPARATE_PARAM(item);
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}
	if (!id_param) {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_STRING(&id, "");
	} else {
		zephir_get_strval(&id, id_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "enforceuniqueid", NULL, 0, &id);
	zephir_check_call_status();
	zephir_get_strval(&id, &_0);
	ZVAL_LONG(&_3, priority);
	ZEPHIR_CALL_CE_STATIC(&_1, moon_component_eventdispatcher_listeneritems_ce, "createwithpriority", &_2, 0, item, &_3, &id);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(item, &_1);
	zephir_update_property_array_multi(this_ptr, SL("items"), item, SL("la"), 2, priority);
	zephir_update_property_array(this_ptr, SL("itemLookup"), &id, item);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sorted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sorted"), &__$false);
	}
	RETURN_CTOR(&id);

}

/**
 * Adds an item to the collection before another existing item.
 *
 * Note: The new item is only guaranteed to get returned before the existing item. No guarantee is made
 * regarding when it will be returned relative to any other item.
 *
 * @param string $pivotId
 *   The existing ID of an item in the collection.
 * @param $item
 *   The new item to add.
 * @param string $id
 *   An opaque string ID by which this item should be known. If it already exists a counter suffix will be added.
 * @return string
 *   An opaque ID string uniquely identifying the new item for future reference.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, addItemBefore) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pivotId_param = NULL, *item = NULL, item_sub, *id_param = NULL, __$true, __$false, _0, _1, _6, _2$$3, _3$$3, _4$$3, _5$$3;
	zval pivotId, id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pivotId);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&item_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &pivotId_param, &item, &id_param);

	zephir_get_strval(&pivotId, pivotId_param);
	ZEPHIR_SEPARATE_PARAM(item);
	if (!id_param) {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_STRING(&id, "");
	} else {
		zephir_get_strval(&id, id_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "enforceuniqueid", NULL, 0, &id);
	zephir_check_call_status();
	zephir_get_strval(&id, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &pivotId)) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &pivotId, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerCollection.zep", 163);
		zephir_read_property(&_4$$3, &_3$$3, ZEND_STRL("priority"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_5$$3, (zephir_get_numberval(&_4$$3) + 1));
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "additem", NULL, 0, item, &_5$$3, &id);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_CE_STATIC(&_6, moon_component_eventdispatcher_listeneritems_ce, "createbefore", &_7, 0, item, &pivotId, &id);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(item, &_6);
	zephir_update_property_array_append(this_ptr, SL("toPrioritize"), item);
	zephir_update_property_array(this_ptr, SL("itemLookup"), &id, item);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sorted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sorted"), &__$false);
	}
	RETURN_CTOR(&id);

}

/**
 * Adds an item to the collection after another existing item.
 *
 * Note: The new item is only guaranteed to get returned after the existing item. No guarantee is made
 * regarding when it will be returned relative to any other item.
 *
 * @param string $pivotId
 *   The existing ID of an item in the collection.
 * @param $item
 *   The new item to add.
 * @param string $id
 *   An opaque string ID by which this item should be known. If it already exists a counter suffix will be added.
 * @return string
 *   An opaque ID string uniquely identifying the new item for future reference.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, addItemAfter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pivotId_param = NULL, *item = NULL, item_sub, *id_param = NULL, __$true, __$false, _0, _1, _6, _2$$3, _3$$3, _4$$3, _5$$3;
	zval pivotId, id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pivotId);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&item_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &pivotId_param, &item, &id_param);

	zephir_get_strval(&pivotId, pivotId_param);
	ZEPHIR_SEPARATE_PARAM(item);
	if (!id_param) {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_STRING(&id, "");
	} else {
		zephir_get_strval(&id, id_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "enforceuniqueid", NULL, 0, &id);
	zephir_check_call_status();
	zephir_get_strval(&id, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &pivotId)) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &pivotId, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerCollection.zep", 194);
		zephir_read_property(&_4$$3, &_3$$3, ZEND_STRL("priority"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_5$$3, (zephir_get_numberval(&_4$$3) - 1));
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "additem", NULL, 0, item, &_5$$3, &id);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_CE_STATIC(&_6, moon_component_eventdispatcher_listeneritems_ce, "createafter", &_7, 0, item, &pivotId, &id);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(item, &_6);
	zephir_update_property_array_append(this_ptr, SL("toPrioritize"), item);
	zephir_update_property_array(this_ptr, SL("itemLookup"), &id, item);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sorted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sorted"), &__$false);
	}
	RETURN_CTOR(&id);

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, prioritizePendingItems) {

	zval priority, item, _0, *_1, _2, _67, _3$$3, _4$$3, _5$$4, _6$$4, _15$$4, _16$$4, _17$$4, _18$$4, _7$$5, _9$$5, _10$$5, _11$$5, _12$$5, _14$$5, _20$$6, _21$$6, _28$$6, _29$$6, _30$$6, _31$$6, _22$$7, _23$$7, _24$$7, _25$$7, _26$$7, _27$$7, _33$$8, _34$$8, _35$$8, _36$$9, _37$$9, _38$$10, _39$$10, _46$$10, _47$$10, _48$$10, _49$$10, _40$$11, _41$$11, _42$$11, _43$$11, _44$$11, _45$$11, _51$$12, _52$$12, _59$$12, _60$$12, _61$$12, _62$$12, _53$$13, _54$$13, _55$$13, _56$$13, _57$$13, _58$$13, _64$$14, _65$$14, _66$$14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _19$$4, _32$$6, _50$$10, _63$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&priority);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_67);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_30$$6);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_35$$8);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_46$$10);
	ZVAL_UNDEF(&_47$$10);
	ZVAL_UNDEF(&_48$$10);
	ZVAL_UNDEF(&_49$$10);
	ZVAL_UNDEF(&_40$$11);
	ZVAL_UNDEF(&_41$$11);
	ZVAL_UNDEF(&_42$$11);
	ZVAL_UNDEF(&_43$$11);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_51$$12);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_59$$12);
	ZVAL_UNDEF(&_60$$12);
	ZVAL_UNDEF(&_61$$12);
	ZVAL_UNDEF(&_62$$12);
	ZVAL_UNDEF(&_53$$13);
	ZVAL_UNDEF(&_54$$13);
	ZVAL_UNDEF(&_55$$13);
	ZVAL_UNDEF(&_56$$13);
	ZVAL_UNDEF(&_57$$13);
	ZVAL_UNDEF(&_58$$13);
	ZVAL_UNDEF(&_64$$14);
	ZVAL_UNDEF(&_65$$14);
	ZVAL_UNDEF(&_66$$14);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("toPrioritize"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "moon/Component/EventDispatcher/ListenerCollection.zep", 227);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1);
			zephir_read_property(&_3$$3, &item, ZEND_STRL("before"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_4$$3, &item, ZEND_STRL("after"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_3$$3)) {
				zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_6$$4, &item, ZEND_STRL("before"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset(&_5$$4, &_6$$4))) {
					zephir_read_property(&_9$$5, &item, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_10$$5, &item, ZEND_STRL("before"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_11$$5);
					ZVAL_STRING(&_11$$5, "Cannot add item %s before non-existent item %s");
					ZEPHIR_CALL_FUNCTION(&_12$$5, "sprintf", &_13, 3, &_11$$5, &_9$$5, &_10$$5);
					zephir_check_call_status();
					ZVAL_LONG(&_14$$5, 0);
					ZEPHIR_CALL_CE_STATIC(&_7$$5, moon_component_eventdispatcher_exception_ce, "runtimeexception", &_8, 0, &_12$$5, &_14$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$5, "moon/Component/EventDispatcher/ListenerCollection.zep", 212);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property(&_15$$4, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_17$$4);
				zephir_read_property(&_17$$4, &item, ZEND_STRL("before"), PH_NOISY_CC);
				zephir_array_fetch(&_16$$4, &_15$$4, &_17$$4, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerCollection.zep", 214);
				zephir_read_property(&_18$$4, &_16$$4, ZEND_STRL("priority"), PH_NOISY_CC | PH_READONLY);
				_19$$4 = (zephir_get_numberval(&_18$$4) + 1);
				ZEPHIR_INIT_NVAR(&priority);
				ZVAL_LONG(&priority, _19$$4);
				zephir_update_property_array_multi(this_ptr, SL("items"), &item, SL("za"), 2, &priority);
			} else if (zephir_is_true(&_4$$3)) {
				zephir_read_property(&_20$$6, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_21$$6, &item, ZEND_STRL("after"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset(&_20$$6, &_21$$6))) {
					zephir_read_property(&_23$$7, &item, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_24$$7, &item, ZEND_STRL("after"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_25$$7);
					ZVAL_STRING(&_25$$7, "Cannot add item %s after non-existent item %s");
					ZEPHIR_CALL_FUNCTION(&_26$$7, "sprintf", &_13, 3, &_25$$7, &_23$$7, &_24$$7);
					zephir_check_call_status();
					ZVAL_LONG(&_27$$7, 0);
					ZEPHIR_CALL_CE_STATIC(&_22$$7, moon_component_eventdispatcher_exception_ce, "runtimeexception", &_8, 0, &_26$$7, &_27$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_22$$7, "moon/Component/EventDispatcher/ListenerCollection.zep", 218);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property(&_28$$6, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_30$$6);
				zephir_read_property(&_30$$6, &item, ZEND_STRL("after"), PH_NOISY_CC);
				zephir_array_fetch(&_29$$6, &_28$$6, &_30$$6, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerCollection.zep", 220);
				zephir_read_property(&_31$$6, &_29$$6, ZEND_STRL("priority"), PH_NOISY_CC | PH_READONLY);
				_32$$6 = (zephir_get_numberval(&_31$$6) - 1);
				ZEPHIR_INIT_NVAR(&priority);
				ZVAL_LONG(&priority, _32$$6);
				zephir_update_property_array_multi(this_ptr, SL("items"), &item, SL("za"), 2, &priority);
			} else {
				ZEPHIR_INIT_NVAR(&_34$$8);
				ZVAL_STRING(&_34$$8, "No, seriously, how did you get here?");
				ZVAL_LONG(&_35$$8, 0);
				ZEPHIR_CALL_CE_STATIC(&_33$$8, moon_component_eventdispatcher_exception_ce, "runtimeexception", &_8, 0, &_34$$8, &_35$$8);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_33$$8, "moon/Component/EventDispatcher/ListenerCollection.zep", 223);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &_0, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_36$$9, &item, ZEND_STRL("before"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_37$$9, &item, ZEND_STRL("after"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_36$$9)) {
					zephir_read_property(&_38$$10, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_39$$10, &item, ZEND_STRL("before"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset(&_38$$10, &_39$$10))) {
						zephir_read_property(&_41$$11, &item, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
						zephir_read_property(&_42$$11, &item, ZEND_STRL("before"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_43$$11);
						ZVAL_STRING(&_43$$11, "Cannot add item %s before non-existent item %s");
						ZEPHIR_CALL_FUNCTION(&_44$$11, "sprintf", &_13, 3, &_43$$11, &_41$$11, &_42$$11);
						zephir_check_call_status();
						ZVAL_LONG(&_45$$11, 0);
						ZEPHIR_CALL_CE_STATIC(&_40$$11, moon_component_eventdispatcher_exception_ce, "runtimeexception", &_8, 0, &_44$$11, &_45$$11);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_40$$11, "moon/Component/EventDispatcher/ListenerCollection.zep", 212);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property(&_46$$10, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_48$$10);
					zephir_read_property(&_48$$10, &item, ZEND_STRL("before"), PH_NOISY_CC);
					zephir_array_fetch(&_47$$10, &_46$$10, &_48$$10, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerCollection.zep", 214);
					zephir_read_property(&_49$$10, &_47$$10, ZEND_STRL("priority"), PH_NOISY_CC | PH_READONLY);
					_50$$10 = (zephir_get_numberval(&_49$$10) + 1);
					ZEPHIR_INIT_NVAR(&priority);
					ZVAL_LONG(&priority, _50$$10);
					zephir_update_property_array_multi(this_ptr, SL("items"), &item, SL("za"), 2, &priority);
				} else if (zephir_is_true(&_37$$9)) {
					zephir_read_property(&_51$$12, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_52$$12, &item, ZEND_STRL("after"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset(&_51$$12, &_52$$12))) {
						zephir_read_property(&_54$$13, &item, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
						zephir_read_property(&_55$$13, &item, ZEND_STRL("after"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_56$$13);
						ZVAL_STRING(&_56$$13, "Cannot add item %s after non-existent item %s");
						ZEPHIR_CALL_FUNCTION(&_57$$13, "sprintf", &_13, 3, &_56$$13, &_54$$13, &_55$$13);
						zephir_check_call_status();
						ZVAL_LONG(&_58$$13, 0);
						ZEPHIR_CALL_CE_STATIC(&_53$$13, moon_component_eventdispatcher_exception_ce, "runtimeexception", &_8, 0, &_57$$13, &_58$$13);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_53$$13, "moon/Component/EventDispatcher/ListenerCollection.zep", 218);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property(&_59$$12, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_61$$12);
					zephir_read_property(&_61$$12, &item, ZEND_STRL("after"), PH_NOISY_CC);
					zephir_array_fetch(&_60$$12, &_59$$12, &_61$$12, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerCollection.zep", 220);
					zephir_read_property(&_62$$12, &_60$$12, ZEND_STRL("priority"), PH_NOISY_CC | PH_READONLY);
					_63$$12 = (zephir_get_numberval(&_62$$12) - 1);
					ZEPHIR_INIT_NVAR(&priority);
					ZVAL_LONG(&priority, _63$$12);
					zephir_update_property_array_multi(this_ptr, SL("items"), &item, SL("za"), 2, &priority);
				} else {
					ZEPHIR_INIT_NVAR(&_65$$14);
					ZVAL_STRING(&_65$$14, "No, seriously, how did you get here?");
					ZVAL_LONG(&_66$$14, 0);
					ZEPHIR_CALL_CE_STATIC(&_64$$14, moon_component_eventdispatcher_exception_ce, "runtimeexception", &_8, 0, &_65$$14, &_66$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_64$$14, "moon/Component/EventDispatcher/ListenerCollection.zep", 223);
					ZEPHIR_MM_RESTORE();
					return;
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_VAR(&_67);
	array_init(&_67);
	zephir_update_property_zval(this_ptr, ZEND_STRL("toPrioritize"), &_67);
	ZEPHIR_MM_RESTORE();

}

/**
 * Ensures a unique ID for all items in the collection.
 *
 * @param null|string $id
 *   The proposed ID of an item, or null to generate a random string.
 * @return string
 *   A confirmed unique ID string.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, enforceUniqueId) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, counter = 0;
	zval *id, id_sub, __$true, candidateId, _0, _1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&candidateId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	if (!(ZEPHIR_IS_EMPTY(id))) {
		ZEPHIR_CPY_WRT(&candidateId, id);
	} else {
		ZEPHIR_INIT_VAR(&_0);
		ZVAL_STRING(&_0, "");
		ZEPHIR_CALL_FUNCTION(&candidateId, "uniqid", NULL, 53, &_0, &__$true);
		zephir_check_call_status();
	}
	counter = 1;
	while (1) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset(&_1, &candidateId))) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_LONG(&_2$$3, counter);
		ZEPHIR_INIT_NVAR(&candidateId);
		ZEPHIR_CONCAT_VSV(&candidateId, id, "-", &_2$$3);
		counter += 1;
	}
	RETURN_CCTOR(&candidateId);

}

zend_object *zephir_init_properties_Moon_Component_EventDispatcher_ListenerCollection(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("toPrioritize"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("toPrioritize"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("itemLookup"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("itemLookup"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("items"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("items"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

