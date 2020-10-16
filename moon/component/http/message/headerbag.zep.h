
extern zend_class_entry *moon_component_http_message_headerbag_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_HeaderBag);

PHP_METHOD(Moon_Component_Http_Message_HeaderBag, __construct);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, __toString);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, all);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, keys);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, replace);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, add);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, get);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, set);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, has);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, contains);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, remove);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, getDate);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, addCacheControlDirective);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, hasCacheControlDirective);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, getCacheControlDirective);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, removeCacheControlDirective);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, getIterator);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, count);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, getCacheControlHeader);
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, parseCacheControl);
zend_object *zephir_init_properties_Moon_Component_Http_Message_HeaderBag(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_headerbag___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_all, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_all, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_keys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_keys, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_headerbag_replace, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_headerbag_add, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_get, 0, 1, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_get, 0, 1, IS_STRING, NULL, 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _default, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, _default)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_headerbag_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, values)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, replace, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, replace)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_contains, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_contains, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_headerbag_remove, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_headerbag_getdate, 0, 2, DateTimeInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_getdate, 0, 2, IS_OBJECT, "DateTimeInterface", 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_OBJ_INFO(0, _default, DateTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_headerbag_addcachecontroldirective, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_hascachecontroldirective, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_hascachecontroldirective, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_headerbag_getcachecontroldirective, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_headerbag_removecachecontroldirective, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_headerbag_getiterator, 0, 0, ArrayIterator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_getiterator, 0, 0, IS_OBJECT, "ArrayIterator", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_count, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_parsecachecontrol, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerbag_parsecachecontrol, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, header)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_headerbag_method_entry) {
	PHP_ME(Moon_Component_Http_Message_HeaderBag, __construct, arginfo_moon_component_http_message_headerbag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, __toString, arginfo_moon_component_http_message_headerbag___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, all, arginfo_moon_component_http_message_headerbag_all, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, keys, arginfo_moon_component_http_message_headerbag_keys, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, replace, arginfo_moon_component_http_message_headerbag_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, add, arginfo_moon_component_http_message_headerbag_add, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, get, arginfo_moon_component_http_message_headerbag_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, set, arginfo_moon_component_http_message_headerbag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, has, arginfo_moon_component_http_message_headerbag_has, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, contains, arginfo_moon_component_http_message_headerbag_contains, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, remove, arginfo_moon_component_http_message_headerbag_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, getDate, arginfo_moon_component_http_message_headerbag_getdate, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, addCacheControlDirective, arginfo_moon_component_http_message_headerbag_addcachecontroldirective, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, hasCacheControlDirective, arginfo_moon_component_http_message_headerbag_hascachecontroldirective, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, getCacheControlDirective, arginfo_moon_component_http_message_headerbag_getcachecontroldirective, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, removeCacheControlDirective, arginfo_moon_component_http_message_headerbag_removecachecontroldirective, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, getIterator, arginfo_moon_component_http_message_headerbag_getiterator, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, count, arginfo_moon_component_http_message_headerbag_count, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, getCacheControlHeader, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_Http_Message_HeaderBag, parseCacheControl, arginfo_moon_component_http_message_headerbag_parsecachecontrol, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
