
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * FileName: AbstractSessionHandler.php
 * User: solely
 * DateTime: 2020/9/7 0:02
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Handler_AbstractSessionHandler) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session\\Storage\\Handler, AbstractSessionHandler, moon, component_http_message_session_storage_handler_abstractsessionhandler, moon_component_http_message_session_storage_handler_abstractsessionhandler_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, SL("sessionName"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, SL("prefetchId"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, SL("prefetchData"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, SL("newSessionId"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, SL("igbinaryEmptyData"), ZEND_ACC_PRIVATE);

	zend_class_implements(moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, 1, zephir_get_internal_ce(SL("sessionhandlerinterface")));
	zend_class_implements(moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, 1, zephir_get_internal_ce(SL("sessionupdatetimestamphandlerinterface")));
	return SUCCESS;

}

/**
 * @param string $savePath
 * @param string $sessionName
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_AbstractSessionHandler, open) {

	zend_bool _1, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *savePath, savePath_sub, *sessionName, sessionName_sub, _0, _2, _3, _6, _7, _8$$3, _9$$3, _10$$3, _11$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &savePath, &sessionName);



	zephir_update_property_zval(this_ptr, ZEND_STRL("sessionName"), sessionName);
	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 10);
	zephir_check_call_status();
	_1 = !zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "session.cache_limiter");
		ZEPHIR_CALL_FUNCTION(&_3, "ini_get", &_4, 13, &_2);
		zephir_check_call_status();
		_1 = !zephir_is_true(&_3);
	}
	_5 = _1;
	if (_5) {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "session.cache_limiter");
		ZEPHIR_CALL_FUNCTION(&_6, "ini_get", &_4, 13, &_2);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7);
		ZVAL_STRING(&_7, "0");
		_5 = !ZEPHIR_IS_IDENTICAL(&_7, &_6);
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "session.cache_expire");
		ZEPHIR_CALL_FUNCTION(&_9$$3, "ini_get", &_4, 13, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "Cache-Control: max-age=%d, private, must-revalidate");
		ZVAL_LONG(&_10$$3, (60 * zephir_get_intval(&_9$$3)));
		ZEPHIR_CALL_FUNCTION(&_11$$3, "sprintf", NULL, 3, &_8$$3, &_10$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 12, &_11$$3);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * @param string $sessionId
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_AbstractSessionHandler, doRead) {

}

/**
 * @param string $sessionId
 * @param string $data
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_AbstractSessionHandler, doWrite) {

}

/**
 * @param string $sessionId
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_AbstractSessionHandler, doDestroy) {

}

/**
 * @param string $sessionId
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_AbstractSessionHandler, validateId) {

	zval _13$$4, _22$$6;
	zend_bool _2, _4, _10$$4, _11$$4, _19$$6, _20$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, __$true, _0, _1, _3, _5, _27, _28, frame$$3, _6$$3, _7$$3, *_8$$3, _9$$3, _12$$4, _14$$4, _15$$4, _17$$5, _18$$5, _21$$6, _23$$6, _24$$6, _25$$7, _26$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&frame$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_22$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "read", NULL, 0, sessionId);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefetchData"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefetchId"), sessionId);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_GET_CONSTANT(&_1, "PHP_VERSION_ID");
	_2 = ZEPHIR_LT_LONG(&_1, 70317);
	if (!(_2)) {
		ZEPHIR_INIT_VAR(&_3);
		ZEPHIR_GET_CONSTANT(&_3, "PHP_VERSION_ID");
		_4 = ZEPHIR_GE_LONG(&_3, 70400);
		if (_4) {
			ZEPHIR_INIT_VAR(&_5);
			ZEPHIR_GET_CONSTANT(&_5, "PHP_VERSION_ID");
			_4 = ZEPHIR_LT_LONG(&_5, 70405);
		}
		_2 = _4;
	}
	if (_2) {
		ZVAL_LONG(&_6$$3, 2);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "debug_backtrace", NULL, 14, &_6$$3);
		zephir_check_call_status();
		zephir_is_iterable(&_7$$3, 0, "moon/Component/Http/Message/Session/Storage/Handler/AbstractSessionHandler.zep", 66);
		if (Z_TYPE_P(&_7$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_7$$3), _8$$3)
			{
				ZEPHIR_INIT_NVAR(&frame$$3);
				ZVAL_COPY(&frame$$3, _8$$3);
				_10$$4 = !(zephir_array_isset_string(&frame$$3, SL("class")));
				if (_10$$4) {
					_10$$4 = zephir_array_isset_string(&frame$$3, SL("function"));
				}
				_11$$4 = _10$$4;
				if (_11$$4) {
					zephir_array_fetch_string(&_12$$4, &frame$$3, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/AbstractSessionHandler.zep", 62);
					ZEPHIR_INIT_NVAR(&_13$$4);
					zephir_create_array(&_13$$4, 2, 0);
					ZEPHIR_INIT_NVAR(&_14$$4);
					ZVAL_STRING(&_14$$4, "session_regenerate_id");
					zephir_array_fast_append(&_13$$4, &_14$$4);
					ZEPHIR_INIT_NVAR(&_14$$4);
					ZVAL_STRING(&_14$$4, "session_create_id");
					zephir_array_fast_append(&_13$$4, &_14$$4);
					ZEPHIR_CALL_FUNCTION(&_15$$4, "in_array", &_16, 5, &_12$$4, &_13$$4, &__$true);
					zephir_check_call_status();
					_11$$4 = zephir_is_true(&_15$$4);
				}
				if (_11$$4) {
					zephir_read_property(&_17$$5, this_ptr, ZEND_STRL("prefetchData"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_18$$5);
					ZVAL_STRING(&_18$$5, "");
					RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_18$$5, &_17$$5));
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_7$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_9$$3, &_7$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&frame$$3, &_7$$3, "current", NULL, 0);
				zephir_check_call_status();
					_19$$6 = !(zephir_array_isset_string(&frame$$3, SL("class")));
					if (_19$$6) {
						_19$$6 = zephir_array_isset_string(&frame$$3, SL("function"));
					}
					_20$$6 = _19$$6;
					if (_20$$6) {
						zephir_array_fetch_string(&_21$$6, &frame$$3, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/AbstractSessionHandler.zep", 62);
						ZEPHIR_INIT_NVAR(&_22$$6);
						zephir_create_array(&_22$$6, 2, 0);
						ZEPHIR_INIT_NVAR(&_23$$6);
						ZVAL_STRING(&_23$$6, "session_regenerate_id");
						zephir_array_fast_append(&_22$$6, &_23$$6);
						ZEPHIR_INIT_NVAR(&_23$$6);
						ZVAL_STRING(&_23$$6, "session_create_id");
						zephir_array_fast_append(&_22$$6, &_23$$6);
						ZEPHIR_CALL_FUNCTION(&_24$$6, "in_array", &_16, 5, &_21$$6, &_22$$6, &__$true);
						zephir_check_call_status();
						_20$$6 = zephir_is_true(&_24$$6);
					}
					if (_20$$6) {
						zephir_read_property(&_25$$7, this_ptr, ZEND_STRL("prefetchData"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_26$$7);
						ZVAL_STRING(&_26$$7, "");
						RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_26$$7, &_25$$7));
					}
				ZEPHIR_CALL_METHOD(NULL, &_7$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&frame$$3);
	}
	zephir_read_property(&_27, this_ptr, ZEND_STRL("prefetchData"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_28);
	ZVAL_STRING(&_28, "");
	RETURN_MM_BOOL(!ZEPHIR_IS_IDENTICAL(&_28, &_27));

}

/**
 * @param string $sessionId
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_AbstractSessionHandler, read) {

	zend_bool _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, __$null, data, prefetchData, prefetchId, _0, _6, _7, _1$$3, _3$$3, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&prefetchData);
	ZVAL_UNDEF(&prefetchId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("prefetchId"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("prefetchId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&prefetchId, &_1$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("prefetchData"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&prefetchData, &_1$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("prefetchId"), &__$null);
		zephir_update_property_zval(this_ptr, ZEND_STRL("prefetchData"), &__$null);
		_2$$3 = ZEPHIR_IS_IDENTICAL(&prefetchId, sessionId);
		if (!(_2$$3)) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "");
			_2$$3 = ZEPHIR_IS_IDENTICAL(&_3$$3, &prefetchData);
		}
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_4$$4);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "");
			if (ZEPHIR_IS_IDENTICAL(&_5$$4, &prefetchData)) {
				ZEPHIR_CPY_WRT(&_4$$4, sessionId);
			} else {
				ZEPHIR_INIT_NVAR(&_4$$4);
				ZVAL_NULL(&_4$$4);
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("newSessionId"), &_4$$4);
			RETURN_CCTOR(&prefetchData);
		}
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "doread", NULL, 0, sessionId);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "");
	if (ZEPHIR_IS_IDENTICAL(&_7, &data)) {
		ZEPHIR_CPY_WRT(&_6, sessionId);
	} else {
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_NULL(&_6);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("newSessionId"), &_6);
	RETURN_CCTOR(&data);

}

/**
 * @param string $sessionId
 * @param string $data
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_AbstractSessionHandler, write) {

	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, *data, data_sub, __$null, _0, _4, _6, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &data);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("igbinaryEmptyData"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "igbinary_serialize");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "\function_exists", NULL, 15, &_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			ZEPHIR_INIT_NVAR(&_2$$3);
			array_init(&_2$$3);
			ZEPHIR_CALL_FUNCTION(&_1$$3, "igbinary_serialize", NULL, 16, &_2$$3);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "");
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("igbinaryEmptyData"), &_1$$3);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "");
	_5 = ZEPHIR_IS_IDENTICAL(&_4, data);
	if (!(_5)) {
		zephir_read_property(&_6, this_ptr, ZEND_STRL("igbinaryEmptyData"), PH_NOISY_CC | PH_READONLY);
		_5 = ZEPHIR_IS_IDENTICAL(&_6, data);
	}
	if (_5) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "destroy", NULL, 0, sessionId);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("newSessionId"), &__$null);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dowrite", NULL, 0, sessionId, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $sessionId
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_AbstractSessionHandler, destroy) {

	zend_bool _1, _30, _15$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_13 = NULL, *_27 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, _COOKIE, params, cookie, _0, _2, _3, _5, _6, _31, _8$$3, _14$$3, _16$$3, _9$$4, _10$$4, _11$$4, _12$$4, _17$$5, _18$$6, _19$$6, _20$$6, _21$$6, _22$$6, _23$$6, _24$$6, _25$$6, _26$$6, _28$$7, _29$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_fetch_params(1, 1, 0, &sessionId);



	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 10);
	zephir_check_call_status();
	_1 = !zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "session.use_cookies");
		ZEPHIR_CALL_FUNCTION(&_3, "ini_get", &_4, 13, &_2);
		zephir_check_call_status();
		ZVAL_LONG(&_5, 258);
		ZEPHIR_CALL_FUNCTION(&_6, "filter_var", &_7, 17, &_3, &_5);
		zephir_check_call_status();
		_1 = zephir_is_true(&_6);
	}
	if (_1) {
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("sessionName"), PH_NOISY_CC | PH_READONLY);
		if (!zephir_is_true(&_8$$3)) {
			ZEPHIR_INIT_VAR(&_9$$4);
			object_init_ex(&_9$$4, spl_ce_LogicException);
			ZEPHIR_INIT_VAR(&_10$$4);
			zephir_get_called_class(&_10$$4);
			ZEPHIR_INIT_VAR(&_11$$4);
			ZVAL_STRING(&_11$$4, "Session name cannot be empty, did you forget to call \"parent::open()\" in \"%s\"?.");
			ZEPHIR_CALL_FUNCTION(&_12$$4, "sprintf", NULL, 3, &_11$$4, &_10$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_9$$4, "__construct", NULL, 18, &_12$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$4, "moon/Component/Http/Message/Session/Storage/Handler/AbstractSessionHandler.zep", 122);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_14$$3, this_ptr, ZEND_STRL("sessionName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&cookie, moon_component_http_message_session_sessionutils_ce, "popsessioncookie", &_13, 0, &_14$$3, sessionId);
		zephir_check_call_status();
		_15$$3 = Z_TYPE_P(&cookie) == IS_NULL;
		if (!(_15$$3)) {
			zephir_read_property(&_16$$3, this_ptr, ZEND_STRL("sessionName"), PH_NOISY_CC | PH_READONLY);
			_15$$3 = zephir_array_isset(&_COOKIE, &_16$$3);
		}
		if (_15$$3) {
			ZEPHIR_INIT_VAR(&_17$$5);
			ZEPHIR_GET_CONSTANT(&_17$$5, "PHP_VERSION_ID");
			if (ZEPHIR_LT_LONG(&_17$$5, 70300)) {
				zephir_read_property(&_18$$6, this_ptr, ZEND_STRL("sessionName"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_19$$6);
				ZVAL_STRING(&_19$$6, "session.cookie_path");
				ZEPHIR_CALL_FUNCTION(&_20$$6, "ini_get", &_4, 13, &_19$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$6);
				ZVAL_STRING(&_19$$6, "session.cookie_domain");
				ZEPHIR_CALL_FUNCTION(&_21$$6, "ini_get", &_4, 13, &_19$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$6);
				ZVAL_STRING(&_19$$6, "session.cookie_secure");
				ZEPHIR_CALL_FUNCTION(&_22$$6, "ini_get", &_4, 13, &_19$$6);
				zephir_check_call_status();
				ZVAL_LONG(&_23$$6, 258);
				ZEPHIR_CALL_FUNCTION(&_24$$6, "filter_var", &_7, 17, &_22$$6, &_23$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$6);
				ZVAL_STRING(&_19$$6, "session.cookie_httponly");
				ZEPHIR_CALL_FUNCTION(&_25$$6, "ini_get", &_4, 13, &_19$$6);
				zephir_check_call_status();
				ZVAL_LONG(&_23$$6, 258);
				ZEPHIR_CALL_FUNCTION(&_26$$6, "filter_var", &_7, 17, &_25$$6, &_23$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$6);
				ZVAL_STRING(&_19$$6, "");
				ZVAL_LONG(&_23$$6, 0);
				ZEPHIR_CALL_FUNCTION(NULL, "setcookie", &_27, 19, &_18$$6, &_19$$6, &_23$$6, &_20$$6, &_21$$6, &_24$$6, &_26$$6);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_FUNCTION(&params, "session_get_cookie_params", NULL, 20);
				zephir_check_call_status();
				zephir_array_unset_string(&params, SL("lifetime"), PH_SEPARATE);
				zephir_read_property(&_28$$7, this_ptr, ZEND_STRL("sessionName"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_29$$7);
				ZVAL_STRING(&_29$$7, "");
				ZEPHIR_CALL_FUNCTION(NULL, "setcookie", &_27, 19, &_28$$7, &_29$$7, &params);
				zephir_check_call_status();
			}
		}
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("newSessionId"), PH_NOISY_CC | PH_READONLY);
	_30 = ZEPHIR_IS_IDENTICAL(&_5, sessionId);
	if (!(_30)) {
		ZEPHIR_CALL_METHOD(&_31, this_ptr, "dodestroy", NULL, 0, sessionId);
		zephir_check_call_status();
		_30 = zephir_is_true(&_31);
	}
	RETURN_MM_BOOL(_30);

}

