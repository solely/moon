
extern zend_class_entry *moon_component_eventdispatcher_listenerprovider_ce;

ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerProvider);

PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, __construct);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, getListenersForEvent);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListener);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListenerBefore);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListenerAfter);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListenerService);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListenerServiceBefore);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListenerServiceAfter);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addSubscriber);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, makeListenerForService);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Psr\\Container\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_getlistenersforevent, 0, 1, IS_ITERABLE, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, event, IS_OBJECT, 0)
#else
	ZEND_ARG_INFO(0, event)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistener, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistener, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, listener)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerbefore, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerbefore, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pivotId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pivotId)
#endif
	ZEND_ARG_INFO(0, listener)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerafter, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerafter, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pivotId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pivotId)
#endif
	ZEND_ARG_INFO(0, listener)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerservice, 0, 3, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerservice, 0, 3, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, methodName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, methodName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, priority)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerservicebefore, 0, 4, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerservicebefore, 0, 4, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pivotId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pivotId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, methodName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, methodName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerserviceafter, 0, 4, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerserviceafter, 0, 4, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pivotId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pivotId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, methodName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, methodName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addsubscriber, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addsubscriber, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_addsubscriber, 0, 0, 2)
#define arginfo_moon_component_eventdispatcher_listenerprovider_addsubscriber NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _class, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _class)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, serviceName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, serviceName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_eventdispatcher_listenerprovider_makelistenerforservice, 0, 0, 2)
	ZEND_ARG_INFO(0, serviceName)
	ZEND_ARG_INFO(0, methodName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_eventdispatcher_listenerprovider_method_entry) {
	PHP_ME(Moon_Component_EventDispatcher_ListenerProvider, __construct, arginfo_moon_component_eventdispatcher_listenerprovider___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProvider, getListenersForEvent, arginfo_moon_component_eventdispatcher_listenerprovider_getlistenersforevent, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProvider, addListener, arginfo_moon_component_eventdispatcher_listenerprovider_addlistener, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProvider, addListenerBefore, arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerbefore, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProvider, addListenerAfter, arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerafter, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProvider, addListenerService, arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerservice, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProvider, addListenerServiceBefore, arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerservicebefore, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProvider, addListenerServiceAfter, arginfo_moon_component_eventdispatcher_listenerprovider_addlistenerserviceafter, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProvider, addSubscriber, arginfo_moon_component_eventdispatcher_listenerprovider_addsubscriber, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerProvider, makeListenerForService, arginfo_moon_component_eventdispatcher_listenerprovider_makelistenerforservice, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
