
extern zend_class_entry *moon_component_http_message_htmlresponse_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_HtmlResponse);

PHP_METHOD(Moon_Component_Http_Message_HtmlResponse, __construct);
PHP_METHOD(Moon_Component_Http_Message_HtmlResponse, createStream);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_htmlresponse___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, html)
	ZEND_ARG_INFO(0, statusCode)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_htmlresponse_createstream, 0, 1, Moon\\Component\\Http\\Message\\Stream, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_htmlresponse_createstream, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Stream", 0)
#endif
	ZEND_ARG_INFO(0, html)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_htmlresponse_method_entry) {
	PHP_ME(Moon_Component_Http_Message_HtmlResponse, __construct, arginfo_moon_component_http_message_htmlresponse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_HtmlResponse, createStream, arginfo_moon_component_http_message_htmlresponse_createstream, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
