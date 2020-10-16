
extern zend_class_entry *moon_component_http_message_session_flash_flashbaginterface_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Flash_FlashBagInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_add, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_peek, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_peek, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_ARRAY_INFO(0, _default, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_peekall, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_peekall, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_get, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_get, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_ARRAY_INFO(0, _default, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_all, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_all, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_setall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, messages, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_keys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_flash_flashbaginterface_keys, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_flash_flashbaginterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, add, arginfo_moon_component_http_message_session_flash_flashbaginterface_add)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, set, arginfo_moon_component_http_message_session_flash_flashbaginterface_set)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, peek, arginfo_moon_component_http_message_session_flash_flashbaginterface_peek)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, peekAll, arginfo_moon_component_http_message_session_flash_flashbaginterface_peekall)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, get, arginfo_moon_component_http_message_session_flash_flashbaginterface_get)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, all, arginfo_moon_component_http_message_session_flash_flashbaginterface_all)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, setAll, arginfo_moon_component_http_message_session_flash_flashbaginterface_setall)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, has, arginfo_moon_component_http_message_session_flash_flashbaginterface_has)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, keys, arginfo_moon_component_http_message_session_flash_flashbaginterface_keys)
	PHP_FE_END
};
