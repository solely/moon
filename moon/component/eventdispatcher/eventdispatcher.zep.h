
extern zend_class_entry *moon_component_eventdispatcher_eventdispatcher_ce;

ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_EventDispatcher);

PHP_METHOD(Moon_Component_EventDispatcher_EventDispatcher, __construct);
PHP_METHOD(Moon_Component_EventDispatcher_EventDispatcher, dispatch);
PHP_METHOD(Moon_Component_EventDispatcher_EventDispatcher, setProvider);
PHP_METHOD(Moon_Component_EventDispatcher_EventDispatcher, getProvider);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_eventdispatcher_eventdispatcher___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, listenerProvider, Psr\\EventDispatcher\\ListenerProviderInterface, 0)
	ZEND_ARG_OBJ_INFO(0, logger, Psr\\Log\\LoggerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_eventdispatcher_eventdispatcher_dispatch, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_eventdispatcher_dispatch, 0, 1, IS_OBJECT, "NULL", 0)
#endif
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_eventdispatcher_setprovider, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_eventdispatcher_setprovider, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_eventdispatcher_eventdispatcher_setprovider, 0, 0, 1)
#define arginfo_moon_component_eventdispatcher_eventdispatcher_setprovider NULL
#endif

	ZEND_ARG_OBJ_INFO(0, provider, Psr\\EventDispatcher\\ListenerProviderInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_eventdispatcher_eventdispatcher_getprovider, 0, 0, Psr\\EventDispatcher\\ListenerProviderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_eventdispatcher_getprovider, 0, 0, IS_OBJECT, "Psr\\EventDispatcher\\ListenerProviderInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_eventdispatcher_eventdispatcher_method_entry) {
	PHP_ME(Moon_Component_EventDispatcher_EventDispatcher, __construct, arginfo_moon_component_eventdispatcher_eventdispatcher___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_EventDispatcher_EventDispatcher, dispatch, arginfo_moon_component_eventdispatcher_eventdispatcher_dispatch, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_EventDispatcher, setProvider, arginfo_moon_component_eventdispatcher_eventdispatcher_setprovider, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_EventDispatcher, getProvider, arginfo_moon_component_eventdispatcher_eventdispatcher_getprovider, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
