
extern zend_class_entry *moon_component_router_routerinterface_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Router_RouterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_routerinterface_dispatch, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_router_routerinterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Component_Router_RouterInterface, addRoutes, NULL)
	PHP_ABSTRACT_ME(Moon_Component_Router_RouterInterface, dispatch, arginfo_moon_component_router_routerinterface_dispatch)
	PHP_FE_END
};
