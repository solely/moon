
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * FileName: MockArraySessionStorage.php
 * User: solely
 * DateTime: 2020/9/7 23:52
 * Description:
 */
/**
 * MockArraySessionStorage mocks the session for unit tests.
 *
 * No PHP session is actually started since a session can be initialized
 * and shutdown only once per PHP execution cycle.
 *
 * When doing functional testing, you should use MockFileSessionStorage instead.
 *
 * Class MockArraySessionStorage
 * @package Moon\Component\Http\Message\Session\Storage
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session\\Storage, MockArraySessionStorage, moon, component_http_message_session_storage_mockarraysessionstorage, moon_component_http_message_session_storage_mockarraysessionstorage_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(moon_component_http_message_session_storage_mockarraysessionstorage_ce, SL("id"), "", ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_mockarraysessionstorage_ce, SL("name"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(moon_component_http_message_session_storage_mockarraysessionstorage_ce, SL("started"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(moon_component_http_message_session_storage_mockarraysessionstorage_ce, SL("closed"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_mockarraysessionstorage_ce, SL("data"), ZEND_ACC_PROTECTED);

	/**
	 * @var MetadataBag
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_mockarraysessionstorage_ce, SL("metadataBag"), ZEND_ACC_PROTECTED);

	/**
	 * @var array|SessionBagInterface[]
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_mockarraysessionstorage_ce, SL("bags"), ZEND_ACC_PROTECTED);

	moon_component_http_message_session_storage_mockarraysessionstorage_ce->create_object = zephir_init_properties_Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage;

	zend_class_implements(moon_component_http_message_session_storage_mockarraysessionstorage_ce, 1, moon_component_http_message_session_storage_sessionstorageinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *metaBag, metaBag_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&metaBag_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &metaBag);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "MOCKSESSID");
	} else {
		zephir_get_strval(&name, name_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmetadatabag", NULL, 0, metaBag);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, setSessionData) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *_array_param = NULL;
	zval _array;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_array);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_array_param);

	zephir_get_arrval(&_array, _array_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_array);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, start) {

	zval _0, _1, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("id"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "generateid", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("id"), &_2$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadsession", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, regenerate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *destroy_param = NULL, *lifetime_param = NULL, _0, _1, _2, _3;
	zend_bool destroy;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
	zephir_read_property(&_1, this_ptr, ZEND_STRL("metadataBag"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, lifetime);
	ZEPHIR_CALL_METHOD(NULL, &_1, "stampnew", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "generateid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("id"), &_3);
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, getId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "id");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, setId) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *id_param = NULL, _0;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_LogicException, "Cannot set session ID after the session has started.", "moon/Component/Http/Message/Session/Storage/MockArraySessionStorage.zep", 104);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("id"), &id);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, setName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, save) {

	zend_bool _1;
	zval __$true, __$false, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	_1 = !zephir_is_true(&_0);
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("closed"), PH_NOISY_CC | PH_READONLY);
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Trying to save a session that was not started yet or was already closed.", "moon/Component/Http/Message/Session/Storage/MockArraySessionStorage.zep", 131);
		return;
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("closed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("closed"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("started"), &__$false);
	}

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, clear) {

	zval bag, _0, *_1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "moon/Component/Http/Message/Session/Storage/MockArraySessionStorage.zep", 149);
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
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadsession", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, registerBag) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bag, bag_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bag_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bag);



	ZEPHIR_CALL_METHOD(&_0, bag, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("bags"), &_0, bag);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, getBag) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _4, _5, _6, _1$$3, _2$$3, _3$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
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
		zephir_throw_exception_debug(&_1$$3, "moon/Component/Http/Message/Session/Storage/MockArraySessionStorage.zep", 168);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("started"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_4)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "start", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &name, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/MockArraySessionStorage.zep", 173);
	RETURN_CTOR(&_6);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, isStarted) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "started");

}

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, setMetadataBag) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bag = NULL, bag_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bag_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bag);

	ZEPHIR_SEPARATE_PARAM(bag);


	if (Z_TYPE_P(bag) == IS_NULL) {
		ZEPHIR_INIT_NVAR(bag);
		object_init_ex(bag, moon_component_http_message_session_storage_metadatabag_ce);
		ZEPHIR_CALL_METHOD(NULL, bag, "__construct", NULL, 52);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("metadataBag"), bag);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the MetadataBag.
 *
 * @return MetadataBag
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, getMetadataBag) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "metadataBag");

}

/**
 * Generates a session ID.
 *
 * This doesn't need to be particularly cryptographically secure since this is just
 * a mock.
 *
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, generateId) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ss_mock_");
	ZEPHIR_CALL_FUNCTION(&_1, "uniqid", NULL, 53, &_0, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "sha256");
	ZEPHIR_RETURN_CALL_FUNCTION("hash", NULL, 54, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage, loadSession) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, key, bags, _0, _2, bag, *_3, _4, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&bags);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&bag);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("metadataBag"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&bags);
	zephir_fast_array_merge(&bags, &_0, &_1);
	zephir_is_iterable(&bags, 0, "moon/Component/Http/Message/Session/Storage/MockArraySessionStorage.zep", 226);
	if (Z_TYPE_P(&bags) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&bags), _3)
		{
			ZEPHIR_INIT_NVAR(&bag);
			ZVAL_COPY(&bag, _3);
			ZEPHIR_CALL_METHOD(&key, &bag, "getstoragekey", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_5$$3);
			zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_6$$3, &key)) {
				zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_5$$3);
				zephir_array_fetch(&_5$$3, &_7$$3, &key, PH_NOISY, "moon/Component/Http/Message/Session/Storage/MockArraySessionStorage.zep", 223);
			} else {
				ZEPHIR_INIT_NVAR(&_5$$3);
				array_init(&_5$$3);
			}
			zephir_update_property_array(this_ptr, SL("data"), &key, &_5$$3);
			zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_9$$3, &_8$$3, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/MockArraySessionStorage.zep", 224);
			ZEPHIR_CALL_METHOD(NULL, &bag, "initialize", NULL, 0, &_9$$3);
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
				ZEPHIR_INIT_NVAR(&_10$$4);
				zephir_read_property(&_11$$4, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_11$$4, &key)) {
					zephir_read_property(&_12$$4, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_10$$4);
					zephir_array_fetch(&_10$$4, &_12$$4, &key, PH_NOISY, "moon/Component/Http/Message/Session/Storage/MockArraySessionStorage.zep", 223);
				} else {
					ZEPHIR_INIT_NVAR(&_10$$4);
					array_init(&_10$$4);
				}
				zephir_update_property_array(this_ptr, SL("data"), &key, &_10$$4);
				zephir_read_property(&_13$$4, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_14$$4, &_13$$4, &key, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/MockArraySessionStorage.zep", 224);
				ZEPHIR_CALL_METHOD(NULL, &bag, "initialize", NULL, 0, &_14$$4);
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

zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Storage_MockArraySessionStorage(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("bags"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bags"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("data"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

