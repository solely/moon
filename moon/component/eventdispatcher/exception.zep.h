
extern zend_class_entry *moon_component_eventdispatcher_exception_ce;

ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_Exception);

PHP_METHOD(Moon_Component_EventDispatcher_Exception, eventDispatcherException);
PHP_METHOD(Moon_Component_EventDispatcher_Exception, unimplementedMethodsException);
PHP_METHOD(Moon_Component_EventDispatcher_Exception, runtimeException);
PHP_METHOD(Moon_Component_EventDispatcher_Exception, containerMissingException);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_eventdispatcher_exception_eventdispatcherexception, 0, 2, Moon\\Component\\EventDispatcher\\Exception\\EventDispatcherException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_exception_eventdispatcherexception, 0, 2, IS_OBJECT, "Moon\\Component\\EventDispatcher\\Exception\\EventDispatcherException", 0)
#endif
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_OBJ_INFO(0, throwable, Throwable, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_eventdispatcher_exception_unimplementedmethodsexception, 0, 2, Moon\\Component\\EventDispatcher\\Exception\\UnimplementedMethodsException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_exception_unimplementedmethodsexception, 0, 2, IS_OBJECT, "Moon\\Component\\EventDispatcher\\Exception\\UnimplementedMethodsException", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_eventdispatcher_exception_runtimeexception, 0, 2, Moon\\Component\\EventDispatcher\\Exception\\RuntimeException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_exception_runtimeexception, 0, 2, IS_OBJECT, "Moon\\Component\\EventDispatcher\\Exception\\RuntimeException", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, msg, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, msg)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
	ZEND_ARG_OBJ_INFO(0, throwable, Throwable, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_eventdispatcher_exception_containermissingexception, 0, 0, Moon\\Component\\EventDispatcher\\Exception\\ContainerMissingException, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_exception_containermissingexception, 0, 0, IS_OBJECT, "Moon\\Component\\EventDispatcher\\Exception\\ContainerMissingException", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_eventdispatcher_exception_method_entry) {
	PHP_ME(Moon_Component_EventDispatcher_Exception, eventDispatcherException, arginfo_moon_component_eventdispatcher_exception_eventdispatcherexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_EventDispatcher_Exception, unimplementedMethodsException, arginfo_moon_component_eventdispatcher_exception_unimplementedmethodsexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_EventDispatcher_Exception, runtimeException, arginfo_moon_component_eventdispatcher_exception_runtimeexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_EventDispatcher_Exception, containerMissingException, arginfo_moon_component_eventdispatcher_exception_containermissingexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
