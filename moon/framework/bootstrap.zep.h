
extern zend_class_entry *moon_framework_bootstrap_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Bootstrap);

PHP_METHOD(Moon_Framework_Bootstrap, handle);
PHP_METHOD(Moon_Framework_Bootstrap, boot);
PHP_METHOD(Moon_Framework_Bootstrap, getKernel);
PHP_METHOD(Moon_Framework_Bootstrap, getRouter);
PHP_METHOD(Moon_Framework_Bootstrap, initializeModules);
PHP_METHOD(Moon_Framework_Bootstrap, initializeContainer);
PHP_METHOD(Moon_Framework_Bootstrap, initializeConfig);
PHP_METHOD(Moon_Framework_Bootstrap, initializeRoutes);
PHP_METHOD(Moon_Framework_Bootstrap, getModule);
PHP_METHOD(Moon_Framework_Bootstrap, getModules);
PHP_METHOD(Moon_Framework_Bootstrap, shutdown);
PHP_METHOD(Moon_Framework_Bootstrap, getProjectDir);
PHP_METHOD(Moon_Framework_Bootstrap, getContainer);
PHP_METHOD(Moon_Framework_Bootstrap, getLogDir);
PHP_METHOD(Moon_Framework_Bootstrap, getConfigDir);
PHP_METHOD(Moon_Framework_Bootstrap, getServicesDir);
PHP_METHOD(Moon_Framework_Bootstrap, getRoutesFile);
PHP_METHOD(Moon_Framework_Bootstrap, getMoonVersion);
PHP_METHOD(Moon_Framework_Bootstrap, getMoonVersionId);
zend_object *zephir_init_properties_Moon_Framework_Bootstrap(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_bootstrap_handle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_bootstrap_getmodule, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_bootstrap_method_entry) {
	PHP_ME(Moon_Framework_Bootstrap, handle, arginfo_moon_framework_bootstrap_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, boot, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, getKernel, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Framework_Bootstrap, getRouter, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Framework_Bootstrap, initializeModules, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Framework_Bootstrap, initializeContainer, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Framework_Bootstrap, initializeConfig, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Framework_Bootstrap, initializeRoutes, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Framework_Bootstrap, getModule, arginfo_moon_framework_bootstrap_getmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, shutdown, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, getProjectDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, getContainer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, getLogDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, getConfigDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, getServicesDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, getRoutesFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, getMoonVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Bootstrap, getMoonVersionId, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
