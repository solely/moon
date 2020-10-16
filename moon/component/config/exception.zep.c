
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
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * FileName: Exception.php
 * User: solely
 * DateTime: 2019/10/6 19:19
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Config_Exception) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Config, Exception, moon, component_config_exception, moon_component_config_exception_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Config_Exception, parserException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *msg_param = NULL, *code = NULL, code_sub, *throwable, throwable_sub;
	zval msg;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&throwable_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &msg_param, &code, &throwable);

	if (!msg_param) {
		ZEPHIR_INIT_VAR(&msg);
		ZVAL_STRING(&msg, "Parsing file failed");
	} else {
		zephir_get_strval(&msg, msg_param);
	}
	if (!code) {
		code = &code_sub;
		ZEPHIR_INIT_VAR(code);
		ZVAL_LONG(code, 0);
	}


	object_init_ex(return_value, moon_component_config_exception_parserexception_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 34, &msg, code, throwable);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Config_Exception, notFoundException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *msg_param = NULL, *code = NULL, code_sub, *throwable, throwable_sub;
	zval msg;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&throwable_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &msg_param, &code, &throwable);

	if (!msg_param) {
		ZEPHIR_INIT_VAR(&msg);
		ZVAL_STRING(&msg, "The key of the array does not exist");
	} else {
		zephir_get_strval(&msg, msg_param);
	}
	if (!code) {
		code = &code_sub;
		ZEPHIR_INIT_VAR(code);
		ZVAL_LONG(code, 0);
	}


	object_init_ex(return_value, moon_component_config_exception_notfoundexception_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 34, &msg, code, throwable);
	zephir_check_call_status();
	RETURN_MM();

}

