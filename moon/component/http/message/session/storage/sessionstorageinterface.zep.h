
extern zend_class_entry *moon_component_http_message_session_storage_sessionstorageinterface_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_start, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_start, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_isstarted, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_isstarted, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getid, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getid, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_setid, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_setname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_regenerate, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_regenerate, 0, 0, _IS_BOOL, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getbag, 0, 1, Moon\\Component\\Http\\Message\\Session\\SessionBagInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getbag, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\SessionBagInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_registerbag, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bag, Moon\\Component\\Http\\Message\\Session\\SessionBagInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getmetadatabag, 0, 0, Moon\\Component\\Http\\Message\\Session\\Storage\\MetadataBag, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getmetadatabag, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\Storage\\MetadataBag", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_storage_sessionstorageinterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, start, arginfo_moon_component_http_message_session_storage_sessionstorageinterface_start)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, isStarted, arginfo_moon_component_http_message_session_storage_sessionstorageinterface_isstarted)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, getId, arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getid)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, setId, arginfo_moon_component_http_message_session_storage_sessionstorageinterface_setid)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, getName, arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getname)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, setName, arginfo_moon_component_http_message_session_storage_sessionstorageinterface_setname)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, regenerate, arginfo_moon_component_http_message_session_storage_sessionstorageinterface_regenerate)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, save, NULL)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, clear, NULL)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, getBag, arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getbag)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, registerBag, arginfo_moon_component_http_message_session_storage_sessionstorageinterface_registerbag)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, getMetadataBag, arginfo_moon_component_http_message_session_storage_sessionstorageinterface_getmetadatabag)
	PHP_FE_END
};
