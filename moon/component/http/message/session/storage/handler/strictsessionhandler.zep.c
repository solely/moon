
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * FileName: StrictSessionHandler.php
 * User: solely
 * DateTime: 2020/9/7 0:16
 * Description:
 */
/**
 * Adds basic `SessionUpdateTimestampHandlerInterface` behaviors to another `SessionHandlerInterface`.
 *
 * Class StrictSessionHandler
 * @package Moon\Component\Http\Message\Session\Storage\Handler
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Handler_StrictSessionHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Session\\Storage\\Handler, StrictSessionHandler, moon, component_http_message_session_storage_handler_strictsessionhandler, moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, moon_component_http_message_session_storage_handler_strictsessionhandler_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_session_storage_handler_strictsessionhandler_ce, SL("handler"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_storage_handler_strictsessionhandler_ce, SL("doDestroy"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_StrictSessionHandler, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler, handler_sub, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &handler);



	if (zephir_is_instance_of(handler, SL("SessionUpdateTimestampHandlerInterface"))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_LogicException);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_get_class(&_1$$3, handler, 0);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\"%s\" is already an instance of \"SessionUpdateTimestampHandlerInterface\", you cannot wrap it with \"%s\".");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Moon\\Component\\Http\\Message\\Session\\Storage\\Handler\\StrictSessionHandler");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 3, &_2$$3, &_1$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 18, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "moon/Component/Http/Message/Session/Storage/Handler/StrictSessionHandler.zep", 22);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $savePath
 * @param string $sessionName
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_StrictSessionHandler, open) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *savePath, savePath_sub, *sessionName, sessionName_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &savePath, &sessionName);



	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_session_storage_handler_strictsessionhandler_ce, getThis(), "open", &_0, 0, savePath, sessionName);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "open", NULL, 0, savePath, sessionName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_StrictSessionHandler, doRead) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, _0;
	zval sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(&sessionId, sessionId_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "read", NULL, 0, &sessionId);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $sessionId
 * @param string $data
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_StrictSessionHandler, updateTimestamp) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&data_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &data);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "write", NULL, 0, sessionId, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_StrictSessionHandler, doWrite) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *data_param = NULL, _0;
	zval sessionId, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId_param, &data_param);

	zephir_get_strval(&sessionId, sessionId_param);
	zephir_get_strval(&data, data_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "write", NULL, 0, &sessionId, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $sessionId
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_StrictSessionHandler, destroy) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *sessionId, sessionId_sub, __$true, __$false, destroyed, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&destroyed);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("doDestroy"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("doDestroy"), &__$false);
	}
	ZEPHIR_CALL_PARENT(&destroyed, moon_component_http_message_session_storage_handler_strictsessionhandler_ce, getThis(), "destroy", &_0, 0, sessionId);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("doDestroy"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "dodestroy", NULL, 0, sessionId);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_1, &destroyed);
	}
	RETURN_CCTOR(&_1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_StrictSessionHandler, doDestroy) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, __$true, __$false, _0;
	zval sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(&sessionId, sessionId_param);


	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("doDestroy"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("doDestroy"), &__$false);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "destroy", NULL, 0, &sessionId);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_StrictSessionHandler, close) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "close", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param int $maxlifetime
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_StrictSessionHandler, gc) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *maxlifetime, maxlifetime_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &maxlifetime);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "gc", NULL, 0, maxlifetime);
	zephir_check_call_status();
	RETURN_MM();

}

