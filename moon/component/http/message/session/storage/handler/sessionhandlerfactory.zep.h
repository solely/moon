
extern zend_class_entry *moon_component_http_message_session_storage_handler_sessionhandlerfactory_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Handler_SessionHandlerFactory);

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_SessionHandlerFactory, createHandler);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_sessionhandlerfactory_createhandler, 0, 1, Moon\\Component\\Http\\Message\\Session\\Storage\\Handler\\AbstractSessionHandler, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_sessionhandlerfactory_createhandler, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\Session\\Storage\\Handler\\AbstractSessionHandler", 0)
#endif
	ZEND_ARG_INFO(0, connection)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_storage_handler_sessionhandlerfactory_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_SessionHandlerFactory, createHandler, arginfo_moon_component_http_message_session_storage_handler_sessionhandlerfactory_createhandler, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
