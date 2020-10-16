
extern zend_class_entry *moon_framework_event_event_kernelevent_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_KernelEvent);

PHP_METHOD(Moon_Framework_Event_Event_KernelEvent, __construct);
PHP_METHOD(Moon_Framework_Event_Event_KernelEvent, getRequest);
PHP_METHOD(Moon_Framework_Event_Event_KernelEvent, setContainer);
PHP_METHOD(Moon_Framework_Event_Event_KernelEvent, getContainer);
PHP_METHOD(Moon_Framework_Event_Event_KernelEvent, getRouter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_kernelevent___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_OBJ_INFO(0, router, Moon\\Component\\Router\\Router, 0)
	ZEND_ARG_OBJ_INFO(0, container, Psr\\Container\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_event_event_kernelevent_getrequest, 0, 0, Moon\\Component\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_kernelevent_getrequest, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\ServerRequest", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_kernelevent_setcontainer, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_kernelevent_setcontainer, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_event_event_kernelevent_setcontainer, 0, 0, 1)
#define arginfo_moon_framework_event_event_kernelevent_setcontainer NULL
#endif

	ZEND_ARG_OBJ_INFO(0, container, Psr\\Container\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_event_event_kernelevent_getcontainer, 0, 0, Psr\\Container\\ContainerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_kernelevent_getcontainer, 0, 0, IS_OBJECT, "Psr\\Container\\ContainerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_event_event_kernelevent_getrouter, 0, 0, Moon\\Component\\Router\\Router, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_event_event_kernelevent_getrouter, 0, 0, IS_OBJECT, "Moon\\Component\\Router\\Router", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_event_event_kernelevent_method_entry) {
	PHP_ME(Moon_Framework_Event_Event_KernelEvent, __construct, arginfo_moon_framework_event_event_kernelevent___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Framework_Event_Event_KernelEvent, getRequest, arginfo_moon_framework_event_event_kernelevent_getrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_KernelEvent, setContainer, arginfo_moon_framework_event_event_kernelevent_setcontainer, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_KernelEvent, getContainer, arginfo_moon_framework_event_event_kernelevent_getcontainer, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Event_Event_KernelEvent, getRouter, arginfo_moon_framework_event_event_kernelevent_getrouter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
