
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
#include "kernel/memory.h"


/**
 * FileName: KernelEvent.php
 * User: solely
 * DateTime: 2020/7/25 19:02
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_KernelEvent) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Framework\\Event\\Event, KernelEvent, moon, framework_event_event_kernelevent, moon_component_eventdispatcher_event_ce, moon_framework_event_event_kernelevent_method_entry, 0);

	zend_declare_property_null(moon_framework_event_event_kernelevent_ce, SL("request"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_framework_event_event_kernelevent_ce, SL("container"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_framework_event_event_kernelevent_ce, SL("router"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Event_Event_KernelEvent, __construct) {

	zval *request, request_sub, *router, router_sub, *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&router_sub);
	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params_without_memory_grow(3, 0, &request, &router, &container);



	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	zephir_update_property_zval(this_ptr, ZEND_STRL("router"), router);

}

/**
 * @return ServerRequest
 */
PHP_METHOD(Moon_Framework_Event_Event_KernelEvent, getRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "request");

}

/**
 * @param ContainerInterface $container
 */
PHP_METHOD(Moon_Framework_Event_Event_KernelEvent, setContainer) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &container);



	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);

}

/**
 * @return ContainerInterface
 */
PHP_METHOD(Moon_Framework_Event_Event_KernelEvent, getContainer) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * @return Router
 */
PHP_METHOD(Moon_Framework_Event_Event_KernelEvent, getRouter) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "router");

}

