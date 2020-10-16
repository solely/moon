
extern zend_class_entry *moon_component_eventdispatcher_listenerproviderproxy_ce;

ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerProviderProxy);

PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderProxy, __construct);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderProxy, addListener);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderProxy, addListenerBefore);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderProxy, addListenerAfter);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderProxy, getRegisteredMethods);
zend_object *zephir_init_properties_Moon_Component_EventDispatcher_ListenerProviderProxy(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderproxy___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, listenerProvider, Moon\\Component\\EventDispatcher\\ListenerProviderInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceClass, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceClass)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderproxy_addlistener, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderproxy_addlistener, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, methodName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, methodName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, id)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderproxy_addlistenerbefore, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderproxy_addlistenerbefore, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pivotId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pivotId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, methodName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, methodName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, id)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderproxy_addlistenerafter, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderproxy_addlistenerafter, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pivotId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pivotId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, methodName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, methodName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, id)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderproxy_getregisteredmethods, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderproxy_getregisteredmethods, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_eventdispatcher_listenerproviderproxy_method_entry) {
	PHP_ME(Moon_Component_EventDispatcher_ListenerProviderProxy, __construct, arginfo_moon_component_eventdispatcher_listenerproviderproxy___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProviderProxy, addListener, arginfo_moon_component_eventdispatcher_listenerproviderproxy_addlistener, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProviderProxy, addListenerBefore, arginfo_moon_component_eventdispatcher_listenerproviderproxy_addlistenerbefore, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProviderProxy, addListenerAfter, arginfo_moon_component_eventdispatcher_listenerproviderproxy_addlistenerafter, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProviderProxy, getRegisteredMethods, arginfo_moon_component_eventdispatcher_listenerproviderproxy_getregisteredmethods, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
