
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "Zend/zend_closures.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"


/**
 * FileName: Argument.php
 * User: solely
 * DateTime: 2020/6/26 19:55
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Router_Argument) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Router, Argument, moon, component_router_argument, moon_component_router_argument_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Router_Argument, resolverArgument) {

	zend_bool _0, _9$$6, _17$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *handler, handler_sub, *params_param = NULL, type, reflection, arguments, param, _5, *_6, _7, _1$$3, _2$$3, _3$$4, _4$$4, _10$$6, _12$$7, _13$$8, _14$$8, _15$$8, _18$$9, _19$$10, _20$$11, _21$$11, _22$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &handler, &params_param);

	zephir_get_arrval(&params, params_param);


	ZEPHIR_INIT_VAR(&arguments);
	array_init(&arguments);
	_0 = Z_TYPE_P(handler) == IS_OBJECT;
	if (_0) {
		_0 = !((zephir_instance_of_ev(handler, zend_ce_closure)));
	}
	if (Z_TYPE_P(handler) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&reflection);
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionmethod")));
		zephir_array_fetch_long(&_1$$3, handler, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Argument.zep", 18);
		zephir_array_fetch_long(&_2$$3, handler, 1, PH_NOISY | PH_READONLY, "moon/Component/Router/Argument.zep", 18);
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 31, &_1$$3, &_2$$3);
		zephir_check_call_status();
	} else if (_0) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, zephir_get_internal_ce(SL("reflectionobject")));
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 28, handler);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "__invoke");
		ZEPHIR_CALL_METHOD(&reflection, &_3$$4, "getmethod", NULL, 29, &_4$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&reflection);
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 26, handler);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_5, &reflection, "getparameters", NULL, 27);
	zephir_check_call_status();
	zephir_is_iterable(&_5, 0, "moon/Component/Router/Argument.zep", 33);
	if (Z_TYPE_P(&_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
		{
			ZEPHIR_INIT_NVAR(&param);
			ZVAL_COPY(&param, _6);
			ZEPHIR_CALL_METHOD(&type, this_ptr, "gettype", &_8, 265, &param, &reflection);
			zephir_check_call_status();
			_9$$6 = zephir_is_true(&type);
			if (_9$$6) {
				ZEPHIR_CALL_METHOD(&_10$$6, this_ptr, "isrequestclass", &_11, 266, &type);
				zephir_check_call_status();
				_9$$6 = zephir_is_true(&_10$$6);
			}
			if (_9$$6) {
				zephir_array_fetch_string(&_12$$7, &params, SL("_request"), PH_NOISY | PH_READONLY, "moon/Component/Router/Argument.zep", 28);
				zephir_array_append(&arguments, &_12$$7, PH_SEPARATE, "moon/Component/Router/Argument.zep", 28);
			} else {
				ZEPHIR_INIT_NVAR(&_13$$8);
				ZEPHIR_CALL_METHOD(&_14$$8, &param, "getname", NULL, 0);
				zephir_check_call_status();
				if (zephir_array_isset(&params, &_14$$8)) {
					ZEPHIR_OBS_NVAR(&_13$$8);
					ZEPHIR_CALL_METHOD(&_15$$8, &param, "getname", NULL, 0);
					zephir_check_call_status();
					zephir_array_fetch(&_13$$8, &params, &_15$$8, PH_NOISY, "moon/Component/Router/Argument.zep", 30);
				} else {
					ZEPHIR_MAKE_REF(&params);
					ZEPHIR_CALL_FUNCTION(&_13$$8, "array_shift", &_16, 169, &params);
					ZEPHIR_UNREF(&params);
					zephir_check_call_status();
				}
				zephir_array_append(&arguments, &_13$$8, PH_SEPARATE, "moon/Component/Router/Argument.zep", 30);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_5, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &_5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&param, &_5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&type, this_ptr, "gettype", &_8, 265, &param, &reflection);
				zephir_check_call_status();
				_17$$9 = zephir_is_true(&type);
				if (_17$$9) {
					ZEPHIR_CALL_METHOD(&_18$$9, this_ptr, "isrequestclass", &_11, 266, &type);
					zephir_check_call_status();
					_17$$9 = zephir_is_true(&_18$$9);
				}
				if (_17$$9) {
					zephir_array_fetch_string(&_19$$10, &params, SL("_request"), PH_NOISY | PH_READONLY, "moon/Component/Router/Argument.zep", 28);
					zephir_array_append(&arguments, &_19$$10, PH_SEPARATE, "moon/Component/Router/Argument.zep", 28);
				} else {
					ZEPHIR_INIT_NVAR(&_20$$11);
					ZEPHIR_CALL_METHOD(&_21$$11, &param, "getname", NULL, 0);
					zephir_check_call_status();
					if (zephir_array_isset(&params, &_21$$11)) {
						ZEPHIR_OBS_NVAR(&_20$$11);
						ZEPHIR_CALL_METHOD(&_22$$11, &param, "getname", NULL, 0);
						zephir_check_call_status();
						zephir_array_fetch(&_20$$11, &params, &_22$$11, PH_NOISY, "moon/Component/Router/Argument.zep", 30);
					} else {
						ZEPHIR_MAKE_REF(&params);
						ZEPHIR_CALL_FUNCTION(&_20$$11, "array_shift", &_16, 169, &params);
						ZEPHIR_UNREF(&params);
						zephir_check_call_status();
					}
					zephir_array_append(&arguments, &_20$$11, PH_SEPARATE, "moon/Component/Router/Argument.zep", 30);
				}
			ZEPHIR_CALL_METHOD(NULL, &_5, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&param);
	RETURN_CCTOR(&arguments);

}

/**
 * @param \ReflectionParameter $parameter
 * @param \ReflectionFunctionAbstract $function
 * @return string|null
 */
PHP_METHOD(Moon_Component_Router_Argument, getType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameter, parameter_sub, *_function, _function_sub, parent, lcName, name, type, _0$$5, _1$$5, _2$$6, _3$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameter_sub);
	ZVAL_UNDEF(&_function_sub);
	ZVAL_UNDEF(&parent);
	ZVAL_UNDEF(&lcName);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &parameter, &_function);



	ZEPHIR_CALL_METHOD(&type, parameter, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!zephir_is_true(&type)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&name, &type, "getname", NULL, 0);
	zephir_check_call_status();
	if (zephir_instance_of_ev(_function, zephir_get_internal_ce(SL("reflectionmethod")))) {
		ZEPHIR_INIT_VAR(&lcName);
		zephir_fast_strtolower(&lcName, &name);
		do {
			if (ZEPHIR_IS_STRING(&lcName, "self")) {
				ZEPHIR_CALL_METHOD(&_0$$5, _function, "getdeclaringclass", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_OBS_VAR(&_1$$5);
				zephir_read_property(&_1$$5, &_0$$5, ZEND_STRL("name"), PH_NOISY_CC);
				RETURN_CCTOR(&_1$$5);
			}
			if (ZEPHIR_IS_STRING(&lcName, "parent")) {
				ZEPHIR_CALL_METHOD(&_2$$6, _function, "getdeclaringclass", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&parent, &_2$$6, "getparentclass", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_3$$6);
				if (zephir_is_true(&parent)) {
					zephir_read_property(&_3$$6, &parent, ZEND_STRL("name"), PH_NOISY_CC);
				} else {
					ZVAL_NULL(&_3$$6);
				}
				RETURN_CCTOR(&_3$$6);
			}
		} while(0);

	}
	RETURN_CCTOR(&name);

}

PHP_METHOD(Moon_Component_Router_Argument, getRequestClass) {

	zval *this_ptr = getThis();


	RETURN_STRING("Psr\\Http\\Message\\RequestInterface");

}

PHP_METHOD(Moon_Component_Router_Argument, isRequestClass) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_class, _class_sub, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_class_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_class);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getrequestclass", &_1, 267);
	zephir_check_call_status();
	if (ZEPHIR_IS_EQUAL(_class, &_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getrequestclass", &_1, 267);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("is_subclass_of", NULL, 268, _class, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

