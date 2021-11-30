
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * FileName: ServerRequest.php
 * User: solely
 * DateTime: 2019/1/13 18:21
 * Description:  对于服务器端应用程序，您将创建一个ServerRequest实例，并填充并返回一个 Response实例。
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_ServerRequest) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message, ServerRequest, moon, component_http_message_serverrequest, moon_component_http_message_request_ce, moon_component_http_message_serverrequest_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_serverrequest_ce, SL("serverParams"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_serverrequest_ce, SL("cookieParams"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_serverrequest_ce, SL("queryParams"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_serverrequest_ce, SL("uploadedFiles"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_serverrequest_ce, SL("parseBody"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_serverrequest_ce, SL("attributes"), ZEND_ACC_PRIVATE);

	moon_component_http_message_serverrequest_ce->create_object = zephir_init_properties_Moon_Component_Http_Message_ServerRequest;

	zend_class_implements(moon_component_http_message_serverrequest_ce, 1, zephir_get_internal_ce(SL("psrext\\http\\message\\serverrequestinterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval header;
	zval *serverParams, serverParams_sub, *cookieParams, cookieParams_sub, *queryParams, queryParams_sub, *parseBody, parseBody_sub, *uploadedFiles, uploadedFiles_sub, *attributes = NULL, attributes_sub, *protocolVersion = NULL, protocolVersion_sub, *uri = NULL, uri_sub, *method = NULL, method_sub, *body = NULL, body_sub, *header_param = NULL, __$null, _0, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serverParams_sub);
	ZVAL_UNDEF(&cookieParams_sub);
	ZVAL_UNDEF(&queryParams_sub);
	ZVAL_UNDEF(&parseBody_sub);
	ZVAL_UNDEF(&uploadedFiles_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_UNDEF(&protocolVersion_sub);
	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&body_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&header);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 6, &serverParams, &cookieParams, &queryParams, &parseBody, &uploadedFiles, &attributes, &protocolVersion, &uri, &method, &body, &header_param);

	if (!attributes) {
		attributes = &attributes_sub;
		ZEPHIR_INIT_VAR(attributes);
		array_init(attributes);
	}
	if (!protocolVersion) {
		protocolVersion = &protocolVersion_sub;
		ZEPHIR_INIT_VAR(protocolVersion);
		ZVAL_STRING(protocolVersion, "1.1");
	}
	if (!uri) {
		uri = &uri_sub;
		ZEPHIR_CPY_WRT(uri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}
	if (!method) {
		method = &method_sub;
		ZEPHIR_CPY_WRT(method, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(method);
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


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_http_message_serverbag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", &_1, 37, serverParams);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("serverParams"), &_0);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, moon_component_http_message_parameterbag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_1, 37, cookieParams);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("cookieParams"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, moon_component_http_message_parameterbag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", &_1, 37, queryParams);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("queryParams"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, moon_component_http_message_parameterbag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", &_1, 37, parseBody);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("parseBody"), &_4);
	ZEPHIR_INIT_VAR(&_5);
	object_init_ex(&_5, moon_component_http_message_filebag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 38, uploadedFiles);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("uploadedFiles"), &_5);
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, moon_component_http_message_parameterbag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", &_1, 37, attributes);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &_6);
	zephir_update_property_zval(this_ptr, ZEND_STRL("protocolVersion"), protocolVersion);
	ZEPHIR_INIT_VAR(&_7);
	if (!(ZEPHIR_IS_EMPTY(uri))) {
		ZEPHIR_CPY_WRT(&_7, uri);
	} else {
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "getfullrequesturl", NULL, 39);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(uri, &_7);
	ZEPHIR_INIT_NVAR(&_7);
	if (!(ZEPHIR_IS_EMPTY(method))) {
		ZEPHIR_CPY_WRT(&_7, method);
	} else {
		zephir_read_property(&_8, this_ptr, ZEND_STRL("serverParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_9);
		ZVAL_STRING(&_9, "REQUEST_METHOD");
		ZEPHIR_INIT_VAR(&_10);
		ZVAL_STRING(&_10, "GET");
		ZEPHIR_CALL_METHOD(&_7, &_8, "get", NULL, 0, &_9, &_10);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(method, &_7);
	ZEPHIR_INIT_NVAR(&_7);
	if (!(ZEPHIR_IS_EMPTY(&header))) {
		ZEPHIR_CPY_WRT(&_7, &header);
	} else {
		zephir_read_property(&_11, this_ptr, ZEND_STRL("serverParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7, &_11, "getheaders", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(&header, &_7);
	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_serverrequest_ce, getThis(), "__construct", &_12, 0, uri, method, body, &header);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getFullRequestUrl) {

	zval url, _0, _1, _2, _3, _4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _11$$4, _12$$4, _13$$4, _14$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&url);
	ZVAL_STRING(&url, "http://");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("serverParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "HTTPS");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&_1, "on")) {
		ZEPHIR_INIT_NVAR(&url);
		ZVAL_STRING(&url, "https://");
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("serverParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "SERVER_PORT");
	ZEPHIR_CALL_METHOD(&_4, &_3, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&_4, "80")) {
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("serverParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "SERVER_NAME");
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "");
		ZEPHIR_CALL_METHOD(&_6$$4, &_5$$4, "get", NULL, 0, &_7$$4, &_8$$4);
		zephir_check_call_status();
		zephir_read_property(&_9$$4, this_ptr, ZEND_STRL("serverParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "SERVER_PORT");
		ZEPHIR_CALL_METHOD(&_10$$4, &_9$$4, "get", NULL, 0, &_7$$4);
		zephir_check_call_status();
		zephir_read_property(&_11$$4, this_ptr, ZEND_STRL("serverParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "REQUEST_URI");
		ZEPHIR_CALL_METHOD(&_12$$4, &_11$$4, "get", NULL, 0, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$4);
		ZEPHIR_CONCAT_VSVSV(&_13$$4, &_6$$4, ":", &_10$$4, ":", &_12$$4);
		zephir_concat_self(&url, &_13$$4);
	} else {
		zephir_read_property(&_14$$5, this_ptr, ZEND_STRL("serverParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_16$$5);
		ZVAL_STRING(&_16$$5, "SERVER_NAME");
		ZEPHIR_INIT_VAR(&_17$$5);
		ZVAL_STRING(&_17$$5, "");
		ZEPHIR_CALL_METHOD(&_15$$5, &_14$$5, "get", NULL, 0, &_16$$5, &_17$$5);
		zephir_check_call_status();
		zephir_read_property(&_18$$5, this_ptr, ZEND_STRL("serverParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_16$$5);
		ZVAL_STRING(&_16$$5, "REQUEST_URI");
		ZEPHIR_CALL_METHOD(&_19$$5, &_18$$5, "get", NULL, 0, &_16$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_20$$5);
		ZEPHIR_CONCAT_VSV(&_20$$5, &_15$$5, ":", &_19$$5);
		zephir_concat_self(&url, &_20$$5);
	}
	RETURN_CCTOR(&url);

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getServerParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "serverParams");

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getCookieParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cookieParams");

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withCookieParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cookies_param = NULL, _new, _0;
	zval cookies;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cookies_param);

	zephir_get_arrval(&cookies, cookies_param);


	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &_new, ZEND_STRL("cookieParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "replace", NULL, 0, &cookies);
	zephir_check_call_status();
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getQueryParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "queryParams");

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withQueryParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, _new, _0;
	zval query;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);

	zephir_get_arrval(&query, query_param);


	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &_new, ZEND_STRL("queryParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "replace", NULL, 0, &query);
	zephir_check_call_status();
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getUploadedFiles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "uploadedFiles");

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withUploadedFiles) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uploadedFiles_param = NULL, _new, _0;
	zval uploadedFiles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uploadedFiles);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uploadedFiles_param);

	zephir_get_arrval(&uploadedFiles, uploadedFiles_param);


	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &_new, ZEND_STRL("uploadedFiles"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "replace", NULL, 0, &uploadedFiles);
	zephir_check_call_status();
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getParsedBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "parseBody");

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withParsedBody) {

	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, _new, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	_0 = Z_TYPE_P(data) != IS_NULL;
	if (_0) {
		_0 = !(Z_TYPE_P(data) == IS_ARRAY);
	}
	_1 = _0;
	if (_1) {
		_1 = !(Z_TYPE_P(data) == IS_OBJECT);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Arguments must be either null, array, or object", "moon/Component/Http/Message/ServerRequest.zep", 112);
		return;
	}
	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_2, &_new, ZEND_STRL("parseBody"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "replace", NULL, 0, data);
	zephir_check_call_status();
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "attributes");

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, getAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *_default = NULL, _default_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &_default);

	if (!_default) {
		_default = &_default_sub;
		_default = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, name, _default);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, _new, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &_new, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, withoutAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _new, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &_new, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "replace", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, validateUploadedFiles) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uploadedFiles_param = NULL, file, *_0, _1;
	zval uploadedFiles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uploadedFiles);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uploadedFiles_param);

	zephir_get_arrval(&uploadedFiles, uploadedFiles_param);


	zephir_is_iterable(&uploadedFiles, 0, "moon/Component/Http/Message/ServerRequest.zep", 156);
	if (Z_TYPE_P(&uploadedFiles) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&uploadedFiles), _0)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			if (Z_TYPE_P(&file) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "validateuploadedfiles", &_2, 40, &file);
				zephir_check_call_status();
			}
			if (!((zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface"))))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "UploadedFile must be an implementation of Psr\\Http\\Message\\UploadedFileInterface", "moon/Component/Http/Message/ServerRequest.zep", 153);
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &uploadedFiles, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &uploadedFiles, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &uploadedFiles, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&file) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "validateuploadedfiles", &_2, 40, &file);
					zephir_check_call_status();
				}
				if (!((zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface"))))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "UploadedFile must be an implementation of Psr\\Http\\Message\\UploadedFileInterface", "moon/Component/Http/Message/ServerRequest.zep", 153);
					return;
				}
			ZEPHIR_CALL_METHOD(NULL, &uploadedFiles, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets a "parameter" value from any bag.
 *
 * This method is mainly useful for libraries that want to provide some flexibility. If you don't need the
 * flexibility in controllers, it is better to explicitly get request parameters from the appropriate
 * public property instead (attributes, query, request).
 *
 * Order of precedence: PATH (routing placeholders or custom attributes), GET, BODY
 *
 * @param string $key
 * @param mixed|null $default The default value if the parameter key does not exist
 *
 * @return mixed|null
 */
PHP_METHOD(Moon_Component_Http_Message_ServerRequest, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_default = NULL, _default_sub, __$null, result, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &_default);

	zephir_get_strval(&key, key_param);
	if (!_default) {
		_default = &_default_sub;
		_default = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "get", NULL, 0, &key, this_ptr);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(this_ptr, &result)) {
		RETURN_CCTOR(&result);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("queryParams"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_1, "get", NULL, 0, &key, this_ptr);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(this_ptr, &result)) {
		RETURN_CCTOR(&result);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("parseBody"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_2, "get", NULL, 0, &key, this_ptr);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(this_ptr, &result)) {
		RETURN_CCTOR(&result);
	}
	RETVAL_ZVAL(_default, 1, 0);
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_ServerRequest, create) {

	zval _11;
	zend_bool _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, _COOKIE, _GET, _POST, _FILES, request, data, _0, _1, _2, _3, _4, _5, _7, _8, _9, _10, _12$$3, _13$$3, _14$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_11);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_INIT_VAR(&request);
	object_init_ex(&request, moon_component_http_message_serverrequest_ce);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "1.1");
	ZVAL_NULL(&_2);
	ZVAL_NULL(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "php://input");
	ZEPHIR_CALL_METHOD(NULL, &request, "__construct", NULL, 41, &_SERVER, &_COOKIE, &_GET, &_POST, &_FILES, &_0, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "CONTENT_TYPE");
	ZEPHIR_CALL_METHOD(&_5, &request, "getheaderline", NULL, 42, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "application/x-www-form-urlencoded");
	ZEPHIR_INIT_NVAR(&_4);
	zephir_fast_strpos(&_4, &_5, &_1, 0 );
	_6 = ZEPHIR_IS_LONG_IDENTICAL(&_4, 0);
	if (_6) {
		ZEPHIR_INIT_VAR(&_7);
		zephir_read_property(&_2, &request, ZEND_STRL("serverParams"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_9);
		ZVAL_STRING(&_9, "REQUEST_METHOD");
		ZEPHIR_INIT_VAR(&_10);
		ZVAL_STRING(&_10, "GET");
		ZEPHIR_CALL_METHOD(&_8, &_2, "get", NULL, 0, &_9, &_10);
		zephir_check_call_status();
		zephir_fast_strtoupper(&_7, &_8);
		ZEPHIR_INIT_VAR(&_11);
		zephir_create_array(&_11, 3, 0);
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_STRING(&_9, "PUT");
		zephir_array_fast_append(&_11, &_9);
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_STRING(&_9, "DELETE");
		zephir_array_fast_append(&_11, &_9);
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_STRING(&_9, "PATCH");
		zephir_array_fast_append(&_11, &_9);
		_6 = zephir_fast_in_array(&_7, &_11);
	}
	if (_6) {
		ZEPHIR_CALL_METHOD(&_12$$3, &request, "getbody", NULL, 43);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13$$3, &_12$$3, "getcontents", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&data);
		ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 44, &_13$$3, &data);
		ZEPHIR_UNREF(&data);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_14$$3);
		object_init_ex(&_14$$3, moon_component_http_message_parameterbag_ce);
		ZEPHIR_CALL_METHOD(NULL, &_14$$3, "__construct", NULL, 37, &data);
		zephir_check_call_status();
		zephir_update_property_zval(&request, ZEND_STRL("parseBody"), &_14$$3);
	}
	RETURN_CCTOR(&request);

}

zend_object *zephir_init_properties_Moon_Component_Http_Message_ServerRequest(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("uploadedFiles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("uploadedFiles"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

