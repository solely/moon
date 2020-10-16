
extern zend_class_entry *moon_component_config_config_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Config_Config);

PHP_METHOD(Moon_Component_Config_Config, __construct);
PHP_METHOD(Moon_Component_Config_Config, loadDir);
PHP_METHOD(Moon_Component_Config_Config, loadFiles);
PHP_METHOD(Moon_Component_Config_Config, loadString);
PHP_METHOD(Moon_Component_Config_Config, get);
PHP_METHOD(Moon_Component_Config_Config, __get);
PHP_METHOD(Moon_Component_Config_Config, getInstance);
PHP_METHOD(Moon_Component_Config_Config, resetConfig);
zend_object *zephir_init_properties_Moon_Component_Config_Config(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_config_config___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_config_config_loaddir, 0, 0, 0)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_config_config_loadfiles, 0, 0, 1)
	ZEND_ARG_INFO(0, files)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_config_config_loadstring, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, configStringArr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_config_config_get, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_config_config___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_config_config_getinstance, 0, 0, Moon\\Component\\Config\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_config_getinstance, 0, 0, IS_OBJECT, "Moon\\Component\\Config\\Config", 0)
#endif
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_config_config_method_entry) {
	PHP_ME(Moon_Component_Config_Config, __construct, arginfo_moon_component_config_config___construct, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Config_Config, loadDir, arginfo_moon_component_config_config_loaddir, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Config_Config, loadFiles, arginfo_moon_component_config_config_loadfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Config_Config, loadString, arginfo_moon_component_config_config_loadstring, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Config_Config, get, arginfo_moon_component_config_config_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Config_Config, __get, arginfo_moon_component_config_config___get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Config_Config, getInstance, arginfo_moon_component_config_config_getinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Config_Config, resetConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
