
extern zend_class_entry *moon_component_di_inject_inject_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Inject_Inject);

PHP_METHOD(Moon_Component_DI_Inject_Inject, __invoke);
PHP_METHOD(Moon_Component_DI_Inject_Inject, setClassName);
PHP_METHOD(Moon_Component_DI_Inject_Inject, getClassName);
PHP_METHOD(Moon_Component_DI_Inject_Inject, setArguments);
PHP_METHOD(Moon_Component_DI_Inject_Inject, getArguments);
PHP_METHOD(Moon_Component_DI_Inject_Inject, setCallMethods);
PHP_METHOD(Moon_Component_DI_Inject_Inject, getCallMethods);
PHP_METHOD(Moon_Component_DI_Inject_Inject, setIsLazy);
PHP_METHOD(Moon_Component_DI_Inject_Inject, getIsLazy);
PHP_METHOD(Moon_Component_DI_Inject_Inject, setCallable);
PHP_METHOD(Moon_Component_DI_Inject_Inject, getCallable);
PHP_METHOD(Moon_Component_DI_Inject_Inject, setObject);
PHP_METHOD(Moon_Component_DI_Inject_Inject, getObject);
zend_object *zephir_init_properties_Moon_Component_DI_Inject_Inject(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setclassname, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setclassname, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_inject_inject_setclassname, 0, 0, 1)
#define arginfo_moon_component_di_inject_inject_setclassname NULL
#endif

	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setarguments, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setarguments, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_inject_inject_setarguments, 0, 0, 1)
#define arginfo_moon_component_di_inject_inject_setarguments NULL
#endif

	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_getarguments, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_getarguments, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setcallmethods, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setcallmethods, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_inject_inject_setcallmethods, 0, 0, 1)
#define arginfo_moon_component_di_inject_inject_setcallmethods NULL
#endif

	ZEND_ARG_ARRAY_INFO(0, callMethods, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_getcallmethods, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_getcallmethods, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setislazy, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setislazy, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_inject_inject_setislazy, 0, 0, 1)
#define arginfo_moon_component_di_inject_inject_setislazy NULL
#endif

	ZEND_ARG_INFO(0, isLazy)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setcallable, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setcallable, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_inject_inject_setcallable, 0, 0, 1)
#define arginfo_moon_component_di_inject_inject_setcallable NULL
#endif

	ZEND_ARG_INFO(0, _callable)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setobject, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_setobject, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_inject_inject_setobject, 0, 0, 1)
#define arginfo_moon_component_di_inject_inject_setobject NULL
#endif

	ZEND_ARG_INFO(0, _object)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_inject_inject_getobject, 0, 0, NULL, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_inject_inject_getobject, 0, 0, IS_OBJECT, "NULL", 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_inject_inject_method_entry) {
	PHP_ME(Moon_Component_DI_Inject_Inject, __invoke, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, setClassName, arginfo_moon_component_di_inject_inject_setclassname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, getClassName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, setArguments, arginfo_moon_component_di_inject_inject_setarguments, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, getArguments, arginfo_moon_component_di_inject_inject_getarguments, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, setCallMethods, arginfo_moon_component_di_inject_inject_setcallmethods, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, getCallMethods, arginfo_moon_component_di_inject_inject_getcallmethods, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, setIsLazy, arginfo_moon_component_di_inject_inject_setislazy, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, getIsLazy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, setCallable, arginfo_moon_component_di_inject_inject_setcallable, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, getCallable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, setObject, arginfo_moon_component_di_inject_inject_setobject, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Inject_Inject, getObject, arginfo_moon_component_di_inject_inject_getobject, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
