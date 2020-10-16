
extern zend_class_entry *moon_component_http_message_parameterbag_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_ParameterBag);

PHP_METHOD(Moon_Component_Http_Message_ParameterBag, __construct);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, all);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, keys);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, replace);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, add);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, get);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, set);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, has);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, remove);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getAlpha);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getAlnum);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getDigits);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getInt);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getBoolean);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, filter);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getIterator);
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, count);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_parameterbag___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_parameterbag_all, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_parameterbag_all, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_parameterbag_keys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_parameterbag_keys, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_parameterbag_replace, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_parameterbag_add, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_parameterbag_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, _default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_parameterbag_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_parameterbag_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_parameterbag_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_parameterbag_remove, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_parameterbag_getalpha, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _default, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _default)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_parameterbag_getalnum, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _default, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _default)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_parameterbag_getdigits, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _default, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _default)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_parameterbag_getint, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_parameterbag_getint, 0, 1, IS_LONG, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _default, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, _default)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_parameterbag_getboolean, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _default, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, _default)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_parameterbag_filter, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, _default)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filter, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, filter)
#endif
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_parameterbag_getiterator, 0, 0, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_parameterbag_getiterator, 0, 0, IS_OBJECT, "NULL", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_parameterbag_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_parameterbag_count, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_parameterbag_method_entry) {
	PHP_ME(Moon_Component_Http_Message_ParameterBag, __construct, arginfo_moon_component_http_message_parameterbag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, all, arginfo_moon_component_http_message_parameterbag_all, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, keys, arginfo_moon_component_http_message_parameterbag_keys, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, replace, arginfo_moon_component_http_message_parameterbag_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, add, arginfo_moon_component_http_message_parameterbag_add, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, get, arginfo_moon_component_http_message_parameterbag_get, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, set, arginfo_moon_component_http_message_parameterbag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, has, arginfo_moon_component_http_message_parameterbag_has, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, remove, arginfo_moon_component_http_message_parameterbag_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, getAlpha, arginfo_moon_component_http_message_parameterbag_getalpha, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, getAlnum, arginfo_moon_component_http_message_parameterbag_getalnum, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, getDigits, arginfo_moon_component_http_message_parameterbag_getdigits, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, getInt, arginfo_moon_component_http_message_parameterbag_getint, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, getBoolean, arginfo_moon_component_http_message_parameterbag_getboolean, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, filter, arginfo_moon_component_http_message_parameterbag_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, getIterator, arginfo_moon_component_http_message_parameterbag_getiterator, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_ParameterBag, count, arginfo_moon_component_http_message_parameterbag_count, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
