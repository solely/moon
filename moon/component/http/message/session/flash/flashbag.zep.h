
extern zend_class_entry *moon_component_http_message_session_flash_flashbag_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Flash_FlashBag);

PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, __construct);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, getName);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, setName);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, initialize);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, add);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, peek);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, peekAll);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, get);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, all);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, set);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, setAll);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, has);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, keys);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, getStorageKey);
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, clear);
zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Flash_FlashBag(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, storageKey, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, storageKey)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_setname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_initialize, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, flashes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_add, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_peek, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_peek, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_ARRAY_INFO(0, _default, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_peekall, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_peekall, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_get, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_get, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_ARRAY_INFO(0, _default, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_all, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_all, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_setall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, messages, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_keys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_keys, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_getstoragekey, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbag_getstoragekey, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_flash_flashbag_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, __construct, arginfo_moon_component_http_message_session_flash_flashbag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, getName, arginfo_moon_component_http_message_session_flash_flashbag_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, setName, arginfo_moon_component_http_message_session_flash_flashbag_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, initialize, arginfo_moon_component_http_message_session_flash_flashbag_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, add, arginfo_moon_component_http_message_session_flash_flashbag_add, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, peek, arginfo_moon_component_http_message_session_flash_flashbag_peek, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, peekAll, arginfo_moon_component_http_message_session_flash_flashbag_peekall, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, get, arginfo_moon_component_http_message_session_flash_flashbag_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, all, arginfo_moon_component_http_message_session_flash_flashbag_all, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, set, arginfo_moon_component_http_message_session_flash_flashbag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, setAll, arginfo_moon_component_http_message_session_flash_flashbag_setall, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, has, arginfo_moon_component_http_message_session_flash_flashbag_has, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, keys, arginfo_moon_component_http_message_session_flash_flashbag_keys, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, getStorageKey, arginfo_moon_component_http_message_session_flash_flashbag_getstoragekey, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Flash_FlashBag, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
