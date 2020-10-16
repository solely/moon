
extern zend_class_entry *moon_component_di_inject_stringinject_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_Inject_StringInject);

PHP_METHOD(Moon_Component_DI_Inject_StringInject, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_di_inject_stringinject___construct, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, parameters, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, parameters)
#endif
	ZEND_ARG_OBJ_INFO(0, container, Moon\\Component\\DI\\MoonContainerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_inject_stringinject_method_entry) {
	PHP_ME(Moon_Component_DI_Inject_StringInject, __construct, arginfo_moon_component_di_inject_stringinject___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
