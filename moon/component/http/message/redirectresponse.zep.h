
extern zend_class_entry *moon_component_http_message_redirectresponse_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_RedirectResponse);

PHP_METHOD(Moon_Component_Http_Message_RedirectResponse, __construct);
PHP_METHOD(Moon_Component_Http_Message_RedirectResponse, setTargetUrl);
PHP_METHOD(Moon_Component_Http_Message_RedirectResponse, getTargetUrl);
PHP_METHOD(Moon_Component_Http_Message_RedirectResponse, createStream);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_redirectresponse___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statusCode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, statusCode)
#endif
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_redirectresponse_settargeturl, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_redirectresponse_gettargeturl, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_redirectresponse_gettargeturl, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_redirectresponse_createstream, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, data)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_redirectresponse_method_entry) {
	PHP_ME(Moon_Component_Http_Message_RedirectResponse, __construct, arginfo_moon_component_http_message_redirectresponse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_RedirectResponse, setTargetUrl, arginfo_moon_component_http_message_redirectresponse_settargeturl, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_RedirectResponse, getTargetUrl, arginfo_moon_component_http_message_redirectresponse_gettargeturl, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_RedirectResponse, createStream, arginfo_moon_component_http_message_redirectresponse_createstream, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
