
extern zend_class_entry *moon_component_http_message_session_storage_nativesessionstorage_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage);

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, __construct);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getSaveHandler);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, start);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getId);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setId);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getName);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setName);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, regenerate);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, save);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, clear);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, registerBag);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getBag);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setMetadataBag);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getMetadataBag);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, isStarted);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setOptions);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setSaveHandler);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, loadSession);
zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Storage_NativeSessionStorage(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_OBJ_INFO(0, metaBag, Moon\\Component\\Http\\Message\\Session\\Storage\\MetadataBag, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_start, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_start, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_getid, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_getid, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_setid, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_setname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_regenerate, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_regenerate, 0, 0, _IS_BOOL, NULL, 0)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_registerbag, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bag, Moon\\Component\\Http\\Message\\Session\\SessionBagInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_getbag, 0, 1, Moon\\Component\\Http\\Message\\Session\\SessionBagInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_getbag, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\SessionBagInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_setmetadatabag, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, metaBag, Moon\\Component\\Http\\Message\\Session\\Storage\\MetadataBag, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_getmetadatabag, 0, 0, Moon\\Component\\Http\\Message\\Session\\Storage\\MetadataBag, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_getmetadatabag, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\Storage\\MetadataBag", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_isstarted, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_isstarted, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_setsavehandler, 0, 0, 0)
	ZEND_ARG_INFO(0, saveHandler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_nativesessionstorage_loadsession, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, session, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_storage_nativesessionstorage_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, __construct, arginfo_moon_component_http_message_session_storage_nativesessionstorage___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getSaveHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, start, arginfo_moon_component_http_message_session_storage_nativesessionstorage_start, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getId, arginfo_moon_component_http_message_session_storage_nativesessionstorage_getid, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setId, arginfo_moon_component_http_message_session_storage_nativesessionstorage_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getName, arginfo_moon_component_http_message_session_storage_nativesessionstorage_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setName, arginfo_moon_component_http_message_session_storage_nativesessionstorage_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, regenerate, arginfo_moon_component_http_message_session_storage_nativesessionstorage_regenerate, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, save, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, registerBag, arginfo_moon_component_http_message_session_storage_nativesessionstorage_registerbag, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getBag, arginfo_moon_component_http_message_session_storage_nativesessionstorage_getbag, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setMetadataBag, arginfo_moon_component_http_message_session_storage_nativesessionstorage_setmetadatabag, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getMetadataBag, arginfo_moon_component_http_message_session_storage_nativesessionstorage_getmetadatabag, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, isStarted, arginfo_moon_component_http_message_session_storage_nativesessionstorage_isstarted, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setOptions, arginfo_moon_component_http_message_session_storage_nativesessionstorage_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setSaveHandler, arginfo_moon_component_http_message_session_storage_nativesessionstorage_setsavehandler, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, loadSession, arginfo_moon_component_http_message_session_storage_nativesessionstorage_loadsession, ZEND_ACC_PROTECTED)
	PHP_FE_END
};