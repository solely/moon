
extern zend_class_entry *moon_component_http_message_session_attribute_attributebaginterface_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebaginterface_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebaginterface_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebaginterface_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebaginterface_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebaginterface_all, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebaginterface_all, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebaginterface_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebaginterface_remove, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_attribute_attributebaginterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, has, arginfo_moon_component_http_message_session_attribute_attributebaginterface_has)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, get, arginfo_moon_component_http_message_session_attribute_attributebaginterface_get)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, set, arginfo_moon_component_http_message_session_attribute_attributebaginterface_set)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, all, arginfo_moon_component_http_message_session_attribute_attributebaginterface_all)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, replace, arginfo_moon_component_http_message_session_attribute_attributebaginterface_replace)
	PHP_ABSTRACT_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, remove, arginfo_moon_component_http_message_session_attribute_attributebaginterface_remove)
	PHP_FE_END
};
