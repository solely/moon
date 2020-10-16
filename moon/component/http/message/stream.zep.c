
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
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * FileName: Stream.php
 * User: solely
 * DateTime: 2018/12/2 21:51
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Stream) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message, Stream, moon, component_http_message_stream, moon_component_http_message_stream_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_stream_ce, SL("_resource"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_stream_ce, SL("stream"), ZEND_ACC_PROTECTED);

	zend_class_implements(moon_component_http_message_stream_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\streaminterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Stream, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *mode = NULL, mode_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&mode_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &stream, &mode);

	if (!mode) {
		mode = &mode_sub;
		ZEPHIR_INIT_VAR(mode);
		ZVAL_STRING(mode, "rb");
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstream", NULL, 0, stream, mode);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param mixed $resource
 */
PHP_METHOD(Moon_Component_Http_Message_Stream, setResource) {

	zval *_resource, _resource_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_resource_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &_resource);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_resource"), _resource);

}

/**
 * @return mixed
 */
PHP_METHOD(Moon_Component_Http_Message_Stream, getResource) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_resource");

}

PHP_METHOD(Moon_Component_Http_Message_Stream, setStream) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval mode;
	zval *stream, stream_sub, *mode_param = NULL, _resource, error, _2, _3, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&_resource);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&mode);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &stream, &mode_param);

	if (!mode_param) {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_STRING(&mode, "rb");
	} else {
		zephir_get_strval(&mode, mode_param);
	}


	ZEPHIR_CPY_WRT(&_resource, stream);
	if (Z_TYPE_P(stream) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_NVAR(&_0$$3);
		zephir_create_closure_ex(&_0$$3, NULL, moon_7__closure_ce, SL("__invoke"));
		zephir_update_static_property_ce(moon_7__closure_ce, ZEND_STRL("error"), &error);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 159, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_resource, "fopen", NULL, 140, stream, &mode);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 163);
		zephir_check_call_status();
	}
	if (zephir_is_true(&error)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(moon_component_http_message_exception_invalidargumentexception_ce, "Invalid stream reference provided", "moon/Component/Http/Message/Stream.zep", 55);
		return;
	}
	_1 = !(Z_TYPE_P(&_resource) == IS_RESOURCE);
	if (!(_1)) {
		ZEPHIR_CALL_FUNCTION(&_2, "get_resource_type", NULL, 121, &_resource);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "stream");
		_1 = !ZEPHIR_IS_IDENTICAL(&_3, &_2);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(moon_component_http_message_exception_invalidargumentexception_ce, "Invalid stream provided; must be a string stream identifier or stream resource", "moon/Component/Http/Message/Stream.zep", 58);
		return;
	}
	if (!ZEPHIR_IS_IDENTICAL(stream, &_resource)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("stream"), stream);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("_resource"), &_resource);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return mixed
 */
PHP_METHOD(Moon_Component_Http_Message_Stream, getStream) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "stream");

}

PHP_METHOD(Moon_Component_Http_Message_Stream, __toString) {

	zval _0, throwable, _2, _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&throwable);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isreadable", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		RETURN_MM_STRING("");
	}

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "isseekable", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_is_true(&_1$$4)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcontents", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_OBJ(&_2, EG(exception));
		Z_ADDREF_P(&_2);
		if (zephir_is_instance_of(&_2, SL("Throwable"))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&throwable, &_2);
			ZEPHIR_CALL_METHOD(NULL, &throwable, "getmessage", NULL, 0);
			zephir_check_call_status();
			RETURN_MM_STRING("");
		}
	}
	RETURN_MM_STRING("");

}

PHP_METHOD(Moon_Component_Http_Message_Stream, close) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "detach", NULL, 0);
	zephir_check_call_status();
	zephir_fclose(&_1);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Stream, detach) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, _resource, _0;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_resource);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&_resource, &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_resource"), &__$null);
	RETURN_CCTOR(&_resource);

}

PHP_METHOD(Moon_Component_Http_Message_Stream, eof) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		RETURN_BOOL(1);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_feof(&_1));

}

PHP_METHOD(Moon_Component_Http_Message_Stream, getContents) {

	zval result, _0, throwable, _2, _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&throwable);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isreadable", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Resource unreadable", "moon/Component/Http/Message/Stream.zep", 120);
		return;
	}

	/* try_start_1: */

		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&result, "stream_get_contents", NULL, 224, &_1$$4);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_OBJ(&_2, EG(exception));
		Z_ADDREF_P(&_2);
		if (zephir_is_instance_of(&_2, SL("Throwable"))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&throwable, &_2);
			zephir_throw_exception_debug(&throwable, "moon/Component/Http/Message/Stream.zep", 126);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Resource read failed", "moon/Component/Http/Message/Stream.zep", 129);
		return;
	}
	RETURN_CCTOR(&result);

}

PHP_METHOD(Moon_Component_Http_Message_Stream, getMetadata) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, __$null, metaData, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&metaData, "stream_get_meta_data", NULL, 243, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(key) == IS_NULL) {
		RETURN_CCTOR(&metaData);
	}
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_array_isset(&metaData, key)) {
		zephir_array_fetch(&_1, &metaData, key, PH_NOISY, "moon/Component/Http/Message/Stream.zep", 141);
	} else {
		ZVAL_NULL(&_1);
	}
	RETURN_CCTOR(&_1);

}

PHP_METHOD(Moon_Component_Http_Message_Stream, getSize) {

	zval stats, _0, _1, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stats);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&stats, "fstat", NULL, 244, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&stats)) {
		zephir_array_fetch_string(&_2$$4, &stats, SL("size"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Stream.zep", 152);
		RETURN_CTOR(&_2$$4);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Moon_Component_Http_Message_Stream, isReadable) {

	zend_bool _6;
	zval mode, _0, _1, _2, _3, _4, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_2, "stream_get_meta_data", NULL, 243, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&mode);
	zephir_array_fetch_string(&mode, &_2, SL("mode"), PH_NOISY, "moon/Component/Http/Message/Stream.zep", 163);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "r");
	ZEPHIR_CALL_FUNCTION(&_4, "strstr", &_5, 245, &mode, &_3);
	zephir_check_call_status();
	_6 = zephir_is_true(&_4);
	if (!(_6)) {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, "+");
		ZEPHIR_CALL_FUNCTION(&_7, "strstr", &_5, 245, &mode, &_3);
		zephir_check_call_status();
		_6 = zephir_is_true(&_7);
	}
	RETURN_MM_BOOL(_6);

}

PHP_METHOD(Moon_Component_Http_Message_Stream, isSeekable) {

	zval meta, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&meta);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&meta, "stream_get_meta_data", NULL, 243, &_1);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &meta, SL("seekable"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Stream.zep", 174);
	RETURN_CTOR(&_2);

}

PHP_METHOD(Moon_Component_Http_Message_Stream, isWritable) {

	zend_bool _6, _8, _10, _12;
	zval mode, _0, _1, _2, _3, _4, _7, _9, _11, _13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_2, "stream_get_meta_data", NULL, 243, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&mode);
	zephir_array_fetch_string(&mode, &_2, SL("mode"), PH_NOISY, "moon/Component/Http/Message/Stream.zep", 183);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "x");
	ZEPHIR_CALL_FUNCTION(&_4, "strstr", &_5, 245, &mode, &_3);
	zephir_check_call_status();
	_6 = zephir_is_true(&_4);
	if (!(_6)) {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, "w");
		ZEPHIR_CALL_FUNCTION(&_7, "strstr", &_5, 245, &mode, &_3);
		zephir_check_call_status();
		_6 = zephir_is_true(&_7);
	}
	_8 = _6;
	if (!(_8)) {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, "c");
		ZEPHIR_CALL_FUNCTION(&_9, "strstr", &_5, 245, &mode, &_3);
		zephir_check_call_status();
		_8 = zephir_is_true(&_9);
	}
	_10 = _8;
	if (!(_10)) {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, "a");
		ZEPHIR_CALL_FUNCTION(&_11, "strstr", &_5, 245, &mode, &_3);
		zephir_check_call_status();
		_10 = zephir_is_true(&_11);
	}
	_12 = _10;
	if (!(_12)) {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, "+");
		ZEPHIR_CALL_FUNCTION(&_13, "strstr", &_5, 245, &mode, &_3);
		zephir_check_call_status();
		_12 = zephir_is_true(&_13);
	}
	RETURN_MM_BOOL(_12);

}

PHP_METHOD(Moon_Component_Http_Message_Stream, read) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *length, length_sub, result, _0, _1, throwable, _3, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&length_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&throwable);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &length);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Resources don't exist", "moon/Component/Http/Message/Stream.zep", 191);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "isreadable", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Resource unreadable", "moon/Component/Http/Message/Stream.zep", 194);
		return;
	}

	/* try_start_1: */

		zephir_read_property(&_2$$5, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&result, "fread", NULL, 246, &_2$$5, length);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		if (zephir_is_instance_of(&_3, SL("Throwable"))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&throwable, &_3);
			zephir_throw_exception_debug(&throwable, "moon/Component/Http/Message/Stream.zep", 200);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&result);

}

PHP_METHOD(Moon_Component_Http_Message_Stream, rewind) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Stream, seek) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub, *whence = NULL, whence_sub, __$null, result, _0, _1, throwable, _3, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&whence_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&throwable);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &offset, &whence);

	if (!whence) {
		whence = &whence_sub;
		ZEPHIR_CPY_WRT(whence, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(whence);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Resources don't exist", "moon/Component/Http/Message/Stream.zep", 214);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "isseekable", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Non-locatable pointer", "moon/Component/Http/Message/Stream.zep", 217);
		return;
	}

	/* try_start_1: */

		if (Z_TYPE_P(whence) == IS_NULL) {
			ZEPHIR_INIT_NVAR(whence);
			ZVAL_LONG(whence, 0);
		}
		zephir_read_property(&_2$$5, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&result, "fseek", NULL, 247, &_2$$5, offset, whence);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		if (zephir_is_instance_of(&_3, SL("Throwable"))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&throwable, &_3);
			zephir_throw_exception_debug(&throwable, "moon/Component/Http/Message/Stream.zep", 226);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (ZEPHIR_IS_LONG_IDENTICAL(&result, -1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(moon_component_http_message_exception_invalidargumentexception_ce, "Location pointer failed", "moon/Component/Http/Message/Stream.zep", 229);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Stream, tell) {

	zval result, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Resources don't exist", "moon/Component/Http/Message/Stream.zep", 237);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&result, "ftell", NULL, 248, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Failed to get the offset in the file stream", "moon/Component/Http/Message/Stream.zep", 241);
		return;
	}
	RETURN_CCTOR(&result);

}

PHP_METHOD(Moon_Component_Http_Message_Stream, write) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_string, _string_sub, result, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_string_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_string);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Resources don't exist", "moon/Component/Http/Message/Stream.zep", 250);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "iswritable", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "File stream not writable", "moon/Component/Http/Message/Stream.zep", 253);
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("_resource"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&result);
	zephir_fwrite(&result, &_2, _string);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(moon_component_http_message_exception_invalidargumentexception_ce, "Failed to write to file stream", "moon/Component/Http/Message/Stream.zep", 257);
		return;
	}
	RETURN_CCTOR(&result);

}

