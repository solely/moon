
extern zend_class_entry *moon_component_errorhandler_errorhandler_ce;

ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_ErrorHandler);

PHP_METHOD(Moon_Component_ErrorHandler_ErrorHandler, register);
PHP_METHOD(Moon_Component_ErrorHandler_ErrorHandler, unregister);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_errorhandler_register, 0, 0, 1)
	ZEND_ARG_INFO(0, errorReportingLevel)
	ZEND_ARG_INFO(0, displayErrors)
	ZEND_ARG_OBJ_INFO(0, formatter, Moon\\Component\\ErrorHandler\\Formatter\\FormatterInterface, 0)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_errorhandler_errorhandler_method_entry) {
	PHP_ME(Moon_Component_ErrorHandler_ErrorHandler, register, arginfo_moon_component_errorhandler_errorhandler_register, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_ErrorHandler, unregister, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
