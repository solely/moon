
extern zend_class_entry *moon_component_errorhandler_helpers_ce;

ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Helpers);

PHP_METHOD(Moon_Component_ErrorHandler_Helpers, escapeHtml);
PHP_METHOD(Moon_Component_ErrorHandler_Helpers, getClass);
PHP_METHOD(Moon_Component_ErrorHandler_Helpers, formatHtml);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_helpers_escapehtml, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_helpers_escapehtml, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, s)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_helpers_getclass, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_helpers_getclass, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_helpers_formathtml, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_helpers_formathtml, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mask, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, mask)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_errorhandler_helpers_method_entry) {
	PHP_ME(Moon_Component_ErrorHandler_Helpers, escapeHtml, arginfo_moon_component_errorhandler_helpers_escapehtml, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Helpers, getClass, arginfo_moon_component_errorhandler_helpers_getclass, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Helpers, formatHtml, arginfo_moon_component_errorhandler_helpers_formathtml, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
