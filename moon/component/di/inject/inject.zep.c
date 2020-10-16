
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"


/**
 * FileName: Inject.php
 * User: solely
 * DateTime: 2019/6/23 22:52
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Inject_Inject) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI\\Inject, Inject, moon, component_di_inject_inject, moon_component_di_inject_inject_method_entry, 0);

	zend_declare_property_null(moon_component_di_inject_inject_ce, SL("className"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_di_inject_inject_ce, SL("arguments"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_di_inject_inject_ce, SL("callMethods"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_di_inject_inject_ce, SL("isLazy"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_di_inject_inject_ce, SL("_callable"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_di_inject_inject_ce, SL("_object"), ZEND_ACC_PROTECTED);

	moon_component_di_inject_inject_ce->create_object = zephir_init_properties_Moon_Component_DI_Inject_Inject;
	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Inject_Inject, __invoke) {

	zval medium, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&medium);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_callable"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		RETURN_MM_MEMBER(getThis(), "_callable");
	}
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_object"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_1))) {
		RETURN_MM_MEMBER(getThis(), "_object");
	}
	ZEPHIR_INIT_VAR(&medium);
	object_init_ex(&medium, moon_component_di_resolver_medium_ce);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("className"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("callMethods"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("isLazy"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &medium, "__construct", NULL, 21, &_2, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, ZEND_STRL("isLazy"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_6)) {
		RETURN_CCTOR(&medium);
	}
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, moon_component_di_resolver_resolver_ce);
	ZEPHIR_CALL_CE_STATIC(&_8, moon_component_di_resolver_reflector_ce, "getinstance", &_9, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 22, &_8);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_7, "resolve", NULL, 23, &medium);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param mixed $className
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, setClassName) {

	zval *className, className_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &className);



	zephir_update_property_zval(this_ptr, ZEND_STRL("className"), className);

}

/**
 * @return mixed
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, getClassName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "className");

}

/**
 * @param array $arguments
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, setArguments) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *arguments_param = NULL;
	zval arguments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arguments_param);

	zephir_get_arrval(&arguments, arguments_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("arguments"), &arguments);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return array
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, getArguments) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "arguments");

}

/**
 * @param array $callMethods
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, setCallMethods) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *callMethods_param = NULL;
	zval callMethods;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callMethods);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callMethods_param);

	zephir_get_arrval(&callMethods, callMethods_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("callMethods"), &callMethods);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return array
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, getCallMethods) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "callMethods");

}

/**
 * @param mixed $isLazy
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, setIsLazy) {

	zval *isLazy, isLazy_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&isLazy_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &isLazy);



	zephir_update_property_zval(this_ptr, ZEND_STRL("isLazy"), isLazy);

}

/**
 * @return mixed
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, getIsLazy) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "isLazy");

}

/**
 * @param callable $callable
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, setCallable) {

	zval *_callable, _callable_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_callable_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &_callable);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_callable"), _callable);

}

/**
 * @return null | callable
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, getCallable) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_callable");

}

/**
 * @param object $object
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, setObject) {

	zval *_object, _object_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_object_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &_object);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_object"), _object);

}

/**
 * @return null | object
 */
PHP_METHOD(Moon_Component_DI_Inject_Inject, getObject) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_object");

}

zend_object *zephir_init_properties_Moon_Component_DI_Inject_Inject(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("callMethods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("callMethods"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("arguments"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("arguments"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

