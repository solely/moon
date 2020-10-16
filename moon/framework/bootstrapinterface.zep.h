
extern zend_class_entry *moon_framework_bootstrapinterface_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_BootstrapInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_bootstrapinterface_getmodule, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_bootstrapinterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Framework_BootstrapInterface, registerModules, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_BootstrapInterface, boot, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_BootstrapInterface, shutdown, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_BootstrapInterface, getModules, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_BootstrapInterface, getModule, arginfo_moon_framework_bootstrapinterface_getmodule)
	PHP_ABSTRACT_ME(Moon_Framework_BootstrapInterface, getProjectDir, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_BootstrapInterface, getContainer, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_BootstrapInterface, getLogDir, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_BootstrapInterface, getConfigDir, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_BootstrapInterface, getServicesDir, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_BootstrapInterface, getRoutesFile, NULL)
	PHP_FE_END
};
