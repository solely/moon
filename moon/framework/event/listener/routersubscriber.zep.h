
extern zend_class_entry *moon_framework_event_listener_routersubscriber_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Event_Listener_RouterSubscriber);

PHP_METHOD(Moon_Framework_Event_Listener_RouterSubscriber, onKernelRequest);
PHP_METHOD(Moon_Framework_Event_Listener_RouterSubscriber, onKernelException);
PHP_METHOD(Moon_Framework_Event_Listener_RouterSubscriber, onKernelFinishRequest);
PHP_METHOD(Moon_Framework_Event_Listener_RouterSubscriber, registerListeners);
PHP_METHOD(Moon_Framework_Event_Listener_RouterSubscriber, createNormalResponse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_listener_routersubscriber_onkernelrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, event, Moon\\Framework\\Event\\Event\\RequestEvent, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_listener_routersubscriber_onkernelexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, event, Moon\\Framework\\Event\\Event\\ExceptionEvent, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_listener_routersubscriber_onkernelfinishrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, event, Moon\\Framework\\Event\\Event\\FinishRequestEvent, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_listener_routersubscriber_registerlisteners, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_listener_routersubscriber_registerlisteners, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_listener_routersubscriber_registerlisteners, 0, 0, 1)
#define arginfo_moon_framework_event_listener_routersubscriber_registerlisteners NULL
#endif

	ZEND_ARG_OBJ_INFO(0, proxy, Moon\\Component\\EventDispatcher\\ListenerProviderProxy, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_listener_routersubscriber_createnormalresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_event_listener_routersubscriber_method_entry) {
	PHP_ME(Moon_Framework_Event_Listener_RouterSubscriber, onKernelRequest, arginfo_moon_framework_event_listener_routersubscriber_onkernelrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Listener_RouterSubscriber, onKernelException, arginfo_moon_framework_event_listener_routersubscriber_onkernelexception, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Listener_RouterSubscriber, onKernelFinishRequest, arginfo_moon_framework_event_listener_routersubscriber_onkernelfinishrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Listener_RouterSubscriber, registerListeners, arginfo_moon_framework_event_listener_routersubscriber_registerlisteners, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Framework_Event_Listener_RouterSubscriber, createNormalResponse, arginfo_moon_framework_event_listener_routersubscriber_createnormalresponse, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
