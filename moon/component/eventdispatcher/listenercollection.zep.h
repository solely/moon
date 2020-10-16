
extern zend_class_entry *moon_component_eventdispatcher_listenercollection_ce;

ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerCollection);

PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, rewind);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, next);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, valid);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, current);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, key);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, addItem);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, addItemBefore);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, addItemAfter);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, prioritizePendingItems);
PHP_METHOD(Moon_Component_EventDispatcher_ListenerCollection, enforceUniqueId);
zend_object *zephir_init_properties_Moon_Component_EventDispatcher_ListenerCollection(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenercollection_additem, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenercollection_additem, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, item)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, priority)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenercollection_additembefore, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenercollection_additembefore, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pivotId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pivotId)
#endif
	ZEND_ARG_INFO(0, item)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenercollection_additemafter, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenercollection_additemafter, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pivotId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pivotId)
#endif
	ZEND_ARG_INFO(0, item)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenercollection_prioritizependingitems, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenercollection_prioritizependingitems, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_component_eventdispatcher_listenercollection_prioritizependingitems NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenercollection_enforceuniqueid, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_listenercollection_enforceuniqueid, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_eventdispatcher_listenercollection_method_entry) {
	PHP_ME(Moon_Component_EventDispatcher_ListenerCollection, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerCollection, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerCollection, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerCollection, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerCollection, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerCollection, addItem, arginfo_moon_component_eventdispatcher_listenercollection_additem, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerCollection, addItemBefore, arginfo_moon_component_eventdispatcher_listenercollection_additembefore, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerCollection, addItemAfter, arginfo_moon_component_eventdispatcher_listenercollection_additemafter, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_EventDispatcher_ListenerCollection, prioritizePendingItems, arginfo_moon_component_eventdispatcher_listenercollection_prioritizependingitems, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_EventDispatcher_ListenerCollection, enforceUniqueId, arginfo_moon_component_eventdispatcher_listenercollection_enforceuniqueid, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
