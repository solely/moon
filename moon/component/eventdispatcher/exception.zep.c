
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * FileName: Exception.php
 * User: solely
 * DateTime: 2019/7/14 23:26
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_Exception) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\EventDispatcher, Exception, moon, component_eventdispatcher_exception, moon_component_eventdispatcher_exception_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_EventDispatcher_Exception, eventDispatcherException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *throwable, throwable_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&throwable_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &event, &throwable);



	object_init_ex(return_value, moon_component_eventdispatcher_exception_eventdispatcherexception_ce);
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, event, 0);
	ZEPHIR_CALL_METHOD(&_1, throwable, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Unhandled exception thrown from listener while processing event.\nThe event name is %s\n%s");
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", NULL, 3, &_2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, throwable, "getcode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 4, &_3, &_4, throwable);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_EventDispatcher_Exception, unimplementedMethodsException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *method_param = NULL, _0, _1;
	zval className, method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &method_param);

	zephir_get_strval(&className, className_param);
	zephir_get_strval(&method, method_param);


	object_init_ex(return_value, moon_component_eventdispatcher_exception_unimplementedmethodsexception_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Do not implement %s::%s method, you should not call");
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", NULL, 3, &_0, &className, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 4, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_EventDispatcher_Exception, runtimeException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *msg_param = NULL, *code_param = NULL, *throwable, throwable_sub, _0;
	zval msg;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&throwable_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &msg_param, &code_param, &throwable);

	zephir_get_strval(&msg, msg_param);
	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}


	object_init_ex(return_value, moon_component_eventdispatcher_exception_runtimeexception_ce);
	ZVAL_LONG(&_0, code);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 26, &msg, &_0, throwable);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_EventDispatcher_Exception, containerMissingException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, moon_component_eventdispatcher_exception_containermissingexception_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 26);
	zephir_check_call_status();
	RETURN_MM();

}

