
#ifdef HAVE_CONFIG_H
#include "../../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../../php_ext.h"
#include "../../../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/object.h"


/**
 * FileName: NativeFileSessionHandler.php
 * User: solely
 * DateTime: 2020/9/7 0:22
 * Description:
 */
/**
 * Native session handler using PHP's built in file storage.
 *
 * Class NativeFileSessionHandler
 * @package Moon\Component\Http\Message\Session\Storage\Handler
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Handler_NativeFileSessionHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Session\\Storage\\Handler, NativeFileSessionHandler, moon, component_http_message_session_storage_handler_nativefilesessionhandler, zephir_get_internal_ce(SL("sessionhandler")), moon_component_http_message_session_storage_handler_nativefilesessionhandler_method_entry, 0);

	return SUCCESS;

}

/**
 * @param string $savePath Path of directory to save session files
 *                         Default null will leave setting as defined by PHP.
 *                         '/path', 'N;/path', or 'N;octal-mode;/path
 *
 * @see https://php.net/session.configuration#ini.session.save-path for further details.
 *
 * @throws \InvalidArgumentException On invalid $savePath
 * @throws \RuntimeException         When failing to create the save directory
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_NativeFileSessionHandler, __construct) {

	zend_bool _8, _11, _14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval savePath, *savePath_param = NULL, __$true, count, baseDir, _1, _9, _12, _13, _15, _20, _0$$3, _2$$5, _3$$5, _4$$5, _6$$4, _7$$4, _16$$6, _17$$6, _18$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&count);
	ZVAL_UNDEF(&baseDir);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &savePath_param);

	if (!savePath_param) {
		ZEPHIR_INIT_VAR(&savePath);
		ZVAL_STRING(&savePath, "");
	} else {
		zephir_get_strval(&savePath, savePath_param);
	}


	if (Z_TYPE_P(&savePath) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "session.save_path");
		ZEPHIR_CALL_FUNCTION(&savePath, "ini_get", NULL, 13, &_0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(&baseDir, &savePath);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ";");
	ZEPHIR_CALL_FUNCTION(&count, "substr_count", NULL, 156, &savePath, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&count)) {
		if (ZEPHIR_GT_LONG(&count, 2)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "Invalid argument $savePath '%s'.");
			ZEPHIR_CALL_FUNCTION(&_4$$5, "sprintf", &_5, 3, &_3$$5, &savePath);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 33, &_4$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "moon/Component/Http/Message/Session/Storage/Handler/NativeFileSessionHandler.zep", 39);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, ";");
		ZEPHIR_CALL_FUNCTION(&_7$$4, "strrchr", NULL, 210, &savePath, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$4);
		ZVAL_STRING(&_6$$4, ";");
		ZEPHIR_INIT_NVAR(&baseDir);
		zephir_fast_trim(&baseDir, &_7$$4, &_6$$4, ZEPHIR_TRIM_LEFT);
	}
	_8 = zephir_is_true(&baseDir);
	if (_8) {
		ZEPHIR_CALL_FUNCTION(&_9, "is_dir", &_10, 211, &baseDir);
		zephir_check_call_status();
		_8 = !zephir_is_true(&_9);
	}
	_11 = _8;
	if (_11) {
		ZVAL_LONG(&_12, 0777);
		ZEPHIR_CALL_FUNCTION(&_13, "mkdir", NULL, 212, &baseDir, &_12, &__$true);
		zephir_check_call_status();
		_11 = !zephir_is_true(&_13);
	}
	_14 = _11;
	if (_14) {
		ZEPHIR_CALL_FUNCTION(&_15, "is_dir", &_10, 211, &baseDir);
		zephir_check_call_status();
		_14 = !zephir_is_true(&_15);
	}
	if (_14) {
		ZEPHIR_INIT_VAR(&_16$$6);
		object_init_ex(&_16$$6, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_17$$6);
		ZVAL_STRING(&_17$$6, "Session Storage was not able to create directory \"%s\".");
		ZEPHIR_CALL_FUNCTION(&_18$$6, "sprintf", &_5, 3, &_17$$6, &baseDir);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_16$$6, "__construct", NULL, 34, &_18$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_16$$6, "moon/Component/Http/Message/Session/Storage/Handler/NativeFileSessionHandler.zep", 45);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "session.save_path");
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_19, 61, &_1, &savePath);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "session.save_handler");
	ZEPHIR_INIT_VAR(&_20);
	ZVAL_STRING(&_20, "files");
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_19, 61, &_1, &_20);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

