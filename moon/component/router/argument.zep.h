
extern zend_class_entry *moon_component_router_argument_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Router_Argument);

PHP_METHOD(Moon_Component_Router_Argument, resolverArgument);
PHP_METHOD(Moon_Component_Router_Argument, getType);
PHP_METHOD(Moon_Component_Router_Argument, getRequestClass);
PHP_METHOD(Moon_Component_Router_Argument, isRequestClass);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_argument_resolverargument, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_argument_resolverargument, 0, 2, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_argument_gettype, 0, 2, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_argument_gettype, 0, 2, IS_STRING, NULL, 1)
#endif
	ZEND_ARG_OBJ_INFO(0, parameter, ReflectionParameter, 0)
	ZEND_ARG_INFO(0, _function)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_argument_isrequestclass, 0, 0, 1)
	ZEND_ARG_INFO(0, _class)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_router_argument_method_entry) {
	PHP_ME(Moon_Component_Router_Argument, resolverArgument, arginfo_moon_component_router_argument_resolverargument, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Argument, getType, arginfo_moon_component_router_argument_gettype, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Router_Argument, getRequestClass, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Router_Argument, isRequestClass, arginfo_moon_component_router_argument_isrequestclass, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
