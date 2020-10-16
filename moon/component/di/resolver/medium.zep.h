
extern zend_class_entry *moon_component_di_resolver_medium_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_Medium);

PHP_METHOD(Moon_Component_DI_Resolver_Medium, __construct);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, __invoke);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, merge);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, getClassName);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, getParams);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, getSetters);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, getMutations);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, replaceParams);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, withParams);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, mergeSetters);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, mergeMutations);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, mergeParams);
PHP_METHOD(Moon_Component_DI_Resolver_Medium, isLazy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_resolver_medium___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
	ZEND_ARG_ARRAY_INFO(0, callMethods, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, isLazy, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, isLazy)
#endif
	ZEND_ARG_ARRAY_INFO(0, mutations, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_resolver_medium___invoke, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium___invoke, 0, 1, IS_OBJECT, "NULL", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, reflectedClass, ReflectionClass, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_resolver_medium_merge, 0, 1, Moon\\Component\\DI\\Resolver\\Medium, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_merge, 0, 1, IS_OBJECT, "Moon\\Component\\DI\\Resolver\\Medium", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, mergeBlueprint, Moon\\Component\\DI\\Resolver\\Medium, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_getclassname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_getclassname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_getparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_getparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_getsetters, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_getsetters, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_getmutations, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_getmutations, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_resolver_medium_replaceparams, 0, 1, Moon\\Component\\DI\\Resolver\\Medium, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_replaceparams, 0, 1, IS_OBJECT, "Moon\\Component\\DI\\Resolver\\Medium", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_resolver_medium_withparams, 0, 1, Moon\\Component\\DI\\Resolver\\Medium, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_withparams, 0, 1, IS_OBJECT, "Moon\\Component\\DI\\Resolver\\Medium", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_mergesetters, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_mergesetters, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, mergeBlueprint, Moon\\Component\\DI\\Resolver\\Medium, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_mergemutations, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_mergemutations, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, mergeBlueprint, Moon\\Component\\DI\\Resolver\\Medium, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_mergeparams, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_mergeparams, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, mergeBlueprint, Moon\\Component\\DI\\Resolver\\Medium, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_islazy, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_resolver_medium_islazy, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_resolver_medium_method_entry) {
	PHP_ME(Moon_Component_DI_Resolver_Medium, __construct, arginfo_moon_component_di_resolver_medium___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_DI_Resolver_Medium, __invoke, arginfo_moon_component_di_resolver_medium___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Medium, merge, arginfo_moon_component_di_resolver_medium_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Medium, getClassName, arginfo_moon_component_di_resolver_medium_getclassname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Medium, getParams, arginfo_moon_component_di_resolver_medium_getparams, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Medium, getSetters, arginfo_moon_component_di_resolver_medium_getsetters, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Medium, getMutations, arginfo_moon_component_di_resolver_medium_getmutations, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Medium, replaceParams, arginfo_moon_component_di_resolver_medium_replaceparams, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Medium, withParams, arginfo_moon_component_di_resolver_medium_withparams, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Resolver_Medium, mergeSetters, arginfo_moon_component_di_resolver_medium_mergesetters, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_DI_Resolver_Medium, mergeMutations, arginfo_moon_component_di_resolver_medium_mergemutations, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_DI_Resolver_Medium, mergeParams, arginfo_moon_component_di_resolver_medium_mergeparams, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_DI_Resolver_Medium, isLazy, arginfo_moon_component_di_resolver_medium_islazy, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
