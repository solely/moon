
extern zend_class_entry *moon_component_http_message_exception_uploadedfileexception_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Exception_UploadedFileException);

PHP_METHOD(Moon_Component_Http_Message_Exception_UploadedFileException, __construct);
PHP_METHOD(Moon_Component_Http_Message_Exception_UploadedFileException, codeToMessage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_exception_uploadedfileexception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_OBJ_INFO(0, previous, Throwable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_exception_uploadedfileexception_codetomessage, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_exception_uploadedfileexception_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Exception_UploadedFileException, __construct, arginfo_moon_component_http_message_exception_uploadedfileexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Exception_UploadedFileException, codeToMessage, arginfo_moon_component_http_message_exception_uploadedfileexception_codetomessage, ZEND_ACC_PRIVATE)
	PHP_FE_END
};