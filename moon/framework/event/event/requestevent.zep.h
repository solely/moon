
extern zend_class_entry *moon_framework_event_event_requestevent_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_RequestEvent);

PHP_METHOD(Moon_Framework_Event_Event_RequestEvent, getResponse);
PHP_METHOD(Moon_Framework_Event_Event_RequestEvent, setResponse);
PHP_METHOD(Moon_Framework_Event_Event_RequestEvent, hasResponse);
PHP_METHOD(Moon_Framework_Event_Event_RequestEvent, setRoute);
PHP_METHOD(Moon_Framework_Event_Event_RequestEvent, getRoute);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_requestevent_setresponse, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_requestevent_setresponse, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_requestevent_setresponse, 0, 0, 1)
#define arginfo_moon_framework_event_event_requestevent_setresponse NULL
#endif

	ZEND_ARG_OBJ_INFO(0, response, Moon\\Component\\Http\\Message\\Response, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_requestevent_hasresponse, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_requestevent_hasresponse, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_requestevent_setroute, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_requestevent_setroute, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_requestevent_setroute, 0, 0, 1)
#define arginfo_moon_framework_event_event_requestevent_setroute NULL
#endif

	ZEND_ARG_OBJ_INFO(0, route, Moon\\Component\\Router\\Node, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_event_event_requestevent_getroute, 0, 0, Moon\\Component\\Router\\Node, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_requestevent_getroute, 0, 0, IS_OBJECT, "Moon\\Component\\Router\\Node", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_event_event_requestevent_method_entry) {
	PHP_ME(Moon_Framework_Event_Event_RequestEvent, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_RequestEvent, setResponse, arginfo_moon_framework_event_event_requestevent_setresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_RequestEvent, hasResponse, arginfo_moon_framework_event_event_requestevent_hasresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_RequestEvent, setRoute, arginfo_moon_framework_event_event_requestevent_setroute, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_RequestEvent, getRoute, arginfo_moon_framework_event_event_requestevent_getroute, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
