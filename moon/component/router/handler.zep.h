
extern zend_class_entry *moon_component_router_handler_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Router_Handler);

PHP_METHOD(Moon_Component_Router_Handler, resolverHandler);
PHP_METHOD(Moon_Component_Router_Handler, instantiateHandler);
PHP_METHOD(Moon_Component_Router_Handler, createHandler);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_handler_resolverhandler, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_handler_instantiatehandler, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _class, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _class)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_handler_createhandler, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _handler, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _handler)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_router_handler_method_entry) {
	PHP_ME(Moon_Component_Router_Handler, resolverHandler, arginfo_moon_component_router_handler_resolverhandler, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_Handler, instantiateHandler, arginfo_moon_component_router_handler_instantiatehandler, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Router_Handler, createHandler, arginfo_moon_component_router_handler_createhandler, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
