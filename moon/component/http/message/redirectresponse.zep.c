
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * FileName: RedirectResponse.php
 * User: solely
 * DateTime: 2020/8/29 23:47
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_RedirectResponse) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message, RedirectResponse, moon, component_http_message_redirectresponse, moon_component_http_message_response_ce, moon_component_http_message_redirectresponse_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_redirectresponse_ce, SL("targetUrl"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_RedirectResponse, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zval headers, _3;
	zend_long statusCode, ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *statusCode_param = NULL, *headers_param = NULL, data, _1, _2, _4, _5;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &url_param, &statusCode_param, &headers_param);

	zephir_get_strval(&url, url_param);
	if (!statusCode_param) {
		statusCode = 302;
	} else {
		statusCode = zephir_get_intval(statusCode_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	ZEPHIR_CALL_METHOD(&data, this_ptr, "settargeturl", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "createstream", NULL, 198, &data);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	ZEPHIR_OBS_VAR(&_4);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("targetUrl"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("Location"), &_4, PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(&_2, &headers, &_3);
	ZVAL_LONG(&_5, statusCode);
	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_redirectresponse_ce, getThis(), "__construct", &_0, 0, &_1, &_5, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_RedirectResponse, setTargetUrl) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, _0, _1, _2, _3;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(&url, url_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (ZEPHIR_IS_IDENTICAL(&_0, &url)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Cannot redirect to an empty URL.", "moon/Component/Http/Message/RedirectResponse.zep", 35);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("targetUrl"), &url);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "UTF-8");
	ZEPHIR_CALL_FUNCTION(&_3, "htmlspecialchars", NULL, 167, &url, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "<!DOCTYPE html>\n<html>\n    <head>\n        <meta charset=\"UTF-8\" />\n        <meta http-equiv=\"refresh\" content=\"0;url='%1$s'\" />\n\n        <title>Redirecting to %1$s</title>\n    </head>\n    <body>\n        Redirecting to <a href=\"%1$s\">%1$s</a>.\n    </body>\n</html>");
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 3, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the target URL.
 *
 * @return string target URL
 */
PHP_METHOD(Moon_Component_Http_Message_RedirectResponse, getTargetUrl) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "targetUrl");

}

PHP_METHOD(Moon_Component_Http_Message_RedirectResponse, createStream) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, stream, _0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&stream);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(&data, data_param);


	ZEPHIR_INIT_VAR(&stream);
	object_init_ex(&stream, moon_component_http_message_stream_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://temp");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "wb+");
	ZEPHIR_CALL_METHOD(NULL, &stream, "__construct", NULL, 2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &stream, "write", NULL, 192, &data);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &stream, "rewind", NULL, 193);
	zephir_check_call_status();
	RETURN_CCTOR(&stream);

}
