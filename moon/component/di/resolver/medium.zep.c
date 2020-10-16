
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * FileName: Medium.php
 * User: solely
 * DateTime: 2019/6/23 22:20
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_Medium) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI\\Resolver, Medium, moon, component_di_resolver_medium, moon_component_di_resolver_medium_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(moon_component_di_resolver_medium_ce, SL("className"), ZEND_ACC_PRIVATE);

	/**
	 * @var array
	 */
	zend_declare_property_null(moon_component_di_resolver_medium_ce, SL("params"), ZEND_ACC_PRIVATE);

	/**
	 * @var array
	 */
	zend_declare_property_null(moon_component_di_resolver_medium_ce, SL("setters"), ZEND_ACC_PRIVATE);

	/**
	 * @var array
	 */
	zend_declare_property_null(moon_component_di_resolver_medium_ce, SL("mutations"), ZEND_ACC_PRIVATE);

	/**
	 * @var bool
	 */
	zend_declare_property_null(moon_component_di_resolver_medium_ce, SL("isLazy"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * Medium constructor.
 * @param string $className
 * @param array $arguments
 * @param array $callMethods
 * @param array $mutations
 * @param bool $isLazy
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool isLazy;
	zval arguments, callMethods, mutations;
	zval *className_param = NULL, *arguments_param = NULL, *callMethods_param = NULL, *isLazy_param = NULL, *mutations_param = NULL, __$true, __$false;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&callMethods);
	ZVAL_UNDEF(&mutations);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &className_param, &arguments_param, &callMethods_param, &isLazy_param, &mutations_param);

	zephir_get_strval(&className, className_param);
	if (!arguments_param) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
	} else {
		zephir_get_arrval(&arguments, arguments_param);
	}
	if (!callMethods_param) {
		ZEPHIR_INIT_VAR(&callMethods);
		array_init(&callMethods);
	} else {
		zephir_get_arrval(&callMethods, callMethods_param);
	}
	if (!isLazy_param) {
		isLazy = 1;
	} else {
		isLazy = zephir_get_boolval(isLazy_param);
	}
	if (!mutations_param) {
		ZEPHIR_INIT_VAR(&mutations);
		array_init(&mutations);
	} else {
		zephir_get_arrval(&mutations, mutations_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("className"), &className);
	zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &arguments);
	zephir_update_property_zval(this_ptr, ZEND_STRL("setters"), &callMethods);
	zephir_update_property_zval(this_ptr, ZEND_STRL("mutations"), &mutations);
	if (isLazy) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isLazy"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isLazy"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *
 * Instantiates a new object based on the current blueprint.
 *
 * @param ReflectionClass $reflectedClass
 *
 * @return object
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, __invoke) {

	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *reflectedClass, reflectedClass_sub, _object, _0, _1, _2, method, value, className_1, _3, *_4, _5, _8$$4, _10$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflectedClass_sub);
	ZVAL_UNDEF(&_object);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&className_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &reflectedClass);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, moon_0__closure_ce, SL("__invoke"));
	zephir_read_property(&_1, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_2, "array_map", NULL, 83, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_object, reflectedClass, "newinstanceargs", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&className_1);
	zephir_read_property(&className_1, this_ptr, ZEND_STRL("className"), PH_NOISY_CC);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "moon/Component/DI/Resolver/Medium.zep", 86);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&method);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&method, _7);
			} else {
				ZVAL_LONG(&method, _6);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _4);
			if (!((zephir_method_exists(&className_1, &method)  == SUCCESS))) {
				ZEPHIR_CALL_CE_STATIC(&_8$$4, moon_component_di_exception_ce, "resolvercallmethodnotfound", &_9, 0, &className_1, &method);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$4, "moon/Component/DI/Resolver/Medium.zep", 80);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_ZVAL(NULL, &_object, &method, NULL, 0, &value);
			zephir_check_call_status();
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
			ZEPHIR_CALL_METHOD(&method, &_3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_3, "current", NULL, 0);
			zephir_check_call_status();
				if (!((zephir_method_exists(&className_1, &method)  == SUCCESS))) {
					ZEPHIR_CALL_CE_STATIC(&_10$$6, moon_component_di_exception_ce, "resolvercallmethodnotfound", &_9, 0, &className_1, &method);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$6, "moon/Component/DI/Resolver/Medium.zep", 80);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_ZVAL(NULL, &_object, &method, NULL, 0, &value);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&method);
	RETURN_CCTOR(&_object);

}

/**
 * Merges all parameters and invokes the lazy ones.
 * @param Medium $mergeBlueprint  The overrides during merging
 * @return Medium
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, merge) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mergeBlueprint, mergeBlueprint_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mergeBlueprint_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mergeBlueprint);



	object_init_ex(return_value, moon_component_di_resolver_medium_ce);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("className"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "mergeparams", NULL, 84, mergeBlueprint);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "mergesetters", NULL, 85, mergeBlueprint);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, mergeBlueprint, "islazy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "mergemutations", NULL, 86, mergeBlueprint);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 21, &_0, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return string
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, getClassName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "className");

}

/**
 * @return array
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "params");

}

/**
 * @return array
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, getSetters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "setters");

}

/**
 * @return array
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, getMutations) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "mutations");

}

/**
 * @param array $params
 * @return Blueprint
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, replaceParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *params_param = NULL, _clone;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_clone);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(&params, params_param);


	ZEPHIR_INIT_VAR(&_clone);
	if (zephir_clone(&_clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_clone, ZEND_STRL("params"), &params);
	RETURN_CCTOR(&_clone);

}

/**
 * @param array $params
 * @return Blueprint
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, withParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, __clone, _0, _1;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&__clone);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(&params, params_param);


	ZEPHIR_INIT_VAR(&__clone);
	if (zephir_clone(&__clone, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "merge", NULL, 0, &params);
	zephir_check_call_status();
	zephir_update_property_zval(&__clone, ZEND_STRL("params"), &_1);
	RETURN_CCTOR(&__clone);

}

/**
 *
 * Merges the setters with overrides; also invokes Lazy values.
 *
 * @param Blueprint $mergeBlueprint A blueprint containing override setters.
 *
 * @return array The merged setters
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, mergeSetters) {

	zval *mergeBlueprint, mergeBlueprint_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mergeBlueprint_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params_without_memory_grow(1, 0, &mergeBlueprint);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, mergeBlueprint, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(return_value, &_0, &_1);
	return;

}

/**
 *
 * Merges the setters with overrides; also invokes Lazy values.
 *
 * @param Blueprint $mergeBlueprint A blueprint containing additional mutations.
 *
 * @return array The merged mutations
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, mergeMutations) {

	zval *mergeBlueprint, mergeBlueprint_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mergeBlueprint_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params_without_memory_grow(1, 0, &mergeBlueprint);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, mergeBlueprint, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(return_value, &_0, &_1);
	return;

}

/**
 *
 * Merges the params with overides; also invokes Lazy values.
 *
 * @param Blueprint $mergeBlueprint A blueprint containing override parameters; the key may
 * be the name *or* the numeric position of the constructor parameter, and
 * the value is the parameter value to use.
 *
 * @return array The merged params
 *
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, mergeParams) {

	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pos = 0;
	zval *mergeBlueprint, mergeBlueprint_sub, val, params, _0, _1, key, *_2, _3, _6$$4, _7$$4, _8$$4, _9$$5, _10$$6, _11$$7, _12$$7, _13$$7, _14$$8, _15$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mergeBlueprint_sub);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mergeBlueprint);



	zephir_read_property(&_0, mergeBlueprint, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		RETURN_MM_MEMBER(getThis(), "params");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&params, &_1);
	pos = 0;
	zephir_is_iterable(&params, 1, "moon/Component/DI/Resolver/Medium.zep", 219);
	if (Z_TYPE_P(&params) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&params), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&key, _5);
			} else {
				ZVAL_LONG(&key, _4);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _2);
			zephir_read_property(&_6$$4, mergeBlueprint, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_7$$4, pos);
			zephir_read_property(&_8$$4, mergeBlueprint, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_key_exists(&_6$$4, &_7$$4)) {
				zephir_read_property(&_9$$5, mergeBlueprint, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&val);
				zephir_array_fetch_long(&val, &_9$$5, pos, PH_NOISY, "moon/Component/DI/Resolver/Medium.zep", 209);
			} else if (zephir_array_key_exists(&_8$$4, &key)) {
				zephir_read_property(&_10$$6, mergeBlueprint, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&val);
				zephir_array_fetch(&val, &_10$$6, &key, PH_NOISY, "moon/Component/DI/Resolver/Medium.zep", 212);
			}
			zephir_array_update_zval(&params, &key, &val, PH_COPY | PH_SEPARATE);
			pos += 1;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &params, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &params, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &params, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &params, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_11$$7, mergeBlueprint, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_12$$7, pos);
				zephir_read_property(&_13$$7, mergeBlueprint, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_key_exists(&_11$$7, &_12$$7)) {
					zephir_read_property(&_14$$8, mergeBlueprint, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&val);
					zephir_array_fetch_long(&val, &_14$$8, pos, PH_NOISY, "moon/Component/DI/Resolver/Medium.zep", 209);
				} else if (zephir_array_key_exists(&_13$$7, &key)) {
					zephir_read_property(&_15$$9, mergeBlueprint, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&val);
					zephir_array_fetch(&val, &_15$$9, &key, PH_NOISY, "moon/Component/DI/Resolver/Medium.zep", 212);
				}
				zephir_array_update_zval(&params, &key, &val, PH_COPY | PH_SEPARATE);
				pos += 1;
			ZEPHIR_CALL_METHOD(NULL, &params, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&params);

}

/**
 * @return bool
 */
PHP_METHOD(Moon_Component_DI_Resolver_Medium, isLazy) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "isLazy");

}

