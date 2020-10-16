
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * FileName: ControllerResolver.php
 * User: solely
 * DateTime: 2020/8/20 23:36
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Controller_ControllerResolver) {

	ZEPHIR_REGISTER_CLASS(Moon\\Framework\\Controller, ControllerResolver, moon, framework_controller_controllerresolver, moon_framework_controller_controllerresolver_method_entry, 0);

	zend_class_implements(moon_framework_controller_controllerresolver_ce, 1, moon_framework_controller_controllerresolverinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Controller_ControllerResolver, getController) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *node, node_sub, _callable, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&node_sub);
	ZVAL_UNDEF(&_callable);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &node);



	ZEPHIR_CALL_METHOD(&_callable, node, "gethandler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_router_handler_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(&_0, "resolverhandler", NULL, 275, &_callable);
	zephir_check_call_status();
	RETURN_MM();

}

