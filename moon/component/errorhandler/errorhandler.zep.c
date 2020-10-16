
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * FileName: ErrorHandler.php
 * User: solely
 * DateTime: 2019/11/3 22:54
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_ErrorHandler) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\ErrorHandler, ErrorHandler, moon, component_errorhandler_errorhandler, moon_component_errorhandler_errorhandler_method_entry, 0);

	zend_declare_property_bool(moon_component_errorhandler_errorhandler_ce, SL("isRegistered"), 0, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_ErrorHandler_ErrorHandler, register) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *errorReportingLevel = NULL, errorReportingLevel_sub, *displayErrors = NULL, displayErrors_sub, *formatter = NULL, formatter_sub, *charset = NULL, charset_sub, __$true, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&errorReportingLevel_sub);
	ZVAL_UNDEF(&displayErrors_sub);
	ZVAL_UNDEF(&formatter_sub);
	ZVAL_UNDEF(&charset_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &errorReportingLevel, &displayErrors, &formatter, &charset);

	ZEPHIR_SEPARATE_PARAM(formatter);
	if (!errorReportingLevel) {
		errorReportingLevel = &errorReportingLevel_sub;
		ZEPHIR_CPY_WRT(errorReportingLevel, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(errorReportingLevel);
	}
	if (!displayErrors) {
		displayErrors = &displayErrors_sub;
		displayErrors = &__$true;
	}
	if (!charset) {
		charset = &charset_sub;
		charset = &__$null;
	}


	if (Z_TYPE_P(errorReportingLevel) == IS_NULL) {
		ZEPHIR_INIT_NVAR(errorReportingLevel);
		ZVAL_LONG(errorReportingLevel, 32767);
	}
	zephir_read_static_property_ce(&_0, moon_component_errorhandler_errorhandler_ce, SL("isRegistered"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		if (Z_TYPE_P(formatter) == IS_NULL) {
			ZEPHIR_INIT_NVAR(formatter);
			object_init_ex(formatter, moon_component_errorhandler_formatter_normalformatter_ce);
			if (zephir_has_constructor(formatter)) {
				ZEPHIR_CALL_METHOD(NULL, formatter, "__construct", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_CALL_CE_STATIC(NULL, moon_component_errorhandler_handler_errorhandler_ce, "register", &_1, 0, formatter, errorReportingLevel, displayErrors, charset);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(NULL, moon_component_errorhandler_handler_exceptionhandler_ce, "register", &_2, 0, formatter, displayErrors, charset);
		zephir_check_call_status();
		zephir_update_static_property_ce(moon_component_errorhandler_errorhandler_ce, ZEND_STRL("isRegistered"), &__$true);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_ErrorHandler_ErrorHandler, unregister) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$false, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, moon_component_errorhandler_errorhandler_ce, SL("isRegistered"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_CE_STATIC(NULL, moon_component_errorhandler_handler_errorhandler_ce, "unregister", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(NULL, moon_component_errorhandler_handler_exceptionhandler_ce, "unregister", &_2, 0);
		zephir_check_call_status();
		zephir_update_static_property_ce(moon_component_errorhandler_errorhandler_ce, ZEND_STRL("isRegistered"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

