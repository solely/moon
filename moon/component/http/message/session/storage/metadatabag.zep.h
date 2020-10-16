
extern zend_class_entry *moon_component_http_message_session_storage_metadatabag_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_MetadataBag);

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, __construct);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, initialize);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, getLifetime);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, stampNew);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, getStorageKey);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, getCreated);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, getLastUsed);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, clear);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, getName);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, setName);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, stampCreated);
zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Storage_MetadataBag(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, storageKey, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, storageKey)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, updateThreshold, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, updateThreshold)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_initialize, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, _array, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_getlifetime, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_getlifetime, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_stampnew, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_getstoragekey, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_getstoragekey, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_getcreated, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_getcreated, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_getlastused, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_getlastused, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_setname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_stampcreated, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_stampcreated, 0, 0, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_metadatabag_stampcreated, 0, 0, 0)
#define arginfo_moon_component_http_message_session_storage_metadatabag_stampcreated NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_storage_metadatabag_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MetadataBag, __construct, arginfo_moon_component_http_message_session_storage_metadatabag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MetadataBag, initialize, arginfo_moon_component_http_message_session_storage_metadatabag_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MetadataBag, getLifetime, arginfo_moon_component_http_message_session_storage_metadatabag_getlifetime, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MetadataBag, stampNew, arginfo_moon_component_http_message_session_storage_metadatabag_stampnew, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MetadataBag, getStorageKey, arginfo_moon_component_http_message_session_storage_metadatabag_getstoragekey, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MetadataBag, getCreated, arginfo_moon_component_http_message_session_storage_metadatabag_getcreated, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MetadataBag, getLastUsed, arginfo_moon_component_http_message_session_storage_metadatabag_getlastused, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MetadataBag, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MetadataBag, getName, arginfo_moon_component_http_message_session_storage_metadatabag_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MetadataBag, setName, arginfo_moon_component_http_message_session_storage_metadatabag_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MetadataBag, stampCreated, arginfo_moon_component_http_message_session_storage_metadatabag_stampcreated, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
