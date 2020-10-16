
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * FileName: ServerBag.php
 * User: solely
 * DateTime: 2020/7/13 23:15
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_ServerBag) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message, ServerBag, moon, component_http_message_serverbag, moon_component_http_message_parameterbag_ce, moon_component_http_message_serverbag_method_entry, 0);

	return SUCCESS;

}

/**
 * Gets the HTTP headers.
 *
 * @return array
 */
PHP_METHOD(Moon_Component_Http_Message_ServerBag, getHeaders) {

	zend_bool _34$$13;
	zval _7$$3, _15$$6;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zval __$true, exploded, authorizationHeader, headers, key, value, _0, *_1, _2, _20, _5$$3, _6$$3, _8$$3, _9$$3, _11$$4, _12$$4, _13$$6, _14$$6, _16$$6, _17$$6, _18$$7, _19$$7, _21$$9, _22$$9, _23$$9, _24$$9, _25$$9, _26$$10, _27$$10, _28$$11, _29$$12, _30$$13, _31$$13, _32$$13, _33$$13, _35$$13, _36$$13, _37$$14, _38$$14, _39$$14, _40$$14, _41$$15, _42$$15, _43$$16, _44$$19, _45$$19, _46$$19, _47$$19, _48$$19, _49$$20;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&exploded);
	ZVAL_UNDEF(&authorizationHeader);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_42$$15);
	ZVAL_UNDEF(&_43$$16);
	ZVAL_UNDEF(&_44$$19);
	ZVAL_UNDEF(&_45$$19);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_47$$19);
	ZVAL_UNDEF(&_48$$19);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_15$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "moon/Component/Http/Message/ServerBag.zep", 31);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_STRING(&_5$$3, "HTTP_");
			ZEPHIR_INIT_NVAR(&_6$$3);
			zephir_fast_strpos(&_6$$3, &key, &_5$$3, 0 );
			ZEPHIR_INIT_NVAR(&_7$$3);
			zephir_create_array(&_7$$3, 3, 0);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "CONTENT_TYPE");
			zephir_array_fast_append(&_7$$3, &_8$$3);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "CONTENT_LENGTH");
			zephir_array_fast_append(&_7$$3, &_8$$3);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "CONTENT_MD5");
			zephir_array_fast_append(&_7$$3, &_8$$3);
			ZEPHIR_CALL_FUNCTION(&_9$$3, "in_array", &_10, 5, &key, &_7$$3, &__$true);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_6$$3, 0)) {
				ZVAL_LONG(&_11$$4, 5);
				ZEPHIR_INIT_NVAR(&_12$$4);
				zephir_substr(&_12$$4, &key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				zephir_array_update_zval(&headers, &_12$$4, &value, PH_COPY | PH_SEPARATE);
			} else if (zephir_is_true(&_9$$3)) {
				zephir_array_update_zval(&headers, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$6);
				ZVAL_STRING(&_13$$6, "HTTP_");
				ZEPHIR_INIT_NVAR(&_14$$6);
				zephir_fast_strpos(&_14$$6, &key, &_13$$6, 0 );
				ZEPHIR_INIT_NVAR(&_15$$6);
				zephir_create_array(&_15$$6, 3, 0);
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZVAL_STRING(&_16$$6, "CONTENT_TYPE");
				zephir_array_fast_append(&_15$$6, &_16$$6);
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZVAL_STRING(&_16$$6, "CONTENT_LENGTH");
				zephir_array_fast_append(&_15$$6, &_16$$6);
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZVAL_STRING(&_16$$6, "CONTENT_MD5");
				zephir_array_fast_append(&_15$$6, &_16$$6);
				ZEPHIR_CALL_FUNCTION(&_17$$6, "in_array", &_10, 5, &key, &_15$$6, &__$true);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_14$$6, 0)) {
					ZVAL_LONG(&_18$$7, 5);
					ZEPHIR_INIT_NVAR(&_19$$7);
					zephir_substr(&_19$$7, &key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
					zephir_array_update_zval(&headers, &_19$$7, &value, PH_COPY | PH_SEPARATE);
				} else if (zephir_is_true(&_17$$6)) {
					zephir_array_update_zval(&headers, &key, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_read_property(&_20, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_20, SL("PHP_AUTH_USER"))) {
		zephir_read_property(&_21$$9, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_22$$9, &_21$$9, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/ServerBag.zep", 32);
		zephir_array_update_string(&headers, SL("PHP_AUTH_USER"), &_22$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_23$$9);
		zephir_read_property(&_24$$9, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string(&_24$$9, SL("PHP_AUTH_PW"))) {
			zephir_read_property(&_25$$9, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&_23$$9);
			zephir_array_fetch_string(&_23$$9, &_25$$9, SL("PHP_AUTH_PW"), PH_NOISY, "moon/Component/Http/Message/ServerBag.zep", 33);
		} else {
			ZEPHIR_INIT_NVAR(&_23$$9);
			ZVAL_STRING(&_23$$9, "");
		}
		zephir_array_update_string(&headers, SL("PHP_AUTH_PW"), &_23$$9, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(&authorizationHeader);
		ZVAL_NULL(&authorizationHeader);
		zephir_read_property(&_26$$10, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_27$$10, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string(&_26$$10, SL("HTTP_AUTHORIZATION"))) {
			zephir_read_property(&_28$$11, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&authorizationHeader);
			zephir_array_fetch_string(&authorizationHeader, &_28$$11, SL("HTTP_AUTHORIZATION"), PH_NOISY, "moon/Component/Http/Message/ServerBag.zep", 50);
		} else if (zephir_array_isset_string(&_27$$10, SL("REDIRECT_HTTP_AUTHORIZATION"))) {
			zephir_read_property(&_29$$12, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&authorizationHeader);
			zephir_array_fetch_string(&authorizationHeader, &_29$$12, SL("REDIRECT_HTTP_AUTHORIZATION"), PH_NOISY, "moon/Component/Http/Message/ServerBag.zep", 52);
		}
		if (Z_TYPE_P(&authorizationHeader) != IS_NULL) {
			ZEPHIR_INIT_VAR(&_30$$13);
			ZVAL_STRING(&_30$$13, "basic ");
			ZEPHIR_CALL_FUNCTION(&_31$$13, "stripos", NULL, 199, &authorizationHeader, &_30$$13);
			zephir_check_call_status();
			zephir_read_property(&_32$$13, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_VAR(&_33$$13);
			zephir_array_fetch_string(&_33$$13, &_32$$13, SL("PHP_AUTH_DIGEST"), PH_NOISY, "moon/Component/Http/Message/ServerBag.zep", 63);
			_34$$13 = ZEPHIR_IS_EMPTY(&_33$$13);
			if (_34$$13) {
				ZEPHIR_INIT_NVAR(&_30$$13);
				ZVAL_STRING(&_30$$13, "digest ");
				ZEPHIR_CALL_FUNCTION(&_35$$13, "stripos", NULL, 199, &authorizationHeader, &_30$$13);
				zephir_check_call_status();
				_34$$13 = ZEPHIR_IS_LONG_IDENTICAL(&_35$$13, 0);
			}
			ZEPHIR_INIT_NVAR(&_30$$13);
			ZVAL_STRING(&_30$$13, "bearer ");
			ZEPHIR_CALL_FUNCTION(&_36$$13, "stripos", NULL, 199, &authorizationHeader, &_30$$13);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_31$$13, 0)) {
				ZVAL_LONG(&_37$$14, 6);
				ZEPHIR_INIT_VAR(&_38$$14);
				zephir_substr(&_38$$14, &authorizationHeader, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_CALL_FUNCTION(&_39$$14, "base64_decode", NULL, 200, &_38$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_40$$14);
				ZVAL_STRING(&_40$$14, ":");
				ZEPHIR_INIT_VAR(&exploded);
				zephir_fast_explode(&exploded, &_40$$14, &_39$$14, 2 );
				if (2 == zephir_fast_count_int(&exploded)) {
					zephir_array_fetch_long(&_41$$15, &exploded, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/ServerBag.zep", 60);
					zephir_array_update_string(&headers, SL("PHP_AUTH_USER"), &_41$$15, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_long(&_42$$15, &exploded, 1, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/ServerBag.zep", 61);
					zephir_array_update_string(&headers, SL("PHP_AUTH_PW"), &_42$$15, PH_COPY | PH_SEPARATE);
				}
			} else if (_34$$13) {
				zephir_array_update_string(&headers, SL("PHP_AUTH_DIGEST"), &authorizationHeader, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_VAR(&_43$$16);
				ZVAL_STRING(&_43$$16, "PHP_AUTH_DIGEST");
				zephir_update_property_array(this_ptr, SL("parameters"), &_43$$16, &authorizationHeader);
			} else if (ZEPHIR_IS_LONG_IDENTICAL(&_36$$13, 0)) {
				zephir_array_update_string(&headers, SL("AUTHORIZATION"), &authorizationHeader, PH_COPY | PH_SEPARATE);
			}
		}
	}
	if (zephir_array_isset_string(&headers, SL("AUTHORIZATION"))) {
		RETURN_CCTOR(&headers);
	}
	if (zephir_array_isset_string(&headers, SL("PHP_AUTH_USER"))) {
		zephir_array_fetch_string(&_44$$19, &headers, SL("PHP_AUTH_USER"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/ServerBag.zep", 82);
		zephir_array_fetch_string(&_45$$19, &headers, SL("PHP_AUTH_PW"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/ServerBag.zep", 82);
		ZEPHIR_INIT_VAR(&_46$$19);
		ZEPHIR_CONCAT_VSV(&_46$$19, &_44$$19, ":", &_45$$19);
		ZEPHIR_CALL_FUNCTION(&_47$$19, "base64_encode", NULL, 201, &_46$$19);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_48$$19);
		ZEPHIR_CONCAT_SV(&_48$$19, "Basic ", &_47$$19);
		zephir_array_update_string(&headers, SL("AUTHORIZATION"), &_48$$19, PH_COPY | PH_SEPARATE);
	} else if (zephir_array_isset_string(&headers, SL("PHP_AUTH_DIGEST"))) {
		zephir_array_fetch_string(&_49$$20, &headers, SL("PHP_AUTH_DIGEST"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/ServerBag.zep", 84);
		zephir_array_update_string(&headers, SL("AUTHORIZATION"), &_49$$20, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&headers);

}

