
extern zend_class_entry *moon_component_http_message_session_sessionbagproxy_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_SessionBagProxy);

PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, __construct);
PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, getBag);
PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, isEmpty);
PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, getName);
PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, initialize);
PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, getStorageKey);
PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, bag, Moon\\Component\\Http\\Message\\Session\\SessionBagInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, usageIndex)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy_getbag, 0, 0, Moon\\Component\\Http\\Message\\Session\\SessionBagInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy_getbag, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\SessionBagInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy_isempty, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy_isempty, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy_initialize, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy_initialize, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy_initialize, 0, 0, 1)
#define arginfo_moon_component_http_message_session_sessionbagproxy_initialize NULL
#endif

	ZEND_ARG_ARRAY_INFO(0, _array, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy_getstoragekey, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionbagproxy_getstoragekey, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_sessionbagproxy_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_SessionBagProxy, __construct, arginfo_moon_component_http_message_session_sessionbagproxy___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Session_SessionBagProxy, getBag, arginfo_moon_component_http_message_session_sessionbagproxy_getbag, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_SessionBagProxy, isEmpty, arginfo_moon_component_http_message_session_sessionbagproxy_isempty, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_SessionBagProxy, getName, arginfo_moon_component_http_message_session_sessionbagproxy_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_SessionBagProxy, initialize, arginfo_moon_component_http_message_session_sessionbagproxy_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_SessionBagProxy, getStorageKey, arginfo_moon_component_http_message_session_sessionbagproxy_getstoragekey, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_SessionBagProxy, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
