
extern zend_class_entry *moon_component_eventdispatcher_subscriberinterface_ce;

ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_SubscriberInterface);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_subscriberinterface_registerlisteners, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_subscriberinterface_registerlisteners, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_eventdispatcher_subscriberinterface_registerlisteners, 0, 0, 1)
#define arginfo_moon_component_eventdispatcher_subscriberinterface_registerlisteners NULL
#endif

	ZEND_ARG_OBJ_INFO(0, proxy, Moon\\Component\\EventDispatcher\\ListenerProviderProxy, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_eventdispatcher_subscriberinterface_method_entry) {
	ZEND_FENTRY(registerListeners, NULL, arginfo_moon_component_eventdispatcher_subscriberinterface_registerlisteners, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
