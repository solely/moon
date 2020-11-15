
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * FileName: Handler.php
 * User: solely
 * DateTime: 2020/10/2 23:01
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Router_Handler) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Router, Handler, moon, component_router_handler, moon_component_router_handler_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Router_Handler, resolverHandler) {

	zend_bool _0$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler, handler_sub, _callable, _1$$3, e$$4, _5$$4, _3$$5, _4$$5, reflectionException$$6, _10$$6, _6$$7, _7$$7, _8$$7, _9$$7, reflectionException$$11, _15$$11, _11$$12, _12$$12, _13$$12, _14$$12, _16$$15, _17$$15, _18$$15, _19$$15, _21$$17, _22$$17, _23$$17, _24$$17, _25$$19, _26$$19, _27$$19, _28$$19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_callable);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&e$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&reflectionException$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&reflectionException$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$19);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &handler);

	ZEPHIR_SEPARATE_PARAM(handler);


	if (Z_TYPE_P(handler) == IS_ARRAY) {
		_0$$3 = zephir_array_isset_long(handler, 0);
		if (_0$$3) {
			zephir_array_fetch_long(&_1$$3, handler, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Handler.zep", 16);
			_0$$3 = Z_TYPE_P(&_1$$3) == IS_STRING;
		}
		_2$$3 = _0$$3;
		if (_2$$3) {
			_2$$3 = zephir_array_isset_long(handler, 1);
		}
		if (_2$$3) {

			/* try_start_1: */

				zephir_array_fetch_long(&_4$$5, handler, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Handler.zep", 19);
				ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "instantiatehandler", NULL, 150, &_4$$5);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_array_update_long(handler, 0, &_3$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);

			try_end_1:

			if (EG(exception)) {
				ZEPHIR_INIT_VAR(&_5$$4);
				ZVAL_OBJ(&_5$$4, EG(exception));
				Z_ADDREF_P(&_5$$4);
				if (zephir_instance_of_ev(&_5$$4, zephir_get_internal_ce(SL("error")))) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e$$4, &_5$$4);

					/* try_start_2: */

						ZEPHIR_INIT_VAR(&_6$$7);
						object_init_ex(&_6$$7, zephir_get_internal_ce(SL("reflectionmethod")));
						zephir_array_fetch_long(&_7$$7, handler, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Handler.zep", 26);
						zephir_array_fetch_long(&_8$$7, handler, 1, PH_NOISY | PH_READONLY, "moon/Component/Router/Handler.zep", 26);
						ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 23, &_7$$7, &_8$$7);
						zephir_check_call_status_or_jump(try_end_2);
						ZEPHIR_CALL_METHOD(&_9$$7, &_6$$7, "isstatic", NULL, 151);
						zephir_check_call_status_or_jump(try_end_2);
						if (zephir_is_true(&_9$$7)) {
							RETVAL_ZVAL(handler, 1, 0);
							RETURN_MM();
						}

					try_end_2:

					if (EG(exception)) {
						ZEPHIR_INIT_VAR(&_10$$6);
						ZVAL_OBJ(&_10$$6, EG(exception));
						Z_ADDREF_P(&_10$$6);
						if (zephir_instance_of_ev(&_10$$6, zephir_get_internal_ce(SL("reflectionexception")))) {
							zend_clear_exception(TSRMLS_C);
							ZEPHIR_CPY_WRT(&reflectionException$$6, &_10$$6);
							zephir_throw_exception_debug(&e$$4, "moon/Component/Router/Handler.zep", 30);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					zephir_throw_exception_debug(&e$$4, "moon/Component/Router/Handler.zep", 32);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					if (zephir_instance_of_ev(&_5$$4, spl_ce_LogicException)) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(&e$$4, &_5$$4);

						/* try_start_3: */

							ZEPHIR_INIT_VAR(&_11$$12);
							object_init_ex(&_11$$12, zephir_get_internal_ce(SL("reflectionmethod")));
							zephir_array_fetch_long(&_12$$12, handler, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Handler.zep", 26);
							zephir_array_fetch_long(&_13$$12, handler, 1, PH_NOISY | PH_READONLY, "moon/Component/Router/Handler.zep", 26);
							ZEPHIR_CALL_METHOD(NULL, &_11$$12, "__construct", NULL, 23, &_12$$12, &_13$$12);
							zephir_check_call_status_or_jump(try_end_3);
							ZEPHIR_CALL_METHOD(&_14$$12, &_11$$12, "isstatic", NULL, 151);
							zephir_check_call_status_or_jump(try_end_3);
							if (zephir_is_true(&_14$$12)) {
								RETVAL_ZVAL(handler, 1, 0);
								RETURN_MM();
							}

						try_end_3:

						if (EG(exception)) {
							ZEPHIR_INIT_VAR(&_15$$11);
							ZVAL_OBJ(&_15$$11, EG(exception));
							Z_ADDREF_P(&_15$$11);
							if (zephir_instance_of_ev(&_15$$11, zephir_get_internal_ce(SL("reflectionexception")))) {
								zend_clear_exception(TSRMLS_C);
								ZEPHIR_CPY_WRT(&reflectionException$$11, &_15$$11);
								zephir_throw_exception_debug(&e$$4, "moon/Component/Router/Handler.zep", 30);
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						zephir_throw_exception_debug(&e$$4, "moon/Component/Router/Handler.zep", 32);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		if (zephir_is_callable(handler) != 1) {
			ZEPHIR_INIT_VAR(&_16$$15);
			object_init_ex(&_16$$15, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_17$$15);
			zephir_get_class(&_17$$15, handler, 0);
			ZEPHIR_INIT_VAR(&_18$$15);
			ZVAL_STRING(&_18$$15, "The handler \"%s\" is not callable: ");
			ZEPHIR_CALL_FUNCTION(&_19$$15, "sprintf", &_20, 3, &_18$$15, &_17$$15);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_16$$15, "__construct", NULL, 25, &_19$$15);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_16$$15, "moon/Component/Router/Handler.zep", 36);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETVAL_ZVAL(handler, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(handler) == IS_OBJECT) {
		if (zephir_is_callable(handler) != 1) {
			ZEPHIR_INIT_VAR(&_21$$17);
			object_init_ex(&_21$$17, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_22$$17);
			zephir_get_class(&_22$$17, handler, 0);
			ZEPHIR_INIT_VAR(&_23$$17);
			ZVAL_STRING(&_23$$17, "The handler \"%s\" is not callable: ");
			ZEPHIR_CALL_FUNCTION(&_24$$17, "sprintf", &_20, 3, &_23$$17, &_22$$17);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_21$$17, "__construct", NULL, 25, &_24$$17);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_21$$17, "moon/Component/Router/Handler.zep", 42);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETVAL_ZVAL(handler, 1, 0);
		RETURN_MM();
	}
	if ((zephir_function_exists(handler)  == SUCCESS)) {
		RETVAL_ZVAL(handler, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_callable, this_ptr, "createhandler", NULL, 152, handler);
	zephir_check_call_status();
	if (zephir_is_callable(&_callable) != 1) {
		ZEPHIR_INIT_VAR(&_25$$19);
		object_init_ex(&_25$$19, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_26$$19);
		zephir_get_class(&_26$$19, handler, 0);
		ZEPHIR_INIT_VAR(&_27$$19);
		ZVAL_STRING(&_27$$19, "The handler \"%s\" is not callable: ");
		ZEPHIR_CALL_FUNCTION(&_28$$19, "sprintf", &_20, 3, &_27$$19, &_26$$19);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_25$$19, "__construct", NULL, 25, &_28$$19);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_25$$19, "moon/Component/Router/Handler.zep", 51);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_callable);

}

PHP_METHOD(Moon_Component_Router_Handler, instantiateHandler) {

	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_class_param = NULL, _0;
	zval _class;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_class);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_class_param);

	zephir_get_strval(&_class, _class_param);


	zephir_fetch_safe_class(&_0, &_class);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Router_Handler, createHandler) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *_handler_param = NULL, handler, classAndMethod, _class, method, _0, _1, e, _8, _2$$3, _3$$3, _4$$3, _6$$4, _7$$4, reflectionException$$5, _11$$5, _9$$6, _10$$6, reflectionException$$10, _14$$10, _12$$11, _13$$11, _15$$14, _16$$14, _17$$14, _18$$14;
	zval _handler;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_handler);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&classAndMethod);
	ZVAL_UNDEF(&_class);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&reflectionException$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&reflectionException$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$14);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_handler_param);

	zephir_get_strval(&_handler, _handler_param);


	ZEPHIR_CPY_WRT(&handler, &_handler);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "::");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &handler, &_0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "The string \"%s\" must contain \"::\"");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", &_5, 3, &_3$$3, &handler);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 25, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "moon/Component/Router/Handler.zep", 70);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&classAndMethod);
	zephir_fast_explode_str(&classAndMethod, SL("::"), &handler, 2 );
	ZEPHIR_OBS_VAR(&_class);
	zephir_array_fetch_long(&_class, &classAndMethod, 0, PH_NOISY, "moon/Component/Router/Handler.zep", 73);
	ZEPHIR_OBS_VAR(&method);
	zephir_array_fetch_long(&method, &classAndMethod, 1, PH_NOISY, "moon/Component/Router/Handler.zep", 74);

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_create_array(&_6$$4, 2, 0);
		ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "instantiatehandler", NULL, 150, &_class);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_array_fast_append(&_6$$4, &_7$$4);
		zephir_array_fast_append(&_6$$4, &method);
		ZEPHIR_CPY_WRT(&handler, &_6$$4);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_OBJ(&_8, EG(exception));
		Z_ADDREF_P(&_8);
		if (zephir_instance_of_ev(&_8, zephir_get_internal_ce(SL("error")))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_8);

			/* try_start_2: */

				ZEPHIR_INIT_VAR(&_9$$6);
				object_init_ex(&_9$$6, zephir_get_internal_ce(SL("reflectionmethod")));
				ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", NULL, 23, &_class, &method);
				zephir_check_call_status_or_jump(try_end_2);
				ZEPHIR_CALL_METHOD(&_10$$6, &_9$$6, "isstatic", NULL, 151);
				zephir_check_call_status_or_jump(try_end_2);
				if (zephir_is_true(&_10$$6)) {
					ZEPHIR_CONCAT_VSV(return_value, &_class, "::", &method);
					RETURN_MM();
				}

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_VAR(&_11$$5);
				ZVAL_OBJ(&_11$$5, EG(exception));
				Z_ADDREF_P(&_11$$5);
				if (zephir_instance_of_ev(&_11$$5, zephir_get_internal_ce(SL("reflectionexception")))) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&reflectionException$$5, &_11$$5);
					zephir_throw_exception_debug(&e, "moon/Component/Router/Handler.zep", 85);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_throw_exception_debug(&e, "moon/Component/Router/Handler.zep", 87);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			if (zephir_instance_of_ev(&_8, spl_ce_LogicException)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_8);

				/* try_start_3: */

					ZEPHIR_INIT_VAR(&_12$$11);
					object_init_ex(&_12$$11, zephir_get_internal_ce(SL("reflectionmethod")));
					ZEPHIR_CALL_METHOD(NULL, &_12$$11, "__construct", NULL, 23, &_class, &method);
					zephir_check_call_status_or_jump(try_end_3);
					ZEPHIR_CALL_METHOD(&_13$$11, &_12$$11, "isstatic", NULL, 151);
					zephir_check_call_status_or_jump(try_end_3);
					if (zephir_is_true(&_13$$11)) {
						ZEPHIR_CONCAT_VSV(return_value, &_class, "::", &method);
						RETURN_MM();
					}

				try_end_3:

				if (EG(exception)) {
					ZEPHIR_INIT_VAR(&_14$$10);
					ZVAL_OBJ(&_14$$10, EG(exception));
					Z_ADDREF_P(&_14$$10);
					if (zephir_instance_of_ev(&_14$$10, zephir_get_internal_ce(SL("reflectionexception")))) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(&reflectionException$$10, &_14$$10);
						zephir_throw_exception_debug(&e, "moon/Component/Router/Handler.zep", 85);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_throw_exception_debug(&e, "moon/Component/Router/Handler.zep", 87);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	if (zephir_is_callable(&handler) != 1) {
		ZEPHIR_INIT_VAR(&_15$$14);
		object_init_ex(&_15$$14, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_16$$14);
		zephir_get_class(&_16$$14, &handler, 0);
		ZEPHIR_INIT_VAR(&_17$$14);
		ZVAL_STRING(&_17$$14, "The handler \"%s\" is not callable: ");
		ZEPHIR_CALL_FUNCTION(&_18$$14, "sprintf", &_5, 3, &_17$$14, &_16$$14);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_15$$14, "__construct", NULL, 25, &_18$$14);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_15$$14, "moon/Component/Router/Handler.zep", 90);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&handler);

}

