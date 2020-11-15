
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
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * FileName: ControllerArgumentsResolver.php
 * User: solely
 * DateTime: 2020/8/23 23:29
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Controller_ControllerArgumentsResolver) {

	ZEPHIR_REGISTER_CLASS(Moon\\Framework\\Controller, ControllerArgumentsResolver, moon, framework_controller_controllerargumentsresolver, moon_framework_controller_controllerargumentsresolver_method_entry, 0);

	zend_class_implements(moon_framework_controller_controllerargumentsresolver_ce, 1, moon_framework_controller_controllerargumentsresolverinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Controller_ControllerArgumentsResolver, getArguments) {

	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *node, node_sub, *controller, controller_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&node_sub);
	ZVAL_UNDEF(&controller_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &request, &node, &controller);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_router_argument_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, node, "getparameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	zephir_array_update_string(&_3, SL("_request"), request, PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(&_1, &_2, &_3);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "resolverargument", NULL, 160, controller, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

