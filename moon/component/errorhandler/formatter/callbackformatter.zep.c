
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
#include "kernel/fcall.h"


/**
 * FileName: CallbackFormatter.php
 * User: solely
 * DateTime: 2019/10/31 23:45
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Formatter_CallbackFormatter) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\ErrorHandler\\Formatter, CallbackFormatter, moon, component_errorhandler_formatter_callbackformatter, moon_component_errorhandler_formatter_callbackformatter_method_entry, 0);

	zend_declare_property_null(moon_component_errorhandler_formatter_callbackformatter_ce, SL("_callable"), ZEND_ACC_PRIVATE);

	zend_class_implements(moon_component_errorhandler_formatter_callbackformatter_ce, 1, moon_component_errorhandler_formatter_formatterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_CallbackFormatter, __construct) {

	zval *_callable, _callable_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_callable_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &_callable);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_callable"), _callable);

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_CallbackFormatter, format) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, *debug, debug_sub, *charset, charset_sub, call;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&debug_sub);
	ZVAL_UNDEF(&charset_sub);
	ZVAL_UNDEF(&call);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &exception, &debug, &charset);



	ZEPHIR_OBS_VAR(&call);
	zephir_read_property(&call, this_ptr, ZEND_STRL("_callable"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&call, NULL, 0, exception, debug, charset);
	zephir_check_call_status();
	RETURN_MM();

}

