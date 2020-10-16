
extern zend_class_entry *moon_component_errorhandler_handler_errorhandler_ce;

ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Handler_ErrorHandler);

PHP_METHOD(Moon_Component_ErrorHandler_Handler_ErrorHandler, register);
PHP_METHOD(Moon_Component_ErrorHandler_Handler_ErrorHandler, handleError);
PHP_METHOD(Moon_Component_ErrorHandler_Handler_ErrorHandler, handleException);
PHP_METHOD(Moon_Component_ErrorHandler_Handler_ErrorHandler, unregister);
PHP_METHOD(Moon_Component_ErrorHandler_Handler_ErrorHandler, handleShutdown);
zend_object *zephir_init_properties_Moon_Component_ErrorHandler_Handler_ErrorHandler(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_handler_errorhandler_register, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, formatter, Moon\\Component\\ErrorHandler\\Formatter\\FormatterInterface, 0)
	ZEND_ARG_INFO(0, errorTypes)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, debug, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, debug)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, charset, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, charset)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_handler_errorhandler_handleerror, 0, 4, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_handler_errorhandler_handleerror, 0, 4, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, errnum, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, errnum)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, file)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, line, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, line)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_handler_errorhandler_handleexception, 0, 0, 1)
	ZEND_ARG_INFO(0, exception)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_errorhandler_handler_errorhandler_method_entry) {
	PHP_ME(Moon_Component_ErrorHandler_Handler_ErrorHandler, register, arginfo_moon_component_errorhandler_handler_errorhandler_register, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Handler_ErrorHandler, handleError, arginfo_moon_component_errorhandler_handler_errorhandler_handleerror, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Handler_ErrorHandler, handleException, arginfo_moon_component_errorhandler_handler_errorhandler_handleexception, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Handler_ErrorHandler, unregister, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Handler_ErrorHandler, handleShutdown, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
