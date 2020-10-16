
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 * FileName: ErrorHandler.php
 * User: solely
 * DateTime: 2019/10/31 23:41
 * Description:
 *      将 错误error 转化成 异常exception ，然后在 ExceptionHandler 中统一处理
 *      突然发现一个解决 在方法体内抛出异常时 IDE 提示未定义处理异常的提示信息 的方法：即是在方法体的注释里加上返回抛出异常的注释。 2019年11月24日21:32:38
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Handler_ErrorHandler) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\ErrorHandler\\Handler, ErrorHandler, moon, component_errorhandler_handler_errorhandler, moon_component_errorhandler_handler_errorhandler_method_entry, 0);

	zend_declare_property_null(moon_component_errorhandler_handler_errorhandler_ce, SL("levels"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_handler_errorhandler_ce, SL("errorTypes"), ZEND_ACC_PRIVATE);

	zend_declare_property_bool(moon_component_errorhandler_handler_errorhandler_ce, SL("canThrowExceptions"), 1, ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_handler_errorhandler_ce, SL("formatter"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_handler_errorhandler_ce, SL("debug"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_handler_errorhandler_ce, SL("charset"), ZEND_ACC_PRIVATE);

	moon_component_errorhandler_handler_errorhandler_ce->create_object = zephir_init_properties_Moon_Component_ErrorHandler_Handler_ErrorHandler;
	return SUCCESS;

}

PHP_METHOD(Moon_Component_ErrorHandler_Handler_ErrorHandler, register) {

	zval _5, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval charset;
	zend_bool debug;
	zval *formatter, formatter_sub, *errorTypes = NULL, errorTypes_sub, *debug_param = NULL, *charset_param = NULL, __$true, __$false, __$null, errorHandler, _1, _6, _0$$4, _2$$5, _3$$5, _4$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&formatter_sub);
	ZVAL_UNDEF(&errorTypes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&errorHandler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&charset);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &formatter, &errorTypes, &debug_param, &charset_param);

	if (!errorTypes) {
		errorTypes = &errorTypes_sub;
		errorTypes = &__$null;
	}
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


	ZEPHIR_INIT_VAR(&errorHandler);
	object_init_ex(&errorHandler, moon_component_errorhandler_handler_errorhandler_ce);
	if (zephir_has_constructor(&errorHandler)) {
		ZEPHIR_CALL_METHOD(NULL, &errorHandler, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (zephir_is_true(errorTypes)) {
		zephir_update_property_zval(&errorHandler, ZEND_STRL("errorTypes"), errorTypes);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_0$$4);
		ZVAL_LONG(&_0$$4, (32767 | 2048));
		zephir_update_property_zval(&errorHandler, ZEND_STRL("errorTypes"), &_0$$4);
	}
	zephir_update_property_zval(&errorHandler, ZEND_STRL("formatter"), formatter);
	if (debug) {
		zephir_update_property_zval(&errorHandler, ZEND_STRL("debug"), &__$true);
	} else {
		zephir_update_property_zval(&errorHandler, ZEND_STRL("debug"), &__$false);
	}
	ZEPHIR_INIT_VAR(&_1);
	if (!(!(Z_TYPE_P(&charset) == IS_UNDEF) && Z_STRLEN_P(&charset))) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "default_charset");
		ZEPHIR_CALL_FUNCTION(&_3$$5, "ini_get", NULL, 13, &_2$$5);
		zephir_check_call_status();
		if (!(zephir_is_true(&_3$$5))) {
			ZEPHIR_INIT_NVAR(&_1);
			ZVAL_STRING(&_1, "UTF-8");
		} else {
			ZEPHIR_INIT_VAR(&_4$$7);
			ZVAL_STRING(&_4$$7, "default_charset");
			ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 13, &_4$$7);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CPY_WRT(&_1, &charset);
	}
	zephir_update_property_zval(&errorHandler, ZEND_STRL("charset"), &_1);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	zephir_array_fast_append(&_5, &errorHandler);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "handleError");
	zephir_array_fast_append(&_5, &_6);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 159, &_5, errorTypes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0);
	zephir_array_fast_append(&_7, &errorHandler);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "handleShutdown");
	zephir_array_fast_append(&_7, &_6);
	ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 160, &_7);
	zephir_check_call_status();
	RETURN_CCTOR(&errorHandler);

}

/**
 * @param $errno
 * @param $message
 * @param $file
 * @param $line
 * @return bool
 * @throws ErrorException
 */
PHP_METHOD(Moon_Component_ErrorHandler_Handler_ErrorHandler, handleError) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval message, file;
	zval *errnum_param = NULL, *message_param = NULL, *file_param = NULL, *line_param = NULL, errorAsException, _0, levelArr, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10;
	zend_long errnum, line, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&errorAsException);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&levelArr);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&file);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &errnum_param, &message_param, &file_param, &line_param);

	errnum = zephir_get_intval(errnum_param);
	zephir_get_strval(&message, message_param);
	zephir_get_strval(&file, file_param);
	line = zephir_get_intval(line_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("errorTypes"), PH_NOISY_CC | PH_READONLY);
	if (!(((errnum & (int) (zephir_get_numberval(&_0)))))) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("levels"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_closure_ex(&_2, NULL, moon_5__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(&_3, errnum);
	zephir_update_static_property_ce(moon_5__closure_ce, ZEND_STRL("errnum"), &_3);
	ZVAL_LONG(&_4, 2);
	ZEPHIR_CALL_FUNCTION(&_5, "array_filter", NULL, 161, &_1, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&levelArr, "array_values", NULL, 98, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_join_str(&_6, SL(""), &levelArr);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "%s: %s");
	ZEPHIR_CALL_FUNCTION(&_8, "sprintf", NULL, 3, &_7, &_6, &message);
	zephir_check_call_status();
	zephir_get_strval(&message, &_8);
	ZEPHIR_INIT_VAR(&errorAsException);
	object_init_ex(&errorAsException, moon_component_errorhandler_exception_errorexception_ce);
	ZVAL_LONG(&_4, 0);
	ZVAL_LONG(&_9, errnum);
	ZVAL_LONG(&_10, line);
	ZEPHIR_CALL_METHOD(NULL, &errorAsException, "__construct", NULL, 162, &message, &_4, &_9, &file, &_10);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("canThrowExceptions"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_4)) {
		zephir_throw_exception_debug(&errorAsException, "moon/Component/ErrorHandler/Handler/ErrorHandler.zep", 63);
		ZEPHIR_MM_RESTORE();
		return;
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "handleexception", NULL, 0, &errorAsException);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Moon_Component_ErrorHandler_Handler_ErrorHandler, handleException) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);

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
	zephir_read_property(&_3, this_ptr, ZEND_STRL("debug"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("charset"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 92, &_0, exception, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Handler_ErrorHandler, unregister) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 163);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @throws ErrorException
 */
PHP_METHOD(Moon_Component_ErrorHandler_Handler_ErrorHandler, handleShutdown) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false, fatalLevel, error, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&fatalLevel);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();

	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("canThrowExceptions"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("canThrowExceptions"), &__$false);
	}
	ZEPHIR_CALL_FUNCTION(&error, "error_get_last", NULL, 164);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&fatalLevel);
	ZVAL_LONG(&fatalLevel, (((((1 | 4) | 16) | 32) | 64) | 128));
	_0 = zephir_is_true(&error);
	if (_0) {
		zephir_array_fetch_string(&_1, &error, SL("type"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Handler/ErrorHandler.zep", 102);
		ZEPHIR_INIT_VAR(&_2);
		zephir_bitwise_and_function(&_2, &_1, &fatalLevel);
		_0 = ZEPHIR_GT_LONG(&_2, 0);
	}
	if (_0) {
		zephir_array_fetch_string(&_3$$3, &error, SL("type"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Handler/ErrorHandler.zep", 103);
		zephir_array_fetch_string(&_4$$3, &error, SL("message"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Handler/ErrorHandler.zep", 103);
		zephir_array_fetch_string(&_5$$3, &error, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Handler/ErrorHandler.zep", 103);
		zephir_array_fetch_string(&_6$$3, &error, SL("line"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Handler/ErrorHandler.zep", 103);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "handleerror", NULL, 0, &_3$$3, &_4$$3, &_5$$3, &_6$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Moon_Component_ErrorHandler_Handler_ErrorHandler(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("levels"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 15, 0);
			add_assoc_stringl_ex(&_1$$3, SL("E_DEPRECATED"), SL("Deprecated"));
			add_assoc_stringl_ex(&_1$$3, SL("E_USER_DEPRECATED"), SL("User Deprecated"));
			add_assoc_stringl_ex(&_1$$3, SL("E_NOTICE"), SL("Notice"));
			add_assoc_stringl_ex(&_1$$3, SL("E_USER_NOTICE"), SL("User Notice"));
			add_assoc_stringl_ex(&_1$$3, SL("E_STRICT"), SL("Runtime Notice"));
			add_assoc_stringl_ex(&_1$$3, SL("E_WARNING"), SL("Warning"));
			add_assoc_stringl_ex(&_1$$3, SL("E_USER_WARNING"), SL("User Warning"));
			add_assoc_stringl_ex(&_1$$3, SL("E_COMPILE_WARNING"), SL("Compile Warning"));
			add_assoc_stringl_ex(&_1$$3, SL("E_CORE_WARNING"), SL("Core Warning"));
			add_assoc_stringl_ex(&_1$$3, SL("E_USER_ERROR"), SL("User Error"));
			add_assoc_stringl_ex(&_1$$3, SL("E_RECOVERABLE_ERROR"), SL("Catchable Fatal Error"));
			add_assoc_stringl_ex(&_1$$3, SL("E_COMPILE_ERROR"), SL("Compile Error"));
			add_assoc_stringl_ex(&_1$$3, SL("E_PARSE"), SL("Parse Error"));
			add_assoc_stringl_ex(&_1$$3, SL("E_ERROR"), SL("Error"));
			add_assoc_stringl_ex(&_1$$3, SL("E_CORE_ERROR"), SL("Core Error"));
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("levels"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

