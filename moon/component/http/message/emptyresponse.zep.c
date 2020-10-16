
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


/**
 * FileName: EmptyResponse.php
 * User: solely
 * DateTime: 2020/9/30 22:16
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_EmptyResponse) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message, EmptyResponse, moon, component_http_message_emptyresponse, moon_component_http_message_response_ce, moon_component_http_message_emptyresponse_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_EmptyResponse, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *statusCode = NULL, statusCode_sub, *headers = NULL, headers_sub, content, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&statusCode_sub);
	ZVAL_UNDEF(&headers_sub);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &statusCode, &headers);

	if (!statusCode) {
		statusCode = &statusCode_sub;
		ZEPHIR_INIT_VAR(statusCode);
		ZVAL_LONG(statusCode, 204);
	}
	if (!headers) {
		headers = &headers_sub;
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	}


	ZEPHIR_INIT_VAR(&content);
	object_init_ex(&content, moon_component_http_message_stream_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://temp");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "r");
	ZEPHIR_CALL_METHOD(NULL, &content, "__construct", NULL, 2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_emptyresponse_ce, getThis(), "__construct", &_2, 0, &content, statusCode, headers);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

