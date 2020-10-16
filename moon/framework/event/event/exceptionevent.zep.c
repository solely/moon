
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
 * FileName: ExceptionEvent.php
 * User: solely
 * DateTime: 2020/7/26 0:20
 * Description:
 *
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_ExceptionEvent) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Framework\\Event\\Event, ExceptionEvent, moon, framework_event_event_exceptionevent, moon_framework_event_event_requestevent_ce, moon_framework_event_event_exceptionevent_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(moon_framework_event_event_exceptionevent_ce, SL("throwable"), ZEND_ACC_PRIVATE);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(moon_framework_event_event_exceptionevent_ce, SL("allowCustomResponseCode"), 0, ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Event_Event_ExceptionEvent, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *request, request_sub, *e, e_sub, *router, router_sub, *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&router_sub);
	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &request, &e, &router, &container);



	ZEPHIR_CALL_PARENT(NULL, moon_framework_event_event_exceptionevent_ce, getThis(), "__construct", &_0, 0, request, router, container);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("throwable"), e);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Event_Event_ExceptionEvent, getThrowable) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "throwable");

}

/**
 * Replaces the thrown exception.
 *
 * This exception will be thrown if no response is set in the event.
 *
 * @param \Throwable $exception
 */
PHP_METHOD(Moon_Framework_Event_Event_ExceptionEvent, setThrowable) {

	zval *exception, exception_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &exception);



	zephir_update_property_zval(this_ptr, ZEND_STRL("throwable"), exception);

}

/**
 * Mark the event as allowing a custom response code.
 */
PHP_METHOD(Moon_Framework_Event_Event_ExceptionEvent, allowCustomResponseCode) {

	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);


	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("allowCustomResponseCode"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("allowCustomResponseCode"), &__$false);
	}

}

/**
 * Returns true if the event allows a custom response code.
 */
PHP_METHOD(Moon_Framework_Event_Event_ExceptionEvent, isAllowingCustomResponseCode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "allowCustomResponseCode");

}

