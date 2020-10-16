
extern zend_class_entry *moon_component_http_message_response_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Response);

PHP_METHOD(Moon_Component_Http_Message_Response, __construct);
PHP_METHOD(Moon_Component_Http_Message_Response, getStatusCode);
PHP_METHOD(Moon_Component_Http_Message_Response, withStatus);
PHP_METHOD(Moon_Component_Http_Message_Response, getReasonPhrase);
PHP_METHOD(Moon_Component_Http_Message_Response, setStatusCode);
PHP_METHOD(Moon_Component_Http_Message_Response, isRedirect);
PHP_METHOD(Moon_Component_Http_Message_Response, isEmpty);
PHP_METHOD(Moon_Component_Http_Message_Response, isSuccessful);
PHP_METHOD(Moon_Component_Http_Message_Response, isRedirection);
PHP_METHOD(Moon_Component_Http_Message_Response, isClientError);
PHP_METHOD(Moon_Component_Http_Message_Response, isServerError);
PHP_METHOD(Moon_Component_Http_Message_Response, isOk);
PHP_METHOD(Moon_Component_Http_Message_Response, isForbidden);
PHP_METHOD(Moon_Component_Http_Message_Response, isNotFound);
PHP_METHOD(Moon_Component_Http_Message_Response, send);
PHP_METHOD(Moon_Component_Http_Message_Response, closeOutputBuffers);
PHP_METHOD(Moon_Component_Http_Message_Response, sendHeaders);
PHP_METHOD(Moon_Component_Http_Message_Response, sendContent);
void zephir_init_static_properties_Moon_Component_Http_Message_Response(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_response___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, statusCode)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_getstatuscode, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_getstatuscode, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_response_withstatus, 0, 1, Moon\\Component\\Http\\Message\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_withstatus, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Response", 0)
#endif
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, reasonPhrase)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_setstatuscode, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_setstatuscode, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_response_setstatuscode, 0, 0, 1)
#define arginfo_moon_component_http_message_response_setstatuscode NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statusCode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, statusCode)
#endif
	ZEND_ARG_INFO(0, reasonPhrase)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isredirect, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isredirect, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isempty, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isempty, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_issuccessful, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_issuccessful, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isredirection, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isredirection, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isclienterror, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isclienterror, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isservererror, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isservererror, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isok, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isok, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isforbidden, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isforbidden, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isnotfound, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_isnotfound, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_response_send, 0, 0, Moon\\Component\\Http\\Message\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_send, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\self", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_closeoutputbuffers, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_closeoutputbuffers, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_response_closeoutputbuffers, 0, 0, 2)
#define arginfo_moon_component_http_message_response_closeoutputbuffers NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, targetLevel, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, targetLevel)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, flush, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, flush)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_response_sendheaders, 0, 0, Moon\\Component\\Http\\Message\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_sendheaders, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\self", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_response_sendcontent, 0, 0, Moon\\Component\\Http\\Message\\self, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_response_sendcontent, 0, 0, IS_OBJECT, "Moon\\Component\\Http\\Message\\self", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_response_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Response, __construct, arginfo_moon_component_http_message_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Response, getStatusCode, arginfo_moon_component_http_message_response_getstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, withStatus, arginfo_moon_component_http_message_response_withstatus, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, getReasonPhrase, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, setStatusCode, arginfo_moon_component_http_message_response_setstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, isRedirect, arginfo_moon_component_http_message_response_isredirect, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, isEmpty, arginfo_moon_component_http_message_response_isempty, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, isSuccessful, arginfo_moon_component_http_message_response_issuccessful, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, isRedirection, arginfo_moon_component_http_message_response_isredirection, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, isClientError, arginfo_moon_component_http_message_response_isclienterror, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, isServerError, arginfo_moon_component_http_message_response_isservererror, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, isOk, arginfo_moon_component_http_message_response_isok, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, isForbidden, arginfo_moon_component_http_message_response_isforbidden, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, isNotFound, arginfo_moon_component_http_message_response_isnotfound, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, send, arginfo_moon_component_http_message_response_send, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, closeOutputBuffers, arginfo_moon_component_http_message_response_closeoutputbuffers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Http_Message_Response, sendHeaders, arginfo_moon_component_http_message_response_sendheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Response, sendContent, arginfo_moon_component_http_message_response_sendcontent, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
