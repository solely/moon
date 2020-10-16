
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "ext/spl/spl_array.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * FileName: JsonResponse.php
 * User: solely
 * DateTime: 2020/8/30 19:08
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_JsonResponse) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message, JsonResponse, moon, component_http_message_jsonresponse, moon_component_http_message_response_ce, moon_component_http_message_jsonresponse_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_jsonresponse_ce, SL("data"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_jsonresponse_ce, SL("callback"), ZEND_ACC_PROTECTED);

	zend_declare_property_long(moon_component_http_message_jsonresponse_ce, SL("encodingOptions"), 15, ZEND_ACC_PROTECTED);

	zephir_declare_class_constant_long(moon_component_http_message_jsonresponse_ce, SL("DEFAULT_ENCODING_OPTIONS"), 15);

	return SUCCESS;

}

/**
 * JsonResponse constructor.
 * @param mixed $data The response data
 * @param int $statusCode The response status code
 * @param array $headers An array of response headers
 * @param bool $json If the data is already a JSON string
 * @throws \Exception
 */
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_bool json, _0;
	zval headers;
	zend_long statusCode, ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *statusCode_param = NULL, *headers_param = NULL, *json_param = NULL, __$null, _6, _7, _1$$4, _2$$4, _3$$5, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &data, &statusCode_param, &headers_param, &json_param);

	if (!data) {
		data = &data_sub;
		ZEPHIR_CPY_WRT(data, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}
	if (!statusCode_param) {
		statusCode = 200;
	} else {
		statusCode = zephir_get_intval(statusCode_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}
	if (!json_param) {
		json = 0;
	} else {
		json = zephir_get_boolval(json_param);
	}


	if (Z_TYPE_P(data) == IS_NULL) {
		ZEPHIR_INIT_NVAR(data);
		object_init_ex(data, spl_ce_ArrayObject);
		ZEPHIR_CALL_METHOD(NULL, data, "__construct", NULL, 194);
		zephir_check_call_status();
	}
	_0 = json;
	if (_0) {
		_0 = Z_TYPE_P(data) == IS_STRING;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "setjson", NULL, 0, data);
		zephir_check_call_status();
		zephir_fast_array_merge(&_1$$4, &headers, &_2$$4);
		ZEPHIR_CPY_WRT(&headers, &_1$$4);
	} else {
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "setdata", NULL, 0, data);
		zephir_check_call_status();
		zephir_fast_array_merge(&_3$$5, &headers, &_4$$5);
		ZEPHIR_CPY_WRT(&headers, &_3$$5);
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "createstream", NULL, 195);
	zephir_check_call_status();
	ZVAL_LONG(&_7, statusCode);
	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_jsonresponse_ce, getThis(), "__construct", &_5, 0, &_6, &_7, &headers);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a raw string containing a JSON document to be sent.
 * @param string $json
 * @return array
 */
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, setJson) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *json_param = NULL;
	zval json;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&json);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &json_param);

	zephir_get_strval(&json, json_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &json);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "update", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Updates the content and headers according to the JSON data and callback.
 *
 * @return array
 */
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, update) {

	zend_bool _7;
	zval _0, _5, _6, _8, _9, _1$$3, _2$$3, _3$$3, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "/**/%s(%s);");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 3, &_3$$3, &_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_4$$3);
		zephir_create_array(return_value, 1, 0);
		add_assoc_stringl_ex(return_value, SL("Content-Type"), SL("text/javascript"));
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "Content-Type");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "hasheader", NULL, 0, &_6);
	zephir_check_call_status();
	_7 = !zephir_is_true(&_5);
	if (!(_7)) {
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_STRING(&_6, "Content-Type");
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "getheaderline", NULL, 0, &_6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9);
		ZVAL_STRING(&_9, "text/javascript");
		_7 = ZEPHIR_IS_IDENTICAL(&_9, &_8);
	}
	if (_7) {
		zephir_create_array(return_value, 1, 0);
		add_assoc_stringl_ex(return_value, SL("Content-Type"), SL("application/json"));
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Sets the data to be sent as JSON.
 * @param mixed $data
 * @return array
 * @throws \Exception
 */
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, setData) {

	zend_bool _12, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, e, _2, eo, _11, _14, _0$$3, _1$$3, _3$$4, _4$$4, _6$$4, _7$$4, _8$$4, _9$$5, _10$$5, _15$$9, _16$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&eo);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}



	/* try_start_1: */

		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("encodingOptions"), PH_NOISY_CC | PH_READONLY);
		zephir_json_encode(&_0$$3, data, zephir_get_intval(&_1$$3) );
		ZEPHIR_CPY_WRT(data, &_0$$3);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_OBJ(&_2, EG(exception));
		Z_ADDREF_P(&_2);
		if (zephir_instance_of_ev(&_2, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_2);
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_get_class(&_3$$4, &e, 0);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "Exception");
			_5$$4 = ZEPHIR_IS_IDENTICAL(&_4$$4, &_3$$4);
			if (_5$$4) {
				ZEPHIR_CALL_METHOD(&_6$$4, &e, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_7$$4);
				ZVAL_STRING(&_7$$4, "Failed calling ");
				ZEPHIR_INIT_VAR(&_8$$4);
				zephir_fast_strpos(&_8$$4, &_6$$4, &_7$$4, 0 );
				_5$$4 = ZEPHIR_IS_LONG_IDENTICAL(&_8$$4, 0);
			}
			if (_5$$4) {
				ZEPHIR_INIT_VAR(&_9$$5);
				ZEPHIR_CALL_METHOD(&_10$$5, &e, "getprevious", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_10$$5))) {
					ZEPHIR_CPY_WRT(&_9$$5, &e);
				} else {
					ZEPHIR_CALL_METHOD(&_9$$5, &e, "getprevious", NULL, 0);
					zephir_check_call_status();
				}
				zephir_throw_exception_debug(&_9$$5, "moon/Component/Http/Message/JsonResponse.zep", 82);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_throw_exception_debug(&e, "moon/Component/Http/Message/JsonResponse.zep", 84);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_OBS_VAR(&eo);
	zephir_read_property(&eo, this_ptr, ZEND_STRL("encodingOptions"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_GET_CONSTANT(&_11, "PHP_VERSION_ID");
	_12 = ZEPHIR_GE_LONG(&_11, 70300);
	if (_12) {
		_12 = (((4194304 & zephir_get_intval(&eo))) ? 1 : 0);
	}
	if (_12) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setjson", &_13, 0, data);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_14, "json_last_error", NULL, 196);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_14, 0)) {
		ZEPHIR_INIT_VAR(&_15$$9);
		object_init_ex(&_15$$9, spl_ce_InvalidArgumentException);
		ZEPHIR_CALL_FUNCTION(&_16$$9, "json_last_error_msg", NULL, 197);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_15$$9, "__construct", NULL, 33, &_16$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_15$$9, "moon/Component/Http/Message/JsonResponse.zep", 93);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setjson", &_13, 0, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns options used while encoding data to JSON.
 *
 * @return int
 */
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, getEncodingOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "encodingOptions");

}

/**
 * Sets options used while encoding data to JSON.
 * @param int $encodingOptions
 * @return JsonResponse
 * @throws \Exception
 */
PHP_METHOD(Moon_Component_Http_Message_JsonResponse, setEncodingOptions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *encodingOptions_param = NULL, _new, _0, _1, _2;
	zend_long encodingOptions, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encodingOptions_param);

	encodingOptions = zephir_get_intval(encodingOptions_param);


	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, encodingOptions);
	zephir_update_property_zval(&_new, ZEND_STRL("encodingOptions"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_0, &_new, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_json_decode(&_1, &_0, 0 );
	ZEPHIR_CALL_METHOD(NULL, &_new, "setdata", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_new, "createstream", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_new, "withbody", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_JsonResponse, createStream) {

	zval stream, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&stream);
	object_init_ex(&stream, moon_component_http_message_stream_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://temp");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "wb+");
	ZEPHIR_CALL_METHOD(NULL, &stream, "__construct", NULL, 2, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &stream, "write", NULL, 192, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &stream, "rewind", NULL, 193);
	zephir_check_call_status();
	RETURN_CCTOR(&stream);

}

