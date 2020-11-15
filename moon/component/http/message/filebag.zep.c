
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * FileName: FileBag.php
 * User: solely
 * DateTime: 2020/7/12 23:42
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_FileBag) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message, FileBag, moon, component_http_message_filebag, moon_component_http_message_parameterbag_ce, moon_component_http_message_filebag_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_filebag_ce, SL("fileKeys"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	return SUCCESS;

}

/**
 * @param array|UploadedFile[] $parameters An array of HTTP files
 */
PHP_METHOD(Moon_Component_Http_Message_FileBag, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "replace", NULL, 0, &parameters);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_FileBag, replace) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *files_param = NULL, _0;
	zval files;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &files_param);

	if (!files_param) {
		ZEPHIR_INIT_VAR(&files);
		array_init(&files);
	} else {
		zephir_get_arrval(&files, files_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &files);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $key
 * @param mixed $value
 */
PHP_METHOD(Moon_Component_Http_Message_FileBag, set) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *key_param = NULL, *value, value_sub, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	_0 = !(Z_TYPE_P(value) == IS_ARRAY);
	if (_0) {
		_0 = !((zephir_instance_of_ev(value, moon_component_http_message_uploadedfile_ce)));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "An uploaded file must be an array or an instance of UploadedFile.", "moon/Component/Http/Message/FileBag.zep", 36);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "convertfileinformation", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_filebag_ce, getThis(), "set", &_1, 0, &key, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_FileBag, add) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *files_param = NULL, key, file, *_0, _1;
	zval files;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &files_param);

	if (!files_param) {
		ZEPHIR_INIT_VAR(&files);
		array_init(&files);
	} else {
		zephir_get_arrval(&files, files_param);
	}


	zephir_is_iterable(&files, 0, "moon/Component/Http/Message/FileBag.zep", 51);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&files), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &key, &file);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &files, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&file, &files, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &key, &file);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Converts uploaded files to UploadedFile instances.
 *
 * @param array|UploadedFile $file A (multi-dimensional) array of uploaded file information
 *
 * @return UploadedFile[]|UploadedFile|null A (multi-dimensional) array of UploadedFile instances
 */
PHP_METHOD(Moon_Component_Http_Message_FileBag, convertFileInformation) {

	zval _8$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file = NULL, file_sub, keys, _0$$4, _1$$4, _2$$5, _3$$7, _4$$7, _5$$7, _6$$7, _7$$7, _9$$8, _10$$8, _11$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_8$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);

	ZEPHIR_SEPARATE_PARAM(file);


	if (zephir_instance_of_ev(file, moon_component_http_message_uploadedfile_ce)) {
		RETVAL_ZVAL(file, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(file) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "fixphpfilesarray", NULL, 0, file);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(file, &_0$$4);
		ZEPHIR_INIT_VAR(&keys);
		zephir_array_keys(&keys, file);
		ZEPHIR_MAKE_REF(&keys);
		ZEPHIR_CALL_FUNCTION(NULL, "sort", NULL, 93, &keys);
		ZEPHIR_UNREF(&keys);
		zephir_check_call_status();
		zephir_read_static_property_ce(&_1$$4, moon_component_http_message_filebag_ce, SL("fileKeys"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_EQUAL(&keys, &_1$$4)) {
			zephir_array_fetch_string(&_2$$5, file, SL("error"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 71);
			if (ZEPHIR_IS_LONG(&_2$$5, 4)) {
				ZEPHIR_INIT_NVAR(file);
				ZVAL_NULL(file);
			} else {
				ZEPHIR_INIT_NVAR(file);
				object_init_ex(file, moon_component_http_message_uploadedfile_ce);
				zephir_array_fetch_string(&_3$$7, file, SL("tmp_name"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 74);
				zephir_array_fetch_string(&_4$$7, file, SL("name"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 74);
				zephir_array_fetch_string(&_5$$7, file, SL("type"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 74);
				zephir_array_fetch_string(&_6$$7, file, SL("error"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 74);
				ZVAL_BOOL(&_7$$7, 0);
				ZEPHIR_CALL_METHOD(NULL, file, "__construct", NULL, 94, &_3$$7, &_4$$7, &_5$$7, &_6$$7, &_7$$7);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_INIT_VAR(&_8$$8);
			zephir_create_array(&_8$$8, 2, 0);
			zephir_array_fast_append(&_8$$8, this_ptr);
			ZEPHIR_INIT_VAR(&_9$$8);
			ZVAL_STRING(&_9$$8, "convertFileInformation");
			zephir_array_fast_append(&_8$$8, &_9$$8);
			ZEPHIR_CALL_FUNCTION(&_10$$8, "array_map", NULL, 60, &_8$$8, file);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(file, &_10$$8);
			ZEPHIR_INIT_NVAR(&_9$$8);
			zephir_array_keys(&_9$$8, &keys);
			if (ZEPHIR_IS_IDENTICAL(&_9$$8, &keys)) {
				ZEPHIR_CALL_FUNCTION(&_11$$9, "array_filter", NULL, 95, file);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(file, &_11$$9);
			}
		}
	}
	RETVAL_ZVAL(file, 1, 0);
	RETURN_MM();

}

/**
 * Fixes a malformed PHP $_FILES array.
 *
 * PHP has a bug that the format of the $_FILES array differs, depending on
 * whether the uploaded file fields had normal field names or array-like
 * field names ("normal" vs. "parent[child]").
 *
 * This method fixes the array to look like the "normal" $_FILES array.
 *
 * It's safe to pass an already converted array, in which case this method
 * just returns the original array unmodified.
 *
 * @param array $data
 *
 * @return array
 */
PHP_METHOD(Moon_Component_Http_Message_FileBag, fixPhpFilesArray) {

	zval _13$$6, _21$$7;
	zend_string *_11;
	zend_ulong _10;
	zend_bool _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, files, keys, _0, _3, k, _4, *_5, _6, key, name, _7, *_8, _9, _12$$6, _14$$6, _15$$6, _16$$6, _17$$6, _18$$6, _20$$7, _22$$7, _23$$7, _24$$7, _25$$7, _26$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_21$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(&keys);
	zephir_array_keys(&keys, data);
	ZEPHIR_MAKE_REF(&keys);
	ZEPHIR_CALL_FUNCTION(NULL, "sort", NULL, 93, &keys);
	ZEPHIR_UNREF(&keys);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_0, moon_component_http_message_filebag_ce, SL("fileKeys"), PH_NOISY_CC | PH_READONLY);
	_1 = !ZEPHIR_IS_EQUAL(&_0, &keys);
	if (!(_1)) {
		_1 = !(zephir_array_isset_string(data, SL("name")));
	}
	_2 = _1;
	if (!(_2)) {
		zephir_array_fetch_string(&_3, data, SL("name"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 108);
		_2 = !(Z_TYPE_P(&_3) == IS_ARRAY);
	}
	if (_2) {
		RETVAL_ZVAL(data, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&files, data);
	zephir_read_static_property_ce(&_4, moon_component_http_message_filebag_ce, SL("fileKeys"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "moon/Component/Http/Message/FileBag.zep", 116);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&k);
			ZVAL_COPY(&k, _5);
			zephir_array_unset(&files, &k, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &_4, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_unset(&files, &k, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&k);
	zephir_array_fetch_string(&_7, data, SL("name"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 118);
	zephir_is_iterable(&_7, 0, "moon/Component/Http/Message/FileBag.zep", 121);
	if (Z_TYPE_P(&_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_7), _10, _11, _8)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_11 != NULL) { 
				ZVAL_STR_COPY(&key, _11);
			} else {
				ZVAL_LONG(&key, _10);
			}
			ZEPHIR_INIT_NVAR(&name);
			ZVAL_COPY(&name, _8);
			ZEPHIR_INIT_NVAR(&_13$$6);
			zephir_create_array(&_13$$6, 5, 0);
			zephir_array_fetch_string(&_14$$6, data, SL("error"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 119);
			ZEPHIR_OBS_NVAR(&_15$$6);
			zephir_array_fetch(&_15$$6, &_14$$6, &key, PH_NOISY, "moon/Component/Http/Message/FileBag.zep", 119);
			zephir_array_update_string(&_13$$6, SL("error"), &_15$$6, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$6, SL("name"), &name, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_16$$6, data, SL("type"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 119);
			ZEPHIR_OBS_NVAR(&_15$$6);
			zephir_array_fetch(&_15$$6, &_16$$6, &key, PH_NOISY, "moon/Component/Http/Message/FileBag.zep", 119);
			zephir_array_update_string(&_13$$6, SL("type"), &_15$$6, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_17$$6, data, SL("tmp_name"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 119);
			ZEPHIR_OBS_NVAR(&_15$$6);
			zephir_array_fetch(&_15$$6, &_17$$6, &key, PH_NOISY, "moon/Component/Http/Message/FileBag.zep", 119);
			zephir_array_update_string(&_13$$6, SL("tmp_name"), &_15$$6, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_18$$6, data, SL("size"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 119);
			ZEPHIR_OBS_NVAR(&_15$$6);
			zephir_array_fetch(&_15$$6, &_18$$6, &key, PH_NOISY, "moon/Component/Http/Message/FileBag.zep", 119);
			zephir_array_update_string(&_13$$6, SL("size"), &_15$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_12$$6, this_ptr, "fixphpfilesarray", &_19, 96, &_13$$6);
			zephir_check_call_status();
			zephir_array_update_zval(&files, &key, &_12$$6, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_7, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_9, &_7, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_7, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&name, &_7, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$7);
				zephir_create_array(&_21$$7, 5, 0);
				zephir_array_fetch_string(&_22$$7, data, SL("error"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 119);
				ZEPHIR_OBS_NVAR(&_23$$7);
				zephir_array_fetch(&_23$$7, &_22$$7, &key, PH_NOISY, "moon/Component/Http/Message/FileBag.zep", 119);
				zephir_array_update_string(&_21$$7, SL("error"), &_23$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_21$$7, SL("name"), &name, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_string(&_24$$7, data, SL("type"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 119);
				ZEPHIR_OBS_NVAR(&_23$$7);
				zephir_array_fetch(&_23$$7, &_24$$7, &key, PH_NOISY, "moon/Component/Http/Message/FileBag.zep", 119);
				zephir_array_update_string(&_21$$7, SL("type"), &_23$$7, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_string(&_25$$7, data, SL("tmp_name"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 119);
				ZEPHIR_OBS_NVAR(&_23$$7);
				zephir_array_fetch(&_23$$7, &_25$$7, &key, PH_NOISY, "moon/Component/Http/Message/FileBag.zep", 119);
				zephir_array_update_string(&_21$$7, SL("tmp_name"), &_23$$7, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_string(&_26$$7, data, SL("size"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/FileBag.zep", 119);
				ZEPHIR_OBS_NVAR(&_23$$7);
				zephir_array_fetch(&_23$$7, &_26$$7, &key, PH_NOISY, "moon/Component/Http/Message/FileBag.zep", 119);
				zephir_array_update_string(&_21$$7, SL("size"), &_23$$7, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_20$$7, this_ptr, "fixphpfilesarray", &_19, 96, &_21$$7);
				zephir_check_call_status();
				zephir_array_update_zval(&files, &key, &_20$$7, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_7, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&files);

}

void zephir_init_static_properties_Moon_Component_Http_Message_FileBag(TSRMLS_D) {

	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 5, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "error");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "name");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "size");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tmp_name");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "type");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_static_property_ce(moon_component_http_message_filebag_ce, ZEND_STRL("fileKeys"), &_0);
	ZEPHIR_MM_RESTORE();

}

