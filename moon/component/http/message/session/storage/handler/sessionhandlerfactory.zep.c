
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/pdo/php_pdo_driver.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * FileName: SessionHandlerFactory.php
 * User: solely
 * DateTime: 2020/9/7 0:53
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Handler_SessionHandlerFactory) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session\\Storage\\Handler, SessionHandlerFactory, moon, component_http_message_session_storage_handler_sessionhandlerfactory, moon_component_http_message_session_storage_handler_sessionhandlerfactory_method_entry, 0);

	return SUCCESS;

}

/**
 * @param $connection
 * @return AbstractSessionHandler
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_SessionHandlerFactory, createHandler) {

	zend_bool _0, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	zval *connection, connection_sub, _13, _14, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _9$$7, _10$$7, _11$$7, _12$$7, _15$$8, _16$$8, _17$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	_0 = !(Z_TYPE_P(connection) == IS_STRING);
	if (_0) {
		_0 = !(Z_TYPE_P(connection) == IS_OBJECT);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zephir_get_internal_ce(SL("typeerror")));
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_gettype(&_2$$3, connection);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Argument 1 passed to \"%s()\" must be a string or a connection object, \"%s\" given.");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "SessionHandlerFactory:createHandler");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", &_6, 3, &_3$$3, &_4$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 229, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "moon/Component/Http/Message/Session/Storage/Handler/SessionHandlerFactory.zep", 18);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		_7 = 1;
		if (_7 == zephir_instance_of_ev(connection, zephir_get_internal_ce(SL("redis"))) || _7 == zephir_instance_of_ev(connection, zephir_get_internal_ce(SL("redisarray"))) || _7 == zephir_instance_of_ev(connection, zephir_get_internal_ce(SL("rediscluster"))) || _7 == zephir_is_instance_of(connection, SL("Predis\\ClientInterface"))) {
			object_init_ex(return_value, moon_component_http_message_session_storage_handler_redissessionhandler_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 230, connection);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (_7 == zephir_instance_of_ev(connection, zephir_get_internal_ce(SL("memcached")))) {
			object_init_ex(return_value, moon_component_http_message_session_storage_handler_memcachedsessionhandler_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 231, connection);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (_7 == zephir_instance_of_ev(connection, php_pdo_get_dbh_ce())) {
			object_init_ex(return_value, moon_component_http_message_session_storage_handler_pdosessionhandler_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_8, 232, connection);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (_7 == !(Z_TYPE_P(connection) == IS_STRING)) {
			ZEPHIR_INIT_VAR(&_9$$7);
			object_init_ex(&_9$$7, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_10$$7);
			zephir_get_class(&_10$$7, connection, 0);
			ZEPHIR_INIT_VAR(&_11$$7);
			ZVAL_STRING(&_11$$7, "Unsupported Connection: \"%s\".");
			ZEPHIR_CALL_FUNCTION(&_12$$7, "sprintf", &_6, 3, &_11$$7, &_10$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", NULL, 33, &_12$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$7, "moon/Component/Http/Message/Session/Storage/Handler/SessionHandlerFactory.zep", 31);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_13);
		ZVAL_STRING(&_13, "file://");
		ZEPHIR_INIT_VAR(&_14);
		zephir_fast_strpos(&_14, connection, &_13, 0 );
		if (_7 == ZEPHIR_IS_LONG_IDENTICAL(&_14, 0)) {
			object_init_ex(return_value, moon_component_http_message_session_storage_handler_strictsessionhandler_ce);
			ZEPHIR_INIT_VAR(&_15$$8);
			object_init_ex(&_15$$8, moon_component_http_message_session_storage_handler_nativefilesessionhandler_ce);
			ZVAL_LONG(&_16$$8, 7);
			ZEPHIR_INIT_VAR(&_17$$8);
			zephir_substr(&_17$$8, connection, 7 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_METHOD(NULL, &_15$$8, "__construct", NULL, 233, &_17$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 67, &_15$$8);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_18);
		ZVAL_STRING(&_18, "mssql://");
		ZEPHIR_INIT_VAR(&_19);
		zephir_fast_strpos(&_19, connection, &_18, 0 );
		ZEPHIR_INIT_VAR(&_20);
		ZVAL_STRING(&_20, "mysql://");
		ZEPHIR_INIT_VAR(&_21);
		zephir_fast_strpos(&_21, connection, &_20, 0 );
		ZEPHIR_INIT_VAR(&_22);
		ZVAL_STRING(&_22, "mysql2://");
		ZEPHIR_INIT_VAR(&_23);
		zephir_fast_strpos(&_23, connection, &_22, 0 );
		ZEPHIR_INIT_VAR(&_24);
		ZVAL_STRING(&_24, "pgsql://");
		ZEPHIR_INIT_VAR(&_25);
		zephir_fast_strpos(&_25, connection, &_24, 0 );
		ZEPHIR_INIT_VAR(&_26);
		ZVAL_STRING(&_26, "postgres://");
		ZEPHIR_INIT_VAR(&_27);
		zephir_fast_strpos(&_27, connection, &_26, 0 );
		ZEPHIR_INIT_VAR(&_28);
		ZVAL_STRING(&_28, "postgresql://");
		ZEPHIR_INIT_VAR(&_29);
		zephir_fast_strpos(&_29, connection, &_28, 0 );
		ZEPHIR_INIT_VAR(&_30);
		ZVAL_STRING(&_30, "sqlsrv://");
		ZEPHIR_INIT_VAR(&_31);
		zephir_fast_strpos(&_31, connection, &_30, 0 );
		ZEPHIR_INIT_VAR(&_32);
		ZVAL_STRING(&_32, "sqlite://");
		ZEPHIR_INIT_VAR(&_33);
		zephir_fast_strpos(&_33, connection, &_32, 0 );
		ZEPHIR_INIT_VAR(&_34);
		ZVAL_STRING(&_34, "sqlite3://");
		ZEPHIR_INIT_VAR(&_35);
		zephir_fast_strpos(&_35, connection, &_34, 0 );
		if (_7 == ZEPHIR_IS_LONG_IDENTICAL(&_19, 0) || _7 == ZEPHIR_IS_LONG_IDENTICAL(&_21, 0) || _7 == ZEPHIR_IS_LONG_IDENTICAL(&_23, 0) || _7 == ZEPHIR_IS_LONG_IDENTICAL(&_25, 0) || _7 == ZEPHIR_IS_LONG_IDENTICAL(&_27, 0) || _7 == ZEPHIR_IS_LONG_IDENTICAL(&_29, 0) || _7 == ZEPHIR_IS_LONG_IDENTICAL(&_31, 0) || _7 == ZEPHIR_IS_LONG_IDENTICAL(&_33, 0) || _7 == ZEPHIR_IS_LONG_IDENTICAL(&_35, 0)) {
			object_init_ex(return_value, moon_component_http_message_session_storage_handler_pdosessionhandler_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 67, connection);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_36);
	object_init_ex(&_36, spl_ce_InvalidArgumentException);
	ZEPHIR_INIT_VAR(&_37);
	ZVAL_STRING(&_37, "Unsupported Connection: \"%s\".");
	ZEPHIR_CALL_FUNCTION(&_38, "sprintf", &_6, 3, &_37, connection);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_36, "__construct", NULL, 33, &_38);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_36, "moon/Component/Http/Message/Session/Storage/Handler/SessionHandlerFactory.zep", 45);
	ZEPHIR_MM_RESTORE();
	return;

}

