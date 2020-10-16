
extern zend_class_entry *moon_component_router_exception_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Router_Exception);

PHP_METHOD(Moon_Component_Router_Exception, notFoundException);
PHP_METHOD(Moon_Component_Router_Exception, notSupportedException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_exception_notfoundexception, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_exception_notsupportedexception, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_router_exception_method_entry) {
	PHP_ME(Moon_Component_Router_Exception, notFoundException, arginfo_moon_component_router_exception_notfoundexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Router_Exception, notSupportedException, arginfo_moon_component_router_exception_notsupportedexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
