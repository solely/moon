
extern zend_class_entry *moon_component_http_message_filebag_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_FileBag);

PHP_METHOD(Moon_Component_Http_Message_FileBag, __construct);
PHP_METHOD(Moon_Component_Http_Message_FileBag, replace);
PHP_METHOD(Moon_Component_Http_Message_FileBag, set);
PHP_METHOD(Moon_Component_Http_Message_FileBag, add);
PHP_METHOD(Moon_Component_Http_Message_FileBag, convertFileInformation);
PHP_METHOD(Moon_Component_Http_Message_FileBag, fixPhpFilesArray);
void zephir_init_static_properties_Moon_Component_Http_Message_FileBag(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_filebag___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_filebag_replace, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, files, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_filebag_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_filebag_add, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, files, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_filebag_convertfileinformation, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_filebag_fixphpfilesarray, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_filebag_fixphpfilesarray, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_filebag_method_entry) {
	PHP_ME(Moon_Component_Http_Message_FileBag, __construct, arginfo_moon_component_http_message_filebag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_FileBag, replace, arginfo_moon_component_http_message_filebag_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_FileBag, set, arginfo_moon_component_http_message_filebag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_FileBag, add, arginfo_moon_component_http_message_filebag_add, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_FileBag, convertFileInformation, arginfo_moon_component_http_message_filebag_convertfileinformation, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_Http_Message_FileBag, fixPhpFilesArray, arginfo_moon_component_http_message_filebag_fixphpfilesarray, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
