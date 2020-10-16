
extern zend_class_entry *moon_component_di_resolver_defaultvalueparam_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_DefaultValueParam);

PHP_METHOD(Moon_Component_DI_Resolver_DefaultValueParam, __construct);
PHP_METHOD(Moon_Component_DI_Resolver_DefaultValueParam, getName);
PHP_METHOD(Moon_Component_DI_Resolver_DefaultValueParam, getValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_resolver_defaultvalueparam___construct, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_defaultvalueparam_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_defaultvalueparam_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_resolver_defaultvalueparam_method_entry) {
	PHP_ME(Moon_Component_DI_Resolver_DefaultValueParam, __construct, arginfo_moon_component_di_resolver_defaultvalueparam___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_DI_Resolver_DefaultValueParam, getName, arginfo_moon_component_di_resolver_defaultvalueparam_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_DefaultValueParam, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
