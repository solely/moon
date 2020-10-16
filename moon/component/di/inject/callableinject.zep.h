
extern zend_class_entry *moon_component_di_inject_callableinject_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Inject_CallableInject);

PHP_METHOD(Moon_Component_DI_Inject_CallableInject, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_inject_callableinject___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_OBJ_INFO(0, container, Moon\\Component\\DI\\MoonContainerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_inject_callableinject_method_entry) {
	PHP_ME(Moon_Component_DI_Inject_CallableInject, __construct, arginfo_moon_component_di_inject_callableinject___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
