
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"


/**
 * FileName: NativeSessionStorage.php
 * User: solely
 * DateTime: 2020/9/8 0:00
 * Description:
 */
/**
 *  This provides a base class for session attribute storage.
 *
 * Class NativeSessionStorage
 * @package Moon\Component\Http\Message\Session\Storage
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session\\Storage, NativeSessionStorage, moon, component_http_message_session_storage_nativesessionstorage, moon_component_http_message_session_storage_nativesessionstorage_method_entry, 0);

	/**
	 * @var SessionBagInterface[]
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_nativesessionstorage_ce, SL("bags"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(moon_component_http_message_session_storage_nativesessionstorage_ce, SL("started"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(moon_component_http_message_session_storage_nativesessionstorage_ce, SL("closed"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var AbstractProxy|\SessionHandlerInterface
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_nativesessionstorage_ce, SL("saveHandler"), ZEND_ACC_PROTECTED);

	/**
	 * @var MetadataBag
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_nativesessionstorage_ce, SL("metadataBag"), ZEND_ACC_PROTECTED);

	/**
	 * @var string|null
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_nativesessionstorage_ce, SL("emulateSameSite"), ZEND_ACC_PRIVATE);

	moon_component_http_message_session_storage_nativesessionstorage_ce->create_object = zephir_init_properties_Moon_Component_Http_Message_Session_Storage_NativeSessionStorage;

	zend_class_implements(moon_component_http_message_session_storage_nativesessionstorage_ce, 1, moon_component_http_message_session_storage_sessionstorageinterface_ce);
	return SUCCESS;

}

/**
 * Depending on how you want the storage driver to behave you probably
 * want to override this constructor entirely.
 *
 * List of options for $options array with their defaults.
 *
 * @see https://php.net/session.configuration for options
 * but we omit 'session.' from the beginning of the keys for convenience.
 *
 * ("auto_start", is not supported as it tells PHP to start a session before
 * PHP starts to execute user-land code. Setting during runtime has no effect).
 *
 * cache_limiter, "" (use "0" to prevent headers from being sent entirely).
 * cache_expire, "0"
 * cookie_domain, ""
 * cookie_httponly, ""
 * cookie_lifetime, "0"
 * cookie_path, "/"
 * cookie_secure, ""
 * cookie_samesite, null
 * gc_divisor, "100"
 * gc_maxlifetime, "1440"
 * gc_probability, "1"
 * lazy_write, "1"
 * name, "PHPSESSID"
 * referer_check, ""
 * serialize_handler, "php"
 * use_strict_mode, "0"
 * use_cookies, "1"
 * use_only_cookies, "1"
 * use_trans_sid, "0"
 * upload_progress.enabled, "1"
 * upload_progress.cleanup, "1"
 * upload_progress.prefix, "upload_progress_"
 * upload_progress.name, "PHP_SESSION_UPLOAD_PROGRESS"
 * upload_progress.freq, "1%"
 * upload_progress.min-freq, "1"
 * url_rewriter.tags, "a=href,area=href,frame=src,form=,fieldset="
 * sid_length, "32"
 * sid_bits_per_character, "5"
 * trans_sid_hosts, $_SERVER['HTTP_HOST']
 * trans_sid_tags, "a=href,area=href,frame=src,form="
 *
 * @param array $options
 * @param AbstractProxy|\SessionHandlerInterface|null $handler
 * @param MetadataBag $metaBag
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *handler = NULL, handler_sub, *metaBag = NULL, metaBag_sub, __$null, _0, _1;
	zval options, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&metaBag_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &options_param, &handler, &metaBag);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (!handler) {
		handler = &handler_sub;
		handler = &__$null;
	}
	if (!metaBag) {
		metaBag = &metaBag_sub;
		metaBag = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 55, &_0);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_LogicException, "PHP extension \"session\" is required.", "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 109);
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 5, 0);
	add_assoc_stringl_ex(&_2, SL("cache_limiter"), SL(""));
	add_assoc_long_ex(&_2, SL("cache_expire"), 0);
	add_assoc_long_ex(&_2, SL("use_cookies"), 1);
	add_assoc_long_ex(&_2, SL("lazy_write"), 1);
	add_assoc_long_ex(&_2, SL("use_strict_mode"), 1);
	zephir_fast_array_merge(&_0, &_2, &options);
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_CALL_FUNCTION(NULL, "session_register_shutdown", NULL, 56);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmetadatabag", NULL, 0, metaBag);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsavehandler", NULL, 0, handler);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the save handler instance.
 *
 * @return AbstractProxy|\SessionHandlerInterface
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getSaveHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "saveHandler");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, start) {

	zend_bool _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$false, _0, _1, file, line, originalCookie, _2, _3, _4, _5, _7, _12, _8$$5, _9$$5, _10$$5, _14$$7, _15$$7, _16$$8, _17$$8, _18$$8;
	zephir_fcall_cache_entry *_11 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&originalCookie);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_FUNCTION(&_1, "session_status", NULL, 57);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(&_1, 2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Failed to start the session: already started by PHP.", "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 147);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "session.use_cookies");
	ZEPHIR_CALL_FUNCTION(&_3, "ini_get", NULL, 13, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 258);
	ZEPHIR_CALL_FUNCTION(&_5, "filter_var", NULL, 17, &_3, &_4);
	zephir_check_call_status();
	_6 = zephir_is_true(&_5);
	if (_6) {
		ZEPHIR_MAKE_REF(&file);
		ZEPHIR_MAKE_REF(&line);
		ZEPHIR_CALL_FUNCTION(&_7, "headers_sent", NULL, 10, &file, &line);
		ZEPHIR_UNREF(&file);
		ZEPHIR_UNREF(&line);
		zephir_check_call_status();
		_6 = zephir_is_true(&_7);
	}
	if (_6) {
		ZEPHIR_INIT_VAR(&_8$$5);
		object_init_ex(&_8$$5, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "Failed to start the session because headers have already been sent by \"%s\" at line %d.");
		ZEPHIR_CALL_FUNCTION(&_10$$5, "sprintf", &_11, 3, &_9$$5, &file, &line);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", NULL, 34, &_10$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$5, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 154);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_12, "session_start", NULL, 58);
	zephir_check_call_status();
	if (!zephir_is_true(&_12)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Failed to start the session.", "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 159);
		return;
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("emulateSameSite"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_4) != IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&_14$$7, "session_name", NULL, 59);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_15$$7, "session_id", NULL, 60);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&originalCookie, moon_component_http_message_session_sessionutils_ce, "popsessioncookie", &_13, 0, &_14$$7, &_15$$7);
		zephir_check_call_status();
		if (Z_TYPE_P(&originalCookie) != IS_NULL) {
			zephir_read_property(&_16$$8, this_ptr, ZEND_STRL("emulateSameSite"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_17$$8);
			ZVAL_STRING(&_17$$8, "%s; SameSite=%s");
			ZEPHIR_CALL_FUNCTION(&_18$$8, "sprintf", &_11, 3, &_17$$8, &originalCookie, &_16$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 12, &_18$$8, &__$false);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadsession", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getId) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("saveHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setId) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, _0;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("saveHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setid", NULL, 0, &id);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getName) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("saveHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getname", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("saveHandler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setname", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, regenerate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *destroy_param = NULL, *lifetime_param = NULL, __$false, isRegenerated, originalCookie, _0, _1, _3, _4, _8, _9, _5$$5, _6$$5, _7$$6, _11$$7, _12$$7, _13$$8, _14$$8, _15$$8;
	zend_bool destroy, _2;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&isRegenerated);
	ZVAL_UNDEF(&originalCookie);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);

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


	ZEPHIR_CALL_FUNCTION(&_0, "session_status", NULL, 57);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_0, 2)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&_1, "headers_sent", NULL, 10);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_MM_BOOL(0);
	}
	_2 = 0 != lifetime;
	if (_2) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "session.cookie_lifetime");
		ZEPHIR_CALL_FUNCTION(&_4, "ini_get", NULL, 13, &_3);
		zephir_check_call_status();
		_2 = !ZEPHIR_IS_LONG(&_4, lifetime);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "session.cookie_lifetime");
		ZVAL_LONG(&_6$$5, lifetime);
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 61, &_5$$5, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "start", NULL, 0);
		zephir_check_call_status();
	}
	if (destroy) {
		zephir_read_property(&_7$$6, this_ptr, ZEND_STRL("metadataBag"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_7$$6, "stampnew", NULL, 0);
		zephir_check_call_status();
	}
	ZVAL_BOOL(&_8, (destroy ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(&isRegenerated, "session_regenerate_id", NULL, 62, &_8);
	zephir_check_call_status();
	zephir_read_property(&_9, this_ptr, ZEND_STRL("emulateSameSite"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_9) != IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&_11$$7, "session_name", NULL, 59);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_12$$7, "session_id", NULL, 60);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&originalCookie, moon_component_http_message_session_sessionutils_ce, "popsessioncookie", &_10, 0, &_11$$7, &_12$$7);
		zephir_check_call_status();
		if (Z_TYPE_P(&originalCookie) != IS_NULL) {
			zephir_read_property(&_13$$8, this_ptr, ZEND_STRL("emulateSameSite"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_14$$8);
			ZVAL_STRING(&_14$$8, "%s; SameSite=%s");
			ZEPHIR_CALL_FUNCTION(&_15$$8, "sprintf", NULL, 3, &_14$$8, &originalCookie, &_13$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 12, &_15$$8, &__$false);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&isRegenerated);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, save) {

	zval keysArr;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _SESSION, __$true, __$false, session, bag, key, keys, e, msg, _0, *_1, _2, _5, _6, _7, _3$$3, _4$$5, _8$$11, _9$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SESSION);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&bag);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&keysArr);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));

	ZEPHIR_INIT_VAR(&keysArr);
	array_init(&keysArr);
	ZEPHIR_CPY_WRT(&session, &_SESSION);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 266);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&bag);
			ZVAL_COPY(&bag, _1);
			ZEPHIR_CALL_METHOD(&key, &bag, "getstoragekey", NULL, 0);
			zephir_check_call_status();
			zephir_array_fetch(&_3$$3, &_SESSION, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 261);
			if (ZEPHIR_IS_EMPTY(&_3$$3)) {
				zephir_array_unset(&_SESSION, &key, PH_SEPARATE);
			}
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
				ZEPHIR_CALL_METHOD(&key, &bag, "getstoragekey", NULL, 0);
				zephir_check_call_status();
				zephir_array_fetch(&_4$$5, &_SESSION, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 261);
				if (ZEPHIR_IS_EMPTY(&_4$$5)) {
					zephir_array_unset(&_SESSION, &key, PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&bag);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("metadataBag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&keys, &_5, "getstoragekey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&keysArr);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 63, &keysArr, &keys);
	ZEPHIR_UNREF(&keysArr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_array_keys(&_6, &_SESSION);
	if (ZEPHIR_IS_IDENTICAL(&keysArr, &_6)) {
		zephir_array_unset(&_SESSION, &keys, PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&msg);
	ZVAL_STRING(&msg, "");

	/* try_start_1: */

		ZEPHIR_CALL_FUNCTION(NULL, "session_write_close", NULL, 64);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_7);
		ZVAL_OBJ(&_7, EG(exception));
		Z_ADDREF_P(&_7);
		if (zephir_instance_of_ev(&_7, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_7);
			ZEPHIR_CALL_METHOD(&msg, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
		}
	}
	if (zephir_is_true(&_SESSION)) {
		ZEPHIR_HASH_COPY(&_SESSION, &session);
	}
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("closed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("closed"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$false);
	}
	if (!(ZEPHIR_IS_EMPTY(&msg))) {
		ZEPHIR_INIT_VAR(&_8$$11);
		object_init_ex(&_8$$11, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_9$$11);
		ZEPHIR_CONCAT_SV(&_9$$11, "session_write_close(): ", &msg);
		ZEPHIR_CALL_METHOD(NULL, &_8$$11, "__construct", NULL, 4, &_9$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$11, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 298);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, clear) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SESSION, bag, _0, *_1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&bag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));

	zephir_read_property(&_0, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 314);
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
	ZEPHIR_INIT_NVAR(&_SESSION);
	array_init(&_SESSION);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadsession", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, registerBag) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bag, bag_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bag_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bag);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_LogicException, "Cannot register a bag when the session is already started.", "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 326);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, bag, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("bags"), &_1, bag);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getBag) {

	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _4, _6, _7, _8, _9, _10, _1$$3, _2$$3, _3$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "The SessionBagInterface \"%s\" is not registered.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 3, &_2$$3, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 33, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 338);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	_5 = !zephir_is_true(&_4);
	if (_5) {
		zephir_read_property(&_6, this_ptr, ZEND_STRL("saveHandler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7, &_6, "isactive", NULL, 0);
		zephir_check_call_status();
		_5 = zephir_is_true(&_7);
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (_5) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadsession", NULL, 0);
		zephir_check_call_status();
	} else if (!zephir_is_true(&_8)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "start", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_9, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_10, &_9, &name, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 347);
	RETURN_CTOR(&_10);

}

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setMetadataBag) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaBag = NULL, metaBag_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaBag_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &metaBag);

	if (!metaBag) {
		metaBag = &metaBag_sub;
		ZEPHIR_CPY_WRT(metaBag, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(metaBag);
	}


	if (Z_TYPE_P(metaBag) == IS_NULL) {
		ZEPHIR_INIT_NVAR(metaBag);
		object_init_ex(metaBag, moon_component_http_message_session_storage_metadatabag_ce);
		ZEPHIR_CALL_METHOD(NULL, metaBag, "__construct", NULL, 52);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("metadataBag"), metaBag);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the MetadataBag.
 *
 * @return MetadataBag
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, getMetadataBag) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "metadataBag");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, isStarted) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "started");

}

/**
 * Sets session.* ini variables.
 *
 * For convenience we omit 'session.' from the beginning of the keys.
 * Explicitly ignores other ini keys.
 *
 * @param array $options Session ini directives [key => value]
 *
 * @see https://php.net/session.configuration
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setOptions) {

	zend_string *_8;
	zend_ulong _7;
	zend_bool _1, _10$$5, _16$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _2, validOptions, key, value, _4, *_5, _6, _9$$5, _11$$5, _12$$5, _13$$5, _15$$8, _17$$8, _18$$8, _19$$8;
	zval options, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&validOptions);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 10);
	zephir_check_call_status();
	_1 = zephir_is_true(&_0);
	if (!(_1)) {
		ZEPHIR_CALL_FUNCTION(&_2, "session_status", NULL, 57);
		zephir_check_call_status();
		_1 = ZEPHIR_IS_LONG_IDENTICAL(&_2, 2);
	}
	if (_1) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 30, 0);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "cache_expire");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "cache_limiter");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "cookie_domain");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "cookie_httponly");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "cookie_lifetime");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "cookie_path");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "cookie_secure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "cookie_samesite");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "gc_divisor");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "gc_maxlifetime");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "gc_probability");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "lazy_write");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "name");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "referer_check");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "serialize_handler");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "use_strict_mode");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "use_cookies");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "use_only_cookies");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "use_trans_sid");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "upload_progress.enabled");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "upload_progress.cleanup");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "upload_progress.prefix");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "upload_progress.name");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "upload_progress.freq");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "upload_progress.min_freq");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "url_rewriter.tags");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "sid_length");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "sid_bits_per_character");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "trans_sid_hosts");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "trans_sid_tags");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_FUNCTION(&validOptions, "array_flip", NULL, 65, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&options, 0, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 420);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&key, _8);
			} else {
				ZVAL_LONG(&key, _7);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _5);
			if (zephir_array_isset(&validOptions, &key)) {
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_STRING(&_9$$5, "cookie_samesite");
				_10$$5 = ZEPHIR_IS_IDENTICAL(&_9$$5, &key);
				if (_10$$5) {
					ZEPHIR_INIT_NVAR(&_11$$5);
					ZEPHIR_GET_CONSTANT(&_11$$5, "PHP_VERSION_ID");
					_10$$5 = ZEPHIR_LT_LONG(&_11$$5, 70300);
				}
				if (_10$$5) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("emulateSameSite"), &value);
					continue;
				}
				ZEPHIR_INIT_NVAR(&_12$$5);
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "url_rewriter.tags");
				if (!ZEPHIR_IS_IDENTICAL(&_13$$5, &key)) {
					ZEPHIR_INIT_NVAR(&_12$$5);
					ZEPHIR_CONCAT_SV(&_12$$5, "session.", &key);
				} else {
					ZEPHIR_CPY_WRT(&_12$$5, &key);
				}
				ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_14, 61, &_12$$5, &value);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &options, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &options, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset(&validOptions, &key)) {
					ZEPHIR_INIT_NVAR(&_15$$8);
					ZVAL_STRING(&_15$$8, "cookie_samesite");
					_16$$8 = ZEPHIR_IS_IDENTICAL(&_15$$8, &key);
					if (_16$$8) {
						ZEPHIR_INIT_NVAR(&_17$$8);
						ZEPHIR_GET_CONSTANT(&_17$$8, "PHP_VERSION_ID");
						_16$$8 = ZEPHIR_LT_LONG(&_17$$8, 70300);
					}
					if (_16$$8) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("emulateSameSite"), &value);
						continue;
					}
					ZEPHIR_INIT_NVAR(&_18$$8);
					ZEPHIR_INIT_NVAR(&_19$$8);
					ZVAL_STRING(&_19$$8, "url_rewriter.tags");
					if (!ZEPHIR_IS_IDENTICAL(&_19$$8, &key)) {
						ZEPHIR_INIT_NVAR(&_18$$8);
						ZEPHIR_CONCAT_SV(&_18$$8, "session.", &key);
					} else {
						ZEPHIR_CPY_WRT(&_18$$8, &key);
					}
					ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_14, 61, &_18$$8, &value);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers session save handler as a PHP session handler.
 *
 * To use internal PHP session save handlers, override this method using ini_set with
 * session.save_handler and session.save_path e.g.
 *
 *     ini_set('session.save_handler', 'files');
 *     ini_set('session.save_path', '/tmp');
 *
 * or pass in a \SessionHandler instance which configures session.save_handler in the
 * constructor, for a template see NativeFileSessionHandler.
 *
 * @see https://php.net/session-set-save-handler
 * @see https://php.net/sessionhandlerinterface
 * @see https://php.net/sessionhandler
 *
 * @param AbstractProxy|\SessionHandlerInterface|null $saveHandler
 *
 * @throws \InvalidArgumentException
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, setSaveHandler) {

	zend_bool _0, _1, _2, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *saveHandler = NULL, saveHandler_sub, __$false, __$null, _5, _7, _8, _3$$5, _4$$5, _9$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&saveHandler_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_9$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &saveHandler);

	if (!saveHandler) {
		saveHandler = &saveHandler_sub;
		ZEPHIR_CPY_WRT(saveHandler, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(saveHandler);
	}


	_0 = !((zephir_instance_of_ev(saveHandler, moon_component_http_message_session_storage_proxy_abstractproxy_ce)));
	if (_0) {
		_0 = !((zephir_is_instance_of(saveHandler, SL("SessionHandlerInterface"))));
	}
	_1 = _0;
	if (_1) {
		_1 = Z_TYPE_P(saveHandler) != IS_NULL;
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Must be instance of AbstractProxy; implement \\SessionHandlerInterface; or be null.", "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 447);
		return;
	}
	_2 = !((zephir_instance_of_ev(saveHandler, moon_component_http_message_session_storage_proxy_abstractproxy_ce)));
	if (_2) {
		_2 = zephir_is_instance_of(saveHandler, SL("SessionHandlerInterface"));
	}
	if (_2) {
		ZEPHIR_INIT_NVAR(saveHandler);
		object_init_ex(saveHandler, moon_component_http_message_session_storage_proxy_sessionhandlerproxy_ce);
		ZEPHIR_CALL_METHOD(NULL, saveHandler, "__construct", NULL, 66, saveHandler);
		zephir_check_call_status();
	} else if (!((zephir_instance_of_ev(saveHandler, moon_component_http_message_session_storage_proxy_abstractproxy_ce)))) {
		ZEPHIR_INIT_NVAR(saveHandler);
		object_init_ex(saveHandler, moon_component_http_message_session_storage_proxy_sessionhandlerproxy_ce);
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, moon_component_http_message_session_storage_handler_strictsessionhandler_ce);
		ZEPHIR_INIT_VAR(&_4$$5);
		object_init_ex(&_4$$5, zephir_get_internal_ce(SL("sessionhandler")));
		if (zephir_has_constructor(&_4$$5)) {
			ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 67, &_4$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, saveHandler, "__construct", NULL, 66, &_3$$5);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("saveHandler"), saveHandler);
	ZEPHIR_CALL_FUNCTION(&_5, "headers_sent", NULL, 10);
	zephir_check_call_status();
	_6 = zephir_is_true(&_5);
	if (!(_6)) {
		ZEPHIR_CALL_FUNCTION(&_7, "session_status", NULL, 57);
		zephir_check_call_status();
		_6 = ZEPHIR_IS_LONG_IDENTICAL(&_7, 2);
	}
	if (_6) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("saveHandler"), PH_NOISY_CC);
	if (zephir_instance_of_ev(&_8, moon_component_http_message_session_storage_proxy_sessionhandlerproxy_ce)) {
		zephir_read_property(&_9$$7, this_ptr, ZEND_STRL("saveHandler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, 68, &_9$$7, &__$false);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Load the session with attributes.
 *
 * After starting the session, PHP retrieves the session from whatever handlers
 * are set to (either PHP's internal, or a custom save handler set with session_set_save_handler()).
 * PHP takes the return value from the read() handler, unserializes it
 * and populates $_SESSION with the result automatically.
 *
 * @param array $session
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_NativeSessionStorage, loadSession) {

	zend_bool _6$$4, _10$$5;
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval session, *session_param = NULL, _SESSION, __$true, __$false, bags, bag, key, _0, _2, *_3, _4, _5$$4, _7$$4, _8$$4, _9$$5, _11$$5, _12$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&bags);
	ZVAL_UNDEF(&bag);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 0, 1, &session_param);

	if (!session_param) {
		ZEPHIR_INIT_VAR(&session);
		array_init(&session);
	} else {
		zephir_get_arrval(&session, session_param);
	}


	if (Z_TYPE_P(&session) == IS_NULL) {
		ZEPHIR_CPY_WRT(&session, &_SESSION);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("metadataBag"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&bags);
	zephir_fast_array_merge(&bags, &_0, &_1);
	zephir_is_iterable(&bags, 0, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 498);
	if (Z_TYPE_P(&bags) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&bags), _3)
		{
			ZEPHIR_INIT_NVAR(&bag);
			ZVAL_COPY(&bag, _3);
			ZEPHIR_CALL_METHOD(&key, &bag, "getstoragekey", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_5$$4);
			_6$$4 = zephir_array_isset(&session, &key);
			if (_6$$4) {
				zephir_array_fetch(&_7$$4, &session, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 494);
				_6$$4 = Z_TYPE_P(&_7$$4) == IS_ARRAY;
			}
			if (_6$$4) {
				ZEPHIR_OBS_NVAR(&_5$$4);
				zephir_array_fetch(&_5$$4, &session, &key, PH_NOISY, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 494);
			} else {
				ZEPHIR_INIT_NVAR(&_5$$4);
				array_init(&_5$$4);
			}
			zephir_array_update_zval(&session, &key, &_5$$4, PH_COPY | PH_SEPARATE);
			zephir_array_fetch(&_8$$4, &session, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 495);
			ZEPHIR_CALL_METHOD(NULL, &bag, "initialize", NULL, 0, &_8$$4);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &bags, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &bags, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&bag, &bags, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&key, &bag, "getstoragekey", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$5);
				_10$$5 = zephir_array_isset(&session, &key);
				if (_10$$5) {
					zephir_array_fetch(&_11$$5, &session, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 494);
					_10$$5 = Z_TYPE_P(&_11$$5) == IS_ARRAY;
				}
				if (_10$$5) {
					ZEPHIR_OBS_NVAR(&_9$$5);
					zephir_array_fetch(&_9$$5, &session, &key, PH_NOISY, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 494);
				} else {
					ZEPHIR_INIT_NVAR(&_9$$5);
					array_init(&_9$$5);
				}
				zephir_array_update_zval(&session, &key, &_9$$5, PH_COPY | PH_SEPARATE);
				zephir_array_fetch(&_12$$5, &session, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/NativeSessionStorage.zep", 495);
				ZEPHIR_CALL_METHOD(NULL, &bag, "initialize", NULL, 0, &_12$$5);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &bags, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&bag);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("closed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("closed"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Storage_NativeSessionStorage(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bags"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

