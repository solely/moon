
extern zend_class_entry *moon_framework_event_event_controllerevent_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_ControllerEvent);

PHP_METHOD(Moon_Framework_Event_Event_ControllerEvent, __construct);
PHP_METHOD(Moon_Framework_Event_Event_ControllerEvent, getController);
PHP_METHOD(Moon_Framework_Event_Event_ControllerEvent, setController);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_controllerevent___construct, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_OBJ_INFO(0, router, Moon\\Component\\Router\\Router, 0)
	ZEND_ARG_INFO(0, controller)
	ZEND_ARG_OBJ_INFO(0, container, Psr\\Container\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_controllerevent_setcontroller, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_controllerevent_setcontroller, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_controllerevent_setcontroller, 0, 0, 1)
#define arginfo_moon_framework_event_event_controllerevent_setcontroller NULL
#endif

	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_event_event_controllerevent_method_entry) {
	PHP_ME(Moon_Framework_Event_Event_ControllerEvent, __construct, arginfo_moon_framework_event_event_controllerevent___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Framework_Event_Event_ControllerEvent, getController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_ControllerEvent, setController, arginfo_moon_framework_event_event_controllerevent_setcontroller, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
