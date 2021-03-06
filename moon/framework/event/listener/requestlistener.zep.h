
extern zend_class_entry *moon_framework_event_listener_requestlistener_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Event_Listener_RequestListener);

PHP_METHOD(Moon_Framework_Event_Listener_RequestListener, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_listener_requestlistener_handle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, event, Moon\\Framework\\Event\\Event\\RequestEvent, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_event_listener_requestlistener_method_entry) {
	PHP_ME(Moon_Framework_Event_Listener_RequestListener, handle, arginfo_moon_framework_event_listener_requestlistener_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
