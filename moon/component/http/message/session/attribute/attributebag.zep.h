
extern zend_class_entry *moon_component_http_message_session_attribute_attributebag_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Attribute_AttributeBag);

PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, __construct);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, getName);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, setName);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, initialize);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, getStorageKey);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, has);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, get);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, set);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, all);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, replace);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, remove);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, clear);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, getIterator);
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBag, count);
zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Attribute_AttributeBag(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, storageKey, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, storageKey)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_setname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_initialize, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_getstoragekey, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_getstoragekey, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_all, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_all, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_remove, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_getiterator, 0, 0, ArrayIterator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_getiterator, 0, 0, IS_OBJECT, "ArrayIterator", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_attribute_attributebag_count, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_attribute_attributebag_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, __construct, arginfo_moon_component_http_message_session_attribute_attributebag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, getName, arginfo_moon_component_http_message_session_attribute_attributebag_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, setName, arginfo_moon_component_http_message_session_attribute_attributebag_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, initialize, arginfo_moon_component_http_message_session_attribute_attributebag_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, getStorageKey, arginfo_moon_component_http_message_session_attribute_attributebag_getstoragekey, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, has, arginfo_moon_component_http_message_session_attribute_attributebag_has, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, get, arginfo_moon_component_http_message_session_attribute_attributebag_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, set, arginfo_moon_component_http_message_session_attribute_attributebag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, all, arginfo_moon_component_http_message_session_attribute_attributebag_all, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, replace, arginfo_moon_component_http_message_session_attribute_attributebag_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, remove, arginfo_moon_component_http_message_session_attribute_attributebag_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, getIterator, arginfo_moon_component_http_message_session_attribute_attributebag_getiterator, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Attribute_AttributeBag, count, arginfo_moon_component_http_message_session_attribute_attributebag_count, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
