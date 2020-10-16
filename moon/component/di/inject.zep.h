
extern zend_class_entry *moon_component_di_inject_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Inject);

PHP_METHOD(Moon_Component_DI_Inject, factory);
zend_object *zephir_init_properties_Moon_Component_DI_Inject(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_inject_factory, 0, 0, 2)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_OBJ_INFO(0, container, Moon\\Component\\DI\\MoonContainerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_inject_method_entry) {
	PHP_ME(Moon_Component_DI_Inject, factory, arginfo_moon_component_di_inject_factory, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
