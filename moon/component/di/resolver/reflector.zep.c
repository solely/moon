
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
#include "kernel/array.h"


/**
 * FileName: Reflector.php
 * User: solely
 * DateTime: 2019/6/23 21:22
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_Reflector) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI\\Resolver, Reflector, moon, component_di_resolver_reflector, moon_component_di_resolver_reflector_method_entry, 0);

	/**
	 *
	 * Collected ReflectionClass instances.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(moon_component_di_resolver_reflector_ce, SL("classes"), ZEND_ACC_PROTECTED);

	/**
	 *
	 * Collected arrays of ReflectionParameter instances for class constructors.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(moon_component_di_resolver_reflector_ce, SL("params"), ZEND_ACC_PROTECTED);

	/**
	 *
	 * Collected traits in classes.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(moon_component_di_resolver_reflector_ce, SL("traits"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_di_resolver_reflector_ce, SL("instance"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	moon_component_di_resolver_reflector_ce->create_object = zephir_init_properties_Moon_Component_DI_Resolver_Reflector;
	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Resolver_Reflector, __construct) {

	zval *this_ptr = getThis();



}

/**
 * @return Reflector|null
 */
PHP_METHOD(Moon_Component_DI_Resolver_Reflector, getInstance) {

	zval _0, _2, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, moon_component_di_resolver_reflector_ce, SL("instance"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, moon_component_di_resolver_reflector_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 87);
		zephir_check_call_status();
		zephir_update_static_property_ce(moon_component_di_resolver_reflector_ce, ZEND_STRL("instance"), &_1$$3);
	}
	zephir_read_static_property_ce(&_2, moon_component_di_resolver_reflector_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_2);

}

/**
 *
 * When serializing, ignore the Reflection-based properties.
 *
 * @return array
 *
 */
PHP_METHOD(Moon_Component_DI_Resolver_Reflector, __sleep) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 1, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "traits");
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

/**
 *
 * Returns a ReflectionClass for the given class.
 *
 * @param string $class Return a ReflectionClass for this class.
 *
 * @return ReflectionClass
 *
 * @throws ReflectionException when the class does not exist.
 *
 */
PHP_METHOD(Moon_Component_DI_Resolver_Reflector, getClass) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_class, _class_sub, _0, _2, _3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_class_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_class);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("classes"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, _class))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zephir_get_internal_ce(SL("reflectionclass")));
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 24, _class);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("classes"), _class, &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("classes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, _class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Reflector.zep", 81);
	RETURN_CTOR(&_3);

}

/**
 *
 * Returns an array of ReflectionParameter instances for the constructor of a given class.
 * @param $class string $class Return the array of ReflectionParameter instances
 *          for the constructor of this class.
 * @return array|\ReflectionParameter[]
 * @throws ReflectionException
 */
PHP_METHOD(Moon_Component_DI_Resolver_Reflector, getParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_class, _class_sub, constructor, _0, _4, _5, _1$$3, _2$$3, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_class_sub);
	ZVAL_UNDEF(&constructor);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_class);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, _class))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_array(this_ptr, SL("params"), _class, &_1$$3);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getclass", NULL, 0, _class);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&constructor, &_2$$3, "getconstructor", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&constructor)) {
			ZEPHIR_CALL_METHOD(&_3$$4, &constructor, "getparameters", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("params"), _class, &_3$$4);
		}
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, _class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Reflector.zep", 102);
	RETURN_CTOR(&_5);

}

/**
 *
 * Returns all traits used by a class and its ancestors,
 * and the traits used by those traits' and their ancestors.
 *
 * @param string $class The class or trait to look at for used traits.
 *
 * @return array All traits used by the requested class or trait.
 *
 * in the parent keys.
 *
 */
PHP_METHOD(Moon_Component_DI_Resolver_Reflector, getTraits) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_6 = NULL;
	zval *_class = NULL, _class_sub, newTraits, traitsToSearch, traits, _0, _12, _13, _1$$4, _3$$4, _5$$5, trait$$3, *_7$$3, _8$$3, _11$$3, _9$$6, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_class_sub);
	ZVAL_UNDEF(&newTraits);
	ZVAL_UNDEF(&traitsToSearch);
	ZVAL_UNDEF(&traits);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&trait$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_class);

	ZEPHIR_SEPARATE_PARAM(_class);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("traits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, _class))) {
		ZEPHIR_INIT_VAR(&traits);
		array_init(&traits);
		do {
			ZEPHIR_CALL_FUNCTION(&_1$$4, "class_uses", &_2, 88, _class);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(&traits, &_1$$4);
			ZEPHIR_CALL_FUNCTION(&_3$$4, "get_parent_class", &_4, 89, _class);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(_class, &_3$$4);
		} while (zephir_is_true(_class));
		ZEPHIR_CPY_WRT(&traitsToSearch, &traits);
		while (1) {
			if (!(!(ZEPHIR_IS_EMPTY(&traitsToSearch)))) {
				break;
			}
			ZEPHIR_MAKE_REF(&traitsToSearch);
			ZEPHIR_CALL_FUNCTION(&_5$$5, "array_pop", &_6, 90, &traitsToSearch);
			ZEPHIR_UNREF(&traitsToSearch);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&newTraits, "class_uses", &_2, 88, &_5$$5);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(&traits, &newTraits);
			ZEPHIR_ADD_ASSIGN(&traitsToSearch, &newTraits);
		}
		zephir_is_iterable(&traits, 1, "moon/Component/DI/Resolver/Reflector.zep", 141);
		if (Z_TYPE_P(&traits) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&traits), _7$$3)
			{
				ZEPHIR_INIT_NVAR(&trait$$3);
				ZVAL_COPY(&trait$$3, _7$$3);
				ZEPHIR_CALL_FUNCTION(&_9$$6, "class_uses", &_2, 88, &trait$$3);
				zephir_check_call_status();
				ZEPHIR_ADD_ASSIGN(&traits, &_9$$6);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &traits, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_8$$3, &traits, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&trait$$3, &traits, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_10$$7, "class_uses", &_2, 88, &trait$$3);
					zephir_check_call_status();
					ZEPHIR_ADD_ASSIGN(&traits, &_10$$7);
				ZEPHIR_CALL_METHOD(NULL, &traits, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&trait$$3);
		ZEPHIR_CALL_FUNCTION(&_11$$3, "array_unique", NULL, 91, &traits);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("traits"), _class, &_11$$3);
	}
	zephir_read_property(&_12, this_ptr, ZEND_STRL("traits"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_13, &_12, _class, PH_NOISY | PH_READONLY, "moon/Component/DI/Resolver/Reflector.zep", 143);
	RETURN_CTOR(&_13);

}

zend_object *zephir_init_properties_Moon_Component_DI_Resolver_Reflector(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("traits"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("traits"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("classes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("classes"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

