
extern zend_class_entry *moon_component_http_message_cookie_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Cookie);

PHP_METHOD(Moon_Component_Http_Message_Cookie, fromString);
PHP_METHOD(Moon_Component_Http_Message_Cookie, create);
PHP_METHOD(Moon_Component_Http_Message_Cookie, __construct);
PHP_METHOD(Moon_Component_Http_Message_Cookie, __toString);
PHP_METHOD(Moon_Component_Http_Message_Cookie, getName);
PHP_METHOD(Moon_Component_Http_Message_Cookie, getValue);
PHP_METHOD(Moon_Component_Http_Message_Cookie, getDomain);
PHP_METHOD(Moon_Component_Http_Message_Cookie, getExpiresTime);
PHP_METHOD(Moon_Component_Http_Message_Cookie, getMaxAge);
PHP_METHOD(Moon_Component_Http_Message_Cookie, getPath);
PHP_METHOD(Moon_Component_Http_Message_Cookie, isSecure);
PHP_METHOD(Moon_Component_Http_Message_Cookie, isHttpOnly);
PHP_METHOD(Moon_Component_Http_Message_Cookie, isCleared);
PHP_METHOD(Moon_Component_Http_Message_Cookie, isRaw);
PHP_METHOD(Moon_Component_Http_Message_Cookie, getSameSite);
PHP_METHOD(Moon_Component_Http_Message_Cookie, setSecureDefault);
void zephir_init_static_properties_Moon_Component_Http_Message_Cookie(TSRMLS_D);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_cookie_fromstring, 0, 1, Moon\\Component\\Http\\Message\\Cookie, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_fromstring, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Cookie", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cookie, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, cookie)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, decode, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, decode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_cookie_create, 0, 1, Moon\\Component\\Http\\Message\\Cookie, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_create, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Cookie", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, value)
#endif
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, domain, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, domain)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, secure, _IS_BOOL, 1)
#else
	ZEND_ARG_INFO(0, secure)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, httpOnly, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, httpOnly)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, raw)
#endif
	ZEND_ARG_INFO(0, sameSite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_cookie___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, value)
#endif
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, domain, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, domain)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, secure, _IS_BOOL, 1)
#else
	ZEND_ARG_INFO(0, secure)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, httpOnly, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, httpOnly)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, raw)
#endif
	ZEND_ARG_INFO(0, sameSite)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getvalue, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getvalue, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getdomain, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getdomain, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getexpirestime, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getexpirestime, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getmaxage, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getmaxage, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getpath, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getpath, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_issecure, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_issecure, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_ishttponly, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_ishttponly, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_iscleared, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_iscleared, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_israw, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_israw, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getsamesite, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_getsamesite, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_setsecuredefault, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_cookie_setsecuredefault, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_cookie_setsecuredefault, 0, 0, 1)
#define arginfo_moon_component_http_message_cookie_setsecuredefault NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _default, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, _default)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_cookie_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Cookie, fromString, arginfo_moon_component_http_message_cookie_fromstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, create, arginfo_moon_component_http_message_cookie_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, __construct, arginfo_moon_component_http_message_cookie___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Cookie, __toString, arginfo_moon_component_http_message_cookie___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, getName, arginfo_moon_component_http_message_cookie_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, getValue, arginfo_moon_component_http_message_cookie_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, getDomain, arginfo_moon_component_http_message_cookie_getdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, getExpiresTime, arginfo_moon_component_http_message_cookie_getexpirestime, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, getMaxAge, arginfo_moon_component_http_message_cookie_getmaxage, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, getPath, arginfo_moon_component_http_message_cookie_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, isSecure, arginfo_moon_component_http_message_cookie_issecure, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, isHttpOnly, arginfo_moon_component_http_message_cookie_ishttponly, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, isCleared, arginfo_moon_component_http_message_cookie_iscleared, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, isRaw, arginfo_moon_component_http_message_cookie_israw, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, getSameSite, arginfo_moon_component_http_message_cookie_getsamesite, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Cookie, setSecureDefault, arginfo_moon_component_http_message_cookie_setsecuredefault, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
