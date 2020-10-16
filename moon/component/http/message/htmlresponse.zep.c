
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
#include "kernel/exception.h"


/**
 * FileName: HtmlResponse.php
 * User: solely
 * DateTime: 2020/9/30 20:00
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_HtmlResponse) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message, HtmlResponse, moon, component_http_message_htmlresponse, moon_component_http_message_response_ce, moon_component_http_message_htmlresponse_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_HtmlResponse, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *html, html_sub, *statusCode = NULL, statusCode_sub, *headers = NULL, headers_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&html_sub);
	ZVAL_UNDEF(&statusCode_sub);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &html, &statusCode, &headers);

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


	ZEPHIR_CALL_METHOD(&_1, this_ptr, "createstream", NULL, 191, html);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_htmlresponse_ce, getThis(), "__construct", &_0, 0, &_1, statusCode, headers);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_HtmlResponse, createStream) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *html, html_sub, body, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&html_sub);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &html);



	if (zephir_is_instance_of(html, SL("Psr\\Http\\Message\\StreamInterface"))) {
		RETVAL_ZVAL(html, 1, 0);
		RETURN_MM();
	}
	if (!(Z_TYPE_P(html) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(moon_component_http_message_exception_invalidargumentexception_ce, "Invalid content", "moon/Component/Http/Message/HtmlResponse.zep", 25);
		return;
	}
	ZEPHIR_INIT_VAR(&body);
	object_init_ex(&body, moon_component_http_message_stream_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://temp");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "wb+");
	ZEPHIR_CALL_METHOD(NULL, &body, "__construct", NULL, 2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &body, "write", NULL, 192, html);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &body, "rewind", NULL, 193);
	zephir_check_call_status();
	RETURN_CCTOR(&body);

}

