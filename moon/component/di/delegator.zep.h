
extern zend_class_entry *moon_component_di_delegator_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Delegator);

PHP_METHOD(Moon_Component_DI_Delegator, get);
PHP_METHOD(Moon_Component_DI_Delegator, has);
PHP_METHOD(Moon_Component_DI_Delegator, set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_delegator_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_delegator_has, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_di_delegator_set, 0, 3, Moon\\Component\\DI\\DelegatorInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_delegator_set, 0, 3, IS_OBJECT, "Moon\\Component\\DI\\DelegatorInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_OBJ_INFO(0, container, Psr\\Container\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_delegator_method_entry) {
	PHP_ME(Moon_Component_DI_Delegator, get, arginfo_moon_component_di_delegator_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Delegator, has, arginfo_moon_component_di_delegator_has, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_DI_Delegator, set, arginfo_moon_component_di_delegator_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
