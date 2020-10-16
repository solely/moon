
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * FileName: ExceptionHandler.php
 * User: solely
 * DateTime: 2019/10/31 23:41
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Handler_ExceptionHandler) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\ErrorHandler\\Handler, ExceptionHandler, moon, component_errorhandler_handler_exceptionhandler, moon_component_errorhandler_handler_exceptionhandler_method_entry, 0);

	zend_declare_property_null(moon_component_errorhandler_handler_exceptionhandler_ce, SL("debug"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_handler_exceptionhandler_ce, SL("charset"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_handler_exceptionhandler_ce, SL("formatter"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_ErrorHandler_Handler_ExceptionHandler, register) {

	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval charset;
	zend_bool debug;
	zval *formatter, formatter_sub, *debug_param = NULL, *charset_param = NULL, __$true, __$false, exceptionHandler, _0, _5, _1$$3, _2$$3, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&formatter_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&exceptionHandler);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&charset);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &formatter, &debug_param, &charset_param);

	if (!debug_param) {
		debug = 1;
	} else {
		debug = zephir_get_boolval(debug_param);
	}
	if (!charset_param) {
		ZEPHIR_INIT_VAR(&charset);
		ZVAL_STRING(&charset, "");
	} else {
		zephir_get_strval(&charset, charset_param);
	}


	ZEPHIR_INIT_VAR(&exceptionHandler);
	object_init_ex(&exceptionHandler, moon_component_errorhandler_handler_exceptionhandler_ce);
	if (zephir_has_constructor(&exceptionHandler)) {
		ZEPHIR_CALL_METHOD(NULL, &exceptionHandler, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(&exceptionHandler, ZEND_STRL("formatter"), formatter);
	if (debug) {
		zephir_update_property_zval(&exceptionHandler, ZEND_STRL("debug"), &__$true);
	} else {
		zephir_update_property_zval(&exceptionHandler, ZEND_STRL("debug"), &__$false);
	}
	ZEPHIR_INIT_VAR(&_0);
	if (!(!(Z_TYPE_P(&charset) == IS_UNDEF) && Z_STRLEN_P(&charset))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "default_charset");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "ini_get", NULL, 13, &_1$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&_2$$3))) {
			ZEPHIR_INIT_NVAR(&_0);
			ZVAL_STRING(&_0, "UTF-8");
		} else {
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "default_charset");
			ZEPHIR_CALL_FUNCTION(&_0, "ini_get", NULL, 13, &_3$$5);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CPY_WRT(&_0, &charset);
	}
	zephir_update_property_zval(&exceptionHandler, ZEND_STRL("charset"), &_0);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_fast_append(&_4, &exceptionHandler);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "handlerException");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 165, &_4);
	zephir_check_call_status();
	RETURN_CCTOR(&exceptionHandler);

}

PHP_METHOD(Moon_Component_ErrorHandler_Handler_ExceptionHandler, handlerException) {

	zval _0, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &exception);



	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("formatter"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "format");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 3, 0);
	zephir_array_fast_append(&_3, exception);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("debug"), PH_NOISY_CC);
	zephir_array_fast_append(&_3, &_1);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("charset"), PH_NOISY_CC);
	zephir_array_fast_append(&_3, &_1);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Handler_ExceptionHandler, unregister) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "restore_exception_handler", NULL, 166);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

