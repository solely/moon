
extern zend_class_entry *moon_component_http_message_session_storage_mockfilesessionstorage_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage);

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, __construct);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, start);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, regenerate);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, save);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, destroy);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, getFilePath);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, read);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_mockfilesessionstorage___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _savePath, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, _savePath)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_OBJ_INFO(0, metaBag, Moon\\Component\\Http\\Message\\Session\\Storage\\MetadataBag, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_start, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_start, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_regenerate, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_regenerate, 0, 0, _IS_BOOL, NULL, 0)
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

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_destroy, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_destroy, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_destroy NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_getfilepath, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_getfilepath, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_read, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_read, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_read NULL
#endif

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_storage_mockfilesessionstorage_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, __construct, arginfo_moon_component_http_message_session_storage_mockfilesessionstorage___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, start, arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_start, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, regenerate, arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_regenerate, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, save, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, destroy, arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_destroy, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, getFilePath, arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_getfilepath, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, read, arginfo_moon_component_http_message_session_storage_mockfilesessionstorage_read, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
