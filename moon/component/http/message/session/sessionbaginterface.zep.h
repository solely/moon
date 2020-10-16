
extern zend_class_entry *moon_component_http_message_session_sessionbaginterface_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_SessionBagInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbaginterface_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbaginterface_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_sessionbaginterface_initialize, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, _array, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbaginterface_getstoragekey, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbaginterface_getstoragekey, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_sessionbaginterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionBagInterface, getName, arginfo_moon_component_http_message_session_sessionbaginterface_getname)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionBagInterface, initialize, arginfo_moon_component_http_message_session_sessionbaginterface_initialize)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionBagInterface, getStorageKey, arginfo_moon_component_http_message_session_sessionbaginterface_getstoragekey)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_SessionBagInterface, clear, NULL)
	PHP_FE_END
};