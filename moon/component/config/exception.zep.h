
extern zend_class_entry *moon_component_config_exception_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Config_Exception);

PHP_METHOD(Moon_Component_Config_Exception, parserException);
PHP_METHOD(Moon_Component_Config_Exception, notFoundException);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_config_exception_parserexception, 0, 1, Moon\\Component\\Config\\Exception\\ParserException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_exception_parserexception, 0, 1, IS_OBJECT, "Moon\\Component\\Config\\Exception\\ParserException", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, msg, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, msg)
#endif
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_OBJ_INFO(0, throwable, Throwable, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_config_exception_notfoundexception, 0, 1, Moon\\Component\\Config\\Exception\\NotFoundException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_exception_notfoundexception, 0, 1, IS_OBJECT, "Moon\\Component\\Config\\Exception\\NotFoundException", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, msg, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, msg)
#endif
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_OBJ_INFO(0, throwable, Throwable, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_config_exception_method_entry) {
	PHP_ME(Moon_Component_Config_Exception, parserException, arginfo_moon_component_config_exception_parserexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Config_Exception, notFoundException, arginfo_moon_component_config_exception_notfoundexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
