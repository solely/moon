
extern zend_class_entry *moon_component_config_reader_loader_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Config_Reader_Loader);

PHP_METHOD(Moon_Component_Config_Reader_Loader, glob);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_config_reader_loader_glob, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, flags)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_config_reader_loader_method_entry) {
	PHP_ME(Moon_Component_Config_Reader_Loader, glob, arginfo_moon_component_config_reader_loader_glob, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
