
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
#include "kernel/memory.h"


/**
 * FileName: ViewEvent.php
 * User: solely
 * DateTime: 2020/7/26 0:00
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_ViewEvent) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Framework\\Event\\Event, ViewEvent, moon, framework_event_event_viewevent, moon_framework_event_event_requestevent_ce, moon_framework_event_event_viewevent_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * The return value of the controller.
	 *
	 * @var mixed
	 */
	zend_declare_property_null(moon_framework_event_event_viewevent_ce, SL("controllerResult"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Event_Event_ViewEvent, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *request, request_sub, *router, router_sub, *controllerResult, controllerResult_sub, *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&router_sub);
	ZVAL_UNDEF(&controllerResult_sub);
	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &request, &router, &controllerResult, &container);



	ZEPHIR_CALL_PARENT(NULL, moon_framework_event_event_viewevent_ce, getThis(), "__construct", &_0, 0, request, router, container);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("controllerResult"), controllerResult);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the return value of the controller.
 *
 * @return mixed The controller return value
 */
PHP_METHOD(Moon_Framework_Event_Event_ViewEvent, getControllerResult) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "controllerResult");

}

/**
 * Assigns the return value of the controller.
 *
 * @param mixed $controllerResult The controller return value
 */
PHP_METHOD(Moon_Framework_Event_Event_ViewEvent, setControllerResult) {

	zval *controllerResult, controllerResult_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerResult_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &controllerResult);



	zephir_update_property_zval(this_ptr, ZEND_STRL("controllerResult"), controllerResult);

}

