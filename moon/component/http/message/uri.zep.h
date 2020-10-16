
extern zend_class_entry *moon_component_http_message_uri_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Uri);

PHP_METHOD(Moon_Component_Http_Message_Uri, __construct);
PHP_METHOD(Moon_Component_Http_Message_Uri, getAuthority);
PHP_METHOD(Moon_Component_Http_Message_Uri, withFragment);
PHP_METHOD(Moon_Component_Http_Message_Uri, getFragment);
PHP_METHOD(Moon_Component_Http_Message_Uri, withHost);
PHP_METHOD(Moon_Component_Http_Message_Uri, getHost);
PHP_METHOD(Moon_Component_Http_Message_Uri, withPath);
PHP_METHOD(Moon_Component_Http_Message_Uri, getPath);
PHP_METHOD(Moon_Component_Http_Message_Uri, withPort);
PHP_METHOD(Moon_Component_Http_Message_Uri, getPort);
PHP_METHOD(Moon_Component_Http_Message_Uri, withQuery);
PHP_METHOD(Moon_Component_Http_Message_Uri, getQuery);
PHP_METHOD(Moon_Component_Http_Message_Uri, withScheme);
PHP_METHOD(Moon_Component_Http_Message_Uri, getScheme);
PHP_METHOD(Moon_Component_Http_Message_Uri, withUserInfo);
PHP_METHOD(Moon_Component_Http_Message_Uri, getUserInfo);
PHP_METHOD(Moon_Component_Http_Message_Uri, __toString);
PHP_METHOD(Moon_Component_Http_Message_Uri, parseUri);
PHP_METHOD(Moon_Component_Http_Message_Uri, filterScheme);
PHP_METHOD(Moon_Component_Http_Message_Uri, filterUser);
PHP_METHOD(Moon_Component_Http_Message_Uri, filterHost);
PHP_METHOD(Moon_Component_Http_Message_Uri, filterPort);
PHP_METHOD(Moon_Component_Http_Message_Uri, filterPath);
PHP_METHOD(Moon_Component_Http_Message_Uri, filterQuery);
PHP_METHOD(Moon_Component_Http_Message_Uri, filterFragment);
PHP_METHOD(Moon_Component_Http_Message_Uri, urlEncode);
PHP_METHOD(Moon_Component_Http_Message_Uri, filterParams);
PHP_METHOD(Moon_Component_Http_Message_Uri, createUriString);
PHP_METHOD(Moon_Component_Http_Message_Uri, __clone);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_uri___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getauthority, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getauthority, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_uri_withfragment, 0, 1, Moon\\Component\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_withfragment, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, fragment)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getfragment, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getfragment, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_uri_withhost, 0, 1, Moon\\Component\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_withhost, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_gethost, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_gethost, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_uri_withpath, 0, 1, Moon\\Component\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_withpath, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getpath, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getpath, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_uri_withport, 0, 1, Moon\\Component\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_withport, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getport, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getport, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_uri_withquery, 0, 1, Moon\\Component\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_withquery, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getquery, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getquery, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_uri_withscheme, 0, 1, Moon\\Component\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_withscheme, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getscheme, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getscheme, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_uri_withuserinfo, 0, 1, Moon\\Component\\Http\\Message\\Uri, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_withuserinfo, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Uri", 0)
#endif
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getuserinfo, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_getuserinfo, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_parseuri, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_parseuri, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_uri_parseuri, 0, 0, 1)
#define arginfo_moon_component_http_message_uri_parseuri NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, uri)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterscheme, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterscheme, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, scheme)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filteruser, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filteruser, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, user, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, user)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterhost, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterhost, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, host, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, host)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterport, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterport, 0, 1, IS_LONG, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, scheme)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterpath, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterpath, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterquery, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterquery, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, query, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, query)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterfragment, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterfragment, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fragment, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, fragment)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_urlencode, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_urlencode, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, matches, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterparams, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_filterparams, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, params, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, params)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_createuristring, 0, 5, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_uri_createuristring, 0, 5, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, scheme, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, scheme)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, authority, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, authority)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, query, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, query)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fragment, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, fragment)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_uri_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Uri, __construct, arginfo_moon_component_http_message_uri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Uri, getAuthority, arginfo_moon_component_http_message_uri_getauthority, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, withFragment, arginfo_moon_component_http_message_uri_withfragment, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, getFragment, arginfo_moon_component_http_message_uri_getfragment, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, withHost, arginfo_moon_component_http_message_uri_withhost, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, getHost, arginfo_moon_component_http_message_uri_gethost, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, withPath, arginfo_moon_component_http_message_uri_withpath, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, getPath, arginfo_moon_component_http_message_uri_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, withPort, arginfo_moon_component_http_message_uri_withport, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, getPort, arginfo_moon_component_http_message_uri_getport, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, withQuery, arginfo_moon_component_http_message_uri_withquery, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, getQuery, arginfo_moon_component_http_message_uri_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, withScheme, arginfo_moon_component_http_message_uri_withscheme, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, getScheme, arginfo_moon_component_http_message_uri_getscheme, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, withUserInfo, arginfo_moon_component_http_message_uri_withuserinfo, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, getUserInfo, arginfo_moon_component_http_message_uri_getuserinfo, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Uri, parseUri, arginfo_moon_component_http_message_uri_parseuri, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Uri, filterScheme, arginfo_moon_component_http_message_uri_filterscheme, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Uri, filterUser, arginfo_moon_component_http_message_uri_filteruser, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Uri, filterHost, arginfo_moon_component_http_message_uri_filterhost, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Uri, filterPort, arginfo_moon_component_http_message_uri_filterport, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Uri, filterPath, arginfo_moon_component_http_message_uri_filterpath, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Uri, filterQuery, arginfo_moon_component_http_message_uri_filterquery, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Uri, filterFragment, arginfo_moon_component_http_message_uri_filterfragment, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Uri, urlEncode, arginfo_moon_component_http_message_uri_urlencode, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Uri, filterParams, arginfo_moon_component_http_message_uri_filterparams, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Uri, createUriString, arginfo_moon_component_http_message_uri_createuristring, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Http_Message_Uri, __clone, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
