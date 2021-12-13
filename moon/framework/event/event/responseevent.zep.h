
extern zend_class_entry *moon_framework_event_event_responseevent_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_ResponseEvent);

PHP_METHOD(Moon_Framework_Event_Event_ResponseEvent, __construct);
PHP_METHOD(Moon_Framework_Event_Event_ResponseEvent, getResponse);
PHP_METHOD(Moon_Framework_Event_Event_ResponseEvent, setResponse);
PHP_METHOD(Moon_Framework_Event_Event_ResponseEvent, getRoute);
PHP_METHOD(Moon_Framework_Event_Event_ResponseEvent, setRoute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_responseevent___construct, 0, 0, 5)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_OBJ_INFO(0, response, Moon\\Component\\Http\\Message\\Response, 0)
	ZEND_ARG_OBJ_INFO(0, route, Moon\\Component\\Router\\Node, 0)
	ZEND_ARG_OBJ_INFO(0, router, Moon\\Component\\Router\\Router, 0)
	ZEND_ARG_OBJ_INFO(0, container, Psr\\Container\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_event_event_responseevent_getresponse, 0, 0, Moon\\Component\\Http\\Message\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_responseevent_getresponse, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\Response", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_responseevent_setresponse, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_responseevent_setresponse, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_responseevent_setresponse, 0, 0, 1)
#define arginfo_moon_framework_event_event_responseevent_setresponse NULL
#endif

	ZEND_ARG_OBJ_INFO(0, response, Moon\\Component\\Http\\Message\\Response, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_event_event_responseevent_getroute, 0, 0, Moon\\Component\\Router\\Node, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_responseevent_getroute, 0, 0, IS_OBJECT, "Moon\\Component\\Router\\Node", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_responseevent_setroute, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_responseevent_setroute, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_responseevent_setroute, 0, 0, 1)
#define arginfo_moon_framework_event_event_responseevent_setroute NULL
#endif

	ZEND_ARG_OBJ_INFO(0, route, Moon\\Component\\Router\\Node, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_event_event_responseevent_method_entry) {
	PHP_ME(Moon_Framework_Event_Event_ResponseEvent, __construct, arginfo_moon_framework_event_event_responseevent___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Framework_Event_Event_ResponseEvent, getResponse, arginfo_moon_framework_event_event_responseevent_getresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_ResponseEvent, setResponse, arginfo_moon_framework_event_event_responseevent_setresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_ResponseEvent, getRoute, arginfo_moon_framework_event_event_responseevent_getroute, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_ResponseEvent, setRoute, arginfo_moon_framework_event_event_responseevent_setroute, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
