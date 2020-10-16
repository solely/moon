
extern zend_class_entry *moon_component_http_message_session_session_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Session);

PHP_METHOD(Moon_Component_Http_Message_Session_Session, __construct);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, start);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, has);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, get);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, set);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, all);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, replace);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, remove);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, clear);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, isStarted);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getIterator);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, count);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getUsageIndex);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, isEmpty);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, invalidate);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, migrate);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, save);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getId);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, setId);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getName);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, setName);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getMetadataBag);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, registerBag);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getBag);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getFlashBag);
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getAttributeBag);
zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Session(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_session___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, storage, Moon\\Component\\Http\\Message\\Session\\Storage\\SessionStorageInterface, 0)
	ZEND_ARG_OBJ_INFO(0, attributes, Moon\\Component\\Http\\Message\\Session\\Attribute\\AttributeBagInterface, 0)
	ZEND_ARG_OBJ_INFO(0, flashes, Moon\\Component\\Http\\Message\\Session\\Flash\\FlashBagInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_start, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_start, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_session_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_session_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_all, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_all, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_session_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_session_remove, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_isstarted, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_isstarted, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_session_getiterator, 0, 0, ArrayIterator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_getiterator, 0, 0, IS_OBJECT, "ArrayIterator", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_count, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_getusageindex, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_getusageindex, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_isempty, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_isempty, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_invalidate, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_invalidate, 0, 0, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_migrate, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_migrate, 0, 0, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, destroy, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, destroy)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_getid, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_getid, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_session_setid, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_session_setname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_session_getmetadatabag, 0, 0, Moon\\Component\\Http\\Message\\Session\\Storage\\MetadataBag, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_getmetadatabag, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\Storage\\MetadataBag", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_session_registerbag, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bag, Moon\\Component\\Http\\Message\\Session\\SessionBagInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_session_getbag, 0, 1, Moon\\Component\\Http\\Message\\Session\\SessionBagInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_getbag, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\SessionBagInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_session_getflashbag, 0, 0, Moon\\Component\\Http\\Message\\Session\\Flash\\FlashBagInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_getflashbag, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\Flash\\FlashBagInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_session_getattributebag, 0, 0, Moon\\Component\\Http\\Message\\Session\\Attribute\\AttributeBagInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_session_getattributebag, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\Attribute\\AttributeBagInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_session_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_Session, __construct, arginfo_moon_component_http_message_session_session___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Session_Session, start, arginfo_moon_component_http_message_session_session_start, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, has, arginfo_moon_component_http_message_session_session_has, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, get, arginfo_moon_component_http_message_session_session_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, set, arginfo_moon_component_http_message_session_session_set, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, all, arginfo_moon_component_http_message_session_session_all, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, replace, arginfo_moon_component_http_message_session_session_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, remove, arginfo_moon_component_http_message_session_session_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, isStarted, arginfo_moon_component_http_message_session_session_isstarted, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, getIterator, arginfo_moon_component_http_message_session_session_getiterator, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, count, arginfo_moon_component_http_message_session_session_count, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, getUsageIndex, arginfo_moon_component_http_message_session_session_getusageindex, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, isEmpty, arginfo_moon_component_http_message_session_session_isempty, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, invalidate, arginfo_moon_component_http_message_session_session_invalidate, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, migrate, arginfo_moon_component_http_message_session_session_migrate, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, save, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, getId, arginfo_moon_component_http_message_session_session_getid, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, setId, arginfo_moon_component_http_message_session_session_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, getName, arginfo_moon_component_http_message_session_session_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, setName, arginfo_moon_component_http_message_session_session_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, getMetadataBag, arginfo_moon_component_http_message_session_session_getmetadatabag, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, registerBag, arginfo_moon_component_http_message_session_session_registerbag, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, getBag, arginfo_moon_component_http_message_session_session_getbag, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, getFlashBag, arginfo_moon_component_http_message_session_session_getflashbag, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Session, getAttributeBag, arginfo_moon_component_http_message_session_session_getattributebag, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
