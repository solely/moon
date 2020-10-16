
extern zend_class_entry *moon_component_di_resolver_reflector_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_Reflector);

PHP_METHOD(Moon_Component_DI_Resolver_Reflector, __construct);
PHP_METHOD(Moon_Component_DI_Resolver_Reflector, getInstance);
PHP_METHOD(Moon_Component_DI_Resolver_Reflector, __sleep);
PHP_METHOD(Moon_Component_DI_Resolver_Reflector, getClass);
PHP_METHOD(Moon_Component_DI_Resolver_Reflector, getParams);
PHP_METHOD(Moon_Component_DI_Resolver_Reflector, getTraits);
zend_object *zephir_init_properties_Moon_Component_DI_Resolver_Reflector(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_resolver_reflector_getinstance, 0, 0, Moon\\Component\\DI\\Resolver\\Reflector, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_reflector_getinstance, 0, 0, IS_OBJECT, "Moon\\Component\\DI\\Resolver\\Reflector", 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_reflector___sleep, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_reflector___sleep, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_resolver_reflector_getclass, 0, 1, ReflectionClass, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_reflector_getclass, 0, 1, IS_OBJECT, "ReflectionClass", 0)
#endif
	ZEND_ARG_INFO(0, _class)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_reflector_getparams, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_reflector_getparams, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _class)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_reflector_gettraits, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_reflector_gettraits, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _class)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_resolver_reflector_method_entry) {
	PHP_ME(Moon_Component_DI_Resolver_Reflector, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_DI_Resolver_Reflector, getInstance, arginfo_moon_component_di_resolver_reflector_getinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_DI_Resolver_Reflector, __sleep, arginfo_moon_component_di_resolver_reflector___sleep, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Reflector, getClass, arginfo_moon_component_di_resolver_reflector_getclass, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Reflector, getParams, arginfo_moon_component_di_resolver_reflector_getparams, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Reflector, getTraits, arginfo_moon_component_di_resolver_reflector_gettraits, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
