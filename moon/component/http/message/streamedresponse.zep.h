
extern zend_class_entry *moon_component_http_message_streamedresponse_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_StreamedResponse);

PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, __construct);
PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, setCallback);
PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, sendHeaders);
PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, sendContent);
PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, setContent);
PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, getContent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_streamedresponse___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, statusCode)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_streamedresponse_setcallback, 0, 1, Moon\\Component\\Http\\Message\\StreamedResponse, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_streamedresponse_setcallback, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\StreamedResponse", 0)
#endif
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_streamedresponse_sendheaders, 0, 0, Moon\\Component\\Http\\Message\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_streamedresponse_sendheaders, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\self", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_streamedresponse_sendcontent, 0, 0, Moon\\Component\\Http\\Message\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_streamedresponse_sendcontent, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\self", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_streamedresponse_setcontent, 0, 1, Moon\\Component\\Http\\Message\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_streamedresponse_setcontent, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\self", 0)
#endif
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_streamedresponse_method_entry) {
	PHP_ME(Moon_Component_Http_Message_StreamedResponse, __construct, arginfo_moon_component_http_message_streamedresponse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_StreamedResponse, setCallback, arginfo_moon_component_http_message_streamedresponse_setcallback, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_StreamedResponse, sendHeaders, arginfo_moon_component_http_message_streamedresponse_sendheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_StreamedResponse, sendContent, arginfo_moon_component_http_message_streamedresponse_sendcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_StreamedResponse, setContent, arginfo_moon_component_http_message_streamedresponse_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_StreamedResponse, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
