
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * FileName: Router.php
 * User: solely
 * DateTime: 2020/6/17 22:50
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Router_Router) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Router, Router, moon, component_router_router, moon_component_router_router_method_entry, 0);

	zend_declare_property_null(moon_component_router_router_ce, SL("nodes"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_router_router_ce, SL("routes"), ZEND_ACC_PRIVATE);

	zend_declare_property_string(moon_component_router_router_ce, SL("prefix"), "", ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_router_router_ce, SL("routers"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_router_router_ce, SL("priority"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_router_router_ce, SL("routeNames"), ZEND_ACC_PRIVATE);

	moon_component_router_router_ce->create_object = zephir_init_properties_Moon_Component_Router_Router;
	zephir_declare_class_constant_string(moon_component_router_router_ce, SL("HTTP_METHOD_GET"), "GET");

	zephir_declare_class_constant_string(moon_component_router_router_ce, SL("HTTP_METHOD_POST"), "POST");

	zephir_declare_class_constant_string(moon_component_router_router_ce, SL("HTTP_METHOD_PUT"), "PUT");

	zephir_declare_class_constant_string(moon_component_router_router_ce, SL("HTTP_METHOD_PATCH"), "PATCH");

	zephir_declare_class_constant_string(moon_component_router_router_ce, SL("HTTP_METHOD_DELETE"), "DELETE");

	zephir_declare_class_constant_string(moon_component_router_router_ce, SL("HTTP_METHOD_OPTIONS"), "OPTIONS");

	zephir_declare_class_constant_string(moon_component_router_router_ce, SL("DEFAULT_REGULAR_EXPRESSION"), "[^/]+");

	zephir_declare_class_constant_string(moon_component_router_router_ce, SL("ROUTER_KEY_SEPARATOR"), "___");

	zend_class_implements(moon_component_router_router_ce, 1, moon_component_router_routerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Router_Router, getHttpMethodList) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 6, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "GET");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "POST");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "OPTIONS");
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

/**
 * @param array $methods
 * @param string $uri
 * @param mixed $handler
 * @param string $routeName
 * @param int $priority
 */
PHP_METHOD(Moon_Component_Router_Router, add) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_10 = NULL, *_24 = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval uri, routeName, _3$$3, _12$$5;
	zval *methods_param = NULL, *uri_param = NULL, *handler, handler_sub, *routeName_param = NULL, *priority_param = NULL, _uri, method, *_0, _1, _17, _29, _30, _2$$3, _4$$3, _7$$4, _8$$4, _9$$4, _11$$5, _13$$5, _14$$6, _15$$6, _16$$6, _18$$7, _19$$7, _20$$7, _21$$7, _22$$7, _23$$7, _25$$8, _26$$8, _27$$8;
	zval methods, _28;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_uri);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &methods_param, &uri_param, &handler, &routeName_param, &priority_param);

	zephir_get_arrval(&methods, methods_param);
	zephir_get_strval(&uri, uri_param);
	if (!routeName_param) {
		ZEPHIR_INIT_VAR(&routeName);
		ZVAL_STRING(&routeName, "");
	} else {
		zephir_get_strval(&routeName, routeName_param);
	}
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	zephir_is_iterable(&methods, 0, "moon/Component/Router/Router.zep", 64);
	if (Z_TYPE_P(&methods) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _0)
		{
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_COPY(&method, _0);
			ZEPHIR_INIT_NVAR(&_2$$3);
			zephir_get_strval(&_3$$3, &method);
			zephir_fast_strtoupper(&_2$$3, &_3$$3);
			ZEPHIR_CALL_SELF(&_4$$3, "gethttpmethodlist", &_5, 0);
			zephir_check_call_status();
			if (!(zephir_fast_in_array(&_2$$3, &_4$$3))) {
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZEPHIR_CALL_SELF(&_8$$4, "gethttpmethodlist", &_5, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_9$$4, "array_diff", &_10, 153, &methods, &_8$$4);
				zephir_check_call_status();
				zephir_fast_join_str(&_7$$4, SL(","), &_9$$4);
				ZEPHIR_CALL_CE_STATIC(NULL, moon_component_router_exception_ce, "notsupportedexception", &_6, 0, &_7$$4);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &methods, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&method, &methods, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_get_strval(&_12$$5, &method);
				zephir_fast_strtoupper(&_11$$5, &_12$$5);
				ZEPHIR_CALL_SELF(&_13$$5, "gethttpmethodlist", &_5, 0);
				zephir_check_call_status();
				if (!(zephir_fast_in_array(&_11$$5, &_13$$5))) {
					ZEPHIR_INIT_NVAR(&_14$$6);
					ZEPHIR_CALL_SELF(&_15$$6, "gethttpmethodlist", &_5, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_16$$6, "array_diff", &_10, 153, &methods, &_15$$6);
					zephir_check_call_status();
					zephir_fast_join_str(&_14$$6, SL(","), &_16$$6);
					ZEPHIR_CALL_CE_STATIC(NULL, moon_component_router_exception_ce, "notsupportedexception", &_6, 0, &_14$$6);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&method);
	ZEPHIR_OBS_VAR(&_17);
	zephir_read_property(&_17, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_17))) {
		ZEPHIR_INIT_VAR(&_18$$7);
		zephir_read_property(&_19$$7, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_20$$7);
		ZVAL_STRING(&_20$$7, "/");
		zephir_fast_trim(&_18$$7, &_19$$7, &_20$$7, ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_VAR(&_21$$7);
		ZEPHIR_INIT_VAR(&_22$$7);
		ZVAL_STRING(&_22$$7, "/");
		zephir_fast_trim(&_21$$7, &uri, &_22$$7, ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_VAR(&_23$$7);
		ZVAL_STRING(&_23$$7, "/%s/%s");
		ZEPHIR_CALL_FUNCTION(&_uri, "sprintf", &_24, 3, &_23$$7, &_18$$7, &_21$$7);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_25$$8);
		ZEPHIR_INIT_VAR(&_26$$8);
		ZVAL_STRING(&_26$$8, "/");
		zephir_fast_trim(&_25$$8, &uri, &_26$$8, ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_VAR(&_27$$8);
		ZVAL_STRING(&_27$$8, "/%s");
		ZEPHIR_CALL_FUNCTION(&_uri, "sprintf", &_24, 3, &_27$$8, &_25$$8);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_28);
	zephir_create_array(&_28, 5, 0);
	zephir_array_update_string(&_28, SL("methods"), &methods, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_28, SL("uri"), &_uri, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_28, SL("handler"), handler, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_28, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_29);
	ZVAL_LONG(&_29, priority);
	zephir_array_update_string(&_28, SL("priority"), &_29, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_append(this_ptr, SL("routers"), &_28);
	ZEPHIR_INIT_ZVAL_NREF(_30);
	ZVAL_LONG(&_30, priority);
	zephir_update_property_array_append(this_ptr, SL("priority"), &_30);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $uri
 * @param mixed $handler
 * @param string $routeName
 * @param int $priority
 */
PHP_METHOD(Moon_Component_Router_Router, get) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *handler, handler_sub, *routeName_param = NULL, *priority_param = NULL, _1, _2;
	zval uri, routeName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &uri_param, &handler, &routeName_param, &priority_param);

	zephir_get_strval(&uri, uri_param);
	if (!routeName_param) {
		ZEPHIR_INIT_VAR(&routeName);
		ZVAL_STRING(&routeName, "");
	} else {
		zephir_get_strval(&routeName, routeName_param);
	}
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "GET");
	zephir_array_fast_append(&_0, &_1);
	ZVAL_LONG(&_2, priority);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0, &uri, handler, &routeName, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $uri
 * @param mixed $handler
 * @param string $routeName
 * @param int $priority
 */
PHP_METHOD(Moon_Component_Router_Router, post) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *handler, handler_sub, *routeName_param = NULL, *priority_param = NULL, _1, _2;
	zval uri, routeName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &uri_param, &handler, &routeName_param, &priority_param);

	zephir_get_strval(&uri, uri_param);
	if (!routeName_param) {
		ZEPHIR_INIT_VAR(&routeName);
		ZVAL_STRING(&routeName, "");
	} else {
		zephir_get_strval(&routeName, routeName_param);
	}
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "POST");
	zephir_array_fast_append(&_0, &_1);
	ZVAL_LONG(&_2, priority);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0, &uri, handler, &routeName, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $uri
 * @param mixed $handler
 * @param string $routeName
 * @param int $priority
 */
PHP_METHOD(Moon_Component_Router_Router, put) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *handler, handler_sub, *routeName_param = NULL, *priority_param = NULL, _1, _2;
	zval uri, routeName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &uri_param, &handler, &routeName_param, &priority_param);

	zephir_get_strval(&uri, uri_param);
	if (!routeName_param) {
		ZEPHIR_INIT_VAR(&routeName);
		ZVAL_STRING(&routeName, "");
	} else {
		zephir_get_strval(&routeName, routeName_param);
	}
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "PUT");
	zephir_array_fast_append(&_0, &_1);
	ZVAL_LONG(&_2, priority);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0, &uri, handler, &routeName, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $uri
 * @param mixed $handler
 * @param string $routeName
 * @param int $priority
 */
PHP_METHOD(Moon_Component_Router_Router, patch) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *handler, handler_sub, *routeName_param = NULL, *priority_param = NULL, _1, _2;
	zval uri, routeName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &uri_param, &handler, &routeName_param, &priority_param);

	zephir_get_strval(&uri, uri_param);
	if (!routeName_param) {
		ZEPHIR_INIT_VAR(&routeName);
		ZVAL_STRING(&routeName, "");
	} else {
		zephir_get_strval(&routeName, routeName_param);
	}
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "PATCH");
	zephir_array_fast_append(&_0, &_1);
	ZVAL_LONG(&_2, priority);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0, &uri, handler, &routeName, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $uri
 * @param mixed $handler
 * @param string $routeName
 * @param int $priority
 */
PHP_METHOD(Moon_Component_Router_Router, delete) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *handler, handler_sub, *routeName_param = NULL, *priority_param = NULL, _1, _2;
	zval uri, routeName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &uri_param, &handler, &routeName_param, &priority_param);

	zephir_get_strval(&uri, uri_param);
	if (!routeName_param) {
		ZEPHIR_INIT_VAR(&routeName);
		ZVAL_STRING(&routeName, "");
	} else {
		zephir_get_strval(&routeName, routeName_param);
	}
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "DELETE");
	zephir_array_fast_append(&_0, &_1);
	ZVAL_LONG(&_2, priority);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0, &uri, handler, &routeName, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $uri
 * @param mixed $handler
 * @param string $routeName
 * @param int $priority
 */
PHP_METHOD(Moon_Component_Router_Router, options) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *handler, handler_sub, *routeName_param = NULL, *priority_param = NULL, _1, _2;
	zval uri, routeName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &uri_param, &handler, &routeName_param, &priority_param);

	zephir_get_strval(&uri, uri_param);
	if (!routeName_param) {
		ZEPHIR_INIT_VAR(&routeName);
		ZVAL_STRING(&routeName, "");
	} else {
		zephir_get_strval(&routeName, routeName_param);
	}
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "OPTIONS");
	zephir_array_fast_append(&_0, &_1);
	ZVAL_LONG(&_2, priority);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0, &uri, handler, &routeName, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $uri
 * @param mixed $handler
 * @param string $routeName
 * @param int $priority
 */
PHP_METHOD(Moon_Component_Router_Router, any) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *handler, handler_sub, *routeName_param = NULL, *priority_param = NULL, _0, _1;
	zval uri, routeName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &uri_param, &handler, &routeName_param, &priority_param);

	zephir_get_strval(&uri, uri_param);
	if (!routeName_param) {
		ZEPHIR_INIT_VAR(&routeName);
		ZVAL_STRING(&routeName, "");
	} else {
		zephir_get_strval(&routeName, routeName_param);
	}
	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_CALL_SELF(&_0, "gethttpmethodlist", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, priority);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0, &uri, handler, &routeName, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $method
 * @param string $uri
 * @return mixed|Node
 */
PHP_METHOD(Moon_Component_Router_Router, match) {

	zend_string *_37$$13, *_61$$21;
	zend_ulong _36$$13, _60$$21;
	zend_bool _8, _10, _21, _23, _38$$14, _43$$17, _62$$22, _67$$25;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_17 = NULL, *_31 = NULL, *_53 = NULL;
	zval *method_param = NULL, *uri_param = NULL, route, res, routeName, parameters, regex, nodesRegex, uriArr, _uriArr, nodes, _method, _0, _4, _5, _6, _7, _9, _11, item, *_12, _13, _22, _24, _25, _2$$4, _3$$4, _14$$6, _15$$6, _16$$6, _18$$8, _19$$8, _20$$8, _26$$11, *_27$$11, _28$$11, _29$$12, _30$$12, match$$12, _32$$12, _33$$12, k$$13, m$$13, *_34$$13, _35$$13, _48$$13, _49$$13, _50$$13, _51$$13, _52$$13, _39$$14, _40$$14, _41$$16, _42$$16, _44$$17, _45$$17, _46$$19, _47$$19, _54$$20, _55$$20, match$$20, _56$$20, _57$$20, k$$21, m$$21, *_58$$21, _59$$21, _72$$21, _73$$21, _74$$21, _75$$21, _76$$21, _63$$22, _64$$22, _65$$24, _66$$24, _68$$25, _69$$25, _70$$27, _71$$27;
	zval method, uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&nodesRegex);
	ZVAL_UNDEF(&uriArr);
	ZVAL_UNDEF(&_uriArr);
	ZVAL_UNDEF(&nodes);
	ZVAL_UNDEF(&_method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&match$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&k$$13);
	ZVAL_UNDEF(&m$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_49$$13);
	ZVAL_UNDEF(&_50$$13);
	ZVAL_UNDEF(&_51$$13);
	ZVAL_UNDEF(&_52$$13);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_41$$16);
	ZVAL_UNDEF(&_42$$16);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_47$$19);
	ZVAL_UNDEF(&_54$$20);
	ZVAL_UNDEF(&_55$$20);
	ZVAL_UNDEF(&match$$20);
	ZVAL_UNDEF(&_56$$20);
	ZVAL_UNDEF(&_57$$20);
	ZVAL_UNDEF(&k$$21);
	ZVAL_UNDEF(&m$$21);
	ZVAL_UNDEF(&_59$$21);
	ZVAL_UNDEF(&_72$$21);
	ZVAL_UNDEF(&_73$$21);
	ZVAL_UNDEF(&_74$$21);
	ZVAL_UNDEF(&_75$$21);
	ZVAL_UNDEF(&_76$$21);
	ZVAL_UNDEF(&_63$$22);
	ZVAL_UNDEF(&_64$$22);
	ZVAL_UNDEF(&_65$$24);
	ZVAL_UNDEF(&_66$$24);
	ZVAL_UNDEF(&_68$$25);
	ZVAL_UNDEF(&_69$$25);
	ZVAL_UNDEF(&_70$$27);
	ZVAL_UNDEF(&_71$$27);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &uri_param);

	zephir_get_strval(&method, method_param);
	zephir_get_strval(&uri, uri_param);


	ZEPHIR_INIT_VAR(&_method);
	zephir_fast_strtoupper(&_method, &method);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &_method))) {
		ZEPHIR_CALL_CE_STATIC(NULL, moon_component_router_exception_ce, "notfoundexception", &_1, 0, &method, &uri);
		zephir_check_call_status();
	}
	if (!ZEPHIR_IS_STRING(&uri, "/")) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "/");
		zephir_fast_trim(&_2$$4, &uri, &_3$$4, ZEPHIR_TRIM_RIGHT);
		zephir_get_strval(&uri, &_2$$4);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &_method, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 180);
	ZEPHIR_CPY_WRT(&nodes, &_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_explode_str(&_6, SL("/"), &uri, LONG_MAX);
	ZEPHIR_CALL_FUNCTION(&_7, "array_filter", NULL, 95, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", NULL, 75, &_7);
	zephir_check_call_status();
	_8 = zephir_fast_count_int(&uriArr) == 0;
	if (_8) {
		ZEPHIR_CALL_METHOD(&_9, &nodes, "getnode", NULL, 0);
		zephir_check_call_status();
		_8 = !(ZEPHIR_IS_EMPTY(&_9));
	}
	_10 = _8;
	if (_10) {
		ZEPHIR_CALL_METHOD(&_11, &nodes, "getnode", NULL, 0);
		zephir_check_call_status();
		_10 = zephir_instance_of_ev(&_11, moon_component_router_node_ce);
	}
	if (_10) {
		ZEPHIR_RETURN_CALL_METHOD(&nodes, "getnode", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&_uriArr, &uriArr);
	zephir_is_iterable(&_uriArr, 0, "moon/Component/Router/Router.zep", 196);
	if (Z_TYPE_P(&_uriArr) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_uriArr), _12)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _12);
			zephir_read_property(&_14$$6, &nodes, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset(&_14$$6, &item))) {
				break;
			}
			zephir_read_property(&_15$$6, &nodes, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_16$$6, &_15$$6, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 192);
			ZEPHIR_CPY_WRT(&nodes, &_16$$6);
			ZEPHIR_MAKE_REF(&uriArr);
			ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_17, 85, &uriArr);
			ZEPHIR_UNREF(&uriArr);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_uriArr, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_13, &_uriArr, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &_uriArr, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_18$$8, &nodes, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset(&_18$$8, &item))) {
					break;
				}
				zephir_read_property(&_19$$8, &nodes, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_20$$8, &_19$$8, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 192);
				ZEPHIR_CPY_WRT(&nodes, &_20$$8);
				ZEPHIR_MAKE_REF(&uriArr);
				ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_17, 85, &uriArr);
				ZEPHIR_UNREF(&uriArr);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_uriArr, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	_21 = zephir_fast_count_int(&uriArr) == 0;
	if (_21) {
		ZEPHIR_CALL_METHOD(&_22, &nodes, "getnode", NULL, 0);
		zephir_check_call_status();
		_21 = !(ZEPHIR_IS_EMPTY(&_22));
	}
	_23 = _21;
	if (_23) {
		ZEPHIR_CALL_METHOD(&_24, &nodes, "getnode", NULL, 0);
		zephir_check_call_status();
		_23 = zephir_instance_of_ev(&_24, moon_component_router_node_ce);
	}
	if (_23) {
		ZEPHIR_RETURN_CALL_METHOD(&nodes, "getnode", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_25, &nodes, "getregex", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&_25))) {
		ZEPHIR_CALL_METHOD(&_26$$11, &nodes, "getregex", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&_26$$11, 0, "moon/Component/Router/Router.zep", 235);
		if (Z_TYPE_P(&_26$$11) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_26$$11), _27$$11)
			{
				ZEPHIR_INIT_NVAR(&nodesRegex);
				ZVAL_COPY(&nodesRegex, _27$$11);
				ZEPHIR_INIT_NVAR(&_29$$12);
				zephir_fast_join_str(&_29$$12, SL("|"), &nodesRegex);
				ZEPHIR_INIT_NVAR(&_30$$12);
				ZVAL_STRING(&_30$$12, "#%s#");
				ZEPHIR_CALL_FUNCTION(&regex, "sprintf", &_31, 3, &_30$$12, &_29$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_30$$12);
				zephir_fast_join_str(&_30$$12, SL("/"), &uriArr);
				ZEPHIR_INIT_NVAR(&_32$$12);
				ZEPHIR_CONCAT_SV(&_32$$12, "/", &_30$$12);
				ZEPHIR_INIT_NVAR(&_33$$12);
				zephir_preg_match(&_33$$12, &regex, &_32$$12, &match$$12, 0, 0 , 0 );
				if (zephir_is_true(&_33$$12)) {
					ZEPHIR_INIT_NVAR(&parameters);
					array_init(&parameters);
					ZEPHIR_INIT_NVAR(&routeName);
					ZVAL_STRING(&routeName, "");
					zephir_is_iterable(&match$$12, 0, "moon/Component/Router/Router.zep", 224);
					if (Z_TYPE_P(&match$$12) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&match$$12), _36$$13, _37$$13, _34$$13)
						{
							ZEPHIR_INIT_NVAR(&k$$13);
							if (_37$$13 != NULL) { 
								ZVAL_STR_COPY(&k$$13, _37$$13);
							} else {
								ZVAL_LONG(&k$$13, _36$$13);
							}
							ZEPHIR_INIT_NVAR(&m$$13);
							ZVAL_COPY(&m$$13, _34$$13);
							_38$$14 = Z_TYPE_P(&k$$13) == IS_STRING;
							if (_38$$14) {
								ZEPHIR_INIT_NVAR(&_39$$14);
								ZVAL_STRING(&_39$$14, "___");
								ZEPHIR_INIT_NVAR(&_40$$14);
								zephir_fast_strpos(&_40$$14, &k$$13, &_39$$14, 0 );
								_38$$14 = !ZEPHIR_IS_FALSE_IDENTICAL(&_40$$14);
							}
							if (_38$$14) {
								if (!(ZEPHIR_IS_EMPTY(&m$$13))) {
									ZEPHIR_INIT_NVAR(&_41$$16);
									ZVAL_STRING(&_41$$16, "___");
									ZEPHIR_INIT_NVAR(&res);
									zephir_fast_explode(&res, &_41$$16, &k$$13, LONG_MAX);
									ZEPHIR_OBS_NVAR(&_42$$16);
									zephir_array_fetch_long(&_42$$16, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 219);
									zephir_array_update_zval(&parameters, &_42$$16, &m$$13, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&routeName);
									zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 220);
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &match$$12, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_35$$13, &match$$12, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_35$$13)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&k$$13, &match$$12, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&m$$13, &match$$12, "current", NULL, 0);
							zephir_check_call_status();
								_43$$17 = Z_TYPE_P(&k$$13) == IS_STRING;
								if (_43$$17) {
									ZEPHIR_INIT_NVAR(&_44$$17);
									ZVAL_STRING(&_44$$17, "___");
									ZEPHIR_INIT_NVAR(&_45$$17);
									zephir_fast_strpos(&_45$$17, &k$$13, &_44$$17, 0 );
									_43$$17 = !ZEPHIR_IS_FALSE_IDENTICAL(&_45$$17);
								}
								if (_43$$17) {
									if (!(ZEPHIR_IS_EMPTY(&m$$13))) {
										ZEPHIR_INIT_NVAR(&_46$$19);
										ZVAL_STRING(&_46$$19, "___");
										ZEPHIR_INIT_NVAR(&res);
										zephir_fast_explode(&res, &_46$$19, &k$$13, LONG_MAX);
										ZEPHIR_OBS_NVAR(&_47$$19);
										zephir_array_fetch_long(&_47$$19, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 219);
										zephir_array_update_zval(&parameters, &_47$$19, &m$$13, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&routeName);
										zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 220);
									}
								}
							ZEPHIR_CALL_METHOD(NULL, &match$$12, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&m$$13);
					ZEPHIR_INIT_NVAR(&k$$13);
					zephir_read_property(&_48$$13, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&route);
					ZEPHIR_INIT_NVAR(&_49$$13);
					ZEPHIR_CONCAT_VSV(&_49$$13, &_method, "_", &routeName);
					zephir_array_fetch(&route, &_48$$13, &_49$$13, PH_NOISY, "moon/Component/Router/Router.zep", 224);
					object_init_ex(return_value, moon_component_router_node_ce);
					zephir_array_fetch_string(&_50$$13, &route, SL("handler"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 228);
					zephir_array_fetch_string(&_51$$13, &route, SL("routeName"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 229);
					zephir_array_fetch_string(&_52$$13, &route, SL("priority"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 230);
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_53, 154, &uri, &_50$$13, &_51$$13, &_52$$13, &parameters);
					zephir_check_call_status();
					RETURN_MM();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_26$$11, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_28$$11, &_26$$11, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_28$$11)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&nodesRegex, &_26$$11, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_54$$20);
					zephir_fast_join_str(&_54$$20, SL("|"), &nodesRegex);
					ZEPHIR_INIT_NVAR(&_55$$20);
					ZVAL_STRING(&_55$$20, "#%s#");
					ZEPHIR_CALL_FUNCTION(&regex, "sprintf", &_31, 3, &_55$$20, &_54$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_55$$20);
					zephir_fast_join_str(&_55$$20, SL("/"), &uriArr);
					ZEPHIR_INIT_NVAR(&_56$$20);
					ZEPHIR_CONCAT_SV(&_56$$20, "/", &_55$$20);
					ZEPHIR_INIT_NVAR(&_57$$20);
					zephir_preg_match(&_57$$20, &regex, &_56$$20, &match$$20, 0, 0 , 0 );
					if (zephir_is_true(&_57$$20)) {
						ZEPHIR_INIT_NVAR(&parameters);
						array_init(&parameters);
						ZEPHIR_INIT_NVAR(&routeName);
						ZVAL_STRING(&routeName, "");
						zephir_is_iterable(&match$$20, 0, "moon/Component/Router/Router.zep", 224);
						if (Z_TYPE_P(&match$$20) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&match$$20), _60$$21, _61$$21, _58$$21)
							{
								ZEPHIR_INIT_NVAR(&k$$21);
								if (_61$$21 != NULL) { 
									ZVAL_STR_COPY(&k$$21, _61$$21);
								} else {
									ZVAL_LONG(&k$$21, _60$$21);
								}
								ZEPHIR_INIT_NVAR(&m$$21);
								ZVAL_COPY(&m$$21, _58$$21);
								_62$$22 = Z_TYPE_P(&k$$21) == IS_STRING;
								if (_62$$22) {
									ZEPHIR_INIT_NVAR(&_63$$22);
									ZVAL_STRING(&_63$$22, "___");
									ZEPHIR_INIT_NVAR(&_64$$22);
									zephir_fast_strpos(&_64$$22, &k$$21, &_63$$22, 0 );
									_62$$22 = !ZEPHIR_IS_FALSE_IDENTICAL(&_64$$22);
								}
								if (_62$$22) {
									if (!(ZEPHIR_IS_EMPTY(&m$$21))) {
										ZEPHIR_INIT_NVAR(&_65$$24);
										ZVAL_STRING(&_65$$24, "___");
										ZEPHIR_INIT_NVAR(&res);
										zephir_fast_explode(&res, &_65$$24, &k$$21, LONG_MAX);
										ZEPHIR_OBS_NVAR(&_66$$24);
										zephir_array_fetch_long(&_66$$24, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 219);
										zephir_array_update_zval(&parameters, &_66$$24, &m$$21, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&routeName);
										zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 220);
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &match$$20, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_59$$21, &match$$20, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_59$$21)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&k$$21, &match$$20, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&m$$21, &match$$20, "current", NULL, 0);
								zephir_check_call_status();
									_67$$25 = Z_TYPE_P(&k$$21) == IS_STRING;
									if (_67$$25) {
										ZEPHIR_INIT_NVAR(&_68$$25);
										ZVAL_STRING(&_68$$25, "___");
										ZEPHIR_INIT_NVAR(&_69$$25);
										zephir_fast_strpos(&_69$$25, &k$$21, &_68$$25, 0 );
										_67$$25 = !ZEPHIR_IS_FALSE_IDENTICAL(&_69$$25);
									}
									if (_67$$25) {
										if (!(ZEPHIR_IS_EMPTY(&m$$21))) {
											ZEPHIR_INIT_NVAR(&_70$$27);
											ZVAL_STRING(&_70$$27, "___");
											ZEPHIR_INIT_NVAR(&res);
											zephir_fast_explode(&res, &_70$$27, &k$$21, LONG_MAX);
											ZEPHIR_OBS_NVAR(&_71$$27);
											zephir_array_fetch_long(&_71$$27, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 219);
											zephir_array_update_zval(&parameters, &_71$$27, &m$$21, PH_COPY | PH_SEPARATE);
											ZEPHIR_OBS_NVAR(&routeName);
											zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 220);
										}
									}
								ZEPHIR_CALL_METHOD(NULL, &match$$20, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&m$$21);
						ZEPHIR_INIT_NVAR(&k$$21);
						zephir_read_property(&_72$$21, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&route);
						ZEPHIR_INIT_NVAR(&_73$$21);
						ZEPHIR_CONCAT_VSV(&_73$$21, &_method, "_", &routeName);
						zephir_array_fetch(&route, &_72$$21, &_73$$21, PH_NOISY, "moon/Component/Router/Router.zep", 224);
						object_init_ex(return_value, moon_component_router_node_ce);
						zephir_array_fetch_string(&_74$$21, &route, SL("handler"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 228);
						zephir_array_fetch_string(&_75$$21, &route, SL("routeName"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 229);
						zephir_array_fetch_string(&_76$$21, &route, SL("priority"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 230);
						ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_53, 154, &uri, &_74$$21, &_75$$21, &_76$$21, &parameters);
						zephir_check_call_status();
						RETURN_MM();
					}
				ZEPHIR_CALL_METHOD(NULL, &_26$$11, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&nodesRegex);
	}
	ZEPHIR_CALL_CE_STATIC(NULL, moon_component_router_exception_ce, "notfoundexception", &_1, 0, &method, &uri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string $prefix
 * @param callable $fn
 */
PHP_METHOD(Moon_Component_Router_Router, group) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, *_fn, _fn_sub, tmpPrefix, _0, _1, _2, _3, _4, _5, _6, _7;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_fn_sub);
	ZVAL_UNDEF(&tmpPrefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &prefix_param, &_fn);

	zephir_get_strval(&prefix, prefix_param);


	ZEPHIR_OBS_VAR(&tmpPrefix);
	zephir_read_property(&tmpPrefix, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_EMPTY(&tmpPrefix)) {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "/");
		zephir_fast_trim(&_1, &prefix, &_2, ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "/%s");
		ZEPHIR_CALL_FUNCTION(&_0, "sprintf", NULL, 3, &_3, &_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_3);
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "/");
		zephir_fast_trim(&_3, &tmpPrefix, &_4, ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_VAR(&_5);
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_STRING(&_6, "/");
		zephir_fast_trim(&_5, &prefix, &_6, ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_VAR(&_7);
		ZVAL_STRING(&_7, "/%s/%s");
		ZEPHIR_CALL_FUNCTION(&_0, "sprintf", NULL, 3, &_7, &_3, &_5);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_0);
	ZEPHIR_CALL_ZVAL_FUNCTION(NULL, _fn, NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &tmpPrefix);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Router_Router, addRoutes) {

	zend_string *_19$$7, *_159$$47, *_297$$88, *_433$$128;
	zend_ulong _18$$7, _158$$47, _296$$88, _432$$128;
	zval _148$$5, _284$$45, _422$$86, _558$$126;
	zval methods, uri, handler, routeName, priority, formatStr, regexPos, regexKey, regexArr, item, i, length, uriArr, _0, _1, _2, _3, router, *_4, _5, method$$4, *_6$$4, _7$$4, _8$$5, _10$$5, tree$$5, _12$$5, _13$$5, _149$$5, _150$$5, _9$$6, *_16$$7, _17$$7, _20$$8, _21$$8, _22$$8, _23$$8, re$$9, *_25$$9, _26$$9, _68$$9, _69$$9, _70$$9, _71$$9, _72$$9, _73$$9, _27$$10, _28$$10, _29$$10, _30$$10, _31$$11, _32$$12, _33$$12, _34$$12, _35$$12, _36$$12, _37$$12, _39$$13, _40$$13, _41$$13, _42$$13, _43$$13, _44$$13, _45$$13, _46$$13, _47$$14, _48$$15, _49$$15, _50$$15, _51$$15, _52$$16, _53$$17, _54$$17, _55$$17, _56$$17, _57$$17, _58$$17, _59$$18, _60$$18, _61$$18, _62$$18, _63$$18, _64$$18, _65$$18, _66$$18, _67$$19, newNode$$21, _76$$21, _77$$22, _78$$22, newTree$$23, _81$$24, _83$$24, _84$$24, _82$$25, _85$$26, _86$$26, _87$$26, _88$$26, re$$27, *_89$$27, _90$$27, _131$$27, _132$$27, _133$$27, _134$$27, _135$$27, _136$$27, _91$$28, _92$$28, _93$$28, _94$$28, _95$$29, _96$$30, _97$$30, _98$$30, _99$$30, _100$$30, _101$$30, _102$$31, _103$$31, _104$$31, _105$$31, _106$$31, _107$$31, _108$$31, _109$$31, _110$$32, _111$$33, _112$$33, _113$$33, _114$$33, _115$$34, _116$$35, _117$$35, _118$$35, _119$$35, _120$$35, _121$$35, _122$$36, _123$$36, _124$$36, _125$$36, _126$$36, _127$$36, _128$$36, _129$$36, _130$$37, newNode$$39, _138$$39, _139$$40, _140$$40, newTree$$41, _142$$42, _144$$42, _145$$42, _143$$43, _146$$44, _151$$45, _153$$45, tree$$45, _154$$45, _155$$45, _285$$45, _286$$45, _152$$46, *_156$$47, _157$$47, _160$$48, _161$$48, _162$$48, _163$$48, re$$49, *_164$$49, _165$$49, _206$$49, _207$$49, _208$$49, _209$$49, _210$$49, _211$$49, _166$$50, _167$$50, _168$$50, _169$$50, _170$$51, _171$$52, _172$$52, _173$$52, _174$$52, _175$$52, _176$$52, _177$$53, _178$$53, _179$$53, _180$$53, _181$$53, _182$$53, _183$$53, _184$$53, _185$$54, _186$$55, _187$$55, _188$$55, _189$$55, _190$$56, _191$$57, _192$$57, _193$$57, _194$$57, _195$$57, _196$$57, _197$$58, _198$$58, _199$$58, _200$$58, _201$$58, _202$$58, _203$$58, _204$$58, _205$$59, newNode$$61, _213$$61, _214$$62, _215$$62, newTree$$63, _217$$64, _219$$64, _220$$64, _218$$65, _221$$66, _222$$66, _223$$66, _224$$66, re$$67, *_225$$67, _226$$67, _267$$67, _268$$67, _269$$67, _270$$67, _271$$67, _272$$67, _227$$68, _228$$68, _229$$68, _230$$68, _231$$69, _232$$70, _233$$70, _234$$70, _235$$70, _236$$70, _237$$70, _238$$71, _239$$71, _240$$71, _241$$71, _242$$71, _243$$71, _244$$71, _245$$71, _246$$72, _247$$73, _248$$73, _249$$73, _250$$73, _251$$74, _252$$75, _253$$75, _254$$75, _255$$75, _256$$75, _257$$75, _258$$76, _259$$76, _260$$76, _261$$76, _262$$76, _263$$76, _264$$76, _265$$76, _266$$77, newNode$$79, _274$$79, _275$$80, _276$$80, newTree$$81, _278$$82, _280$$82, _281$$82, _279$$83, _282$$84, method$$85, *_287$$85, _288$$85, _289$$86, _291$$86, tree$$86, _292$$86, _293$$86, _423$$86, _424$$86, _290$$87, *_294$$88, _295$$88, _298$$89, _299$$89, _300$$89, _301$$89, re$$90, *_302$$90, _303$$90, _344$$90, _345$$90, _346$$90, _347$$90, _348$$90, _349$$90, _304$$91, _305$$91, _306$$91, _307$$91, _308$$92, _309$$93, _310$$93, _311$$93, _312$$93, _313$$93, _314$$93, _315$$94, _316$$94, _317$$94, _318$$94, _319$$94, _320$$94, _321$$94, _322$$94, _323$$95, _324$$96, _325$$96, _326$$96, _327$$96, _328$$97, _329$$98, _330$$98, _331$$98, _332$$98, _333$$98, _334$$98, _335$$99, _336$$99, _337$$99, _338$$99, _339$$99, _340$$99, _341$$99, _342$$99, _343$$100, newNode$$102, _351$$102, _352$$103, _353$$103, newTree$$104, _355$$105, _357$$105, _358$$105, _356$$106, _359$$107, _360$$107, _361$$107, _362$$107, re$$108, *_363$$108, _364$$108, _405$$108, _406$$108, _407$$108, _408$$108, _409$$108, _410$$108, _365$$109, _366$$109, _367$$109, _368$$109, _369$$110, _370$$111, _371$$111, _372$$111, _373$$111, _374$$111, _375$$111, _376$$112, _377$$112, _378$$112, _379$$112, _380$$112, _381$$112, _382$$112, _383$$112, _384$$113, _385$$114, _386$$114, _387$$114, _388$$114, _389$$115, _390$$116, _391$$116, _392$$116, _393$$116, _394$$116, _395$$116, _396$$117, _397$$117, _398$$117, _399$$117, _400$$117, _401$$117, _402$$117, _403$$117, _404$$118, newNode$$120, _412$$120, _413$$121, _414$$121, newTree$$122, _416$$123, _418$$123, _419$$123, _417$$124, _420$$125, _425$$126, _427$$126, tree$$126, _428$$126, _429$$126, _559$$126, _560$$126, _426$$127, *_430$$128, _431$$128, _434$$129, _435$$129, _436$$129, _437$$129, re$$130, *_438$$130, _439$$130, _480$$130, _481$$130, _482$$130, _483$$130, _484$$130, _485$$130, _440$$131, _441$$131, _442$$131, _443$$131, _444$$132, _445$$133, _446$$133, _447$$133, _448$$133, _449$$133, _450$$133, _451$$134, _452$$134, _453$$134, _454$$134, _455$$134, _456$$134, _457$$134, _458$$134, _459$$135, _460$$136, _461$$136, _462$$136, _463$$136, _464$$137, _465$$138, _466$$138, _467$$138, _468$$138, _469$$138, _470$$138, _471$$139, _472$$139, _473$$139, _474$$139, _475$$139, _476$$139, _477$$139, _478$$139, _479$$140, newNode$$142, _487$$142, _488$$143, _489$$143, newTree$$144, _491$$145, _493$$145, _494$$145, _492$$146, _495$$147, _496$$147, _497$$147, _498$$147, re$$148, *_499$$148, _500$$148, _541$$148, _542$$148, _543$$148, _544$$148, _545$$148, _546$$148, _501$$149, _502$$149, _503$$149, _504$$149, _505$$150, _506$$151, _507$$151, _508$$151, _509$$151, _510$$151, _511$$151, _512$$152, _513$$152, _514$$152, _515$$152, _516$$152, _517$$152, _518$$152, _519$$152, _520$$153, _521$$154, _522$$154, _523$$154, _524$$154, _525$$155, _526$$156, _527$$156, _528$$156, _529$$156, _530$$156, _531$$156, _532$$157, _533$$157, _534$$157, _535$$157, _536$$157, _537$$157, _538$$157, _539$$157, _540$$158, newNode$$160, _548$$160, _549$$161, _550$$161, newTree$$162, _552$$163, _554$$163, _555$$163, _553$$164, _556$$165;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_14 = NULL, *_15 = NULL, *_24 = NULL, *_38 = NULL, *_74 = NULL, *_75 = NULL, *_79 = NULL, *_80 = NULL, *_137 = NULL, *_141 = NULL, *_147 = NULL, *_212 = NULL, *_216 = NULL, *_273 = NULL, *_277 = NULL, *_283 = NULL, *_350 = NULL, *_354 = NULL, *_411 = NULL, *_415 = NULL, *_421 = NULL, *_486 = NULL, *_490 = NULL, *_547 = NULL, *_551 = NULL, *_557 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&priority);
	ZVAL_UNDEF(&formatStr);
	ZVAL_UNDEF(&regexPos);
	ZVAL_UNDEF(&regexKey);
	ZVAL_UNDEF(&regexArr);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&uriArr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&method$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&tree$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_149$$5);
	ZVAL_UNDEF(&_150$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&re$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_68$$9);
	ZVAL_UNDEF(&_69$$9);
	ZVAL_UNDEF(&_70$$9);
	ZVAL_UNDEF(&_71$$9);
	ZVAL_UNDEF(&_72$$9);
	ZVAL_UNDEF(&_73$$9);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_35$$12);
	ZVAL_UNDEF(&_36$$12);
	ZVAL_UNDEF(&_37$$12);
	ZVAL_UNDEF(&_39$$13);
	ZVAL_UNDEF(&_40$$13);
	ZVAL_UNDEF(&_41$$13);
	ZVAL_UNDEF(&_42$$13);
	ZVAL_UNDEF(&_43$$13);
	ZVAL_UNDEF(&_44$$13);
	ZVAL_UNDEF(&_45$$13);
	ZVAL_UNDEF(&_46$$13);
	ZVAL_UNDEF(&_47$$14);
	ZVAL_UNDEF(&_48$$15);
	ZVAL_UNDEF(&_49$$15);
	ZVAL_UNDEF(&_50$$15);
	ZVAL_UNDEF(&_51$$15);
	ZVAL_UNDEF(&_52$$16);
	ZVAL_UNDEF(&_53$$17);
	ZVAL_UNDEF(&_54$$17);
	ZVAL_UNDEF(&_55$$17);
	ZVAL_UNDEF(&_56$$17);
	ZVAL_UNDEF(&_57$$17);
	ZVAL_UNDEF(&_58$$17);
	ZVAL_UNDEF(&_59$$18);
	ZVAL_UNDEF(&_60$$18);
	ZVAL_UNDEF(&_61$$18);
	ZVAL_UNDEF(&_62$$18);
	ZVAL_UNDEF(&_63$$18);
	ZVAL_UNDEF(&_64$$18);
	ZVAL_UNDEF(&_65$$18);
	ZVAL_UNDEF(&_66$$18);
	ZVAL_UNDEF(&_67$$19);
	ZVAL_UNDEF(&newNode$$21);
	ZVAL_UNDEF(&_76$$21);
	ZVAL_UNDEF(&_77$$22);
	ZVAL_UNDEF(&_78$$22);
	ZVAL_UNDEF(&newTree$$23);
	ZVAL_UNDEF(&_81$$24);
	ZVAL_UNDEF(&_83$$24);
	ZVAL_UNDEF(&_84$$24);
	ZVAL_UNDEF(&_82$$25);
	ZVAL_UNDEF(&_85$$26);
	ZVAL_UNDEF(&_86$$26);
	ZVAL_UNDEF(&_87$$26);
	ZVAL_UNDEF(&_88$$26);
	ZVAL_UNDEF(&re$$27);
	ZVAL_UNDEF(&_90$$27);
	ZVAL_UNDEF(&_131$$27);
	ZVAL_UNDEF(&_132$$27);
	ZVAL_UNDEF(&_133$$27);
	ZVAL_UNDEF(&_134$$27);
	ZVAL_UNDEF(&_135$$27);
	ZVAL_UNDEF(&_136$$27);
	ZVAL_UNDEF(&_91$$28);
	ZVAL_UNDEF(&_92$$28);
	ZVAL_UNDEF(&_93$$28);
	ZVAL_UNDEF(&_94$$28);
	ZVAL_UNDEF(&_95$$29);
	ZVAL_UNDEF(&_96$$30);
	ZVAL_UNDEF(&_97$$30);
	ZVAL_UNDEF(&_98$$30);
	ZVAL_UNDEF(&_99$$30);
	ZVAL_UNDEF(&_100$$30);
	ZVAL_UNDEF(&_101$$30);
	ZVAL_UNDEF(&_102$$31);
	ZVAL_UNDEF(&_103$$31);
	ZVAL_UNDEF(&_104$$31);
	ZVAL_UNDEF(&_105$$31);
	ZVAL_UNDEF(&_106$$31);
	ZVAL_UNDEF(&_107$$31);
	ZVAL_UNDEF(&_108$$31);
	ZVAL_UNDEF(&_109$$31);
	ZVAL_UNDEF(&_110$$32);
	ZVAL_UNDEF(&_111$$33);
	ZVAL_UNDEF(&_112$$33);
	ZVAL_UNDEF(&_113$$33);
	ZVAL_UNDEF(&_114$$33);
	ZVAL_UNDEF(&_115$$34);
	ZVAL_UNDEF(&_116$$35);
	ZVAL_UNDEF(&_117$$35);
	ZVAL_UNDEF(&_118$$35);
	ZVAL_UNDEF(&_119$$35);
	ZVAL_UNDEF(&_120$$35);
	ZVAL_UNDEF(&_121$$35);
	ZVAL_UNDEF(&_122$$36);
	ZVAL_UNDEF(&_123$$36);
	ZVAL_UNDEF(&_124$$36);
	ZVAL_UNDEF(&_125$$36);
	ZVAL_UNDEF(&_126$$36);
	ZVAL_UNDEF(&_127$$36);
	ZVAL_UNDEF(&_128$$36);
	ZVAL_UNDEF(&_129$$36);
	ZVAL_UNDEF(&_130$$37);
	ZVAL_UNDEF(&newNode$$39);
	ZVAL_UNDEF(&_138$$39);
	ZVAL_UNDEF(&_139$$40);
	ZVAL_UNDEF(&_140$$40);
	ZVAL_UNDEF(&newTree$$41);
	ZVAL_UNDEF(&_142$$42);
	ZVAL_UNDEF(&_144$$42);
	ZVAL_UNDEF(&_145$$42);
	ZVAL_UNDEF(&_143$$43);
	ZVAL_UNDEF(&_146$$44);
	ZVAL_UNDEF(&_151$$45);
	ZVAL_UNDEF(&_153$$45);
	ZVAL_UNDEF(&tree$$45);
	ZVAL_UNDEF(&_154$$45);
	ZVAL_UNDEF(&_155$$45);
	ZVAL_UNDEF(&_285$$45);
	ZVAL_UNDEF(&_286$$45);
	ZVAL_UNDEF(&_152$$46);
	ZVAL_UNDEF(&_157$$47);
	ZVAL_UNDEF(&_160$$48);
	ZVAL_UNDEF(&_161$$48);
	ZVAL_UNDEF(&_162$$48);
	ZVAL_UNDEF(&_163$$48);
	ZVAL_UNDEF(&re$$49);
	ZVAL_UNDEF(&_165$$49);
	ZVAL_UNDEF(&_206$$49);
	ZVAL_UNDEF(&_207$$49);
	ZVAL_UNDEF(&_208$$49);
	ZVAL_UNDEF(&_209$$49);
	ZVAL_UNDEF(&_210$$49);
	ZVAL_UNDEF(&_211$$49);
	ZVAL_UNDEF(&_166$$50);
	ZVAL_UNDEF(&_167$$50);
	ZVAL_UNDEF(&_168$$50);
	ZVAL_UNDEF(&_169$$50);
	ZVAL_UNDEF(&_170$$51);
	ZVAL_UNDEF(&_171$$52);
	ZVAL_UNDEF(&_172$$52);
	ZVAL_UNDEF(&_173$$52);
	ZVAL_UNDEF(&_174$$52);
	ZVAL_UNDEF(&_175$$52);
	ZVAL_UNDEF(&_176$$52);
	ZVAL_UNDEF(&_177$$53);
	ZVAL_UNDEF(&_178$$53);
	ZVAL_UNDEF(&_179$$53);
	ZVAL_UNDEF(&_180$$53);
	ZVAL_UNDEF(&_181$$53);
	ZVAL_UNDEF(&_182$$53);
	ZVAL_UNDEF(&_183$$53);
	ZVAL_UNDEF(&_184$$53);
	ZVAL_UNDEF(&_185$$54);
	ZVAL_UNDEF(&_186$$55);
	ZVAL_UNDEF(&_187$$55);
	ZVAL_UNDEF(&_188$$55);
	ZVAL_UNDEF(&_189$$55);
	ZVAL_UNDEF(&_190$$56);
	ZVAL_UNDEF(&_191$$57);
	ZVAL_UNDEF(&_192$$57);
	ZVAL_UNDEF(&_193$$57);
	ZVAL_UNDEF(&_194$$57);
	ZVAL_UNDEF(&_195$$57);
	ZVAL_UNDEF(&_196$$57);
	ZVAL_UNDEF(&_197$$58);
	ZVAL_UNDEF(&_198$$58);
	ZVAL_UNDEF(&_199$$58);
	ZVAL_UNDEF(&_200$$58);
	ZVAL_UNDEF(&_201$$58);
	ZVAL_UNDEF(&_202$$58);
	ZVAL_UNDEF(&_203$$58);
	ZVAL_UNDEF(&_204$$58);
	ZVAL_UNDEF(&_205$$59);
	ZVAL_UNDEF(&newNode$$61);
	ZVAL_UNDEF(&_213$$61);
	ZVAL_UNDEF(&_214$$62);
	ZVAL_UNDEF(&_215$$62);
	ZVAL_UNDEF(&newTree$$63);
	ZVAL_UNDEF(&_217$$64);
	ZVAL_UNDEF(&_219$$64);
	ZVAL_UNDEF(&_220$$64);
	ZVAL_UNDEF(&_218$$65);
	ZVAL_UNDEF(&_221$$66);
	ZVAL_UNDEF(&_222$$66);
	ZVAL_UNDEF(&_223$$66);
	ZVAL_UNDEF(&_224$$66);
	ZVAL_UNDEF(&re$$67);
	ZVAL_UNDEF(&_226$$67);
	ZVAL_UNDEF(&_267$$67);
	ZVAL_UNDEF(&_268$$67);
	ZVAL_UNDEF(&_269$$67);
	ZVAL_UNDEF(&_270$$67);
	ZVAL_UNDEF(&_271$$67);
	ZVAL_UNDEF(&_272$$67);
	ZVAL_UNDEF(&_227$$68);
	ZVAL_UNDEF(&_228$$68);
	ZVAL_UNDEF(&_229$$68);
	ZVAL_UNDEF(&_230$$68);
	ZVAL_UNDEF(&_231$$69);
	ZVAL_UNDEF(&_232$$70);
	ZVAL_UNDEF(&_233$$70);
	ZVAL_UNDEF(&_234$$70);
	ZVAL_UNDEF(&_235$$70);
	ZVAL_UNDEF(&_236$$70);
	ZVAL_UNDEF(&_237$$70);
	ZVAL_UNDEF(&_238$$71);
	ZVAL_UNDEF(&_239$$71);
	ZVAL_UNDEF(&_240$$71);
	ZVAL_UNDEF(&_241$$71);
	ZVAL_UNDEF(&_242$$71);
	ZVAL_UNDEF(&_243$$71);
	ZVAL_UNDEF(&_244$$71);
	ZVAL_UNDEF(&_245$$71);
	ZVAL_UNDEF(&_246$$72);
	ZVAL_UNDEF(&_247$$73);
	ZVAL_UNDEF(&_248$$73);
	ZVAL_UNDEF(&_249$$73);
	ZVAL_UNDEF(&_250$$73);
	ZVAL_UNDEF(&_251$$74);
	ZVAL_UNDEF(&_252$$75);
	ZVAL_UNDEF(&_253$$75);
	ZVAL_UNDEF(&_254$$75);
	ZVAL_UNDEF(&_255$$75);
	ZVAL_UNDEF(&_256$$75);
	ZVAL_UNDEF(&_257$$75);
	ZVAL_UNDEF(&_258$$76);
	ZVAL_UNDEF(&_259$$76);
	ZVAL_UNDEF(&_260$$76);
	ZVAL_UNDEF(&_261$$76);
	ZVAL_UNDEF(&_262$$76);
	ZVAL_UNDEF(&_263$$76);
	ZVAL_UNDEF(&_264$$76);
	ZVAL_UNDEF(&_265$$76);
	ZVAL_UNDEF(&_266$$77);
	ZVAL_UNDEF(&newNode$$79);
	ZVAL_UNDEF(&_274$$79);
	ZVAL_UNDEF(&_275$$80);
	ZVAL_UNDEF(&_276$$80);
	ZVAL_UNDEF(&newTree$$81);
	ZVAL_UNDEF(&_278$$82);
	ZVAL_UNDEF(&_280$$82);
	ZVAL_UNDEF(&_281$$82);
	ZVAL_UNDEF(&_279$$83);
	ZVAL_UNDEF(&_282$$84);
	ZVAL_UNDEF(&method$$85);
	ZVAL_UNDEF(&_288$$85);
	ZVAL_UNDEF(&_289$$86);
	ZVAL_UNDEF(&_291$$86);
	ZVAL_UNDEF(&tree$$86);
	ZVAL_UNDEF(&_292$$86);
	ZVAL_UNDEF(&_293$$86);
	ZVAL_UNDEF(&_423$$86);
	ZVAL_UNDEF(&_424$$86);
	ZVAL_UNDEF(&_290$$87);
	ZVAL_UNDEF(&_295$$88);
	ZVAL_UNDEF(&_298$$89);
	ZVAL_UNDEF(&_299$$89);
	ZVAL_UNDEF(&_300$$89);
	ZVAL_UNDEF(&_301$$89);
	ZVAL_UNDEF(&re$$90);
	ZVAL_UNDEF(&_303$$90);
	ZVAL_UNDEF(&_344$$90);
	ZVAL_UNDEF(&_345$$90);
	ZVAL_UNDEF(&_346$$90);
	ZVAL_UNDEF(&_347$$90);
	ZVAL_UNDEF(&_348$$90);
	ZVAL_UNDEF(&_349$$90);
	ZVAL_UNDEF(&_304$$91);
	ZVAL_UNDEF(&_305$$91);
	ZVAL_UNDEF(&_306$$91);
	ZVAL_UNDEF(&_307$$91);
	ZVAL_UNDEF(&_308$$92);
	ZVAL_UNDEF(&_309$$93);
	ZVAL_UNDEF(&_310$$93);
	ZVAL_UNDEF(&_311$$93);
	ZVAL_UNDEF(&_312$$93);
	ZVAL_UNDEF(&_313$$93);
	ZVAL_UNDEF(&_314$$93);
	ZVAL_UNDEF(&_315$$94);
	ZVAL_UNDEF(&_316$$94);
	ZVAL_UNDEF(&_317$$94);
	ZVAL_UNDEF(&_318$$94);
	ZVAL_UNDEF(&_319$$94);
	ZVAL_UNDEF(&_320$$94);
	ZVAL_UNDEF(&_321$$94);
	ZVAL_UNDEF(&_322$$94);
	ZVAL_UNDEF(&_323$$95);
	ZVAL_UNDEF(&_324$$96);
	ZVAL_UNDEF(&_325$$96);
	ZVAL_UNDEF(&_326$$96);
	ZVAL_UNDEF(&_327$$96);
	ZVAL_UNDEF(&_328$$97);
	ZVAL_UNDEF(&_329$$98);
	ZVAL_UNDEF(&_330$$98);
	ZVAL_UNDEF(&_331$$98);
	ZVAL_UNDEF(&_332$$98);
	ZVAL_UNDEF(&_333$$98);
	ZVAL_UNDEF(&_334$$98);
	ZVAL_UNDEF(&_335$$99);
	ZVAL_UNDEF(&_336$$99);
	ZVAL_UNDEF(&_337$$99);
	ZVAL_UNDEF(&_338$$99);
	ZVAL_UNDEF(&_339$$99);
	ZVAL_UNDEF(&_340$$99);
	ZVAL_UNDEF(&_341$$99);
	ZVAL_UNDEF(&_342$$99);
	ZVAL_UNDEF(&_343$$100);
	ZVAL_UNDEF(&newNode$$102);
	ZVAL_UNDEF(&_351$$102);
	ZVAL_UNDEF(&_352$$103);
	ZVAL_UNDEF(&_353$$103);
	ZVAL_UNDEF(&newTree$$104);
	ZVAL_UNDEF(&_355$$105);
	ZVAL_UNDEF(&_357$$105);
	ZVAL_UNDEF(&_358$$105);
	ZVAL_UNDEF(&_356$$106);
	ZVAL_UNDEF(&_359$$107);
	ZVAL_UNDEF(&_360$$107);
	ZVAL_UNDEF(&_361$$107);
	ZVAL_UNDEF(&_362$$107);
	ZVAL_UNDEF(&re$$108);
	ZVAL_UNDEF(&_364$$108);
	ZVAL_UNDEF(&_405$$108);
	ZVAL_UNDEF(&_406$$108);
	ZVAL_UNDEF(&_407$$108);
	ZVAL_UNDEF(&_408$$108);
	ZVAL_UNDEF(&_409$$108);
	ZVAL_UNDEF(&_410$$108);
	ZVAL_UNDEF(&_365$$109);
	ZVAL_UNDEF(&_366$$109);
	ZVAL_UNDEF(&_367$$109);
	ZVAL_UNDEF(&_368$$109);
	ZVAL_UNDEF(&_369$$110);
	ZVAL_UNDEF(&_370$$111);
	ZVAL_UNDEF(&_371$$111);
	ZVAL_UNDEF(&_372$$111);
	ZVAL_UNDEF(&_373$$111);
	ZVAL_UNDEF(&_374$$111);
	ZVAL_UNDEF(&_375$$111);
	ZVAL_UNDEF(&_376$$112);
	ZVAL_UNDEF(&_377$$112);
	ZVAL_UNDEF(&_378$$112);
	ZVAL_UNDEF(&_379$$112);
	ZVAL_UNDEF(&_380$$112);
	ZVAL_UNDEF(&_381$$112);
	ZVAL_UNDEF(&_382$$112);
	ZVAL_UNDEF(&_383$$112);
	ZVAL_UNDEF(&_384$$113);
	ZVAL_UNDEF(&_385$$114);
	ZVAL_UNDEF(&_386$$114);
	ZVAL_UNDEF(&_387$$114);
	ZVAL_UNDEF(&_388$$114);
	ZVAL_UNDEF(&_389$$115);
	ZVAL_UNDEF(&_390$$116);
	ZVAL_UNDEF(&_391$$116);
	ZVAL_UNDEF(&_392$$116);
	ZVAL_UNDEF(&_393$$116);
	ZVAL_UNDEF(&_394$$116);
	ZVAL_UNDEF(&_395$$116);
	ZVAL_UNDEF(&_396$$117);
	ZVAL_UNDEF(&_397$$117);
	ZVAL_UNDEF(&_398$$117);
	ZVAL_UNDEF(&_399$$117);
	ZVAL_UNDEF(&_400$$117);
	ZVAL_UNDEF(&_401$$117);
	ZVAL_UNDEF(&_402$$117);
	ZVAL_UNDEF(&_403$$117);
	ZVAL_UNDEF(&_404$$118);
	ZVAL_UNDEF(&newNode$$120);
	ZVAL_UNDEF(&_412$$120);
	ZVAL_UNDEF(&_413$$121);
	ZVAL_UNDEF(&_414$$121);
	ZVAL_UNDEF(&newTree$$122);
	ZVAL_UNDEF(&_416$$123);
	ZVAL_UNDEF(&_418$$123);
	ZVAL_UNDEF(&_419$$123);
	ZVAL_UNDEF(&_417$$124);
	ZVAL_UNDEF(&_420$$125);
	ZVAL_UNDEF(&_425$$126);
	ZVAL_UNDEF(&_427$$126);
	ZVAL_UNDEF(&tree$$126);
	ZVAL_UNDEF(&_428$$126);
	ZVAL_UNDEF(&_429$$126);
	ZVAL_UNDEF(&_559$$126);
	ZVAL_UNDEF(&_560$$126);
	ZVAL_UNDEF(&_426$$127);
	ZVAL_UNDEF(&_431$$128);
	ZVAL_UNDEF(&_434$$129);
	ZVAL_UNDEF(&_435$$129);
	ZVAL_UNDEF(&_436$$129);
	ZVAL_UNDEF(&_437$$129);
	ZVAL_UNDEF(&re$$130);
	ZVAL_UNDEF(&_439$$130);
	ZVAL_UNDEF(&_480$$130);
	ZVAL_UNDEF(&_481$$130);
	ZVAL_UNDEF(&_482$$130);
	ZVAL_UNDEF(&_483$$130);
	ZVAL_UNDEF(&_484$$130);
	ZVAL_UNDEF(&_485$$130);
	ZVAL_UNDEF(&_440$$131);
	ZVAL_UNDEF(&_441$$131);
	ZVAL_UNDEF(&_442$$131);
	ZVAL_UNDEF(&_443$$131);
	ZVAL_UNDEF(&_444$$132);
	ZVAL_UNDEF(&_445$$133);
	ZVAL_UNDEF(&_446$$133);
	ZVAL_UNDEF(&_447$$133);
	ZVAL_UNDEF(&_448$$133);
	ZVAL_UNDEF(&_449$$133);
	ZVAL_UNDEF(&_450$$133);
	ZVAL_UNDEF(&_451$$134);
	ZVAL_UNDEF(&_452$$134);
	ZVAL_UNDEF(&_453$$134);
	ZVAL_UNDEF(&_454$$134);
	ZVAL_UNDEF(&_455$$134);
	ZVAL_UNDEF(&_456$$134);
	ZVAL_UNDEF(&_457$$134);
	ZVAL_UNDEF(&_458$$134);
	ZVAL_UNDEF(&_459$$135);
	ZVAL_UNDEF(&_460$$136);
	ZVAL_UNDEF(&_461$$136);
	ZVAL_UNDEF(&_462$$136);
	ZVAL_UNDEF(&_463$$136);
	ZVAL_UNDEF(&_464$$137);
	ZVAL_UNDEF(&_465$$138);
	ZVAL_UNDEF(&_466$$138);
	ZVAL_UNDEF(&_467$$138);
	ZVAL_UNDEF(&_468$$138);
	ZVAL_UNDEF(&_469$$138);
	ZVAL_UNDEF(&_470$$138);
	ZVAL_UNDEF(&_471$$139);
	ZVAL_UNDEF(&_472$$139);
	ZVAL_UNDEF(&_473$$139);
	ZVAL_UNDEF(&_474$$139);
	ZVAL_UNDEF(&_475$$139);
	ZVAL_UNDEF(&_476$$139);
	ZVAL_UNDEF(&_477$$139);
	ZVAL_UNDEF(&_478$$139);
	ZVAL_UNDEF(&_479$$140);
	ZVAL_UNDEF(&newNode$$142);
	ZVAL_UNDEF(&_487$$142);
	ZVAL_UNDEF(&_488$$143);
	ZVAL_UNDEF(&_489$$143);
	ZVAL_UNDEF(&newTree$$144);
	ZVAL_UNDEF(&_491$$145);
	ZVAL_UNDEF(&_493$$145);
	ZVAL_UNDEF(&_494$$145);
	ZVAL_UNDEF(&_492$$146);
	ZVAL_UNDEF(&_495$$147);
	ZVAL_UNDEF(&_496$$147);
	ZVAL_UNDEF(&_497$$147);
	ZVAL_UNDEF(&_498$$147);
	ZVAL_UNDEF(&re$$148);
	ZVAL_UNDEF(&_500$$148);
	ZVAL_UNDEF(&_541$$148);
	ZVAL_UNDEF(&_542$$148);
	ZVAL_UNDEF(&_543$$148);
	ZVAL_UNDEF(&_544$$148);
	ZVAL_UNDEF(&_545$$148);
	ZVAL_UNDEF(&_546$$148);
	ZVAL_UNDEF(&_501$$149);
	ZVAL_UNDEF(&_502$$149);
	ZVAL_UNDEF(&_503$$149);
	ZVAL_UNDEF(&_504$$149);
	ZVAL_UNDEF(&_505$$150);
	ZVAL_UNDEF(&_506$$151);
	ZVAL_UNDEF(&_507$$151);
	ZVAL_UNDEF(&_508$$151);
	ZVAL_UNDEF(&_509$$151);
	ZVAL_UNDEF(&_510$$151);
	ZVAL_UNDEF(&_511$$151);
	ZVAL_UNDEF(&_512$$152);
	ZVAL_UNDEF(&_513$$152);
	ZVAL_UNDEF(&_514$$152);
	ZVAL_UNDEF(&_515$$152);
	ZVAL_UNDEF(&_516$$152);
	ZVAL_UNDEF(&_517$$152);
	ZVAL_UNDEF(&_518$$152);
	ZVAL_UNDEF(&_519$$152);
	ZVAL_UNDEF(&_520$$153);
	ZVAL_UNDEF(&_521$$154);
	ZVAL_UNDEF(&_522$$154);
	ZVAL_UNDEF(&_523$$154);
	ZVAL_UNDEF(&_524$$154);
	ZVAL_UNDEF(&_525$$155);
	ZVAL_UNDEF(&_526$$156);
	ZVAL_UNDEF(&_527$$156);
	ZVAL_UNDEF(&_528$$156);
	ZVAL_UNDEF(&_529$$156);
	ZVAL_UNDEF(&_530$$156);
	ZVAL_UNDEF(&_531$$156);
	ZVAL_UNDEF(&_532$$157);
	ZVAL_UNDEF(&_533$$157);
	ZVAL_UNDEF(&_534$$157);
	ZVAL_UNDEF(&_535$$157);
	ZVAL_UNDEF(&_536$$157);
	ZVAL_UNDEF(&_537$$157);
	ZVAL_UNDEF(&_538$$157);
	ZVAL_UNDEF(&_539$$157);
	ZVAL_UNDEF(&_540$$158);
	ZVAL_UNDEF(&newNode$$160);
	ZVAL_UNDEF(&_548$$160);
	ZVAL_UNDEF(&_549$$161);
	ZVAL_UNDEF(&_550$$161);
	ZVAL_UNDEF(&newTree$$162);
	ZVAL_UNDEF(&_552$$163);
	ZVAL_UNDEF(&_554$$163);
	ZVAL_UNDEF(&_555$$163);
	ZVAL_UNDEF(&_553$$164);
	ZVAL_UNDEF(&_556$$165);
	ZVAL_UNDEF(&_148$$5);
	ZVAL_UNDEF(&_284$$45);
	ZVAL_UNDEF(&_422$$86);
	ZVAL_UNDEF(&_558$$126);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("routers"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("priority"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("routers"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 3);
	ZEPHIR_MAKE_REF(&_1);
	ZEPHIR_MAKE_REF(&_3);
	ZEPHIR_MAKE_REF(&_2);
	ZEPHIR_CALL_FUNCTION(NULL, "array_multisort", NULL, 155, &_1, &_3, &_2);
	ZEPHIR_UNREF(&_1);
	ZEPHIR_UNREF(&_3);
	ZEPHIR_UNREF(&_2);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("routers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "moon/Component/Router/Router.zep", 381);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&router);
			ZVAL_COPY(&router, _4);
			ZEPHIR_OBS_NVAR(&methods);
			zephir_array_fetch_string(&methods, &router, SL("methods"), PH_NOISY, "moon/Component/Router/Router.zep", 275);
			ZEPHIR_OBS_NVAR(&uri);
			zephir_array_fetch_string(&uri, &router, SL("uri"), PH_NOISY, "moon/Component/Router/Router.zep", 276);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_string(&handler, &router, SL("handler"), PH_NOISY, "moon/Component/Router/Router.zep", 277);
			ZEPHIR_OBS_NVAR(&routeName);
			zephir_array_fetch_string(&routeName, &router, SL("routeName"), PH_NOISY, "moon/Component/Router/Router.zep", 278);
			ZEPHIR_OBS_NVAR(&priority);
			zephir_array_fetch_string(&priority, &router, SL("priority"), PH_NOISY, "moon/Component/Router/Router.zep", 279);
			zephir_is_iterable(&methods, 0, "moon/Component/Router/Router.zep", 380);
			if (Z_TYPE_P(&methods) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _6$$4)
				{
					ZEPHIR_INIT_NVAR(&method$$4);
					ZVAL_COPY(&method$$4, _6$$4);
					zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset(&_8$$5, &method$$4))) {
						ZEPHIR_INIT_NVAR(&_9$$6);
						object_init_ex(&_9$$6, moon_component_router_treenode_ce);
						if (zephir_has_constructor(&_9$$6)) {
							ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", NULL, 0);
							zephir_check_call_status();
						}
						zephir_update_property_array(this_ptr, SL("nodes"), &method$$4, &_9$$6);
					}
					ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "generateroutename", &_11, 156, &routeName, &method$$4, &uri);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&routeName, &_10$$5);
					zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&tree$$5);
					zephir_array_fetch(&tree$$5, &_12$$5, &method$$4, PH_NOISY, "moon/Component/Router/Router.zep", 295);
					ZEPHIR_INIT_NVAR(&_13$$5);
					zephir_fast_explode_str(&_13$$5, SL("/"), &uri, LONG_MAX);
					ZEPHIR_CALL_FUNCTION(&_10$$5, "array_filter", &_14, 95, &_13$$5);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_15, 75, &_10$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&length);
					ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
					if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
						zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 368);
						if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uriArr), _18$$7, _19$$7, _16$$7)
							{
								ZEPHIR_INIT_NVAR(&i);
								if (_19$$7 != NULL) { 
									ZVAL_STR_COPY(&i, _19$$7);
								} else {
									ZVAL_LONG(&i, _18$$7);
								}
								ZEPHIR_INIT_NVAR(&item);
								ZVAL_COPY(&item, _16$$7);
								ZVAL_LONG(&_20$$8, 0);
								ZVAL_LONG(&_21$$8, 1);
								ZEPHIR_INIT_NVAR(&_22$$8);
								zephir_substr(&_22$$8, &item, 0 , 1 , 0);
								ZEPHIR_INIT_NVAR(&_23$$8);
								ZVAL_STRING(&_23$$8, "{");
								if (ZEPHIR_IS_EQUAL(&_23$$8, &_22$$8)) {
									ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&regexKey);
									ZVAL_STRING(&regexKey, "");
									zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 326);
									if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _25$$9)
										{
											ZEPHIR_INIT_NVAR(&re$$9);
											ZVAL_COPY(&re$$9, _25$$9);
											ZVAL_LONG(&_27$$10, 0);
											ZVAL_LONG(&_28$$10, 1);
											ZEPHIR_INIT_NVAR(&_29$$10);
											zephir_substr(&_29$$10, &re$$9, 0 , 1 , 0);
											ZEPHIR_INIT_NVAR(&_30$$10);
											ZVAL_STRING(&_30$$10, "{");
											if (ZEPHIR_IS_EQUAL(&_30$$10, &_29$$10)) {
												ZEPHIR_INIT_NVAR(&_31$$11);
												ZVAL_STRING(&_31$$11, "<");
												ZEPHIR_INIT_NVAR(&regexPos);
												zephir_fast_strpos(&regexPos, &re$$9, &_31$$11, 0 );
												ZEPHIR_INIT_NVAR(&formatStr);
												ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
												if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
													ZVAL_LONG(&_32$$12, 1);
													ZVAL_LONG(&_33$$12, -1);
													ZEPHIR_INIT_NVAR(&_34$$12);
													zephir_substr(&_34$$12, &re$$9, 1 , -1 , 0);
													ZEPHIR_INIT_NVAR(&_35$$12);
													ZVAL_STRING(&_35$$12, "___");
													ZEPHIR_INIT_NVAR(&_36$$12);
													ZVAL_STRING(&_36$$12, "[^/]+");
													ZEPHIR_CALL_FUNCTION(&_37$$12, "sprintf", &_38, 3, &formatStr, &_34$$12, &_35$$12, &routeName, &_36$$12);
													zephir_check_call_status();
													zephir_concat_self(&regexKey, &_37$$12);
												} else {
													ZVAL_LONG(&_39$$13, 1);
													ZVAL_LONG(&_40$$13, (zephir_get_numberval(&regexPos) - 1));
													ZEPHIR_INIT_NVAR(&_41$$13);
													zephir_substr(&_41$$13, &re$$9, 1 , zephir_get_intval(&_40$$13), 0);
													ZVAL_LONG(&_42$$13, (zephir_get_numberval(&regexPos) + 1));
													ZVAL_LONG(&_43$$13, -2);
													ZEPHIR_INIT_NVAR(&_44$$13);
													zephir_substr(&_44$$13, &re$$9, zephir_get_intval(&_42$$13), -2 , 0);
													ZEPHIR_INIT_NVAR(&_45$$13);
													ZVAL_STRING(&_45$$13, "___");
													ZEPHIR_CALL_FUNCTION(&_46$$13, "sprintf", &_38, 3, &formatStr, &_41$$13, &_45$$13, &routeName, &_44$$13);
													zephir_check_call_status();
													zephir_concat_self(&regexKey, &_46$$13);
												}
											} else {
												ZEPHIR_INIT_NVAR(&_47$$14);
												ZEPHIR_CONCAT_SV(&_47$$14, "/", &re$$9);
												zephir_concat_self(&regexKey, &_47$$14);
											}
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_26$$9, &regexArr, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_26$$9)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&re$$9, &regexArr, "current", NULL, 0);
											zephir_check_call_status();
												ZVAL_LONG(&_48$$15, 0);
												ZVAL_LONG(&_49$$15, 1);
												ZEPHIR_INIT_NVAR(&_50$$15);
												zephir_substr(&_50$$15, &re$$9, 0 , 1 , 0);
												ZEPHIR_INIT_NVAR(&_51$$15);
												ZVAL_STRING(&_51$$15, "{");
												if (ZEPHIR_IS_EQUAL(&_51$$15, &_50$$15)) {
													ZEPHIR_INIT_NVAR(&_52$$16);
													ZVAL_STRING(&_52$$16, "<");
													ZEPHIR_INIT_NVAR(&regexPos);
													zephir_fast_strpos(&regexPos, &re$$9, &_52$$16, 0 );
													ZEPHIR_INIT_NVAR(&formatStr);
													ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
													if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
														ZVAL_LONG(&_53$$17, 1);
														ZVAL_LONG(&_54$$17, -1);
														ZEPHIR_INIT_NVAR(&_55$$17);
														zephir_substr(&_55$$17, &re$$9, 1 , -1 , 0);
														ZEPHIR_INIT_NVAR(&_56$$17);
														ZVAL_STRING(&_56$$17, "___");
														ZEPHIR_INIT_NVAR(&_57$$17);
														ZVAL_STRING(&_57$$17, "[^/]+");
														ZEPHIR_CALL_FUNCTION(&_58$$17, "sprintf", &_38, 3, &formatStr, &_55$$17, &_56$$17, &routeName, &_57$$17);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_58$$17);
													} else {
														ZVAL_LONG(&_59$$18, 1);
														ZVAL_LONG(&_60$$18, (zephir_get_numberval(&regexPos) - 1));
														ZEPHIR_INIT_NVAR(&_61$$18);
														zephir_substr(&_61$$18, &re$$9, 1 , zephir_get_intval(&_60$$18), 0);
														ZVAL_LONG(&_62$$18, (zephir_get_numberval(&regexPos) + 1));
														ZVAL_LONG(&_63$$18, -2);
														ZEPHIR_INIT_NVAR(&_64$$18);
														zephir_substr(&_64$$18, &re$$9, zephir_get_intval(&_62$$18), -2 , 0);
														ZEPHIR_INIT_NVAR(&_65$$18);
														ZVAL_STRING(&_65$$18, "___");
														ZEPHIR_CALL_FUNCTION(&_66$$18, "sprintf", &_38, 3, &formatStr, &_61$$18, &_65$$18, &routeName, &_64$$18);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_66$$18);
													}
												} else {
													ZEPHIR_INIT_NVAR(&_67$$19);
													ZEPHIR_CONCAT_SV(&_67$$19, "/", &re$$9);
													zephir_concat_self(&regexKey, &_67$$19);
												}
											ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&re$$9);
									ZVAL_LONG(&_68$$9, -1);
									ZVAL_LONG(&_69$$9, 1);
									ZEPHIR_INIT_NVAR(&_70$$9);
									zephir_substr(&_70$$9, &regexKey, -1 , 1 , 0);
									ZEPHIR_INIT_NVAR(&_71$$9);
									ZVAL_STRING(&_71$$9, ")");
									if (!ZEPHIR_IS_EQUAL(&_71$$9, &_70$$9)) {
										zephir_concat_self_str(&regexKey, SL("\\b"));
									}
									ZEPHIR_INIT_NVAR(&_72$$9);
									ZVAL_STRING(&_72$$9, "^%s$");
									ZEPHIR_CALL_FUNCTION(&_73$$9, "sprintf", &_38, 3, &_72$$9, &regexKey);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&regexKey, &_73$$9);
									ZEPHIR_CALL_METHOD(NULL, &tree$$5, "setregex", &_74, 0, &regexKey);
									zephir_check_call_status();
									break;
								}
								if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
									ZEPHIR_INIT_NVAR(&newNode$$21);
									object_init_ex(&newNode$$21, moon_component_router_node_ce);
									ZEPHIR_CALL_METHOD(NULL, &newNode$$21, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
									zephir_check_call_status();
									zephir_read_property(&_76$$21, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
									if (zephir_array_isset(&_76$$21, &item)) {
										zephir_read_property(&_77$$22, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										zephir_array_fetch(&_78$$22, &_77$$22, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 351);
										ZEPHIR_CALL_METHOD(NULL, &_78$$22, "setnode", NULL, 0, &newNode$$21);
										zephir_check_call_status();
									} else {
										ZEPHIR_INIT_NVAR(&newTree$$23);
										object_init_ex(&newTree$$23, moon_component_router_treenode_ce);
										if (zephir_has_constructor(&newTree$$23)) {
											ZEPHIR_CALL_METHOD(NULL, &newTree$$23, "__construct", &_79, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(NULL, &newTree$$23, "setnode", &_80, 158, &newNode$$21);
										zephir_check_call_status();
										zephir_update_property_array(&tree$$5, SL("children"), &item, &newTree$$23);
									}
								} else {
									zephir_read_property(&_81$$24, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
									if (!(zephir_array_isset(&_81$$24, &item))) {
										ZEPHIR_INIT_NVAR(&_82$$25);
										object_init_ex(&_82$$25, moon_component_router_treenode_ce);
										if (zephir_has_constructor(&_82$$25)) {
											ZEPHIR_CALL_METHOD(NULL, &_82$$25, "__construct", NULL, 0);
											zephir_check_call_status();
										}
										zephir_update_property_array(&tree$$5, SL("children"), &item, &_82$$25);
									}
									zephir_read_property(&_83$$24, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch(&_84$$24, &_83$$24, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 365);
									ZEPHIR_CPY_WRT(&tree$$5, &_84$$24);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_17$$7, &uriArr, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_17$$7)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&i, &uriArr, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
								zephir_check_call_status();
									ZVAL_LONG(&_85$$26, 0);
									ZVAL_LONG(&_86$$26, 1);
									ZEPHIR_INIT_NVAR(&_87$$26);
									zephir_substr(&_87$$26, &item, 0 , 1 , 0);
									ZEPHIR_INIT_NVAR(&_88$$26);
									ZVAL_STRING(&_88$$26, "{");
									if (ZEPHIR_IS_EQUAL(&_88$$26, &_87$$26)) {
										ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&regexKey);
										ZVAL_STRING(&regexKey, "");
										zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 326);
										if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _89$$27)
											{
												ZEPHIR_INIT_NVAR(&re$$27);
												ZVAL_COPY(&re$$27, _89$$27);
												ZVAL_LONG(&_91$$28, 0);
												ZVAL_LONG(&_92$$28, 1);
												ZEPHIR_INIT_NVAR(&_93$$28);
												zephir_substr(&_93$$28, &re$$27, 0 , 1 , 0);
												ZEPHIR_INIT_NVAR(&_94$$28);
												ZVAL_STRING(&_94$$28, "{");
												if (ZEPHIR_IS_EQUAL(&_94$$28, &_93$$28)) {
													ZEPHIR_INIT_NVAR(&_95$$29);
													ZVAL_STRING(&_95$$29, "<");
													ZEPHIR_INIT_NVAR(&regexPos);
													zephir_fast_strpos(&regexPos, &re$$27, &_95$$29, 0 );
													ZEPHIR_INIT_NVAR(&formatStr);
													ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
													if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
														ZVAL_LONG(&_96$$30, 1);
														ZVAL_LONG(&_97$$30, -1);
														ZEPHIR_INIT_NVAR(&_98$$30);
														zephir_substr(&_98$$30, &re$$27, 1 , -1 , 0);
														ZEPHIR_INIT_NVAR(&_99$$30);
														ZVAL_STRING(&_99$$30, "___");
														ZEPHIR_INIT_NVAR(&_100$$30);
														ZVAL_STRING(&_100$$30, "[^/]+");
														ZEPHIR_CALL_FUNCTION(&_101$$30, "sprintf", &_38, 3, &formatStr, &_98$$30, &_99$$30, &routeName, &_100$$30);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_101$$30);
													} else {
														ZVAL_LONG(&_102$$31, 1);
														ZVAL_LONG(&_103$$31, (zephir_get_numberval(&regexPos) - 1));
														ZEPHIR_INIT_NVAR(&_104$$31);
														zephir_substr(&_104$$31, &re$$27, 1 , zephir_get_intval(&_103$$31), 0);
														ZVAL_LONG(&_105$$31, (zephir_get_numberval(&regexPos) + 1));
														ZVAL_LONG(&_106$$31, -2);
														ZEPHIR_INIT_NVAR(&_107$$31);
														zephir_substr(&_107$$31, &re$$27, zephir_get_intval(&_105$$31), -2 , 0);
														ZEPHIR_INIT_NVAR(&_108$$31);
														ZVAL_STRING(&_108$$31, "___");
														ZEPHIR_CALL_FUNCTION(&_109$$31, "sprintf", &_38, 3, &formatStr, &_104$$31, &_108$$31, &routeName, &_107$$31);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_109$$31);
													}
												} else {
													ZEPHIR_INIT_NVAR(&_110$$32);
													ZEPHIR_CONCAT_SV(&_110$$32, "/", &re$$27);
													zephir_concat_self(&regexKey, &_110$$32);
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_90$$27, &regexArr, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_90$$27)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&re$$27, &regexArr, "current", NULL, 0);
												zephir_check_call_status();
													ZVAL_LONG(&_111$$33, 0);
													ZVAL_LONG(&_112$$33, 1);
													ZEPHIR_INIT_NVAR(&_113$$33);
													zephir_substr(&_113$$33, &re$$27, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_114$$33);
													ZVAL_STRING(&_114$$33, "{");
													if (ZEPHIR_IS_EQUAL(&_114$$33, &_113$$33)) {
														ZEPHIR_INIT_NVAR(&_115$$34);
														ZVAL_STRING(&_115$$34, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$27, &_115$$34, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_116$$35, 1);
															ZVAL_LONG(&_117$$35, -1);
															ZEPHIR_INIT_NVAR(&_118$$35);
															zephir_substr(&_118$$35, &re$$27, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_119$$35);
															ZVAL_STRING(&_119$$35, "___");
															ZEPHIR_INIT_NVAR(&_120$$35);
															ZVAL_STRING(&_120$$35, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_121$$35, "sprintf", &_38, 3, &formatStr, &_118$$35, &_119$$35, &routeName, &_120$$35);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_121$$35);
														} else {
															ZVAL_LONG(&_122$$36, 1);
															ZVAL_LONG(&_123$$36, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_124$$36);
															zephir_substr(&_124$$36, &re$$27, 1 , zephir_get_intval(&_123$$36), 0);
															ZVAL_LONG(&_125$$36, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_126$$36, -2);
															ZEPHIR_INIT_NVAR(&_127$$36);
															zephir_substr(&_127$$36, &re$$27, zephir_get_intval(&_125$$36), -2 , 0);
															ZEPHIR_INIT_NVAR(&_128$$36);
															ZVAL_STRING(&_128$$36, "___");
															ZEPHIR_CALL_FUNCTION(&_129$$36, "sprintf", &_38, 3, &formatStr, &_124$$36, &_128$$36, &routeName, &_127$$36);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_129$$36);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_130$$37);
														ZEPHIR_CONCAT_SV(&_130$$37, "/", &re$$27);
														zephir_concat_self(&regexKey, &_130$$37);
													}
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&re$$27);
										ZVAL_LONG(&_131$$27, -1);
										ZVAL_LONG(&_132$$27, 1);
										ZEPHIR_INIT_NVAR(&_133$$27);
										zephir_substr(&_133$$27, &regexKey, -1 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_134$$27);
										ZVAL_STRING(&_134$$27, ")");
										if (!ZEPHIR_IS_EQUAL(&_134$$27, &_133$$27)) {
											zephir_concat_self_str(&regexKey, SL("\\b"));
										}
										ZEPHIR_INIT_NVAR(&_135$$27);
										ZVAL_STRING(&_135$$27, "^%s$");
										ZEPHIR_CALL_FUNCTION(&_136$$27, "sprintf", &_38, 3, &_135$$27, &regexKey);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&regexKey, &_136$$27);
										ZEPHIR_CALL_METHOD(NULL, &tree$$5, "setregex", &_137, 0, &regexKey);
										zephir_check_call_status();
										break;
									}
									if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
										ZEPHIR_INIT_NVAR(&newNode$$39);
										object_init_ex(&newNode$$39, moon_component_router_node_ce);
										ZEPHIR_CALL_METHOD(NULL, &newNode$$39, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
										zephir_check_call_status();
										zephir_read_property(&_138$$39, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										if (zephir_array_isset(&_138$$39, &item)) {
											zephir_read_property(&_139$$40, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											zephir_array_fetch(&_140$$40, &_139$$40, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 351);
											ZEPHIR_CALL_METHOD(NULL, &_140$$40, "setnode", NULL, 0, &newNode$$39);
											zephir_check_call_status();
										} else {
											ZEPHIR_INIT_NVAR(&newTree$$41);
											object_init_ex(&newTree$$41, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&newTree$$41)) {
												ZEPHIR_CALL_METHOD(NULL, &newTree$$41, "__construct", &_141, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, &newTree$$41, "setnode", &_80, 158, &newNode$$39);
											zephir_check_call_status();
											zephir_update_property_array(&tree$$5, SL("children"), &item, &newTree$$41);
										}
									} else {
										zephir_read_property(&_142$$42, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										if (!(zephir_array_isset(&_142$$42, &item))) {
											ZEPHIR_INIT_NVAR(&_143$$43);
											object_init_ex(&_143$$43, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&_143$$43)) {
												ZEPHIR_CALL_METHOD(NULL, &_143$$43, "__construct", NULL, 0);
												zephir_check_call_status();
											}
											zephir_update_property_array(&tree$$5, SL("children"), &item, &_143$$43);
										}
										zephir_read_property(&_144$$42, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										zephir_array_fetch(&_145$$42, &_144$$42, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 365);
										ZEPHIR_CPY_WRT(&tree$$5, &_145$$42);
									}
								ZEPHIR_CALL_METHOD(NULL, &uriArr, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&item);
						ZEPHIR_INIT_NVAR(&i);
					} else {
						ZEPHIR_INIT_NVAR(&uri);
						ZVAL_STRING(&uri, "/");
						ZEPHIR_INIT_NVAR(&_146$$44);
						object_init_ex(&_146$$44, moon_component_router_node_ce);
						ZEPHIR_CALL_METHOD(NULL, &_146$$44, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &tree$$5, "setnode", &_147, 0, &_146$$44);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(&_148$$5);
					zephir_create_array(&_148$$5, 5, 0);
					zephir_array_update_string(&_148$$5, SL("method"), &method$$4, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_148$$5, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_148$$5, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_148$$5, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_148$$5, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_149$$5);
					ZVAL_STRING(&_149$$5, "%s_%s");
					ZEPHIR_CALL_FUNCTION(&_150$$5, "sprintf", &_38, 3, &_149$$5, &method$$4, &routeName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("routes"), &_150$$5, &_148$$5);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_7$$4, &methods, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_7$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&method$$4, &methods, "current", NULL, 0);
					zephir_check_call_status();
						zephir_read_property(&_151$$45, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
						if (!(zephir_array_isset(&_151$$45, &method$$4))) {
							ZEPHIR_INIT_NVAR(&_152$$46);
							object_init_ex(&_152$$46, moon_component_router_treenode_ce);
							if (zephir_has_constructor(&_152$$46)) {
								ZEPHIR_CALL_METHOD(NULL, &_152$$46, "__construct", NULL, 0);
								zephir_check_call_status();
							}
							zephir_update_property_array(this_ptr, SL("nodes"), &method$$4, &_152$$46);
						}
						ZEPHIR_CALL_METHOD(&_153$$45, this_ptr, "generateroutename", &_11, 156, &routeName, &method$$4, &uri);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&routeName, &_153$$45);
						zephir_read_property(&_154$$45, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&tree$$45);
						zephir_array_fetch(&tree$$45, &_154$$45, &method$$4, PH_NOISY, "moon/Component/Router/Router.zep", 295);
						ZEPHIR_INIT_NVAR(&_155$$45);
						zephir_fast_explode_str(&_155$$45, SL("/"), &uri, LONG_MAX);
						ZEPHIR_CALL_FUNCTION(&_153$$45, "array_filter", &_14, 95, &_155$$45);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_15, 75, &_153$$45);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&length);
						ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
						if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
							zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 368);
							if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uriArr), _158$$47, _159$$47, _156$$47)
								{
									ZEPHIR_INIT_NVAR(&i);
									if (_159$$47 != NULL) { 
										ZVAL_STR_COPY(&i, _159$$47);
									} else {
										ZVAL_LONG(&i, _158$$47);
									}
									ZEPHIR_INIT_NVAR(&item);
									ZVAL_COPY(&item, _156$$47);
									ZVAL_LONG(&_160$$48, 0);
									ZVAL_LONG(&_161$$48, 1);
									ZEPHIR_INIT_NVAR(&_162$$48);
									zephir_substr(&_162$$48, &item, 0 , 1 , 0);
									ZEPHIR_INIT_NVAR(&_163$$48);
									ZVAL_STRING(&_163$$48, "{");
									if (ZEPHIR_IS_EQUAL(&_163$$48, &_162$$48)) {
										ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&regexKey);
										ZVAL_STRING(&regexKey, "");
										zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 326);
										if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _164$$49)
											{
												ZEPHIR_INIT_NVAR(&re$$49);
												ZVAL_COPY(&re$$49, _164$$49);
												ZVAL_LONG(&_166$$50, 0);
												ZVAL_LONG(&_167$$50, 1);
												ZEPHIR_INIT_NVAR(&_168$$50);
												zephir_substr(&_168$$50, &re$$49, 0 , 1 , 0);
												ZEPHIR_INIT_NVAR(&_169$$50);
												ZVAL_STRING(&_169$$50, "{");
												if (ZEPHIR_IS_EQUAL(&_169$$50, &_168$$50)) {
													ZEPHIR_INIT_NVAR(&_170$$51);
													ZVAL_STRING(&_170$$51, "<");
													ZEPHIR_INIT_NVAR(&regexPos);
													zephir_fast_strpos(&regexPos, &re$$49, &_170$$51, 0 );
													ZEPHIR_INIT_NVAR(&formatStr);
													ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
													if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
														ZVAL_LONG(&_171$$52, 1);
														ZVAL_LONG(&_172$$52, -1);
														ZEPHIR_INIT_NVAR(&_173$$52);
														zephir_substr(&_173$$52, &re$$49, 1 , -1 , 0);
														ZEPHIR_INIT_NVAR(&_174$$52);
														ZVAL_STRING(&_174$$52, "___");
														ZEPHIR_INIT_NVAR(&_175$$52);
														ZVAL_STRING(&_175$$52, "[^/]+");
														ZEPHIR_CALL_FUNCTION(&_176$$52, "sprintf", &_38, 3, &formatStr, &_173$$52, &_174$$52, &routeName, &_175$$52);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_176$$52);
													} else {
														ZVAL_LONG(&_177$$53, 1);
														ZVAL_LONG(&_178$$53, (zephir_get_numberval(&regexPos) - 1));
														ZEPHIR_INIT_NVAR(&_179$$53);
														zephir_substr(&_179$$53, &re$$49, 1 , zephir_get_intval(&_178$$53), 0);
														ZVAL_LONG(&_180$$53, (zephir_get_numberval(&regexPos) + 1));
														ZVAL_LONG(&_181$$53, -2);
														ZEPHIR_INIT_NVAR(&_182$$53);
														zephir_substr(&_182$$53, &re$$49, zephir_get_intval(&_180$$53), -2 , 0);
														ZEPHIR_INIT_NVAR(&_183$$53);
														ZVAL_STRING(&_183$$53, "___");
														ZEPHIR_CALL_FUNCTION(&_184$$53, "sprintf", &_38, 3, &formatStr, &_179$$53, &_183$$53, &routeName, &_182$$53);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_184$$53);
													}
												} else {
													ZEPHIR_INIT_NVAR(&_185$$54);
													ZEPHIR_CONCAT_SV(&_185$$54, "/", &re$$49);
													zephir_concat_self(&regexKey, &_185$$54);
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_165$$49, &regexArr, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_165$$49)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&re$$49, &regexArr, "current", NULL, 0);
												zephir_check_call_status();
													ZVAL_LONG(&_186$$55, 0);
													ZVAL_LONG(&_187$$55, 1);
													ZEPHIR_INIT_NVAR(&_188$$55);
													zephir_substr(&_188$$55, &re$$49, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_189$$55);
													ZVAL_STRING(&_189$$55, "{");
													if (ZEPHIR_IS_EQUAL(&_189$$55, &_188$$55)) {
														ZEPHIR_INIT_NVAR(&_190$$56);
														ZVAL_STRING(&_190$$56, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$49, &_190$$56, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_191$$57, 1);
															ZVAL_LONG(&_192$$57, -1);
															ZEPHIR_INIT_NVAR(&_193$$57);
															zephir_substr(&_193$$57, &re$$49, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_194$$57);
															ZVAL_STRING(&_194$$57, "___");
															ZEPHIR_INIT_NVAR(&_195$$57);
															ZVAL_STRING(&_195$$57, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_196$$57, "sprintf", &_38, 3, &formatStr, &_193$$57, &_194$$57, &routeName, &_195$$57);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_196$$57);
														} else {
															ZVAL_LONG(&_197$$58, 1);
															ZVAL_LONG(&_198$$58, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_199$$58);
															zephir_substr(&_199$$58, &re$$49, 1 , zephir_get_intval(&_198$$58), 0);
															ZVAL_LONG(&_200$$58, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_201$$58, -2);
															ZEPHIR_INIT_NVAR(&_202$$58);
															zephir_substr(&_202$$58, &re$$49, zephir_get_intval(&_200$$58), -2 , 0);
															ZEPHIR_INIT_NVAR(&_203$$58);
															ZVAL_STRING(&_203$$58, "___");
															ZEPHIR_CALL_FUNCTION(&_204$$58, "sprintf", &_38, 3, &formatStr, &_199$$58, &_203$$58, &routeName, &_202$$58);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_204$$58);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_205$$59);
														ZEPHIR_CONCAT_SV(&_205$$59, "/", &re$$49);
														zephir_concat_self(&regexKey, &_205$$59);
													}
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&re$$49);
										ZVAL_LONG(&_206$$49, -1);
										ZVAL_LONG(&_207$$49, 1);
										ZEPHIR_INIT_NVAR(&_208$$49);
										zephir_substr(&_208$$49, &regexKey, -1 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_209$$49);
										ZVAL_STRING(&_209$$49, ")");
										if (!ZEPHIR_IS_EQUAL(&_209$$49, &_208$$49)) {
											zephir_concat_self_str(&regexKey, SL("\\b"));
										}
										ZEPHIR_INIT_NVAR(&_210$$49);
										ZVAL_STRING(&_210$$49, "^%s$");
										ZEPHIR_CALL_FUNCTION(&_211$$49, "sprintf", &_38, 3, &_210$$49, &regexKey);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&regexKey, &_211$$49);
										ZEPHIR_CALL_METHOD(NULL, &tree$$45, "setregex", &_212, 0, &regexKey);
										zephir_check_call_status();
										break;
									}
									if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
										ZEPHIR_INIT_NVAR(&newNode$$61);
										object_init_ex(&newNode$$61, moon_component_router_node_ce);
										ZEPHIR_CALL_METHOD(NULL, &newNode$$61, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
										zephir_check_call_status();
										zephir_read_property(&_213$$61, &tree$$45, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										if (zephir_array_isset(&_213$$61, &item)) {
											zephir_read_property(&_214$$62, &tree$$45, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											zephir_array_fetch(&_215$$62, &_214$$62, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 351);
											ZEPHIR_CALL_METHOD(NULL, &_215$$62, "setnode", NULL, 0, &newNode$$61);
											zephir_check_call_status();
										} else {
											ZEPHIR_INIT_NVAR(&newTree$$63);
											object_init_ex(&newTree$$63, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&newTree$$63)) {
												ZEPHIR_CALL_METHOD(NULL, &newTree$$63, "__construct", &_216, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, &newTree$$63, "setnode", &_80, 158, &newNode$$61);
											zephir_check_call_status();
											zephir_update_property_array(&tree$$45, SL("children"), &item, &newTree$$63);
										}
									} else {
										zephir_read_property(&_217$$64, &tree$$45, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										if (!(zephir_array_isset(&_217$$64, &item))) {
											ZEPHIR_INIT_NVAR(&_218$$65);
											object_init_ex(&_218$$65, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&_218$$65)) {
												ZEPHIR_CALL_METHOD(NULL, &_218$$65, "__construct", NULL, 0);
												zephir_check_call_status();
											}
											zephir_update_property_array(&tree$$45, SL("children"), &item, &_218$$65);
										}
										zephir_read_property(&_219$$64, &tree$$45, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										zephir_array_fetch(&_220$$64, &_219$$64, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 365);
										ZEPHIR_CPY_WRT(&tree$$45, &_220$$64);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_157$$47, &uriArr, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_157$$47)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&i, &uriArr, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
									zephir_check_call_status();
										ZVAL_LONG(&_221$$66, 0);
										ZVAL_LONG(&_222$$66, 1);
										ZEPHIR_INIT_NVAR(&_223$$66);
										zephir_substr(&_223$$66, &item, 0 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_224$$66);
										ZVAL_STRING(&_224$$66, "{");
										if (ZEPHIR_IS_EQUAL(&_224$$66, &_223$$66)) {
											ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&regexKey);
											ZVAL_STRING(&regexKey, "");
											zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 326);
											if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _225$$67)
												{
													ZEPHIR_INIT_NVAR(&re$$67);
													ZVAL_COPY(&re$$67, _225$$67);
													ZVAL_LONG(&_227$$68, 0);
													ZVAL_LONG(&_228$$68, 1);
													ZEPHIR_INIT_NVAR(&_229$$68);
													zephir_substr(&_229$$68, &re$$67, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_230$$68);
													ZVAL_STRING(&_230$$68, "{");
													if (ZEPHIR_IS_EQUAL(&_230$$68, &_229$$68)) {
														ZEPHIR_INIT_NVAR(&_231$$69);
														ZVAL_STRING(&_231$$69, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$67, &_231$$69, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_232$$70, 1);
															ZVAL_LONG(&_233$$70, -1);
															ZEPHIR_INIT_NVAR(&_234$$70);
															zephir_substr(&_234$$70, &re$$67, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_235$$70);
															ZVAL_STRING(&_235$$70, "___");
															ZEPHIR_INIT_NVAR(&_236$$70);
															ZVAL_STRING(&_236$$70, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_237$$70, "sprintf", &_38, 3, &formatStr, &_234$$70, &_235$$70, &routeName, &_236$$70);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_237$$70);
														} else {
															ZVAL_LONG(&_238$$71, 1);
															ZVAL_LONG(&_239$$71, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_240$$71);
															zephir_substr(&_240$$71, &re$$67, 1 , zephir_get_intval(&_239$$71), 0);
															ZVAL_LONG(&_241$$71, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_242$$71, -2);
															ZEPHIR_INIT_NVAR(&_243$$71);
															zephir_substr(&_243$$71, &re$$67, zephir_get_intval(&_241$$71), -2 , 0);
															ZEPHIR_INIT_NVAR(&_244$$71);
															ZVAL_STRING(&_244$$71, "___");
															ZEPHIR_CALL_FUNCTION(&_245$$71, "sprintf", &_38, 3, &formatStr, &_240$$71, &_244$$71, &routeName, &_243$$71);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_245$$71);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_246$$72);
														ZEPHIR_CONCAT_SV(&_246$$72, "/", &re$$67);
														zephir_concat_self(&regexKey, &_246$$72);
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_226$$67, &regexArr, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_226$$67)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&re$$67, &regexArr, "current", NULL, 0);
													zephir_check_call_status();
														ZVAL_LONG(&_247$$73, 0);
														ZVAL_LONG(&_248$$73, 1);
														ZEPHIR_INIT_NVAR(&_249$$73);
														zephir_substr(&_249$$73, &re$$67, 0 , 1 , 0);
														ZEPHIR_INIT_NVAR(&_250$$73);
														ZVAL_STRING(&_250$$73, "{");
														if (ZEPHIR_IS_EQUAL(&_250$$73, &_249$$73)) {
															ZEPHIR_INIT_NVAR(&_251$$74);
															ZVAL_STRING(&_251$$74, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$67, &_251$$74, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_252$$75, 1);
																ZVAL_LONG(&_253$$75, -1);
																ZEPHIR_INIT_NVAR(&_254$$75);
																zephir_substr(&_254$$75, &re$$67, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_255$$75);
																ZVAL_STRING(&_255$$75, "___");
																ZEPHIR_INIT_NVAR(&_256$$75);
																ZVAL_STRING(&_256$$75, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_257$$75, "sprintf", &_38, 3, &formatStr, &_254$$75, &_255$$75, &routeName, &_256$$75);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_257$$75);
															} else {
																ZVAL_LONG(&_258$$76, 1);
																ZVAL_LONG(&_259$$76, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_260$$76);
																zephir_substr(&_260$$76, &re$$67, 1 , zephir_get_intval(&_259$$76), 0);
																ZVAL_LONG(&_261$$76, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_262$$76, -2);
																ZEPHIR_INIT_NVAR(&_263$$76);
																zephir_substr(&_263$$76, &re$$67, zephir_get_intval(&_261$$76), -2 , 0);
																ZEPHIR_INIT_NVAR(&_264$$76);
																ZVAL_STRING(&_264$$76, "___");
																ZEPHIR_CALL_FUNCTION(&_265$$76, "sprintf", &_38, 3, &formatStr, &_260$$76, &_264$$76, &routeName, &_263$$76);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_265$$76);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_266$$77);
															ZEPHIR_CONCAT_SV(&_266$$77, "/", &re$$67);
															zephir_concat_self(&regexKey, &_266$$77);
														}
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&re$$67);
											ZVAL_LONG(&_267$$67, -1);
											ZVAL_LONG(&_268$$67, 1);
											ZEPHIR_INIT_NVAR(&_269$$67);
											zephir_substr(&_269$$67, &regexKey, -1 , 1 , 0);
											ZEPHIR_INIT_NVAR(&_270$$67);
											ZVAL_STRING(&_270$$67, ")");
											if (!ZEPHIR_IS_EQUAL(&_270$$67, &_269$$67)) {
												zephir_concat_self_str(&regexKey, SL("\\b"));
											}
											ZEPHIR_INIT_NVAR(&_271$$67);
											ZVAL_STRING(&_271$$67, "^%s$");
											ZEPHIR_CALL_FUNCTION(&_272$$67, "sprintf", &_38, 3, &_271$$67, &regexKey);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&regexKey, &_272$$67);
											ZEPHIR_CALL_METHOD(NULL, &tree$$45, "setregex", &_273, 0, &regexKey);
											zephir_check_call_status();
											break;
										}
										if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
											ZEPHIR_INIT_NVAR(&newNode$$79);
											object_init_ex(&newNode$$79, moon_component_router_node_ce);
											ZEPHIR_CALL_METHOD(NULL, &newNode$$79, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
											zephir_check_call_status();
											zephir_read_property(&_274$$79, &tree$$45, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											if (zephir_array_isset(&_274$$79, &item)) {
												zephir_read_property(&_275$$80, &tree$$45, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
												zephir_array_fetch(&_276$$80, &_275$$80, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 351);
												ZEPHIR_CALL_METHOD(NULL, &_276$$80, "setnode", NULL, 0, &newNode$$79);
												zephir_check_call_status();
											} else {
												ZEPHIR_INIT_NVAR(&newTree$$81);
												object_init_ex(&newTree$$81, moon_component_router_treenode_ce);
												if (zephir_has_constructor(&newTree$$81)) {
													ZEPHIR_CALL_METHOD(NULL, &newTree$$81, "__construct", &_277, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(NULL, &newTree$$81, "setnode", &_80, 158, &newNode$$79);
												zephir_check_call_status();
												zephir_update_property_array(&tree$$45, SL("children"), &item, &newTree$$81);
											}
										} else {
											zephir_read_property(&_278$$82, &tree$$45, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											if (!(zephir_array_isset(&_278$$82, &item))) {
												ZEPHIR_INIT_NVAR(&_279$$83);
												object_init_ex(&_279$$83, moon_component_router_treenode_ce);
												if (zephir_has_constructor(&_279$$83)) {
													ZEPHIR_CALL_METHOD(NULL, &_279$$83, "__construct", NULL, 0);
													zephir_check_call_status();
												}
												zephir_update_property_array(&tree$$45, SL("children"), &item, &_279$$83);
											}
											zephir_read_property(&_280$$82, &tree$$45, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											zephir_array_fetch(&_281$$82, &_280$$82, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 365);
											ZEPHIR_CPY_WRT(&tree$$45, &_281$$82);
										}
									ZEPHIR_CALL_METHOD(NULL, &uriArr, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&item);
							ZEPHIR_INIT_NVAR(&i);
						} else {
							ZEPHIR_INIT_NVAR(&uri);
							ZVAL_STRING(&uri, "/");
							ZEPHIR_INIT_NVAR(&_282$$84);
							object_init_ex(&_282$$84, moon_component_router_node_ce);
							ZEPHIR_CALL_METHOD(NULL, &_282$$84, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &tree$$45, "setnode", &_283, 0, &_282$$84);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_284$$45);
						zephir_create_array(&_284$$45, 5, 0);
						zephir_array_update_string(&_284$$45, SL("method"), &method$$4, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_284$$45, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_284$$45, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_284$$45, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_284$$45, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_285$$45);
						ZVAL_STRING(&_285$$45, "%s_%s");
						ZEPHIR_CALL_FUNCTION(&_286$$45, "sprintf", &_38, 3, &_285$$45, &method$$4, &routeName);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("routes"), &_286$$45, &_284$$45);
					ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&method$$4);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&router, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&methods);
				zephir_array_fetch_string(&methods, &router, SL("methods"), PH_NOISY, "moon/Component/Router/Router.zep", 275);
				ZEPHIR_OBS_NVAR(&uri);
				zephir_array_fetch_string(&uri, &router, SL("uri"), PH_NOISY, "moon/Component/Router/Router.zep", 276);
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_string(&handler, &router, SL("handler"), PH_NOISY, "moon/Component/Router/Router.zep", 277);
				ZEPHIR_OBS_NVAR(&routeName);
				zephir_array_fetch_string(&routeName, &router, SL("routeName"), PH_NOISY, "moon/Component/Router/Router.zep", 278);
				ZEPHIR_OBS_NVAR(&priority);
				zephir_array_fetch_string(&priority, &router, SL("priority"), PH_NOISY, "moon/Component/Router/Router.zep", 279);
				zephir_is_iterable(&methods, 0, "moon/Component/Router/Router.zep", 380);
				if (Z_TYPE_P(&methods) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _287$$85)
					{
						ZEPHIR_INIT_NVAR(&method$$85);
						ZVAL_COPY(&method$$85, _287$$85);
						zephir_read_property(&_289$$86, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
						if (!(zephir_array_isset(&_289$$86, &method$$85))) {
							ZEPHIR_INIT_NVAR(&_290$$87);
							object_init_ex(&_290$$87, moon_component_router_treenode_ce);
							if (zephir_has_constructor(&_290$$87)) {
								ZEPHIR_CALL_METHOD(NULL, &_290$$87, "__construct", NULL, 0);
								zephir_check_call_status();
							}
							zephir_update_property_array(this_ptr, SL("nodes"), &method$$85, &_290$$87);
						}
						ZEPHIR_CALL_METHOD(&_291$$86, this_ptr, "generateroutename", &_11, 156, &routeName, &method$$85, &uri);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&routeName, &_291$$86);
						zephir_read_property(&_292$$86, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&tree$$86);
						zephir_array_fetch(&tree$$86, &_292$$86, &method$$85, PH_NOISY, "moon/Component/Router/Router.zep", 295);
						ZEPHIR_INIT_NVAR(&_293$$86);
						zephir_fast_explode_str(&_293$$86, SL("/"), &uri, LONG_MAX);
						ZEPHIR_CALL_FUNCTION(&_291$$86, "array_filter", &_14, 95, &_293$$86);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_15, 75, &_291$$86);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&length);
						ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
						if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
							zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 368);
							if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uriArr), _296$$88, _297$$88, _294$$88)
								{
									ZEPHIR_INIT_NVAR(&i);
									if (_297$$88 != NULL) { 
										ZVAL_STR_COPY(&i, _297$$88);
									} else {
										ZVAL_LONG(&i, _296$$88);
									}
									ZEPHIR_INIT_NVAR(&item);
									ZVAL_COPY(&item, _294$$88);
									ZVAL_LONG(&_298$$89, 0);
									ZVAL_LONG(&_299$$89, 1);
									ZEPHIR_INIT_NVAR(&_300$$89);
									zephir_substr(&_300$$89, &item, 0 , 1 , 0);
									ZEPHIR_INIT_NVAR(&_301$$89);
									ZVAL_STRING(&_301$$89, "{");
									if (ZEPHIR_IS_EQUAL(&_301$$89, &_300$$89)) {
										ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&regexKey);
										ZVAL_STRING(&regexKey, "");
										zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 326);
										if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _302$$90)
											{
												ZEPHIR_INIT_NVAR(&re$$90);
												ZVAL_COPY(&re$$90, _302$$90);
												ZVAL_LONG(&_304$$91, 0);
												ZVAL_LONG(&_305$$91, 1);
												ZEPHIR_INIT_NVAR(&_306$$91);
												zephir_substr(&_306$$91, &re$$90, 0 , 1 , 0);
												ZEPHIR_INIT_NVAR(&_307$$91);
												ZVAL_STRING(&_307$$91, "{");
												if (ZEPHIR_IS_EQUAL(&_307$$91, &_306$$91)) {
													ZEPHIR_INIT_NVAR(&_308$$92);
													ZVAL_STRING(&_308$$92, "<");
													ZEPHIR_INIT_NVAR(&regexPos);
													zephir_fast_strpos(&regexPos, &re$$90, &_308$$92, 0 );
													ZEPHIR_INIT_NVAR(&formatStr);
													ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
													if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
														ZVAL_LONG(&_309$$93, 1);
														ZVAL_LONG(&_310$$93, -1);
														ZEPHIR_INIT_NVAR(&_311$$93);
														zephir_substr(&_311$$93, &re$$90, 1 , -1 , 0);
														ZEPHIR_INIT_NVAR(&_312$$93);
														ZVAL_STRING(&_312$$93, "___");
														ZEPHIR_INIT_NVAR(&_313$$93);
														ZVAL_STRING(&_313$$93, "[^/]+");
														ZEPHIR_CALL_FUNCTION(&_314$$93, "sprintf", &_38, 3, &formatStr, &_311$$93, &_312$$93, &routeName, &_313$$93);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_314$$93);
													} else {
														ZVAL_LONG(&_315$$94, 1);
														ZVAL_LONG(&_316$$94, (zephir_get_numberval(&regexPos) - 1));
														ZEPHIR_INIT_NVAR(&_317$$94);
														zephir_substr(&_317$$94, &re$$90, 1 , zephir_get_intval(&_316$$94), 0);
														ZVAL_LONG(&_318$$94, (zephir_get_numberval(&regexPos) + 1));
														ZVAL_LONG(&_319$$94, -2);
														ZEPHIR_INIT_NVAR(&_320$$94);
														zephir_substr(&_320$$94, &re$$90, zephir_get_intval(&_318$$94), -2 , 0);
														ZEPHIR_INIT_NVAR(&_321$$94);
														ZVAL_STRING(&_321$$94, "___");
														ZEPHIR_CALL_FUNCTION(&_322$$94, "sprintf", &_38, 3, &formatStr, &_317$$94, &_321$$94, &routeName, &_320$$94);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_322$$94);
													}
												} else {
													ZEPHIR_INIT_NVAR(&_323$$95);
													ZEPHIR_CONCAT_SV(&_323$$95, "/", &re$$90);
													zephir_concat_self(&regexKey, &_323$$95);
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_303$$90, &regexArr, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_303$$90)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&re$$90, &regexArr, "current", NULL, 0);
												zephir_check_call_status();
													ZVAL_LONG(&_324$$96, 0);
													ZVAL_LONG(&_325$$96, 1);
													ZEPHIR_INIT_NVAR(&_326$$96);
													zephir_substr(&_326$$96, &re$$90, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_327$$96);
													ZVAL_STRING(&_327$$96, "{");
													if (ZEPHIR_IS_EQUAL(&_327$$96, &_326$$96)) {
														ZEPHIR_INIT_NVAR(&_328$$97);
														ZVAL_STRING(&_328$$97, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$90, &_328$$97, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_329$$98, 1);
															ZVAL_LONG(&_330$$98, -1);
															ZEPHIR_INIT_NVAR(&_331$$98);
															zephir_substr(&_331$$98, &re$$90, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_332$$98);
															ZVAL_STRING(&_332$$98, "___");
															ZEPHIR_INIT_NVAR(&_333$$98);
															ZVAL_STRING(&_333$$98, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_334$$98, "sprintf", &_38, 3, &formatStr, &_331$$98, &_332$$98, &routeName, &_333$$98);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_334$$98);
														} else {
															ZVAL_LONG(&_335$$99, 1);
															ZVAL_LONG(&_336$$99, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_337$$99);
															zephir_substr(&_337$$99, &re$$90, 1 , zephir_get_intval(&_336$$99), 0);
															ZVAL_LONG(&_338$$99, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_339$$99, -2);
															ZEPHIR_INIT_NVAR(&_340$$99);
															zephir_substr(&_340$$99, &re$$90, zephir_get_intval(&_338$$99), -2 , 0);
															ZEPHIR_INIT_NVAR(&_341$$99);
															ZVAL_STRING(&_341$$99, "___");
															ZEPHIR_CALL_FUNCTION(&_342$$99, "sprintf", &_38, 3, &formatStr, &_337$$99, &_341$$99, &routeName, &_340$$99);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_342$$99);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_343$$100);
														ZEPHIR_CONCAT_SV(&_343$$100, "/", &re$$90);
														zephir_concat_self(&regexKey, &_343$$100);
													}
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&re$$90);
										ZVAL_LONG(&_344$$90, -1);
										ZVAL_LONG(&_345$$90, 1);
										ZEPHIR_INIT_NVAR(&_346$$90);
										zephir_substr(&_346$$90, &regexKey, -1 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_347$$90);
										ZVAL_STRING(&_347$$90, ")");
										if (!ZEPHIR_IS_EQUAL(&_347$$90, &_346$$90)) {
											zephir_concat_self_str(&regexKey, SL("\\b"));
										}
										ZEPHIR_INIT_NVAR(&_348$$90);
										ZVAL_STRING(&_348$$90, "^%s$");
										ZEPHIR_CALL_FUNCTION(&_349$$90, "sprintf", &_38, 3, &_348$$90, &regexKey);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&regexKey, &_349$$90);
										ZEPHIR_CALL_METHOD(NULL, &tree$$86, "setregex", &_350, 0, &regexKey);
										zephir_check_call_status();
										break;
									}
									if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
										ZEPHIR_INIT_NVAR(&newNode$$102);
										object_init_ex(&newNode$$102, moon_component_router_node_ce);
										ZEPHIR_CALL_METHOD(NULL, &newNode$$102, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
										zephir_check_call_status();
										zephir_read_property(&_351$$102, &tree$$86, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										if (zephir_array_isset(&_351$$102, &item)) {
											zephir_read_property(&_352$$103, &tree$$86, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											zephir_array_fetch(&_353$$103, &_352$$103, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 351);
											ZEPHIR_CALL_METHOD(NULL, &_353$$103, "setnode", NULL, 0, &newNode$$102);
											zephir_check_call_status();
										} else {
											ZEPHIR_INIT_NVAR(&newTree$$104);
											object_init_ex(&newTree$$104, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&newTree$$104)) {
												ZEPHIR_CALL_METHOD(NULL, &newTree$$104, "__construct", &_354, 0);
												zephir_check_call_status();
											}
											ZEPHIR_CALL_METHOD(NULL, &newTree$$104, "setnode", &_80, 158, &newNode$$102);
											zephir_check_call_status();
											zephir_update_property_array(&tree$$86, SL("children"), &item, &newTree$$104);
										}
									} else {
										zephir_read_property(&_355$$105, &tree$$86, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										if (!(zephir_array_isset(&_355$$105, &item))) {
											ZEPHIR_INIT_NVAR(&_356$$106);
											object_init_ex(&_356$$106, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&_356$$106)) {
												ZEPHIR_CALL_METHOD(NULL, &_356$$106, "__construct", NULL, 0);
												zephir_check_call_status();
											}
											zephir_update_property_array(&tree$$86, SL("children"), &item, &_356$$106);
										}
										zephir_read_property(&_357$$105, &tree$$86, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										zephir_array_fetch(&_358$$105, &_357$$105, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 365);
										ZEPHIR_CPY_WRT(&tree$$86, &_358$$105);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_295$$88, &uriArr, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_295$$88)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&i, &uriArr, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
									zephir_check_call_status();
										ZVAL_LONG(&_359$$107, 0);
										ZVAL_LONG(&_360$$107, 1);
										ZEPHIR_INIT_NVAR(&_361$$107);
										zephir_substr(&_361$$107, &item, 0 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_362$$107);
										ZVAL_STRING(&_362$$107, "{");
										if (ZEPHIR_IS_EQUAL(&_362$$107, &_361$$107)) {
											ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&regexKey);
											ZVAL_STRING(&regexKey, "");
											zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 326);
											if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _363$$108)
												{
													ZEPHIR_INIT_NVAR(&re$$108);
													ZVAL_COPY(&re$$108, _363$$108);
													ZVAL_LONG(&_365$$109, 0);
													ZVAL_LONG(&_366$$109, 1);
													ZEPHIR_INIT_NVAR(&_367$$109);
													zephir_substr(&_367$$109, &re$$108, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_368$$109);
													ZVAL_STRING(&_368$$109, "{");
													if (ZEPHIR_IS_EQUAL(&_368$$109, &_367$$109)) {
														ZEPHIR_INIT_NVAR(&_369$$110);
														ZVAL_STRING(&_369$$110, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$108, &_369$$110, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_370$$111, 1);
															ZVAL_LONG(&_371$$111, -1);
															ZEPHIR_INIT_NVAR(&_372$$111);
															zephir_substr(&_372$$111, &re$$108, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_373$$111);
															ZVAL_STRING(&_373$$111, "___");
															ZEPHIR_INIT_NVAR(&_374$$111);
															ZVAL_STRING(&_374$$111, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_375$$111, "sprintf", &_38, 3, &formatStr, &_372$$111, &_373$$111, &routeName, &_374$$111);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_375$$111);
														} else {
															ZVAL_LONG(&_376$$112, 1);
															ZVAL_LONG(&_377$$112, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_378$$112);
															zephir_substr(&_378$$112, &re$$108, 1 , zephir_get_intval(&_377$$112), 0);
															ZVAL_LONG(&_379$$112, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_380$$112, -2);
															ZEPHIR_INIT_NVAR(&_381$$112);
															zephir_substr(&_381$$112, &re$$108, zephir_get_intval(&_379$$112), -2 , 0);
															ZEPHIR_INIT_NVAR(&_382$$112);
															ZVAL_STRING(&_382$$112, "___");
															ZEPHIR_CALL_FUNCTION(&_383$$112, "sprintf", &_38, 3, &formatStr, &_378$$112, &_382$$112, &routeName, &_381$$112);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_383$$112);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_384$$113);
														ZEPHIR_CONCAT_SV(&_384$$113, "/", &re$$108);
														zephir_concat_self(&regexKey, &_384$$113);
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_364$$108, &regexArr, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_364$$108)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&re$$108, &regexArr, "current", NULL, 0);
													zephir_check_call_status();
														ZVAL_LONG(&_385$$114, 0);
														ZVAL_LONG(&_386$$114, 1);
														ZEPHIR_INIT_NVAR(&_387$$114);
														zephir_substr(&_387$$114, &re$$108, 0 , 1 , 0);
														ZEPHIR_INIT_NVAR(&_388$$114);
														ZVAL_STRING(&_388$$114, "{");
														if (ZEPHIR_IS_EQUAL(&_388$$114, &_387$$114)) {
															ZEPHIR_INIT_NVAR(&_389$$115);
															ZVAL_STRING(&_389$$115, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$108, &_389$$115, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_390$$116, 1);
																ZVAL_LONG(&_391$$116, -1);
																ZEPHIR_INIT_NVAR(&_392$$116);
																zephir_substr(&_392$$116, &re$$108, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_393$$116);
																ZVAL_STRING(&_393$$116, "___");
																ZEPHIR_INIT_NVAR(&_394$$116);
																ZVAL_STRING(&_394$$116, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_395$$116, "sprintf", &_38, 3, &formatStr, &_392$$116, &_393$$116, &routeName, &_394$$116);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_395$$116);
															} else {
																ZVAL_LONG(&_396$$117, 1);
																ZVAL_LONG(&_397$$117, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_398$$117);
																zephir_substr(&_398$$117, &re$$108, 1 , zephir_get_intval(&_397$$117), 0);
																ZVAL_LONG(&_399$$117, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_400$$117, -2);
																ZEPHIR_INIT_NVAR(&_401$$117);
																zephir_substr(&_401$$117, &re$$108, zephir_get_intval(&_399$$117), -2 , 0);
																ZEPHIR_INIT_NVAR(&_402$$117);
																ZVAL_STRING(&_402$$117, "___");
																ZEPHIR_CALL_FUNCTION(&_403$$117, "sprintf", &_38, 3, &formatStr, &_398$$117, &_402$$117, &routeName, &_401$$117);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_403$$117);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_404$$118);
															ZEPHIR_CONCAT_SV(&_404$$118, "/", &re$$108);
															zephir_concat_self(&regexKey, &_404$$118);
														}
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&re$$108);
											ZVAL_LONG(&_405$$108, -1);
											ZVAL_LONG(&_406$$108, 1);
											ZEPHIR_INIT_NVAR(&_407$$108);
											zephir_substr(&_407$$108, &regexKey, -1 , 1 , 0);
											ZEPHIR_INIT_NVAR(&_408$$108);
											ZVAL_STRING(&_408$$108, ")");
											if (!ZEPHIR_IS_EQUAL(&_408$$108, &_407$$108)) {
												zephir_concat_self_str(&regexKey, SL("\\b"));
											}
											ZEPHIR_INIT_NVAR(&_409$$108);
											ZVAL_STRING(&_409$$108, "^%s$");
											ZEPHIR_CALL_FUNCTION(&_410$$108, "sprintf", &_38, 3, &_409$$108, &regexKey);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&regexKey, &_410$$108);
											ZEPHIR_CALL_METHOD(NULL, &tree$$86, "setregex", &_411, 0, &regexKey);
											zephir_check_call_status();
											break;
										}
										if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
											ZEPHIR_INIT_NVAR(&newNode$$120);
											object_init_ex(&newNode$$120, moon_component_router_node_ce);
											ZEPHIR_CALL_METHOD(NULL, &newNode$$120, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
											zephir_check_call_status();
											zephir_read_property(&_412$$120, &tree$$86, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											if (zephir_array_isset(&_412$$120, &item)) {
												zephir_read_property(&_413$$121, &tree$$86, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
												zephir_array_fetch(&_414$$121, &_413$$121, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 351);
												ZEPHIR_CALL_METHOD(NULL, &_414$$121, "setnode", NULL, 0, &newNode$$120);
												zephir_check_call_status();
											} else {
												ZEPHIR_INIT_NVAR(&newTree$$122);
												object_init_ex(&newTree$$122, moon_component_router_treenode_ce);
												if (zephir_has_constructor(&newTree$$122)) {
													ZEPHIR_CALL_METHOD(NULL, &newTree$$122, "__construct", &_415, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(NULL, &newTree$$122, "setnode", &_80, 158, &newNode$$120);
												zephir_check_call_status();
												zephir_update_property_array(&tree$$86, SL("children"), &item, &newTree$$122);
											}
										} else {
											zephir_read_property(&_416$$123, &tree$$86, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											if (!(zephir_array_isset(&_416$$123, &item))) {
												ZEPHIR_INIT_NVAR(&_417$$124);
												object_init_ex(&_417$$124, moon_component_router_treenode_ce);
												if (zephir_has_constructor(&_417$$124)) {
													ZEPHIR_CALL_METHOD(NULL, &_417$$124, "__construct", NULL, 0);
													zephir_check_call_status();
												}
												zephir_update_property_array(&tree$$86, SL("children"), &item, &_417$$124);
											}
											zephir_read_property(&_418$$123, &tree$$86, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											zephir_array_fetch(&_419$$123, &_418$$123, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 365);
											ZEPHIR_CPY_WRT(&tree$$86, &_419$$123);
										}
									ZEPHIR_CALL_METHOD(NULL, &uriArr, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&item);
							ZEPHIR_INIT_NVAR(&i);
						} else {
							ZEPHIR_INIT_NVAR(&uri);
							ZVAL_STRING(&uri, "/");
							ZEPHIR_INIT_NVAR(&_420$$125);
							object_init_ex(&_420$$125, moon_component_router_node_ce);
							ZEPHIR_CALL_METHOD(NULL, &_420$$125, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &tree$$86, "setnode", &_421, 0, &_420$$125);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_422$$86);
						zephir_create_array(&_422$$86, 5, 0);
						zephir_array_update_string(&_422$$86, SL("method"), &method$$85, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_422$$86, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_422$$86, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_422$$86, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_422$$86, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_423$$86);
						ZVAL_STRING(&_423$$86, "%s_%s");
						ZEPHIR_CALL_FUNCTION(&_424$$86, "sprintf", &_38, 3, &_423$$86, &method$$85, &routeName);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("routes"), &_424$$86, &_422$$86);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_288$$85, &methods, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_288$$85)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&method$$85, &methods, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property(&_425$$126, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
							if (!(zephir_array_isset(&_425$$126, &method$$85))) {
								ZEPHIR_INIT_NVAR(&_426$$127);
								object_init_ex(&_426$$127, moon_component_router_treenode_ce);
								if (zephir_has_constructor(&_426$$127)) {
									ZEPHIR_CALL_METHOD(NULL, &_426$$127, "__construct", NULL, 0);
									zephir_check_call_status();
								}
								zephir_update_property_array(this_ptr, SL("nodes"), &method$$85, &_426$$127);
							}
							ZEPHIR_CALL_METHOD(&_427$$126, this_ptr, "generateroutename", &_11, 156, &routeName, &method$$85, &uri);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&routeName, &_427$$126);
							zephir_read_property(&_428$$126, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&tree$$126);
							zephir_array_fetch(&tree$$126, &_428$$126, &method$$85, PH_NOISY, "moon/Component/Router/Router.zep", 295);
							ZEPHIR_INIT_NVAR(&_429$$126);
							zephir_fast_explode_str(&_429$$126, SL("/"), &uri, LONG_MAX);
							ZEPHIR_CALL_FUNCTION(&_427$$126, "array_filter", &_14, 95, &_429$$126);
							zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_15, 75, &_427$$126);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&length);
							ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
							if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
								zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 368);
								if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
									ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uriArr), _432$$128, _433$$128, _430$$128)
									{
										ZEPHIR_INIT_NVAR(&i);
										if (_433$$128 != NULL) { 
											ZVAL_STR_COPY(&i, _433$$128);
										} else {
											ZVAL_LONG(&i, _432$$128);
										}
										ZEPHIR_INIT_NVAR(&item);
										ZVAL_COPY(&item, _430$$128);
										ZVAL_LONG(&_434$$129, 0);
										ZVAL_LONG(&_435$$129, 1);
										ZEPHIR_INIT_NVAR(&_436$$129);
										zephir_substr(&_436$$129, &item, 0 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_437$$129);
										ZVAL_STRING(&_437$$129, "{");
										if (ZEPHIR_IS_EQUAL(&_437$$129, &_436$$129)) {
											ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&regexKey);
											ZVAL_STRING(&regexKey, "");
											zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 326);
											if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _438$$130)
												{
													ZEPHIR_INIT_NVAR(&re$$130);
													ZVAL_COPY(&re$$130, _438$$130);
													ZVAL_LONG(&_440$$131, 0);
													ZVAL_LONG(&_441$$131, 1);
													ZEPHIR_INIT_NVAR(&_442$$131);
													zephir_substr(&_442$$131, &re$$130, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_443$$131);
													ZVAL_STRING(&_443$$131, "{");
													if (ZEPHIR_IS_EQUAL(&_443$$131, &_442$$131)) {
														ZEPHIR_INIT_NVAR(&_444$$132);
														ZVAL_STRING(&_444$$132, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$130, &_444$$132, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_445$$133, 1);
															ZVAL_LONG(&_446$$133, -1);
															ZEPHIR_INIT_NVAR(&_447$$133);
															zephir_substr(&_447$$133, &re$$130, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_448$$133);
															ZVAL_STRING(&_448$$133, "___");
															ZEPHIR_INIT_NVAR(&_449$$133);
															ZVAL_STRING(&_449$$133, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_450$$133, "sprintf", &_38, 3, &formatStr, &_447$$133, &_448$$133, &routeName, &_449$$133);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_450$$133);
														} else {
															ZVAL_LONG(&_451$$134, 1);
															ZVAL_LONG(&_452$$134, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_453$$134);
															zephir_substr(&_453$$134, &re$$130, 1 , zephir_get_intval(&_452$$134), 0);
															ZVAL_LONG(&_454$$134, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_455$$134, -2);
															ZEPHIR_INIT_NVAR(&_456$$134);
															zephir_substr(&_456$$134, &re$$130, zephir_get_intval(&_454$$134), -2 , 0);
															ZEPHIR_INIT_NVAR(&_457$$134);
															ZVAL_STRING(&_457$$134, "___");
															ZEPHIR_CALL_FUNCTION(&_458$$134, "sprintf", &_38, 3, &formatStr, &_453$$134, &_457$$134, &routeName, &_456$$134);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_458$$134);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_459$$135);
														ZEPHIR_CONCAT_SV(&_459$$135, "/", &re$$130);
														zephir_concat_self(&regexKey, &_459$$135);
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_439$$130, &regexArr, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_439$$130)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&re$$130, &regexArr, "current", NULL, 0);
													zephir_check_call_status();
														ZVAL_LONG(&_460$$136, 0);
														ZVAL_LONG(&_461$$136, 1);
														ZEPHIR_INIT_NVAR(&_462$$136);
														zephir_substr(&_462$$136, &re$$130, 0 , 1 , 0);
														ZEPHIR_INIT_NVAR(&_463$$136);
														ZVAL_STRING(&_463$$136, "{");
														if (ZEPHIR_IS_EQUAL(&_463$$136, &_462$$136)) {
															ZEPHIR_INIT_NVAR(&_464$$137);
															ZVAL_STRING(&_464$$137, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$130, &_464$$137, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_465$$138, 1);
																ZVAL_LONG(&_466$$138, -1);
																ZEPHIR_INIT_NVAR(&_467$$138);
																zephir_substr(&_467$$138, &re$$130, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_468$$138);
																ZVAL_STRING(&_468$$138, "___");
																ZEPHIR_INIT_NVAR(&_469$$138);
																ZVAL_STRING(&_469$$138, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_470$$138, "sprintf", &_38, 3, &formatStr, &_467$$138, &_468$$138, &routeName, &_469$$138);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_470$$138);
															} else {
																ZVAL_LONG(&_471$$139, 1);
																ZVAL_LONG(&_472$$139, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_473$$139);
																zephir_substr(&_473$$139, &re$$130, 1 , zephir_get_intval(&_472$$139), 0);
																ZVAL_LONG(&_474$$139, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_475$$139, -2);
																ZEPHIR_INIT_NVAR(&_476$$139);
																zephir_substr(&_476$$139, &re$$130, zephir_get_intval(&_474$$139), -2 , 0);
																ZEPHIR_INIT_NVAR(&_477$$139);
																ZVAL_STRING(&_477$$139, "___");
																ZEPHIR_CALL_FUNCTION(&_478$$139, "sprintf", &_38, 3, &formatStr, &_473$$139, &_477$$139, &routeName, &_476$$139);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_478$$139);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_479$$140);
															ZEPHIR_CONCAT_SV(&_479$$140, "/", &re$$130);
															zephir_concat_self(&regexKey, &_479$$140);
														}
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&re$$130);
											ZVAL_LONG(&_480$$130, -1);
											ZVAL_LONG(&_481$$130, 1);
											ZEPHIR_INIT_NVAR(&_482$$130);
											zephir_substr(&_482$$130, &regexKey, -1 , 1 , 0);
											ZEPHIR_INIT_NVAR(&_483$$130);
											ZVAL_STRING(&_483$$130, ")");
											if (!ZEPHIR_IS_EQUAL(&_483$$130, &_482$$130)) {
												zephir_concat_self_str(&regexKey, SL("\\b"));
											}
											ZEPHIR_INIT_NVAR(&_484$$130);
											ZVAL_STRING(&_484$$130, "^%s$");
											ZEPHIR_CALL_FUNCTION(&_485$$130, "sprintf", &_38, 3, &_484$$130, &regexKey);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&regexKey, &_485$$130);
											ZEPHIR_CALL_METHOD(NULL, &tree$$126, "setregex", &_486, 0, &regexKey);
											zephir_check_call_status();
											break;
										}
										if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
											ZEPHIR_INIT_NVAR(&newNode$$142);
											object_init_ex(&newNode$$142, moon_component_router_node_ce);
											ZEPHIR_CALL_METHOD(NULL, &newNode$$142, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
											zephir_check_call_status();
											zephir_read_property(&_487$$142, &tree$$126, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											if (zephir_array_isset(&_487$$142, &item)) {
												zephir_read_property(&_488$$143, &tree$$126, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
												zephir_array_fetch(&_489$$143, &_488$$143, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 351);
												ZEPHIR_CALL_METHOD(NULL, &_489$$143, "setnode", NULL, 0, &newNode$$142);
												zephir_check_call_status();
											} else {
												ZEPHIR_INIT_NVAR(&newTree$$144);
												object_init_ex(&newTree$$144, moon_component_router_treenode_ce);
												if (zephir_has_constructor(&newTree$$144)) {
													ZEPHIR_CALL_METHOD(NULL, &newTree$$144, "__construct", &_490, 0);
													zephir_check_call_status();
												}
												ZEPHIR_CALL_METHOD(NULL, &newTree$$144, "setnode", &_80, 158, &newNode$$142);
												zephir_check_call_status();
												zephir_update_property_array(&tree$$126, SL("children"), &item, &newTree$$144);
											}
										} else {
											zephir_read_property(&_491$$145, &tree$$126, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											if (!(zephir_array_isset(&_491$$145, &item))) {
												ZEPHIR_INIT_NVAR(&_492$$146);
												object_init_ex(&_492$$146, moon_component_router_treenode_ce);
												if (zephir_has_constructor(&_492$$146)) {
													ZEPHIR_CALL_METHOD(NULL, &_492$$146, "__construct", NULL, 0);
													zephir_check_call_status();
												}
												zephir_update_property_array(&tree$$126, SL("children"), &item, &_492$$146);
											}
											zephir_read_property(&_493$$145, &tree$$126, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											zephir_array_fetch(&_494$$145, &_493$$145, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 365);
											ZEPHIR_CPY_WRT(&tree$$126, &_494$$145);
										}
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_431$$128, &uriArr, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_431$$128)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&i, &uriArr, "key", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
										zephir_check_call_status();
											ZVAL_LONG(&_495$$147, 0);
											ZVAL_LONG(&_496$$147, 1);
											ZEPHIR_INIT_NVAR(&_497$$147);
											zephir_substr(&_497$$147, &item, 0 , 1 , 0);
											ZEPHIR_INIT_NVAR(&_498$$147);
											ZVAL_STRING(&_498$$147, "{");
											if (ZEPHIR_IS_EQUAL(&_498$$147, &_497$$147)) {
												ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
												zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&regexKey);
												ZVAL_STRING(&regexKey, "");
												zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 326);
												if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
													ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _499$$148)
													{
														ZEPHIR_INIT_NVAR(&re$$148);
														ZVAL_COPY(&re$$148, _499$$148);
														ZVAL_LONG(&_501$$149, 0);
														ZVAL_LONG(&_502$$149, 1);
														ZEPHIR_INIT_NVAR(&_503$$149);
														zephir_substr(&_503$$149, &re$$148, 0 , 1 , 0);
														ZEPHIR_INIT_NVAR(&_504$$149);
														ZVAL_STRING(&_504$$149, "{");
														if (ZEPHIR_IS_EQUAL(&_504$$149, &_503$$149)) {
															ZEPHIR_INIT_NVAR(&_505$$150);
															ZVAL_STRING(&_505$$150, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$148, &_505$$150, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_506$$151, 1);
																ZVAL_LONG(&_507$$151, -1);
																ZEPHIR_INIT_NVAR(&_508$$151);
																zephir_substr(&_508$$151, &re$$148, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_509$$151);
																ZVAL_STRING(&_509$$151, "___");
																ZEPHIR_INIT_NVAR(&_510$$151);
																ZVAL_STRING(&_510$$151, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_511$$151, "sprintf", &_38, 3, &formatStr, &_508$$151, &_509$$151, &routeName, &_510$$151);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_511$$151);
															} else {
																ZVAL_LONG(&_512$$152, 1);
																ZVAL_LONG(&_513$$152, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_514$$152);
																zephir_substr(&_514$$152, &re$$148, 1 , zephir_get_intval(&_513$$152), 0);
																ZVAL_LONG(&_515$$152, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_516$$152, -2);
																ZEPHIR_INIT_NVAR(&_517$$152);
																zephir_substr(&_517$$152, &re$$148, zephir_get_intval(&_515$$152), -2 , 0);
																ZEPHIR_INIT_NVAR(&_518$$152);
																ZVAL_STRING(&_518$$152, "___");
																ZEPHIR_CALL_FUNCTION(&_519$$152, "sprintf", &_38, 3, &formatStr, &_514$$152, &_518$$152, &routeName, &_517$$152);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_519$$152);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_520$$153);
															ZEPHIR_CONCAT_SV(&_520$$153, "/", &re$$148);
															zephir_concat_self(&regexKey, &_520$$153);
														}
													} ZEND_HASH_FOREACH_END();
												} else {
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
													zephir_check_call_status();
													while (1) {
														ZEPHIR_CALL_METHOD(&_500$$148, &regexArr, "valid", NULL, 0);
														zephir_check_call_status();
														if (!zend_is_true(&_500$$148)) {
															break;
														}
														ZEPHIR_CALL_METHOD(&re$$148, &regexArr, "current", NULL, 0);
														zephir_check_call_status();
															ZVAL_LONG(&_521$$154, 0);
															ZVAL_LONG(&_522$$154, 1);
															ZEPHIR_INIT_NVAR(&_523$$154);
															zephir_substr(&_523$$154, &re$$148, 0 , 1 , 0);
															ZEPHIR_INIT_NVAR(&_524$$154);
															ZVAL_STRING(&_524$$154, "{");
															if (ZEPHIR_IS_EQUAL(&_524$$154, &_523$$154)) {
																ZEPHIR_INIT_NVAR(&_525$$155);
																ZVAL_STRING(&_525$$155, "<");
																ZEPHIR_INIT_NVAR(&regexPos);
																zephir_fast_strpos(&regexPos, &re$$148, &_525$$155, 0 );
																ZEPHIR_INIT_NVAR(&formatStr);
																ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
																if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																	ZVAL_LONG(&_526$$156, 1);
																	ZVAL_LONG(&_527$$156, -1);
																	ZEPHIR_INIT_NVAR(&_528$$156);
																	zephir_substr(&_528$$156, &re$$148, 1 , -1 , 0);
																	ZEPHIR_INIT_NVAR(&_529$$156);
																	ZVAL_STRING(&_529$$156, "___");
																	ZEPHIR_INIT_NVAR(&_530$$156);
																	ZVAL_STRING(&_530$$156, "[^/]+");
																	ZEPHIR_CALL_FUNCTION(&_531$$156, "sprintf", &_38, 3, &formatStr, &_528$$156, &_529$$156, &routeName, &_530$$156);
																	zephir_check_call_status();
																	zephir_concat_self(&regexKey, &_531$$156);
																} else {
																	ZVAL_LONG(&_532$$157, 1);
																	ZVAL_LONG(&_533$$157, (zephir_get_numberval(&regexPos) - 1));
																	ZEPHIR_INIT_NVAR(&_534$$157);
																	zephir_substr(&_534$$157, &re$$148, 1 , zephir_get_intval(&_533$$157), 0);
																	ZVAL_LONG(&_535$$157, (zephir_get_numberval(&regexPos) + 1));
																	ZVAL_LONG(&_536$$157, -2);
																	ZEPHIR_INIT_NVAR(&_537$$157);
																	zephir_substr(&_537$$157, &re$$148, zephir_get_intval(&_535$$157), -2 , 0);
																	ZEPHIR_INIT_NVAR(&_538$$157);
																	ZVAL_STRING(&_538$$157, "___");
																	ZEPHIR_CALL_FUNCTION(&_539$$157, "sprintf", &_38, 3, &formatStr, &_534$$157, &_538$$157, &routeName, &_537$$157);
																	zephir_check_call_status();
																	zephir_concat_self(&regexKey, &_539$$157);
																}
															} else {
																ZEPHIR_INIT_NVAR(&_540$$158);
																ZEPHIR_CONCAT_SV(&_540$$158, "/", &re$$148);
																zephir_concat_self(&regexKey, &_540$$158);
															}
														ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
														zephir_check_call_status();
													}
												}
												ZEPHIR_INIT_NVAR(&re$$148);
												ZVAL_LONG(&_541$$148, -1);
												ZVAL_LONG(&_542$$148, 1);
												ZEPHIR_INIT_NVAR(&_543$$148);
												zephir_substr(&_543$$148, &regexKey, -1 , 1 , 0);
												ZEPHIR_INIT_NVAR(&_544$$148);
												ZVAL_STRING(&_544$$148, ")");
												if (!ZEPHIR_IS_EQUAL(&_544$$148, &_543$$148)) {
													zephir_concat_self_str(&regexKey, SL("\\b"));
												}
												ZEPHIR_INIT_NVAR(&_545$$148);
												ZVAL_STRING(&_545$$148, "^%s$");
												ZEPHIR_CALL_FUNCTION(&_546$$148, "sprintf", &_38, 3, &_545$$148, &regexKey);
												zephir_check_call_status();
												ZEPHIR_CPY_WRT(&regexKey, &_546$$148);
												ZEPHIR_CALL_METHOD(NULL, &tree$$126, "setregex", &_547, 0, &regexKey);
												zephir_check_call_status();
												break;
											}
											if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
												ZEPHIR_INIT_NVAR(&newNode$$160);
												object_init_ex(&newNode$$160, moon_component_router_node_ce);
												ZEPHIR_CALL_METHOD(NULL, &newNode$$160, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
												zephir_check_call_status();
												zephir_read_property(&_548$$160, &tree$$126, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
												if (zephir_array_isset(&_548$$160, &item)) {
													zephir_read_property(&_549$$161, &tree$$126, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
													zephir_array_fetch(&_550$$161, &_549$$161, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 351);
													ZEPHIR_CALL_METHOD(NULL, &_550$$161, "setnode", NULL, 0, &newNode$$160);
													zephir_check_call_status();
												} else {
													ZEPHIR_INIT_NVAR(&newTree$$162);
													object_init_ex(&newTree$$162, moon_component_router_treenode_ce);
													if (zephir_has_constructor(&newTree$$162)) {
														ZEPHIR_CALL_METHOD(NULL, &newTree$$162, "__construct", &_551, 0);
														zephir_check_call_status();
													}
													ZEPHIR_CALL_METHOD(NULL, &newTree$$162, "setnode", &_80, 158, &newNode$$160);
													zephir_check_call_status();
													zephir_update_property_array(&tree$$126, SL("children"), &item, &newTree$$162);
												}
											} else {
												zephir_read_property(&_552$$163, &tree$$126, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
												if (!(zephir_array_isset(&_552$$163, &item))) {
													ZEPHIR_INIT_NVAR(&_553$$164);
													object_init_ex(&_553$$164, moon_component_router_treenode_ce);
													if (zephir_has_constructor(&_553$$164)) {
														ZEPHIR_CALL_METHOD(NULL, &_553$$164, "__construct", NULL, 0);
														zephir_check_call_status();
													}
													zephir_update_property_array(&tree$$126, SL("children"), &item, &_553$$164);
												}
												zephir_read_property(&_554$$163, &tree$$126, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
												zephir_array_fetch(&_555$$163, &_554$$163, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 365);
												ZEPHIR_CPY_WRT(&tree$$126, &_555$$163);
											}
										ZEPHIR_CALL_METHOD(NULL, &uriArr, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&item);
								ZEPHIR_INIT_NVAR(&i);
							} else {
								ZEPHIR_INIT_NVAR(&uri);
								ZVAL_STRING(&uri, "/");
								ZEPHIR_INIT_NVAR(&_556$$165);
								object_init_ex(&_556$$165, moon_component_router_node_ce);
								ZEPHIR_CALL_METHOD(NULL, &_556$$165, "__construct", &_75, 154, &uri, &handler, &routeName, &priority);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &tree$$126, "setnode", &_557, 0, &_556$$165);
								zephir_check_call_status();
							}
							ZEPHIR_INIT_NVAR(&_558$$126);
							zephir_create_array(&_558$$126, 5, 0);
							zephir_array_update_string(&_558$$126, SL("method"), &method$$85, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_558$$126, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_558$$126, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_558$$126, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_558$$126, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_559$$126);
							ZVAL_STRING(&_559$$126, "%s_%s");
							ZEPHIR_CALL_FUNCTION(&_560$$126, "sprintf", &_38, 3, &_559$$126, &method$$85, &routeName);
							zephir_check_call_status();
							zephir_update_property_array(this_ptr, SL("routes"), &_560$$126, &_558$$126);
						ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&method$$85);
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&router);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param RequestInterface $request
 * @return mixed
 */
PHP_METHOD(Moon_Component_Router_Router, dispatch) {

	zval _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, route, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_CALL_METHOD(&_0, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&route, this_ptr, "match", NULL, 0, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, moon_component_router_handler_ce);
	if (zephir_has_constructor(&_3)) {
		ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_5, &route, "gethandler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_3, "resolverhandler", NULL, 159, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, moon_component_router_argument_ce);
	if (zephir_has_constructor(&_6)) {
		ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_8, &route, "gethandler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CALL_METHOD(&_10, &route, "getparameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 1, 0);
	zephir_array_update_string(&_11, SL("_request"), request, PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(&_9, &_10, &_11);
	ZEPHIR_CALL_METHOD(&_7, &_6, "resolverargument", NULL, 160, &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_4, &_7);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Router_Router, generateRouteName) {

	zend_long counter;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *routeName_param = NULL, *method_param = NULL, *uri_param = NULL, _4, _6, _0$$4, _2$$4, _3$$4, _5$$5;
	zval routeName, method, uri, r, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &routeName_param, &method_param, &uri_param);

	zephir_get_strval(&routeName, routeName_param);
	zephir_get_strval(&method, method_param);
	zephir_get_strval(&uri, uri_param);


	if (!(ZEPHIR_IS_EMPTY(&routeName))) {
		ZEPHIR_CPY_WRT(&r, &routeName);
	} else {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_VV(&_1$$4, &method, &uri);
		zephir_md5(&_0$$4, &_1$$4);
		ZVAL_LONG(&_2$$4, 0);
		ZVAL_LONG(&_3$$4, 5);
		ZEPHIR_INIT_NVAR(&r);
		zephir_substr(&r, &_0$$4, 0 , 5 , 0);
		ZEPHIR_CPY_WRT(&routeName, &r);
	}
	counter = 1;
	while (1) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("routeNames"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset(&_4, &r))) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_5$$5);
		ZVAL_LONG(&_5$$5, counter);
		ZEPHIR_INIT_NVAR(&r);
		ZEPHIR_CONCAT_VV(&r, &routeName, &_5$$5);
		counter += 1;
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "");
	zephir_update_property_array(this_ptr, SL("routeNames"), &r, &_6);
	RETURN_CTOR(&r);

}

/**
 * @return array
 */
PHP_METHOD(Moon_Component_Router_Router, getRoutes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "routes");

}

/**
 * @return array
 */
PHP_METHOD(Moon_Component_Router_Router, getNodes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "nodes");

}

zend_object *zephir_init_properties_Moon_Component_Router_Router(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("routeNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routeNames"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("priority"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("priority"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("routers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routers"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routes"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("nodes"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

