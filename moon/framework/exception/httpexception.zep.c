
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * FileName: HttpException.php
 * User: solely
 * DateTime: 2020/8/19 23:30
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Exception_HttpException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Framework\\Exception, HttpException, moon, framework_exception_httpexception, spl_ce_RuntimeException, moon_framework_exception_httpexception_method_entry, 0);

	zend_declare_property_null(moon_framework_exception_httpexception_ce, SL("statusCode"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_framework_exception_httpexception_ce, SL("headers"), ZEND_ACC_PRIVATE);

	zend_class_implements(moon_framework_exception_httpexception_ce, 1, moon_framework_exception_httpexceptioninterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Exception_HttpException, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval headers;
	zval message;
	zval *statusCode_param = NULL, *message_param = NULL, *previous, previous_sub, *headers_param = NULL, *code = NULL, code_sub, _0;
	zend_long statusCode, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&previous_sub);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &statusCode_param, &message_param, &previous, &headers_param, &code);

	statusCode = zephir_get_intval(statusCode_param);
	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}
	if (!code) {
		code = &code_sub;
		ZEPHIR_INIT_VAR(code);
		ZVAL_LONG(code, 0);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, statusCode);
	zephir_update_property_zval(this_ptr, ZEND_STRL("statusCode"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &headers);
	ZEPHIR_CALL_PARENT(NULL, moon_framework_exception_httpexception_ce, getThis(), "__construct", NULL, 0, &message, code, previous);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Exception_HttpException, getStatusCode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "statusCode");

}

PHP_METHOD(Moon_Framework_Exception_HttpException, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

/**
 * Set response headers.
 *
 * @param array $headers Response headers
 */
PHP_METHOD(Moon_Framework_Exception_HttpException, setHeaders) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *headers_param = NULL;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(&headers, headers_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &headers);
	ZEPHIR_MM_RESTORE();

}

