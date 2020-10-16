
extern zend_class_entry *moon_component_http_message_session_storage_handler_pdosessionhandler_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler);

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, __construct);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, createTable);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, isSessionExpired);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, open);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, read);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, gc);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doDestroy);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doWrite);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, updateTimestamp);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, close);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, connect);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, buildDsnFromUrl);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, beginTransaction);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, commit);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, rollback);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doRead);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doAdvisoryLock);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, convertStringToInt);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getSelectSql);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getInsertStatement);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getUpdateStatement);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getMergeStatement);
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getConnection);
zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, pdoOrDsn)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_issessionexpired, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_issessionexpired, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_open, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_open, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, savePath)
	ZEND_ARG_INFO(0, sessionName)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_read, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_read, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_gc, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_gc, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, maxlifetime)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_dodestroy, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_dodestroy, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionId)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_dowrite, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_dowrite, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, data)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_updatetimestamp, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_updatetimestamp, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, sessionId)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_close, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_close, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_connect, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_connect, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_connect, 0, 0, 1)
#define arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_connect NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dsn, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dsn)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_builddsnfromurl, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dsnOrUrl, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dsnOrUrl)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_begintransaction, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_begintransaction, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_begintransaction NULL
#endif

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_commit, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_commit, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_commit NULL
#endif

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_rollback, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_rollback, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_rollback NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_doread, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_doread, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionId)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_doadvisorylock, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionId)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_convertstringtoint, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_convertstringtoint, 0, 1, IS_LONG, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, _string, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, _string)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getselectsql, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getselectsql, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getinsertstatement, 0, 3, PDOStatement, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getinsertstatement, 0, 3, IS_OBJECT, "PDOStatement", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionData, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionData)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, maxlifetime, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, maxlifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getupdatestatement, 0, 3, PDOStatement, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getupdatestatement, 0, 3, IS_OBJECT, "PDOStatement", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionData, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionData)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, maxlifetime, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, maxlifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getmergestatement, 0, 3, PDOStatement, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getmergestatement, 0, 3, IS_OBJECT, "PDOStatement", 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sessionId, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sessionId)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, data)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, maxlifetime, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, maxlifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getconnection, 0, 0, PDO, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getconnection, 0, 0, IS_OBJECT, "PDO", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_session_storage_handler_pdosessionhandler_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, __construct, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, createTable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, isSessionExpired, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_issessionexpired, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, open, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_open, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, read, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_read, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, gc, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doDestroy, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_dodestroy, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doWrite, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_dowrite, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, updateTimestamp, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_updatetimestamp, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, close, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_close, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, connect, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_connect, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, buildDsnFromUrl, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_builddsnfromurl, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, beginTransaction, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_begintransaction, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, commit, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_commit, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, rollback, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_rollback, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doRead, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_doread, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doAdvisoryLock, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_doadvisorylock, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, convertStringToInt, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_convertstringtoint, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getSelectSql, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getselectsql, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getInsertStatement, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getinsertstatement, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getUpdateStatement, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getupdatestatement, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getMergeStatement, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getmergestatement, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getConnection, arginfo_moon_component_http_message_session_storage_handler_pdosessionhandler_getconnection, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
