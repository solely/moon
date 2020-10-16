
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * FileName: NamespacedAttributeBag.php
 * User: solely
 * DateTime: 2020/9/6 23:54
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Session\\Attribute, NamespacedAttributeBag, moon, component_http_message_session_attribute_namespacedattributebag, moon_component_http_message_session_attribute_attributebag_ce, moon_component_http_message_session_attribute_namespacedattributebag_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_session_attribute_namespacedattributebag_ce, SL("namespaceCharacter"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * @param string $storageKey         Session storage key
 * @param string $namespaceCharacter Namespace character to use in keys
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *storageKey_param = NULL, *namespaceCharacter_param = NULL;
	zval storageKey, namespaceCharacter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&storageKey);
	ZVAL_UNDEF(&namespaceCharacter);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &storageKey_param, &namespaceCharacter_param);

	if (!storageKey_param) {
		ZEPHIR_INIT_VAR(&storageKey);
		ZVAL_STRING(&storageKey, "_moons_attributes");
	} else {
		zephir_get_strval(&storageKey, storageKey_param);
	}
	if (!namespaceCharacter_param) {
		ZEPHIR_INIT_VAR(&namespaceCharacter);
		ZVAL_STRING(&namespaceCharacter, "/");
	} else {
		zephir_get_strval(&namespaceCharacter, namespaceCharacter_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("namespaceCharacter"), &namespaceCharacter);
	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_session_attribute_namespacedattributebag_ce, getThis(), "__construct", &_0, 0, &storageKey);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name, *name_param = NULL, attributes, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "resolveattributepath", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvekey", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&name, &_0);
	if (Z_TYPE_P(&attributes) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(zephir_array_key_exists(&attributes, &name));

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name, *name_param = NULL, *_default = NULL, _default_sub, __$null, attributes, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &_default);

	zephir_get_strval(&name, name_param);
	if (!_default) {
		_default = &_default_sub;
		_default = &__$null;
	}


	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "resolveattributepath", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvekey", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&name, &_0);
	if (Z_TYPE_P(&attributes) == IS_NULL) {
		RETVAL_ZVAL(_default, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_array_key_exists(&attributes, &name)) {
		zephir_array_fetch(&_1, &attributes, &name, PH_NOISY, "moon/Component/Http/Message/Session/Attribute/NamespacedAttributeBag.zep", 51);
	} else {
		ZEPHIR_CPY_WRT(&_1, _default);
	}
	RETURN_CCTOR(&_1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name, *name_param = NULL, *value, value_sub, attributes, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	ZVAL_BOOL(&_0, 1);
	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "resolveattributepath", NULL, 0, &name, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolvekey", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&name, &_1);
	zephir_array_update_zval(&attributes, &name, value, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_2, &_0, &attributes);
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &_2);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, remove) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name, *name_param = NULL, retval, attributes, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&retval);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&retval);
	ZVAL_NULL(&retval);
	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "resolveattributepath", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "resolvekey", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&name, &_0);
	_1 = Z_TYPE_P(&attributes) != IS_NULL;
	if (_1) {
		_1 = zephir_array_key_exists(&attributes, &name);
	}
	if (_1) {
		ZEPHIR_OBS_NVAR(&retval);
		zephir_array_fetch(&retval, &attributes, &name, PH_NOISY, "moon/Component/Http/Message/Session/Attribute/NamespacedAttributeBag.zep", 79);
		zephir_array_unset(&attributes, &name, PH_SEPARATE);
		zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	}
	RETURN_CCTOR(&retval);

}

/**
 * Resolves a path in attributes property and returns it as a reference.
 *
 * This method allows structured namespacing of session attributes.
 *
 * @param string $name         Key name
 * @param bool   $writeContext Write context, default false
 *
 * @return array|null
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, resolveAttributePath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool writeContext, _9$$6, _10$$9;
	zval name, *name_param = NULL, *writeContext_param = NULL, evalStr, item, partLink, parts, _array, _0, _1, _2, _3, _4, part, *_7, _8, _5$$4, _6$$4, *_11$$12, _12$$12, _15$$12, _13$$13, _14$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&evalStr);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&partLink);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_array);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$14);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &writeContext_param);

	zephir_get_strval(&name, name_param);
	if (!writeContext_param) {
		writeContext = 0;
	} else {
		writeContext = zephir_get_boolval(writeContext_param);
	}


	ZEPHIR_OBS_VAR(&_array);
	zephir_read_property(&_array, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("namespaceCharacter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strpos(&_2, &name, &_1, 0 );
	if (ZEPHIR_IS_LONG_IDENTICAL(&_2, 0)) {
		ZVAL_LONG(&_3, 1);
		ZEPHIR_INIT_NVAR(&_0);
		zephir_substr(&_0, &name, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else {
		ZEPHIR_CPY_WRT(&_0, &name);
	}
	ZEPHIR_CPY_WRT(&name, &_0);
	if (!zephir_is_true(&name)) {
		RETURN_CCTOR(&_array);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("namespaceCharacter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode(&parts, &_4, &name, LONG_MAX);
	if (zephir_fast_count_int(&parts) < 2) {
		if (!writeContext) {
			RETURN_CCTOR(&_array);
		}
		ZEPHIR_INIT_VAR(&_5$$4);
		array_init(&_5$$4);
		ZEPHIR_OBS_VAR(&_6$$4);
		zephir_array_fetch_long(&_6$$4, &parts, 0, PH_NOISY, "moon/Component/Http/Message/Session/Attribute/NamespacedAttributeBag.zep", 115);
		zephir_array_update_zval(&_array, &_6$$4, &_5$$4, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &_array);
		RETURN_CCTOR(&_array);
	}
	zephir_array_unset_long(&parts, (zephir_fast_count_int(&parts) - 1), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&partLink);
	array_init(&partLink);
	zephir_is_iterable(&parts, 0, "moon/Component/Http/Message/Session/Attribute/NamespacedAttributeBag.zep", 136);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _7)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _7);
			_9$$6 = Z_TYPE_P(&_array) != IS_NULL;
			if (_9$$6) {
				_9$$6 = !(zephir_array_key_exists(&_array, &part));
			}
			if (_9$$6) {
				if (!writeContext) {
					RETURN_MM_NULL();
				}
				zephir_array_append(&partLink, &part, PH_SEPARATE, "moon/Component/Http/Message/Session/Attribute/NamespacedAttributeBag.zep", 130);
				break;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				_10$$9 = Z_TYPE_P(&_array) != IS_NULL;
				if (_10$$9) {
					_10$$9 = !(zephir_array_key_exists(&_array, &part));
				}
				if (_10$$9) {
					if (!writeContext) {
						RETURN_MM_NULL();
					}
					zephir_array_append(&partLink, &part, PH_SEPARATE, "moon/Component/Http/Message/Session/Attribute/NamespacedAttributeBag.zep", 130);
					break;
				}
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	if (!(ZEPHIR_IS_EMPTY(&partLink))) {
		ZEPHIR_INIT_VAR(&evalStr);
		ZVAL_STRING(&evalStr, "$_array");
		zephir_is_iterable(&parts, 0, "moon/Component/Http/Message/Session/Attribute/NamespacedAttributeBag.zep", 141);
		if (Z_TYPE_P(&parts) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _11$$12)
			{
				ZEPHIR_INIT_NVAR(&item);
				ZVAL_COPY(&item, _11$$12);
				ZEPHIR_INIT_NVAR(&_13$$13);
				ZEPHIR_CONCAT_SVS(&_13$$13, "[", &item, "]");
				zephir_concat_self(&evalStr, &_13$$13);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_12$$12, &parts, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$12)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&item, &parts, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_14$$14);
					ZEPHIR_CONCAT_SVS(&_14$$14, "[", &item, "]");
					zephir_concat_self(&evalStr, &_14$$14);
				ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&item);
		zephir_concat_self_str(&evalStr, SL(" = 0;"));
		ZEPHIR_INIT_VAR(&_15$$12);
		zephir_eval_php(&evalStr, &_15$$12, "moon/Component/Http/Message/Session/Attribute/NamespacedAttributeBag.zep:142");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &_array);
	RETURN_CCTOR(&_array);

}

/**
 * Resolves the key from the name.
 *
 * This is the last part in a dot separated string.
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Attribute_NamespacedAttributeBag, resolveKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name, *name_param = NULL, pos, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("namespaceCharacter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&pos, "strrpos", NULL, 120, &name, &_0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
		ZVAL_LONG(&_1$$3, (zephir_get_numberval(&pos) + 1));
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_substr(&_2$$3, &name, zephir_get_intval(&_1$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CPY_WRT(&name, &_2$$3);
	}
	RETURN_CCTOR(&name);

}

