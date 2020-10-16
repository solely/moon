
extern zend_class_entry *moon_component_http_message_session_attribute_namespacedattributebag_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag);

PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, __construct);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, has);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, get);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, set);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, remove);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, resolveAttributePath);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, resolveKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_namespacedattributebag___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, storageKey, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, storageKey)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, namespaceCharacter, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, namespaceCharacter)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_namespacedattributebag_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_namespacedattributebag_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_namespacedattributebag_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_namespacedattributebag_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_namespacedattributebag_remove, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_namespacedattributebag_resolveattributepath, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, writeContext, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, writeContext)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_namespacedattributebag_resolvekey, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_namespacedattributebag_resolvekey, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_attribute_namespacedattributebag_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, __construct, arginfo_moon_component_http_message_session_attribute_namespacedattributebag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, has, arginfo_moon_component_http_message_session_attribute_namespacedattributebag_has, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, get, arginfo_moon_component_http_message_session_attribute_namespacedattributebag_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, set, arginfo_moon_component_http_message_session_attribute_namespacedattributebag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, remove, arginfo_moon_component_http_message_session_attribute_namespacedattributebag_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, resolveAttributePath, arginfo_moon_component_http_message_session_attribute_namespacedattributebag_resolveattributepath, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, resolveKey, arginfo_moon_component_http_message_session_attribute_namespacedattributebag_resolvekey, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
