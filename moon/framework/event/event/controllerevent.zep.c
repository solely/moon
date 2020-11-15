
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * FileName: ControllerEvent.php
 * User: solely
 * DateTime: 2020/8/23 23:06
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_ControllerEvent) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Framework\\Event\\Event, ControllerEvent, moon, framework_event_event_controllerevent, moon_framework_event_event_kernelevent_ce, moon_framework_event_event_controllerevent_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(moon_framework_event_event_controllerevent_ce, SL("controller"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Event_Event_ControllerEvent, __construct) {

	zend_bool _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *request, request_sub, *router, router_sub, *controller, controller_sub, *container, container_sub, _3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&router_sub);
	ZVAL_UNDEF(&controller_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &request, &router, &controller, &container);



	ZEPHIR_CALL_PARENT(NULL, moon_framework_event_event_controllerevent_ce, getThis(), "__construct", &_0, 0, request, router, container);
	zephir_check_call_status();
	_1 = (zephir_is_callable(controller) == 1);
	if (_1) {
		_1 = Z_TYPE_P(controller) == IS_ARRAY;
	}
	_2 = _1;
	if (_2) {
		zephir_array_fetch_long(&_3, controller, 0, PH_NOISY | PH_READONLY, "moon/Framework/Event/Event/ControllerEvent.zep", 18);
		_2 = Z_TYPE_P(&_3) == IS_OBJECT;
	}
	if (_2) {
		zephir_array_fetch_long(&_4$$3, controller, 0, PH_NOISY | PH_READONLY, "moon/Framework/Event/Event/ControllerEvent.zep", 19);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "setcontainer", NULL, 0, container);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("controller"), controller);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Event_Event_ControllerEvent, getController) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "controller");

}

PHP_METHOD(Moon_Framework_Event_Event_ControllerEvent, setController) {

	zval *controller, controller_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controller_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &controller);



	zephir_update_property_zval(this_ptr, ZEND_STRL("controller"), controller);

}

