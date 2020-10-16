
extern zend_class_entry *moon_component_http_message_serverbag_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_ServerBag);

PHP_METHOD(Moon_Component_Http_Message_ServerBag, getHeaders);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverbag_getheaders, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_serverbag_getheaders, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_serverbag_method_entry) {
	PHP_ME(Moon_Component_Http_Message_ServerBag, getHeaders, arginfo_moon_component_http_message_serverbag_getheaders, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
