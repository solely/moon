
extern zend_class_entry *moon_component_errorhandler_handler_exceptionhandler_ce;

ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Handler_ExceptionHandler);

PHP_METHOD(Moon_Component_ErrorHandler_Handler_ExceptionHandler, register);
PHP_METHOD(Moon_Component_ErrorHandler_Handler_ExceptionHandler, handlerException);
PHP_METHOD(Moon_Component_ErrorHandler_Handler_ExceptionHandler, unregister);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_handler_exceptionhandler_register, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, formatter, Moon\\Component\\ErrorHandler\\Formatter\\FormatterInterface, 0)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_handler_exceptionhandler_handlerexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_errorhandler_handler_exceptionhandler_method_entry) {
	PHP_ME(Moon_Component_ErrorHandler_Handler_ExceptionHandler, register, arginfo_moon_component_errorhandler_handler_exceptionhandler_register, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Handler_ExceptionHandler, handlerException, arginfo_moon_component_errorhandler_handler_exceptionhandler_handlerexception, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Handler_ExceptionHandler, unregister, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
