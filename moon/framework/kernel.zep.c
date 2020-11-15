
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * FileName: Kernel.php
 * User: solely
 * DateTime: 2020/7/15 0:03
 * Description:  处理请求的类
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Kernel) {

	ZEPHIR_REGISTER_CLASS(Moon\\Framework, Kernel, moon, framework_kernel, moon_framework_kernel_method_entry, 0);

	zend_declare_property_null(moon_framework_kernel_ce, SL("container"), ZEND_ACC_PRIVATE);

	/** @var EventDispatcherInterface */
	zend_declare_property_null(moon_framework_kernel_ce, SL("dispatcher"), ZEND_ACC_PRIVATE);

	/** @var Router */
	zend_declare_property_null(moon_framework_kernel_ce, SL("router"), ZEND_ACC_PRIVATE);

	/** @var ControllerResolverInterface */
	zend_declare_property_null(moon_framework_kernel_ce, SL("resolver"), ZEND_ACC_PRIVATE);

	/** @var ControllerArgumentsResolverInterface */
	zend_declare_property_null(moon_framework_kernel_ce, SL("argumentsResolver"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Kernel, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "dispatcher");
	ZEPHIR_CALL_METHOD(&_0, container, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("dispatcher"), &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "router");
	ZEPHIR_CALL_METHOD(&_2, container, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("router"), &_2);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "controller_resolver");
	ZEPHIR_CALL_METHOD(&_3, container, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("resolver"), &_3);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "controller_arguments_resolver");
	ZEPHIR_CALL_METHOD(&_4, container, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("argumentsResolver"), &_4);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Kernel, handle) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *_catch = NULL, _catch_sub, __$true, msg, response, arguments, controller, route, event, e, _22, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$3, _6$$4, _16$$5, _17$$5, _18$$5, _19$$5, _20$$7, _21$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_catch_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &_catch);

	if (!_catch) {
		_catch = &_catch_sub;
		_catch = &__$true;
	}



	/* try_start_1: */

		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "request");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "set", NULL, 0, &_1$$3, request);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&event);
		object_init_ex(&event, moon_framework_event_event_requestevent_ce);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 180, request, &_2$$3, &_3$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("dispatcher"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "dispatch", NULL, 0, &event);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_5$$3, &event, "hasresponse", NULL, 181);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_is_true(&_5$$3)) {
			ZEPHIR_CALL_METHOD(&_6$$4, &event, "getresponse", NULL, 182);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filterresponse", &_7, 183, &_6$$4, request);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(&route, &event, "getroute", NULL, 184);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("resolver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&controller, &_8$$3, "getcontroller", NULL, 0, &route);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_NVAR(&event);
		object_init_ex(&event, moon_framework_event_event_controllerevent_ce);
		zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 185, request, &_9$$3, &controller, &_10$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_property(&_11$$3, this_ptr, ZEND_STRL("dispatcher"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_11$$3, "dispatch", NULL, 0, &event);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_property(&_12$$3, this_ptr, ZEND_STRL("argumentsResolver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&arguments, &_12$$3, "getarguments", NULL, 0, request, &route, &controller);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_NVAR(&event);
		object_init_ex(&event, moon_framework_event_event_controllerargumentsevent_ce);
		zephir_read_property(&_13$$3, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_14$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 186, request, &_13$$3, &controller, &arguments, &_14$$3);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_property(&_15$$3, this_ptr, ZEND_STRL("dispatcher"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_15$$3, "dispatch", NULL, 0, &event);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&controller, &event, "getcontroller", NULL, 187);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&arguments, &event, "getarguments", NULL, 188);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&response);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&response, &controller, &arguments);
		zephir_check_call_status_or_jump(try_end_1);
		if (!((zephir_instance_of_ev(&response, moon_component_http_message_response_ce)))) {
			ZEPHIR_INIT_NVAR(&event);
			object_init_ex(&event, moon_framework_event_event_viewevent_ce);
			zephir_read_property(&_16$$5, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_17$$5, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 189, request, &_16$$5, &response, &_17$$5);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_read_property(&_18$$5, this_ptr, ZEND_STRL("dispatcher"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_18$$5, "dispatch", NULL, 0, &event);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&_19$$5, &event, "hasresponse", NULL, 181);
			zephir_check_call_status_or_jump(try_end_1);
			if (zephir_is_true(&_19$$5)) {
				ZEPHIR_CALL_METHOD(&response, &event, "getresponse", NULL, 182);
				zephir_check_call_status_or_jump(try_end_1);
			} else {
				ZEPHIR_CALL_METHOD(&_20$$7, this_ptr, "vartostring", NULL, 190, &response);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_INIT_VAR(&_21$$7);
				ZVAL_STRING(&_21$$7, "The controller must return a \"Moon\\Component\\Http\\Message\\Response\" object but it returned %s.");
				ZEPHIR_CALL_FUNCTION(&msg, "sprintf", NULL, 3, &_21$$7, &_20$$7);
				zephir_check_call_status_or_jump(try_end_1);
				if (Z_TYPE_P(&response) == IS_NULL) {
					zephir_concat_self_str(&msg, SL(" Did you forget to add a return statement somewhere in your controller?"));
				}
				ZEPHIR_INIT_NVAR(&_21$$7);
				object_init_ex(&_21$$7, moon_framework_exception_controllerexception_ce);
				ZEPHIR_CALL_METHOD(NULL, &_21$$7, "__construct", NULL, 26, &msg);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_throw_exception_debug(&_21$$7, "moon/Framework/Kernel.zep", 87);
				goto try_end_1;

			}
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filterresponse", &_7, 183, &response, request);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_22);
		ZVAL_OBJ(&_22, EG(exception));
		Z_ADDREF_P(&_22);
		if (zephir_instance_of_ev(&_22, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_22);
			if (ZEPHIR_IS_FALSE(_catch)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "finishrequest", NULL, 191, request);
				zephir_check_call_status();
				zephir_throw_exception_debug(&e, "moon/Framework/Kernel.zep", 94);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "handlethrowable", NULL, 192, &e, request);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Kernel, finishRequest) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("dispatcher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, moon_framework_event_event_finishrequestevent_ce);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 180, request, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "dispatch", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Kernel, handleThrowable) {

	zend_bool _5, _7, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *e = NULL, e_sub, *request, request_sub, response, he, event, _0, _1, _2, _3, _4, _6, _8, _10, _15, _16, _11$$5, _12$$5, _13$$5, _14$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&he);
	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &e, &request);

	ZEPHIR_SEPARATE_PARAM(e);


	ZEPHIR_INIT_VAR(&event);
	object_init_ex(&event, moon_framework_event_event_exceptionevent_ce);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 193, request, e, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("dispatcher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "dispatch", NULL, 0, &event);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(e, &event, "getthrowable", NULL, 194);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &event, "hasresponse", NULL, 181);
	zephir_check_call_status();
	if (!zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "finishrequest", NULL, 191, request);
		zephir_check_call_status();
		zephir_throw_exception_debug(e, "moon/Framework/Kernel.zep", 116);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&response, &event, "getresponse", NULL, 182);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &event, "isallowingcustomresponsecode", NULL, 195);
	zephir_check_call_status();
	_5 = !zephir_is_true(&_4);
	if (_5) {
		ZEPHIR_CALL_METHOD(&_6, &response, "isclienterror", NULL, 0);
		zephir_check_call_status();
		_5 = !zephir_is_true(&_6);
	}
	_7 = _5;
	if (_7) {
		ZEPHIR_CALL_METHOD(&_8, &response, "isservererror", NULL, 0);
		zephir_check_call_status();
		_7 = !zephir_is_true(&_8);
	}
	_9 = _7;
	if (_9) {
		ZEPHIR_CALL_METHOD(&_10, &response, "isredirect", NULL, 0);
		zephir_check_call_status();
		_9 = !zephir_is_true(&_10);
	}
	if (_9) {
		if (zephir_instance_of_ev(e, moon_framework_exception_httpexceptioninterface_ce)) {
			ZEPHIR_CPY_WRT(&he, e);
			ZEPHIR_CALL_METHOD(&_11$$5, &he, "getstatuscode", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &response, "setstatuscode", NULL, 0, &_11$$5);
			zephir_check_call_status();
			zephir_read_property(&_12$$5, &response, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_13$$5, &he, "getheaders", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_12$$5, "add", NULL, 0, &_13$$5);
			zephir_check_call_status();
		} else {
			ZVAL_LONG(&_14$$6, 500);
			ZEPHIR_CALL_METHOD(NULL, &response, "setstatuscode", NULL, 0, &_14$$6);
			zephir_check_call_status();
		}
	}

	/* try_start_1: */

		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filterresponse", NULL, 183, &response, request);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_15);
		ZVAL_OBJ(&_15, EG(exception));
		Z_ADDREF_P(&_15);
		ZEPHIR_INIT_VAR(&_16);
		if (zephir_instance_of_ev(&_15, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_16, &_15);
			RETURN_CCTOR(&response);
		}
	}

}

PHP_METHOD(Moon_Framework_Kernel, filterResponse) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *response, response_sub, *request, request_sub, event, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &response, &request);



	ZEPHIR_INIT_VAR(&event);
	object_init_ex(&event, moon_framework_event_event_responseevent_ce);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("router"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &event, "__construct", NULL, 196, request, response, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("dispatcher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "dispatch", NULL, 0, &event);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "finishrequest", NULL, 191, request);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&event, "getresponse", NULL, 197);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a human-readable string for the specified variable.
 *
 * @param $var
 * @return string
 */
PHP_METHOD(Moon_Framework_Kernel, varToString) {

	zend_string *_7$$4;
	zend_ulong _6$$4;
	zval _28, _26$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_16 = NULL;
	zval *_var, _var_sub, a, _0$$3, _1$$3, k$$4, _3$$4, *_4$$4, _5$$4, _12$$4, _13$$4, _14$$4, _15$$4, _17$$4, _8$$5, _9$$5, _10$$6, _11$$6, _18$$7, _19$$7, _20$$11, _21$$11, _22$$11, _23$$11, _24$$11, _25$$11, _27$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&a);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&k$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_26$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_var);



	if (Z_TYPE_P(_var) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, _var, 0);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "an object of type %s");
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 3, &_1$$3, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(_var) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&a);
		array_init(&a);
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_is_iterable(_var, 0, "moon/Framework/Kernel.zep", 168);
		if (Z_TYPE_P(_var) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_var), _6$$4, _7$$4, _4$$4)
			{
				ZEPHIR_INIT_NVAR(&k$$4);
				if (_7$$4 != NULL) { 
					ZVAL_STR_COPY(&k$$4, _7$$4);
				} else {
					ZVAL_LONG(&k$$4, _6$$4);
				}
				ZEPHIR_INIT_NVAR(&_3$$4);
				ZVAL_COPY(&_3$$4, _4$$4);
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZVAL_STRING(&_8$$5, "%s => ...");
				ZEPHIR_CALL_FUNCTION(&_9$$5, "sprintf", &_2, 3, &_8$$5, &k$$4);
				zephir_check_call_status();
				zephir_array_append(&a, &_9$$5, PH_SEPARATE, "moon/Framework/Kernel.zep", 166);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _var, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$4, _var, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&k$$4, _var, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_3$$4, _var, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_10$$6);
					ZVAL_STRING(&_10$$6, "%s => ...");
					ZEPHIR_CALL_FUNCTION(&_11$$6, "sprintf", &_2, 3, &_10$$6, &k$$4);
					zephir_check_call_status();
					zephir_array_append(&a, &_11$$6, PH_SEPARATE, "moon/Framework/Kernel.zep", 166);
				ZEPHIR_CALL_METHOD(NULL, _var, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZEPHIR_INIT_NVAR(&k$$4);
		ZEPHIR_INIT_VAR(&_12$$4);
		zephir_fast_join_str(&_12$$4, SL(", "), &a);
		ZVAL_LONG(&_13$$4, 0);
		ZVAL_LONG(&_14$$4, 255);
		ZEPHIR_CALL_FUNCTION(&_15$$4, "mb_substr", &_16, 198, &_12$$4, &_13$$4, &_14$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_17$$4);
		ZVAL_STRING(&_17$$4, "an array ([%s])");
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 3, &_17$$4, &_15$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(_var) == IS_RESOURCE) {
		ZEPHIR_CALL_FUNCTION(&_18$$7, "get_resource_type", NULL, 119, _var);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_19$$7);
		ZVAL_STRING(&_19$$7, "a resource (%s)");
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 3, &_19$$7, &_18$$7);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(_var) == IS_NULL) {
		RETURN_MM_STRING("null");
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(_var)) {
		RETURN_MM_STRING("a boolean value (false)");
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(_var)) {
		RETURN_MM_STRING("a boolean value (true)");
	}
	if (Z_TYPE_P(_var) == IS_STRING) {
		ZVAL_LONG(&_20$$11, 0);
		ZVAL_LONG(&_21$$11, 255);
		ZEPHIR_CALL_FUNCTION(&_22$$11, "mb_substr", &_16, 198, _var, &_20$$11, &_21$$11);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_23$$11);
		ZEPHIR_CALL_FUNCTION(&_24$$11, "mb_strlen", NULL, 199, _var);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&_24$$11, 255)) {
			ZEPHIR_INIT_NVAR(&_23$$11);
			ZVAL_STRING(&_23$$11, "...");
		} else {
			ZEPHIR_INIT_NVAR(&_23$$11);
			ZVAL_STRING(&_23$$11, "");
		}
		ZEPHIR_INIT_VAR(&_25$$11);
		ZVAL_STRING(&_25$$11, "a string (\"%s%s\")");
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 3, &_25$$11, &_22$$11, &_23$$11);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_is_numeric(_var)) {
		zephir_get_strval(&_26$$12, _var);
		ZEPHIR_INIT_VAR(&_27$$12);
		ZVAL_STRING(&_27$$12, "a number (%s)");
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 3, &_27$$12, &_26$$12);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_get_strval(&_28, _var);
	RETURN_CTOR(&_28);

}

