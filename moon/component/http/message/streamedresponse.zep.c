
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * FileName: StreamedResponse.php
 * User: solely
 * DateTime: 2020/9/6 22:16
 * Description:
 */
/**
 * Class StreamedResponse
 * @package Moon\Component\Http\Message
 *
 * The callback should use the standard PHP functions like echo
 * to stream the response back to the client. The flush() function
 * can also be used if needed.
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_StreamedResponse) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message, StreamedResponse, moon, component_http_message_streamedresponse, moon_component_http_message_response_ce, moon_component_http_message_streamedresponse_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_streamedresponse_ce, SL("callback"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_streamedresponse_ce, SL("streamed"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_streamedresponse_ce, SL("headersSent"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *callback = NULL, callback_sub, *statusCode = NULL, statusCode_sub, *headers = NULL, headers_sub, __$true, __$false, __$null, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&statusCode_sub);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &callback, &statusCode, &headers);

	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
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
	ZVAL_STRING(&_1, "php://memory");
	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_streamedresponse_ce, getThis(), "__construct", &_0, 0, &_1, statusCode, headers);
	zephir_check_call_status();
	if (zephir_is_callable(callback) == 1) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcallback", NULL, 0, callback);
		zephir_check_call_status();
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("streamed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("streamed"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("headersSent"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("headersSent"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the PHP callback associated with this Response.
 *
 * @param callable $callback
 * @return $this
 */
PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, setCallback) {

	zval *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &callback);



	zephir_update_property_zval(this_ptr, ZEND_STRL("callback"), callback);
	RETURN_THISW();

}

/**
 * {@inheritdoc}
 *
 * This method only sends the headers once.
 *
 * @return $this
 */
PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, sendHeaders) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval __$true, __$false, _0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("headersSent"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("headersSent"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("headersSent"), &__$false);
	}
	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_streamedresponse_ce, getThis(), "sendheaders", &_1, 0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * {@inheritdoc}
 *
 * This method only sends the content once.
 *
 * @return $this
 */
PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, sendContent) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false, _0, _1, call;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&call);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("streamed"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("streamed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("streamed"), &__$false);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_1) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_LogicException, "The Response callback must not be null.", "moon/Component/Http/Message/StreamedResponse.zep", 75);
		return;
	}
	ZEPHIR_OBS_VAR(&call);
	zephir_read_property(&call, this_ptr, ZEND_STRL("callback"), PH_NOISY_CC);
	ZEPHIR_CALL_ZVAL_FUNCTION(NULL, &call, NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * {@inheritdoc}
 *
 * @throws \LogicException when the content is not null
 *
 * @return $this
 */
PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, setContent) {

	zval *content, content_sub, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &content);



	if (Z_TYPE_P(content) != IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_LogicException, "The content cannot be set on a StreamedResponse instance.", "moon/Component/Http/Message/StreamedResponse.zep", 93);
		return;
	}
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("streamed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("streamed"), &__$false);
	}
	RETURN_THISW();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_StreamedResponse, getContent) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

}

