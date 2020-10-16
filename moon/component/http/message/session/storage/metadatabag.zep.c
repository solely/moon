
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
#include "kernel/time.h"
#include "kernel/fcall.h"


/**
 * FileName: MetadataBag.php
 * User: solely
 * DateTime: 2020/9/7 23:46
 * Description:
 */
/**
 * Metadata container.
 *
 * Adds metadata to the session.
 *
 * Class MetadataBag
 * @package Moon\Component\Http\Message\Session\Storage
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_MetadataBag) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session\\Storage, MetadataBag, moon, component_http_message_session_storage_metadatabag, moon_component_http_message_session_storage_metadatabag_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(moon_component_http_message_session_storage_metadatabag_ce, SL("name"), "__metadata", ZEND_ACC_PRIVATE);

	/**
	 * @var string
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_metadatabag_ce, SL("storageKey"), ZEND_ACC_PRIVATE);

	/**
	 * @var array
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_metadatabag_ce, SL("meta"), ZEND_ACC_PROTECTED);

	/**
	 * Unix timestamp.
	 *
	 * @var int
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_metadatabag_ce, SL("lastUsed"), ZEND_ACC_PRIVATE);

	/**
	 * @var int
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_metadatabag_ce, SL("updateThreshold"), ZEND_ACC_PRIVATE);

	moon_component_http_message_session_storage_metadatabag_ce->create_object = zephir_init_properties_Moon_Component_Http_Message_Session_Storage_MetadataBag;
	zephir_declare_class_constant_string(moon_component_http_message_session_storage_metadatabag_ce, SL("CREATED"), "c");

	zephir_declare_class_constant_string(moon_component_http_message_session_storage_metadatabag_ce, SL("UPDATED"), "u");

	zephir_declare_class_constant_string(moon_component_http_message_session_storage_metadatabag_ce, SL("LIFETIME"), "l");

	zend_class_implements(moon_component_http_message_session_storage_metadatabag_ce, 1, moon_component_http_message_session_sessionbaginterface_ce);
	return SUCCESS;

}

/**
 * @param string $storageKey      The key used to store bag in the session
 * @param int    $updateThreshold The time to wait between two UPDATED updates
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long updateThreshold;
	zval *storageKey_param = NULL, *updateThreshold_param = NULL, _0;
	zval storageKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&storageKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &storageKey_param, &updateThreshold_param);

	if (!storageKey_param) {
		ZEPHIR_INIT_VAR(&storageKey);
		ZVAL_STRING(&storageKey, "_moons_meta");
	} else {
		zephir_get_strval(&storageKey, storageKey_param);
	}
	if (!updateThreshold_param) {
		updateThreshold = 0;
	} else {
		updateThreshold = zephir_get_intval(updateThreshold_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("storageKey"), &storageKey);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, updateThreshold);
	zephir_update_property_zval(this_ptr, ZEND_STRL("updateThreshold"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, initialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_array_param = NULL, timeStamp, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$4;
	zval _array;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_array);
	ZVAL_UNDEF(&timeStamp);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_array_param);

	zephir_get_arrval(&_array, _array_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("meta"), &_array);
	if (zephir_array_isset_string(&_array, SL("c"))) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("meta"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_1$$3, &_0$$3, SL("u"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/MetadataBag.zep", 65);
		zephir_update_property_zval(this_ptr, ZEND_STRL("lastUsed"), &_1$$3);
		ZEPHIR_INIT_VAR(&timeStamp);
		zephir_time(&timeStamp);
		zephir_array_fetch_string(&_2$$3, &_array, SL("u"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/MetadataBag.zep", 67);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_sub_function(&_3$$3, &timeStamp, &_2$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("updateThreshold"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_GE(&_3$$3, &_4$$3)) {
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "u");
			zephir_update_property_array(this_ptr, SL("meta"), &_5$$4, &timeStamp);
		}
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "stampcreated", NULL, 234);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the lifetime that the session cookie was set with.
 *
 * @return int
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, getLifetime) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("meta"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("l"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/MetadataBag.zep", 82);
	RETURN_CTORW(&_1);

}

/**
 * Stamps a new session's metadata.
 *
 * @param int $lifetime Sets the cookie lifetime for the session cookie. A null value
 *                      will leave the system settings unchanged, 0 sets the cookie
 *                      to expire with browser session. Time is in seconds, and is
 *                      not a Unix timestamp.
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, stampNew) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *lifetime_param = NULL, _0;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &lifetime_param);

	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZVAL_LONG(&_0, lifetime);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "stampcreated", NULL, 234, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, getStorageKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "storageKey");

}

/**
 * Gets the created timestamp metadata.
 *
 * @return int Unix timestamp
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, getCreated) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("meta"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("c"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/MetadataBag.zep", 113);
	RETURN_CTORW(&_1);

}

/**
 * Gets the last used metadata.
 *
 * @return int Unix timestamp
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, getLastUsed) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "lastUsed");

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, clear) {

	zval *this_ptr = getThis();



}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * Sets name.
 * @param string $name
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, setName) {

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

PHP_METHOD(Moon_Component_Http_Message_Session_Storage_MetadataBag, stampCreated) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *lifetime_param = NULL, timeStamp, _0, _1, _2, _3;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&timeStamp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &lifetime_param);

	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZEPHIR_INIT_VAR(&timeStamp);
	zephir_time(&timeStamp);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "c");
	zephir_update_property_array(this_ptr, SL("meta"), &_0, &timeStamp);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "u");
	zephir_update_property_array(this_ptr, SL("meta"), &_1, &timeStamp);
	zephir_update_property_zval(this_ptr, ZEND_STRL("lastUsed"), &timeStamp);
	ZEPHIR_INIT_VAR(&_2);
	if (0 == lifetime) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "session.cookie_lifetime");
		ZEPHIR_CALL_FUNCTION(&_2, "ini_get", NULL, 13, &_3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_LONG(&_2, lifetime);
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "l");
	zephir_update_property_array(this_ptr, SL("meta"), &_3, &_2);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Storage_MetadataBag(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("meta"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 3, 0);
			add_assoc_long_ex(&_1$$3, SL("c"), 0);
			add_assoc_long_ex(&_1$$3, SL("u"), 0);
			add_assoc_long_ex(&_1$$3, SL("l"), 0);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("meta"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

