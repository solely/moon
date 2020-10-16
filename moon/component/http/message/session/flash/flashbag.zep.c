
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
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * FileName: FlashBag.php
 * User: solely
 * DateTime: 2020/9/6 23:59
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Flash_FlashBag) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session\\Flash, FlashBag, moon, component_http_message_session_flash_flashbag, moon_component_http_message_session_flash_flashbag_method_entry, 0);

	zend_declare_property_string(moon_component_http_message_session_flash_flashbag_ce, SL("name"), "flashes", ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_flash_flashbag_ce, SL("flashes"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_flash_flashbag_ce, SL("storageKey"), ZEND_ACC_PRIVATE);

	moon_component_http_message_session_flash_flashbag_ce->create_object = zephir_init_properties_Moon_Component_Http_Message_Session_Flash_FlashBag;

	zend_class_implements(moon_component_http_message_session_flash_flashbag_ce, 1, moon_component_http_message_session_flash_flashbaginterface_ce);
	return SUCCESS;

}

/**
 * @param string $storageKey The key used to store flashes in the session
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, __construct) {

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
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, setName) {

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
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, initialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *flashes_param = NULL;
	zval flashes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&flashes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &flashes_param);

	zephir_get_arrval(&flashes, flashes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("flashes"), &flashes);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, add) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, *message, message_sub;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message);

	zephir_get_strval(&type, type_param);


	zephir_update_property_array_multi(this_ptr, SL("flashes"), message, SL("za"), 2, &type);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, peek) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _default;
	zval *type_param = NULL, *_default_param = NULL, _0, _1, _2;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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
		zephir_array_fetch(&_0, &_2, &type, PH_NOISY, "moon/Component/Http/Message/Session/Flash/FlashBag.zep", 58);
	} else {
		ZEPHIR_CPY_WRT(&_0, &_default);
	}
	RETURN_CCTOR(&_0);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, peekAll) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "flashes");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _default;
	zval *type_param = NULL, *_default_param = NULL, _return, _0, _1, _2;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_return);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &type);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		RETURN_CTOR(&_default);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_return, &_1, &type, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Flash/FlashBag.zep", 78);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_2, &type, PH_SEPARATE);
	RETURN_CTOR(&_return);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, all) {

	zval _return, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_return);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_return, this_ptr, "peekall", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("flashes"), &_0);
	RETURN_CCTOR(&_return);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, set) {

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
	zephir_update_property_array(this_ptr, SL("flashes"), &type, &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, setAll) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *messages_param = NULL;
	zval messages;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages_param);

	zephir_get_arrval(&messages, messages_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("flashes"), &messages);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, has) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, _0, _2, _3;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_key_exists(&_0, &type);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3, &_2, &type, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Flash/FlashBag.zep", 115);
		_1 = zephir_is_true(&_3);
	}
	RETURN_MM_BOOL(_1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, keys) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(return_value, &_0);
	return;

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, getStorageKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "storageKey");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBag, clear) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Flash_FlashBag(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("flashes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("flashes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

