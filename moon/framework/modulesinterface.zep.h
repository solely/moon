
extern zend_class_entry *moon_framework_modulesinterface_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_ModulesInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_modulesinterface_getpath, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_modulesinterface_getpath, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_modulesinterface_build, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Moon\\Component\\DI\\Container, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_modulesinterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Framework_ModulesInterface, boot, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_ModulesInterface, shutdown, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_ModulesInterface, getName, NULL)
	PHP_ABSTRACT_ME(Moon_Framework_ModulesInterface, getPath, arginfo_moon_framework_modulesinterface_getpath)
	PHP_ABSTRACT_ME(Moon_Framework_ModulesInterface, build, arginfo_moon_framework_modulesinterface_build)
	PHP_FE_END
};
