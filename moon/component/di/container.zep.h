
extern zend_class_entry *moon_component_di_container_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Container);

PHP_METHOD(Moon_Component_DI_Container, __construct);
PHP_METHOD(Moon_Component_DI_Container, get);
PHP_METHOD(Moon_Component_DI_Container, has);
PHP_METHOD(Moon_Component_DI_Container, set);
PHP_METHOD(Moon_Component_DI_Container, getInstance);
PHP_METHOD(Moon_Component_DI_Container, setDefaultIsLazy);
PHP_METHOD(Moon_Component_DI_Container, getDefaultIsLazy);
zend_object *zephir_init_properties_Moon_Component_DI_Container(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_container___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, inject, Moon\\Component\\DI\\InjectInterface, 0)
	ZEND_ARG_OBJ_INFO(0, delegator, Moon\\Component\\DI\\DelegatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_container_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_container_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_container_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_container_set, 0, 2, Moon\\Component\\DI\\Container, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_container_set, 0, 2, IS_OBJECT, "Moon\\Component\\DI\\Container", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_container_getinstance, 0, 2, Moon\\Component\\DI\\Container, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_container_getinstance, 0, 2, IS_OBJECT, "Moon\\Component\\DI\\Container", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, inject, Moon\\Component\\DI\\InjectInterface, 0)
	ZEND_ARG_OBJ_INFO(0, delegator, Moon\\Component\\DI\\DelegatorInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_container_setdefaultislazy, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_container_setdefaultislazy, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_container_setdefaultislazy, 0, 0, 1)
#define arginfo_moon_component_di_container_setdefaultislazy NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultIsLazy, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, defaultIsLazy)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_container_getdefaultislazy, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_container_getdefaultislazy, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_container_method_entry) {
	PHP_ME(Moon_Component_DI_Container, __construct, arginfo_moon_component_di_container___construct, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_DI_Container, get, arginfo_moon_component_di_container_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Container, has, arginfo_moon_component_di_container_has, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Container, set, arginfo_moon_component_di_container_set, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Container, getInstance, arginfo_moon_component_di_container_getinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_DI_Container, setDefaultIsLazy, arginfo_moon_component_di_container_setdefaultislazy, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Container, getDefaultIsLazy, arginfo_moon_component_di_container_getdefaultislazy, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
