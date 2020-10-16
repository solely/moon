
extern zend_class_entry *moon_component_http_message_headerutils_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_HeaderUtils);

PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, __construct);
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, split);
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, combine);
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, toString);
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, quote);
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, unquote);
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, makeDisposition);
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, groupParts);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_split, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_split, 0, 2, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, header)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, separators, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, separators)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_combine, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_combine, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, parts, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_tostring, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_tostring, 0, 2, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, assoc, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, separator, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, separator)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_quote, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_quote, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, s, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, s)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_unquote, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_unquote, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, s, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, s)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_makedisposition, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_makedisposition, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, disposition, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, disposition)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filename)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filenameFallback, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filenameFallback)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_groupparts, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_headerutils_groupparts, 0, 2, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, matches, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, separators, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, separators)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_headerutils_method_entry) {
	PHP_ME(Moon_Component_Http_Message_HeaderUtils, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_HeaderUtils, split, arginfo_moon_component_http_message_headerutils_split, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Http_Message_HeaderUtils, combine, arginfo_moon_component_http_message_headerutils_combine, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Http_Message_HeaderUtils, toString, arginfo_moon_component_http_message_headerutils_tostring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Http_Message_HeaderUtils, quote, arginfo_moon_component_http_message_headerutils_quote, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Http_Message_HeaderUtils, unquote, arginfo_moon_component_http_message_headerutils_unquote, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Http_Message_HeaderUtils, makeDisposition, arginfo_moon_component_http_message_headerutils_makedisposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Http_Message_HeaderUtils, groupParts, arginfo_moon_component_http_message_headerutils_groupparts, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
