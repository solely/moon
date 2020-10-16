
#ifdef HAVE_CONFIG_H
#include "../../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../../php_ext.h"
#include "../../../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * FileName: MigratingSessionHandler.php
 * User: solely
 * DateTime: 2020/9/7 0:12
 * Description:
 */
/**
 * Migrating session handler for migrating from one handler to another. It reads
 * from the current handler and writes both the current and new ones.
 *
 * It ignores errors from the new handler.
 *
 * Class MigratingSessionHandler
 * @package Moon\Component\Http\Message\Session\Storage\Handler
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Handler_MigratingSessionHandler) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session\\Storage\\Handler, MigratingSessionHandler, moon, component_http_message_session_storage_handler_migratingsessionhandler, moon_component_http_message_session_storage_handler_migratingsessionhandler_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_session_storage_handler_migratingsessionhandler_ce, SL("currentHandler"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_storage_handler_migratingsessionhandler_ce, SL("writeOnlyHandler"), ZEND_ACC_PRIVATE);

	zend_class_implements(moon_component_http_message_session_storage_handler_migratingsessionhandler_ce, 1, zephir_get_internal_ce(SL("sessionhandlerinterface")));
	zend_class_implements(moon_component_http_message_session_storage_handler_migratingsessionhandler_ce, 1, zephir_get_internal_ce(SL("sessionupdatetimestamphandlerinterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MigratingSessionHandler, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *currentHandler = NULL, currentHandler_sub, *writeOnlyHandler = NULL, writeOnlyHandler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&currentHandler_sub);
	ZVAL_UNDEF(&writeOnlyHandler_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &currentHandler, &writeOnlyHandler);

	ZEPHIR_SEPARATE_PARAM(currentHandler);
	ZEPHIR_SEPARATE_PARAM(writeOnlyHandler);


	if (!((zephir_is_instance_of(currentHandler, SL("SessionUpdateTimestampHandlerInterface"))))) {
		ZEPHIR_INIT_NVAR(currentHandler);
		object_init_ex(currentHandler, moon_component_http_message_session_storage_handler_strictsessionhandler_ce);
		ZEPHIR_CALL_METHOD(NULL, currentHandler, "__construct", &_0, 67, currentHandler);
		zephir_check_call_status();
	}
	if (!((zephir_is_instance_of(writeOnlyHandler, SL("SessionUpdateTimestampHandlerInterface"))))) {
		ZEPHIR_INIT_NVAR(writeOnlyHandler);
		object_init_ex(writeOnlyHandler, moon_component_http_message_session_storage_handler_strictsessionhandler_ce);
		ZEPHIR_CALL_METHOD(NULL, writeOnlyHandler, "__construct", &_0, 67, writeOnlyHandler);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("currentHandler"), currentHandler);
	zephir_update_property_zval(this_ptr, ZEND_STRL("writeOnlyHandler"), writeOnlyHandler);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MigratingSessionHandler, close) {

	zval result, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("currentHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "close", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("writeOnlyHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "close", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&result);

}

/**
 * @param string $sessionId
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MigratingSessionHandler, destroy) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, result, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("currentHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "destroy", NULL, 0, sessionId);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("writeOnlyHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "destroy", NULL, 0, sessionId);
	zephir_check_call_status();
	RETURN_CCTOR(&result);

}

/**
 * @param int $maxlifetime
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MigratingSessionHandler, gc) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *maxlifetime, maxlifetime_sub, result, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &maxlifetime);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("currentHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "gc", NULL, 0, maxlifetime);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("writeOnlyHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "gc", NULL, 0, maxlifetime);
	zephir_check_call_status();
	RETURN_CCTOR(&result);

}

/**
 * @param string $savePath
 * @param string $sessionName
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MigratingSessionHandler, open) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *savePath, savePath_sub, *sessionName, sessionName_sub, result, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &savePath, &sessionName);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("currentHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "open", NULL, 0, savePath, sessionName);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("writeOnlyHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "open", NULL, 0, savePath, sessionName);
	zephir_check_call_status();
	RETURN_CCTOR(&result);

}

/**
 * @param string $sessionId
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MigratingSessionHandler, read) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("currentHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "read", NULL, 0, sessionId);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $sessionId
 * @param string $sessionData
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MigratingSessionHandler, write) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, *sessionData, sessionData_sub, result, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&sessionData_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &sessionData);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("currentHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "write", NULL, 0, sessionId, sessionData);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("writeOnlyHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "write", NULL, 0, sessionId, sessionData);
	zephir_check_call_status();
	RETURN_CCTOR(&result);

}

/**
 * @param string $sessionId
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MigratingSessionHandler, validateId) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("currentHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "validateid", NULL, 0, sessionId);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $sessionId
 * @param string $sessionData
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MigratingSessionHandler, updateTimestamp) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, *sessionData, sessionData_sub, result, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&sessionData_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &sessionData);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("currentHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "updatetimestamp", NULL, 0, sessionId, sessionData);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("writeOnlyHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "updatetimestamp", NULL, 0, sessionId, sessionData);
	zephir_check_call_status();
	RETURN_CCTOR(&result);

}

