
extern zend_class_entry *moon_component_eventdispatcher_event_ce;

ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_Event);

PHP_METHOD(Moon_Component_EventDispatcher_Event, isPropagationStopped);
PHP_METHOD(Moon_Component_EventDispatcher_Event, stopPropagation);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_event_ispropagationstopped, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_event_ispropagationstopped, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_event_stoppropagation, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_event_stoppropagation, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_component_eventdispatcher_event_stoppropagation NULL
#endif

ZEPHIR_INIT_FUNCS(moon_component_eventdispatcher_event_method_entry) {
	PHP_ME(Moon_Component_EventDispatcher_Event, isPropagationStopped, arginfo_moon_component_eventdispatcher_event_ispropagationstopped, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_Event, stopPropagation, arginfo_moon_component_eventdispatcher_event_stoppropagation, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
