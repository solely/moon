
extern zend_class_entry *moon_component_http_message_session_sessionutils_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_SessionUtils);

PHP_METHOD(Moon_Component_Http_Message_Session_SessionUtils, popSessionCookie);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionutils_popsessioncookie, 0, 2, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_sessionutils_popsessioncookie, 0, 2, IS_STRING, NULL, 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionId)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_sessionutils_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_SessionUtils, popSessionCookie, arginfo_moon_component_http_message_session_sessionutils_popsessioncookie, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
