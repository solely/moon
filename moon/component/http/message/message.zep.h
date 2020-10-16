
extern zend_class_entry *moon_component_http_message_message_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Message);

PHP_METHOD(Moon_Component_Http_Message_Message, getHeader);
PHP_METHOD(Moon_Component_Http_Message_Message, getHeaderLine);
PHP_METHOD(Moon_Component_Http_Message_Message, getHeaders);
PHP_METHOD(Moon_Component_Http_Message_Message, hasHeader);
PHP_METHOD(Moon_Component_Http_Message_Message, setHeader);
PHP_METHOD(Moon_Component_Http_Message_Message, withHeader);
PHP_METHOD(Moon_Component_Http_Message_Message, withAddedHeader);
PHP_METHOD(Moon_Component_Http_Message_Message, withoutHeader);
PHP_METHOD(Moon_Component_Http_Message_Message, getProtocolVersion);
PHP_METHOD(Moon_Component_Http_Message_Message, withProtocolVersion);
PHP_METHOD(Moon_Component_Http_Message_Message, getBody);
PHP_METHOD(Moon_Component_Http_Message_Message, withBody);
PHP_METHOD(Moon_Component_Http_Message_Message, getStream);
PHP_METHOD(Moon_Component_Http_Message_Message, setHeaders);
PHP_METHOD(Moon_Component_Http_Message_Message, validName);
zend_object *zephir_init_properties_Moon_Component_Http_Message_Message(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_message_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_message_getheaderline, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_message_hasheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_message_setheader, 0, 2, Moon\\Component\\Http\\Message\\Message, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_message_setheader, 0, 2, IS_OBJECT, "Moon\\Component\\Http\\Message\\Message", 0)
#endif
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_message_withheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_message_withaddedheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_message_withoutheader, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_message_withprotocolversion, 0, 0, 1)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_message_withbody, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_message_getstream, 0, 2, Moon\\Component\\Http\\Message\\Stream, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_message_getstream, 0, 2, IS_OBJECT, "Moon\\Component\\Http\\Message\\Stream", 0)
#endif
	ZEND_ARG_INFO(0, stream)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_message_setheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_message_validname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_message_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Message, getHeader, arginfo_moon_component_http_message_message_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, getHeaderLine, arginfo_moon_component_http_message_message_getheaderline, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, hasHeader, arginfo_moon_component_http_message_message_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, setHeader, arginfo_moon_component_http_message_message_setheader, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_Http_Message_Message, withHeader, arginfo_moon_component_http_message_message_withheader, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, withAddedHeader, arginfo_moon_component_http_message_message_withaddedheader, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, withoutHeader, arginfo_moon_component_http_message_message_withoutheader, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, getProtocolVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, withProtocolVersion, arginfo_moon_component_http_message_message_withprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, withBody, arginfo_moon_component_http_message_message_withbody, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, getStream, arginfo_moon_component_http_message_message_getstream, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, setHeaders, arginfo_moon_component_http_message_message_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Message, validName, arginfo_moon_component_http_message_message_validname, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
