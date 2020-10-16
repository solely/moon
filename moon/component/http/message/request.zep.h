
extern zend_class_entry *moon_component_http_message_request_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Request);

PHP_METHOD(Moon_Component_Http_Message_Request, __construct);
PHP_METHOD(Moon_Component_Http_Message_Request, getRequestTarget);
PHP_METHOD(Moon_Component_Http_Message_Request, withRequestTarget);
PHP_METHOD(Moon_Component_Http_Message_Request, getMethod);
PHP_METHOD(Moon_Component_Http_Message_Request, withMethod);
PHP_METHOD(Moon_Component_Http_Message_Request, getUri);
PHP_METHOD(Moon_Component_Http_Message_Request, withUri);
PHP_METHOD(Moon_Component_Http_Message_Request, setUri);
PHP_METHOD(Moon_Component_Http_Message_Request, setMethod);
PHP_METHOD(Moon_Component_Http_Message_Request, setBody);
PHP_METHOD(Moon_Component_Http_Message_Request, setHost);
PHP_METHOD(Moon_Component_Http_Message_Request, getHostFromUri);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_request___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_INFO(0, body)
	ZEND_ARG_ARRAY_INFO(0, header, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_getrequesttarget, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_getrequesttarget, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_request_withrequesttarget, 0, 1, Psr\\Http\\Message\\RequestInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_withrequesttarget, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\RequestInterface", 0)
#endif
	ZEND_ARG_INFO(0, requestTarget)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_getmethod, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_getmethod, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_request_withmethod, 0, 1, Psr\\Http\\Message\\RequestInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_withmethod, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\RequestInterface", 0)
#endif
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_request_geturi, 0, 0, Psr\\Http\\Message\\UriInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_geturi, 0, 0, IS_OBJECT, "Psr\\Http\\Message\\UriInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_request_withuri, 0, 1, Psr\\Http\\Message\\RequestInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_withuri, 0, 1, IS_OBJECT, "Psr\\Http\\Message\\RequestInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, uri, Psr\\Http\\Message\\UriInterface, 0)
	ZEND_ARG_INFO(0, preserveHost)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_seturi, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_seturi, 0, 0, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_request_seturi, 0, 0, 0)
#define arginfo_moon_component_http_message_request_seturi NULL
#endif

	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_setmethod, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_setmethod, 0, 0, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_request_setmethod, 0, 0, 0)
#define arginfo_moon_component_http_message_request_setmethod NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, method)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_setbody, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_setbody, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_request_setbody, 0, 0, 1)
#define arginfo_moon_component_http_message_request_setbody NULL
#endif

	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_sethost, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_sethost, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_component_http_message_request_sethost NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_gethostfromuri, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_request_gethostfromuri, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_request_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Request, __construct, arginfo_moon_component_http_message_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Request, getRequestTarget, arginfo_moon_component_http_message_request_getrequesttarget, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Request, withRequestTarget, arginfo_moon_component_http_message_request_withrequesttarget, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Request, getMethod, arginfo_moon_component_http_message_request_getmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Request, withMethod, arginfo_moon_component_http_message_request_withmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Request, getUri, arginfo_moon_component_http_message_request_geturi, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Request, withUri, arginfo_moon_component_http_message_request_withuri, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Request, setUri, arginfo_moon_component_http_message_request_seturi, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Request, setMethod, arginfo_moon_component_http_message_request_setmethod, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Request, setBody, arginfo_moon_component_http_message_request_setbody, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Request, setHost, arginfo_moon_component_http_message_request_sethost, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Request, getHostFromUri, arginfo_moon_component_http_message_request_gethostfromuri, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
