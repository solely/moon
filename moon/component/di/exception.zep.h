
extern zend_class_entry *moon_component_di_exception_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Exception);

PHP_METHOD(Moon_Component_DI_Exception, notFoundException);
PHP_METHOD(Moon_Component_DI_Exception, resolverException);
PHP_METHOD(Moon_Component_DI_Exception, resolverNoSuchProperty);
PHP_METHOD(Moon_Component_DI_Exception, resolverMissingParam);
PHP_METHOD(Moon_Component_DI_Exception, resolverCallMethodNotFound);
PHP_METHOD(Moon_Component_DI_Exception, containerExistingException);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_exception_notfoundexception, 0, 1, Moon\\Component\\DI\\Exception\\NotFoundException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_exception_notfoundexception, 0, 1, IS_OBJECT, "Moon\\Component\\DI\\Exception\\NotFoundException", 0)
#endif
	ZEND_ARG_INFO(0, container)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_exception_resolverexception, 0, 1, Moon\\Component\\DI\\Exception\\ResolverException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_exception_resolverexception, 0, 1, IS_OBJECT, "Moon\\Component\\DI\\Exception\\ResolverException", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, exception, Exception, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_exception_resolvernosuchproperty, 0, 1, Moon\\Component\\DI\\Exception\\ResolverException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_exception_resolvernosuchproperty, 0, 1, IS_OBJECT, "Moon\\Component\\DI\\Exception\\ResolverException", 0)
#endif
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_exception_resolvermissingparam, 0, 2, Moon\\Component\\DI\\Exception\\ResolverException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_exception_resolvermissingparam, 0, 2, IS_OBJECT, "Moon\\Component\\DI\\Exception\\ResolverException", 0)
#endif
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_exception_resolvercallmethodnotfound, 0, 2, Moon\\Component\\DI\\Exception\\ResolverException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_exception_resolvercallmethodnotfound, 0, 2, IS_OBJECT, "Moon\\Component\\DI\\Exception\\ResolverException", 0)
#endif
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_exception_containerexistingexception, 0, 1, Moon\\Component\\DI\\Exception\\ContainerExistingException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_exception_containerexistingexception, 0, 1, IS_OBJECT, "Moon\\Component\\DI\\Exception\\ContainerExistingException", 0)
#endif
	ZEND_ARG_INFO(0, container)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_exception_method_entry) {
	PHP_ME(Moon_Component_DI_Exception, notFoundException, arginfo_moon_component_di_exception_notfoundexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_DI_Exception, resolverException, arginfo_moon_component_di_exception_resolverexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_DI_Exception, resolverNoSuchProperty, arginfo_moon_component_di_exception_resolvernosuchproperty, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_DI_Exception, resolverMissingParam, arginfo_moon_component_di_exception_resolvermissingparam, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_DI_Exception, resolverCallMethodNotFound, arginfo_moon_component_di_exception_resolvercallmethodnotfound, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_DI_Exception, containerExistingException, arginfo_moon_component_di_exception_containerexistingexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
