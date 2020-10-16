
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"


/**
 * FileName: PhpBridgeSessionStorage.php
 * User: solely
 * DateTime: 2020/9/8 0:06
 * Description:
 */
/**
 * Allows session to be started by PHP and managed by Moon (Symfony).
 *
 * Class PhpBridgeSessionStorage
 * @package Moon\Component\Http\Message\Session\Storage
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_PhpBridgeSessionStorage) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Session\\Storage, PhpBridgeSessionStorage, moon, component_http_message_session_storage_phpbridgesessionstorage, moon_component_http_message_session_storage_nativesessionstorage_ce, moon_component_http_message_session_storage_phpbridgesessionstorage_method_entry, 0);

	return SUCCESS;

}

/**
 * @param AbstractProxy|\SessionHandlerInterface|null $handler
 * @param MetadataBag $metaBag
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_PhpBridgeSessionStorage, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler = NULL, handler_sub, *metaBag, metaBag_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&metaBag_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &handler, &metaBag);

	if (!handler) {
		handler = &handler_sub;
		handler = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 55, &_0);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_LogicException, "PHP extension \"session\" is required.", "moon/Component/Http/Message/Session/Storage/PhpBridgeSessionStorage.zep", 25);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmetadatabag", NULL, 0, metaBag);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsavehandler", NULL, 0, handler);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_PhpBridgeSessionStorage, start) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadsession", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_PhpBridgeSessionStorage, clear) {

	zval bag, _0, *_1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "moon/Component/Http/Message/Session/Storage/PhpBridgeSessionStorage.zep", 55);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&bag);
			ZVAL_COPY(&bag, _1);
			ZEPHIR_CALL_METHOD(NULL, &bag, "clear", NULL, 0);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&bag, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &bag, "clear", NULL, 0);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&bag);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadsession", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

