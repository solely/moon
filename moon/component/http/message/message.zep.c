
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


/**
 * FileName: Message.php
 * User: solely
 * DateTime: 2018/10/24 13:31
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Message) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message, Message, moon, component_http_message_message, moon_component_http_message_message_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_message_ce, SL("headers"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_message_ce, SL("_headers"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_message_ce, SL("protocolVersion"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_message_ce, SL("body"), ZEND_ACC_PROTECTED);

	moon_component_http_message_message_ce->create_object = zephir_init_properties_Moon_Component_Http_Message_Message;

	zend_class_implements(moon_component_http_message_message_ce, 1, zephir_get_internal_ce(SL("psrext\\http\\message\\messageinterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Message, getHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, header, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_CALL_METHOD(&header, this_ptr, "getheaderline", NULL, 0, name);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&header))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, ",");
		zephir_fast_explode(return_value, &_0$$3, &header, LONG_MAX);
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_Message, getHeaderLine) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasheader", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3, this_ptr, ZEND_STRL("_headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_4);
		ZEPHIR_INIT_VAR(&_5);
		zephir_fast_strtolower(&_5, name);
		zephir_array_fetch(&_4, &_3, &_5, PH_NOISY, "moon/Component/Http/Message/Message.zep", 30);
		zephir_array_fetch(&_0, &_2, &_4, PH_NOISY, "moon/Component/Http/Message/Message.zep", 30);
	} else {
		ZVAL_STRING(&_0, "");
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(Moon_Component_Http_Message_Message, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

PHP_METHOD(Moon_Component_Http_Message_Message, hasHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validname", NULL, 1, name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, name);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * @param $name
 * @param $value
 * @return $this
 */
PHP_METHOD(Moon_Component_Http_Message_Message, setHeader) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validname", NULL, 1, name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, name);
	zephir_update_property_array(this_ptr, SL("_headers"), &_0, name);
	zephir_get_strval(&_1, value);
	zephir_update_property_array(this_ptr, SL("headers"), name, &_1);
	RETURN_THIS();

}

PHP_METHOD(Moon_Component_Http_Message_Message, withHeader) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, _new, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "validname", NULL, 1, name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, name);
	zephir_update_property_array(&_new, SL("_headers"), &_0, name);
	zephir_get_strval(&_1, value);
	zephir_update_property_array(&_new, SL("headers"), name, &_1);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Message, withAddedHeader) {

	zval _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, _0, _3$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasheader", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_get_strval(&_1$$3, value);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, ",", &_1$$3);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("_headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_4$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_fast_strtolower(&_5$$3, name);
		zephir_array_fetch(&_4$$3, &_3$$3, &_5$$3, PH_NOISY, "moon/Component/Http/Message/Message.zep", 70);
		zephir_update_property_array(this_ptr, SL("headers"), &_4$$3, &_2$$3);
		RETURN_THIS();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "withheader", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_Message, withoutHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasheader", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("_headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_fast_strtolower(&_4$$3, name);
		zephir_array_fetch(&_3$$3, &_2$$3, &_4$$3, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Message.zep", 79);
		zephir_array_unset(&_1$$3, &_3$$3, PH_SEPARATE);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("_headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_fast_strtolower(&_6$$3, name);
		zephir_array_unset(&_5$$3, &_6$$3, PH_SEPARATE);
	}
	RETURN_THIS();

}

PHP_METHOD(Moon_Component_Http_Message_Message, getProtocolVersion) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "protocolVersion");

}

PHP_METHOD(Moon_Component_Http_Message_Message, withProtocolVersion) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *version, version_sub, _new;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);
	ZVAL_UNDEF(&_new);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version);



	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_new, ZEND_STRL("protocolVersion"), version);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Message, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

PHP_METHOD(Moon_Component_Http_Message_Message, withBody) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *body, body_sub, _new;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body_sub);
	ZVAL_UNDEF(&_new);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &body);



	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_new, ZEND_STRL("body"), body);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Message, getStream) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval mode;
	zval *stream, stream_sub, *mode_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&mode);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &stream, &mode_param);

	zephir_get_strval(&mode, mode_param);


	if (zephir_is_instance_of(stream, SL("Psr\\Http\\Message\\StreamInterface"))) {
		RETVAL_ZVAL(stream, 1, 0);
		RETURN_MM();
	}
	_0 = !(Z_TYPE_P(stream) == IS_STRING);
	if (_0) {
		_0 = !(Z_TYPE_P(stream) == IS_RESOURCE);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(moon_component_http_message_exception_invalidargumentexception_ce, "The first parameter stream must be a string or resource or an implementation of Psr\\Http\\Message\\StreamInterface", "moon/Component/Http/Message/Message.zep", 117);
		return;
	}
	object_init_ex(return_value, moon_component_http_message_stream_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 2, stream, &mode);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_Message, setHeaders) {

	zval _6$$3, _8$$4;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, name, value, *_0, _1, _5$$3, _7$$4;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(&headers, headers_param);


	zephir_is_iterable(&headers, 0, "moon/Component/Http/Message/Message.zep", 131);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "validname", &_4, 1, &name);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_5$$3);
			zephir_fast_strtolower(&_5$$3, &name);
			zephir_update_property_array(this_ptr, SL("_headers"), &_5$$3, &name);
			zephir_get_strval(&_6$$3, &value);
			zephir_update_property_array(this_ptr, SL("headers"), &name, &_6$$3);
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
			ZEPHIR_CALL_METHOD(&name, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "validname", &_4, 1, &name);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$4);
				zephir_fast_strtolower(&_7$$4, &name);
				zephir_update_property_array(this_ptr, SL("_headers"), &_7$$4, &name);
				zephir_get_strval(&_8$$4, &value);
				zephir_update_property_array(this_ptr, SL("headers"), &name, &_8$$4);
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param $name
 * @throws InvalidArgumentException
 */
PHP_METHOD(Moon_Component_Http_Message_Message, validName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _0, _1, _2, _3, _4$$4, _5$$4, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	if (!(Z_TYPE_P(name) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(moon_component_http_message_exception_invalidargumentexception_ce, "Header name must be a string", "moon/Component/Http/Message/Message.zep", 140);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/^[a-zA-Z0-9'`#$%&*+.^_|~!-]+$/");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/^[a-zA-Z0-9'`#$%&*+.^_|~!-]+$/");
	zephir_preg_match(&_2, &_3, name, &_0, 0, 0 , 0 );
	if (!zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, moon_component_http_message_exception_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "\"%s\" is not valid header name");
		ZEPHIR_CALL_FUNCTION(&_6$$4, "sprintf", NULL, 3, &_5$$4, name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 4, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "moon/Component/Http/Message/Message.zep", 143);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Moon_Component_Http_Message_Message(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("_headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_headers"), &_1$$3);
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

