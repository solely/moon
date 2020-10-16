
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * FileName: AutoExpireFlashBag.php
 * User: solely
 * DateTime: 2020/9/7 0:00
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session\\Flash, AutoExpireFlashBag, moon, component_http_message_session_flash_autoexpireflashbag, moon_component_http_message_session_flash_autoexpireflashbag_method_entry, 0);

	zend_declare_property_string(moon_component_http_message_session_flash_autoexpireflashbag_ce, SL("name"), "flashes", ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_flash_autoexpireflashbag_ce, SL("flashes"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_flash_autoexpireflashbag_ce, SL("storageKey"), ZEND_ACC_PRIVATE);

	moon_component_http_message_session_flash_autoexpireflashbag_ce->create_object = zephir_init_properties_Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag;

	zend_class_implements(moon_component_http_message_session_flash_autoexpireflashbag_ce, 1, moon_component_http_message_session_flash_flashbaginterface_ce);
	return SUCCESS;

}

/**
 * @param string $storageKey The key used to store flashes in the session
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *storageKey_param = NULL;
	zval storageKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&storageKey);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &storageKey_param);

	if (!storageKey_param) {
		ZEPHIR_INIT_VAR(&storageKey);
		ZVAL_STRING(&storageKey, "_moon_flashes");
	} else {
		zephir_get_strval(&storageKey, storageKey_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("storageKey"), &storageKey);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, setName) {

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
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, initialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *flashes_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zval flashes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&flashes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &flashes_param);

	zephir_get_arrval(&flashes, flashes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("flashes"), &flashes);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "new");
	if (zephir_array_key_exists(&_1, &_2)) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch_string(&_0, &_3, SL("new"), PH_NOISY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 46);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		array_init(&_0);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "display");
	zephir_update_property_array(this_ptr, SL("flashes"), &_4, &_0);
	ZEPHIR_INIT_VAR(&_5);
	array_init(&_5);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "new");
	zephir_update_property_array(this_ptr, SL("flashes"), &_6, &_5);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, add) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, *message, message_sub;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message);

	zephir_get_strval(&type, type_param);


	zephir_update_property_array_multi(this_ptr, SL("flashes"), message, SL("sza"), 4, SL("new"), &type);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, peek) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _default;
	zval *type_param = NULL, *_default_param = NULL, _0, _1, _2, _3;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_default);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &type_param, &_default_param);

	zephir_get_strval(&type, type_param);
	if (!_default_param) {
		ZEPHIR_INIT_VAR(&_default);
		array_init(&_default);
	} else {
		zephir_get_arrval(&_default, _default_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "has", NULL, 0, &type);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3, &_2, SL("display"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 63);
		zephir_array_fetch(&_0, &_3, &type, PH_NOISY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 63);
	} else {
		ZEPHIR_CPY_WRT(&_0, &_default);
	}
	RETURN_CCTOR(&_0);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, peekAll) {

	zval _5;
	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "display");
	if (zephir_array_key_exists(&_1, &_2)) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_4);
		zephir_array_fetch_string(&_4, &_3, SL("display"), PH_NOISY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 71);
		zephir_get_arrval(&_5, &_4);
		ZEPHIR_CPY_WRT(&_0, &_5);
	} else {
		array_init(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _default;
	zval *type_param = NULL, *_default_param = NULL, _return, _0, _1, _2, _3$$4, _4$$4, _5$$4, _6$$4;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_return);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_default);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &type_param, &_default_param);

	zephir_get_strval(&type, type_param);
	if (!_default_param) {
		ZEPHIR_INIT_VAR(&_default);
		array_init(&_default);
	} else {
		zephir_get_arrval(&_default, _default_param);
	}


	ZEPHIR_CPY_WRT(&_return, &_default);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &type);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		RETURN_CCTOR(&_return);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("display"), PH_READONLY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 84);
	if (zephir_array_isset(&_2, &type)) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_4$$4, &_3$$4, SL("display"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 85);
		ZEPHIR_OBS_NVAR(&_return);
		zephir_array_fetch(&_return, &_4$$4, &type, PH_NOISY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 85);
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_6$$4, &_5$$4, SL("display"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 86);
		zephir_array_unset(&_6$$4, &type, PH_SEPARATE);
	}
	RETURN_CCTOR(&_return);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, all) {

	zval _return, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_return);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_return, &_0, SL("display"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 97);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "display");
	zephir_update_property_array(this_ptr, SL("flashes"), &_2, &_1);
	RETURN_CTOR(&_return);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, setAll) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *messages_param = NULL, _0;
	zval messages;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages_param);

	zephir_get_arrval(&messages, messages_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "new");
	zephir_update_property_array(this_ptr, SL("flashes"), &_0, &messages);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, set) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, *messages, messages_sub;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&messages_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &messages);

	zephir_get_strval(&type, type_param);


	zephir_get_arrval(&_0, messages);
	zephir_update_property_array_multi(this_ptr, SL("flashes"), &_0, SL("sz"), 3, SL("new"), &type);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, has) {

	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, _0, _1, _3, _4, _5;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("display"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 123);
	_2 = zephir_array_key_exists(&_1, &type);
	if (_2) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_4, &_3, SL("display"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 123);
		zephir_array_fetch(&_5, &_4, &type, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 123);
		_2 = zephir_is_true(&_5);
	}
	RETURN_MM_BOOL(_2);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, keys) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("display"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Flash/AutoExpireFlashBag.zep", 131);
	zephir_array_keys(return_value, &_1);
	return;

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, getStorageKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "storageKey");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag, clear) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Flash_AutoExpireFlashBag(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 2, 0);
			ZEPHIR_INIT_VAR(&_2$$3);
			array_init(&_2$$3);
			zephir_array_update_string(&_1$$3, SL("display"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			array_init(&_2$$3);
			zephir_array_update_string(&_1$$3, SL("new"), &_2$$3, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("flashes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

