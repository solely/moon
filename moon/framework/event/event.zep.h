
extern zend_class_entry *moon_framework_event_event_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event);

PHP_METHOD(Moon_Framework_Event_Event, registerEvent);
PHP_METHOD(Moon_Framework_Event_Event, registerSubscriber);
PHP_METHOD(Moon_Framework_Event_Event, getEventList);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_registerevent, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Moon\\Component\\DI\\Container, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_registersubscriber, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Moon\\Component\\DI\\Container, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_geteventlist, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_geteventlist, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_event_event_method_entry) {
	PHP_ME(Moon_Framework_Event_Event, registerEvent, arginfo_moon_framework_event_event_registerevent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Framework_Event_Event, registerSubscriber, arginfo_moon_framework_event_event_registersubscriber, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Moon_Framework_Event_Event, getEventList, arginfo_moon_framework_event_event_geteventlist, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
