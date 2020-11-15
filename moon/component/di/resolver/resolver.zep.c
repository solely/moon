
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
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * FileName: Resolver.php
 * User: solely
 * DateTime: 2019/6/25 23:24
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_Resolver) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI\\Resolver, Resolver, moon, component_di_resolver_resolver, moon_component_di_resolver_resolver_method_entry, 0);

	/**
	 *
	 * A Reflector.
	 *
	 * @var Reflector
	 *
	 */
	zend_declare_property_null(moon_component_di_resolver_resolver_ce, SL("reflector"), ZEND_ACC_PROTECTED);

	/**
	 *
	 * Constructor params in the form `$params[$class][$name] = $value`.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(moon_component_di_resolver_resolver_ce, SL("params"), ZEND_ACC_PROTECTED);

	/**
	 *
	 * Setter definitions in the form of `$setters[$class][$method] = $value`.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(moon_component_di_resolver_resolver_ce, SL("setters"), ZEND_ACC_PROTECTED);

	/**
	 *
	 * Setter definitions in the form of `$mutations[$class][] = $value`.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(moon_component_di_resolver_resolver_ce, SL("mutations"), ZEND_ACC_PROTECTED);

	/**
	 *
	 * Arbitrary values in the form of `$values[$key] = $value`.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(moon_component_di_resolver_resolver_ce, SL("values"), ZEND_ACC_PROTECTED);

	/**
	 *
	 * Constructor params and setter definitions, unified across class
	 * defaults, inheritance hierarchies, and configuration.
	 *
	 * @var array|Blueprint[]
	 *
	 */
	zend_declare_property_null(moon_component_di_resolver_resolver_ce, SL("unified"), ZEND_ACC_PROTECTED);

	moon_component_di_resolver_resolver_ce->create_object = zephir_init_properties_Moon_Component_DI_Resolver_Resolver;
	return SUCCESS;

}

/**
 *
 * Constructor.
 *
 * @param Reflector $reflector A collection point for Reflection data.
 *
 */
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, __construct) {

	zval *reflector, reflector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflector_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &reflector);



	zephir_update_property_zval(this_ptr, ZEND_STRL("reflector"), reflector);

}

/**
 * Returns a reference to various property arrays.
 *
 * @param $key  The property name to return.
 * @return array
 * @throws Exception\ResolverException
 * 
 * PHP 源文件还是有 引用，这里拆成了 两个魔术方法：__get()、__set()
 */
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *key, key_sub, _0$$3, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	if (zephir_isset_property_zval(this_ptr, key)) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property_zval(&_0$$3, this_ptr, key, PH_NOISY_CC);
		RETURN_CCTOR(&_0$$3);
	}
	ZEPHIR_CALL_CE_STATIC(&_1, moon_component_di_exception_ce, "resolvernosuchproperty", &_2, 0, key);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "moon/Component/DI/Resolver/Resolver.zep", 89);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Moon_Component_DI_Resolver_Resolver, __set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval arr;
	zval *key_param = NULL, *arr_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&arr);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &arr_param);

	zephir_get_strval(&key, key_param);
	zephir_get_arrval(&arr, arr_param);


	zephir_update_property_zval_zval(this_ptr, &key, &arr);
	ZEPHIR_MM_RESTORE();

}

/**
 *
 * Creates and returns a new instance of a class using reflection and
 * the configuration parameters, optionally with overrides, invoking Lazy
 * values along the way.
 *
 * @param Blueprint $blueprint The blueprint to be resolved containing
 * its overrides for this specific case.
 *
 * @param array $contextualBlueprints
 *
 * @return object
 *
 */
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, resolve) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL, *_12 = NULL, *_24 = NULL, *_29 = NULL, *_34 = NULL, *_36 = NULL, *_48 = NULL, *_53 = NULL, *_58 = NULL, *_69 = NULL, *_81 = NULL, *_95 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval contextualBlueprints;
	zval *blueprint, blueprint_sub, *contextualBlueprints_param = NULL, resolved, className, remember, reflectionException, _93, _0$$4, _1$$4, _2$$4, _3$$4, _5$$4, _6$$4, _7$$4, _9$$3, contextualBlueprint$$3, *_10$$3, _11$$3, _60$$3, _61$$3, _62$$3, _63$$3, _64$$3, _65$$3, _66$$3, *_67$$3, _68$$3, _13$$5, _14$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5, _21$$5, _22$$5, _23$$5, _25$$5, _26$$5, _27$$5, _28$$5, _30$$5, _31$$5, _32$$5, _33$$5, _35$$5, _37$$6, _38$$6, _39$$6, _40$$6, _41$$6, _42$$6, _43$$6, _44$$6, _45$$6, _46$$6, _47$$6, _49$$6, _50$$6, _51$$6, _52$$6, _54$$6, _55$$6, _56$$6, _57$$6, _59$$6, _70$$7, _71$$7, _72$$7, _73$$7, _74$$7, _75$$7, _76$$7, _77$$7, _78$$8, _79$$8, _80$$9, _82$$10, _83$$10, _84$$10, _85$$10, _86$$10, _87$$10, _88$$10, _89$$10, _90$$11, _91$$11, _92$$12, _94$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&blueprint_sub);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&remember);
	ZVAL_UNDEF(&reflectionException);
	ZVAL_UNDEF(&_93);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&contextualBlueprint$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_60$$3);
	ZVAL_UNDEF(&_61$$3);
	ZVAL_UNDEF(&_62$$3);
	ZVAL_UNDEF(&_63$$3);
	ZVAL_UNDEF(&_64$$3);
	ZVAL_UNDEF(&_65$$3);
	ZVAL_UNDEF(&_66$$3);
	ZVAL_UNDEF(&_68$$3);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_27$$5);
	ZVAL_UNDEF(&_28$$5);
	ZVAL_UNDEF(&_30$$5);
	ZVAL_UNDEF(&_31$$5);
	ZVAL_UNDEF(&_32$$5);
	ZVAL_UNDEF(&_33$$5);
	ZVAL_UNDEF(&_35$$5);
	ZVAL_UNDEF(&_37$$6);
	ZVAL_UNDEF(&_38$$6);
	ZVAL_UNDEF(&_39$$6);
	ZVAL_UNDEF(&_40$$6);
	ZVAL_UNDEF(&_41$$6);
	ZVAL_UNDEF(&_42$$6);
	ZVAL_UNDEF(&_43$$6);
	ZVAL_UNDEF(&_44$$6);
	ZVAL_UNDEF(&_45$$6);
	ZVAL_UNDEF(&_46$$6);
	ZVAL_UNDEF(&_47$$6);
	ZVAL_UNDEF(&_49$$6);
	ZVAL_UNDEF(&_50$$6);
	ZVAL_UNDEF(&_51$$6);
	ZVAL_UNDEF(&_52$$6);
	ZVAL_UNDEF(&_54$$6);
	ZVAL_UNDEF(&_55$$6);
	ZVAL_UNDEF(&_56$$6);
	ZVAL_UNDEF(&_57$$6);
	ZVAL_UNDEF(&_59$$6);
	ZVAL_UNDEF(&_70$$7);
	ZVAL_UNDEF(&_71$$7);
	ZVAL_UNDEF(&_72$$7);
	ZVAL_UNDEF(&_73$$7);
	ZVAL_UNDEF(&_74$$7);
	ZVAL_UNDEF(&_75$$7);
	ZVAL_UNDEF(&_76$$7);
	ZVAL_UNDEF(&_77$$7);
	ZVAL_UNDEF(&_78$$8);
	ZVAL_UNDEF(&_79$$8);
	ZVAL_UNDEF(&_80$$9);
	ZVAL_UNDEF(&_82$$10);
	ZVAL_UNDEF(&_83$$10);
	ZVAL_UNDEF(&_84$$10);
	ZVAL_UNDEF(&_85$$10);
	ZVAL_UNDEF(&_86$$10);
	ZVAL_UNDEF(&_87$$10);
	ZVAL_UNDEF(&_88$$10);
	ZVAL_UNDEF(&_89$$10);
	ZVAL_UNDEF(&_90$$11);
	ZVAL_UNDEF(&_91$$11);
	ZVAL_UNDEF(&_92$$12);
	ZVAL_UNDEF(&_94$$13);
	ZVAL_UNDEF(&contextualBlueprints);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &blueprint, &contextualBlueprints_param);

	if (!contextualBlueprints_param) {
		ZEPHIR_INIT_VAR(&contextualBlueprints);
		array_init(&contextualBlueprints);
	} else {
		zephir_get_arrval(&contextualBlueprints, contextualBlueprints_param);
	}



	/* try_start_1: */

		if (ZEPHIR_IS_EMPTY(&contextualBlueprints)) {
			ZEPHIR_CALL_METHOD(&_2$$4, blueprint, "getclassname", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getunified", NULL, 0, &_2$$4);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&_3$$4, &_1$$4, "merge", NULL, 0, blueprint);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "expandparams", &_4, 0, &_3$$4);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("reflector"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_7$$4, blueprint, "getclassname", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&_6$$4, &_5$$4, "getclass", NULL, 0, &_7$$4);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", &_8, 69, &_0$$4, &_6$$4);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&remember);
		object_init_ex(&remember, moon_component_di_resolver_resolver_ce);
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("reflector"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &remember, "__construct", NULL, 14, &_9$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(&contextualBlueprints, 0, "moon/Component/DI/Resolver/Resolver.zep", 133);
		if (Z_TYPE_P(&contextualBlueprints) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&contextualBlueprints), _10$$3)
			{
				ZEPHIR_INIT_NVAR(&contextualBlueprint$$3);
				ZVAL_COPY(&contextualBlueprint$$3, _10$$3);
				ZEPHIR_CALL_METHOD(&className, &contextualBlueprint$$3, "getclassname", &_12, 0);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_read_property(&_14$$5, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_14$$5, &className)) {
					zephir_read_property(&_15$$5, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_13$$5);
					zephir_array_fetch(&_13$$5, &_15$$5, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 125);
				} else {
					ZEPHIR_INIT_NVAR(&_13$$5);
					array_init(&_13$$5);
				}
				zephir_update_property_array(&remember, SL("params"), &className, &_13$$5);
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_read_property(&_16$$5, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_16$$5, &className)) {
					zephir_read_property(&_17$$5, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_13$$5);
					zephir_array_fetch(&_13$$5, &_17$$5, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 126);
				} else {
					ZEPHIR_INIT_NVAR(&_13$$5);
					array_init(&_13$$5);
				}
				zephir_update_property_array(&remember, SL("setters"), &className, &_13$$5);
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_read_property(&_18$$5, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_18$$5, &className)) {
					zephir_read_property(&_19$$5, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_13$$5);
					zephir_array_fetch(&_13$$5, &_19$$5, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 127);
				} else {
					ZEPHIR_INIT_NVAR(&_13$$5);
					array_init(&_13$$5);
				}
				zephir_update_property_array(&remember, SL("mutations"), &className, &_13$$5);
				ZEPHIR_INIT_NVAR(&_20$$5);
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_read_property(&_21$$5, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_21$$5, &className)) {
					zephir_read_property(&_22$$5, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_13$$5);
					zephir_array_fetch(&_13$$5, &_22$$5, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 128);
				} else {
					ZEPHIR_INIT_NVAR(&_13$$5);
					array_init(&_13$$5);
				}
				ZEPHIR_CALL_METHOD(&_23$$5, &contextualBlueprint$$3, "getparams", &_24, 0);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_fast_array_merge(&_20$$5, &_13$$5, &_23$$5);
				zephir_update_property_array(this_ptr, SL("params"), &className, &_20$$5);
				ZEPHIR_INIT_NVAR(&_20$$5);
				ZEPHIR_INIT_NVAR(&_25$$5);
				zephir_read_property(&_26$$5, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_26$$5, &className)) {
					zephir_read_property(&_27$$5, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_25$$5);
					zephir_array_fetch(&_25$$5, &_27$$5, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 129);
				} else {
					ZEPHIR_INIT_NVAR(&_25$$5);
					array_init(&_25$$5);
				}
				ZEPHIR_CALL_METHOD(&_28$$5, &contextualBlueprint$$3, "getsetters", &_29, 0);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_fast_array_merge(&_20$$5, &_25$$5, &_28$$5);
				zephir_update_property_array(this_ptr, SL("setters"), &className, &_20$$5);
				ZEPHIR_INIT_NVAR(&_20$$5);
				ZEPHIR_INIT_NVAR(&_30$$5);
				zephir_read_property(&_31$$5, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_31$$5, &className)) {
					zephir_read_property(&_32$$5, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_30$$5);
					zephir_array_fetch(&_30$$5, &_32$$5, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 130);
				} else {
					ZEPHIR_INIT_NVAR(&_30$$5);
					array_init(&_30$$5);
				}
				ZEPHIR_CALL_METHOD(&_33$$5, &contextualBlueprint$$3, "getmutations", &_34, 0);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_fast_array_merge(&_20$$5, &_30$$5, &_33$$5);
				zephir_update_property_array(this_ptr, SL("setters"), &className, &_20$$5);
				zephir_read_property(&_35$$5, this_ptr, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_35$$5, &className, PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &contextualBlueprints, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_11$$3, &contextualBlueprints, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_11$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&contextualBlueprint$$3, &contextualBlueprints, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&className, &contextualBlueprint$$3, "getclassname", &_36, 0);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_INIT_NVAR(&_37$$6);
					zephir_read_property(&_38$$6, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_38$$6, &className)) {
						zephir_read_property(&_39$$6, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_37$$6);
						zephir_array_fetch(&_37$$6, &_39$$6, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 125);
					} else {
						ZEPHIR_INIT_NVAR(&_37$$6);
						array_init(&_37$$6);
					}
					zephir_update_property_array(&remember, SL("params"), &className, &_37$$6);
					ZEPHIR_INIT_NVAR(&_37$$6);
					zephir_read_property(&_40$$6, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_40$$6, &className)) {
						zephir_read_property(&_41$$6, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_37$$6);
						zephir_array_fetch(&_37$$6, &_41$$6, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 126);
					} else {
						ZEPHIR_INIT_NVAR(&_37$$6);
						array_init(&_37$$6);
					}
					zephir_update_property_array(&remember, SL("setters"), &className, &_37$$6);
					ZEPHIR_INIT_NVAR(&_37$$6);
					zephir_read_property(&_42$$6, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_42$$6, &className)) {
						zephir_read_property(&_43$$6, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_37$$6);
						zephir_array_fetch(&_37$$6, &_43$$6, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 127);
					} else {
						ZEPHIR_INIT_NVAR(&_37$$6);
						array_init(&_37$$6);
					}
					zephir_update_property_array(&remember, SL("mutations"), &className, &_37$$6);
					ZEPHIR_INIT_NVAR(&_44$$6);
					ZEPHIR_INIT_NVAR(&_37$$6);
					zephir_read_property(&_45$$6, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_45$$6, &className)) {
						zephir_read_property(&_46$$6, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_37$$6);
						zephir_array_fetch(&_37$$6, &_46$$6, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 128);
					} else {
						ZEPHIR_INIT_NVAR(&_37$$6);
						array_init(&_37$$6);
					}
					ZEPHIR_CALL_METHOD(&_47$$6, &contextualBlueprint$$3, "getparams", &_48, 0);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_fast_array_merge(&_44$$6, &_37$$6, &_47$$6);
					zephir_update_property_array(this_ptr, SL("params"), &className, &_44$$6);
					ZEPHIR_INIT_NVAR(&_44$$6);
					ZEPHIR_INIT_NVAR(&_49$$6);
					zephir_read_property(&_50$$6, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_50$$6, &className)) {
						zephir_read_property(&_51$$6, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_49$$6);
						zephir_array_fetch(&_49$$6, &_51$$6, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 129);
					} else {
						ZEPHIR_INIT_NVAR(&_49$$6);
						array_init(&_49$$6);
					}
					ZEPHIR_CALL_METHOD(&_52$$6, &contextualBlueprint$$3, "getsetters", &_53, 0);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_fast_array_merge(&_44$$6, &_49$$6, &_52$$6);
					zephir_update_property_array(this_ptr, SL("setters"), &className, &_44$$6);
					ZEPHIR_INIT_NVAR(&_44$$6);
					ZEPHIR_INIT_NVAR(&_54$$6);
					zephir_read_property(&_55$$6, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_55$$6, &className)) {
						zephir_read_property(&_56$$6, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_54$$6);
						zephir_array_fetch(&_54$$6, &_56$$6, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 130);
					} else {
						ZEPHIR_INIT_NVAR(&_54$$6);
						array_init(&_54$$6);
					}
					ZEPHIR_CALL_METHOD(&_57$$6, &contextualBlueprint$$3, "getmutations", &_58, 0);
					zephir_check_call_status_or_jump(try_end_1);
					zephir_fast_array_merge(&_44$$6, &_54$$6, &_57$$6);
					zephir_update_property_array(this_ptr, SL("setters"), &className, &_44$$6);
					zephir_read_property(&_59$$6, this_ptr, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_59$$6, &className, PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &contextualBlueprints, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&contextualBlueprint$$3);
		ZEPHIR_CALL_METHOD(&_62$$3, blueprint, "getclassname", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_61$$3, this_ptr, "getunified", NULL, 0, &_62$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_63$$3, &_61$$3, "merge", NULL, 0, blueprint);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_60$$3, this_ptr, "expandparams", &_4, 0, &_63$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_property(&_64$$3, this_ptr, ZEND_STRL("reflector"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_66$$3, blueprint, "getclassname", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_65$$3, &_64$$3, "getclass", NULL, 0, &_66$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_FUNCTION(&resolved, "call_user_func", &_8, 69, &_60$$3, &_65$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(&contextualBlueprints, 0, "moon/Component/DI/Resolver/Resolver.zep", 146);
		if (Z_TYPE_P(&contextualBlueprints) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&contextualBlueprints), _67$$3)
			{
				ZEPHIR_INIT_NVAR(&contextualBlueprint$$3);
				ZVAL_COPY(&contextualBlueprint$$3, _67$$3);
				ZEPHIR_CALL_METHOD(&className, &contextualBlueprint$$3, "getclassname", &_69, 0);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_INIT_NVAR(&_70$$7);
				zephir_read_property(&_71$$7, &remember, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_71$$7, &className)) {
					zephir_read_property(&_72$$7, &remember, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_70$$7);
					zephir_array_fetch(&_70$$7, &_72$$7, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 137);
				} else {
					ZEPHIR_INIT_NVAR(&_70$$7);
					array_init(&_70$$7);
				}
				zephir_update_property_array(this_ptr, SL("params"), &className, &_70$$7);
				ZEPHIR_INIT_NVAR(&_70$$7);
				zephir_read_property(&_73$$7, &remember, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_73$$7, &className)) {
					zephir_read_property(&_74$$7, &remember, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_70$$7);
					zephir_array_fetch(&_70$$7, &_74$$7, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 138);
				} else {
					ZEPHIR_INIT_NVAR(&_70$$7);
					array_init(&_70$$7);
				}
				zephir_update_property_array(this_ptr, SL("setters"), &className, &_70$$7);
				ZEPHIR_INIT_NVAR(&_70$$7);
				zephir_read_property(&_75$$7, &remember, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_75$$7, &className)) {
					zephir_read_property(&_76$$7, &remember, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_70$$7);
					zephir_array_fetch(&_70$$7, &_76$$7, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 139);
				} else {
					ZEPHIR_INIT_NVAR(&_70$$7);
					array_init(&_70$$7);
				}
				zephir_update_property_array(this_ptr, SL("mutations"), &className, &_70$$7);
				zephir_read_property(&_77$$7, &remember, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_77$$7, &className)) {
					zephir_read_property(&_78$$8, &remember, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_79$$8, &_78$$8, &className, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 141);
					zephir_update_property_array(this_ptr, SL("unified"), &className, &_79$$8);
				} else {
					zephir_read_property(&_80$$9, this_ptr, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_80$$9, &className, PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &contextualBlueprints, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_68$$3, &contextualBlueprints, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_68$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&contextualBlueprint$$3, &contextualBlueprints, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&className, &contextualBlueprint$$3, "getclassname", &_81, 0);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_INIT_NVAR(&_82$$10);
					zephir_read_property(&_83$$10, &remember, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_83$$10, &className)) {
						zephir_read_property(&_84$$10, &remember, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_82$$10);
						zephir_array_fetch(&_82$$10, &_84$$10, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 137);
					} else {
						ZEPHIR_INIT_NVAR(&_82$$10);
						array_init(&_82$$10);
					}
					zephir_update_property_array(this_ptr, SL("params"), &className, &_82$$10);
					ZEPHIR_INIT_NVAR(&_82$$10);
					zephir_read_property(&_85$$10, &remember, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_85$$10, &className)) {
						zephir_read_property(&_86$$10, &remember, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_82$$10);
						zephir_array_fetch(&_82$$10, &_86$$10, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 138);
					} else {
						ZEPHIR_INIT_NVAR(&_82$$10);
						array_init(&_82$$10);
					}
					zephir_update_property_array(this_ptr, SL("setters"), &className, &_82$$10);
					ZEPHIR_INIT_NVAR(&_82$$10);
					zephir_read_property(&_87$$10, &remember, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_87$$10, &className)) {
						zephir_read_property(&_88$$10, &remember, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_82$$10);
						zephir_array_fetch(&_82$$10, &_88$$10, &className, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 139);
					} else {
						ZEPHIR_INIT_NVAR(&_82$$10);
						array_init(&_82$$10);
					}
					zephir_update_property_array(this_ptr, SL("mutations"), &className, &_82$$10);
					zephir_read_property(&_89$$10, &remember, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_89$$10, &className)) {
						zephir_read_property(&_90$$11, &remember, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_91$$11, &_90$$11, &className, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 141);
						zephir_update_property_array(this_ptr, SL("unified"), &className, &_91$$11);
					} else {
						zephir_read_property(&_92$$12, this_ptr, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
						zephir_array_unset(&_92$$12, &className, PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, &contextualBlueprints, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&contextualBlueprint$$3);
		RETURN_CCTOR(&resolved);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_93);
		ZVAL_OBJ(&_93, EG(exception));
		Z_ADDREF_P(&_93);
		if (zephir_instance_of_ev(&_93, zephir_get_internal_ce(SL("reflectionexception")))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&reflectionException, &_93);
			ZEPHIR_CALL_CE_STATIC(&_94$$13, moon_component_di_exception_ce, "resolverexception", &_95, 0, &reflectionException);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_94$$13, "moon/Component/DI/Resolver/Resolver.zep", 148);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *
 * Returns the unified constructor params and setters for a class.
 *
 * @param string $class The class name to return values for.
 *
 * @return Blueprint A blueprint how to construct an object
 *
 */
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, getUnified) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_class_param = NULL, spec, parent, _0, _4, _5, _6, _7, _8, _9, _10, _11, _12, _1$$3, _2$$3;
	zval _class;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_class);
	ZVAL_UNDEF(&spec);
	ZVAL_UNDEF(&parent);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_class_param);

	zephir_get_strval(&_class, _class_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &_class)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &_class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 167);
		RETURN_CTOR(&_2$$3);
	}
	ZEPHIR_CALL_FUNCTION(&parent, "get_parent_class", NULL, 66, &_class);
	zephir_check_call_status();
	if (zephir_is_true(&parent)) {
		ZEPHIR_CALL_METHOD(&spec, this_ptr, "getunified", NULL, 70, &parent);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&spec);
		object_init_ex(&spec, moon_component_di_resolver_medium_ce);
		ZEPHIR_CALL_METHOD(NULL, &spec, "__construct", &_3, 13, &_class);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, moon_component_di_resolver_medium_ce);
	ZEPHIR_CALL_METHOD(&_6, &spec, "getparams", NULL, 71);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getunifiedparams", NULL, 0, &_class, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, &spec, "getsetters", NULL, 72);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getunifiedsetters", NULL, 0, &_class, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, &spec, "getmutations", NULL, 73);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "getunifiedmutations", NULL, 0, &_class, &_10);
	zephir_check_call_status();
	ZVAL_BOOL(&_11, 0);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", &_3, 13, &_class, &_5, &_7, &_11, &_9);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("unified"), &_class, &_4);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_12, &_11, &_class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 187);
	RETURN_CTOR(&_12);

}

/**
 * Returns the unified constructor params for a class.
 *
 * @param string $class The class name to return values for.
 * @param array $parent The parent unified params.
 * @return array  The unified params.
 * @throws Exception\ResolverException
 */
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, getUnifiedParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parent;
	zval *_class_param = NULL, *parent_param = NULL, rparams, unified, reflectionException, _8, _0$$3, rparam$$3, *_1$$3, _2$$3, _3$$4, _5$$4, _6$$5, _7$$5, _9$$6;
	zval _class;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_class);
	ZVAL_UNDEF(&rparams);
	ZVAL_UNDEF(&unified);
	ZVAL_UNDEF(&reflectionException);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&rparam$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&parent);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &_class_param, &parent_param);

	zephir_get_strval(&_class, _class_param);
	zephir_get_arrval(&parent, parent_param);



	/* try_start_1: */

		ZEPHIR_INIT_VAR(&unified);
		array_init(&unified);
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("reflector"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&rparams, &_0$$3, "getparams", NULL, 0, &_class);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(&rparams, 0, "moon/Component/DI/Resolver/Resolver.zep", 211);
		if (Z_TYPE_P(&rparams) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rparams), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&rparam$$3);
				ZVAL_COPY(&rparam$$3, _1$$3);
				ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getunifiedparam", &_4, 0, &rparam$$3, &_class, &parent);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_OBS_NVAR(&_5$$4);
				zephir_read_property(&_5$$4, &rparam$$3, ZEND_STRL("name"), PH_NOISY_CC);
				zephir_array_update_zval(&unified, &_5$$4, &_3$$4, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &rparams, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, &rparams, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&rparam$$3, &rparams, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "getunifiedparam", &_4, 0, &rparam$$3, &_class, &parent);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_OBS_NVAR(&_7$$5);
					zephir_read_property(&_7$$5, &rparam$$3, ZEND_STRL("name"), PH_NOISY_CC);
					zephir_array_update_zval(&unified, &_7$$5, &_6$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &rparams, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&rparam$$3);
		RETURN_CCTOR(&unified);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_OBJ(&_8, EG(exception));
		Z_ADDREF_P(&_8);
		if (zephir_instance_of_ev(&_8, zephir_get_internal_ce(SL("reflectionexception")))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&reflectionException, &_8);
			ZEPHIR_CALL_CE_STATIC(&_9$$6, moon_component_di_exception_ce, "resolverexception", &_10, 0, &reflectionException);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$6, "moon/Component/DI/Resolver/Resolver.zep", 213);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a unified param.
 *
 * @param ReflectionParameter $rparam A parameter reflection.
 * @param string $class The class name to return values for.
 * @param array $parent The parent unified params.
 * @return mixed|DefaultValueParam|UnresolvedParam
 * @throws ReflectionException
 */
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, getUnifiedParam) {

	zend_class_entry *_35, *_29$$6;
	zend_bool parentDefault = 0, implicitNamed = 0, explicitNamed = 0, explicitPos = 0, _1, _4, _12, _15, _22, _24, _31;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _parent;
	zval _class;
	zval *rparam, rparam_sub, *_class_param = NULL, *_parent_param = NULL, pos, name, DParam, UParam, _0, _2, _3, _5, _6, _7, _11, _13, _14, _16, _17, _18, _23, _25, _27, _32, _34, _8$$3, _9$$3, _10$$3, _19$$4, _20$$4, _21$$4, _26$$5, _28$$6, _30$$6, _33$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rparam_sub);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&DParam);
	ZVAL_UNDEF(&UParam);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_30$$6);
	ZVAL_UNDEF(&_33$$7);
	ZVAL_UNDEF(&_class);
	ZVAL_UNDEF(&_parent);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &rparam, &_class_param, &_parent_param);

	zephir_get_strval(&_class, _class_param);
	zephir_get_arrval(&_parent, _parent_param);


	ZEPHIR_CALL_METHOD(&name, rparam, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&pos, rparam, "getposition", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, &_class);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3, &_2, &_class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 239);
		_1 = zephir_array_key_exists(&_3, &pos);
	}
	_4 = _1;
	if (_4) {
		zephir_read_property(&_5, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_6, &_5, &_class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 239);
		ZEPHIR_OBS_VAR(&_7);
		zephir_array_fetch(&_7, &_6, &pos, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 239);
		_4 = !(zephir_instance_of_ev(&_7, moon_component_di_resolver_unresolvedparam_ce));
	}
	explicitPos = _4;
	if (explicitPos) {
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_9$$3, &_8$$3, &_class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 241);
		zephir_array_fetch(&_10$$3, &_9$$3, &pos, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 241);
		RETURN_CTOR(&_10$$3);
	}
	zephir_read_property(&_11, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	_12 = zephir_array_isset(&_11, &_class);
	if (_12) {
		zephir_read_property(&_13, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_14, &_13, &_class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 244);
		_12 = zephir_array_key_exists(&_14, &name);
	}
	_15 = _12;
	if (_15) {
		zephir_read_property(&_16, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_17, &_16, &_class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 244);
		ZEPHIR_OBS_VAR(&_18);
		zephir_array_fetch(&_18, &_17, &name, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 244);
		_15 = !(zephir_instance_of_ev(&_18, moon_component_di_resolver_unresolvedparam_ce));
	}
	explicitNamed = _15;
	if (explicitNamed) {
		zephir_read_property(&_19$$4, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_20$$4, &_19$$4, &_class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 246);
		zephir_array_fetch(&_21$$4, &_20$$4, &name, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 246);
		RETURN_CTOR(&_21$$4);
	}
	_22 = zephir_array_key_exists(&_parent, &name);
	if (_22) {
		ZEPHIR_OBS_VAR(&_23);
		zephir_array_fetch(&_23, &_parent, &name, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 251);
		_22 = !(zephir_instance_of_ev(&_23, moon_component_di_resolver_unresolvedparam_ce));
	}
	_24 = _22;
	if (_24) {
		ZEPHIR_OBS_VAR(&_25);
		zephir_array_fetch(&_25, &_parent, &name, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 251);
		_24 = !(zephir_instance_of_ev(&_25, moon_component_di_resolver_defaultvalueparam_ce));
	}
	implicitNamed = _24;
	if (implicitNamed) {
		zephir_array_fetch(&_26$$5, &_parent, &name, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 253);
		RETURN_CTOR(&_26$$5);
	}
	ZEPHIR_CALL_METHOD(&_27, rparam, "isdefaultvalueavailable", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_27)) {
		ZEPHIR_INIT_VAR(&DParam);
		ZVAL_STRING(&DParam, "DefaultValueParam");
		zephir_fetch_safe_class(&_28$$6, &DParam);
		_29$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_28$$6), Z_STRLEN_P(&_28$$6), ZEND_FETCH_CLASS_AUTO);
		if(!_29$$6) {
			RETURN_MM_NULL();
		}
		object_init_ex(return_value, _29$$6);
		if (zephir_has_constructor(return_value)) {
			ZEPHIR_CALL_METHOD(&_30$$6, rparam, "getdefaultvalue", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &name, &_30$$6);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	_31 = zephir_array_key_exists(&_parent, &name);
	if (_31) {
		ZEPHIR_OBS_VAR(&_32);
		zephir_array_fetch(&_32, &_parent, &name, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 261);
		_31 = zephir_instance_of_ev(&_32, moon_component_di_resolver_defaultvalueparam_ce);
	}
	parentDefault = _31;
	if (parentDefault) {
		zephir_array_fetch(&_33$$7, &_parent, &name, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 263);
		RETURN_CTOR(&_33$$7);
	}
	ZEPHIR_INIT_VAR(&UParam);
	ZVAL_STRING(&UParam, "UnresolvedParam");
	zephir_fetch_safe_class(&_34, &UParam);
	_35 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_34), Z_STRLEN_P(&_34), ZEND_FETCH_CLASS_AUTO);
	if(!_35) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _35);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &name);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 *
 * Returns the unified mutations for a class.
 *
 * Class-specific mutations are executed last before trait-based mutations and before interface-based mutations.
 *
 * @param string $class The class name to return values for.
 *
 * @param array $parent The parent unified setters.
 *
 * @return array The unified mutations.
 *
 */
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, getUnifiedMutations) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _parent;
	zval *_class_param = NULL, *_parent_param = NULL, traits, interfaces, unified, _interface, *_0, _1, _10, trait, *_11, _12, _21, _2$$3, _3$$4, _4$$4, _5$$4, _6$$5, _7$$6, _8$$6, _9$$6, _13$$7, _14$$8, _15$$8, _16$$8, _17$$9, _18$$10, _19$$10, _20$$10, _22$$11, _23$$11, _24$$11;
	zval _class;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_class);
	ZVAL_UNDEF(&traits);
	ZVAL_UNDEF(&interfaces);
	ZVAL_UNDEF(&unified);
	ZVAL_UNDEF(&_interface);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&trait);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_parent);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &_class_param, &_parent_param);

	zephir_get_strval(&_class, _class_param);
	zephir_get_arrval(&_parent, _parent_param);


	ZEPHIR_CPY_WRT(&unified, &_parent);
	ZEPHIR_CALL_FUNCTION(&interfaces, "class_implements", NULL, 74, &_class);
	zephir_check_call_status();
	zephir_is_iterable(&interfaces, 0, "moon/Component/DI/Resolver/Resolver.zep", 298);
	if (Z_TYPE_P(&interfaces) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&interfaces), _0)
		{
			ZEPHIR_INIT_NVAR(&_interface);
			ZVAL_COPY(&_interface, _0);
			zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_2$$3, &_interface)) {
				ZEPHIR_INIT_NVAR(&_3$$4);
				zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_5$$4, &_4$$4, &_interface, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 294);
				zephir_fast_array_merge(&_3$$4, &_5$$4, &unified);
				ZEPHIR_CPY_WRT(&unified, &_3$$4);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &interfaces, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &interfaces, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_interface, &interfaces, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_6$$5, &_interface)) {
					ZEPHIR_INIT_NVAR(&_7$$6);
					zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_9$$6, &_8$$6, &_interface, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 294);
					zephir_fast_array_merge(&_7$$6, &_9$$6, &unified);
					ZEPHIR_CPY_WRT(&unified, &_7$$6);
				}
			ZEPHIR_CALL_METHOD(NULL, &interfaces, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_interface);
	zephir_read_property(&_10, this_ptr, ZEND_STRL("reflector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&traits, &_10, "gettraits", NULL, 0, &_class);
	zephir_check_call_status();
	zephir_is_iterable(&traits, 0, "moon/Component/DI/Resolver/Resolver.zep", 306);
	if (Z_TYPE_P(&traits) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&traits), _11)
		{
			ZEPHIR_INIT_NVAR(&trait);
			ZVAL_COPY(&trait, _11);
			zephir_read_property(&_13$$7, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_13$$7, &trait)) {
				ZEPHIR_INIT_NVAR(&_14$$8);
				zephir_read_property(&_15$$8, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_16$$8, &_15$$8, &trait, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 302);
				zephir_fast_array_merge(&_14$$8, &_16$$8, &unified);
				ZEPHIR_CPY_WRT(&unified, &_14$$8);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &traits, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_12, &traits, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&trait, &traits, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_17$$9, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_17$$9, &trait)) {
					ZEPHIR_INIT_NVAR(&_18$$10);
					zephir_read_property(&_19$$10, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_20$$10, &_19$$10, &trait, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 302);
					zephir_fast_array_merge(&_18$$10, &_20$$10, &unified);
					ZEPHIR_CPY_WRT(&unified, &_18$$10);
				}
			ZEPHIR_CALL_METHOD(NULL, &traits, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&trait);
	zephir_read_property(&_21, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_21, &_class)) {
		ZEPHIR_INIT_VAR(&_22$$11);
		zephir_read_property(&_23$$11, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_24$$11, &_23$$11, &_class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 307);
		zephir_fast_array_merge(&_22$$11, &unified, &_24$$11);
		ZEPHIR_CPY_WRT(&unified, &_22$$11);
	}
	RETURN_CCTOR(&unified);

}

/**
 *
 * Returns the unified setters for a class.
 *
 * Class-specific setters take precendence over trait-based setters, which
 * take precedence over interface-based setters.
 *
 * @param string $class The class name to return values for.
 *
 * @param array $parent The parent unified setters.
 *
 * @return array The unified setters.
 *
 */
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, getUnifiedSetters) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval _parent;
	zval *_class_param = NULL, *_parent_param = NULL, traits, interfaces, unified, _interface, *_0, _1, _10, trait, *_11, _12, _21, _2$$3, _3$$4, _4$$4, _5$$4, _6$$5, _7$$6, _8$$6, _9$$6, _13$$7, _14$$8, _15$$8, _16$$8, _17$$9, _18$$10, _19$$10, _20$$10, _22$$11, _23$$11, _24$$11;
	zval _class;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_class);
	ZVAL_UNDEF(&traits);
	ZVAL_UNDEF(&interfaces);
	ZVAL_UNDEF(&unified);
	ZVAL_UNDEF(&_interface);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&trait);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_parent);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &_class_param, &_parent_param);

	zephir_get_strval(&_class, _class_param);
	zephir_get_arrval(&_parent, _parent_param);


	ZEPHIR_CPY_WRT(&unified, &_parent);
	ZEPHIR_CALL_FUNCTION(&interfaces, "class_implements", NULL, 74, &_class);
	zephir_check_call_status();
	zephir_is_iterable(&interfaces, 0, "moon/Component/DI/Resolver/Resolver.zep", 341);
	if (Z_TYPE_P(&interfaces) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&interfaces), _0)
		{
			ZEPHIR_INIT_NVAR(&_interface);
			ZVAL_COPY(&_interface, _0);
			zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_2$$3, &_interface)) {
				ZEPHIR_INIT_NVAR(&_3$$4);
				zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_5$$4, &_4$$4, &_interface, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 337);
				zephir_fast_array_merge(&_3$$4, &_5$$4, &unified);
				ZEPHIR_CPY_WRT(&unified, &_3$$4);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &interfaces, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &interfaces, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_interface, &interfaces, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_6$$5, &_interface)) {
					ZEPHIR_INIT_NVAR(&_7$$6);
					zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_9$$6, &_8$$6, &_interface, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 337);
					zephir_fast_array_merge(&_7$$6, &_9$$6, &unified);
					ZEPHIR_CPY_WRT(&unified, &_7$$6);
				}
			ZEPHIR_CALL_METHOD(NULL, &interfaces, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_interface);
	zephir_read_property(&_10, this_ptr, ZEND_STRL("reflector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&traits, &_10, "gettraits", NULL, 0, &_class);
	zephir_check_call_status();
	zephir_is_iterable(&traits, 0, "moon/Component/DI/Resolver/Resolver.zep", 349);
	if (Z_TYPE_P(&traits) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&traits), _11)
		{
			ZEPHIR_INIT_NVAR(&trait);
			ZVAL_COPY(&trait, _11);
			zephir_read_property(&_13$$7, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_13$$7, &trait)) {
				ZEPHIR_INIT_NVAR(&_14$$8);
				zephir_read_property(&_15$$8, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_16$$8, &_15$$8, &trait, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 345);
				zephir_fast_array_merge(&_14$$8, &_16$$8, &unified);
				ZEPHIR_CPY_WRT(&unified, &_14$$8);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &traits, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_12, &traits, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&trait, &traits, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_17$$9, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_17$$9, &trait)) {
					ZEPHIR_INIT_NVAR(&_18$$10);
					zephir_read_property(&_19$$10, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_20$$10, &_19$$10, &trait, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 345);
					zephir_fast_array_merge(&_18$$10, &_20$$10, &unified);
					ZEPHIR_CPY_WRT(&unified, &_18$$10);
				}
			ZEPHIR_CALL_METHOD(NULL, &traits, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&trait);
	zephir_read_property(&_21, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_21, &_class)) {
		ZEPHIR_INIT_VAR(&_22$$11);
		zephir_read_property(&_23$$11, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_24$$11, &_23$$11, &_class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 350);
		zephir_fast_array_merge(&_22$$11, &unified, &_24$$11);
		ZEPHIR_CPY_WRT(&unified, &_22$$11);
	}
	RETURN_CCTOR(&unified);

}

/**
 * Expands variadic parameters onto the end of a contructor parameters array.
 *
 * @param Medium $blueprint $blueprint The blueprint to expand parameters for.
 * @return Medium  The blueprint with expanded constructor parameters.
 * @throws ReflectionException
 */
PHP_METHOD(Moon_Component_DI_Resolver_Resolver, expandParams) {

	zend_bool _5$$3, _13$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *blueprint, blueprint_sub, paramName, variadicParams, params, _class, reflectParam, _0, _1, *_2, _3, _20, _21, _4$$3, _6$$3, _9$$3, _7$$4, _8$$4, _10$$5, _11$$5, _12$$6, _14$$6, _17$$6, _15$$7, _16$$7, _18$$8, _19$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&blueprint_sub);
	ZVAL_UNDEF(&paramName);
	ZVAL_UNDEF(&variadicParams);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_class);
	ZVAL_UNDEF(&reflectParam);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &blueprint);



	ZEPHIR_CALL_METHOD(&_class, blueprint, "getclassname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&params, blueprint, "getparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&variadicParams);
	array_init(&variadicParams);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("reflector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getparams", NULL, 0, &_class);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "moon/Component/DI/Resolver/Resolver.zep", 384);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&reflectParam);
			ZVAL_COPY(&reflectParam, _2);
			ZEPHIR_CALL_METHOD(&paramName, &reflectParam, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$3, &reflectParam, "isvariadic", NULL, 0);
			zephir_check_call_status();
			_5$$3 = zephir_is_true(&_4$$3);
			if (_5$$3) {
				zephir_array_fetch(&_6$$3, &params, &paramName, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 374);
				_5$$3 = Z_TYPE_P(&_6$$3) == IS_ARRAY;
			}
			if (_5$$3) {
				ZEPHIR_INIT_NVAR(&_7$$4);
				zephir_array_fetch(&_8$$4, &params, &paramName, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 375);
				zephir_fast_array_merge(&_7$$4, &variadicParams, &_8$$4);
				ZEPHIR_CPY_WRT(&variadicParams, &_7$$4);
				zephir_array_unset(&params, &paramName, PH_SEPARATE);
				break;
			}
			ZEPHIR_OBS_NVAR(&_9$$3);
			zephir_array_fetch(&_9$$3, &params, &paramName, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 380);
			if (zephir_instance_of_ev(&_9$$3, moon_component_di_resolver_defaultvalueparam_ce)) {
				zephir_array_fetch(&_10$$5, &params, &paramName, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 381);
				ZEPHIR_CALL_METHOD(&_11$$5, &_10$$5, "getvalue", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&params, &paramName, &_11$$5, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&reflectParam, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&paramName, &reflectParam, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_12$$6, &reflectParam, "isvariadic", NULL, 0);
				zephir_check_call_status();
				_13$$6 = zephir_is_true(&_12$$6);
				if (_13$$6) {
					zephir_array_fetch(&_14$$6, &params, &paramName, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 374);
					_13$$6 = Z_TYPE_P(&_14$$6) == IS_ARRAY;
				}
				if (_13$$6) {
					ZEPHIR_INIT_NVAR(&_15$$7);
					zephir_array_fetch(&_16$$7, &params, &paramName, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 375);
					zephir_fast_array_merge(&_15$$7, &variadicParams, &_16$$7);
					ZEPHIR_CPY_WRT(&variadicParams, &_15$$7);
					zephir_array_unset(&params, &paramName, PH_SEPARATE);
					break;
				}
				ZEPHIR_OBS_NVAR(&_17$$6);
				zephir_array_fetch(&_17$$6, &params, &paramName, PH_NOISY, "moon/Component/DI/Resolver/Resolver.zep", 380);
				if (zephir_instance_of_ev(&_17$$6, moon_component_di_resolver_defaultvalueparam_ce)) {
					zephir_array_fetch(&_18$$8, &params, &paramName, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Resolver.zep", 381);
					ZEPHIR_CALL_METHOD(&_19$$8, &_18$$8, "getvalue", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&params, &paramName, &_19$$8, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&reflectParam);
	ZEPHIR_INIT_VAR(&_20);
	ZEPHIR_CALL_FUNCTION(&_21, "array_values", NULL, 75, &variadicParams);
	zephir_check_call_status();
	zephir_fast_array_merge(&_20, &params, &_21);
	ZEPHIR_RETURN_CALL_METHOD(blueprint, "replaceparams", NULL, 0, &_20);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Moon_Component_DI_Resolver_Resolver(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("unified"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("unified"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("values"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("values"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("mutations"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("mutations"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("setters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("setters"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

