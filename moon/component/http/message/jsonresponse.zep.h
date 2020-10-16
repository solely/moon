
extern zend_class_entry *moon_component_http_message_jsonresponse_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_JsonResponse);

PHP_METHOD(Moon_Component_Http_Message_JsonResponse, __construct);
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, setJson);
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, update);
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, setData);
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, getEncodingOptions);
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, setEncodingOptions);
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, createStream);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_jsonresponse___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statusCode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, statusCode)
#endif
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, json, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, json)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_jsonresponse_setjson, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_jsonresponse_setjson, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, json, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, json)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_jsonresponse_update, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_jsonresponse_update, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_jsonresponse_setdata, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_jsonresponse_setdata, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_jsonresponse_getencodingoptions, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_jsonresponse_getencodingoptions, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_jsonresponse_setencodingoptions, 0, 1, Moon\\Component\\Http\\Message\\JsonResponse, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_jsonresponse_setencodingoptions, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\JsonResponse", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, encodingOptions, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, encodingOptions)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_jsonresponse_method_entry) {
	PHP_ME(Moon_Component_Http_Message_JsonResponse, __construct, arginfo_moon_component_http_message_jsonresponse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_JsonResponse, setJson, arginfo_moon_component_http_message_jsonresponse_setjson, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_JsonResponse, update, arginfo_moon_component_http_message_jsonresponse_update, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_Http_Message_JsonResponse, setData, arginfo_moon_component_http_message_jsonresponse_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_JsonResponse, getEncodingOptions, arginfo_moon_component_http_message_jsonresponse_getencodingoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_JsonResponse, setEncodingOptions, arginfo_moon_component_http_message_jsonresponse_setencodingoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_JsonResponse, createStream, NULL, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
