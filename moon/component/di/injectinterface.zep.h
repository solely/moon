
extern zend_class_entry *moon_component_di_injectinterface_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_InjectInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_injectinterface_factory, 0, 0, 2)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_OBJ_INFO(0, moonContainer, Moon\\Component\\DI\\MoonContainerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_injectinterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Component_DI_InjectInterface, factory, arginfo_moon_component_di_injectinterface_factory)
	PHP_FE_END
};
