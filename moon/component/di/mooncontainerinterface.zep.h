
extern zend_class_entry *moon_component_di_mooncontainerinterface_ce;

ZEPHIR_INIT_CLASS(Moon_Component_DI_MoonContainerInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_mooncontainerinterface_getdefaultislazy, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_di_mooncontainerinterface_getdefaultislazy, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_di_mooncontainerinterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Component_DI_MoonContainerInterface, getDefaultIsLazy, arginfo_moon_component_di_mooncontainerinterface_getdefaultislazy)
	PHP_FE_END
};
