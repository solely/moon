
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * FileName: RedisSessionHandler.php
 * User: solely
 * DateTime: 2020/9/7 0:34
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Handler_RedisSessionHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Session\\Storage\\Handler, RedisSessionHandler, moon, component_http_message_session_storage_handler_redissessionhandler, moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, moon_component_http_message_session_storage_handler_redissessionhandler_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_session_storage_handler_redissessionhandler_ce, SL("redis"), ZEND_ACC_PRIVATE);

	/**
	 * @var string Key prefix for shared environments
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_handler_redissessionhandler_ce, SL("prefix"), ZEND_ACC_PRIVATE);

	/**
	 * @var int Time to live in seconds
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_handler_redissessionhandler_ce, SL("ttl"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * List of available options:
 *  * prefix: The prefix to use for the keys in order to avoid collision on the Redis server
 *  * ttl: The time to live in seconds.
 *
 * @param \Redis|\RedisArray|\RedisCluster|\Predis\ClientInterface|RedisProxy|RedisClusterProxy $redis
 * @param array $options
 *
 * @throws \InvalidArgumentException When unsupported client or options are passed
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_RedisSessionHandler, __construct) {

	zend_bool _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_8 = NULL;
	zval options, _10;
	zval *redis, redis_sub, *options_param = NULL, diff, _9, _11, _16, _17, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _12$$4, _13$$4, _14$$4, _15$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&redis_sub);
	ZVAL_UNDEF(&diff);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &redis, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	_0 = !((zephir_instance_of_ev(redis, zephir_get_internal_ce(SL("redis")))));
	if (_0) {
		_0 = !((zephir_instance_of_ev(redis, zephir_get_internal_ce(SL("redisarray")))));
	}
	_1 = _0;
	if (_1) {
		_1 = !((zephir_instance_of_ev(redis, zephir_get_internal_ce(SL("rediscluster")))));
	}
	_2 = _1;
	if (_2) {
		_2 = !((zephir_is_instance_of(redis, SL("Predis\\ClientInterface"))));
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_4$$3);
		if (Z_TYPE_P(redis) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_get_class(&_4$$3, redis, 0);
		} else {
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_gettype(&_4$$3, redis);
		}
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "\"%s()\" expects parameter 1 to be Redis, RedisArray, RedisCluster or Predis\\ClientInterface, \"%s\" given.");
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "RedisSessionHandler:__construct");
		ZEPHIR_CALL_FUNCTION(&_7$$3, "sprintf", &_8, 3, &_5$$3, &_6$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 33, &_7$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "moon/Component/Http/Message/Session/Storage/Handler/RedisSessionHandler.zep", 35);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_9);
	zephir_array_keys(&_9, &options);
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 2, 0);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "prefix");
	zephir_array_fast_append(&_10, &_11);
	ZEPHIR_INIT_NVAR(&_11);
	ZVAL_STRING(&_11, "ttl");
	zephir_array_fast_append(&_10, &_11);
	ZEPHIR_CALL_FUNCTION(&diff, "array_diff", NULL, 209, &_9, &_10);
	zephir_check_call_status();
	if (zephir_is_true(&diff)) {
		ZEPHIR_INIT_VAR(&_12$$4);
		object_init_ex(&_12$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_13$$4);
		zephir_fast_join_str(&_13$$4, SL(", "), &diff);
		ZEPHIR_INIT_VAR(&_14$$4);
		ZVAL_STRING(&_14$$4, "The following options are not supported \"%s\".");
		ZEPHIR_CALL_FUNCTION(&_15$$4, "sprintf", &_8, 3, &_14$$4, &_13$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_12$$4, "__construct", NULL, 33, &_15$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$4, "moon/Component/Http/Message/Session/Storage/Handler/RedisSessionHandler.zep", 39);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("redis"), redis);
	ZEPHIR_INIT_VAR(&_16);
	if (zephir_array_isset_string(&options, SL("prefix"))) {
		ZEPHIR_OBS_NVAR(&_16);
		zephir_array_fetch_string(&_16, &options, SL("prefix"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/RedisSessionHandler.zep", 42);
	} else {
		ZEPHIR_INIT_NVAR(&_16);
		ZVAL_STRING(&_16, "sf_s");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_16);
	ZEPHIR_INIT_VAR(&_17);
	if (zephir_array_isset_string(&options, SL("ttl"))) {
		ZEPHIR_OBS_NVAR(&_17);
		zephir_array_fetch_string(&_17, &options, SL("ttl"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/RedisSessionHandler.zep", 43);
	} else {
		ZEPHIR_INIT_NVAR(&_17);
		ZVAL_NULL(&_17);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("ttl"), &_17);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_RedisSessionHandler, doRead) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, _0, _1, _2, _3, _4, _5$$4, _6$$4, _7$$4;
	zval sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(&sessionId, sessionId_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_3, &sessionId);
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_4);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZVAL_STRING(&_0, "");
	} else {
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_CONCAT_VV(&_7$$4, &_6$$4, &sessionId);
		ZEPHIR_CALL_METHOD(&_0, &_5$$4, "get", NULL, 0, &_7$$4);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_RedisSessionHandler, doWrite) {

	zend_bool _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *data_param = NULL, result, _0, _1, _2, _3, _4, _5;
	zval sessionId, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId_param, &data_param);

	zephir_get_strval(&sessionId, sessionId_param);
	zephir_get_strval(&data, data_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &sessionId);
	ZEPHIR_INIT_VAR(&_3);
	if (zephir_isset_property(this_ptr, SL("ttl"))) {
		ZEPHIR_OBS_NVAR(&_3);
		zephir_read_property(&_3, this_ptr, ZEND_STRL("ttl"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "session.gc_maxlifetime");
		ZEPHIR_CALL_FUNCTION(&_3, "ini_get", NULL, 13, &_4);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_5, zephir_get_intval(&_3));
	ZEPHIR_CALL_METHOD(&result, &_0, "setex", NULL, 0, &_2, &_5, &data);
	zephir_check_call_status();
	_6 = zephir_is_true(&result);
	if (_6) {
		_6 = !((zephir_is_instance_of(&result, SL("Predis\\Response\\ErrorInterface"))));
	}
	RETURN_MM_BOOL(_6);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_RedisSessionHandler, doDestroy) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, _0, _1, _2;
	zval sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(&sessionId, sessionId_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &sessionId);
	ZEPHIR_CALL_METHOD(NULL, &_0, "del", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_RedisSessionHandler, close) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_RedisSessionHandler, gc) {

	zval *maxlifetime, maxlifetime_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &maxlifetime);



	RETURN_BOOL(1);

}

/**
 * @param string $sessionId
 * @param string $data
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_RedisSessionHandler, updateTimestamp) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, *data, data_sub, _0, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &data);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("redis"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_2, sessionId);
	ZEPHIR_INIT_VAR(&_4);
	if (zephir_isset_property(this_ptr, SL("ttl"))) {
		ZEPHIR_OBS_NVAR(&_4);
		zephir_read_property(&_4, this_ptr, ZEND_STRL("ttl"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "session.gc_maxlifetime");
		ZEPHIR_CALL_FUNCTION(&_4, "ini_get", NULL, 13, &_5);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_6, zephir_get_intval(&_4));
	ZEPHIR_CALL_METHOD(&_1, &_0, "expire", NULL, 0, &_3, &_6);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_1));

}

