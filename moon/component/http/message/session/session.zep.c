
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/spl/spl_iterators.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/**
 * FileName: Session.php
 * User: solely
 * DateTime: 2020/9/13 23:31
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Session) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session, Session, moon, component_http_message_session_session, moon_component_http_message_session_session_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_session_session_ce, SL("storage"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_session_session_ce, SL("flashName"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_session_ce, SL("attributeName"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_session_ce, SL("data"), ZEND_ACC_PRIVATE);

	zend_declare_property_long(moon_component_http_message_session_session_ce, SL("usageIndex"), 0, ZEND_ACC_PRIVATE);

	moon_component_http_message_session_session_ce->create_object = zephir_init_properties_Moon_Component_Http_Message_Session_Session;

	zend_class_implements(moon_component_http_message_session_session_ce, 1, moon_component_http_message_session_sessioninterface_ce);
	zend_class_implements(moon_component_http_message_session_session_ce, 1, zend_ce_aggregate);
	zend_class_implements(moon_component_http_message_session_session_ce, 1, spl_ce_Countable);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Session_Session, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *storage, storage_sub, *attributes = NULL, attributes_sub, *flashes = NULL, flashes_sub, _0, _1, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&storage_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_UNDEF(&flashes_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &storage, &attributes, &flashes);

	ZEPHIR_SEPARATE_PARAM(attributes);
	ZEPHIR_SEPARATE_PARAM(flashes);


	ZEPHIR_INIT_VAR(&_0);
	if (!(zephir_is_true(storage))) {
		ZEPHIR_INIT_NVAR(&_0);
		object_init_ex(&_0, moon_component_http_message_session_storage_nativesessionstorage_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 202);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_0, storage);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("storage"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (!(zephir_is_true(attributes))) {
		ZEPHIR_INIT_NVAR(&_1);
		object_init_ex(&_1, moon_component_http_message_session_attribute_attributebag_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 203);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_1, attributes);
	}
	ZEPHIR_CPY_WRT(attributes, &_1);
	ZEPHIR_CALL_METHOD(&_2, attributes, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributeName"), &_2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerbag", &_3, 0, attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	if (!(zephir_is_true(flashes))) {
		ZEPHIR_INIT_NVAR(&_1);
		object_init_ex(&_1, moon_component_http_message_session_flash_flashbag_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 204);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_1, flashes);
	}
	ZEPHIR_CPY_WRT(flashes, &_1);
	ZEPHIR_CALL_METHOD(&_4, flashes, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("flashName"), &_4);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerbag", &_3, 0, flashes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, start) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "start", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, has) {

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributebag", NULL, 205);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_default = NULL, _default_sub, __$null, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &_default);

	zephir_get_strval(&name, name_param);
	if (!_default) {
		_default = &_default_sub;
		_default = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributebag", NULL, 205);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &name, _default);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributebag", NULL, 205);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &name, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, all) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributebag", NULL, 205);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "all", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, replace) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, _0;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	zephir_get_arrval(&attributes, attributes_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributebag", NULL, 205);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "replace", NULL, 0, &attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, remove) {

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributebag", NULL, 205);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "remove", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, clear) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributebag", NULL, 205);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, isStarted) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "isstarted", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an iterator for attributes.
 *
 * @return \ArrayIterator An \ArrayIterator instance
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getIterator) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SL("arrayiterator")));
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributebag", NULL, 205);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "all", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 37, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the number of attributes.
 *
 * @return int
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, count) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getattributebag", NULL, 205);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "all", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(&_1));

}

PHP_METHOD(Moon_Component_Http_Message_Session_Session, getUsageIndex) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "usageIndex");

}

/**
 * @internal
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, isEmpty) {

	zval _0, data, _3, *_4, _5, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isstarted", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_LONG(&_2$$3, 1);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("usageIndex"), PH_NOISY_CC);
		ZEPHIR_ADD_ASSIGN(&_1$$3, &_2$$3)
		zephir_update_property_zval(this_ptr, ZEND_STRL("usageIndex"), &_1$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "moon/Component/Http/Message/Session/Session.zep", 149);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&data);
			ZVAL_COPY(&data, _4);
			if (!(ZEPHIR_IS_EMPTY(&data))) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&data, &_3, "current", NULL, 0);
			zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&data))) {
					RETURN_MM_BOOL(0);
				}
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&data);
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, invalidate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *lifetime_param = NULL, _0, _1, _2;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &lifetime_param);

	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "clear", NULL, 0);
	zephir_check_call_status();
	ZVAL_BOOL(&_1, 1);
	ZVAL_LONG(&_2, lifetime);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "migrate", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, migrate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *destroy_param = NULL, *lifetime_param = NULL, _0, _1, _2;
	zend_bool destroy;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	if (destroy) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZVAL_LONG(&_2, lifetime);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "regenerate", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, save) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "save", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getId) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, setId) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, _0, _1, _2$$3;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getid", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_1, &id)) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "setid", NULL, 0, &id);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getName) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getname", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, setName) {

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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setname", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getMetadataBag) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("usageIndex"), PH_NOISY_CC);
	ZEPHIR_ADD_ASSIGN(&_0, &_1)
	zephir_update_property_zval(this_ptr, ZEND_STRL("usageIndex"), &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getmetadatabag", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, registerBag) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bag, bag_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bag_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bag);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, moon_component_http_message_session_sessionbagproxy_ce);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("usageIndex"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 206, bag, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "registerbag", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getBag) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, bag, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&bag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("storage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&bag, &_0, "getbag", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if ((zephir_method_exists_ex(&bag, ZEND_STRL("getbag")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_1, &bag, "getbag", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_1, &bag);
	}
	RETURN_CCTOR(&_1);

}

/**
 * Gets the flashbag interface.
 *
 * @return FlashBagInterface
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getFlashBag) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("flashName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbag", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the attributebag interface.
 *
 * Note that this method was added to help with IDE autocompletion.
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Session, getAttributeBag) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributeName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbag", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Session(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("data"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

