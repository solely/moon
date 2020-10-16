
extern zend_class_entry *moon_component_http_message_session_flash_autoexpireflashbag_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag);

PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, __construct);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, getName);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, setName);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, initialize);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, add);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, peek);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, peekAll);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, get);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, all);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, setAll);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, set);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, has);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, keys);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, getStorageKey);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, clear);
zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, storageKey, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, storageKey)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_setname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_initialize, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, flashes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_add, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_peek, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_peek, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_ARRAY_INFO(0, _default, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_peekall, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_peekall, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_get, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_get, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_ARRAY_INFO(0, _default, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_all, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_all, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_setall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, messages, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_keys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_keys, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_getstoragekey, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_autoexpireflashbag_getstoragekey, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_flash_autoexpireflashbag_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, __construct, arginfo_moon_component_http_message_session_flash_autoexpireflashbag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, getName, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, setName, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, initialize, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, add, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_add, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, peek, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_peek, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, peekAll, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_peekall, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, get, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, all, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_all, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, setAll, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_setall, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, set, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, has, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_has, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, keys, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_keys, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, getStorageKey, arginfo_moon_component_http_message_session_flash_autoexpireflashbag_getstoragekey, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
