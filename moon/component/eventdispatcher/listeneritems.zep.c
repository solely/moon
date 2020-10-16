
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * FileName: ListenerItems.php
 * User: solely
 * DateTime: 2019/7/18 23:14
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerItems) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\EventDispatcher, ListenerItems, moon, component_eventdispatcher_listeneritems, moon_component_eventdispatcher_listeneritems_method_entry, 0);

	zend_declare_property_null(moon_component_eventdispatcher_listeneritems_ce, SL("item"), ZEND_ACC_PUBLIC);

	/** @var int */
	zend_declare_property_null(moon_component_eventdispatcher_listeneritems_ce, SL("priority"), ZEND_ACC_PUBLIC);

	/** @var string */
	zend_declare_property_null(moon_component_eventdispatcher_listeneritems_ce, SL("id"), ZEND_ACC_PUBLIC);

	/** @var string */
	zend_declare_property_null(moon_component_eventdispatcher_listeneritems_ce, SL("before"), ZEND_ACC_PUBLIC);

	/** @var string */
	zend_declare_property_null(moon_component_eventdispatcher_listeneritems_ce, SL("after"), ZEND_ACC_PUBLIC);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerItems, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval id;
	zend_long priority;
	zval *item = NULL, item_sub, *priority_param = NULL, *id_param = NULL, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&id);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &item, &priority_param, &id_param);

	if (!item) {
		item = &item_sub;
		item = &__$null;
	}
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


	zephir_update_property_zval(this_ptr, ZEND_STRL("item"), item);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, priority);
	zephir_update_property_zval(this_ptr, ZEND_STRL("priority"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("id"), &id);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerItems, createWithPriority) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval id;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, *priority_param = NULL, *id_param = NULL, _new, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&id);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &item, &priority_param, &id_param);

	priority = zephir_get_intval(priority_param);
	zephir_get_strval(&id, id_param);


	ZEPHIR_INIT_VAR(&_new);
	object_init_ex(&_new, moon_component_eventdispatcher_listeneritems_ce);
	ZEPHIR_CALL_METHOD(NULL, &_new, "__construct", NULL, 170);
	zephir_check_call_status();
	zephir_update_property_zval(&_new, ZEND_STRL("item"), item);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, priority);
	zephir_update_property_zval(&_new, ZEND_STRL("priority"), &_0);
	zephir_update_property_zval(&_new, ZEND_STRL("id"), &id);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerItems, createBefore) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pivotId;
	zval *item, item_sub, *pivotId_param = NULL, *id, id_sub, _new;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&pivotId);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &item, &pivotId_param, &id);

	zephir_get_strval(&pivotId, pivotId_param);


	ZEPHIR_INIT_VAR(&_new);
	object_init_ex(&_new, moon_component_eventdispatcher_listeneritems_ce);
	ZEPHIR_CALL_METHOD(NULL, &_new, "__construct", NULL, 170);
	zephir_check_call_status();
	zephir_update_property_zval(&_new, ZEND_STRL("item"), item);
	zephir_update_property_zval(&_new, ZEND_STRL("before"), &pivotId);
	zephir_update_property_zval(&_new, ZEND_STRL("id"), id);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerItems, createAfter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pivotId;
	zval *item, item_sub, *pivotId_param = NULL, *id, id_sub, _new;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&pivotId);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &item, &pivotId_param, &id);

	zephir_get_strval(&pivotId, pivotId_param);


	ZEPHIR_INIT_VAR(&_new);
	object_init_ex(&_new, moon_component_eventdispatcher_listeneritems_ce);
	ZEPHIR_CALL_METHOD(NULL, &_new, "__construct", NULL, 170);
	zephir_check_call_status();
	zephir_update_property_zval(&_new, ZEND_STRL("item"), item);
	zephir_update_property_zval(&_new, ZEND_STRL("after"), &pivotId);
	zephir_update_property_zval(&_new, ZEND_STRL("id"), id);
	RETURN_CCTOR(&_new);

}

