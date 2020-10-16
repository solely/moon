
extern zend_class_entry *moon_component_di_resolver_unresolvedparam_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_UnresolvedParam);

PHP_METHOD(Moon_Component_DI_Resolver_UnresolvedParam, __construct);
PHP_METHOD(Moon_Component_DI_Resolver_UnresolvedParam, getName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_resolver_unresolvedparam___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_unresolvedparam_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_unresolvedparam_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_resolver_unresolvedparam_method_entry) {
	PHP_ME(Moon_Component_DI_Resolver_UnresolvedParam, __construct, arginfo_moon_component_di_resolver_unresolvedparam___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_DI_Resolver_UnresolvedParam, getName, arginfo_moon_component_di_resolver_unresolvedparam_getname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
