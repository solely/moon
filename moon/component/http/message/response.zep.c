
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * FileName: Response.php
 * User: solely
 * DateTime: 2019/1/21 0:21
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Response) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message, Response, moon, component_http_message_response, moon_component_http_message_message_ce, moon_component_http_message_response_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_response_ce, SL("phrase"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	zend_declare_property_null(moon_component_http_message_response_ce, SL("statusCode"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_response_ce, SL("reasonPhrase"), ZEND_ACC_PRIVATE);

	zend_class_implements(moon_component_http_message_response_ce, 1, zephir_get_internal_ce(SL("psrext\\http\\message\\responseinterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Response, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, *statusCode = NULL, statusCode_sub, *headers = NULL, headers_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&statusCode_sub);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &content, &statusCode, &headers);

	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "php://memory");
	}
	if (!statusCode) {
		statusCode = &statusCode_sub;
		ZEPHIR_INIT_VAR(statusCode);
		ZVAL_LONG(statusCode, 200);
	}
	if (!headers) {
		headers = &headers_sub;
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "wb+");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getstream", NULL, 0, content, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("body"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheaders", NULL, 0, headers);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, statusCode);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Response, getStatusCode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "statusCode");

}

PHP_METHOD(Moon_Component_Http_Message_Response, withStatus) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub, *reasonPhrase = NULL, reasonPhrase_sub, _new;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&reasonPhrase_sub);
	ZVAL_UNDEF(&_new);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &code, &reasonPhrase);

	if (!reasonPhrase) {
		reasonPhrase = &reasonPhrase_sub;
		ZEPHIR_INIT_VAR(reasonPhrase);
		ZVAL_STRING(reasonPhrase, "");
	}


	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, &_new, "setstatuscode", NULL, 0, code, reasonPhrase);
	zephir_check_call_status();
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Response, getReasonPhrase) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "reasonPhrase");

}

PHP_METHOD(Moon_Component_Http_Message_Response, setStatusCode) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *statusCode_param = NULL, *reasonPhrase = NULL, reasonPhrase_sub, _0, _1, _2, _3;
	zend_long statusCode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reasonPhrase_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statusCode_param, &reasonPhrase);

	statusCode = zephir_get_intval(statusCode_param);
	if (!reasonPhrase) {
		reasonPhrase = &reasonPhrase_sub;
		ZEPHIR_INIT_VAR(reasonPhrase);
		ZVAL_STRING(reasonPhrase, "");
	}


	zephir_read_static_property_ce(&_0, moon_component_http_message_response_ce, SL("phrase"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_long(&_0, statusCode))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid HTTP status", "moon/Component/Http/Message/Response.zep", 129);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, statusCode);
	zephir_update_property_zval(this_ptr, ZEND_STRL("statusCode"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	if (ZEPHIR_IS_IDENTICAL(&_3, reasonPhrase)) {
		zephir_read_static_property_ce(&_1, moon_component_http_message_response_ce, SL("phrase"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_2);
		zephir_array_fetch_long(&_2, &_1, statusCode, PH_NOISY, "moon/Component/Http/Message/Response.zep", 132);
	} else {
		ZEPHIR_CPY_WRT(&_2, reasonPhrase);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("reasonPhrase"), &_2);
	ZEPHIR_MM_RESTORE();

}

/**
 * Is the response a redirect of some form?
 * @param string|null $location
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Response, isRedirect) {

	zend_bool _3;
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *location = NULL, location_sub, __$null, _0, _2, _4, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&location_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &location);

	if (!location) {
		location = &location_sub;
		location = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 6, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, 201);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 301);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 302);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 303);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 307);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 308);
	zephir_array_fast_append(&_1, &_2);
	_3 = zephir_fast_in_array(&_0, &_1);
	if (_3) {
		ZEPHIR_INIT_VAR(&_4);
		ZEPHIR_INIT_NVAR(&_4);
		if (!(Z_TYPE_P(location) == IS_NULL)) {
			ZEPHIR_INIT_VAR(&_6$$3);
			ZVAL_STRING(&_6$$3, "Location");
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getheaderline", NULL, 0, &_6$$3);
			zephir_check_call_status();
			ZVAL_BOOL(&_4, ZEPHIR_IS_EQUAL(location, &_5$$3));
		} else {
			ZVAL_BOOL(&_4, Z_TYPE_P(location) == IS_NULL);
		}
		_3 = zephir_is_true(&_4);
	}
	RETURN_MM_BOOL(_3);

}

/**
 * Is the response empty?
 *
 * @final
 */
PHP_METHOD(Moon_Component_Http_Message_Response, isEmpty) {

	zval _1;
	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, 204);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_2, 304);
	zephir_array_fast_append(&_1, &_2);
	RETURN_MM_BOOL(zephir_fast_in_array(&_0, &_1));

}

/**
 * Is response successful?
 *
 * @final
 */
PHP_METHOD(Moon_Component_Http_Message_Response, isSuccessful) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 200);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 300);
	}
	RETURN_BOOL(_1);

}

/**
 * Is the response a redirect?
 *
 * @final
 */
PHP_METHOD(Moon_Component_Http_Message_Response, isRedirection) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 300);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 400);
	}
	RETURN_BOOL(_1);

}

/**
 * Is there a client error?
 *
 * @final
 */
PHP_METHOD(Moon_Component_Http_Message_Response, isClientError) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 400);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 500);
	}
	RETURN_BOOL(_1);

}

/**
 * Was there a server side error?
 *
 * @final
 */
PHP_METHOD(Moon_Component_Http_Message_Response, isServerError) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 500);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 600);
	}
	RETURN_BOOL(_1);

}

/**
 * Is the response OK?
 *
 * @final
 */
PHP_METHOD(Moon_Component_Http_Message_Response, isOk) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 200));

}

/**
 * Is the response forbidden?
 *
 * @final
 */
PHP_METHOD(Moon_Component_Http_Message_Response, isForbidden) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 403));

}

/**
 * Is the response a not found error?
 *
 * @final
 */
PHP_METHOD(Moon_Component_Http_Message_Response, isNotFound) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 404));

}

/**
 * Sends HTTP headers and content.
 *
 * @return $this
 */
PHP_METHOD(Moon_Component_Http_Message_Response, send) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, _0, _2, _3, _4$$4, _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_SAPI");
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "cli");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "phpdbg");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_CALL_FUNCTION(&_3, "in_array", NULL, 5, &_0, &_1, &__$true);
	zephir_check_call_status();
	if ((zephir_function_exists_ex(ZEND_STRL("fastcgi_finish_request")) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(NULL, "fastcgi_finish_request", NULL, 6);
		zephir_check_call_status();
	} else if (!zephir_is_true(&_3)) {
		ZVAL_LONG(&_4$$4, 0);
		ZVAL_BOOL(&_5$$4, 1);
		ZEPHIR_CALL_STATIC(NULL, "closeoutputbuffers", NULL, 0, &_4$$4, &_5$$4);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Cleans or flushes output buffers up to target level.
 *
 * Resulting level can be greater than target level if a non-removable buffer has been encountered.
 *
 * @param int $targetLevel
 * @param bool $flush
 */
PHP_METHOD(Moon_Component_Http_Message_Response, closeOutputBuffers) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL;
	zend_bool flush, _1, _2, _4;
	zval *targetLevel_param = NULL, *flush_param = NULL, __$true, s, flags, level, status, _0, _3, _5, _6, _7$$3;
	zend_long targetLevel, ZEPHIR_LAST_CALL_STATUS, po;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&flags);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &targetLevel_param, &flush_param);

	targetLevel = zephir_get_intval(targetLevel_param);
	flush = zephir_get_boolval(flush_param);


	ZEPHIR_CALL_FUNCTION(&status, "ob_get_status", NULL, 7, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&level);
	ZVAL_LONG(&level, zephir_fast_count_int(&status));
	po = 0;
	ZEPHIR_INIT_VAR(&_0);
	if (flush) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 32);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 16);
	}
	po = zephir_get_numberval(&_0);
	ZEPHIR_INIT_VAR(&flags);
	ZVAL_LONG(&flags, (64 | po));
	ZEPHIR_OBS_VAR(&s);
	zephir_array_fetch(&s, &status, &level, PH_NOISY, "moon/Component/Http/Message/Response.zep", 261);
	while (1) {
		_1 = ZEPHIR_GT_LONG(&level, targetLevel);
		if (_1) {
			_1 = zephir_is_true(&s);
		}
		_2 = _1;
		if (_2) {
			ZEPHIR_INIT_NVAR(&_3);
			if (!(zephir_array_isset_string(&s, SL("del")))) {
				_4 = !(zephir_array_isset_string(&s, SL("flags")));
				if (!(_4)) {
					zephir_array_fetch_string(&_5, &s, SL("flags"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Response.zep", 262);
					ZEPHIR_INIT_NVAR(&_6);
					zephir_bitwise_and_function(&_6, &_5, &flags);
					_4 = ZEPHIR_IS_IDENTICAL(&_6, &flags);
				}
				ZEPHIR_INIT_NVAR(&_3);
				ZVAL_BOOL(&_3, _4);
			} else {
				ZEPHIR_OBS_NVAR(&_3);
				zephir_array_fetch_string(&_3, &s, SL("del"), PH_NOISY, "moon/Component/Http/Message/Response.zep", 262);
			}
			_2 = zephir_is_true(&_3);
		}
		if (!(_2)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_LONG(&_7$$3, 1);
		ZEPHIR_SUB_ASSIGN(&level, &_7$$3);
		ZEPHIR_OBS_NVAR(&s);
		zephir_array_fetch(&s, &status, &level, PH_NOISY, "moon/Component/Http/Message/Response.zep", 264);
		if (flush) {
			ZEPHIR_CALL_FUNCTION(NULL, "ob_end_flush", &_8, 8);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", &_9, 9);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sends HTTP headers.
 *
 * @return $this
 */
PHP_METHOD(Moon_Component_Http_Message_Response, sendHeaders) {

	zend_string *_5;
	zend_ulong _4;
	zend_bool replace = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, _0, name, values, _1, *_2, _3, _34, _35, _36, _37, _38, _39, _6$$4, _7$$4, value$$5, *_9$$5, _10$$5, _11$$6, _12$$6, _13$$6, _15$$7, _16$$7, _17$$7, _18$$8, _19$$8, _20$$8, _21$$9, _22$$9, value$$10, *_23$$10, _24$$10, _25$$11, _26$$11, _27$$11, _28$$12, _29$$12, _30$$12, _31$$13, _32$$13, _33$$13;
	zephir_fcall_cache_entry *_8 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&value$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&value$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 10);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getheaders", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "moon/Component/Http/Message/Response.zep", 301);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&name, _5);
			} else {
				ZVAL_LONG(&name, _4);
			}
			ZEPHIR_INIT_NVAR(&values);
			ZVAL_COPY(&values, _2);
			ZEPHIR_INIT_NVAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "Content-Type");
			ZEPHIR_CALL_FUNCTION(&_7$$4, "strcasecmp", &_8, 11, &name, &_6$$4);
			zephir_check_call_status();
			replace = ZEPHIR_IS_LONG_IDENTICAL(&_7$$4, 0);
			if (Z_TYPE_P(&values) == IS_ARRAY) {
				zephir_is_iterable(&values, 0, "moon/Component/Http/Message/Response.zep", 295);
				if (Z_TYPE_P(&values) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _9$$5)
					{
						ZEPHIR_INIT_NVAR(&value$$5);
						ZVAL_COPY(&value$$5, _9$$5);
						ZEPHIR_INIT_NVAR(&_11$$6);
						ZEPHIR_CONCAT_VSV(&_11$$6, &name, ": ", &value$$5);
						zephir_read_property(&_12$$6, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
						ZVAL_BOOL(&_13$$6, (replace ? 1 : 0));
						ZEPHIR_CALL_FUNCTION(NULL, "header", &_14, 12, &_11$$6, &_13$$6, &_12$$6);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_10$$5, &values, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_10$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&value$$5, &values, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_15$$7);
							ZEPHIR_CONCAT_VSV(&_15$$7, &name, ": ", &value$$5);
							zephir_read_property(&_16$$7, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
							ZVAL_BOOL(&_17$$7, (replace ? 1 : 0));
							ZEPHIR_CALL_FUNCTION(NULL, "header", &_14, 12, &_15$$7, &_17$$7, &_16$$7);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&value$$5);
			} else {
				ZEPHIR_INIT_NVAR(&_18$$8);
				ZEPHIR_CONCAT_VSV(&_18$$8, &name, ": ", &values);
				zephir_read_property(&_19$$8, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
				ZVAL_BOOL(&_20$$8, (replace ? 1 : 0));
				ZEPHIR_CALL_FUNCTION(NULL, "header", &_14, 12, &_18$$8, &_20$$8, &_19$$8);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &_1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&values, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$9);
				ZVAL_STRING(&_21$$9, "Content-Type");
				ZEPHIR_CALL_FUNCTION(&_22$$9, "strcasecmp", &_8, 11, &name, &_21$$9);
				zephir_check_call_status();
				replace = ZEPHIR_IS_LONG_IDENTICAL(&_22$$9, 0);
				if (Z_TYPE_P(&values) == IS_ARRAY) {
					zephir_is_iterable(&values, 0, "moon/Component/Http/Message/Response.zep", 295);
					if (Z_TYPE_P(&values) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _23$$10)
						{
							ZEPHIR_INIT_NVAR(&value$$10);
							ZVAL_COPY(&value$$10, _23$$10);
							ZEPHIR_INIT_NVAR(&_25$$11);
							ZEPHIR_CONCAT_VSV(&_25$$11, &name, ": ", &value$$10);
							zephir_read_property(&_26$$11, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
							ZVAL_BOOL(&_27$$11, (replace ? 1 : 0));
							ZEPHIR_CALL_FUNCTION(NULL, "header", &_14, 12, &_25$$11, &_27$$11, &_26$$11);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_24$$10, &values, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_24$$10)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&value$$10, &values, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_28$$12);
								ZEPHIR_CONCAT_VSV(&_28$$12, &name, ": ", &value$$10);
								zephir_read_property(&_29$$12, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
								ZVAL_BOOL(&_30$$12, (replace ? 1 : 0));
								ZEPHIR_CALL_FUNCTION(NULL, "header", &_14, 12, &_28$$12, &_30$$12, &_29$$12);
								zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&value$$10);
				} else {
					ZEPHIR_INIT_NVAR(&_31$$13);
					ZEPHIR_CONCAT_VSV(&_31$$13, &name, ": ", &values);
					zephir_read_property(&_32$$13, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
					ZVAL_BOOL(&_33$$13, (replace ? 1 : 0));
					ZEPHIR_CALL_FUNCTION(NULL, "header", &_14, 12, &_31$$13, &_33$$13, &_32$$13);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&values);
	ZEPHIR_INIT_NVAR(&name);
	zephir_read_property(&_34, this_ptr, ZEND_STRL("protocolVersion"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_35, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_36, this_ptr, ZEND_STRL("reasonPhrase"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_37);
	ZVAL_STRING(&_37, "HTTP/%s %s %s");
	ZEPHIR_CALL_FUNCTION(&_38, "sprintf", NULL, 3, &_37, &_34, &_35, &_36);
	zephir_check_call_status();
	zephir_read_property(&_39, this_ptr, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_14, 12, &_38, &__$true, &_39);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sends content for the current web response.
 *
 * @return $this
 */
PHP_METHOD(Moon_Component_Http_Message_Response, sendContent) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getbody", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "getcontents", NULL, 0);
	zephir_check_call_status();
	zend_print_zval(&_1, 0);
	RETURN_THIS();

}

void zephir_init_static_properties_Moon_Component_Http_Message_Response(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 62, 0);
	add_index_stringl(&_0, 100, SL("Continue"));
	add_index_stringl(&_0, 101, SL("Switching Protocols"));
	add_index_stringl(&_0, 102, SL("Processing"));
	add_index_stringl(&_0, 103, SL("Early Hints"));
	add_index_stringl(&_0, 200, SL("OK"));
	add_index_stringl(&_0, 201, SL("Created"));
	add_index_stringl(&_0, 202, SL("Accepted"));
	add_index_stringl(&_0, 203, SL("Non-Authoritative Information"));
	add_index_stringl(&_0, 204, SL("No Content"));
	add_index_stringl(&_0, 205, SL("Reset Content"));
	add_index_stringl(&_0, 206, SL("Partial Content"));
	add_index_stringl(&_0, 207, SL("Multi-Status"));
	add_index_stringl(&_0, 208, SL("Already Reported"));
	add_index_stringl(&_0, 226, SL("IM Used"));
	add_index_stringl(&_0, 300, SL("Multiple Choices"));
	add_index_stringl(&_0, 301, SL("Moved Permanently"));
	add_index_stringl(&_0, 302, SL("Found"));
	add_index_stringl(&_0, 303, SL("See Other"));
	add_index_stringl(&_0, 304, SL("Not Modified"));
	add_index_stringl(&_0, 305, SL("Use Proxy"));
	add_index_stringl(&_0, 307, SL("Temporary Redirect"));
	add_index_stringl(&_0, 308, SL("Permanent Redirect"));
	add_index_stringl(&_0, 400, SL("Bad Request"));
	add_index_stringl(&_0, 401, SL("Unauthorized"));
	add_index_stringl(&_0, 402, SL("Payment Required"));
	add_index_stringl(&_0, 403, SL("Forbidden"));
	add_index_stringl(&_0, 404, SL("Not Found"));
	add_index_stringl(&_0, 405, SL("Method Not Allowed"));
	add_index_stringl(&_0, 406, SL("Not Acceptable"));
	add_index_stringl(&_0, 407, SL("Proxy Authentication Required"));
	add_index_stringl(&_0, 408, SL("Request Timeout"));
	add_index_stringl(&_0, 409, SL("Conflict"));
	add_index_stringl(&_0, 410, SL("Gone"));
	add_index_stringl(&_0, 411, SL("Length Required"));
	add_index_stringl(&_0, 412, SL("Precondition Failed"));
	add_index_stringl(&_0, 413, SL("Payload Too Large"));
	add_index_stringl(&_0, 414, SL("URI Too Long"));
	add_index_stringl(&_0, 415, SL("Unsupported Media Type"));
	add_index_stringl(&_0, 416, SL("Range Not Satisfiable"));
	add_index_stringl(&_0, 417, SL("Expectation Failed"));
	add_index_stringl(&_0, 418, SL("I'm a teapot"));
	add_index_stringl(&_0, 421, SL("Misdirected Request"));
	add_index_stringl(&_0, 422, SL("Unprocessable Entity"));
	add_index_stringl(&_0, 423, SL("Locked"));
	add_index_stringl(&_0, 424, SL("Failed Dependency"));
	add_index_stringl(&_0, 425, SL("Too Early"));
	add_index_stringl(&_0, 426, SL("Upgrade Required"));
	add_index_stringl(&_0, 428, SL("Precondition Required"));
	add_index_stringl(&_0, 429, SL("Too Many Requests"));
	add_index_stringl(&_0, 431, SL("Request Header Fields Too Large"));
	add_index_stringl(&_0, 451, SL("Unavailable For Legal Reasons"));
	add_index_stringl(&_0, 500, SL("Internal Server Error"));
	add_index_stringl(&_0, 501, SL("Not Implemented"));
	add_index_stringl(&_0, 502, SL("Bad Gateway"));
	add_index_stringl(&_0, 503, SL("Service Unavailable"));
	add_index_stringl(&_0, 504, SL("Gateway Timeout"));
	add_index_stringl(&_0, 505, SL("HTTP Version Not Supported"));
	add_index_stringl(&_0, 506, SL("Variant Also Negotiates"));
	add_index_stringl(&_0, 507, SL("Insufficient Storage"));
	add_index_stringl(&_0, 508, SL("Loop Detected"));
	add_index_stringl(&_0, 510, SL("Not Extended"));
	add_index_stringl(&_0, 511, SL("Network Authentication Required"));
	zephir_update_static_property_ce(moon_component_http_message_response_ce, ZEND_STRL("phrase"), &_0);
	ZEPHIR_MM_RESTORE();

}

