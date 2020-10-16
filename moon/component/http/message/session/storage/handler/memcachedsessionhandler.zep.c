
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/time.h"


/**
 * FileName: MemcachedSessionHandler.php
 * User: solely
 * DateTime: 2020/9/7 0:09
 * Description:
 */
/**
 * Memcached based session storage handler based on the Memcached class
 * provided by the PHP memcached extension.
 *
 * @see https://php.net/memcached
 *
 * Class MemcachedSessionHandler
 * @package Moon\Component\Http\Message\Session\Storage\Handler
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Handler_MemcachedSessionHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Session\\Storage\\Handler, MemcachedSessionHandler, moon, component_http_message_session_storage_handler_memcachedsessionhandler, moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, moon_component_http_message_session_storage_handler_memcachedsessionhandler_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_session_storage_handler_memcachedsessionhandler_ce, SL("memcached"), ZEND_ACC_PRIVATE);

	/**
	 * @var int Time to live in seconds
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_handler_memcachedsessionhandler_ce, SL("ttl"), ZEND_ACC_PRIVATE);

	/**
	 * @var string Key prefix for shared environments
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_handler_memcachedsessionhandler_ce, SL("prefix"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * Constructor.
 *
 * List of available options:
 *  * prefix: The prefix to use for the memcached keys in order to avoid collision
 *  * expiretime: The time to live in seconds.
 *
 * @param \Memcached $memcached
 * @param array $options
 * @throws \InvalidArgumentException When unsupported options are passed
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MemcachedSessionHandler, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _1;
	zval *memcached, memcached_sub, *options_param = NULL, diff, _0, _2, _7, _8, _9, _3$$3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&memcached_sub);
	ZVAL_UNDEF(&diff);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &memcached, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("memcached"), memcached);
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, &options);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "prefix");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "expiretime");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_CALL_FUNCTION(&diff, "array_diff", NULL, 209, &_0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&diff)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_fast_join_str(&_4$$3, SL(", "), &diff);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "The following options are not supported \"%s\".");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", NULL, 3, &_5$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 33, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "moon/Component/Http/Message/Session/Storage/Handler/MemcachedSessionHandler.zep", 46);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	if (zephir_array_isset_string(&options, SL("expiretime"))) {
		ZEPHIR_OBS_VAR(&_8);
		zephir_array_fetch_string(&_8, &options, SL("expiretime"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/MemcachedSessionHandler.zep", 48);
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_LONG(&_7, zephir_get_intval(&_8));
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_LONG(&_7, 86400);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("ttl"), &_7);
	ZEPHIR_INIT_VAR(&_9);
	if (zephir_array_isset_string(&options, SL("prefix"))) {
		ZEPHIR_OBS_NVAR(&_9);
		zephir_array_fetch_string(&_9, &options, SL("prefix"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/MemcachedSessionHandler.zep", 49);
	} else {
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_STRING(&_9, "moons");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_9);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MemcachedSessionHandler, close) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("memcached"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "quit", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MemcachedSessionHandler, doRead) {

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
	zephir_read_property(&_1, this_ptr, ZEND_STRL("memcached"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_3, &sessionId);
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_4);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZVAL_STRING(&_0, "");
	} else {
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("memcached"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_CONCAT_VV(&_7$$4, &_6$$4, &sessionId);
		ZEPHIR_CALL_METHOD(&_0, &_5$$4, "get", NULL, 0, &_7$$4);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * @param string $sessionId
 * @param string $data
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MemcachedSessionHandler, updateTimestamp) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, *data, data_sub, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &data);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("memcached"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, sessionId);
	ZEPHIR_INIT_VAR(&_3);
	zephir_time(&_3);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("ttl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	zephir_add_function(&_5, &_3, &_4);
	ZEPHIR_CALL_METHOD(NULL, &_0, "touch", NULL, 0, &_2, &_5);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MemcachedSessionHandler, doWrite) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *data_param = NULL, _0, _1, _2, _3, _4, _5;
	zval sessionId, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&data);
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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("memcached"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &sessionId);
	ZEPHIR_INIT_VAR(&_3);
	zephir_time(&_3);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("ttl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	zephir_add_function(&_5, &_3, &_4);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "set", NULL, 0, &_2, &data, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MemcachedSessionHandler, doDestroy) {

	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, result, _0, _1, _2, _4, _5;
	zval sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(&sessionId, sessionId_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("memcached"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &sessionId);
	ZEPHIR_CALL_METHOD(&result, &_0, "delete", NULL, 0, &_2);
	zephir_check_call_status();
	_3 = zephir_is_true(&result);
	if (!(_3)) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("memcached"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5, &_4, "getresultcode", NULL, 0);
		zephir_check_call_status();
		_3 = ZEPHIR_IS_LONG(&_5, 16);
	}
	RETURN_MM_BOOL(_3);

}

/**
 * @param int $maxlifetime
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MemcachedSessionHandler, gc) {

	zval *maxlifetime, maxlifetime_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &maxlifetime);



	RETURN_BOOL(1);

}

/**
 * Return a Memcached instance.
 *
 * @return \Memcached
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_MemcachedSessionHandler, getMemcached) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "memcached");

}

