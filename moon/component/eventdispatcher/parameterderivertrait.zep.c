
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "Zend/zend_closures.h"


/**
 * FileName: ParameterDeriverTrait.php
 * User: solely
 * DateTime: 2020/10/5 15:19
 * Description:
 *
 */
/**
 * Utility trait to derive the type of event an event listener is for.
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ParameterDeriverTrait) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\EventDispatcher, ParameterDeriverTrait, moon, component_eventdispatcher_parameterderivertrait, moon_component_eventdispatcher_parameterderivertrait_method_entry, 0);

	return SUCCESS;

}

/**
 * Derives the class type of the first argument of a callable.
 *
 * @param callable $callable
 *   The callable for which we want the parameter type.
 * @return string
 *   The class the parameter is type hinted on.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, getParameterType) {

	zend_bool _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_callable, _callable_sub, type, rType, params, reflect, e, _19, _0$$3, _1$$3, _3$$3, _4$$3, _5$$3, _16$$3, _6$$4, _7$$4, _8$$4, _9$$6, _10$$6, _11$$6, _12$$7, _13$$7, _14$$8, _15$$8, _17$$9, _18$$9, _20$$10, _21$$10, _22$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_callable_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&rType);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&reflect);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_callable);




	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "isclasscallable", NULL, 0, _callable);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "isfunctioncallable", NULL, 0, _callable);
		zephir_check_call_status_or_jump(try_end_1);
		_2$$3 = zephir_is_true(&_1$$3);
		if (!(_2$$3)) {
			ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "isclosurecallable", NULL, 0, _callable);
			zephir_check_call_status_or_jump(try_end_1);
			_2$$3 = zephir_is_true(&_3$$3);
		}
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "isobjectcallable", NULL, 0, _callable);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "isinvokable", NULL, 16, _callable);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_is_true(&_0$$3)) {
			ZEPHIR_INIT_VAR(&reflect);
			object_init_ex(&reflect, zephir_get_internal_ce(SL("reflectionclass")));
			zephir_array_fetch_long(&_6$$4, _callable, 0, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ParameterDeriverTrait.zep", 61);
			ZEPHIR_CALL_METHOD(NULL, &reflect, "__construct", NULL, 17, &_6$$4);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_array_fetch_long(&_8$$4, _callable, 1, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ParameterDeriverTrait.zep", 62);
			ZEPHIR_CALL_METHOD(&_7$$4, &reflect, "getmethod", NULL, 18, &_8$$4);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&params, &_7$$4, "getparameters", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		} else if (_2$$3) {
			ZEPHIR_INIT_NVAR(&reflect);
			object_init_ex(&reflect, zephir_get_internal_ce(SL("reflectionfunction")));
			ZEPHIR_CALL_METHOD(NULL, &reflect, "__construct", NULL, 19, _callable);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&params, &reflect, "getparameters", NULL, 20);
			zephir_check_call_status_or_jump(try_end_1);
		} else if (zephir_is_true(&_4$$3)) {
			ZEPHIR_INIT_NVAR(&reflect);
			object_init_ex(&reflect, zephir_get_internal_ce(SL("reflectionobject")));
			zephir_array_fetch_long(&_9$$6, _callable, 0, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ParameterDeriverTrait.zep", 67);
			ZEPHIR_CALL_METHOD(NULL, &reflect, "__construct", NULL, 21, &_9$$6);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_array_fetch_long(&_11$$6, _callable, 1, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ParameterDeriverTrait.zep", 68);
			ZEPHIR_CALL_METHOD(&_10$$6, &reflect, "getmethod", NULL, 22, &_11$$6);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&params, &_10$$6, "getparameters", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		} else if (zephir_is_true(&_5$$3)) {
			ZEPHIR_INIT_VAR(&_12$$7);
			object_init_ex(&_12$$7, zephir_get_internal_ce(SL("reflectionmethod")));
			ZEPHIR_INIT_VAR(&_13$$7);
			ZVAL_STRING(&_13$$7, "__invoke");
			ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", NULL, 23, _callable, &_13$$7);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&params, &_12$$7, "getparameters", NULL, 24);
			zephir_check_call_status_or_jump(try_end_1);
		} else {
			ZEPHIR_INIT_VAR(&_14$$8);
			object_init_ex(&_14$$8, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_15$$8);
			ZVAL_STRING(&_15$$8, "Not a recognized type of callable");
			ZEPHIR_CALL_METHOD(NULL, &_14$$8, "__construct", NULL, 25, &_15$$8);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(&_14$$8, "moon/Component/EventDispatcher/ParameterDeriverTrait.zep", 72);
			goto try_end_1;

		}
		zephir_array_fetch_long(&_16$$3, &params, 0, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ParameterDeriverTrait.zep", 75);
		ZEPHIR_CALL_METHOD(&rType, &_16$$3, "gettype", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(&rType) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_17$$9);
			object_init_ex(&_17$$9, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_18$$9);
			ZVAL_STRING(&_18$$9, "Listeners must declare an object type they can accept");
			ZEPHIR_CALL_METHOD(NULL, &_17$$9, "__construct", NULL, 25, &_18$$9);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(&_17$$9, "moon/Component/EventDispatcher/ParameterDeriverTrait.zep", 77);
			goto try_end_1;

		}
		ZEPHIR_CALL_METHOD(&type, &rType, "getname", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_19);
		ZVAL_OBJ(&_19, EG(exception));
		Z_ADDREF_P(&_19);
		if (zephir_instance_of_ev(&_19, zephir_get_internal_ce(SL("reflectionexception")))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_19);
			ZEPHIR_INIT_VAR(&_20$$10);
			object_init_ex(&_20$$10, spl_ce_RuntimeException);
			ZEPHIR_INIT_VAR(&_21$$10);
			ZVAL_STRING(&_21$$10, "Type error registering listener");
			ZVAL_LONG(&_22$$10, 0);
			ZEPHIR_CALL_METHOD(NULL, &_20$$10, "__construct", NULL, 26, &_21$$10, &_22$$10, &e);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_20$$10, "moon/Component/EventDispatcher/ParameterDeriverTrait.zep", 81);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&type);

}

/**
 * Determines if a callable represents a function.
 *
 * Or at least a reasonable approximation, since a function name may not be defined yet.
 *
 * @param callable $callable
 * @return True if the callable represents a function, false otherwise.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, isFunctionCallable) {

	zend_bool _0, _1;
	zval *_callable, _callable_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_callable_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &_callable);



	_0 = (zephir_is_callable(_callable) == 1);
	if (_0) {
		_0 = (Z_TYPE_P(_callable) != IS_ARRAY);
	}
	_1 = _0;
	if (_1) {
		_1 = Z_TYPE_P(_callable) == IS_STRING;
	}
	RETURN_BOOL(_1);

}

/**
 * Determines if a callable represents a closure/anonymous function.
 *
 * @param callable $callable
 * @return True if the callable represents a closure object, false otherwise.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, isClosureCallable) {

	zend_bool _0, _1;
	zval *_callable, _callable_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_callable_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &_callable);



	_0 = (zephir_is_callable(_callable) == 1);
	if (_0) {
		_0 = (Z_TYPE_P(_callable) != IS_ARRAY);
	}
	_1 = _0;
	if (_1) {
		_1 = (zephir_instance_of_ev(_callable, zend_ce_closure));
	}
	RETURN_BOOL(_1);

}

/**
 * Determines if a callable represents a method on an object.
 *
 * @param callable $callable
 * @return True if the callable represents a method object, false otherwise.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, isObjectCallable) {

	zend_bool _0, _1;
	zval *_callable, _callable_sub, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_callable_sub);
	ZVAL_UNDEF(&_2);

	zephir_fetch_params_without_memory_grow(1, 0, &_callable);



	_0 = (zephir_is_callable(_callable) == 1);
	if (_0) {
		_0 = Z_TYPE_P(_callable) == IS_ARRAY;
	}
	_1 = _0;
	if (_1) {
		zephir_array_fetch_long(&_2, _callable, 0, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ParameterDeriverTrait.zep", 119);
		_1 = Z_TYPE_P(&_2) == IS_OBJECT;
	}
	RETURN_BOOL(_1);

}

/**
 * Determines if a callable represents a static class method.
 *
 * The parameter here is untyped so that this method may be called with an
 * array that represents a class name and a non-static method.  The routine
 * to determine the parameter type is identical to a static method, but such
 * an array is still not technically callable.  Omitting the parameter type here
 * allows us to use this method to handle both cases.
 *
 * Note that this method must therefore be the first in the switch statement
 * above, or else subsequent calls will break as the array is not going to satisfy
 * the callable type hint but it would pass `is_callable()`.  Because PHP.
 *
 * @param callable $callable
 * @return True if the callable represents a static method, false otherwise.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, isClassCallable) {

	zend_bool _0, _2;
	zval *_callable, _callable_sub, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_callable_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	zephir_fetch_params_without_memory_grow(1, 0, &_callable);



	_0 = Z_TYPE_P(_callable) == IS_ARRAY;
	if (_0) {
		zephir_array_fetch_long(&_1, _callable, 0, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ParameterDeriverTrait.zep", 140);
		_0 = Z_TYPE_P(&_1) == IS_STRING;
	}
	_2 = _0;
	if (_2) {
		zephir_array_fetch_long(&_3, _callable, 0, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ParameterDeriverTrait.zep", 140);
		_2 = zephir_class_exists(&_3, 1);
	}
	RETURN_BOOL(_2);

}

/**
 * Determines if a callable is a class that has __invoke() method
 *
 * @param callable $callable
 * @return True if the callable represents an invokable object, false otherwise.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, isInvokable) {

	zend_bool _0;
	zval *_callable, _callable_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_callable_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &_callable);



	_0 = (zephir_is_callable(_callable) == 1);
	if (_0) {
		_0 = Z_TYPE_P(_callable) == IS_OBJECT;
	}
	RETURN_BOOL(_0);

}

