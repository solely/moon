
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/spl/spl_iterators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * FileName: HeaderBag.php
 * User: solely
 * DateTime: 2020/7/13 23:17
 * Description:  
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_HeaderBag) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message, HeaderBag, moon, component_http_message_headerbag, moon_component_http_message_headerbag_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_headerbag_ce, SL("headers"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_headerbag_ce, SL("cacheControl"), ZEND_ACC_PROTECTED);

	moon_component_http_message_headerbag_ce->create_object = zephir_init_properties_Moon_Component_Http_Message_HeaderBag;
	zephir_declare_class_constant_string(moon_component_http_message_headerbag_ce, SL("UPPER"), "_ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	zephir_declare_class_constant_string(moon_component_http_message_headerbag_ce, SL("LOWER"), "-abcdefghijklmnopqrstuvwxyz");

	zend_class_implements(moon_component_http_message_headerbag_ce, 1, zend_ce_aggregate);
	zend_class_implements(moon_component_http_message_headerbag_ce, 1, spl_ce_Countable);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_HeaderBag, __construct) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, key, values, *_0, _1;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &headers_param);

	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	zephir_is_iterable(&headers, 0, "moon/Component/Http/Message/HeaderBag.zep", 22);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&values);
			ZVAL_COPY(&values, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &key, &values);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&values, &headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &key, &values);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&values);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the headers as a string.
 *
 * @return string The headers
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, __toString) {

	zend_string *_7;
	zend_ulong _6;
	zval content, max, headers, _0, _1, _2, _3, name, values, *_4, _5, _8$$4, _9$$4, value$$4, *_11$$4, _12$$4, _13$$5, _14$$5, _15$$5, _17$$6, _18$$6, _19$$6, _20$$7, _21$$7, value$$7, *_22$$7, _23$$7, _24$$8, _25$$8, _26$$8, _27$$9, _28$$9, _29$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&max);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&value$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&value$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_29$$9);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&headers, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&headers)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_MAKE_REF(&headers);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 186, &headers);
	ZEPHIR_UNREF(&headers);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, &headers);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "strlen");
	ZEPHIR_CALL_FUNCTION(&_2, "array_map", NULL, 83, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "max", NULL, 152, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&max);
	ZVAL_LONG(&max, (zephir_get_numberval(&_3) + 1));
	ZEPHIR_INIT_VAR(&content);
	ZVAL_STRING(&content, "");
	zephir_is_iterable(&headers, 0, "moon/Component/Http/Message/HeaderBag.zep", 50);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&name, _7);
			} else {
				ZVAL_LONG(&name, _6);
			}
			ZEPHIR_INIT_NVAR(&values);
			ZVAL_COPY(&values, _4);
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "-");
			ZEPHIR_CALL_FUNCTION(&_9$$4, "ucwords", &_10, 187, &name, &_8$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&name, &_9$$4);
			zephir_is_iterable(&values, 0, "moon/Component/Http/Message/HeaderBag.zep", 49);
			if (Z_TYPE_P(&values) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _11$$4)
				{
					ZEPHIR_INIT_NVAR(&value$$4);
					ZVAL_COPY(&value$$4, _11$$4);
					ZEPHIR_INIT_NVAR(&_13$$5);
					ZEPHIR_CONCAT_SVS(&_13$$5, "%-", &max, "s %s\r\n");
					ZEPHIR_INIT_NVAR(&_14$$5);
					ZEPHIR_CONCAT_VS(&_14$$5, &name, ":");
					ZEPHIR_CALL_FUNCTION(&_15$$5, "sprintf", &_16, 3, &_13$$5, &_14$$5, &value$$4);
					zephir_check_call_status();
					zephir_concat_self(&content, &_15$$5);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_12$$4, &values, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_12$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value$$4, &values, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_17$$6);
						ZEPHIR_CONCAT_SVS(&_17$$6, "%-", &max, "s %s\r\n");
						ZEPHIR_INIT_NVAR(&_18$$6);
						ZEPHIR_CONCAT_VS(&_18$$6, &name, ":");
						ZEPHIR_CALL_FUNCTION(&_19$$6, "sprintf", &_16, 3, &_17$$6, &_18$$6, &value$$4);
						zephir_check_call_status();
						zephir_concat_self(&content, &_19$$6);
					ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value$$4);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&values, &headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$7);
				ZVAL_STRING(&_20$$7, "-");
				ZEPHIR_CALL_FUNCTION(&_21$$7, "ucwords", &_10, 187, &name, &_20$$7);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&name, &_21$$7);
				zephir_is_iterable(&values, 0, "moon/Component/Http/Message/HeaderBag.zep", 49);
				if (Z_TYPE_P(&values) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _22$$7)
					{
						ZEPHIR_INIT_NVAR(&value$$7);
						ZVAL_COPY(&value$$7, _22$$7);
						ZEPHIR_INIT_NVAR(&_24$$8);
						ZEPHIR_CONCAT_SVS(&_24$$8, "%-", &max, "s %s\r\n");
						ZEPHIR_INIT_NVAR(&_25$$8);
						ZEPHIR_CONCAT_VS(&_25$$8, &name, ":");
						ZEPHIR_CALL_FUNCTION(&_26$$8, "sprintf", &_16, 3, &_24$$8, &_25$$8, &value$$7);
						zephir_check_call_status();
						zephir_concat_self(&content, &_26$$8);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_23$$7, &values, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_23$$7)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&value$$7, &values, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_27$$9);
							ZEPHIR_CONCAT_SVS(&_27$$9, "%-", &max, "s %s\r\n");
							ZEPHIR_INIT_NVAR(&_28$$9);
							ZEPHIR_CONCAT_VS(&_28$$9, &name, ":");
							ZEPHIR_CALL_FUNCTION(&_29$$9, "sprintf", &_16, 3, &_27$$9, &_28$$9, &value$$7);
							zephir_check_call_status();
							zephir_concat_self(&content, &_29$$9);
						ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&value$$7);
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&values);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&content);

}

/**
 * Returns the headers.
 *
 * @param string|null $key The name of the headers to return or null to get them all
 *
 * @return array An array of headers
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, all) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}


	if (!(Z_TYPE_P(&key) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "_ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "-abcdefghijklmnopqrstuvwxyz");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 128, &key, &_2$$3, &_3$$3);
		zephir_check_call_status();
		if (zephir_array_isset(&_1$$3, &_4$$3)) {
			zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "_ABCDEFGHIJKLMNOPQRSTUVWXYZ");
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "-abcdefghijklmnopqrstuvwxyz");
			ZEPHIR_CALL_FUNCTION(&_6$$3, "strtr", NULL, 128, &key, &_2$$3, &_3$$3);
			zephir_check_call_status();
			zephir_array_fetch(&_0$$3, &_5$$3, &_6$$3, PH_NOISY, "moon/Component/Http/Message/HeaderBag.zep", 63);
		} else {
			array_init(&_0$$3);
		}
		RETURN_CCTOR(&_0$$3);
	}
	RETURN_MM_MEMBER(getThis(), "headers");

}

/**
 * Returns the parameter keys.
 *
 * @return array An array of parameter keys
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, keys) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	zephir_array_keys(return_value, &_0);
	RETURN_MM();

}

/**
 * Replaces the current HTTP headers by a new set.
 * @param array $headers
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, replace) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, _0;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &headers_param);

	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &headers);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds new headers the current HTTP headers set.
 * @param array $headers
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, add) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, key, values, *_0, _1;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(&headers, headers_param);


	zephir_is_iterable(&headers, 0, "moon/Component/Http/Message/HeaderBag.zep", 99);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&values);
			ZVAL_COPY(&values, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &key, &values);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&values, &headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &key, &values);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&values);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a header value by name.
 * @param string $key
 * @param string|null $default
 * @return string|null  The first header value or default value
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_default_param = NULL, headers, _0, _1;
	zval key, _default, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_default);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &_default_param);

	zephir_get_strval(&key, key_param);
	if (!_default_param) {
		ZEPHIR_INIT_VAR(&_default);
		ZVAL_STRING(&_default, "");
	} else {
		zephir_get_strval(&_default, _default_param);
	}


	ZEPHIR_CALL_METHOD(&headers, this_ptr, "all", NULL, 0, &key);
	zephir_check_call_status();
	if (!zephir_is_true(&headers)) {
		RETURN_CTOR(&_default);
	}
	zephir_array_fetch_long(&_0, &headers, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/HeaderBag.zep", 114);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_long(&_1, &headers, 0, PH_NOISY, "moon/Component/Http/Message/HeaderBag.zep", 117);
	zephir_get_strval(&_2, &_1);
	RETURN_CTOR(&_2);

}

/**
 * Sets a header by name.
 *
 * @param string          $key
 * @param string|string[] $values  The value or an array of values
 * @param bool            $replace Whether to replace the actual value or not (true by default)
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, set) {

	zval _11$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool replace, _4$$3, _9$$6;
	zval *key_param = NULL, *values = NULL, values_sub, *replace_param = NULL, _0, _1, _2, _12, _3$$3, _5$$3, _6$$5, _7$$5, _8$$5, _10$$6, _13$$9, _14$$9, _15$$9, _16$$9;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&values_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_11$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &values, &replace_param);

	zephir_get_strval(&key, key_param);
	ZEPHIR_SEPARATE_PARAM(values);
	if (!replace_param) {
		replace = 1;
	} else {
		replace = zephir_get_boolval(replace_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "_ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "-abcdefghijklmnopqrstuvwxyz");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 128, &key, &_0, &_1);
	zephir_check_call_status();
	zephir_get_strval(&key, &_2);
	if (Z_TYPE_P(values) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_values", NULL, 98, values);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(values, &_3$$3);
		_4$$3 = replace == 1;
		if (!(_4$$3)) {
			zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
			_4$$3 = !(zephir_array_isset(&_5$$3, &key));
		}
		if (_4$$3) {
			zephir_update_property_array(this_ptr, SL("headers"), &key, values);
		} else {
			ZEPHIR_INIT_VAR(&_6$$5);
			zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_8$$5, &_7$$5, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/HeaderBag.zep", 135);
			zephir_fast_array_merge(&_6$$5, &_8$$5, values);
			zephir_update_property_array(this_ptr, SL("headers"), &key, &_6$$5);
		}
	} else {
		_9$$6 = replace == 1;
		if (!(_9$$6)) {
			zephir_read_property(&_10$$6, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
			_9$$6 = !(zephir_array_isset(&_10$$6, &key));
		}
		if (_9$$6) {
			ZEPHIR_INIT_VAR(&_11$$7);
			zephir_create_array(&_11$$7, 1, 0);
			zephir_array_fast_append(&_11$$7, values);
			zephir_update_property_array(this_ptr, SL("headers"), &key, &_11$$7);
		} else {
			zephir_update_property_array_multi(this_ptr, SL("headers"), values, SL("za"), 2, &key);
		}
	}
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "cache-control");
	if (ZEPHIR_IS_IDENTICAL(&_12, &key)) {
		ZEPHIR_INIT_VAR(&_14$$9);
		zephir_read_property(&_15$$9, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_16$$9, &_15$$9, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/HeaderBag.zep", 145);
		zephir_fast_join_str(&_14$$9, SL(", "), &_16$$9);
		ZEPHIR_CALL_METHOD(&_13$$9, this_ptr, "parsecachecontrol", NULL, 0, &_14$$9);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("cacheControl"), &_13$$9);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns true if the HTTP header is defined.
 * @param string $key
 * @return bool  true if the parameter exists, false otherwise
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1, _2, _3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "_ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "-abcdefghijklmnopqrstuvwxyz");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 128, &key, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_key_exists(&_3, &_2));

}

/**
 * Returns true if the given HTTP header contains the given value.
 *
 * @param string $key
 * @param string $value
 * @return bool true if the value is contained in the header, false otherwise
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, contains) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, _0;
	zval key, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value_param);

	zephir_get_strval(&key, key_param);
	zephir_get_strval(&value, value_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "all", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_fast_in_array(&value, &_0));

}

/**
 * Removes a header.
 * @param string $key
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, remove) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key, *key_param = NULL, _0, _1, _2, _3, _4, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "_ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "-abcdefghijklmnopqrstuvwxyz");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 128, &key, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&key, &_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_3, &key, PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "cache-control");
	if (ZEPHIR_IS_IDENTICAL(&_4, &key)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		array_init(&_5$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("cacheControl"), &_5$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the HTTP header value converted to a date.
 *
 * @param string $key
 * @param \DateTime|null $default
 * @return \DateTimeInterface|null The parsed DateTime or the default value if the header does not exist
 *
 * @throws \RuntimeException When the HTTP header is not parseable
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, getDate) {

	zend_class_entry *_0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_default, _default_sub, date, value, _1, _2$$4, _3$$4, _4$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_UNDEF(&date);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &_default);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&value, this_ptr, "get", NULL, 0, &key);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) == IS_NULL) {
		RETVAL_ZVAL(_default, 1, 0);
		RETURN_MM();
	}
	_0 = zephir_fetch_class_str_ex(SL("DateTime"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "D, d M Y H:i:s O");
	ZEPHIR_CALL_CE_STATIC(&date, _0, "createfromformat", NULL, 0, &_1, &value);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&date)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "The \"%s\" HTTP header is not parseable (%s).");
		ZEPHIR_CALL_FUNCTION(&_4$$4, "sprintf", NULL, 3, &_3$$4, &key, &value);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 34, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "moon/Component/Http/Message/HeaderBag.zep", 204);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&date);

}

/**
 * Adds a custom Cache-Control directive.
 *
 * @param string $key
 * @param mixed $value The Cache-Control directive value
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, addCacheControlDirective) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value = NULL, value_sub, __$true, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &value);

	zephir_get_strval(&key, key_param);
	if (!value) {
		value = &value_sub;
		value = &__$true;
	}


	zephir_update_property_array(this_ptr, SL("cacheControl"), &key, value);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcachecontrolheader", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Cache-Control");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns true if the Cache-Control directive is defined.
 *
 * @param string $key
 * @return bool true if the directive exists, false otherwise
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, hasCacheControlDirective) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("cacheControl"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_key_exists(&_0, &key));

}

/**
 * Returns a Cache-Control directive value by name.
 *
 * @param string $key
 * @return mixed|null The directive value if defined, null otherwise
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, getCacheControlDirective) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("cacheControl"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_1, &key)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("cacheControl"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &key, PH_NOISY, "moon/Component/Http/Message/HeaderBag.zep", 240);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Removes a Cache-Control directive.
 * @param string $key
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, removeCacheControlDirective) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("cacheControl"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &key, PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcachecontrolheader", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Cache-Control");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns an iterator for headers.
 *
 * @return \ArrayIterator An \ArrayIterator instance
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, getIterator) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SL("arrayiterator")));
	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 37, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the number of headers.
 *
 * @return int The number of headers
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));

}

PHP_METHOD(Moon_Component_Http_Message_HeaderBag, getCacheControlHeader) {

	zval _0, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("cacheControl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&_0);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 186, &_0);
	ZEPHIR_UNREF(&_0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("cacheControl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, ",");
	ZEPHIR_RETURN_CALL_CE_STATIC(moon_component_http_message_headerutils_ce, "tostring", &_1, 0, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Parses a Cache-Control HTTP header.
 *
 * @return array An array representing the attribute values
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderBag, parseCacheControl) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *header_param = NULL, parts, _1;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

	zephir_get_strval(&header, header_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ",=");
	ZEPHIR_CALL_CE_STATIC(&parts, moon_component_http_message_headerutils_ce, "split", &_0, 0, &header, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_CE_STATIC(moon_component_http_message_headerutils_ce, "combine", &_2, 0, &parts);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Moon_Component_Http_Message_HeaderBag(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("cacheControl"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("cacheControl"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("headers"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

