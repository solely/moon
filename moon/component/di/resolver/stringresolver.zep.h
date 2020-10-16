
extern zend_class_entry *moon_component_di_resolver_stringresolver_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_StringResolver);

PHP_METHOD(Moon_Component_DI_Resolver_StringResolver, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_resolver_stringresolver___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, parameters, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, parameters)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_resolver_stringresolver_method_entry) {
	PHP_ME(Moon_Component_DI_Resolver_StringResolver, __construct, arginfo_moon_component_di_resolver_stringresolver___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
