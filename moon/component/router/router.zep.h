
extern zend_class_entry *moon_component_router_router_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Router_Router);

PHP_METHOD(Moon_Component_Router_Router, getHttpMethodList);
PHP_METHOD(Moon_Component_Router_Router, add);
PHP_METHOD(Moon_Component_Router_Router, get);
PHP_METHOD(Moon_Component_Router_Router, post);
PHP_METHOD(Moon_Component_Router_Router, put);
PHP_METHOD(Moon_Component_Router_Router, patch);
PHP_METHOD(Moon_Component_Router_Router, delete);
PHP_METHOD(Moon_Component_Router_Router, options);
PHP_METHOD(Moon_Component_Router_Router, any);
PHP_METHOD(Moon_Component_Router_Router, match);
PHP_METHOD(Moon_Component_Router_Router, group);
PHP_METHOD(Moon_Component_Router_Router, addRoutes);
PHP_METHOD(Moon_Component_Router_Router, dispatch);
zend_object *zephir_init_properties_Moon_Component_Router_Router(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_router_add, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, methods, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_INFO(0, handler)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routeName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routeName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_router_get, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_INFO(0, handler)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routeName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routeName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_router_post, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_INFO(0, handler)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routeName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routeName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_router_put, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_INFO(0, handler)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routeName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routeName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_router_patch, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_INFO(0, handler)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routeName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routeName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_router_delete, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_INFO(0, handler)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routeName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routeName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_router_options, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_INFO(0, handler)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routeName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routeName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_router_any, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
	ZEND_ARG_INFO(0, handler)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, routeName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, routeName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_router_match, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_router_group, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
	ZEND_ARG_INFO(0, _fn)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_router_dispatch, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_router_router_method_entry) {
	PHP_ME(Moon_Component_Router_Router, getHttpMethodList, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Router_Router, add, arginfo_moon_component_router_router_add, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Router, get, arginfo_moon_component_router_router_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Router, post, arginfo_moon_component_router_router_post, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Router, put, arginfo_moon_component_router_router_put, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Router, patch, arginfo_moon_component_router_router_patch, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Router, delete, arginfo_moon_component_router_router_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Router, options, arginfo_moon_component_router_router_options, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Router, any, arginfo_moon_component_router_router_any, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Router, match, arginfo_moon_component_router_router_match, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Router, group, arginfo_moon_component_router_router_group, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Router, addRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Router, dispatch, arginfo_moon_component_router_router_dispatch, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
