
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * FileName: Request.php
 * User: solely
 * DateTime: 2019/1/1 22:50
 * Description:  https://docs.laminas.dev/laminas-diactoros/v2/usage/
 *              用法根据编写的是HTTP客户端还是服务器端应用程序而异。
 *              出于HTTP客户端的目的，您将创建并填充一个Request实例，并且客户端应返回一个Response实例。
 *              对于服务器端应用程序，您将创建一个ServerRequest实例，并填充并返回一个 Response实例。 2020年6月27日16:00:46
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Request) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message, Request, moon, component_http_message_request, moon_component_http_message_message_ce, moon_component_http_message_request_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_request_ce, SL("uri"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(moon_component_http_message_request_ce, SL("method"), "get", ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_request_ce, SL("requestTarget"), ZEND_ACC_PRIVATE);

	zend_class_implements(moon_component_http_message_request_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\requestinterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Request, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval header;
	zval method;
	zval *uri = NULL, uri_sub, *method_param = NULL, *body = NULL, body_sub, *header_param = NULL, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&body_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&header);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &uri, &method_param, &body, &header_param);

	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}
	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "");
	} else {
		zephir_get_strval(&method, method_param);
	}
	if (!body) {
		body = &body_sub;
		ZEPHIR_INIT_VAR(body);
		ZVAL_STRING(body, "php://temp");
	}
	if (!header_param) {
		ZEPHIR_INIT_VAR(&header);
		array_init(&header);
	} else {
		zephir_get_arrval(&header, header_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seturi", NULL, 31, uri);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmethod", NULL, 32, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setbody", NULL, 33, body);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheaders", NULL, 0, &header);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sethost", NULL, 34);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Request, getRequestTarget) {

	zval target, _0, _1, _2, _3, _4$$4, _5$$4, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("requestTarget"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "requestTarget");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&target, &_1, "getpath", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getquery", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$4, &_4$$4, "getquery", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CONCAT_SV(&_6$$4, "?", &_5$$4);
		zephir_concat_self(&target, &_6$$4);
	}
	if (ZEPHIR_IS_EMPTY(&target)) {
		ZEPHIR_INIT_NVAR(&target);
		ZVAL_LONG(&target, '/');
	}
	RETURN_CCTOR(&target);

}

PHP_METHOD(Moon_Component_Http_Message_Request, withRequestTarget) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *requestTarget, requestTarget_sub, _new, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestTarget_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &requestTarget);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "#\\s#");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "#\\s#");
	zephir_preg_match(&_2, &_3, requestTarget, &_0, 0, 0 , 0 );
	if (zephir_is_true(&_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid request target provided; cannot contain whitespace", "moon/Component/Http/Message/Request.zep", 49);
		return;
	}
	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_new, ZEND_STRL("requestTarget"), requestTarget);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Request, getMethod) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "method");

}

PHP_METHOD(Moon_Component_Http_Message_Request, withMethod) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, _new;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_new);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method);



	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, &_new, "setmethod", NULL, 0, method);
	zephir_check_call_status();
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Request, getUri) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "uri");

}

PHP_METHOD(Moon_Component_Http_Message_Request, withUri) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri, uri_sub, *preserveHost = NULL, preserveHost_sub, __$false, host, _new, _1, _2, _3, _4, _7, _8, _5$$5, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&preserveHost_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri, &preserveHost);

	if (!preserveHost) {
		preserveHost = &preserveHost_sub;
		preserveHost = &__$false;
	}


	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_new, ZEND_STRL("uri"), uri);
	_0 = zephir_is_true(preserveHost);
	if (_0) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "Host");
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasheader", NULL, 0, &_2);
		zephir_check_call_status();
		_0 = zephir_is_true(&_1);
	}
	if (_0) {
		RETURN_CCTOR(&_new);
	}
	ZEPHIR_CALL_METHOD(&_3, uri, "gethost", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&_3)) {
		RETURN_CCTOR(&_new);
	}
	ZEPHIR_CALL_METHOD(&host, uri, "gethost", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, uri, "getport", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_CALL_METHOD(&_5$$5, uri, "getport", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$5);
		ZEPHIR_CONCAT_SV(&_6$$5, ":", &_5$$5);
		zephir_concat_self(&host, &_6$$5);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "host");
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "Host");
	zephir_update_property_array(&_new, SL("_headers"), &_2, &_7);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "Host");
	zephir_update_property_array(&_new, SL("headers"), &_8, &host);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Request, setUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, uri_sub, __$null, _0$$3, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}


	if (Z_TYPE_P(uri) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, moon_component_http_message_uri_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", &_1, 35);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("uri"), &_0$$3);
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(uri) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, moon_component_http_message_uri_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", &_1, 35, uri);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("uri"), &_2$$4);
		RETURN_MM_NULL();
	}
	if (zephir_is_instance_of(uri, SL("Psr\\Http\\Message\\UriInterface"))) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("uri"), uri);
		RETURN_MM_NULL();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Unsupported URI parameter", "moon/Component/Http/Message/Request.zep", 109);
	return;

}

PHP_METHOD(Moon_Component_Http_Message_Request, setMethod) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method, *method_param = NULL, _0$$3, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &method_param);

	if (!method_param) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "");
	} else {
		zephir_get_strval(&method, method_param);
	}


	if (Z_TYPE_P(&method) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "/^[!#$%&'*+.^_`\\|~0-9a-z-]+$/i");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "/^[!#$%&'*+.^_`\\|~0-9a-z-]+$/i");
		zephir_preg_match(&_2$$3, &_3$$3, &method, &_0$$3, 0, 0 , 0 );
		if (!zephir_is_true(&_2$$3)) {
			ZEPHIR_INIT_VAR(&_4$$4);
			object_init_ex(&_4$$4, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "Unsupported HTTP %s method");
			ZEPHIR_CALL_FUNCTION(&_6$$4, "sprintf", NULL, 3, &_5$$4, &method);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 25, &_6$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$4, "moon/Component/Http/Message/Request.zep", 117);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("method"), &method);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Request, setBody) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *body, body_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "wb+");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getstream", NULL, 0, body, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("body"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Request, setHost) {

	zend_bool _2;
	zval _0, _1, _3, _4, _5$$3, _6$$3, _7$$3, _8$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Host");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasheader", NULL, 0, &_1);
	zephir_check_call_status();
	_2 = !zephir_is_true(&_0);
	if (_2) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4, &_3, "gethost", NULL, 0);
		zephir_check_call_status();
		_2 = zephir_is_true(&_4);
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "host");
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "Host");
		zephir_update_property_array(this_ptr, SL("_headers"), &_5$$3, &_6$$3);
		ZEPHIR_CALL_METHOD(&_7$$3, this_ptr, "gethostfromuri", NULL, 36);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "Host");
		zephir_update_property_array(this_ptr, SL("headers"), &_8$$3, &_7$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Request, getHostFromUri) {

	zval host, _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&host, &_0, "gethost", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getport", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5, &_4, "getport", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1);
		ZEPHIR_CONCAT_SV(&_1, ":", &_5);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "");
	}
	zephir_concat_self(&host, &_1);
	RETURN_CCTOR(&host);

}

