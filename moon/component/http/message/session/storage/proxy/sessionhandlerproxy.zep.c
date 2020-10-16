
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
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * FileName: SessionHandlerProxy.php
 * User: solely
 * DateTime: 2020/9/7 23:43
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Proxy_SessionHandlerProxy) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Session\\Storage\\Proxy, SessionHandlerProxy, moon, component_http_message_session_storage_proxy_sessionhandlerproxy, moon_component_http_message_session_storage_proxy_abstractproxy_ce, moon_component_http_message_session_storage_proxy_sessionhandlerproxy_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_session_storage_proxy_sessionhandlerproxy_ce, SL("handler"), ZEND_ACC_PROTECTED);

	zend_class_implements(moon_component_http_message_session_storage_proxy_sessionhandlerproxy_ce, 1, zephir_get_internal_ce(SL("sessionhandlerinterface")));
	zend_class_implements(moon_component_http_message_session_storage_proxy_sessionhandlerproxy_ce, 1, zephir_get_internal_ce(SL("sessionupdatetimestamphandlerinterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_SessionHandlerProxy, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler, handler_sub, __$true, __$false, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &handler);



	zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	if (zephir_instance_of_ev(handler, zephir_get_internal_ce(SL("sessionhandler")))) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("wrapper"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("wrapper"), &__$false);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("wrapper"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "session.save_handler");
		ZEPHIR_CALL_FUNCTION(&_0, "ini_get", NULL, 13, &_2);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "user");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("saveHandlerName"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return \SessionHandlerInterface
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_SessionHandlerProxy, getHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handler");

}

/**
 * @param string $savePath
 * @param string $sessionName
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_SessionHandlerProxy, open) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *savePath, savePath_sub, *sessionName, sessionName_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &savePath, &sessionName);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "open", NULL, 0, savePath, sessionName);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_1));

}

/**
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_SessionHandlerProxy, close) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "close", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_1));

}

/**
 * @param string $sessionId
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_SessionHandlerProxy, read) {

	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "read", NULL, 0, sessionId);
	zephir_check_call_status();
	zephir_get_strval(&_2, &_1);
	RETURN_CTOR(&_2);

}

/**
 * @param string $sessionId
 * @param string $data
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_SessionHandlerProxy, write) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, *data, data_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &data);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "write", NULL, 0, sessionId, data);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_1));

}

/**
 * @param string $sessionId
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_SessionHandlerProxy, destroy) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "destroy", NULL, 0, sessionId);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_1));

}

/**
 * @param int $maxlifetime
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_SessionHandlerProxy, gc) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *maxlifetime, maxlifetime_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &maxlifetime);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "gc", NULL, 0, maxlifetime);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_1));

}

/**
 * @param string $sessionId
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_SessionHandlerProxy, validateId) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
	_1 = !(zephir_is_instance_of(&_0, SL("SessionUpdateTimestampHandlerInterface")));
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3, &_2, "validateid", NULL, 0, sessionId);
		zephir_check_call_status();
		_1 = zephir_is_true(&_3);
	}
	RETURN_MM_BOOL(_1);

}

/**
 * @param string $sessionId
 * @param string $data
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_SessionHandlerProxy, updateTimestamp) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, *data, data_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &data);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
	if (zephir_is_instance_of(&_1, SL("SessionUpdateTimestampHandlerInterface"))) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_0, &_2, "updatetimestamp", NULL, 0, sessionId, data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "write", NULL, 0, sessionId, data);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

