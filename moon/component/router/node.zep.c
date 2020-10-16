
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * FileName: Node.php
 * User: solely
 * DateTime: 2020/6/17 23:02
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Router_Node) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Router, Node, moon, component_router_node, moon_component_router_node_method_entry, 0);

	zend_declare_property_null(moon_component_router_node_ce, SL("pathInfo"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_router_node_ce, SL("handler"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_router_node_ce, SL("routeName"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_router_node_ce, SL("priority"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_router_node_ce, SL("parameters"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Router_Node, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval parameters;
	zval *pathInfo, pathInfo_sub, *handler, handler_sub, *routeName = NULL, routeName_sub, *priority = NULL, priority_sub, *parameters_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pathInfo_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&routeName_sub);
	ZVAL_UNDEF(&priority_sub);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &pathInfo, &handler, &routeName, &priority, &parameters_param);

	if (!routeName) {
		routeName = &routeName_sub;
		ZEPHIR_INIT_VAR(routeName);
		ZVAL_STRING(routeName, "");
	}
	if (!priority) {
		priority = &priority_sub;
		ZEPHIR_INIT_VAR(priority);
		ZVAL_LONG(priority, 0);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("pathInfo"), pathInfo);
	zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	zephir_update_property_zval(this_ptr, ZEND_STRL("routeName"), routeName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("priority"), priority);
	zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &parameters);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param $pathInfo
 * @return Node
 */
PHP_METHOD(Moon_Component_Router_Node, setPathInfo) {

	zval *pathInfo, pathInfo_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pathInfo_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &pathInfo);



	zephir_update_property_zval(this_ptr, ZEND_STRL("pathInfo"), pathInfo);
	RETURN_THISW();

}

/**
 * @return mixed
 */
PHP_METHOD(Moon_Component_Router_Node, getPathInfo) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "pathInfo");

}

/**
 * @param $handler
 * @return Node
 */
PHP_METHOD(Moon_Component_Router_Node, setHandler) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &handler);



	zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	RETURN_THISW();

}

/**
 * @return mixed
 */
PHP_METHOD(Moon_Component_Router_Node, getHandler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handler");

}

/**
 * @param string $routeName
 * @return Node
 */
PHP_METHOD(Moon_Component_Router_Node, setRouteName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *routeName_param = NULL;
	zval routeName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &routeName_param);

	zephir_get_strval(&routeName, routeName_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("routeName"), &routeName);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Moon_Component_Router_Node, getRouteName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "routeName");

}

/**
 * @param int $priority
 * @return Node
 */
PHP_METHOD(Moon_Component_Router_Node, setPriority) {

	zval *priority_param = NULL, _0;
	zend_long priority;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &priority_param);

	priority = zephir_get_intval(priority_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, priority);
	zephir_update_property_zval(this_ptr, ZEND_STRL("priority"), &_0);
	RETURN_THISW();

}

/**
 * @return int
 */
PHP_METHOD(Moon_Component_Router_Node, getPriority) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "priority");

}

/**
 * @param array $parameters
 * @return Node
 */
PHP_METHOD(Moon_Component_Router_Node, setParameters) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *parameters_param = NULL;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_arrval(&parameters, parameters_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("parameters"), &parameters);
	RETURN_THIS();

}

/**
 * @return array
 */
PHP_METHOD(Moon_Component_Router_Node, getParameters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "parameters");

}

