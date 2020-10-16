
extern zend_class_entry *moon_framework_event_event_controllerargumentsevent_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_ControllerArgumentsEvent);

PHP_METHOD(Moon_Framework_Event_Event_ControllerArgumentsEvent, __construct);
PHP_METHOD(Moon_Framework_Event_Event_ControllerArgumentsEvent, setController);
PHP_METHOD(Moon_Framework_Event_Event_ControllerArgumentsEvent, getController);
PHP_METHOD(Moon_Framework_Event_Event_ControllerArgumentsEvent, setArguments);
PHP_METHOD(Moon_Framework_Event_Event_ControllerArgumentsEvent, getArguments);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_controllerargumentsevent___construct, 0, 0, 5)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_OBJ_INFO(0, router, Moon\\Component\\Router\\Router, 0)
	ZEND_ARG_INFO(0, controller)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
	ZEND_ARG_OBJ_INFO(0, container, Psr\\Container\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_controllerargumentsevent_setcontroller, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_controllerargumentsevent_setcontroller, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_controllerargumentsevent_setcontroller, 0, 0, 1)
#define arginfo_moon_framework_event_event_controllerargumentsevent_setcontroller NULL
#endif

	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_controllerargumentsevent_setarguments, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_controllerargumentsevent_setarguments, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_controllerargumentsevent_setarguments, 0, 0, 1)
#define arginfo_moon_framework_event_event_controllerargumentsevent_setarguments NULL
#endif

	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_controllerargumentsevent_getarguments, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_controllerargumentsevent_getarguments, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_event_event_controllerargumentsevent_method_entry) {
	PHP_ME(Moon_Framework_Event_Event_ControllerArgumentsEvent, __construct, arginfo_moon_framework_event_event_controllerargumentsevent___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Framework_Event_Event_ControllerArgumentsEvent, setController, arginfo_moon_framework_event_event_controllerargumentsevent_setcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_ControllerArgumentsEvent, getController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_ControllerArgumentsEvent, setArguments, arginfo_moon_framework_event_event_controllerargumentsevent_setarguments, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_ControllerArgumentsEvent, getArguments, arginfo_moon_framework_event_event_controllerargumentsevent_getarguments, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
