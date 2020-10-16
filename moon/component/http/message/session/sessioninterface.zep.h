
extern zend_class_entry *moon_component_http_message_session_sessioninterface_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_SessionInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_start, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_start, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_getid, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_getid, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_setid, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_setname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_invalidate, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_invalidate, 0, 0, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_migrate, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_migrate, 0, 0, _IS_BOOL, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_all, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_all, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_remove, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_isstarted, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_isstarted, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_registerbag, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bag, Moon\\Component\\Http\\Message\\Session\\SessionBagInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_getbag, 0, 1, Moon\\Component\\Http\\Message\\Session\\SessionBagInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_getbag, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\SessionBagInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_getmetadatabag, 0, 0, Moon\\Component\\Http\\Message\\Session\\Storage\\MetadataBag, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessioninterface_getmetadatabag, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\Storage\\MetadataBag", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_sessioninterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, start, arginfo_moon_component_http_message_session_sessioninterface_start)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, getId, arginfo_moon_component_http_message_session_sessioninterface_getid)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, setId, arginfo_moon_component_http_message_session_sessioninterface_setid)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, getName, arginfo_moon_component_http_message_session_sessioninterface_getname)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, setName, arginfo_moon_component_http_message_session_sessioninterface_setname)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, invalidate, arginfo_moon_component_http_message_session_sessioninterface_invalidate)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, migrate, arginfo_moon_component_http_message_session_sessioninterface_migrate)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, save, NULL)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, has, arginfo_moon_component_http_message_session_sessioninterface_has)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, get, arginfo_moon_component_http_message_session_sessioninterface_get)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, set, arginfo_moon_component_http_message_session_sessioninterface_set)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, all, arginfo_moon_component_http_message_session_sessioninterface_all)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, replace, arginfo_moon_component_http_message_session_sessioninterface_replace)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, remove, arginfo_moon_component_http_message_session_sessioninterface_remove)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, clear, NULL)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, isStarted, arginfo_moon_component_http_message_session_sessioninterface_isstarted)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, registerBag, arginfo_moon_component_http_message_session_sessioninterface_registerbag)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, getBag, arginfo_moon_component_http_message_session_sessioninterface_getbag)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionInterface, getMetadataBag, arginfo_moon_component_http_message_session_sessioninterface_getmetadatabag)
	PHP_FE_END
};
