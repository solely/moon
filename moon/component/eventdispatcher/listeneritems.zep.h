
extern zend_class_entry *moon_component_eventdispatcher_listeneritems_ce;

ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerItems);

PHP_METHOD(Moon_Component_EventDispatcher_ListenerItems, __construct);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerItems, createWithPriority);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerItems, createBefore);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerItems, createAfter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_eventdispatcher_listeneritems___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, item)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_eventdispatcher_listeneritems_createwithpriority, 0, 3, Moon\\Component\\EventDispatcher\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listeneritems_createwithpriority, 0, 3, IS_OBJECT, "Moon\\Component\\EventDispatcher\\self", 0)
#endif
	ZEND_ARG_INFO(0, item)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_eventdispatcher_listeneritems_createbefore, 0, 3, Moon\\Component\\EventDispatcher\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listeneritems_createbefore, 0, 3, IS_OBJECT, "Moon\\Component\\EventDispatcher\\self", 0)
#endif
	ZEND_ARG_INFO(0, item)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pivotId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pivotId)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_eventdispatcher_listeneritems_createafter, 0, 3, Moon\\Component\\EventDispatcher\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listeneritems_createafter, 0, 3, IS_OBJECT, "Moon\\Component\\EventDispatcher\\self", 0)
#endif
	ZEND_ARG_INFO(0, item)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pivotId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pivotId)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_eventdispatcher_listeneritems_method_entry) {
	PHP_ME(Moon_Component_EventDispatcher_ListenerItems, __construct, arginfo_moon_component_eventdispatcher_listeneritems___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_EventDispatcher_ListenerItems, createWithPriority, arginfo_moon_component_eventdispatcher_listeneritems_createwithpriority, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerItems, createBefore, arginfo_moon_component_eventdispatcher_listeneritems_createbefore, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerItems, createAfter, arginfo_moon_component_eventdispatcher_listeneritems_createafter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
