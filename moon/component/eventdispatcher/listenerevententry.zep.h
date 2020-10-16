
extern zend_class_entry *moon_component_eventdispatcher_listenerevententry_ce;

ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerEventEntry);

PHP_METHOD(Moon_Component_EventDispatcher_ListenerEventEntry, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_eventdispatcher_listenerevententry___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, listener)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_eventdispatcher_listenerevententry_method_entry) {
	PHP_ME(Moon_Component_EventDispatcher_ListenerEventEntry, __construct, arginfo_moon_component_eventdispatcher_listenerevententry___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
