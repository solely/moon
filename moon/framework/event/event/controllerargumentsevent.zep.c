
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * FileName: ControllerArgumentsEvent.php
 * User: solely
 * DateTime: 2020/8/23 23:38
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_ControllerArgumentsEvent) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Framework\\Event\\Event, ControllerArgumentsEvent, moon, framework_event_event_controllerargumentsevent, moon_framework_event_event_kernelevent_ce, moon_framework_event_event_controllerargumentsevent_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(moon_framework_event_event_controllerargumentsevent_ce, SL("controller"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_framework_event_event_controllerargumentsevent_ce, SL("arguments"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Event_Event_ControllerArgumentsEvent, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval arguments;
	zval *request, request_sub, *router, router_sub, *controller, controller_sub, *arguments_param = NULL, *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&router_sub);
	ZVAL_UNDEF(&controller_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&arguments);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &request, &router, &controller, &arguments_param, &container);

	zephir_get_arrval(&arguments, arguments_param);


	ZEPHIR_CALL_PARENT(NULL, moon_framework_event_event_controllerargumentsevent_ce, getThis(), "__construct", &_0, 0, request, router, container);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("controller"), controller);
	zephir_update_property_zval(this_ptr, ZEND_STRL("arguments"), &arguments);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param callable $controller
 */
PHP_METHOD(Moon_Framework_Event_Event_ControllerArgumentsEvent, setController) {

	zval *controller, controller_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controller_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &controller);



	zephir_update_property_zval(this_ptr, ZEND_STRL("controller"), controller);

}

/**
 * @return callable
 */
PHP_METHOD(Moon_Framework_Event_Event_ControllerArgumentsEvent, getController) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "controller");

}

/**
 * @param array $arguments
 */
PHP_METHOD(Moon_Framework_Event_Event_ControllerArgumentsEvent, setArguments) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *arguments_param = NULL;
	zval arguments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arguments_param);

	zephir_get_arrval(&arguments, arguments_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("arguments"), &arguments);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return array
 */
PHP_METHOD(Moon_Framework_Event_Event_ControllerArgumentsEvent, getArguments) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "arguments");

}

