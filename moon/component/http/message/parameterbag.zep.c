
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


/**
 * FileName: ParameterBag.php
 * User: solely
 * DateTime: 2020/7/12 18:29
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_ParameterBag) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message, ParameterBag, moon, component_http_message_parameterbag, moon_component_http_message_parameterbag_method_entry, 0);

	/**
	 * Parameter storage.
	 */
	zend_declare_property_null(moon_component_http_message_parameterbag_ce, SL("parameters"), ZEND_ACC_PROTECTED);

	zend_class_implements(moon_component_http_message_parameterbag_ce, 1, zend_ce_aggregate);
	zend_class_implements(moon_component_http_message_parameterbag_ce, 1, spl_ce_Countable);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_ParameterBag, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *parameters_param = NULL;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &parameters);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the parameters.
 *
 * @return array An array of parameters
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, all) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "parameters");

}

/**
 * Returns the parameter keys.
 *
 * @return array An array of parameter keys
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, keys) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(return_value, &_0);
	return;

}

/**
 * Replaces the current parameters by a new set.
 * @param array $parameters
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, replace) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *parameters_param = NULL;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &parameters);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds parameters.
 * @param array $parameters
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, add) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, _0, _1;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "array_replace", NULL, 35, &_0, &parameters);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a parameter by name.
 * @param string $key
 * @param null $default The default value if the parameter key does not exist
 * @return mixed|null
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *_default = NULL, _default_sub, __$null, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &_default);

	zephir_get_strval(&key, key_param);
	if (!_default) {
		_default = &_default_sub;
		_default = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_1, &key)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &key, PH_NOISY, "moon/Component/Http/Message/ParameterBag.zep", 66);
	} else {
		ZEPHIR_CPY_WRT(&_0, _default);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Sets a parameter by name.
 * @param string $key
 * @param mixed $value The value
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	zephir_update_property_array(this_ptr, SL("parameters"), &key, value);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns true if the parameter is defined.
 * @param string $key
 * @return bool true if the parameter exists, false otherwise
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_key_exists(&_0, &key));

}

/**
 * Removes a parameter.
 * @param string $key
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, remove) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the alphabetic characters of the parameter value.
 * @param string $key
 * @param string $default
 * @return string|string[]|null  The filtered value
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getAlpha) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_default_param = NULL, _0, _1, _2;
	zval key, _default;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_default);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &_default_param);

	zephir_get_strval(&key, key_param);
	if (!_default_param) {
		ZEPHIR_INIT_VAR(&_default);
		ZVAL_STRING(&_default, "");
	} else {
		zephir_get_strval(&_default, _default_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &key, &_default);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/[^[:alpha:]]/");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 36, &_1, &_2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the alphabetic characters and digits of the parameter value.
 * @param string $key
 * @param string $default
 * @return string|string[]|null The filtered value
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getAlnum) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_default_param = NULL, _0, _1, _2;
	zval key, _default;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_default);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &_default_param);

	zephir_get_strval(&key, key_param);
	if (!_default_param) {
		ZEPHIR_INIT_VAR(&_default);
		ZVAL_STRING(&_default, "");
	} else {
		zephir_get_strval(&_default, _default_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &key, &_default);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/[^[:alnum:]]/");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 36, &_1, &_2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the digits of the parameter value.
 * @param string $key
 * @param string $default
 * @return mixed  The filtered value
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getDigits) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_default_param = NULL, _1, _2, _3, _4;
	zval key, _default;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_default);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &_default_param);

	zephir_get_strval(&key, key_param);
	if (!_default_param) {
		ZEPHIR_INIT_VAR(&_default);
		ZVAL_STRING(&_default, "");
	} else {
		zephir_get_strval(&_default, _default_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, '-');
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_LONG(&_1, '+');
	zephir_array_fast_append(&_0, &_1);
	ZVAL_LONG(&_3, 519);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "filter", NULL, 0, &key, &_default, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_str_replace(&_4, &_0, &_1, &_2);
	RETURN_CCTOR(&_4);

}

/**
 * Returns the parameter value converted to integer.
 * @param string $key
 * @param int $default
 * @return int The filtered value
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getInt) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long _default, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_default_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &_default_param);

	zephir_get_strval(&key, key_param);
	if (!_default_param) {
		_default = 0;
	} else {
		_default = zephir_get_intval(_default_param);
	}


	ZVAL_LONG(&_1, _default);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &key, &_1);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(&_0));

}

/**
 * Returns the parameter value converted to boolean.
 * @param string $key
 * @param bool $default
 * @return mixed The filtered value
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getBoolean) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool _default;
	zval *key_param = NULL, *_default_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &_default_param);

	zephir_get_strval(&key, key_param);
	if (!_default_param) {
		_default = 0;
	} else {
		_default = zephir_get_boolval(_default_param);
	}


	if (_default) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZVAL_LONG(&_1, 258);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filter", NULL, 0, &key, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Filter key.
 * @param string $key
 * @param null $default  Default = null
 * @param int $filter    FILTER_* constant
 * @param array $options Filter options
 *
 * @see https://php.net/filter-var
 *
 * @return mixed
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, filter) {

	zend_bool _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long filter, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_default = NULL, _default_sub, *filter_param = NULL, *options = NULL, options_sub, __$null, value, _4, _1$$3, _3$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &key_param, &_default, &filter_param, &options);

	zephir_get_strval(&key, key_param);
	if (!_default) {
		_default = &_default_sub;
		_default = &__$null;
	}
	if (!filter_param) {
		filter = -1;
	} else {
		filter = zephir_get_intval(filter_param);
	}
	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	ZEPHIR_CALL_METHOD(&value, this_ptr, "get", NULL, 0, &key, _default);
	zephir_check_call_status();
	_0 = !(Z_TYPE_P(options) == IS_ARRAY);
	if (_0) {
		_0 = !(ZEPHIR_IS_EMPTY(options));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0);
		zephir_array_update_string(&_1$$3, SL("flags"), options, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(options, &_1$$3);
	}
	_2 = Z_TYPE_P(&value) == IS_ARRAY;
	if (_2) {
		_2 = !(zephir_array_isset_string(options, SL("flags")));
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_LONG(&_3$$4, 16777216);
		zephir_array_update_string(options, SL("flags"), &_3$$4, PH_COPY | PH_SEPARATE);
	}
	if (filter <= 0) {
		filter = 516;
	}
	ZVAL_LONG(&_4, filter);
	ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 17, &value, &_4, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an iterator for parameters.
 * @return \ArrayIterator|\Traversable
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, getIterator) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SL("arrayiterator")));
	zephir_read_property(&_0, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 37, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the number of parameters.
 *
 * @return int The number of parameters
 */
PHP_METHOD(Moon_Component_Http_Message_ParameterBag, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("parameters"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));

}

