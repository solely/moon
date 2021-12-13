
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
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * FileName: ResponseEvent.php
 * User: solely
 * DateTime: 2020/7/25 23:57
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_ResponseEvent) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Framework\\Event\\Event, ResponseEvent, moon, framework_event_event_responseevent, moon_framework_event_event_kernelevent_ce, moon_framework_event_event_responseevent_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(moon_framework_event_event_responseevent_ce, SL("response"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_framework_event_event_responseevent_ce, SL("route"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Event_Event_ResponseEvent, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *request, request_sub, *response, response_sub, *route, route_sub, *router, router_sub, *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&route_sub);
	ZVAL_UNDEF(&router_sub);
	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &request, &response, &route, &router, &container);



	ZEPHIR_CALL_PARENT(NULL, moon_framework_event_event_responseevent_ce, getThis(), "__construct", &_0, 0, request, router, container);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setresponse", NULL, 177, response);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setroute", NULL, 178, route);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Event_Event_ResponseEvent, getResponse) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "response");

}

PHP_METHOD(Moon_Framework_Event_Event_ResponseEvent, setResponse) {

	zval *response, response_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &response);



	zephir_update_property_zval(this_ptr, ZEND_STRL("response"), response);

}

PHP_METHOD(Moon_Framework_Event_Event_ResponseEvent, getRoute) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "route");

}

PHP_METHOD(Moon_Framework_Event_Event_ResponseEvent, setRoute) {

	zval *route, route_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&route_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &route);



	zephir_update_property_zval(this_ptr, ZEND_STRL("route"), route);

}

