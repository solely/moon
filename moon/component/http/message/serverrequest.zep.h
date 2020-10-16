
extern zend_class_entry *moon_component_http_message_serverrequest_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_ServerRequest);

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, __construct);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getFullRequestUrl);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getServerParams);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getCookieParams);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withCookieParams);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getQueryParams);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withQueryParams);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getUploadedFiles);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withUploadedFiles);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getParsedBody);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withParsedBody);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getAttributes);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getAttribute);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withAttribute);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withoutAttribute);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, validateUploadedFiles);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, get);
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, create);
zend_object *zephir_init_properties_Moon_Component_Http_Message_ServerRequest(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_serverrequest___construct, 0, 0, 5)
	ZEND_ARG_INFO(0, serverParams)
	ZEND_ARG_INFO(0, cookieParams)
	ZEND_ARG_INFO(0, queryParams)
	ZEND_ARG_INFO(0, parseBody)
	ZEND_ARG_INFO(0, uploadedFiles)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, protocolVersion)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_ARRAY_INFO(0, header, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_serverrequest_withcookieparams, 0, 1, Moon\\Component\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverrequest_withcookieparams, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, cookies, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_serverrequest_withqueryparams, 0, 1, Moon\\Component\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverrequest_withqueryparams, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, query, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_serverrequest_withuploadedfiles, 0, 1, Moon\\Component\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverrequest_withuploadedfiles, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, uploadedFiles, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_serverrequest_withparsedbody, 0, 1, Moon\\Component\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverrequest_withparsedbody, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverrequest_getattributes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverrequest_getattributes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_serverrequest_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_serverrequest_withattribute, 0, 2, Moon\\Component\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverrequest_withattribute, 0, 2, IS_OBJECT, "Moon\\Component\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_serverrequest_withoutattribute, 0, 1, Moon\\Component\\Http\\Message\\ServerRequest, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverrequest_withoutattribute, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\ServerRequest", 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverrequest_validateuploadedfiles, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverrequest_validateuploadedfiles, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_serverrequest_validateuploadedfiles, 0, 0, 1)
#define arginfo_moon_component_http_message_serverrequest_validateuploadedfiles NULL
#endif

	ZEND_ARG_ARRAY_INFO(0, uploadedFiles, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_serverrequest_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_serverrequest_method_entry) {
	PHP_ME(Moon_Component_Http_Message_ServerRequest, __construct, arginfo_moon_component_http_message_serverrequest___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, getFullRequestUrl, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, getServerParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, getCookieParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, withCookieParams, arginfo_moon_component_http_message_serverrequest_withcookieparams, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, getQueryParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, withQueryParams, arginfo_moon_component_http_message_serverrequest_withqueryparams, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, getUploadedFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, withUploadedFiles, arginfo_moon_component_http_message_serverrequest_withuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, getParsedBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, withParsedBody, arginfo_moon_component_http_message_serverrequest_withparsedbody, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, getAttributes, arginfo_moon_component_http_message_serverrequest_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, getAttribute, arginfo_moon_component_http_message_serverrequest_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, withAttribute, arginfo_moon_component_http_message_serverrequest_withattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, withoutAttribute, arginfo_moon_component_http_message_serverrequest_withoutattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, validateUploadedFiles, arginfo_moon_component_http_message_serverrequest_validateuploadedfiles, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, get, arginfo_moon_component_http_message_serverrequest_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ServerRequest, create, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
