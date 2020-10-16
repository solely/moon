
extern zend_class_entry *moon_component_http_message_uploadedfile_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_UploadedFile);

PHP_METHOD(Moon_Component_Http_Message_UploadedFile, __construct);
PHP_METHOD(Moon_Component_Http_Message_UploadedFile, getSize);
PHP_METHOD(Moon_Component_Http_Message_UploadedFile, getClientFilename);
PHP_METHOD(Moon_Component_Http_Message_UploadedFile, getClientMediaType);
PHP_METHOD(Moon_Component_Http_Message_UploadedFile, getError);
PHP_METHOD(Moon_Component_Http_Message_UploadedFile, getStream);
PHP_METHOD(Moon_Component_Http_Message_UploadedFile, moveTo);
PHP_METHOD(Moon_Component_Http_Message_UploadedFile, check);
PHP_METHOD(Moon_Component_Http_Message_UploadedFile, writeFile);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_uploadedfile___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, clientFilename)
	ZEND_ARG_INFO(0, clientMediaType)
	ZEND_ARG_INFO(0, error)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uploadedfile_getsize, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uploadedfile_getsize, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uploadedfile_getclientfilename, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uploadedfile_getclientfilename, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uploadedfile_getclientmediatype, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uploadedfile_getclientmediatype, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uploadedfile_geterror, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uploadedfile_geterror, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_uploadedfile_getstream, 0, 0, Psr\\Http\\Message\\StreamInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uploadedfile_getstream, 0, 0, IS_OBJECT, "Psr\\Http\\Message\\StreamInterface", 0)
#endif
	ZEND_ARG_INFO(0, isCheck)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_uploadedfile_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uploadedfile_check, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uploadedfile_check, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_component_http_message_uploadedfile_check NULL
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_uploadedfile_writefile, 0, 0, 1)
	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_uploadedfile_method_entry) {
	PHP_ME(Moon_Component_Http_Message_UploadedFile, __construct, arginfo_moon_component_http_message_uploadedfile___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_UploadedFile, getSize, arginfo_moon_component_http_message_uploadedfile_getsize, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_UploadedFile, getClientFilename, arginfo_moon_component_http_message_uploadedfile_getclientfilename, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_UploadedFile, getClientMediaType, arginfo_moon_component_http_message_uploadedfile_getclientmediatype, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_UploadedFile, getError, arginfo_moon_component_http_message_uploadedfile_geterror, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_UploadedFile, getStream, arginfo_moon_component_http_message_uploadedfile_getstream, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_UploadedFile, moveTo, arginfo_moon_component_http_message_uploadedfile_moveto, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_UploadedFile, check, arginfo_moon_component_http_message_uploadedfile_check, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_UploadedFile, writeFile, arginfo_moon_component_http_message_uploadedfile_writefile, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
