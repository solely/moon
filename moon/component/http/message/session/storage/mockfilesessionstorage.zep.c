
#ifdef HAVE_CONFIG_H
#include "../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../php_ext.h"
#include "../../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/concat.h"


/**
 * FileName: MockFileSessionStorage.php
 * User: solely
 * DateTime: 2020/9/7 23:56
 * Description:
 */
/**
 * MockFileSessionStorage is used to mock sessions for
 * functional testing when done in a single PHP process.
 *
 * No PHP session is actually started since a session can be initialized
 * and shutdown only once per PHP execution cycle and this class does
 * not pollute any session related globals, including session_*() functions
 * or session.* PHP ini directives.
 *
 * Class MockFileSessionStorage
 * @package Moon\Component\Http\Message\Session\Storage
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Session\\Storage, MockFileSessionStorage, moon, component_http_message_session_storage_mockfilesessionstorage, moon_component_http_message_session_storage_mockarraysessionstorage_ce, moon_component_http_message_session_storage_mockfilesessionstorage_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_session_storage_mockfilesessionstorage_ce, SL("savePath"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * @param string $savePath Path of directory to save session files
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, __construct) {

	zend_bool _2, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_savePath_param = NULL, *name_param = NULL, *metaBag = NULL, metaBag_sub, __$true, __$null, savePath, _0, _3, _4, _6, _7$$5, _8$$5, _9$$5;
	zval _savePath, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_savePath);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&metaBag_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&savePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &_savePath_param, &name_param, &metaBag);

	if (!_savePath_param) {
		ZEPHIR_INIT_VAR(&_savePath);
		ZVAL_STRING(&_savePath, "");
	} else {
		zephir_get_strval(&_savePath, _savePath_param);
	}
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "MOCKSESSID");
	} else {
		zephir_get_strval(&name, name_param);
	}
	if (!metaBag) {
		metaBag = &metaBag_sub;
		metaBag = &__$null;
	}


	if (Z_TYPE_P(&_savePath) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&savePath, "sys_get_temp_dir", NULL, 235);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&savePath, &_savePath);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", &_1, 211, &savePath);
	zephir_check_call_status();
	_2 = !zephir_is_true(&_0);
	if (_2) {
		ZVAL_LONG(&_3, 0777);
		ZEPHIR_CALL_FUNCTION(&_4, "mkdir", NULL, 212, &savePath, &_3, &__$true);
		zephir_check_call_status();
		_2 = !zephir_is_true(&_4);
	}
	_5 = _2;
	if (_5) {
		ZEPHIR_CALL_FUNCTION(&_6, "is_dir", &_1, 211, &savePath);
		zephir_check_call_status();
		_5 = !zephir_is_true(&_6);
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&_7$$5);
		object_init_ex(&_7$$5, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "Session Storage was not able to create directory \"%s\".");
		ZEPHIR_CALL_FUNCTION(&_9$$5, "sprintf", NULL, 3, &_8$$5, &savePath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", NULL, 34, &_9$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$5, "moon/Component/Http/Message/Session/Storage/MockFileSessionStorage.zep", 40);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("savePath"), &savePath);
	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_session_storage_mockfilesessionstorage_ce, getThis(), "__construct", &_10, 0, &name, metaBag);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, start) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _1, _2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_1)) {
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "generateid", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("id"), &_2$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "read", NULL, 236);
	zephir_check_call_status();
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$false);
	}
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, regenerate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *destroy_param = NULL, *lifetime_param = NULL, _0, _2, _3;
	zend_bool destroy;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &destroy_param, &lifetime_param);

	if (!destroy_param) {
		destroy = 0;
	} else {
		destroy = zephir_get_boolval(destroy_param);
	}
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "start", NULL, 0);
		zephir_check_call_status();
	}
	if (destroy) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "destroy", NULL, 237);
		zephir_check_call_status();
	}
	if (destroy) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZVAL_LONG(&_3, lifetime);
	ZEPHIR_RETURN_CALL_PARENT(moon_component_http_message_session_storage_mockfilesessionstorage_ce, getThis(), "regenerate", &_1, 0, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, save) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, data, bag, key, keys, _1, *_2, _3, _6, _7, _8, _4$$4, _5$$6, _9$$10, _10$$10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&bag);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Trying to save a session that was not started yet or was already closed.", "moon/Component/Http/Message/Session/Storage/MockFileSessionStorage.zep", 90);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "moon/Component/Http/Message/Session/Storage/MockFileSessionStorage.zep", 106);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&bag);
			ZVAL_COPY(&bag, _2);
			ZEPHIR_CALL_METHOD(&key, &bag, "getstoragekey", NULL, 0);
			zephir_check_call_status();
			zephir_array_fetch(&_4$$4, &data, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/MockFileSessionStorage.zep", 101);
			if (ZEPHIR_IS_EMPTY(&_4$$4)) {
				zephir_array_unset(&data, &key, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&bag, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&key, &bag, "getstoragekey", NULL, 0);
				zephir_check_call_status();
				zephir_array_fetch(&_5$$6, &data, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/MockFileSessionStorage.zep", 101);
				if (ZEPHIR_IS_EMPTY(&_5$$6)) {
					zephir_array_unset(&data, &key, PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&bag);
	ZEPHIR_INIT_VAR(&keys);
	zephir_create_array(&keys, 1, 0);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("metadataBag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_7, &_6, "getstoragekey", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&keys, &_7);
	ZEPHIR_INIT_VAR(&_8);
	zephir_array_keys(&_8, &data);
	if (ZEPHIR_IS_IDENTICAL(&keys, &_8)) {
		zephir_array_unset(&data, &keys, PH_SEPARATE);
	}

	/* try_start_1: */

		if (zephir_is_true(&data)) {
			ZEPHIR_CALL_METHOD(&_9$$10, this_ptr, "getfilepath", NULL, 238);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_FUNCTION(&_10$$10, "serialize", NULL, 239, &data);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_file_put_contents(NULL, &_9$$10, &_10$$10);
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "destroy", NULL, 237);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a session from persistent storage.
 * Deliberately leaves session data in memory intact.
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, destroy) {

	zval _0, _2, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getfilepath", &_1, 238);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "is_file", NULL, 73, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "getfilepath", &_1, 238);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 240, &_3$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Calculate path to file.
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, getFilePath) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("savePath"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("id"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VSVS(return_value, &_0, "/", &_1, ".mocksess");
	return;

}

/**
 * Reads session from storage and loads session.
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockFileSessionStorage, read) {

	zend_bool _2;
	zval filePath, _0, _1, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&filePath, this_ptr, "getfilepath", NULL, 238);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_FUNCTION(&_1, "is_readable", NULL, 241, &filePath);
	zephir_check_call_status();
	_2 = zephir_is_true(&_1);
	if (_2) {
		ZEPHIR_CALL_FUNCTION(&_3, "is_file", NULL, 73, &filePath);
		zephir_check_call_status();
		_2 = zephir_is_true(&_3);
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_file_get_contents(&_4, &filePath);
		ZEPHIR_CALL_FUNCTION(&_0, "unserialize", NULL, 242, &_4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		array_init(&_0);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadsession", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

