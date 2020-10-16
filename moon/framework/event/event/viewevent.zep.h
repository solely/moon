
extern zend_class_entry *moon_framework_event_event_viewevent_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_ViewEvent);

PHP_METHOD(Moon_Framework_Event_Event_ViewEvent, __construct);
PHP_METHOD(Moon_Framework_Event_Event_ViewEvent, getControllerResult);
PHP_METHOD(Moon_Framework_Event_Event_ViewEvent, setControllerResult);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_viewevent___construct, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_OBJ_INFO(0, router, Moon\\Component\\Router\\Router, 0)
	ZEND_ARG_INFO(0, controllerResult)
	ZEND_ARG_OBJ_INFO(0, container, Psr\\Container\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_viewevent_setcontrollerresult, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_viewevent_setcontrollerresult, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_viewevent_setcontrollerresult, 0, 0, 1)
#define arginfo_moon_framework_event_event_viewevent_setcontrollerresult NULL
#endif

	ZEND_ARG_INFO(0, controllerResult)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_event_event_viewevent_method_entry) {
	PHP_ME(Moon_Framework_Event_Event_ViewEvent, __construct, arginfo_moon_framework_event_event_viewevent___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Framework_Event_Event_ViewEvent, getControllerResult, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_ViewEvent, setControllerResult, arginfo_moon_framework_event_event_viewevent_setcontrollerresult, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
