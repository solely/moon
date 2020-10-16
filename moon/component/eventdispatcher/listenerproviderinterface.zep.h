
extern zend_class_entry *moon_component_eventdispatcher_listenerproviderinterface_ce;

ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerProviderInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistener, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistener, 0, 1, IS_STRING, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerbefore, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerbefore, 0, 2, IS_STRING, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerafter, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerafter, 0, 2, IS_STRING, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerservice, 0, 3, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerservice, 0, 3, IS_STRING, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerservicebefore, 0, 4, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerservicebefore, 0, 4, IS_STRING, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerserviceafter, 0, 4, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerserviceafter, 0, 4, IS_STRING, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addsubscriber, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addsubscriber, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_eventdispatcher_listenerproviderinterface_addsubscriber, 0, 0, 2)
#define arginfo_moon_component_eventdispatcher_listenerproviderinterface_addsubscriber NULL
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

ZEPHIR_INIT_FUNCS(moon_component_eventdispatcher_listenerproviderinterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Component_EventDispatcher_ListenerProviderInterface, addListener, arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistener)
	PHP_ABSTRACT_ME(Moon_Component_EventDispatcher_ListenerProviderInterface, addListenerBefore, arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerbefore)
	PHP_ABSTRACT_ME(Moon_Component_EventDispatcher_ListenerProviderInterface, addListenerAfter, arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerafter)
	PHP_ABSTRACT_ME(Moon_Component_EventDispatcher_ListenerProviderInterface, addListenerService, arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerservice)
	PHP_ABSTRACT_ME(Moon_Component_EventDispatcher_ListenerProviderInterface, addListenerServiceBefore, arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerservicebefore)
	PHP_ABSTRACT_ME(Moon_Component_EventDispatcher_ListenerProviderInterface, addListenerServiceAfter, arginfo_moon_component_eventdispatcher_listenerproviderinterface_addlistenerserviceafter)
	PHP_ABSTRACT_ME(Moon_Component_EventDispatcher_ListenerProviderInterface, addSubscriber, arginfo_moon_component_eventdispatcher_listenerproviderinterface_addsubscriber)
	PHP_FE_END
};
