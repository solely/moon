
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/file.h"


/**
 * FileName: UploadedFile.php
 * User: solely
 * DateTime: 2019/1/14 0:04
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_UploadedFile) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message, UploadedFile, moon, component_http_message_uploadedfile, moon_component_http_message_uploadedfile_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_uploadedfile_ce, SL("size"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_uploadedfile_ce, SL("clientFilename"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_uploadedfile_ce, SL("clientMediaType"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_uploadedfile_ce, SL("error"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_uploadedfile_ce, SL("stream"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_uploadedfile_ce, SL("file"), ZEND_ACC_PRIVATE);

	zend_declare_property_bool(moon_component_http_message_uploadedfile_ce, SL("moved"), 0, ZEND_ACC_PRIVATE);

	zend_class_implements(moon_component_http_message_uploadedfile_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\uploadedfileinterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_UploadedFile, __construct) {

	zval *size, size_sub, *clientFilename, clientFilename_sub, *clientMediaType, clientMediaType_sub, *error, error_sub, *file = NULL, file_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&size_sub);
	ZVAL_UNDEF(&clientFilename_sub);
	ZVAL_UNDEF(&clientMediaType_sub);
	ZVAL_UNDEF(&error_sub);
	ZVAL_UNDEF(&file_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params_without_memory_grow(4, 1, &size, &clientFilename, &clientMediaType, &error, &file);

	if (!file) {
		file = &file_sub;
		file = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("size"), size);
	zephir_update_property_zval(this_ptr, ZEND_STRL("clientFilename"), clientFilename);
	zephir_update_property_zval(this_ptr, ZEND_STRL("clientMediaType"), clientMediaType);
	zephir_update_property_zval(this_ptr, ZEND_STRL("error"), error);
	zephir_update_property_zval(this_ptr, ZEND_STRL("file"), file);

}

PHP_METHOD(Moon_Component_Http_Message_UploadedFile, getSize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "size");

}

PHP_METHOD(Moon_Component_Http_Message_UploadedFile, getClientFilename) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "clientFilename");

}

PHP_METHOD(Moon_Component_Http_Message_UploadedFile, getClientMediaType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "clientMediaType");

}

PHP_METHOD(Moon_Component_Http_Message_UploadedFile, getError) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "error");

}

PHP_METHOD(Moon_Component_Http_Message_UploadedFile, getStream) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *isCheck = NULL, isCheck_sub, __$true, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&isCheck_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &isCheck);

	if (!isCheck) {
		isCheck = &isCheck_sub;
		isCheck = &__$true;
	}


	if (zephir_is_true(isCheck)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "check", NULL, 249);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("stream"), PH_NOISY_CC);
	if (zephir_is_instance_of(&_0, SL("Psr\\Http\\Message\\StreamInterface"))) {
		RETURN_MM_MEMBER(getThis(), "stream");
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, moon_component_http_message_stream_ce);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 2, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("stream"), &_1);
	RETURN_MM_MEMBER(getThis(), "stream");

}

PHP_METHOD(Moon_Component_Http_Message_UploadedFile, moveTo) {

	zend_bool _7, _8, _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *targetPath, targetPath_sub, __$true, __$false, sApi, path, _0, _4, _9, _10, _12, _1$$3, _2$$3, _5$$4, _6$$4, _13$$6, _14$$6, _15$$7, _16$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&sApi);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "check", NULL, 249);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&path, "dirname", NULL, 250, targetPath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 211, &path);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, moon_component_http_message_exception_uploadedfileexception_ce);
		ZVAL_LONG(&_2$$3, 102);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", &_3, 251, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "moon/Component/Http/Message/UploadedFile.zep", 70);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_4, "is_writable", NULL, 252, &path);
	zephir_check_call_status();
	if (!zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, moon_component_http_message_exception_uploadedfileexception_ce);
		ZVAL_LONG(&_6$$4, 103);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", &_3, 251, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "moon/Component/Http/Message/UploadedFile.zep", 73);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&sApi);
	ZEPHIR_GET_CONSTANT(&sApi, "PHP_SAPI");
	do {
		_7 = 1;
		_8 = ZEPHIR_IS_EMPTY(&sApi);
		if (!(_8)) {
			ZEPHIR_INIT_VAR(&_9);
			ZVAL_STRING(&_9, "cli");
			ZEPHIR_INIT_VAR(&_10);
			zephir_fast_strpos(&_10, &sApi, &_9, 0 );
			_8 = ZEPHIR_IS_LONG_IDENTICAL(&_10, 0);
		}
		_11 = _8;
		if (!(_11)) {
			zephir_read_property(&_12, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
			_11 = !zephir_is_true(&_12);
		}
		if (_7 == _11) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "writefile", NULL, 253, targetPath);
			zephir_check_call_status();
			break;
		}
		zephir_read_property(&_13$$6, this_ptr, ZEND_STRL("file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_14$$6, "move_uploaded_file", NULL, 254, &_13$$6, targetPath);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_14$$6)) {
			ZEPHIR_INIT_VAR(&_15$$7);
			object_init_ex(&_15$$7, moon_component_http_message_exception_uploadedfileexception_ce);
			ZVAL_LONG(&_16$$7, 104);
			ZEPHIR_CALL_METHOD(NULL, &_15$$7, "__construct", &_3, 251, &_16$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_15$$7, "moon/Component/Http/Message/UploadedFile.zep", 82);
			ZEPHIR_MM_RESTORE();
			return;
		}
		break;
	} while(0);

	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("moved"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("moved"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_UploadedFile, check) {

	zval _0, _4, _1$$3, _2$$3, _5$$4, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("error"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_LONG(&_0, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, moon_component_http_message_exception_uploadedfileexception_ce);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("error"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", &_3, 251, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "moon/Component/Http/Message/UploadedFile.zep", 92);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("moved"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, moon_component_http_message_exception_uploadedfileexception_ce);
		ZVAL_LONG(&_6$$4, 101);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", &_3, 251, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "moon/Component/Http/Message/UploadedFile.zep", 95);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_UploadedFile, writeFile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *targetPath, targetPath_sub, s, fp, stream, _0, _1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath_sub);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&fp);
	ZVAL_UNDEF(&stream);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath);



	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(&stream, this_ptr, "getstream", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &stream, "rewind", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "wb");
	ZEPHIR_CALL_FUNCTION(&fp, "fopen", NULL, 140, targetPath, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 4096);
	ZEPHIR_CALL_METHOD(&s, &stream, "read", NULL, 0, &_0);
	zephir_check_call_status();
	while (1) {
		if (!(zephir_is_true(&s))) {
			break;
		}
		zephir_fwrite(NULL, &fp, &s);
		ZVAL_LONG(&_2$$3, 4096);
		ZEPHIR_CALL_METHOD(&s, &stream, "read", NULL, 0, &_2$$3);
		zephir_check_call_status();
	}
	zephir_fclose(&fp);
	ZEPHIR_MM_RESTORE();

}

