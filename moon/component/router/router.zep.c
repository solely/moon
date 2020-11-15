
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
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_10 = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval uri, routeName, _3$$3, _12$$5;
	zval *methods_param = NULL, *uri_param = NULL, *handler, handler_sub, *routeName_param = NULL, *priority_param = NULL, _uri, method, *_0, _1, _17, _24, _26, _27, _2$$3, _4$$3, _7$$4, _8$$4, _9$$4, _11$$5, _13$$5, _14$$6, _15$$6, _16$$6, _18$$7, _19$$7, _20$$7, _21$$7, _22$$7, _23$$7;
	zval methods, _25;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_uri);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
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
		ZEPHIR_CALL_FUNCTION(&_uri, "sprintf", NULL, 3, &_23$$7, &_18$$7, &_21$$7);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_24);
	ZVAL_STRING(&_24, "/");
	ZEPHIR_INIT_NVAR(&_uri);
	zephir_fast_trim(&_uri, &uri, &_24, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&_25);
	zephir_create_array(&_25, 5, 0);
	zephir_array_update_string(&_25, SL("methods"), &methods, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_25, SL("uri"), &_uri, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_25, SL("handler"), handler, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_25, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_26);
	ZVAL_LONG(&_26, priority);
	zephir_array_update_string(&_25, SL("priority"), &_26, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_append(this_ptr, SL("routers"), &_25);
	ZEPHIR_INIT_ZVAL_NREF(_27);
	ZVAL_LONG(&_27, priority);
	zephir_update_property_array_append(this_ptr, SL("priority"), &_27);
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
	zephir_array_fetch(&_5, &_4, &_method, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 178);
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
	zephir_is_iterable(&_uriArr, 0, "moon/Component/Router/Router.zep", 194);
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
			zephir_array_fetch(&_16$$6, &_15$$6, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 190);
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
				zephir_array_fetch(&_20$$8, &_19$$8, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 190);
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
		zephir_is_iterable(&_26$$11, 0, "moon/Component/Router/Router.zep", 233);
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
					zephir_is_iterable(&match$$12, 0, "moon/Component/Router/Router.zep", 222);
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
									zephir_array_fetch_long(&_42$$16, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 217);
									zephir_array_update_zval(&parameters, &_42$$16, &m$$13, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&routeName);
									zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 218);
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
										zephir_array_fetch_long(&_47$$19, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 217);
										zephir_array_update_zval(&parameters, &_47$$19, &m$$13, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&routeName);
										zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 218);
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
					zephir_array_fetch(&route, &_48$$13, &_49$$13, PH_NOISY, "moon/Component/Router/Router.zep", 222);
					object_init_ex(return_value, moon_component_router_node_ce);
					zephir_array_fetch_string(&_50$$13, &route, SL("handler"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 226);
					zephir_array_fetch_string(&_51$$13, &route, SL("routeName"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 227);
					zephir_array_fetch_string(&_52$$13, &route, SL("priority"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 228);
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
						zephir_is_iterable(&match$$20, 0, "moon/Component/Router/Router.zep", 222);
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
										zephir_array_fetch_long(&_66$$24, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 217);
										zephir_array_update_zval(&parameters, &_66$$24, &m$$21, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&routeName);
										zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 218);
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
											zephir_array_fetch_long(&_71$$27, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 217);
											zephir_array_update_zval(&parameters, &_71$$27, &m$$21, PH_COPY | PH_SEPARATE);
											ZEPHIR_OBS_NVAR(&routeName);
											zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 218);
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
						zephir_array_fetch(&route, &_72$$21, &_73$$21, PH_NOISY, "moon/Component/Router/Router.zep", 222);
						object_init_ex(return_value, moon_component_router_node_ce);
						zephir_array_fetch_string(&_74$$21, &route, SL("handler"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 226);
						zephir_array_fetch_string(&_75$$21, &route, SL("routeName"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 227);
						zephir_array_fetch_string(&_76$$21, &route, SL("priority"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 228);
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
	zval *prefix_param = NULL, *_fn, _fn_sub, _0;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_fn_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &prefix_param, &_fn);

	zephir_get_strval(&prefix, prefix_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &prefix);
	ZEPHIR_CALL_ZVAL_FUNCTION(NULL, _fn, NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Router_Router, addRoutes) {

	zend_string *_19$$7, *_157$$43, *_293$$80, *_427$$116;
	zend_ulong _18$$7, _156$$43, _292$$80, _426$$116;
	zval _146$$5, _280$$41, _416$$78, _550$$114;
	zval methods, uri, handler, routeName, priority, formatStr, regexPos, regexKey, regexArr, item, i, length, uriArr, _0, _1, _2, _3, router, *_4, _5, method$$4, *_6$$4, _7$$4, _8$$5, _10$$5, tree$$5, _12$$5, _13$$5, _147$$5, _148$$5, _9$$6, *_16$$7, _17$$7, _20$$8, _21$$8, _22$$8, _23$$8, re$$9, *_25$$9, _26$$9, _68$$9, _69$$9, _70$$9, _71$$9, _72$$9, _73$$9, _27$$10, _28$$10, _29$$10, _30$$10, _31$$11, _32$$12, _33$$12, _34$$12, _35$$12, _36$$12, _37$$12, _39$$13, _40$$13, _41$$13, _42$$13, _43$$13, _44$$13, _45$$13, _46$$13, _47$$14, _48$$15, _49$$15, _50$$15, _51$$15, _52$$16, _53$$17, _54$$17, _55$$17, _56$$17, _57$$17, _58$$17, _59$$18, _60$$18, _61$$18, _62$$18, _63$$18, _64$$18, _65$$18, _66$$18, _67$$19, newTree$$21, _76$$21, _79$$22, _80$$22, _82$$22, _83$$22, _81$$23, _84$$24, _85$$24, _86$$24, _87$$24, re$$25, *_88$$25, _89$$25, _130$$25, _131$$25, _132$$25, _133$$25, _134$$25, _135$$25, _90$$26, _91$$26, _92$$26, _93$$26, _94$$27, _95$$28, _96$$28, _97$$28, _98$$28, _99$$28, _100$$28, _101$$29, _102$$29, _103$$29, _104$$29, _105$$29, _106$$29, _107$$29, _108$$29, _109$$30, _110$$31, _111$$31, _112$$31, _113$$31, _114$$32, _115$$33, _116$$33, _117$$33, _118$$33, _119$$33, _120$$33, _121$$34, _122$$34, _123$$34, _124$$34, _125$$34, _126$$34, _127$$34, _128$$34, _129$$35, newTree$$37, _138$$37, _139$$38, _140$$38, _142$$38, _143$$38, _141$$39, _144$$40, _149$$41, _151$$41, tree$$41, _152$$41, _153$$41, _281$$41, _282$$41, _150$$42, *_154$$43, _155$$43, _158$$44, _159$$44, _160$$44, _161$$44, re$$45, *_162$$45, _163$$45, _204$$45, _205$$45, _206$$45, _207$$45, _208$$45, _209$$45, _164$$46, _165$$46, _166$$46, _167$$46, _168$$47, _169$$48, _170$$48, _171$$48, _172$$48, _173$$48, _174$$48, _175$$49, _176$$49, _177$$49, _178$$49, _179$$49, _180$$49, _181$$49, _182$$49, _183$$50, _184$$51, _185$$51, _186$$51, _187$$51, _188$$52, _189$$53, _190$$53, _191$$53, _192$$53, _193$$53, _194$$53, _195$$54, _196$$54, _197$$54, _198$$54, _199$$54, _200$$54, _201$$54, _202$$54, _203$$55, newTree$$57, _212$$57, _213$$58, _214$$58, _216$$58, _217$$58, _215$$59, _218$$60, _219$$60, _220$$60, _221$$60, re$$61, *_222$$61, _223$$61, _264$$61, _265$$61, _266$$61, _267$$61, _268$$61, _269$$61, _224$$62, _225$$62, _226$$62, _227$$62, _228$$63, _229$$64, _230$$64, _231$$64, _232$$64, _233$$64, _234$$64, _235$$65, _236$$65, _237$$65, _238$$65, _239$$65, _240$$65, _241$$65, _242$$65, _243$$66, _244$$67, _245$$67, _246$$67, _247$$67, _248$$68, _249$$69, _250$$69, _251$$69, _252$$69, _253$$69, _254$$69, _255$$70, _256$$70, _257$$70, _258$$70, _259$$70, _260$$70, _261$$70, _262$$70, _263$$71, newTree$$73, _272$$73, _273$$74, _274$$74, _276$$74, _277$$74, _275$$75, _278$$76, method$$77, *_283$$77, _284$$77, _285$$78, _287$$78, tree$$78, _288$$78, _289$$78, _417$$78, _418$$78, _286$$79, *_290$$80, _291$$80, _294$$81, _295$$81, _296$$81, _297$$81, re$$82, *_298$$82, _299$$82, _340$$82, _341$$82, _342$$82, _343$$82, _344$$82, _345$$82, _300$$83, _301$$83, _302$$83, _303$$83, _304$$84, _305$$85, _306$$85, _307$$85, _308$$85, _309$$85, _310$$85, _311$$86, _312$$86, _313$$86, _314$$86, _315$$86, _316$$86, _317$$86, _318$$86, _319$$87, _320$$88, _321$$88, _322$$88, _323$$88, _324$$89, _325$$90, _326$$90, _327$$90, _328$$90, _329$$90, _330$$90, _331$$91, _332$$91, _333$$91, _334$$91, _335$$91, _336$$91, _337$$91, _338$$91, _339$$92, newTree$$94, _348$$94, _349$$95, _350$$95, _352$$95, _353$$95, _351$$96, _354$$97, _355$$97, _356$$97, _357$$97, re$$98, *_358$$98, _359$$98, _400$$98, _401$$98, _402$$98, _403$$98, _404$$98, _405$$98, _360$$99, _361$$99, _362$$99, _363$$99, _364$$100, _365$$101, _366$$101, _367$$101, _368$$101, _369$$101, _370$$101, _371$$102, _372$$102, _373$$102, _374$$102, _375$$102, _376$$102, _377$$102, _378$$102, _379$$103, _380$$104, _381$$104, _382$$104, _383$$104, _384$$105, _385$$106, _386$$106, _387$$106, _388$$106, _389$$106, _390$$106, _391$$107, _392$$107, _393$$107, _394$$107, _395$$107, _396$$107, _397$$107, _398$$107, _399$$108, newTree$$110, _408$$110, _409$$111, _410$$111, _412$$111, _413$$111, _411$$112, _414$$113, _419$$114, _421$$114, tree$$114, _422$$114, _423$$114, _551$$114, _552$$114, _420$$115, *_424$$116, _425$$116, _428$$117, _429$$117, _430$$117, _431$$117, re$$118, *_432$$118, _433$$118, _474$$118, _475$$118, _476$$118, _477$$118, _478$$118, _479$$118, _434$$119, _435$$119, _436$$119, _437$$119, _438$$120, _439$$121, _440$$121, _441$$121, _442$$121, _443$$121, _444$$121, _445$$122, _446$$122, _447$$122, _448$$122, _449$$122, _450$$122, _451$$122, _452$$122, _453$$123, _454$$124, _455$$124, _456$$124, _457$$124, _458$$125, _459$$126, _460$$126, _461$$126, _462$$126, _463$$126, _464$$126, _465$$127, _466$$127, _467$$127, _468$$127, _469$$127, _470$$127, _471$$127, _472$$127, _473$$128, newTree$$130, _482$$130, _483$$131, _484$$131, _486$$131, _487$$131, _485$$132, _488$$133, _489$$133, _490$$133, _491$$133, re$$134, *_492$$134, _493$$134, _534$$134, _535$$134, _536$$134, _537$$134, _538$$134, _539$$134, _494$$135, _495$$135, _496$$135, _497$$135, _498$$136, _499$$137, _500$$137, _501$$137, _502$$137, _503$$137, _504$$137, _505$$138, _506$$138, _507$$138, _508$$138, _509$$138, _510$$138, _511$$138, _512$$138, _513$$139, _514$$140, _515$$140, _516$$140, _517$$140, _518$$141, _519$$142, _520$$142, _521$$142, _522$$142, _523$$142, _524$$142, _525$$143, _526$$143, _527$$143, _528$$143, _529$$143, _530$$143, _531$$143, _532$$143, _533$$144, newTree$$146, _542$$146, _543$$147, _544$$147, _546$$147, _547$$147, _545$$148, _548$$149;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_14 = NULL, *_15 = NULL, *_24 = NULL, *_38 = NULL, *_74 = NULL, *_75 = NULL, *_77 = NULL, *_78 = NULL, *_136 = NULL, *_137 = NULL, *_145 = NULL, *_210 = NULL, *_211 = NULL, *_270 = NULL, *_271 = NULL, *_279 = NULL, *_346 = NULL, *_347 = NULL, *_406 = NULL, *_407 = NULL, *_415 = NULL, *_480 = NULL, *_481 = NULL, *_540 = NULL, *_541 = NULL, *_549 = NULL;
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
	ZVAL_UNDEF(&_147$$5);
	ZVAL_UNDEF(&_148$$5);
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
	ZVAL_UNDEF(&newTree$$21);
	ZVAL_UNDEF(&_76$$21);
	ZVAL_UNDEF(&_79$$22);
	ZVAL_UNDEF(&_80$$22);
	ZVAL_UNDEF(&_82$$22);
	ZVAL_UNDEF(&_83$$22);
	ZVAL_UNDEF(&_81$$23);
	ZVAL_UNDEF(&_84$$24);
	ZVAL_UNDEF(&_85$$24);
	ZVAL_UNDEF(&_86$$24);
	ZVAL_UNDEF(&_87$$24);
	ZVAL_UNDEF(&re$$25);
	ZVAL_UNDEF(&_89$$25);
	ZVAL_UNDEF(&_130$$25);
	ZVAL_UNDEF(&_131$$25);
	ZVAL_UNDEF(&_132$$25);
	ZVAL_UNDEF(&_133$$25);
	ZVAL_UNDEF(&_134$$25);
	ZVAL_UNDEF(&_135$$25);
	ZVAL_UNDEF(&_90$$26);
	ZVAL_UNDEF(&_91$$26);
	ZVAL_UNDEF(&_92$$26);
	ZVAL_UNDEF(&_93$$26);
	ZVAL_UNDEF(&_94$$27);
	ZVAL_UNDEF(&_95$$28);
	ZVAL_UNDEF(&_96$$28);
	ZVAL_UNDEF(&_97$$28);
	ZVAL_UNDEF(&_98$$28);
	ZVAL_UNDEF(&_99$$28);
	ZVAL_UNDEF(&_100$$28);
	ZVAL_UNDEF(&_101$$29);
	ZVAL_UNDEF(&_102$$29);
	ZVAL_UNDEF(&_103$$29);
	ZVAL_UNDEF(&_104$$29);
	ZVAL_UNDEF(&_105$$29);
	ZVAL_UNDEF(&_106$$29);
	ZVAL_UNDEF(&_107$$29);
	ZVAL_UNDEF(&_108$$29);
	ZVAL_UNDEF(&_109$$30);
	ZVAL_UNDEF(&_110$$31);
	ZVAL_UNDEF(&_111$$31);
	ZVAL_UNDEF(&_112$$31);
	ZVAL_UNDEF(&_113$$31);
	ZVAL_UNDEF(&_114$$32);
	ZVAL_UNDEF(&_115$$33);
	ZVAL_UNDEF(&_116$$33);
	ZVAL_UNDEF(&_117$$33);
	ZVAL_UNDEF(&_118$$33);
	ZVAL_UNDEF(&_119$$33);
	ZVAL_UNDEF(&_120$$33);
	ZVAL_UNDEF(&_121$$34);
	ZVAL_UNDEF(&_122$$34);
	ZVAL_UNDEF(&_123$$34);
	ZVAL_UNDEF(&_124$$34);
	ZVAL_UNDEF(&_125$$34);
	ZVAL_UNDEF(&_126$$34);
	ZVAL_UNDEF(&_127$$34);
	ZVAL_UNDEF(&_128$$34);
	ZVAL_UNDEF(&_129$$35);
	ZVAL_UNDEF(&newTree$$37);
	ZVAL_UNDEF(&_138$$37);
	ZVAL_UNDEF(&_139$$38);
	ZVAL_UNDEF(&_140$$38);
	ZVAL_UNDEF(&_142$$38);
	ZVAL_UNDEF(&_143$$38);
	ZVAL_UNDEF(&_141$$39);
	ZVAL_UNDEF(&_144$$40);
	ZVAL_UNDEF(&_149$$41);
	ZVAL_UNDEF(&_151$$41);
	ZVAL_UNDEF(&tree$$41);
	ZVAL_UNDEF(&_152$$41);
	ZVAL_UNDEF(&_153$$41);
	ZVAL_UNDEF(&_281$$41);
	ZVAL_UNDEF(&_282$$41);
	ZVAL_UNDEF(&_150$$42);
	ZVAL_UNDEF(&_155$$43);
	ZVAL_UNDEF(&_158$$44);
	ZVAL_UNDEF(&_159$$44);
	ZVAL_UNDEF(&_160$$44);
	ZVAL_UNDEF(&_161$$44);
	ZVAL_UNDEF(&re$$45);
	ZVAL_UNDEF(&_163$$45);
	ZVAL_UNDEF(&_204$$45);
	ZVAL_UNDEF(&_205$$45);
	ZVAL_UNDEF(&_206$$45);
	ZVAL_UNDEF(&_207$$45);
	ZVAL_UNDEF(&_208$$45);
	ZVAL_UNDEF(&_209$$45);
	ZVAL_UNDEF(&_164$$46);
	ZVAL_UNDEF(&_165$$46);
	ZVAL_UNDEF(&_166$$46);
	ZVAL_UNDEF(&_167$$46);
	ZVAL_UNDEF(&_168$$47);
	ZVAL_UNDEF(&_169$$48);
	ZVAL_UNDEF(&_170$$48);
	ZVAL_UNDEF(&_171$$48);
	ZVAL_UNDEF(&_172$$48);
	ZVAL_UNDEF(&_173$$48);
	ZVAL_UNDEF(&_174$$48);
	ZVAL_UNDEF(&_175$$49);
	ZVAL_UNDEF(&_176$$49);
	ZVAL_UNDEF(&_177$$49);
	ZVAL_UNDEF(&_178$$49);
	ZVAL_UNDEF(&_179$$49);
	ZVAL_UNDEF(&_180$$49);
	ZVAL_UNDEF(&_181$$49);
	ZVAL_UNDEF(&_182$$49);
	ZVAL_UNDEF(&_183$$50);
	ZVAL_UNDEF(&_184$$51);
	ZVAL_UNDEF(&_185$$51);
	ZVAL_UNDEF(&_186$$51);
	ZVAL_UNDEF(&_187$$51);
	ZVAL_UNDEF(&_188$$52);
	ZVAL_UNDEF(&_189$$53);
	ZVAL_UNDEF(&_190$$53);
	ZVAL_UNDEF(&_191$$53);
	ZVAL_UNDEF(&_192$$53);
	ZVAL_UNDEF(&_193$$53);
	ZVAL_UNDEF(&_194$$53);
	ZVAL_UNDEF(&_195$$54);
	ZVAL_UNDEF(&_196$$54);
	ZVAL_UNDEF(&_197$$54);
	ZVAL_UNDEF(&_198$$54);
	ZVAL_UNDEF(&_199$$54);
	ZVAL_UNDEF(&_200$$54);
	ZVAL_UNDEF(&_201$$54);
	ZVAL_UNDEF(&_202$$54);
	ZVAL_UNDEF(&_203$$55);
	ZVAL_UNDEF(&newTree$$57);
	ZVAL_UNDEF(&_212$$57);
	ZVAL_UNDEF(&_213$$58);
	ZVAL_UNDEF(&_214$$58);
	ZVAL_UNDEF(&_216$$58);
	ZVAL_UNDEF(&_217$$58);
	ZVAL_UNDEF(&_215$$59);
	ZVAL_UNDEF(&_218$$60);
	ZVAL_UNDEF(&_219$$60);
	ZVAL_UNDEF(&_220$$60);
	ZVAL_UNDEF(&_221$$60);
	ZVAL_UNDEF(&re$$61);
	ZVAL_UNDEF(&_223$$61);
	ZVAL_UNDEF(&_264$$61);
	ZVAL_UNDEF(&_265$$61);
	ZVAL_UNDEF(&_266$$61);
	ZVAL_UNDEF(&_267$$61);
	ZVAL_UNDEF(&_268$$61);
	ZVAL_UNDEF(&_269$$61);
	ZVAL_UNDEF(&_224$$62);
	ZVAL_UNDEF(&_225$$62);
	ZVAL_UNDEF(&_226$$62);
	ZVAL_UNDEF(&_227$$62);
	ZVAL_UNDEF(&_228$$63);
	ZVAL_UNDEF(&_229$$64);
	ZVAL_UNDEF(&_230$$64);
	ZVAL_UNDEF(&_231$$64);
	ZVAL_UNDEF(&_232$$64);
	ZVAL_UNDEF(&_233$$64);
	ZVAL_UNDEF(&_234$$64);
	ZVAL_UNDEF(&_235$$65);
	ZVAL_UNDEF(&_236$$65);
	ZVAL_UNDEF(&_237$$65);
	ZVAL_UNDEF(&_238$$65);
	ZVAL_UNDEF(&_239$$65);
	ZVAL_UNDEF(&_240$$65);
	ZVAL_UNDEF(&_241$$65);
	ZVAL_UNDEF(&_242$$65);
	ZVAL_UNDEF(&_243$$66);
	ZVAL_UNDEF(&_244$$67);
	ZVAL_UNDEF(&_245$$67);
	ZVAL_UNDEF(&_246$$67);
	ZVAL_UNDEF(&_247$$67);
	ZVAL_UNDEF(&_248$$68);
	ZVAL_UNDEF(&_249$$69);
	ZVAL_UNDEF(&_250$$69);
	ZVAL_UNDEF(&_251$$69);
	ZVAL_UNDEF(&_252$$69);
	ZVAL_UNDEF(&_253$$69);
	ZVAL_UNDEF(&_254$$69);
	ZVAL_UNDEF(&_255$$70);
	ZVAL_UNDEF(&_256$$70);
	ZVAL_UNDEF(&_257$$70);
	ZVAL_UNDEF(&_258$$70);
	ZVAL_UNDEF(&_259$$70);
	ZVAL_UNDEF(&_260$$70);
	ZVAL_UNDEF(&_261$$70);
	ZVAL_UNDEF(&_262$$70);
	ZVAL_UNDEF(&_263$$71);
	ZVAL_UNDEF(&newTree$$73);
	ZVAL_UNDEF(&_272$$73);
	ZVAL_UNDEF(&_273$$74);
	ZVAL_UNDEF(&_274$$74);
	ZVAL_UNDEF(&_276$$74);
	ZVAL_UNDEF(&_277$$74);
	ZVAL_UNDEF(&_275$$75);
	ZVAL_UNDEF(&_278$$76);
	ZVAL_UNDEF(&method$$77);
	ZVAL_UNDEF(&_284$$77);
	ZVAL_UNDEF(&_285$$78);
	ZVAL_UNDEF(&_287$$78);
	ZVAL_UNDEF(&tree$$78);
	ZVAL_UNDEF(&_288$$78);
	ZVAL_UNDEF(&_289$$78);
	ZVAL_UNDEF(&_417$$78);
	ZVAL_UNDEF(&_418$$78);
	ZVAL_UNDEF(&_286$$79);
	ZVAL_UNDEF(&_291$$80);
	ZVAL_UNDEF(&_294$$81);
	ZVAL_UNDEF(&_295$$81);
	ZVAL_UNDEF(&_296$$81);
	ZVAL_UNDEF(&_297$$81);
	ZVAL_UNDEF(&re$$82);
	ZVAL_UNDEF(&_299$$82);
	ZVAL_UNDEF(&_340$$82);
	ZVAL_UNDEF(&_341$$82);
	ZVAL_UNDEF(&_342$$82);
	ZVAL_UNDEF(&_343$$82);
	ZVAL_UNDEF(&_344$$82);
	ZVAL_UNDEF(&_345$$82);
	ZVAL_UNDEF(&_300$$83);
	ZVAL_UNDEF(&_301$$83);
	ZVAL_UNDEF(&_302$$83);
	ZVAL_UNDEF(&_303$$83);
	ZVAL_UNDEF(&_304$$84);
	ZVAL_UNDEF(&_305$$85);
	ZVAL_UNDEF(&_306$$85);
	ZVAL_UNDEF(&_307$$85);
	ZVAL_UNDEF(&_308$$85);
	ZVAL_UNDEF(&_309$$85);
	ZVAL_UNDEF(&_310$$85);
	ZVAL_UNDEF(&_311$$86);
	ZVAL_UNDEF(&_312$$86);
	ZVAL_UNDEF(&_313$$86);
	ZVAL_UNDEF(&_314$$86);
	ZVAL_UNDEF(&_315$$86);
	ZVAL_UNDEF(&_316$$86);
	ZVAL_UNDEF(&_317$$86);
	ZVAL_UNDEF(&_318$$86);
	ZVAL_UNDEF(&_319$$87);
	ZVAL_UNDEF(&_320$$88);
	ZVAL_UNDEF(&_321$$88);
	ZVAL_UNDEF(&_322$$88);
	ZVAL_UNDEF(&_323$$88);
	ZVAL_UNDEF(&_324$$89);
	ZVAL_UNDEF(&_325$$90);
	ZVAL_UNDEF(&_326$$90);
	ZVAL_UNDEF(&_327$$90);
	ZVAL_UNDEF(&_328$$90);
	ZVAL_UNDEF(&_329$$90);
	ZVAL_UNDEF(&_330$$90);
	ZVAL_UNDEF(&_331$$91);
	ZVAL_UNDEF(&_332$$91);
	ZVAL_UNDEF(&_333$$91);
	ZVAL_UNDEF(&_334$$91);
	ZVAL_UNDEF(&_335$$91);
	ZVAL_UNDEF(&_336$$91);
	ZVAL_UNDEF(&_337$$91);
	ZVAL_UNDEF(&_338$$91);
	ZVAL_UNDEF(&_339$$92);
	ZVAL_UNDEF(&newTree$$94);
	ZVAL_UNDEF(&_348$$94);
	ZVAL_UNDEF(&_349$$95);
	ZVAL_UNDEF(&_350$$95);
	ZVAL_UNDEF(&_352$$95);
	ZVAL_UNDEF(&_353$$95);
	ZVAL_UNDEF(&_351$$96);
	ZVAL_UNDEF(&_354$$97);
	ZVAL_UNDEF(&_355$$97);
	ZVAL_UNDEF(&_356$$97);
	ZVAL_UNDEF(&_357$$97);
	ZVAL_UNDEF(&re$$98);
	ZVAL_UNDEF(&_359$$98);
	ZVAL_UNDEF(&_400$$98);
	ZVAL_UNDEF(&_401$$98);
	ZVAL_UNDEF(&_402$$98);
	ZVAL_UNDEF(&_403$$98);
	ZVAL_UNDEF(&_404$$98);
	ZVAL_UNDEF(&_405$$98);
	ZVAL_UNDEF(&_360$$99);
	ZVAL_UNDEF(&_361$$99);
	ZVAL_UNDEF(&_362$$99);
	ZVAL_UNDEF(&_363$$99);
	ZVAL_UNDEF(&_364$$100);
	ZVAL_UNDEF(&_365$$101);
	ZVAL_UNDEF(&_366$$101);
	ZVAL_UNDEF(&_367$$101);
	ZVAL_UNDEF(&_368$$101);
	ZVAL_UNDEF(&_369$$101);
	ZVAL_UNDEF(&_370$$101);
	ZVAL_UNDEF(&_371$$102);
	ZVAL_UNDEF(&_372$$102);
	ZVAL_UNDEF(&_373$$102);
	ZVAL_UNDEF(&_374$$102);
	ZVAL_UNDEF(&_375$$102);
	ZVAL_UNDEF(&_376$$102);
	ZVAL_UNDEF(&_377$$102);
	ZVAL_UNDEF(&_378$$102);
	ZVAL_UNDEF(&_379$$103);
	ZVAL_UNDEF(&_380$$104);
	ZVAL_UNDEF(&_381$$104);
	ZVAL_UNDEF(&_382$$104);
	ZVAL_UNDEF(&_383$$104);
	ZVAL_UNDEF(&_384$$105);
	ZVAL_UNDEF(&_385$$106);
	ZVAL_UNDEF(&_386$$106);
	ZVAL_UNDEF(&_387$$106);
	ZVAL_UNDEF(&_388$$106);
	ZVAL_UNDEF(&_389$$106);
	ZVAL_UNDEF(&_390$$106);
	ZVAL_UNDEF(&_391$$107);
	ZVAL_UNDEF(&_392$$107);
	ZVAL_UNDEF(&_393$$107);
	ZVAL_UNDEF(&_394$$107);
	ZVAL_UNDEF(&_395$$107);
	ZVAL_UNDEF(&_396$$107);
	ZVAL_UNDEF(&_397$$107);
	ZVAL_UNDEF(&_398$$107);
	ZVAL_UNDEF(&_399$$108);
	ZVAL_UNDEF(&newTree$$110);
	ZVAL_UNDEF(&_408$$110);
	ZVAL_UNDEF(&_409$$111);
	ZVAL_UNDEF(&_410$$111);
	ZVAL_UNDEF(&_412$$111);
	ZVAL_UNDEF(&_413$$111);
	ZVAL_UNDEF(&_411$$112);
	ZVAL_UNDEF(&_414$$113);
	ZVAL_UNDEF(&_419$$114);
	ZVAL_UNDEF(&_421$$114);
	ZVAL_UNDEF(&tree$$114);
	ZVAL_UNDEF(&_422$$114);
	ZVAL_UNDEF(&_423$$114);
	ZVAL_UNDEF(&_551$$114);
	ZVAL_UNDEF(&_552$$114);
	ZVAL_UNDEF(&_420$$115);
	ZVAL_UNDEF(&_425$$116);
	ZVAL_UNDEF(&_428$$117);
	ZVAL_UNDEF(&_429$$117);
	ZVAL_UNDEF(&_430$$117);
	ZVAL_UNDEF(&_431$$117);
	ZVAL_UNDEF(&re$$118);
	ZVAL_UNDEF(&_433$$118);
	ZVAL_UNDEF(&_474$$118);
	ZVAL_UNDEF(&_475$$118);
	ZVAL_UNDEF(&_476$$118);
	ZVAL_UNDEF(&_477$$118);
	ZVAL_UNDEF(&_478$$118);
	ZVAL_UNDEF(&_479$$118);
	ZVAL_UNDEF(&_434$$119);
	ZVAL_UNDEF(&_435$$119);
	ZVAL_UNDEF(&_436$$119);
	ZVAL_UNDEF(&_437$$119);
	ZVAL_UNDEF(&_438$$120);
	ZVAL_UNDEF(&_439$$121);
	ZVAL_UNDEF(&_440$$121);
	ZVAL_UNDEF(&_441$$121);
	ZVAL_UNDEF(&_442$$121);
	ZVAL_UNDEF(&_443$$121);
	ZVAL_UNDEF(&_444$$121);
	ZVAL_UNDEF(&_445$$122);
	ZVAL_UNDEF(&_446$$122);
	ZVAL_UNDEF(&_447$$122);
	ZVAL_UNDEF(&_448$$122);
	ZVAL_UNDEF(&_449$$122);
	ZVAL_UNDEF(&_450$$122);
	ZVAL_UNDEF(&_451$$122);
	ZVAL_UNDEF(&_452$$122);
	ZVAL_UNDEF(&_453$$123);
	ZVAL_UNDEF(&_454$$124);
	ZVAL_UNDEF(&_455$$124);
	ZVAL_UNDEF(&_456$$124);
	ZVAL_UNDEF(&_457$$124);
	ZVAL_UNDEF(&_458$$125);
	ZVAL_UNDEF(&_459$$126);
	ZVAL_UNDEF(&_460$$126);
	ZVAL_UNDEF(&_461$$126);
	ZVAL_UNDEF(&_462$$126);
	ZVAL_UNDEF(&_463$$126);
	ZVAL_UNDEF(&_464$$126);
	ZVAL_UNDEF(&_465$$127);
	ZVAL_UNDEF(&_466$$127);
	ZVAL_UNDEF(&_467$$127);
	ZVAL_UNDEF(&_468$$127);
	ZVAL_UNDEF(&_469$$127);
	ZVAL_UNDEF(&_470$$127);
	ZVAL_UNDEF(&_471$$127);
	ZVAL_UNDEF(&_472$$127);
	ZVAL_UNDEF(&_473$$128);
	ZVAL_UNDEF(&newTree$$130);
	ZVAL_UNDEF(&_482$$130);
	ZVAL_UNDEF(&_483$$131);
	ZVAL_UNDEF(&_484$$131);
	ZVAL_UNDEF(&_486$$131);
	ZVAL_UNDEF(&_487$$131);
	ZVAL_UNDEF(&_485$$132);
	ZVAL_UNDEF(&_488$$133);
	ZVAL_UNDEF(&_489$$133);
	ZVAL_UNDEF(&_490$$133);
	ZVAL_UNDEF(&_491$$133);
	ZVAL_UNDEF(&re$$134);
	ZVAL_UNDEF(&_493$$134);
	ZVAL_UNDEF(&_534$$134);
	ZVAL_UNDEF(&_535$$134);
	ZVAL_UNDEF(&_536$$134);
	ZVAL_UNDEF(&_537$$134);
	ZVAL_UNDEF(&_538$$134);
	ZVAL_UNDEF(&_539$$134);
	ZVAL_UNDEF(&_494$$135);
	ZVAL_UNDEF(&_495$$135);
	ZVAL_UNDEF(&_496$$135);
	ZVAL_UNDEF(&_497$$135);
	ZVAL_UNDEF(&_498$$136);
	ZVAL_UNDEF(&_499$$137);
	ZVAL_UNDEF(&_500$$137);
	ZVAL_UNDEF(&_501$$137);
	ZVAL_UNDEF(&_502$$137);
	ZVAL_UNDEF(&_503$$137);
	ZVAL_UNDEF(&_504$$137);
	ZVAL_UNDEF(&_505$$138);
	ZVAL_UNDEF(&_506$$138);
	ZVAL_UNDEF(&_507$$138);
	ZVAL_UNDEF(&_508$$138);
	ZVAL_UNDEF(&_509$$138);
	ZVAL_UNDEF(&_510$$138);
	ZVAL_UNDEF(&_511$$138);
	ZVAL_UNDEF(&_512$$138);
	ZVAL_UNDEF(&_513$$139);
	ZVAL_UNDEF(&_514$$140);
	ZVAL_UNDEF(&_515$$140);
	ZVAL_UNDEF(&_516$$140);
	ZVAL_UNDEF(&_517$$140);
	ZVAL_UNDEF(&_518$$141);
	ZVAL_UNDEF(&_519$$142);
	ZVAL_UNDEF(&_520$$142);
	ZVAL_UNDEF(&_521$$142);
	ZVAL_UNDEF(&_522$$142);
	ZVAL_UNDEF(&_523$$142);
	ZVAL_UNDEF(&_524$$142);
	ZVAL_UNDEF(&_525$$143);
	ZVAL_UNDEF(&_526$$143);
	ZVAL_UNDEF(&_527$$143);
	ZVAL_UNDEF(&_528$$143);
	ZVAL_UNDEF(&_529$$143);
	ZVAL_UNDEF(&_530$$143);
	ZVAL_UNDEF(&_531$$143);
	ZVAL_UNDEF(&_532$$143);
	ZVAL_UNDEF(&_533$$144);
	ZVAL_UNDEF(&newTree$$146);
	ZVAL_UNDEF(&_542$$146);
	ZVAL_UNDEF(&_543$$147);
	ZVAL_UNDEF(&_544$$147);
	ZVAL_UNDEF(&_546$$147);
	ZVAL_UNDEF(&_547$$147);
	ZVAL_UNDEF(&_545$$148);
	ZVAL_UNDEF(&_548$$149);
	ZVAL_UNDEF(&_146$$5);
	ZVAL_UNDEF(&_280$$41);
	ZVAL_UNDEF(&_416$$78);
	ZVAL_UNDEF(&_550$$114);

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
	zephir_is_iterable(&_3, 0, "moon/Component/Router/Router.zep", 369);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&router);
			ZVAL_COPY(&router, _4);
			ZEPHIR_OBS_NVAR(&methods);
			zephir_array_fetch_string(&methods, &router, SL("methods"), PH_NOISY, "moon/Component/Router/Router.zep", 271);
			ZEPHIR_OBS_NVAR(&uri);
			zephir_array_fetch_string(&uri, &router, SL("uri"), PH_NOISY, "moon/Component/Router/Router.zep", 272);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_string(&handler, &router, SL("handler"), PH_NOISY, "moon/Component/Router/Router.zep", 273);
			ZEPHIR_OBS_NVAR(&routeName);
			zephir_array_fetch_string(&routeName, &router, SL("routeName"), PH_NOISY, "moon/Component/Router/Router.zep", 274);
			ZEPHIR_OBS_NVAR(&priority);
			zephir_array_fetch_string(&priority, &router, SL("priority"), PH_NOISY, "moon/Component/Router/Router.zep", 275);
			zephir_is_iterable(&methods, 0, "moon/Component/Router/Router.zep", 368);
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
					zephir_array_fetch(&tree$$5, &_12$$5, &method$$4, PH_NOISY, "moon/Component/Router/Router.zep", 291);
					ZEPHIR_INIT_NVAR(&_13$$5);
					zephir_fast_explode_str(&_13$$5, SL("/"), &uri, LONG_MAX);
					ZEPHIR_CALL_FUNCTION(&_10$$5, "array_filter", &_14, 95, &_13$$5);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_15, 75, &_10$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&length);
					ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
					if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
						zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 356);
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
									zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 322);
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
									ZEPHIR_INIT_NVAR(&newTree$$21);
									object_init_ex(&newTree$$21, moon_component_router_treenode_ce);
									if (zephir_has_constructor(&newTree$$21)) {
										ZEPHIR_CALL_METHOD(NULL, &newTree$$21, "__construct", &_75, 0);
										zephir_check_call_status();
									}
									ZEPHIR_INIT_NVAR(&_76$$21);
									object_init_ex(&_76$$21, moon_component_router_node_ce);
									ZEPHIR_CALL_METHOD(NULL, &_76$$21, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &newTree$$21, "setnode", &_78, 158, &_76$$21);
									zephir_check_call_status();
									zephir_update_property_array(&tree$$5, SL("children"), &item, &newTree$$21);
								} else {
									zephir_read_property(&_79$$22, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_OBS_NVAR(&_80$$22);
									zephir_array_fetch(&_80$$22, &_79$$22, &item, PH_NOISY, "moon/Component/Router/Router.zep", 350);
									if (ZEPHIR_IS_EMPTY(&_80$$22)) {
										ZEPHIR_INIT_NVAR(&_81$$23);
										object_init_ex(&_81$$23, moon_component_router_treenode_ce);
										if (zephir_has_constructor(&_81$$23)) {
											ZEPHIR_CALL_METHOD(NULL, &_81$$23, "__construct", NULL, 0);
											zephir_check_call_status();
										}
										zephir_update_property_array(&tree$$5, SL("children"), &item, &_81$$23);
									}
									zephir_read_property(&_82$$22, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
									zephir_array_fetch(&_83$$22, &_82$$22, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 353);
									ZEPHIR_CPY_WRT(&tree$$5, &_83$$22);
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
									ZVAL_LONG(&_84$$24, 0);
									ZVAL_LONG(&_85$$24, 1);
									ZEPHIR_INIT_NVAR(&_86$$24);
									zephir_substr(&_86$$24, &item, 0 , 1 , 0);
									ZEPHIR_INIT_NVAR(&_87$$24);
									ZVAL_STRING(&_87$$24, "{");
									if (ZEPHIR_IS_EQUAL(&_87$$24, &_86$$24)) {
										ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&regexKey);
										ZVAL_STRING(&regexKey, "");
										zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 322);
										if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _88$$25)
											{
												ZEPHIR_INIT_NVAR(&re$$25);
												ZVAL_COPY(&re$$25, _88$$25);
												ZVAL_LONG(&_90$$26, 0);
												ZVAL_LONG(&_91$$26, 1);
												ZEPHIR_INIT_NVAR(&_92$$26);
												zephir_substr(&_92$$26, &re$$25, 0 , 1 , 0);
												ZEPHIR_INIT_NVAR(&_93$$26);
												ZVAL_STRING(&_93$$26, "{");
												if (ZEPHIR_IS_EQUAL(&_93$$26, &_92$$26)) {
													ZEPHIR_INIT_NVAR(&_94$$27);
													ZVAL_STRING(&_94$$27, "<");
													ZEPHIR_INIT_NVAR(&regexPos);
													zephir_fast_strpos(&regexPos, &re$$25, &_94$$27, 0 );
													ZEPHIR_INIT_NVAR(&formatStr);
													ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
													if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
														ZVAL_LONG(&_95$$28, 1);
														ZVAL_LONG(&_96$$28, -1);
														ZEPHIR_INIT_NVAR(&_97$$28);
														zephir_substr(&_97$$28, &re$$25, 1 , -1 , 0);
														ZEPHIR_INIT_NVAR(&_98$$28);
														ZVAL_STRING(&_98$$28, "___");
														ZEPHIR_INIT_NVAR(&_99$$28);
														ZVAL_STRING(&_99$$28, "[^/]+");
														ZEPHIR_CALL_FUNCTION(&_100$$28, "sprintf", &_38, 3, &formatStr, &_97$$28, &_98$$28, &routeName, &_99$$28);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_100$$28);
													} else {
														ZVAL_LONG(&_101$$29, 1);
														ZVAL_LONG(&_102$$29, (zephir_get_numberval(&regexPos) - 1));
														ZEPHIR_INIT_NVAR(&_103$$29);
														zephir_substr(&_103$$29, &re$$25, 1 , zephir_get_intval(&_102$$29), 0);
														ZVAL_LONG(&_104$$29, (zephir_get_numberval(&regexPos) + 1));
														ZVAL_LONG(&_105$$29, -2);
														ZEPHIR_INIT_NVAR(&_106$$29);
														zephir_substr(&_106$$29, &re$$25, zephir_get_intval(&_104$$29), -2 , 0);
														ZEPHIR_INIT_NVAR(&_107$$29);
														ZVAL_STRING(&_107$$29, "___");
														ZEPHIR_CALL_FUNCTION(&_108$$29, "sprintf", &_38, 3, &formatStr, &_103$$29, &_107$$29, &routeName, &_106$$29);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_108$$29);
													}
												} else {
													ZEPHIR_INIT_NVAR(&_109$$30);
													ZEPHIR_CONCAT_SV(&_109$$30, "/", &re$$25);
													zephir_concat_self(&regexKey, &_109$$30);
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_89$$25, &regexArr, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_89$$25)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&re$$25, &regexArr, "current", NULL, 0);
												zephir_check_call_status();
													ZVAL_LONG(&_110$$31, 0);
													ZVAL_LONG(&_111$$31, 1);
													ZEPHIR_INIT_NVAR(&_112$$31);
													zephir_substr(&_112$$31, &re$$25, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_113$$31);
													ZVAL_STRING(&_113$$31, "{");
													if (ZEPHIR_IS_EQUAL(&_113$$31, &_112$$31)) {
														ZEPHIR_INIT_NVAR(&_114$$32);
														ZVAL_STRING(&_114$$32, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$25, &_114$$32, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_115$$33, 1);
															ZVAL_LONG(&_116$$33, -1);
															ZEPHIR_INIT_NVAR(&_117$$33);
															zephir_substr(&_117$$33, &re$$25, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_118$$33);
															ZVAL_STRING(&_118$$33, "___");
															ZEPHIR_INIT_NVAR(&_119$$33);
															ZVAL_STRING(&_119$$33, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_120$$33, "sprintf", &_38, 3, &formatStr, &_117$$33, &_118$$33, &routeName, &_119$$33);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_120$$33);
														} else {
															ZVAL_LONG(&_121$$34, 1);
															ZVAL_LONG(&_122$$34, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_123$$34);
															zephir_substr(&_123$$34, &re$$25, 1 , zephir_get_intval(&_122$$34), 0);
															ZVAL_LONG(&_124$$34, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_125$$34, -2);
															ZEPHIR_INIT_NVAR(&_126$$34);
															zephir_substr(&_126$$34, &re$$25, zephir_get_intval(&_124$$34), -2 , 0);
															ZEPHIR_INIT_NVAR(&_127$$34);
															ZVAL_STRING(&_127$$34, "___");
															ZEPHIR_CALL_FUNCTION(&_128$$34, "sprintf", &_38, 3, &formatStr, &_123$$34, &_127$$34, &routeName, &_126$$34);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_128$$34);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_129$$35);
														ZEPHIR_CONCAT_SV(&_129$$35, "/", &re$$25);
														zephir_concat_self(&regexKey, &_129$$35);
													}
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&re$$25);
										ZVAL_LONG(&_130$$25, -1);
										ZVAL_LONG(&_131$$25, 1);
										ZEPHIR_INIT_NVAR(&_132$$25);
										zephir_substr(&_132$$25, &regexKey, -1 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_133$$25);
										ZVAL_STRING(&_133$$25, ")");
										if (!ZEPHIR_IS_EQUAL(&_133$$25, &_132$$25)) {
											zephir_concat_self_str(&regexKey, SL("\\b"));
										}
										ZEPHIR_INIT_NVAR(&_134$$25);
										ZVAL_STRING(&_134$$25, "^%s$");
										ZEPHIR_CALL_FUNCTION(&_135$$25, "sprintf", &_38, 3, &_134$$25, &regexKey);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&regexKey, &_135$$25);
										ZEPHIR_CALL_METHOD(NULL, &tree$$5, "setregex", &_136, 0, &regexKey);
										zephir_check_call_status();
										break;
									}
									if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
										ZEPHIR_INIT_NVAR(&newTree$$37);
										object_init_ex(&newTree$$37, moon_component_router_treenode_ce);
										if (zephir_has_constructor(&newTree$$37)) {
											ZEPHIR_CALL_METHOD(NULL, &newTree$$37, "__construct", &_137, 0);
											zephir_check_call_status();
										}
										ZEPHIR_INIT_NVAR(&_138$$37);
										object_init_ex(&_138$$37, moon_component_router_node_ce);
										ZEPHIR_CALL_METHOD(NULL, &_138$$37, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &newTree$$37, "setnode", &_78, 158, &_138$$37);
										zephir_check_call_status();
										zephir_update_property_array(&tree$$5, SL("children"), &item, &newTree$$37);
									} else {
										zephir_read_property(&_139$$38, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_OBS_NVAR(&_140$$38);
										zephir_array_fetch(&_140$$38, &_139$$38, &item, PH_NOISY, "moon/Component/Router/Router.zep", 350);
										if (ZEPHIR_IS_EMPTY(&_140$$38)) {
											ZEPHIR_INIT_NVAR(&_141$$39);
											object_init_ex(&_141$$39, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&_141$$39)) {
												ZEPHIR_CALL_METHOD(NULL, &_141$$39, "__construct", NULL, 0);
												zephir_check_call_status();
											}
											zephir_update_property_array(&tree$$5, SL("children"), &item, &_141$$39);
										}
										zephir_read_property(&_142$$38, &tree$$5, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										zephir_array_fetch(&_143$$38, &_142$$38, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 353);
										ZEPHIR_CPY_WRT(&tree$$5, &_143$$38);
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
						ZEPHIR_INIT_NVAR(&_144$$40);
						object_init_ex(&_144$$40, moon_component_router_node_ce);
						ZEPHIR_CALL_METHOD(NULL, &_144$$40, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &tree$$5, "setnode", &_145, 0, &_144$$40);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(&_146$$5);
					zephir_create_array(&_146$$5, 5, 0);
					zephir_array_update_string(&_146$$5, SL("method"), &method$$4, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_146$$5, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_146$$5, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_146$$5, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_146$$5, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_147$$5);
					ZVAL_STRING(&_147$$5, "%s_%s");
					ZEPHIR_CALL_FUNCTION(&_148$$5, "sprintf", &_38, 3, &_147$$5, &method$$4, &routeName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("routes"), &_148$$5, &_146$$5);
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
						zephir_read_property(&_149$$41, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
						if (!(zephir_array_isset(&_149$$41, &method$$4))) {
							ZEPHIR_INIT_NVAR(&_150$$42);
							object_init_ex(&_150$$42, moon_component_router_treenode_ce);
							if (zephir_has_constructor(&_150$$42)) {
								ZEPHIR_CALL_METHOD(NULL, &_150$$42, "__construct", NULL, 0);
								zephir_check_call_status();
							}
							zephir_update_property_array(this_ptr, SL("nodes"), &method$$4, &_150$$42);
						}
						ZEPHIR_CALL_METHOD(&_151$$41, this_ptr, "generateroutename", &_11, 156, &routeName, &method$$4, &uri);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&routeName, &_151$$41);
						zephir_read_property(&_152$$41, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&tree$$41);
						zephir_array_fetch(&tree$$41, &_152$$41, &method$$4, PH_NOISY, "moon/Component/Router/Router.zep", 291);
						ZEPHIR_INIT_NVAR(&_153$$41);
						zephir_fast_explode_str(&_153$$41, SL("/"), &uri, LONG_MAX);
						ZEPHIR_CALL_FUNCTION(&_151$$41, "array_filter", &_14, 95, &_153$$41);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_15, 75, &_151$$41);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&length);
						ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
						if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
							zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 356);
							if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uriArr), _156$$43, _157$$43, _154$$43)
								{
									ZEPHIR_INIT_NVAR(&i);
									if (_157$$43 != NULL) { 
										ZVAL_STR_COPY(&i, _157$$43);
									} else {
										ZVAL_LONG(&i, _156$$43);
									}
									ZEPHIR_INIT_NVAR(&item);
									ZVAL_COPY(&item, _154$$43);
									ZVAL_LONG(&_158$$44, 0);
									ZVAL_LONG(&_159$$44, 1);
									ZEPHIR_INIT_NVAR(&_160$$44);
									zephir_substr(&_160$$44, &item, 0 , 1 , 0);
									ZEPHIR_INIT_NVAR(&_161$$44);
									ZVAL_STRING(&_161$$44, "{");
									if (ZEPHIR_IS_EQUAL(&_161$$44, &_160$$44)) {
										ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&regexKey);
										ZVAL_STRING(&regexKey, "");
										zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 322);
										if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _162$$45)
											{
												ZEPHIR_INIT_NVAR(&re$$45);
												ZVAL_COPY(&re$$45, _162$$45);
												ZVAL_LONG(&_164$$46, 0);
												ZVAL_LONG(&_165$$46, 1);
												ZEPHIR_INIT_NVAR(&_166$$46);
												zephir_substr(&_166$$46, &re$$45, 0 , 1 , 0);
												ZEPHIR_INIT_NVAR(&_167$$46);
												ZVAL_STRING(&_167$$46, "{");
												if (ZEPHIR_IS_EQUAL(&_167$$46, &_166$$46)) {
													ZEPHIR_INIT_NVAR(&_168$$47);
													ZVAL_STRING(&_168$$47, "<");
													ZEPHIR_INIT_NVAR(&regexPos);
													zephir_fast_strpos(&regexPos, &re$$45, &_168$$47, 0 );
													ZEPHIR_INIT_NVAR(&formatStr);
													ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
													if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
														ZVAL_LONG(&_169$$48, 1);
														ZVAL_LONG(&_170$$48, -1);
														ZEPHIR_INIT_NVAR(&_171$$48);
														zephir_substr(&_171$$48, &re$$45, 1 , -1 , 0);
														ZEPHIR_INIT_NVAR(&_172$$48);
														ZVAL_STRING(&_172$$48, "___");
														ZEPHIR_INIT_NVAR(&_173$$48);
														ZVAL_STRING(&_173$$48, "[^/]+");
														ZEPHIR_CALL_FUNCTION(&_174$$48, "sprintf", &_38, 3, &formatStr, &_171$$48, &_172$$48, &routeName, &_173$$48);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_174$$48);
													} else {
														ZVAL_LONG(&_175$$49, 1);
														ZVAL_LONG(&_176$$49, (zephir_get_numberval(&regexPos) - 1));
														ZEPHIR_INIT_NVAR(&_177$$49);
														zephir_substr(&_177$$49, &re$$45, 1 , zephir_get_intval(&_176$$49), 0);
														ZVAL_LONG(&_178$$49, (zephir_get_numberval(&regexPos) + 1));
														ZVAL_LONG(&_179$$49, -2);
														ZEPHIR_INIT_NVAR(&_180$$49);
														zephir_substr(&_180$$49, &re$$45, zephir_get_intval(&_178$$49), -2 , 0);
														ZEPHIR_INIT_NVAR(&_181$$49);
														ZVAL_STRING(&_181$$49, "___");
														ZEPHIR_CALL_FUNCTION(&_182$$49, "sprintf", &_38, 3, &formatStr, &_177$$49, &_181$$49, &routeName, &_180$$49);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_182$$49);
													}
												} else {
													ZEPHIR_INIT_NVAR(&_183$$50);
													ZEPHIR_CONCAT_SV(&_183$$50, "/", &re$$45);
													zephir_concat_self(&regexKey, &_183$$50);
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_163$$45, &regexArr, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_163$$45)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&re$$45, &regexArr, "current", NULL, 0);
												zephir_check_call_status();
													ZVAL_LONG(&_184$$51, 0);
													ZVAL_LONG(&_185$$51, 1);
													ZEPHIR_INIT_NVAR(&_186$$51);
													zephir_substr(&_186$$51, &re$$45, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_187$$51);
													ZVAL_STRING(&_187$$51, "{");
													if (ZEPHIR_IS_EQUAL(&_187$$51, &_186$$51)) {
														ZEPHIR_INIT_NVAR(&_188$$52);
														ZVAL_STRING(&_188$$52, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$45, &_188$$52, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_189$$53, 1);
															ZVAL_LONG(&_190$$53, -1);
															ZEPHIR_INIT_NVAR(&_191$$53);
															zephir_substr(&_191$$53, &re$$45, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_192$$53);
															ZVAL_STRING(&_192$$53, "___");
															ZEPHIR_INIT_NVAR(&_193$$53);
															ZVAL_STRING(&_193$$53, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_194$$53, "sprintf", &_38, 3, &formatStr, &_191$$53, &_192$$53, &routeName, &_193$$53);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_194$$53);
														} else {
															ZVAL_LONG(&_195$$54, 1);
															ZVAL_LONG(&_196$$54, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_197$$54);
															zephir_substr(&_197$$54, &re$$45, 1 , zephir_get_intval(&_196$$54), 0);
															ZVAL_LONG(&_198$$54, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_199$$54, -2);
															ZEPHIR_INIT_NVAR(&_200$$54);
															zephir_substr(&_200$$54, &re$$45, zephir_get_intval(&_198$$54), -2 , 0);
															ZEPHIR_INIT_NVAR(&_201$$54);
															ZVAL_STRING(&_201$$54, "___");
															ZEPHIR_CALL_FUNCTION(&_202$$54, "sprintf", &_38, 3, &formatStr, &_197$$54, &_201$$54, &routeName, &_200$$54);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_202$$54);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_203$$55);
														ZEPHIR_CONCAT_SV(&_203$$55, "/", &re$$45);
														zephir_concat_self(&regexKey, &_203$$55);
													}
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&re$$45);
										ZVAL_LONG(&_204$$45, -1);
										ZVAL_LONG(&_205$$45, 1);
										ZEPHIR_INIT_NVAR(&_206$$45);
										zephir_substr(&_206$$45, &regexKey, -1 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_207$$45);
										ZVAL_STRING(&_207$$45, ")");
										if (!ZEPHIR_IS_EQUAL(&_207$$45, &_206$$45)) {
											zephir_concat_self_str(&regexKey, SL("\\b"));
										}
										ZEPHIR_INIT_NVAR(&_208$$45);
										ZVAL_STRING(&_208$$45, "^%s$");
										ZEPHIR_CALL_FUNCTION(&_209$$45, "sprintf", &_38, 3, &_208$$45, &regexKey);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&regexKey, &_209$$45);
										ZEPHIR_CALL_METHOD(NULL, &tree$$41, "setregex", &_210, 0, &regexKey);
										zephir_check_call_status();
										break;
									}
									if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
										ZEPHIR_INIT_NVAR(&newTree$$57);
										object_init_ex(&newTree$$57, moon_component_router_treenode_ce);
										if (zephir_has_constructor(&newTree$$57)) {
											ZEPHIR_CALL_METHOD(NULL, &newTree$$57, "__construct", &_211, 0);
											zephir_check_call_status();
										}
										ZEPHIR_INIT_NVAR(&_212$$57);
										object_init_ex(&_212$$57, moon_component_router_node_ce);
										ZEPHIR_CALL_METHOD(NULL, &_212$$57, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &newTree$$57, "setnode", &_78, 158, &_212$$57);
										zephir_check_call_status();
										zephir_update_property_array(&tree$$41, SL("children"), &item, &newTree$$57);
									} else {
										zephir_read_property(&_213$$58, &tree$$41, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_OBS_NVAR(&_214$$58);
										zephir_array_fetch(&_214$$58, &_213$$58, &item, PH_NOISY, "moon/Component/Router/Router.zep", 350);
										if (ZEPHIR_IS_EMPTY(&_214$$58)) {
											ZEPHIR_INIT_NVAR(&_215$$59);
											object_init_ex(&_215$$59, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&_215$$59)) {
												ZEPHIR_CALL_METHOD(NULL, &_215$$59, "__construct", NULL, 0);
												zephir_check_call_status();
											}
											zephir_update_property_array(&tree$$41, SL("children"), &item, &_215$$59);
										}
										zephir_read_property(&_216$$58, &tree$$41, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										zephir_array_fetch(&_217$$58, &_216$$58, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 353);
										ZEPHIR_CPY_WRT(&tree$$41, &_217$$58);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_155$$43, &uriArr, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_155$$43)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&i, &uriArr, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
									zephir_check_call_status();
										ZVAL_LONG(&_218$$60, 0);
										ZVAL_LONG(&_219$$60, 1);
										ZEPHIR_INIT_NVAR(&_220$$60);
										zephir_substr(&_220$$60, &item, 0 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_221$$60);
										ZVAL_STRING(&_221$$60, "{");
										if (ZEPHIR_IS_EQUAL(&_221$$60, &_220$$60)) {
											ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&regexKey);
											ZVAL_STRING(&regexKey, "");
											zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 322);
											if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _222$$61)
												{
													ZEPHIR_INIT_NVAR(&re$$61);
													ZVAL_COPY(&re$$61, _222$$61);
													ZVAL_LONG(&_224$$62, 0);
													ZVAL_LONG(&_225$$62, 1);
													ZEPHIR_INIT_NVAR(&_226$$62);
													zephir_substr(&_226$$62, &re$$61, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_227$$62);
													ZVAL_STRING(&_227$$62, "{");
													if (ZEPHIR_IS_EQUAL(&_227$$62, &_226$$62)) {
														ZEPHIR_INIT_NVAR(&_228$$63);
														ZVAL_STRING(&_228$$63, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$61, &_228$$63, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_229$$64, 1);
															ZVAL_LONG(&_230$$64, -1);
															ZEPHIR_INIT_NVAR(&_231$$64);
															zephir_substr(&_231$$64, &re$$61, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_232$$64);
															ZVAL_STRING(&_232$$64, "___");
															ZEPHIR_INIT_NVAR(&_233$$64);
															ZVAL_STRING(&_233$$64, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_234$$64, "sprintf", &_38, 3, &formatStr, &_231$$64, &_232$$64, &routeName, &_233$$64);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_234$$64);
														} else {
															ZVAL_LONG(&_235$$65, 1);
															ZVAL_LONG(&_236$$65, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_237$$65);
															zephir_substr(&_237$$65, &re$$61, 1 , zephir_get_intval(&_236$$65), 0);
															ZVAL_LONG(&_238$$65, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_239$$65, -2);
															ZEPHIR_INIT_NVAR(&_240$$65);
															zephir_substr(&_240$$65, &re$$61, zephir_get_intval(&_238$$65), -2 , 0);
															ZEPHIR_INIT_NVAR(&_241$$65);
															ZVAL_STRING(&_241$$65, "___");
															ZEPHIR_CALL_FUNCTION(&_242$$65, "sprintf", &_38, 3, &formatStr, &_237$$65, &_241$$65, &routeName, &_240$$65);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_242$$65);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_243$$66);
														ZEPHIR_CONCAT_SV(&_243$$66, "/", &re$$61);
														zephir_concat_self(&regexKey, &_243$$66);
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_223$$61, &regexArr, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_223$$61)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&re$$61, &regexArr, "current", NULL, 0);
													zephir_check_call_status();
														ZVAL_LONG(&_244$$67, 0);
														ZVAL_LONG(&_245$$67, 1);
														ZEPHIR_INIT_NVAR(&_246$$67);
														zephir_substr(&_246$$67, &re$$61, 0 , 1 , 0);
														ZEPHIR_INIT_NVAR(&_247$$67);
														ZVAL_STRING(&_247$$67, "{");
														if (ZEPHIR_IS_EQUAL(&_247$$67, &_246$$67)) {
															ZEPHIR_INIT_NVAR(&_248$$68);
															ZVAL_STRING(&_248$$68, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$61, &_248$$68, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_249$$69, 1);
																ZVAL_LONG(&_250$$69, -1);
																ZEPHIR_INIT_NVAR(&_251$$69);
																zephir_substr(&_251$$69, &re$$61, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_252$$69);
																ZVAL_STRING(&_252$$69, "___");
																ZEPHIR_INIT_NVAR(&_253$$69);
																ZVAL_STRING(&_253$$69, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_254$$69, "sprintf", &_38, 3, &formatStr, &_251$$69, &_252$$69, &routeName, &_253$$69);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_254$$69);
															} else {
																ZVAL_LONG(&_255$$70, 1);
																ZVAL_LONG(&_256$$70, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_257$$70);
																zephir_substr(&_257$$70, &re$$61, 1 , zephir_get_intval(&_256$$70), 0);
																ZVAL_LONG(&_258$$70, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_259$$70, -2);
																ZEPHIR_INIT_NVAR(&_260$$70);
																zephir_substr(&_260$$70, &re$$61, zephir_get_intval(&_258$$70), -2 , 0);
																ZEPHIR_INIT_NVAR(&_261$$70);
																ZVAL_STRING(&_261$$70, "___");
																ZEPHIR_CALL_FUNCTION(&_262$$70, "sprintf", &_38, 3, &formatStr, &_257$$70, &_261$$70, &routeName, &_260$$70);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_262$$70);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_263$$71);
															ZEPHIR_CONCAT_SV(&_263$$71, "/", &re$$61);
															zephir_concat_self(&regexKey, &_263$$71);
														}
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&re$$61);
											ZVAL_LONG(&_264$$61, -1);
											ZVAL_LONG(&_265$$61, 1);
											ZEPHIR_INIT_NVAR(&_266$$61);
											zephir_substr(&_266$$61, &regexKey, -1 , 1 , 0);
											ZEPHIR_INIT_NVAR(&_267$$61);
											ZVAL_STRING(&_267$$61, ")");
											if (!ZEPHIR_IS_EQUAL(&_267$$61, &_266$$61)) {
												zephir_concat_self_str(&regexKey, SL("\\b"));
											}
											ZEPHIR_INIT_NVAR(&_268$$61);
											ZVAL_STRING(&_268$$61, "^%s$");
											ZEPHIR_CALL_FUNCTION(&_269$$61, "sprintf", &_38, 3, &_268$$61, &regexKey);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&regexKey, &_269$$61);
											ZEPHIR_CALL_METHOD(NULL, &tree$$41, "setregex", &_270, 0, &regexKey);
											zephir_check_call_status();
											break;
										}
										if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
											ZEPHIR_INIT_NVAR(&newTree$$73);
											object_init_ex(&newTree$$73, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&newTree$$73)) {
												ZEPHIR_CALL_METHOD(NULL, &newTree$$73, "__construct", &_271, 0);
												zephir_check_call_status();
											}
											ZEPHIR_INIT_NVAR(&_272$$73);
											object_init_ex(&_272$$73, moon_component_router_node_ce);
											ZEPHIR_CALL_METHOD(NULL, &_272$$73, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
											zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, &newTree$$73, "setnode", &_78, 158, &_272$$73);
											zephir_check_call_status();
											zephir_update_property_array(&tree$$41, SL("children"), &item, &newTree$$73);
										} else {
											zephir_read_property(&_273$$74, &tree$$41, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											ZEPHIR_OBS_NVAR(&_274$$74);
											zephir_array_fetch(&_274$$74, &_273$$74, &item, PH_NOISY, "moon/Component/Router/Router.zep", 350);
											if (ZEPHIR_IS_EMPTY(&_274$$74)) {
												ZEPHIR_INIT_NVAR(&_275$$75);
												object_init_ex(&_275$$75, moon_component_router_treenode_ce);
												if (zephir_has_constructor(&_275$$75)) {
													ZEPHIR_CALL_METHOD(NULL, &_275$$75, "__construct", NULL, 0);
													zephir_check_call_status();
												}
												zephir_update_property_array(&tree$$41, SL("children"), &item, &_275$$75);
											}
											zephir_read_property(&_276$$74, &tree$$41, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											zephir_array_fetch(&_277$$74, &_276$$74, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 353);
											ZEPHIR_CPY_WRT(&tree$$41, &_277$$74);
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
							ZEPHIR_INIT_NVAR(&_278$$76);
							object_init_ex(&_278$$76, moon_component_router_node_ce);
							ZEPHIR_CALL_METHOD(NULL, &_278$$76, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &tree$$41, "setnode", &_279, 0, &_278$$76);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_280$$41);
						zephir_create_array(&_280$$41, 5, 0);
						zephir_array_update_string(&_280$$41, SL("method"), &method$$4, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_280$$41, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_280$$41, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_280$$41, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_280$$41, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_281$$41);
						ZVAL_STRING(&_281$$41, "%s_%s");
						ZEPHIR_CALL_FUNCTION(&_282$$41, "sprintf", &_38, 3, &_281$$41, &method$$4, &routeName);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("routes"), &_282$$41, &_280$$41);
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
				zephir_array_fetch_string(&methods, &router, SL("methods"), PH_NOISY, "moon/Component/Router/Router.zep", 271);
				ZEPHIR_OBS_NVAR(&uri);
				zephir_array_fetch_string(&uri, &router, SL("uri"), PH_NOISY, "moon/Component/Router/Router.zep", 272);
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_string(&handler, &router, SL("handler"), PH_NOISY, "moon/Component/Router/Router.zep", 273);
				ZEPHIR_OBS_NVAR(&routeName);
				zephir_array_fetch_string(&routeName, &router, SL("routeName"), PH_NOISY, "moon/Component/Router/Router.zep", 274);
				ZEPHIR_OBS_NVAR(&priority);
				zephir_array_fetch_string(&priority, &router, SL("priority"), PH_NOISY, "moon/Component/Router/Router.zep", 275);
				zephir_is_iterable(&methods, 0, "moon/Component/Router/Router.zep", 368);
				if (Z_TYPE_P(&methods) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _283$$77)
					{
						ZEPHIR_INIT_NVAR(&method$$77);
						ZVAL_COPY(&method$$77, _283$$77);
						zephir_read_property(&_285$$78, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
						if (!(zephir_array_isset(&_285$$78, &method$$77))) {
							ZEPHIR_INIT_NVAR(&_286$$79);
							object_init_ex(&_286$$79, moon_component_router_treenode_ce);
							if (zephir_has_constructor(&_286$$79)) {
								ZEPHIR_CALL_METHOD(NULL, &_286$$79, "__construct", NULL, 0);
								zephir_check_call_status();
							}
							zephir_update_property_array(this_ptr, SL("nodes"), &method$$77, &_286$$79);
						}
						ZEPHIR_CALL_METHOD(&_287$$78, this_ptr, "generateroutename", &_11, 156, &routeName, &method$$77, &uri);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&routeName, &_287$$78);
						zephir_read_property(&_288$$78, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&tree$$78);
						zephir_array_fetch(&tree$$78, &_288$$78, &method$$77, PH_NOISY, "moon/Component/Router/Router.zep", 291);
						ZEPHIR_INIT_NVAR(&_289$$78);
						zephir_fast_explode_str(&_289$$78, SL("/"), &uri, LONG_MAX);
						ZEPHIR_CALL_FUNCTION(&_287$$78, "array_filter", &_14, 95, &_289$$78);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_15, 75, &_287$$78);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&length);
						ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
						if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
							zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 356);
							if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uriArr), _292$$80, _293$$80, _290$$80)
								{
									ZEPHIR_INIT_NVAR(&i);
									if (_293$$80 != NULL) { 
										ZVAL_STR_COPY(&i, _293$$80);
									} else {
										ZVAL_LONG(&i, _292$$80);
									}
									ZEPHIR_INIT_NVAR(&item);
									ZVAL_COPY(&item, _290$$80);
									ZVAL_LONG(&_294$$81, 0);
									ZVAL_LONG(&_295$$81, 1);
									ZEPHIR_INIT_NVAR(&_296$$81);
									zephir_substr(&_296$$81, &item, 0 , 1 , 0);
									ZEPHIR_INIT_NVAR(&_297$$81);
									ZVAL_STRING(&_297$$81, "{");
									if (ZEPHIR_IS_EQUAL(&_297$$81, &_296$$81)) {
										ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&regexKey);
										ZVAL_STRING(&regexKey, "");
										zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 322);
										if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _298$$82)
											{
												ZEPHIR_INIT_NVAR(&re$$82);
												ZVAL_COPY(&re$$82, _298$$82);
												ZVAL_LONG(&_300$$83, 0);
												ZVAL_LONG(&_301$$83, 1);
												ZEPHIR_INIT_NVAR(&_302$$83);
												zephir_substr(&_302$$83, &re$$82, 0 , 1 , 0);
												ZEPHIR_INIT_NVAR(&_303$$83);
												ZVAL_STRING(&_303$$83, "{");
												if (ZEPHIR_IS_EQUAL(&_303$$83, &_302$$83)) {
													ZEPHIR_INIT_NVAR(&_304$$84);
													ZVAL_STRING(&_304$$84, "<");
													ZEPHIR_INIT_NVAR(&regexPos);
													zephir_fast_strpos(&regexPos, &re$$82, &_304$$84, 0 );
													ZEPHIR_INIT_NVAR(&formatStr);
													ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
													if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
														ZVAL_LONG(&_305$$85, 1);
														ZVAL_LONG(&_306$$85, -1);
														ZEPHIR_INIT_NVAR(&_307$$85);
														zephir_substr(&_307$$85, &re$$82, 1 , -1 , 0);
														ZEPHIR_INIT_NVAR(&_308$$85);
														ZVAL_STRING(&_308$$85, "___");
														ZEPHIR_INIT_NVAR(&_309$$85);
														ZVAL_STRING(&_309$$85, "[^/]+");
														ZEPHIR_CALL_FUNCTION(&_310$$85, "sprintf", &_38, 3, &formatStr, &_307$$85, &_308$$85, &routeName, &_309$$85);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_310$$85);
													} else {
														ZVAL_LONG(&_311$$86, 1);
														ZVAL_LONG(&_312$$86, (zephir_get_numberval(&regexPos) - 1));
														ZEPHIR_INIT_NVAR(&_313$$86);
														zephir_substr(&_313$$86, &re$$82, 1 , zephir_get_intval(&_312$$86), 0);
														ZVAL_LONG(&_314$$86, (zephir_get_numberval(&regexPos) + 1));
														ZVAL_LONG(&_315$$86, -2);
														ZEPHIR_INIT_NVAR(&_316$$86);
														zephir_substr(&_316$$86, &re$$82, zephir_get_intval(&_314$$86), -2 , 0);
														ZEPHIR_INIT_NVAR(&_317$$86);
														ZVAL_STRING(&_317$$86, "___");
														ZEPHIR_CALL_FUNCTION(&_318$$86, "sprintf", &_38, 3, &formatStr, &_313$$86, &_317$$86, &routeName, &_316$$86);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_318$$86);
													}
												} else {
													ZEPHIR_INIT_NVAR(&_319$$87);
													ZEPHIR_CONCAT_SV(&_319$$87, "/", &re$$82);
													zephir_concat_self(&regexKey, &_319$$87);
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_299$$82, &regexArr, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_299$$82)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&re$$82, &regexArr, "current", NULL, 0);
												zephir_check_call_status();
													ZVAL_LONG(&_320$$88, 0);
													ZVAL_LONG(&_321$$88, 1);
													ZEPHIR_INIT_NVAR(&_322$$88);
													zephir_substr(&_322$$88, &re$$82, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_323$$88);
													ZVAL_STRING(&_323$$88, "{");
													if (ZEPHIR_IS_EQUAL(&_323$$88, &_322$$88)) {
														ZEPHIR_INIT_NVAR(&_324$$89);
														ZVAL_STRING(&_324$$89, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$82, &_324$$89, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_325$$90, 1);
															ZVAL_LONG(&_326$$90, -1);
															ZEPHIR_INIT_NVAR(&_327$$90);
															zephir_substr(&_327$$90, &re$$82, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_328$$90);
															ZVAL_STRING(&_328$$90, "___");
															ZEPHIR_INIT_NVAR(&_329$$90);
															ZVAL_STRING(&_329$$90, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_330$$90, "sprintf", &_38, 3, &formatStr, &_327$$90, &_328$$90, &routeName, &_329$$90);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_330$$90);
														} else {
															ZVAL_LONG(&_331$$91, 1);
															ZVAL_LONG(&_332$$91, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_333$$91);
															zephir_substr(&_333$$91, &re$$82, 1 , zephir_get_intval(&_332$$91), 0);
															ZVAL_LONG(&_334$$91, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_335$$91, -2);
															ZEPHIR_INIT_NVAR(&_336$$91);
															zephir_substr(&_336$$91, &re$$82, zephir_get_intval(&_334$$91), -2 , 0);
															ZEPHIR_INIT_NVAR(&_337$$91);
															ZVAL_STRING(&_337$$91, "___");
															ZEPHIR_CALL_FUNCTION(&_338$$91, "sprintf", &_38, 3, &formatStr, &_333$$91, &_337$$91, &routeName, &_336$$91);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_338$$91);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_339$$92);
														ZEPHIR_CONCAT_SV(&_339$$92, "/", &re$$82);
														zephir_concat_self(&regexKey, &_339$$92);
													}
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&re$$82);
										ZVAL_LONG(&_340$$82, -1);
										ZVAL_LONG(&_341$$82, 1);
										ZEPHIR_INIT_NVAR(&_342$$82);
										zephir_substr(&_342$$82, &regexKey, -1 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_343$$82);
										ZVAL_STRING(&_343$$82, ")");
										if (!ZEPHIR_IS_EQUAL(&_343$$82, &_342$$82)) {
											zephir_concat_self_str(&regexKey, SL("\\b"));
										}
										ZEPHIR_INIT_NVAR(&_344$$82);
										ZVAL_STRING(&_344$$82, "^%s$");
										ZEPHIR_CALL_FUNCTION(&_345$$82, "sprintf", &_38, 3, &_344$$82, &regexKey);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&regexKey, &_345$$82);
										ZEPHIR_CALL_METHOD(NULL, &tree$$78, "setregex", &_346, 0, &regexKey);
										zephir_check_call_status();
										break;
									}
									if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
										ZEPHIR_INIT_NVAR(&newTree$$94);
										object_init_ex(&newTree$$94, moon_component_router_treenode_ce);
										if (zephir_has_constructor(&newTree$$94)) {
											ZEPHIR_CALL_METHOD(NULL, &newTree$$94, "__construct", &_347, 0);
											zephir_check_call_status();
										}
										ZEPHIR_INIT_NVAR(&_348$$94);
										object_init_ex(&_348$$94, moon_component_router_node_ce);
										ZEPHIR_CALL_METHOD(NULL, &_348$$94, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &newTree$$94, "setnode", &_78, 158, &_348$$94);
										zephir_check_call_status();
										zephir_update_property_array(&tree$$78, SL("children"), &item, &newTree$$94);
									} else {
										zephir_read_property(&_349$$95, &tree$$78, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_OBS_NVAR(&_350$$95);
										zephir_array_fetch(&_350$$95, &_349$$95, &item, PH_NOISY, "moon/Component/Router/Router.zep", 350);
										if (ZEPHIR_IS_EMPTY(&_350$$95)) {
											ZEPHIR_INIT_NVAR(&_351$$96);
											object_init_ex(&_351$$96, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&_351$$96)) {
												ZEPHIR_CALL_METHOD(NULL, &_351$$96, "__construct", NULL, 0);
												zephir_check_call_status();
											}
											zephir_update_property_array(&tree$$78, SL("children"), &item, &_351$$96);
										}
										zephir_read_property(&_352$$95, &tree$$78, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
										zephir_array_fetch(&_353$$95, &_352$$95, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 353);
										ZEPHIR_CPY_WRT(&tree$$78, &_353$$95);
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_291$$80, &uriArr, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_291$$80)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&i, &uriArr, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
									zephir_check_call_status();
										ZVAL_LONG(&_354$$97, 0);
										ZVAL_LONG(&_355$$97, 1);
										ZEPHIR_INIT_NVAR(&_356$$97);
										zephir_substr(&_356$$97, &item, 0 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_357$$97);
										ZVAL_STRING(&_357$$97, "{");
										if (ZEPHIR_IS_EQUAL(&_357$$97, &_356$$97)) {
											ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&regexKey);
											ZVAL_STRING(&regexKey, "");
											zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 322);
											if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _358$$98)
												{
													ZEPHIR_INIT_NVAR(&re$$98);
													ZVAL_COPY(&re$$98, _358$$98);
													ZVAL_LONG(&_360$$99, 0);
													ZVAL_LONG(&_361$$99, 1);
													ZEPHIR_INIT_NVAR(&_362$$99);
													zephir_substr(&_362$$99, &re$$98, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_363$$99);
													ZVAL_STRING(&_363$$99, "{");
													if (ZEPHIR_IS_EQUAL(&_363$$99, &_362$$99)) {
														ZEPHIR_INIT_NVAR(&_364$$100);
														ZVAL_STRING(&_364$$100, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$98, &_364$$100, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_365$$101, 1);
															ZVAL_LONG(&_366$$101, -1);
															ZEPHIR_INIT_NVAR(&_367$$101);
															zephir_substr(&_367$$101, &re$$98, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_368$$101);
															ZVAL_STRING(&_368$$101, "___");
															ZEPHIR_INIT_NVAR(&_369$$101);
															ZVAL_STRING(&_369$$101, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_370$$101, "sprintf", &_38, 3, &formatStr, &_367$$101, &_368$$101, &routeName, &_369$$101);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_370$$101);
														} else {
															ZVAL_LONG(&_371$$102, 1);
															ZVAL_LONG(&_372$$102, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_373$$102);
															zephir_substr(&_373$$102, &re$$98, 1 , zephir_get_intval(&_372$$102), 0);
															ZVAL_LONG(&_374$$102, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_375$$102, -2);
															ZEPHIR_INIT_NVAR(&_376$$102);
															zephir_substr(&_376$$102, &re$$98, zephir_get_intval(&_374$$102), -2 , 0);
															ZEPHIR_INIT_NVAR(&_377$$102);
															ZVAL_STRING(&_377$$102, "___");
															ZEPHIR_CALL_FUNCTION(&_378$$102, "sprintf", &_38, 3, &formatStr, &_373$$102, &_377$$102, &routeName, &_376$$102);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_378$$102);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_379$$103);
														ZEPHIR_CONCAT_SV(&_379$$103, "/", &re$$98);
														zephir_concat_self(&regexKey, &_379$$103);
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_359$$98, &regexArr, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_359$$98)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&re$$98, &regexArr, "current", NULL, 0);
													zephir_check_call_status();
														ZVAL_LONG(&_380$$104, 0);
														ZVAL_LONG(&_381$$104, 1);
														ZEPHIR_INIT_NVAR(&_382$$104);
														zephir_substr(&_382$$104, &re$$98, 0 , 1 , 0);
														ZEPHIR_INIT_NVAR(&_383$$104);
														ZVAL_STRING(&_383$$104, "{");
														if (ZEPHIR_IS_EQUAL(&_383$$104, &_382$$104)) {
															ZEPHIR_INIT_NVAR(&_384$$105);
															ZVAL_STRING(&_384$$105, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$98, &_384$$105, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_385$$106, 1);
																ZVAL_LONG(&_386$$106, -1);
																ZEPHIR_INIT_NVAR(&_387$$106);
																zephir_substr(&_387$$106, &re$$98, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_388$$106);
																ZVAL_STRING(&_388$$106, "___");
																ZEPHIR_INIT_NVAR(&_389$$106);
																ZVAL_STRING(&_389$$106, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_390$$106, "sprintf", &_38, 3, &formatStr, &_387$$106, &_388$$106, &routeName, &_389$$106);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_390$$106);
															} else {
																ZVAL_LONG(&_391$$107, 1);
																ZVAL_LONG(&_392$$107, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_393$$107);
																zephir_substr(&_393$$107, &re$$98, 1 , zephir_get_intval(&_392$$107), 0);
																ZVAL_LONG(&_394$$107, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_395$$107, -2);
																ZEPHIR_INIT_NVAR(&_396$$107);
																zephir_substr(&_396$$107, &re$$98, zephir_get_intval(&_394$$107), -2 , 0);
																ZEPHIR_INIT_NVAR(&_397$$107);
																ZVAL_STRING(&_397$$107, "___");
																ZEPHIR_CALL_FUNCTION(&_398$$107, "sprintf", &_38, 3, &formatStr, &_393$$107, &_397$$107, &routeName, &_396$$107);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_398$$107);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_399$$108);
															ZEPHIR_CONCAT_SV(&_399$$108, "/", &re$$98);
															zephir_concat_self(&regexKey, &_399$$108);
														}
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&re$$98);
											ZVAL_LONG(&_400$$98, -1);
											ZVAL_LONG(&_401$$98, 1);
											ZEPHIR_INIT_NVAR(&_402$$98);
											zephir_substr(&_402$$98, &regexKey, -1 , 1 , 0);
											ZEPHIR_INIT_NVAR(&_403$$98);
											ZVAL_STRING(&_403$$98, ")");
											if (!ZEPHIR_IS_EQUAL(&_403$$98, &_402$$98)) {
												zephir_concat_self_str(&regexKey, SL("\\b"));
											}
											ZEPHIR_INIT_NVAR(&_404$$98);
											ZVAL_STRING(&_404$$98, "^%s$");
											ZEPHIR_CALL_FUNCTION(&_405$$98, "sprintf", &_38, 3, &_404$$98, &regexKey);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&regexKey, &_405$$98);
											ZEPHIR_CALL_METHOD(NULL, &tree$$78, "setregex", &_406, 0, &regexKey);
											zephir_check_call_status();
											break;
										}
										if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
											ZEPHIR_INIT_NVAR(&newTree$$110);
											object_init_ex(&newTree$$110, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&newTree$$110)) {
												ZEPHIR_CALL_METHOD(NULL, &newTree$$110, "__construct", &_407, 0);
												zephir_check_call_status();
											}
											ZEPHIR_INIT_NVAR(&_408$$110);
											object_init_ex(&_408$$110, moon_component_router_node_ce);
											ZEPHIR_CALL_METHOD(NULL, &_408$$110, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
											zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, &newTree$$110, "setnode", &_78, 158, &_408$$110);
											zephir_check_call_status();
											zephir_update_property_array(&tree$$78, SL("children"), &item, &newTree$$110);
										} else {
											zephir_read_property(&_409$$111, &tree$$78, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											ZEPHIR_OBS_NVAR(&_410$$111);
											zephir_array_fetch(&_410$$111, &_409$$111, &item, PH_NOISY, "moon/Component/Router/Router.zep", 350);
											if (ZEPHIR_IS_EMPTY(&_410$$111)) {
												ZEPHIR_INIT_NVAR(&_411$$112);
												object_init_ex(&_411$$112, moon_component_router_treenode_ce);
												if (zephir_has_constructor(&_411$$112)) {
													ZEPHIR_CALL_METHOD(NULL, &_411$$112, "__construct", NULL, 0);
													zephir_check_call_status();
												}
												zephir_update_property_array(&tree$$78, SL("children"), &item, &_411$$112);
											}
											zephir_read_property(&_412$$111, &tree$$78, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											zephir_array_fetch(&_413$$111, &_412$$111, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 353);
											ZEPHIR_CPY_WRT(&tree$$78, &_413$$111);
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
							ZEPHIR_INIT_NVAR(&_414$$113);
							object_init_ex(&_414$$113, moon_component_router_node_ce);
							ZEPHIR_CALL_METHOD(NULL, &_414$$113, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &tree$$78, "setnode", &_415, 0, &_414$$113);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_416$$78);
						zephir_create_array(&_416$$78, 5, 0);
						zephir_array_update_string(&_416$$78, SL("method"), &method$$77, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_416$$78, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_416$$78, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_416$$78, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_416$$78, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_417$$78);
						ZVAL_STRING(&_417$$78, "%s_%s");
						ZEPHIR_CALL_FUNCTION(&_418$$78, "sprintf", &_38, 3, &_417$$78, &method$$77, &routeName);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("routes"), &_418$$78, &_416$$78);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_284$$77, &methods, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_284$$77)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&method$$77, &methods, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property(&_419$$114, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
							if (!(zephir_array_isset(&_419$$114, &method$$77))) {
								ZEPHIR_INIT_NVAR(&_420$$115);
								object_init_ex(&_420$$115, moon_component_router_treenode_ce);
								if (zephir_has_constructor(&_420$$115)) {
									ZEPHIR_CALL_METHOD(NULL, &_420$$115, "__construct", NULL, 0);
									zephir_check_call_status();
								}
								zephir_update_property_array(this_ptr, SL("nodes"), &method$$77, &_420$$115);
							}
							ZEPHIR_CALL_METHOD(&_421$$114, this_ptr, "generateroutename", &_11, 156, &routeName, &method$$77, &uri);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&routeName, &_421$$114);
							zephir_read_property(&_422$$114, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&tree$$114);
							zephir_array_fetch(&tree$$114, &_422$$114, &method$$77, PH_NOISY, "moon/Component/Router/Router.zep", 291);
							ZEPHIR_INIT_NVAR(&_423$$114);
							zephir_fast_explode_str(&_423$$114, SL("/"), &uri, LONG_MAX);
							ZEPHIR_CALL_FUNCTION(&_421$$114, "array_filter", &_14, 95, &_423$$114);
							zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_15, 75, &_421$$114);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&length);
							ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
							if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
								zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 356);
								if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
									ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uriArr), _426$$116, _427$$116, _424$$116)
									{
										ZEPHIR_INIT_NVAR(&i);
										if (_427$$116 != NULL) { 
											ZVAL_STR_COPY(&i, _427$$116);
										} else {
											ZVAL_LONG(&i, _426$$116);
										}
										ZEPHIR_INIT_NVAR(&item);
										ZVAL_COPY(&item, _424$$116);
										ZVAL_LONG(&_428$$117, 0);
										ZVAL_LONG(&_429$$117, 1);
										ZEPHIR_INIT_NVAR(&_430$$117);
										zephir_substr(&_430$$117, &item, 0 , 1 , 0);
										ZEPHIR_INIT_NVAR(&_431$$117);
										ZVAL_STRING(&_431$$117, "{");
										if (ZEPHIR_IS_EQUAL(&_431$$117, &_430$$117)) {
											ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&regexKey);
											ZVAL_STRING(&regexKey, "");
											zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 322);
											if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _432$$118)
												{
													ZEPHIR_INIT_NVAR(&re$$118);
													ZVAL_COPY(&re$$118, _432$$118);
													ZVAL_LONG(&_434$$119, 0);
													ZVAL_LONG(&_435$$119, 1);
													ZEPHIR_INIT_NVAR(&_436$$119);
													zephir_substr(&_436$$119, &re$$118, 0 , 1 , 0);
													ZEPHIR_INIT_NVAR(&_437$$119);
													ZVAL_STRING(&_437$$119, "{");
													if (ZEPHIR_IS_EQUAL(&_437$$119, &_436$$119)) {
														ZEPHIR_INIT_NVAR(&_438$$120);
														ZVAL_STRING(&_438$$120, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$118, &_438$$120, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_439$$121, 1);
															ZVAL_LONG(&_440$$121, -1);
															ZEPHIR_INIT_NVAR(&_441$$121);
															zephir_substr(&_441$$121, &re$$118, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_442$$121);
															ZVAL_STRING(&_442$$121, "___");
															ZEPHIR_INIT_NVAR(&_443$$121);
															ZVAL_STRING(&_443$$121, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_444$$121, "sprintf", &_38, 3, &formatStr, &_441$$121, &_442$$121, &routeName, &_443$$121);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_444$$121);
														} else {
															ZVAL_LONG(&_445$$122, 1);
															ZVAL_LONG(&_446$$122, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_447$$122);
															zephir_substr(&_447$$122, &re$$118, 1 , zephir_get_intval(&_446$$122), 0);
															ZVAL_LONG(&_448$$122, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_449$$122, -2);
															ZEPHIR_INIT_NVAR(&_450$$122);
															zephir_substr(&_450$$122, &re$$118, zephir_get_intval(&_448$$122), -2 , 0);
															ZEPHIR_INIT_NVAR(&_451$$122);
															ZVAL_STRING(&_451$$122, "___");
															ZEPHIR_CALL_FUNCTION(&_452$$122, "sprintf", &_38, 3, &formatStr, &_447$$122, &_451$$122, &routeName, &_450$$122);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_452$$122);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_453$$123);
														ZEPHIR_CONCAT_SV(&_453$$123, "/", &re$$118);
														zephir_concat_self(&regexKey, &_453$$123);
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_433$$118, &regexArr, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_433$$118)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&re$$118, &regexArr, "current", NULL, 0);
													zephir_check_call_status();
														ZVAL_LONG(&_454$$124, 0);
														ZVAL_LONG(&_455$$124, 1);
														ZEPHIR_INIT_NVAR(&_456$$124);
														zephir_substr(&_456$$124, &re$$118, 0 , 1 , 0);
														ZEPHIR_INIT_NVAR(&_457$$124);
														ZVAL_STRING(&_457$$124, "{");
														if (ZEPHIR_IS_EQUAL(&_457$$124, &_456$$124)) {
															ZEPHIR_INIT_NVAR(&_458$$125);
															ZVAL_STRING(&_458$$125, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$118, &_458$$125, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_459$$126, 1);
																ZVAL_LONG(&_460$$126, -1);
																ZEPHIR_INIT_NVAR(&_461$$126);
																zephir_substr(&_461$$126, &re$$118, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_462$$126);
																ZVAL_STRING(&_462$$126, "___");
																ZEPHIR_INIT_NVAR(&_463$$126);
																ZVAL_STRING(&_463$$126, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_464$$126, "sprintf", &_38, 3, &formatStr, &_461$$126, &_462$$126, &routeName, &_463$$126);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_464$$126);
															} else {
																ZVAL_LONG(&_465$$127, 1);
																ZVAL_LONG(&_466$$127, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_467$$127);
																zephir_substr(&_467$$127, &re$$118, 1 , zephir_get_intval(&_466$$127), 0);
																ZVAL_LONG(&_468$$127, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_469$$127, -2);
																ZEPHIR_INIT_NVAR(&_470$$127);
																zephir_substr(&_470$$127, &re$$118, zephir_get_intval(&_468$$127), -2 , 0);
																ZEPHIR_INIT_NVAR(&_471$$127);
																ZVAL_STRING(&_471$$127, "___");
																ZEPHIR_CALL_FUNCTION(&_472$$127, "sprintf", &_38, 3, &formatStr, &_467$$127, &_471$$127, &routeName, &_470$$127);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_472$$127);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_473$$128);
															ZEPHIR_CONCAT_SV(&_473$$128, "/", &re$$118);
															zephir_concat_self(&regexKey, &_473$$128);
														}
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&re$$118);
											ZVAL_LONG(&_474$$118, -1);
											ZVAL_LONG(&_475$$118, 1);
											ZEPHIR_INIT_NVAR(&_476$$118);
											zephir_substr(&_476$$118, &regexKey, -1 , 1 , 0);
											ZEPHIR_INIT_NVAR(&_477$$118);
											ZVAL_STRING(&_477$$118, ")");
											if (!ZEPHIR_IS_EQUAL(&_477$$118, &_476$$118)) {
												zephir_concat_self_str(&regexKey, SL("\\b"));
											}
											ZEPHIR_INIT_NVAR(&_478$$118);
											ZVAL_STRING(&_478$$118, "^%s$");
											ZEPHIR_CALL_FUNCTION(&_479$$118, "sprintf", &_38, 3, &_478$$118, &regexKey);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&regexKey, &_479$$118);
											ZEPHIR_CALL_METHOD(NULL, &tree$$114, "setregex", &_480, 0, &regexKey);
											zephir_check_call_status();
											break;
										}
										if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
											ZEPHIR_INIT_NVAR(&newTree$$130);
											object_init_ex(&newTree$$130, moon_component_router_treenode_ce);
											if (zephir_has_constructor(&newTree$$130)) {
												ZEPHIR_CALL_METHOD(NULL, &newTree$$130, "__construct", &_481, 0);
												zephir_check_call_status();
											}
											ZEPHIR_INIT_NVAR(&_482$$130);
											object_init_ex(&_482$$130, moon_component_router_node_ce);
											ZEPHIR_CALL_METHOD(NULL, &_482$$130, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
											zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, &newTree$$130, "setnode", &_78, 158, &_482$$130);
											zephir_check_call_status();
											zephir_update_property_array(&tree$$114, SL("children"), &item, &newTree$$130);
										} else {
											zephir_read_property(&_483$$131, &tree$$114, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											ZEPHIR_OBS_NVAR(&_484$$131);
											zephir_array_fetch(&_484$$131, &_483$$131, &item, PH_NOISY, "moon/Component/Router/Router.zep", 350);
											if (ZEPHIR_IS_EMPTY(&_484$$131)) {
												ZEPHIR_INIT_NVAR(&_485$$132);
												object_init_ex(&_485$$132, moon_component_router_treenode_ce);
												if (zephir_has_constructor(&_485$$132)) {
													ZEPHIR_CALL_METHOD(NULL, &_485$$132, "__construct", NULL, 0);
													zephir_check_call_status();
												}
												zephir_update_property_array(&tree$$114, SL("children"), &item, &_485$$132);
											}
											zephir_read_property(&_486$$131, &tree$$114, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
											zephir_array_fetch(&_487$$131, &_486$$131, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 353);
											ZEPHIR_CPY_WRT(&tree$$114, &_487$$131);
										}
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_425$$116, &uriArr, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_425$$116)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&i, &uriArr, "key", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
										zephir_check_call_status();
											ZVAL_LONG(&_488$$133, 0);
											ZVAL_LONG(&_489$$133, 1);
											ZEPHIR_INIT_NVAR(&_490$$133);
											zephir_substr(&_490$$133, &item, 0 , 1 , 0);
											ZEPHIR_INIT_NVAR(&_491$$133);
											ZVAL_STRING(&_491$$133, "{");
											if (ZEPHIR_IS_EQUAL(&_491$$133, &_490$$133)) {
												ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_24, 157, &uriArr, &i);
												zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&regexKey);
												ZVAL_STRING(&regexKey, "");
												zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 322);
												if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
													ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _492$$134)
													{
														ZEPHIR_INIT_NVAR(&re$$134);
														ZVAL_COPY(&re$$134, _492$$134);
														ZVAL_LONG(&_494$$135, 0);
														ZVAL_LONG(&_495$$135, 1);
														ZEPHIR_INIT_NVAR(&_496$$135);
														zephir_substr(&_496$$135, &re$$134, 0 , 1 , 0);
														ZEPHIR_INIT_NVAR(&_497$$135);
														ZVAL_STRING(&_497$$135, "{");
														if (ZEPHIR_IS_EQUAL(&_497$$135, &_496$$135)) {
															ZEPHIR_INIT_NVAR(&_498$$136);
															ZVAL_STRING(&_498$$136, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$134, &_498$$136, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_499$$137, 1);
																ZVAL_LONG(&_500$$137, -1);
																ZEPHIR_INIT_NVAR(&_501$$137);
																zephir_substr(&_501$$137, &re$$134, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_502$$137);
																ZVAL_STRING(&_502$$137, "___");
																ZEPHIR_INIT_NVAR(&_503$$137);
																ZVAL_STRING(&_503$$137, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_504$$137, "sprintf", &_38, 3, &formatStr, &_501$$137, &_502$$137, &routeName, &_503$$137);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_504$$137);
															} else {
																ZVAL_LONG(&_505$$138, 1);
																ZVAL_LONG(&_506$$138, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_507$$138);
																zephir_substr(&_507$$138, &re$$134, 1 , zephir_get_intval(&_506$$138), 0);
																ZVAL_LONG(&_508$$138, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_509$$138, -2);
																ZEPHIR_INIT_NVAR(&_510$$138);
																zephir_substr(&_510$$138, &re$$134, zephir_get_intval(&_508$$138), -2 , 0);
																ZEPHIR_INIT_NVAR(&_511$$138);
																ZVAL_STRING(&_511$$138, "___");
																ZEPHIR_CALL_FUNCTION(&_512$$138, "sprintf", &_38, 3, &formatStr, &_507$$138, &_511$$138, &routeName, &_510$$138);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_512$$138);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_513$$139);
															ZEPHIR_CONCAT_SV(&_513$$139, "/", &re$$134);
															zephir_concat_self(&regexKey, &_513$$139);
														}
													} ZEND_HASH_FOREACH_END();
												} else {
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
													zephir_check_call_status();
													while (1) {
														ZEPHIR_CALL_METHOD(&_493$$134, &regexArr, "valid", NULL, 0);
														zephir_check_call_status();
														if (!zend_is_true(&_493$$134)) {
															break;
														}
														ZEPHIR_CALL_METHOD(&re$$134, &regexArr, "current", NULL, 0);
														zephir_check_call_status();
															ZVAL_LONG(&_514$$140, 0);
															ZVAL_LONG(&_515$$140, 1);
															ZEPHIR_INIT_NVAR(&_516$$140);
															zephir_substr(&_516$$140, &re$$134, 0 , 1 , 0);
															ZEPHIR_INIT_NVAR(&_517$$140);
															ZVAL_STRING(&_517$$140, "{");
															if (ZEPHIR_IS_EQUAL(&_517$$140, &_516$$140)) {
																ZEPHIR_INIT_NVAR(&_518$$141);
																ZVAL_STRING(&_518$$141, "<");
																ZEPHIR_INIT_NVAR(&regexPos);
																zephir_fast_strpos(&regexPos, &re$$134, &_518$$141, 0 );
																ZEPHIR_INIT_NVAR(&formatStr);
																ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
																if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																	ZVAL_LONG(&_519$$142, 1);
																	ZVAL_LONG(&_520$$142, -1);
																	ZEPHIR_INIT_NVAR(&_521$$142);
																	zephir_substr(&_521$$142, &re$$134, 1 , -1 , 0);
																	ZEPHIR_INIT_NVAR(&_522$$142);
																	ZVAL_STRING(&_522$$142, "___");
																	ZEPHIR_INIT_NVAR(&_523$$142);
																	ZVAL_STRING(&_523$$142, "[^/]+");
																	ZEPHIR_CALL_FUNCTION(&_524$$142, "sprintf", &_38, 3, &formatStr, &_521$$142, &_522$$142, &routeName, &_523$$142);
																	zephir_check_call_status();
																	zephir_concat_self(&regexKey, &_524$$142);
																} else {
																	ZVAL_LONG(&_525$$143, 1);
																	ZVAL_LONG(&_526$$143, (zephir_get_numberval(&regexPos) - 1));
																	ZEPHIR_INIT_NVAR(&_527$$143);
																	zephir_substr(&_527$$143, &re$$134, 1 , zephir_get_intval(&_526$$143), 0);
																	ZVAL_LONG(&_528$$143, (zephir_get_numberval(&regexPos) + 1));
																	ZVAL_LONG(&_529$$143, -2);
																	ZEPHIR_INIT_NVAR(&_530$$143);
																	zephir_substr(&_530$$143, &re$$134, zephir_get_intval(&_528$$143), -2 , 0);
																	ZEPHIR_INIT_NVAR(&_531$$143);
																	ZVAL_STRING(&_531$$143, "___");
																	ZEPHIR_CALL_FUNCTION(&_532$$143, "sprintf", &_38, 3, &formatStr, &_527$$143, &_531$$143, &routeName, &_530$$143);
																	zephir_check_call_status();
																	zephir_concat_self(&regexKey, &_532$$143);
																}
															} else {
																ZEPHIR_INIT_NVAR(&_533$$144);
																ZEPHIR_CONCAT_SV(&_533$$144, "/", &re$$134);
																zephir_concat_self(&regexKey, &_533$$144);
															}
														ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
														zephir_check_call_status();
													}
												}
												ZEPHIR_INIT_NVAR(&re$$134);
												ZVAL_LONG(&_534$$134, -1);
												ZVAL_LONG(&_535$$134, 1);
												ZEPHIR_INIT_NVAR(&_536$$134);
												zephir_substr(&_536$$134, &regexKey, -1 , 1 , 0);
												ZEPHIR_INIT_NVAR(&_537$$134);
												ZVAL_STRING(&_537$$134, ")");
												if (!ZEPHIR_IS_EQUAL(&_537$$134, &_536$$134)) {
													zephir_concat_self_str(&regexKey, SL("\\b"));
												}
												ZEPHIR_INIT_NVAR(&_538$$134);
												ZVAL_STRING(&_538$$134, "^%s$");
												ZEPHIR_CALL_FUNCTION(&_539$$134, "sprintf", &_38, 3, &_538$$134, &regexKey);
												zephir_check_call_status();
												ZEPHIR_CPY_WRT(&regexKey, &_539$$134);
												ZEPHIR_CALL_METHOD(NULL, &tree$$114, "setregex", &_540, 0, &regexKey);
												zephir_check_call_status();
												break;
											}
											if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
												ZEPHIR_INIT_NVAR(&newTree$$146);
												object_init_ex(&newTree$$146, moon_component_router_treenode_ce);
												if (zephir_has_constructor(&newTree$$146)) {
													ZEPHIR_CALL_METHOD(NULL, &newTree$$146, "__construct", &_541, 0);
													zephir_check_call_status();
												}
												ZEPHIR_INIT_NVAR(&_542$$146);
												object_init_ex(&_542$$146, moon_component_router_node_ce);
												ZEPHIR_CALL_METHOD(NULL, &_542$$146, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
												zephir_check_call_status();
												ZEPHIR_CALL_METHOD(NULL, &newTree$$146, "setnode", &_78, 158, &_542$$146);
												zephir_check_call_status();
												zephir_update_property_array(&tree$$114, SL("children"), &item, &newTree$$146);
											} else {
												zephir_read_property(&_543$$147, &tree$$114, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
												ZEPHIR_OBS_NVAR(&_544$$147);
												zephir_array_fetch(&_544$$147, &_543$$147, &item, PH_NOISY, "moon/Component/Router/Router.zep", 350);
												if (ZEPHIR_IS_EMPTY(&_544$$147)) {
													ZEPHIR_INIT_NVAR(&_545$$148);
													object_init_ex(&_545$$148, moon_component_router_treenode_ce);
													if (zephir_has_constructor(&_545$$148)) {
														ZEPHIR_CALL_METHOD(NULL, &_545$$148, "__construct", NULL, 0);
														zephir_check_call_status();
													}
													zephir_update_property_array(&tree$$114, SL("children"), &item, &_545$$148);
												}
												zephir_read_property(&_546$$147, &tree$$114, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
												zephir_array_fetch(&_547$$147, &_546$$147, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 353);
												ZEPHIR_CPY_WRT(&tree$$114, &_547$$147);
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
								ZEPHIR_INIT_NVAR(&_548$$149);
								object_init_ex(&_548$$149, moon_component_router_node_ce);
								ZEPHIR_CALL_METHOD(NULL, &_548$$149, "__construct", &_77, 154, &uri, &handler, &routeName, &priority);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &tree$$114, "setnode", &_549, 0, &_548$$149);
								zephir_check_call_status();
							}
							ZEPHIR_INIT_NVAR(&_550$$114);
							zephir_create_array(&_550$$114, 5, 0);
							zephir_array_update_string(&_550$$114, SL("method"), &method$$77, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_550$$114, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_550$$114, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_550$$114, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_550$$114, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_551$$114);
							ZVAL_STRING(&_551$$114, "%s_%s");
							ZEPHIR_CALL_FUNCTION(&_552$$114, "sprintf", &_38, 3, &_551$$114, &method$$77, &routeName);
							zephir_check_call_status();
							zephir_update_property_array(this_ptr, SL("routes"), &_552$$114, &_550$$114);
						ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&method$$77);
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

