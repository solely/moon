
extern zend_class_entry *moon_framework_event_event_exceptionevent_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_ExceptionEvent);

PHP_METHOD(Moon_Framework_Event_Event_ExceptionEvent, __construct);
PHP_METHOD(Moon_Framework_Event_Event_ExceptionEvent, getThrowable);
PHP_METHOD(Moon_Framework_Event_Event_ExceptionEvent, setThrowable);
PHP_METHOD(Moon_Framework_Event_Event_ExceptionEvent, allowCustomResponseCode);
PHP_METHOD(Moon_Framework_Event_Event_ExceptionEvent, isAllowingCustomResponseCode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_exceptionevent___construct, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_OBJ_INFO(0, e, Throwable, 0)
	ZEND_ARG_OBJ_INFO(0, router, Moon\\Component\\Router\\Router, 0)
	ZEND_ARG_OBJ_INFO(0, container, Psr\\Container\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_event_event_exceptionevent_getthrowable, 0, 0, Throwable, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_exceptionevent_getthrowable, 0, 0, IS_OBJECT, "Throwable", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_exceptionevent_setthrowable, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_exceptionevent_setthrowable, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_exceptionevent_setthrowable, 0, 0, 1)
#define arginfo_moon_framework_event_event_exceptionevent_setthrowable NULL
#endif

	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_exceptionevent_allowcustomresponsecode, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_exceptionevent_allowcustomresponsecode, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_framework_event_event_exceptionevent_allowcustomresponsecode NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_exceptionevent_isallowingcustomresponsecode, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_exceptionevent_isallowingcustomresponsecode, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_event_event_exceptionevent_method_entry) {
	PHP_ME(Moon_Framework_Event_Event_ExceptionEvent, __construct, arginfo_moon_framework_event_event_exceptionevent___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Framework_Event_Event_ExceptionEvent, getThrowable, arginfo_moon_framework_event_event_exceptionevent_getthrowable, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_ExceptionEvent, setThrowable, arginfo_moon_framework_event_event_exceptionevent_setthrowable, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_ExceptionEvent, allowCustomResponseCode, arginfo_moon_framework_event_event_exceptionevent_allowcustomresponsecode, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_ExceptionEvent, isAllowingCustomResponseCode, arginfo_moon_framework_event_event_exceptionevent_isallowingcustomresponsecode, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
