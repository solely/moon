
extern zend_class_entry *moon_component_router_node_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Router_Node);

PHP_METHOD(Moon_Component_Router_Node, __construct);
PHP_METHOD(Moon_Component_Router_Node, setPathInfo);
PHP_METHOD(Moon_Component_Router_Node, getPathInfo);
PHP_METHOD(Moon_Component_Router_Node, setHandler);
PHP_METHOD(Moon_Component_Router_Node, getHandler);
PHP_METHOD(Moon_Component_Router_Node, setRouteName);
PHP_METHOD(Moon_Component_Router_Node, getRouteName);
PHP_METHOD(Moon_Component_Router_Node, setPriority);
PHP_METHOD(Moon_Component_Router_Node, getPriority);
PHP_METHOD(Moon_Component_Router_Node, setParameters);
PHP_METHOD(Moon_Component_Router_Node, getParameters);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_node___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, pathInfo)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, routeName)
	ZEND_ARG_INFO(0, priority)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_router_node_setpathinfo, 0, 1, Moon\\Component\\Router\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_node_setpathinfo, 0, 1, IS_OBJECT, "Moon\\Component\\Router\\self", 0)
#endif
	ZEND_ARG_INFO(0, pathInfo)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_router_node_sethandler, 0, 1, Moon\\Component\\Router\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_node_sethandler, 0, 1, IS_OBJECT, "Moon\\Component\\Router\\self", 0)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_router_node_setroutename, 0, 1, Moon\\Component\\Router\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_node_setroutename, 0, 1, IS_OBJECT, "Moon\\Component\\Router\\self", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routeName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routeName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_node_getroutename, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_node_getroutename, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_router_node_setpriority, 0, 1, Moon\\Component\\Router\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_node_setpriority, 0, 1, IS_OBJECT, "Moon\\Component\\Router\\self", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_node_getpriority, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_node_getpriority, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_router_node_setparameters, 0, 1, Moon\\Component\\Router\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_node_setparameters, 0, 1, IS_OBJECT, "Moon\\Component\\Router\\self", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_node_getparameters, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_node_getparameters, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_router_node_method_entry) {
	PHP_ME(Moon_Component_Router_Node, __construct, arginfo_moon_component_router_node___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Router_Node, setPathInfo, arginfo_moon_component_router_node_setpathinfo, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Node, getPathInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Node, setHandler, arginfo_moon_component_router_node_sethandler, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Node, getHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Node, setRouteName, arginfo_moon_component_router_node_setroutename, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Node, getRouteName, arginfo_moon_component_router_node_getroutename, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Node, setPriority, arginfo_moon_component_router_node_setpriority, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Node, getPriority, arginfo_moon_component_router_node_getpriority, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Node, setParameters, arginfo_moon_component_router_node_setparameters, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Node, getParameters, arginfo_moon_component_router_node_getparameters, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
