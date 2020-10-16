
extern zend_class_entry *moon_component_http_message_emptyresponse_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_EmptyResponse);

PHP_METHOD(Moon_Component_Http_Message_EmptyResponse, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_emptyresponse___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, statusCode)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_emptyresponse_method_entry) {
	PHP_ME(Moon_Component_Http_Message_EmptyResponse, __construct, arginfo_moon_component_http_message_emptyresponse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
