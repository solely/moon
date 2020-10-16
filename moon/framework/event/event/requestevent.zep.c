
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * FileName: RequestEvent.php
 * User: solely
 * DateTime: 2020/7/25 23:53
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_RequestEvent) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Framework\\Event\\Event, RequestEvent, moon, framework_event_event_requestevent, moon_framework_event_event_kernelevent_ce, moon_framework_event_event_requestevent_method_entry, 0);

	zend_declare_property_null(moon_framework_event_event_requestevent_ce, SL("response"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_framework_event_event_requestevent_ce, SL("route"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * @return mixed
 */
PHP_METHOD(Moon_Framework_Event_Event_RequestEvent, getResponse) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "response");

}

/**
 * @param mixed $response
 */
PHP_METHOD(Moon_Framework_Event_Event_RequestEvent, setResponse) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *response, response_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	zephir_update_property_zval(this_ptr, ZEND_STRL("response"), response);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "stoppropagation", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Moon_Framework_Event_Event_RequestEvent, hasResponse) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_0) != IS_NULL);

}

/**
 * @param Node $route
 */
PHP_METHOD(Moon_Framework_Event_Event_RequestEvent, setRoute) {

	zval *route, route_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &route);



	zephir_update_property_zval(this_ptr, ZEND_STRL("route"), route);

}

/**
 * @return Node
 */
PHP_METHOD(Moon_Framework_Event_Event_RequestEvent, getRoute) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "route");

}

