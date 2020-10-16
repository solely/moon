
extern zend_class_entry *moon_component_di_resolver_resolver_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_Resolver);

PHP_METHOD(Moon_Component_DI_Resolver_Resolver, __construct);
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, __get);
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, __set);
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, resolve);
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, getUnified);
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, getUnifiedParams);
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, getUnifiedParam);
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, getUnifiedMutations);
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, getUnifiedSetters);
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, expandParams);
zend_object *zephir_init_properties_Moon_Component_DI_Resolver_Resolver(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_resolver_resolver___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, reflector, Moon\\Component\\DI\\Resolver\\Reflector, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_resolver___get, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_resolver___get, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_resolver___set, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_resolver___set, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_resolver_resolver___set, 0, 0, 2)
#define arginfo_moon_component_di_resolver_resolver___set NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_resolver_resolver_resolve, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, blueprint, Moon\\Component\\DI\\Resolver\\Medium, 0)
	ZEND_ARG_ARRAY_INFO(0, contextualBlueprints, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_resolver_resolver_getunified, 0, 1, Moon\\Component\\DI\\Resolver\\Medium, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_resolver_getunified, 0, 1, IS_OBJECT, "Moon\\Component\\DI\\Resolver\\Medium", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _class, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _class)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_resolver_resolver_getunifiedparams, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _class, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _class)
#endif
	ZEND_ARG_ARRAY_INFO(0, parent, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_resolver_resolver_getunifiedparam, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, rparam, ReflectionParameter, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _class, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _class)
#endif
	ZEND_ARG_ARRAY_INFO(0, _parent, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_resolver_getunifiedmutations, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_resolver_getunifiedmutations, 0, 2, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _class, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _class)
#endif
	ZEND_ARG_ARRAY_INFO(0, _parent, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_resolver_getunifiedsetters, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_resolver_getunifiedsetters, 0, 2, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _class, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _class)
#endif
	ZEND_ARG_ARRAY_INFO(0, _parent, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_resolver_resolver_expandparams, 0, 1, Moon\\Component\\DI\\Resolver\\Medium, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_resolver_expandparams, 0, 1, IS_OBJECT, "Moon\\Component\\DI\\Resolver\\Medium", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, blueprint, Moon\\Component\\DI\\Resolver\\Medium, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_resolver_resolver_method_entry) {
	PHP_ME(Moon_Component_DI_Resolver_Resolver, __construct, arginfo_moon_component_di_resolver_resolver___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_DI_Resolver_Resolver, __get, arginfo_moon_component_di_resolver_resolver___get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Resolver, __set, arginfo_moon_component_di_resolver_resolver___set, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Resolver, resolve, arginfo_moon_component_di_resolver_resolver_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Resolver, getUnified, arginfo_moon_component_di_resolver_resolver_getunified, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Resolver, getUnifiedParams, arginfo_moon_component_di_resolver_resolver_getunifiedparams, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_DI_Resolver_Resolver, getUnifiedParam, arginfo_moon_component_di_resolver_resolver_getunifiedparam, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_DI_Resolver_Resolver, getUnifiedMutations, arginfo_moon_component_di_resolver_resolver_getunifiedmutations, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_DI_Resolver_Resolver, getUnifiedSetters, arginfo_moon_component_di_resolver_resolver_getunifiedsetters, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_DI_Resolver_Resolver, expandParams, arginfo_moon_component_di_resolver_resolver_expandparams, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
