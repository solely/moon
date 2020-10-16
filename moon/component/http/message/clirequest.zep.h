
extern zend_class_entry *moon_component_http_message_clirequest_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_CLIRequest);

PHP_METHOD(Moon_Component_Http_Message_CLIRequest, create);

ZEPHIR_INIT_FUNCS(moon_component_http_message_clirequest_method_entry) {
	PHP_ME(Moon_Component_Http_Message_CLIRequest, create, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
