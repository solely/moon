
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * FileName: Exception.php
 * User: solely
 * DateTime: 2020/6/21 15:06
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Router_Exception) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Router, Exception, moon, component_router_exception, moon_component_router_exception_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Router_Exception, notFoundException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *uri_param = NULL, _0, _1, _2;
	zval method, uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &uri_param);

	zephir_get_strval(&method, method_param);
	zephir_get_strval(&uri, uri_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_router_exception_notfoundexception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "No match to route %s for request mode %s");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 3, &_1, &uri, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 26, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "moon/Component/Router/Exception.zep", 15);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Moon_Component_Router_Exception, notSupportedException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, _0, _1, _2;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(&method, method_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_router_exception_routerexception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "The request mode of %s is not supported");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 3, &_1, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 26, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "moon/Component/Router/Exception.zep", 20);
	ZEPHIR_MM_RESTORE();
	return;

}

