
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
#include "kernel/math.h"


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
	zval routeName, _3$$3, _12$$5;
	zval *methods_param = NULL, uri, *uri_param = NULL, *handler, handler_sub, *routeName_param = NULL, *priority_param = NULL, method, *_0, _1, _17, _24, _25, _27, _2$$3, _4$$3, _7$$4, _8$$4, _9$$4, _11$$5, _13$$5, _14$$6, _15$$6, _16$$6, _18$$7, _19$$7, _20$$7, _21$$7, _22$$7, _23$$7;
	zval methods, _26;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
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


	zephir_is_iterable(&methods, 0, "moon/Component/Router/Router.zep", 63);
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
				ZEPHIR_CALL_FUNCTION(&_9$$4, "array_diff", &_10, 209, &methods, &_8$$4);
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
					ZEPHIR_CALL_FUNCTION(&_16$$6, "array_diff", &_10, 209, &methods, &_15$$6);
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
		ZEPHIR_CALL_FUNCTION(&uri, "sprintf", NULL, 3, &_23$$7, &_18$$7, &_21$$7);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_24);
	ZEPHIR_INIT_VAR(&_25);
	ZVAL_STRING(&_25, "/");
	zephir_fast_trim(&_24, &uri, &_25, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_CPY_WRT(&uri, &_24);
	ZEPHIR_INIT_VAR(&_26);
	zephir_create_array(&_26, 5, 0);
	zephir_array_update_string(&_26, SL("methods"), &methods, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_26, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_26, SL("handler"), handler, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_26, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_24);
	ZVAL_LONG(&_24, priority);
	zephir_array_update_string(&_26, SL("priority"), &_24, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_append(this_ptr, SL("routers"), &_26);
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

	zend_string *_36$$13, *_60$$21;
	zend_ulong _35$$13, _59$$21;
	zend_bool _9, _11, _19, _21, _37$$14, _42$$17, _61$$22, _66$$25;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_17 = NULL, *_30 = NULL, *_52 = NULL;
	zval *method_param = NULL, *uri_param = NULL, route, res, routeName, parameters, regex, nodesArr, nodesRegex, uriArr, nodes, _method, _0, _2, _5, _6, _7, _8, _10, _12, item, *_14, _15, _20, _22, _24, _3$$4, _4$$4, _13$$5, _16$$6, _18$$8, _23$$10, _25$$11, *_26$$11, _27$$11, _28$$12, _29$$12, match$$12, _31$$12, _32$$12, k$$13, m$$13, *_33$$13, _34$$13, _47$$13, _48$$13, _49$$13, _50$$13, _51$$13, _38$$14, _39$$14, _40$$16, _41$$16, _43$$17, _44$$17, _45$$19, _46$$19, _53$$20, _54$$20, match$$20, _55$$20, _56$$20, k$$21, m$$21, *_57$$21, _58$$21, _71$$21, _72$$21, _73$$21, _74$$21, _75$$21, _62$$22, _63$$22, _64$$24, _65$$24, _67$$25, _68$$25, _69$$27, _70$$27;
	zval method, uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&nodesArr);
	ZVAL_UNDEF(&nodesRegex);
	ZVAL_UNDEF(&uriArr);
	ZVAL_UNDEF(&nodes);
	ZVAL_UNDEF(&_method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&match$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&k$$13);
	ZVAL_UNDEF(&m$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_47$$13);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_49$$13);
	ZVAL_UNDEF(&_50$$13);
	ZVAL_UNDEF(&_51$$13);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_40$$16);
	ZVAL_UNDEF(&_41$$16);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$19);
	ZVAL_UNDEF(&_46$$19);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_54$$20);
	ZVAL_UNDEF(&match$$20);
	ZVAL_UNDEF(&_55$$20);
	ZVAL_UNDEF(&_56$$20);
	ZVAL_UNDEF(&k$$21);
	ZVAL_UNDEF(&m$$21);
	ZVAL_UNDEF(&_58$$21);
	ZVAL_UNDEF(&_71$$21);
	ZVAL_UNDEF(&_72$$21);
	ZVAL_UNDEF(&_73$$21);
	ZVAL_UNDEF(&_74$$21);
	ZVAL_UNDEF(&_75$$21);
	ZVAL_UNDEF(&_62$$22);
	ZVAL_UNDEF(&_63$$22);
	ZVAL_UNDEF(&_64$$24);
	ZVAL_UNDEF(&_65$$24);
	ZVAL_UNDEF(&_67$$25);
	ZVAL_UNDEF(&_68$$25);
	ZVAL_UNDEF(&_69$$27);
	ZVAL_UNDEF(&_70$$27);

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
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	if (!ZEPHIR_IS_EQUAL(&_2, &uri)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "/");
		zephir_fast_trim(&_3$$4, &uri, &_4$$4, ZEPHIR_TRIM_RIGHT);
		zephir_get_strval(&uri, &_3$$4);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &_method, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 175);
	ZEPHIR_CPY_WRT(&nodes, &_6);
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_explode_str(&_7, SL("/"), &uri, LONG_MAX);
	ZEPHIR_CALL_FUNCTION(&_8, "array_filter", NULL, 161, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", NULL, 98, &_8);
	zephir_check_call_status();
	_9 = zephir_fast_count_int(&uriArr) == 0;
	if (_9) {
		ZEPHIR_OBS_VAR(&_10);
		zephir_array_fetch_string(&_10, &nodes, SL("$index$"), PH_NOISY, "moon/Component/Router/Router.zep", 179);
		_9 = !(ZEPHIR_IS_EMPTY(&_10));
	}
	_11 = _9;
	if (_11) {
		ZEPHIR_OBS_VAR(&_12);
		zephir_array_fetch_string(&_12, &nodes, SL("$index$"), PH_NOISY, "moon/Component/Router/Router.zep", 179);
		_11 = zephir_instance_of_ev(&_12, moon_component_router_node_ce);
	}
	if (_11) {
		zephir_array_fetch_string(&_13$$5, &nodes, SL("$index$"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 180);
		RETURN_CTOR(&_13$$5);
	}
	zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 191);
	if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&uriArr), _14)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _14);
			if (!(zephir_array_isset(&nodes, &item))) {
				break;
			}
			zephir_array_fetch(&_16$$6, &nodes, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 187);
			ZEPHIR_CPY_WRT(&nodes, &_16$$6);
			ZEPHIR_MAKE_REF(&uriArr);
			ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_17, 169, &uriArr);
			ZEPHIR_UNREF(&uriArr);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_15, &uriArr, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_isset(&nodes, &item))) {
					break;
				}
				zephir_array_fetch(&_18$$8, &nodes, &item, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 187);
				ZEPHIR_CPY_WRT(&nodes, &_18$$8);
				ZEPHIR_MAKE_REF(&uriArr);
				ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_17, 169, &uriArr);
				ZEPHIR_UNREF(&uriArr);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &uriArr, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	_19 = zephir_fast_count_int(&uriArr) == 0;
	if (_19) {
		ZEPHIR_OBS_VAR(&_20);
		zephir_array_fetch_string(&_20, &nodes, SL("$node$"), PH_NOISY, "moon/Component/Router/Router.zep", 191);
		_19 = !(ZEPHIR_IS_EMPTY(&_20));
	}
	_21 = _19;
	if (_21) {
		ZEPHIR_OBS_VAR(&_22);
		zephir_array_fetch_string(&_22, &nodes, SL("$node$"), PH_NOISY, "moon/Component/Router/Router.zep", 191);
		_21 = zephir_instance_of_ev(&_22, moon_component_router_node_ce);
	}
	if (_21) {
		zephir_array_fetch_string(&_23$$10, &nodes, SL("$node$"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 192);
		RETURN_CTOR(&_23$$10);
	}
	ZEPHIR_OBS_VAR(&_24);
	zephir_array_fetch_string(&_24, &nodes, SL("$regex$"), PH_NOISY, "moon/Component/Router/Router.zep", 194);
	if (!(ZEPHIR_IS_EMPTY(&_24))) {
		zephir_array_fetch_string(&_25$$11, &nodes, SL("$regex$"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 197);
		zephir_is_iterable(&_25$$11, 0, "moon/Component/Router/Router.zep", 236);
		if (Z_TYPE_P(&_25$$11) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_25$$11), _26$$11)
			{
				ZEPHIR_INIT_NVAR(&nodesRegex);
				ZVAL_COPY(&nodesRegex, _26$$11);
				ZEPHIR_INIT_NVAR(&nodesArr);
				zephir_array_keys(&nodesArr, &nodesRegex);
				ZEPHIR_INIT_NVAR(&_28$$12);
				zephir_fast_join_str(&_28$$12, SL("|"), &nodesArr);
				ZEPHIR_INIT_NVAR(&_29$$12);
				ZVAL_STRING(&_29$$12, "#%s#");
				ZEPHIR_CALL_FUNCTION(&regex, "sprintf", &_30, 3, &_29$$12, &_28$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_29$$12);
				zephir_fast_join_str(&_29$$12, SL("/"), &uriArr);
				ZEPHIR_INIT_NVAR(&_31$$12);
				ZEPHIR_CONCAT_SV(&_31$$12, "/", &_29$$12);
				ZEPHIR_INIT_NVAR(&_32$$12);
				zephir_preg_match(&_32$$12, &regex, &_31$$12, &match$$12, 0, 0 , 0 );
				if (zephir_is_true(&_32$$12)) {
					ZEPHIR_INIT_NVAR(&parameters);
					array_init(&parameters);
					ZEPHIR_INIT_NVAR(&routeName);
					ZVAL_STRING(&routeName, "");
					zephir_is_iterable(&match$$12, 0, "moon/Component/Router/Router.zep", 225);
					if (Z_TYPE_P(&match$$12) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&match$$12), _35$$13, _36$$13, _33$$13)
						{
							ZEPHIR_INIT_NVAR(&k$$13);
							if (_36$$13 != NULL) { 
								ZVAL_STR_COPY(&k$$13, _36$$13);
							} else {
								ZVAL_LONG(&k$$13, _35$$13);
							}
							ZEPHIR_INIT_NVAR(&m$$13);
							ZVAL_COPY(&m$$13, _33$$13);
							_37$$14 = Z_TYPE_P(&k$$13) == IS_STRING;
							if (_37$$14) {
								ZEPHIR_INIT_NVAR(&_38$$14);
								ZVAL_STRING(&_38$$14, "___");
								ZEPHIR_INIT_NVAR(&_39$$14);
								zephir_fast_strpos(&_39$$14, &k$$13, &_38$$14, 0 );
								_37$$14 = !ZEPHIR_IS_FALSE_IDENTICAL(&_39$$14);
							}
							if (_37$$14) {
								if (!(ZEPHIR_IS_EMPTY(&m$$13))) {
									ZEPHIR_INIT_NVAR(&_40$$16);
									ZVAL_STRING(&_40$$16, "___");
									ZEPHIR_INIT_NVAR(&res);
									zephir_fast_explode(&res, &_40$$16, &k$$13, LONG_MAX);
									ZEPHIR_OBS_NVAR(&_41$$16);
									zephir_array_fetch_long(&_41$$16, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 220);
									zephir_array_update_zval(&parameters, &_41$$16, &m$$13, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&routeName);
									zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 221);
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &match$$12, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_34$$13, &match$$12, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_34$$13)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&k$$13, &match$$12, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&m$$13, &match$$12, "current", NULL, 0);
							zephir_check_call_status();
								_42$$17 = Z_TYPE_P(&k$$13) == IS_STRING;
								if (_42$$17) {
									ZEPHIR_INIT_NVAR(&_43$$17);
									ZVAL_STRING(&_43$$17, "___");
									ZEPHIR_INIT_NVAR(&_44$$17);
									zephir_fast_strpos(&_44$$17, &k$$13, &_43$$17, 0 );
									_42$$17 = !ZEPHIR_IS_FALSE_IDENTICAL(&_44$$17);
								}
								if (_42$$17) {
									if (!(ZEPHIR_IS_EMPTY(&m$$13))) {
										ZEPHIR_INIT_NVAR(&_45$$19);
										ZVAL_STRING(&_45$$19, "___");
										ZEPHIR_INIT_NVAR(&res);
										zephir_fast_explode(&res, &_45$$19, &k$$13, LONG_MAX);
										ZEPHIR_OBS_NVAR(&_46$$19);
										zephir_array_fetch_long(&_46$$19, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 220);
										zephir_array_update_zval(&parameters, &_46$$19, &m$$13, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&routeName);
										zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 221);
									}
								}
							ZEPHIR_CALL_METHOD(NULL, &match$$12, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&m$$13);
					ZEPHIR_INIT_NVAR(&k$$13);
					zephir_read_property(&_47$$13, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&route);
					ZEPHIR_INIT_NVAR(&_48$$13);
					ZEPHIR_CONCAT_VSV(&_48$$13, &_method, "_", &routeName);
					zephir_array_fetch(&route, &_47$$13, &_48$$13, PH_NOISY, "moon/Component/Router/Router.zep", 225);
					object_init_ex(return_value, moon_component_router_node_ce);
					zephir_array_fetch_string(&_49$$13, &route, SL("handler"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 229);
					zephir_array_fetch_string(&_50$$13, &route, SL("routeName"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 230);
					zephir_array_fetch_string(&_51$$13, &route, SL("priority"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 231);
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_52, 272, &uri, &_49$$13, &_50$$13, &_51$$13, &parameters);
					zephir_check_call_status();
					RETURN_MM();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_25$$11, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_27$$11, &_25$$11, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_27$$11)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&nodesRegex, &_25$$11, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&nodesArr);
					zephir_array_keys(&nodesArr, &nodesRegex);
					ZEPHIR_INIT_NVAR(&_53$$20);
					zephir_fast_join_str(&_53$$20, SL("|"), &nodesArr);
					ZEPHIR_INIT_NVAR(&_54$$20);
					ZVAL_STRING(&_54$$20, "#%s#");
					ZEPHIR_CALL_FUNCTION(&regex, "sprintf", &_30, 3, &_54$$20, &_53$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_54$$20);
					zephir_fast_join_str(&_54$$20, SL("/"), &uriArr);
					ZEPHIR_INIT_NVAR(&_55$$20);
					ZEPHIR_CONCAT_SV(&_55$$20, "/", &_54$$20);
					ZEPHIR_INIT_NVAR(&_56$$20);
					zephir_preg_match(&_56$$20, &regex, &_55$$20, &match$$20, 0, 0 , 0 );
					if (zephir_is_true(&_56$$20)) {
						ZEPHIR_INIT_NVAR(&parameters);
						array_init(&parameters);
						ZEPHIR_INIT_NVAR(&routeName);
						ZVAL_STRING(&routeName, "");
						zephir_is_iterable(&match$$20, 0, "moon/Component/Router/Router.zep", 225);
						if (Z_TYPE_P(&match$$20) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&match$$20), _59$$21, _60$$21, _57$$21)
							{
								ZEPHIR_INIT_NVAR(&k$$21);
								if (_60$$21 != NULL) { 
									ZVAL_STR_COPY(&k$$21, _60$$21);
								} else {
									ZVAL_LONG(&k$$21, _59$$21);
								}
								ZEPHIR_INIT_NVAR(&m$$21);
								ZVAL_COPY(&m$$21, _57$$21);
								_61$$22 = Z_TYPE_P(&k$$21) == IS_STRING;
								if (_61$$22) {
									ZEPHIR_INIT_NVAR(&_62$$22);
									ZVAL_STRING(&_62$$22, "___");
									ZEPHIR_INIT_NVAR(&_63$$22);
									zephir_fast_strpos(&_63$$22, &k$$21, &_62$$22, 0 );
									_61$$22 = !ZEPHIR_IS_FALSE_IDENTICAL(&_63$$22);
								}
								if (_61$$22) {
									if (!(ZEPHIR_IS_EMPTY(&m$$21))) {
										ZEPHIR_INIT_NVAR(&_64$$24);
										ZVAL_STRING(&_64$$24, "___");
										ZEPHIR_INIT_NVAR(&res);
										zephir_fast_explode(&res, &_64$$24, &k$$21, LONG_MAX);
										ZEPHIR_OBS_NVAR(&_65$$24);
										zephir_array_fetch_long(&_65$$24, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 220);
										zephir_array_update_zval(&parameters, &_65$$24, &m$$21, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&routeName);
										zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 221);
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &match$$20, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_58$$21, &match$$20, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_58$$21)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&k$$21, &match$$20, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&m$$21, &match$$20, "current", NULL, 0);
								zephir_check_call_status();
									_66$$25 = Z_TYPE_P(&k$$21) == IS_STRING;
									if (_66$$25) {
										ZEPHIR_INIT_NVAR(&_67$$25);
										ZVAL_STRING(&_67$$25, "___");
										ZEPHIR_INIT_NVAR(&_68$$25);
										zephir_fast_strpos(&_68$$25, &k$$21, &_67$$25, 0 );
										_66$$25 = !ZEPHIR_IS_FALSE_IDENTICAL(&_68$$25);
									}
									if (_66$$25) {
										if (!(ZEPHIR_IS_EMPTY(&m$$21))) {
											ZEPHIR_INIT_NVAR(&_69$$27);
											ZVAL_STRING(&_69$$27, "___");
											ZEPHIR_INIT_NVAR(&res);
											zephir_fast_explode(&res, &_69$$27, &k$$21, LONG_MAX);
											ZEPHIR_OBS_NVAR(&_70$$27);
											zephir_array_fetch_long(&_70$$27, &res, 0, PH_NOISY, "moon/Component/Router/Router.zep", 220);
											zephir_array_update_zval(&parameters, &_70$$27, &m$$21, PH_COPY | PH_SEPARATE);
											ZEPHIR_OBS_NVAR(&routeName);
											zephir_array_fetch_long(&routeName, &res, 1, PH_NOISY, "moon/Component/Router/Router.zep", 221);
										}
									}
								ZEPHIR_CALL_METHOD(NULL, &match$$20, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&m$$21);
						ZEPHIR_INIT_NVAR(&k$$21);
						zephir_read_property(&_71$$21, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&route);
						ZEPHIR_INIT_NVAR(&_72$$21);
						ZEPHIR_CONCAT_VSV(&_72$$21, &_method, "_", &routeName);
						zephir_array_fetch(&route, &_71$$21, &_72$$21, PH_NOISY, "moon/Component/Router/Router.zep", 225);
						object_init_ex(return_value, moon_component_router_node_ce);
						zephir_array_fetch_string(&_73$$21, &route, SL("handler"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 229);
						zephir_array_fetch_string(&_74$$21, &route, SL("routeName"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 230);
						zephir_array_fetch_string(&_75$$21, &route, SL("priority"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 231);
						ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_52, 272, &uri, &_73$$21, &_74$$21, &_75$$21, &parameters);
						zephir_check_call_status();
						RETURN_MM();
					}
				ZEPHIR_CALL_METHOD(NULL, &_25$$11, "next", NULL, 0);
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

	zend_string *_24$$8, *_147$$49, *_269$$91, *_389$$132;
	zend_ulong _23$$8, _146$$49, _268$$91, _388$$132;
	zval _131$$5, _251$$46, _373$$88, _493$$129;
	zval methods, uri, handler, routeName, priority, index, formatStr, regexPos, regexKey, regexArr, item, i, length, uriArr, _0, _1, _2, _3, router, *_4, _5, method$$4, *_6$$4, _7$$4, _8$$5, nodes$$5, _15$$5, _16$$5, _17$$5, _18$$5, _132$$5, _133$$5, _9$$6, _10$$7, _11$$7, _12$$7, _13$$7, *_21$$8, _22$$8, _25$$9, _26$$9, re$$10, *_28$$10, _29$$10, _67$$10, _68$$10, _72$$10, _73$$10, _30$$11, _31$$11, _32$$12, _33$$13, _34$$13, _35$$13, _36$$13, _37$$13, _38$$13, _40$$14, _41$$14, _42$$14, _43$$14, _44$$14, _45$$14, _46$$14, _47$$14, _48$$15, _49$$16, _50$$16, _51$$17, _52$$18, _53$$18, _54$$18, _55$$18, _56$$18, _57$$18, _58$$19, _59$$19, _60$$19, _61$$19, _62$$19, _63$$19, _64$$19, _65$$19, _66$$20, _69$$22, _70$$23, _71$$23, _74$$24, _75$$25, _77$$26, _78$$26, _79$$27, _80$$27, re$$28, *_81$$28, _82$$28, _119$$28, _120$$28, _124$$28, _125$$28, _83$$29, _84$$29, _85$$30, _86$$31, _87$$31, _88$$31, _89$$31, _90$$31, _91$$31, _92$$32, _93$$32, _94$$32, _95$$32, _96$$32, _97$$32, _98$$32, _99$$32, _100$$33, _101$$34, _102$$34, _103$$35, _104$$36, _105$$36, _106$$36, _107$$36, _108$$36, _109$$36, _110$$37, _111$$37, _112$$37, _113$$37, _114$$37, _115$$37, _116$$37, _117$$37, _118$$38, _121$$40, _122$$41, _123$$41, _126$$42, _127$$43, _128$$44, _129$$44, _130$$45, _134$$46, nodes$$46, _140$$46, _141$$46, _142$$46, _143$$46, _252$$46, _253$$46, _135$$47, _136$$48, _137$$48, _138$$48, _139$$48, *_144$$49, _145$$49, _148$$50, _149$$50, re$$51, *_150$$51, _151$$51, _188$$51, _189$$51, _193$$51, _194$$51, _152$$52, _153$$52, _154$$53, _155$$54, _156$$54, _157$$54, _158$$54, _159$$54, _160$$54, _161$$55, _162$$55, _163$$55, _164$$55, _165$$55, _166$$55, _167$$55, _168$$55, _169$$56, _170$$57, _171$$57, _172$$58, _173$$59, _174$$59, _175$$59, _176$$59, _177$$59, _178$$59, _179$$60, _180$$60, _181$$60, _182$$60, _183$$60, _184$$60, _185$$60, _186$$60, _187$$61, _190$$63, _191$$64, _192$$64, _195$$65, _196$$66, _197$$67, _198$$67, _199$$68, _200$$68, re$$69, *_201$$69, _202$$69, _239$$69, _240$$69, _244$$69, _245$$69, _203$$70, _204$$70, _205$$71, _206$$72, _207$$72, _208$$72, _209$$72, _210$$72, _211$$72, _212$$73, _213$$73, _214$$73, _215$$73, _216$$73, _217$$73, _218$$73, _219$$73, _220$$74, _221$$75, _222$$75, _223$$76, _224$$77, _225$$77, _226$$77, _227$$77, _228$$77, _229$$77, _230$$78, _231$$78, _232$$78, _233$$78, _234$$78, _235$$78, _236$$78, _237$$78, _238$$79, _241$$81, _242$$82, _243$$82, _246$$83, _247$$84, _248$$85, _249$$85, _250$$86, method$$87, *_254$$87, _255$$87, _256$$88, nodes$$88, _262$$88, _263$$88, _264$$88, _265$$88, _374$$88, _375$$88, _257$$89, _258$$90, _259$$90, _260$$90, _261$$90, *_266$$91, _267$$91, _270$$92, _271$$92, re$$93, *_272$$93, _273$$93, _310$$93, _311$$93, _315$$93, _316$$93, _274$$94, _275$$94, _276$$95, _277$$96, _278$$96, _279$$96, _280$$96, _281$$96, _282$$96, _283$$97, _284$$97, _285$$97, _286$$97, _287$$97, _288$$97, _289$$97, _290$$97, _291$$98, _292$$99, _293$$99, _294$$100, _295$$101, _296$$101, _297$$101, _298$$101, _299$$101, _300$$101, _301$$102, _302$$102, _303$$102, _304$$102, _305$$102, _306$$102, _307$$102, _308$$102, _309$$103, _312$$105, _313$$106, _314$$106, _317$$107, _318$$108, _319$$109, _320$$109, _321$$110, _322$$110, re$$111, *_323$$111, _324$$111, _361$$111, _362$$111, _366$$111, _367$$111, _325$$112, _326$$112, _327$$113, _328$$114, _329$$114, _330$$114, _331$$114, _332$$114, _333$$114, _334$$115, _335$$115, _336$$115, _337$$115, _338$$115, _339$$115, _340$$115, _341$$115, _342$$116, _343$$117, _344$$117, _345$$118, _346$$119, _347$$119, _348$$119, _349$$119, _350$$119, _351$$119, _352$$120, _353$$120, _354$$120, _355$$120, _356$$120, _357$$120, _358$$120, _359$$120, _360$$121, _363$$123, _364$$124, _365$$124, _368$$125, _369$$126, _370$$127, _371$$127, _372$$128, _376$$129, nodes$$129, _382$$129, _383$$129, _384$$129, _385$$129, _494$$129, _495$$129, _377$$130, _378$$131, _379$$131, _380$$131, _381$$131, *_386$$132, _387$$132, _390$$133, _391$$133, re$$134, *_392$$134, _393$$134, _430$$134, _431$$134, _435$$134, _436$$134, _394$$135, _395$$135, _396$$136, _397$$137, _398$$137, _399$$137, _400$$137, _401$$137, _402$$137, _403$$138, _404$$138, _405$$138, _406$$138, _407$$138, _408$$138, _409$$138, _410$$138, _411$$139, _412$$140, _413$$140, _414$$141, _415$$142, _416$$142, _417$$142, _418$$142, _419$$142, _420$$142, _421$$143, _422$$143, _423$$143, _424$$143, _425$$143, _426$$143, _427$$143, _428$$143, _429$$144, _432$$146, _433$$147, _434$$147, _437$$148, _438$$149, _439$$150, _440$$150, _441$$151, _442$$151, re$$152, *_443$$152, _444$$152, _481$$152, _482$$152, _486$$152, _487$$152, _445$$153, _446$$153, _447$$154, _448$$155, _449$$155, _450$$155, _451$$155, _452$$155, _453$$155, _454$$156, _455$$156, _456$$156, _457$$156, _458$$156, _459$$156, _460$$156, _461$$156, _462$$157, _463$$158, _464$$158, _465$$159, _466$$160, _467$$160, _468$$160, _469$$160, _470$$160, _471$$160, _472$$161, _473$$161, _474$$161, _475$$161, _476$$161, _477$$161, _478$$161, _479$$161, _480$$162, _483$$164, _484$$165, _485$$165, _488$$166, _489$$167, _490$$168, _491$$168, _492$$169;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL, *_19 = NULL, *_20 = NULL, *_27 = NULL, *_39 = NULL, *_76 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, count = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&priority);
	ZVAL_UNDEF(&index);
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
	ZVAL_UNDEF(&nodes$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_132$$5);
	ZVAL_UNDEF(&_133$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&re$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_67$$10);
	ZVAL_UNDEF(&_68$$10);
	ZVAL_UNDEF(&_72$$10);
	ZVAL_UNDEF(&_73$$10);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_41$$14);
	ZVAL_UNDEF(&_42$$14);
	ZVAL_UNDEF(&_43$$14);
	ZVAL_UNDEF(&_44$$14);
	ZVAL_UNDEF(&_45$$14);
	ZVAL_UNDEF(&_46$$14);
	ZVAL_UNDEF(&_47$$14);
	ZVAL_UNDEF(&_48$$15);
	ZVAL_UNDEF(&_49$$16);
	ZVAL_UNDEF(&_50$$16);
	ZVAL_UNDEF(&_51$$17);
	ZVAL_UNDEF(&_52$$18);
	ZVAL_UNDEF(&_53$$18);
	ZVAL_UNDEF(&_54$$18);
	ZVAL_UNDEF(&_55$$18);
	ZVAL_UNDEF(&_56$$18);
	ZVAL_UNDEF(&_57$$18);
	ZVAL_UNDEF(&_58$$19);
	ZVAL_UNDEF(&_59$$19);
	ZVAL_UNDEF(&_60$$19);
	ZVAL_UNDEF(&_61$$19);
	ZVAL_UNDEF(&_62$$19);
	ZVAL_UNDEF(&_63$$19);
	ZVAL_UNDEF(&_64$$19);
	ZVAL_UNDEF(&_65$$19);
	ZVAL_UNDEF(&_66$$20);
	ZVAL_UNDEF(&_69$$22);
	ZVAL_UNDEF(&_70$$23);
	ZVAL_UNDEF(&_71$$23);
	ZVAL_UNDEF(&_74$$24);
	ZVAL_UNDEF(&_75$$25);
	ZVAL_UNDEF(&_77$$26);
	ZVAL_UNDEF(&_78$$26);
	ZVAL_UNDEF(&_79$$27);
	ZVAL_UNDEF(&_80$$27);
	ZVAL_UNDEF(&re$$28);
	ZVAL_UNDEF(&_82$$28);
	ZVAL_UNDEF(&_119$$28);
	ZVAL_UNDEF(&_120$$28);
	ZVAL_UNDEF(&_124$$28);
	ZVAL_UNDEF(&_125$$28);
	ZVAL_UNDEF(&_83$$29);
	ZVAL_UNDEF(&_84$$29);
	ZVAL_UNDEF(&_85$$30);
	ZVAL_UNDEF(&_86$$31);
	ZVAL_UNDEF(&_87$$31);
	ZVAL_UNDEF(&_88$$31);
	ZVAL_UNDEF(&_89$$31);
	ZVAL_UNDEF(&_90$$31);
	ZVAL_UNDEF(&_91$$31);
	ZVAL_UNDEF(&_92$$32);
	ZVAL_UNDEF(&_93$$32);
	ZVAL_UNDEF(&_94$$32);
	ZVAL_UNDEF(&_95$$32);
	ZVAL_UNDEF(&_96$$32);
	ZVAL_UNDEF(&_97$$32);
	ZVAL_UNDEF(&_98$$32);
	ZVAL_UNDEF(&_99$$32);
	ZVAL_UNDEF(&_100$$33);
	ZVAL_UNDEF(&_101$$34);
	ZVAL_UNDEF(&_102$$34);
	ZVAL_UNDEF(&_103$$35);
	ZVAL_UNDEF(&_104$$36);
	ZVAL_UNDEF(&_105$$36);
	ZVAL_UNDEF(&_106$$36);
	ZVAL_UNDEF(&_107$$36);
	ZVAL_UNDEF(&_108$$36);
	ZVAL_UNDEF(&_109$$36);
	ZVAL_UNDEF(&_110$$37);
	ZVAL_UNDEF(&_111$$37);
	ZVAL_UNDEF(&_112$$37);
	ZVAL_UNDEF(&_113$$37);
	ZVAL_UNDEF(&_114$$37);
	ZVAL_UNDEF(&_115$$37);
	ZVAL_UNDEF(&_116$$37);
	ZVAL_UNDEF(&_117$$37);
	ZVAL_UNDEF(&_118$$38);
	ZVAL_UNDEF(&_121$$40);
	ZVAL_UNDEF(&_122$$41);
	ZVAL_UNDEF(&_123$$41);
	ZVAL_UNDEF(&_126$$42);
	ZVAL_UNDEF(&_127$$43);
	ZVAL_UNDEF(&_128$$44);
	ZVAL_UNDEF(&_129$$44);
	ZVAL_UNDEF(&_130$$45);
	ZVAL_UNDEF(&_134$$46);
	ZVAL_UNDEF(&nodes$$46);
	ZVAL_UNDEF(&_140$$46);
	ZVAL_UNDEF(&_141$$46);
	ZVAL_UNDEF(&_142$$46);
	ZVAL_UNDEF(&_143$$46);
	ZVAL_UNDEF(&_252$$46);
	ZVAL_UNDEF(&_253$$46);
	ZVAL_UNDEF(&_135$$47);
	ZVAL_UNDEF(&_136$$48);
	ZVAL_UNDEF(&_137$$48);
	ZVAL_UNDEF(&_138$$48);
	ZVAL_UNDEF(&_139$$48);
	ZVAL_UNDEF(&_145$$49);
	ZVAL_UNDEF(&_148$$50);
	ZVAL_UNDEF(&_149$$50);
	ZVAL_UNDEF(&re$$51);
	ZVAL_UNDEF(&_151$$51);
	ZVAL_UNDEF(&_188$$51);
	ZVAL_UNDEF(&_189$$51);
	ZVAL_UNDEF(&_193$$51);
	ZVAL_UNDEF(&_194$$51);
	ZVAL_UNDEF(&_152$$52);
	ZVAL_UNDEF(&_153$$52);
	ZVAL_UNDEF(&_154$$53);
	ZVAL_UNDEF(&_155$$54);
	ZVAL_UNDEF(&_156$$54);
	ZVAL_UNDEF(&_157$$54);
	ZVAL_UNDEF(&_158$$54);
	ZVAL_UNDEF(&_159$$54);
	ZVAL_UNDEF(&_160$$54);
	ZVAL_UNDEF(&_161$$55);
	ZVAL_UNDEF(&_162$$55);
	ZVAL_UNDEF(&_163$$55);
	ZVAL_UNDEF(&_164$$55);
	ZVAL_UNDEF(&_165$$55);
	ZVAL_UNDEF(&_166$$55);
	ZVAL_UNDEF(&_167$$55);
	ZVAL_UNDEF(&_168$$55);
	ZVAL_UNDEF(&_169$$56);
	ZVAL_UNDEF(&_170$$57);
	ZVAL_UNDEF(&_171$$57);
	ZVAL_UNDEF(&_172$$58);
	ZVAL_UNDEF(&_173$$59);
	ZVAL_UNDEF(&_174$$59);
	ZVAL_UNDEF(&_175$$59);
	ZVAL_UNDEF(&_176$$59);
	ZVAL_UNDEF(&_177$$59);
	ZVAL_UNDEF(&_178$$59);
	ZVAL_UNDEF(&_179$$60);
	ZVAL_UNDEF(&_180$$60);
	ZVAL_UNDEF(&_181$$60);
	ZVAL_UNDEF(&_182$$60);
	ZVAL_UNDEF(&_183$$60);
	ZVAL_UNDEF(&_184$$60);
	ZVAL_UNDEF(&_185$$60);
	ZVAL_UNDEF(&_186$$60);
	ZVAL_UNDEF(&_187$$61);
	ZVAL_UNDEF(&_190$$63);
	ZVAL_UNDEF(&_191$$64);
	ZVAL_UNDEF(&_192$$64);
	ZVAL_UNDEF(&_195$$65);
	ZVAL_UNDEF(&_196$$66);
	ZVAL_UNDEF(&_197$$67);
	ZVAL_UNDEF(&_198$$67);
	ZVAL_UNDEF(&_199$$68);
	ZVAL_UNDEF(&_200$$68);
	ZVAL_UNDEF(&re$$69);
	ZVAL_UNDEF(&_202$$69);
	ZVAL_UNDEF(&_239$$69);
	ZVAL_UNDEF(&_240$$69);
	ZVAL_UNDEF(&_244$$69);
	ZVAL_UNDEF(&_245$$69);
	ZVAL_UNDEF(&_203$$70);
	ZVAL_UNDEF(&_204$$70);
	ZVAL_UNDEF(&_205$$71);
	ZVAL_UNDEF(&_206$$72);
	ZVAL_UNDEF(&_207$$72);
	ZVAL_UNDEF(&_208$$72);
	ZVAL_UNDEF(&_209$$72);
	ZVAL_UNDEF(&_210$$72);
	ZVAL_UNDEF(&_211$$72);
	ZVAL_UNDEF(&_212$$73);
	ZVAL_UNDEF(&_213$$73);
	ZVAL_UNDEF(&_214$$73);
	ZVAL_UNDEF(&_215$$73);
	ZVAL_UNDEF(&_216$$73);
	ZVAL_UNDEF(&_217$$73);
	ZVAL_UNDEF(&_218$$73);
	ZVAL_UNDEF(&_219$$73);
	ZVAL_UNDEF(&_220$$74);
	ZVAL_UNDEF(&_221$$75);
	ZVAL_UNDEF(&_222$$75);
	ZVAL_UNDEF(&_223$$76);
	ZVAL_UNDEF(&_224$$77);
	ZVAL_UNDEF(&_225$$77);
	ZVAL_UNDEF(&_226$$77);
	ZVAL_UNDEF(&_227$$77);
	ZVAL_UNDEF(&_228$$77);
	ZVAL_UNDEF(&_229$$77);
	ZVAL_UNDEF(&_230$$78);
	ZVAL_UNDEF(&_231$$78);
	ZVAL_UNDEF(&_232$$78);
	ZVAL_UNDEF(&_233$$78);
	ZVAL_UNDEF(&_234$$78);
	ZVAL_UNDEF(&_235$$78);
	ZVAL_UNDEF(&_236$$78);
	ZVAL_UNDEF(&_237$$78);
	ZVAL_UNDEF(&_238$$79);
	ZVAL_UNDEF(&_241$$81);
	ZVAL_UNDEF(&_242$$82);
	ZVAL_UNDEF(&_243$$82);
	ZVAL_UNDEF(&_246$$83);
	ZVAL_UNDEF(&_247$$84);
	ZVAL_UNDEF(&_248$$85);
	ZVAL_UNDEF(&_249$$85);
	ZVAL_UNDEF(&_250$$86);
	ZVAL_UNDEF(&method$$87);
	ZVAL_UNDEF(&_255$$87);
	ZVAL_UNDEF(&_256$$88);
	ZVAL_UNDEF(&nodes$$88);
	ZVAL_UNDEF(&_262$$88);
	ZVAL_UNDEF(&_263$$88);
	ZVAL_UNDEF(&_264$$88);
	ZVAL_UNDEF(&_265$$88);
	ZVAL_UNDEF(&_374$$88);
	ZVAL_UNDEF(&_375$$88);
	ZVAL_UNDEF(&_257$$89);
	ZVAL_UNDEF(&_258$$90);
	ZVAL_UNDEF(&_259$$90);
	ZVAL_UNDEF(&_260$$90);
	ZVAL_UNDEF(&_261$$90);
	ZVAL_UNDEF(&_267$$91);
	ZVAL_UNDEF(&_270$$92);
	ZVAL_UNDEF(&_271$$92);
	ZVAL_UNDEF(&re$$93);
	ZVAL_UNDEF(&_273$$93);
	ZVAL_UNDEF(&_310$$93);
	ZVAL_UNDEF(&_311$$93);
	ZVAL_UNDEF(&_315$$93);
	ZVAL_UNDEF(&_316$$93);
	ZVAL_UNDEF(&_274$$94);
	ZVAL_UNDEF(&_275$$94);
	ZVAL_UNDEF(&_276$$95);
	ZVAL_UNDEF(&_277$$96);
	ZVAL_UNDEF(&_278$$96);
	ZVAL_UNDEF(&_279$$96);
	ZVAL_UNDEF(&_280$$96);
	ZVAL_UNDEF(&_281$$96);
	ZVAL_UNDEF(&_282$$96);
	ZVAL_UNDEF(&_283$$97);
	ZVAL_UNDEF(&_284$$97);
	ZVAL_UNDEF(&_285$$97);
	ZVAL_UNDEF(&_286$$97);
	ZVAL_UNDEF(&_287$$97);
	ZVAL_UNDEF(&_288$$97);
	ZVAL_UNDEF(&_289$$97);
	ZVAL_UNDEF(&_290$$97);
	ZVAL_UNDEF(&_291$$98);
	ZVAL_UNDEF(&_292$$99);
	ZVAL_UNDEF(&_293$$99);
	ZVAL_UNDEF(&_294$$100);
	ZVAL_UNDEF(&_295$$101);
	ZVAL_UNDEF(&_296$$101);
	ZVAL_UNDEF(&_297$$101);
	ZVAL_UNDEF(&_298$$101);
	ZVAL_UNDEF(&_299$$101);
	ZVAL_UNDEF(&_300$$101);
	ZVAL_UNDEF(&_301$$102);
	ZVAL_UNDEF(&_302$$102);
	ZVAL_UNDEF(&_303$$102);
	ZVAL_UNDEF(&_304$$102);
	ZVAL_UNDEF(&_305$$102);
	ZVAL_UNDEF(&_306$$102);
	ZVAL_UNDEF(&_307$$102);
	ZVAL_UNDEF(&_308$$102);
	ZVAL_UNDEF(&_309$$103);
	ZVAL_UNDEF(&_312$$105);
	ZVAL_UNDEF(&_313$$106);
	ZVAL_UNDEF(&_314$$106);
	ZVAL_UNDEF(&_317$$107);
	ZVAL_UNDEF(&_318$$108);
	ZVAL_UNDEF(&_319$$109);
	ZVAL_UNDEF(&_320$$109);
	ZVAL_UNDEF(&_321$$110);
	ZVAL_UNDEF(&_322$$110);
	ZVAL_UNDEF(&re$$111);
	ZVAL_UNDEF(&_324$$111);
	ZVAL_UNDEF(&_361$$111);
	ZVAL_UNDEF(&_362$$111);
	ZVAL_UNDEF(&_366$$111);
	ZVAL_UNDEF(&_367$$111);
	ZVAL_UNDEF(&_325$$112);
	ZVAL_UNDEF(&_326$$112);
	ZVAL_UNDEF(&_327$$113);
	ZVAL_UNDEF(&_328$$114);
	ZVAL_UNDEF(&_329$$114);
	ZVAL_UNDEF(&_330$$114);
	ZVAL_UNDEF(&_331$$114);
	ZVAL_UNDEF(&_332$$114);
	ZVAL_UNDEF(&_333$$114);
	ZVAL_UNDEF(&_334$$115);
	ZVAL_UNDEF(&_335$$115);
	ZVAL_UNDEF(&_336$$115);
	ZVAL_UNDEF(&_337$$115);
	ZVAL_UNDEF(&_338$$115);
	ZVAL_UNDEF(&_339$$115);
	ZVAL_UNDEF(&_340$$115);
	ZVAL_UNDEF(&_341$$115);
	ZVAL_UNDEF(&_342$$116);
	ZVAL_UNDEF(&_343$$117);
	ZVAL_UNDEF(&_344$$117);
	ZVAL_UNDEF(&_345$$118);
	ZVAL_UNDEF(&_346$$119);
	ZVAL_UNDEF(&_347$$119);
	ZVAL_UNDEF(&_348$$119);
	ZVAL_UNDEF(&_349$$119);
	ZVAL_UNDEF(&_350$$119);
	ZVAL_UNDEF(&_351$$119);
	ZVAL_UNDEF(&_352$$120);
	ZVAL_UNDEF(&_353$$120);
	ZVAL_UNDEF(&_354$$120);
	ZVAL_UNDEF(&_355$$120);
	ZVAL_UNDEF(&_356$$120);
	ZVAL_UNDEF(&_357$$120);
	ZVAL_UNDEF(&_358$$120);
	ZVAL_UNDEF(&_359$$120);
	ZVAL_UNDEF(&_360$$121);
	ZVAL_UNDEF(&_363$$123);
	ZVAL_UNDEF(&_364$$124);
	ZVAL_UNDEF(&_365$$124);
	ZVAL_UNDEF(&_368$$125);
	ZVAL_UNDEF(&_369$$126);
	ZVAL_UNDEF(&_370$$127);
	ZVAL_UNDEF(&_371$$127);
	ZVAL_UNDEF(&_372$$128);
	ZVAL_UNDEF(&_376$$129);
	ZVAL_UNDEF(&nodes$$129);
	ZVAL_UNDEF(&_382$$129);
	ZVAL_UNDEF(&_383$$129);
	ZVAL_UNDEF(&_384$$129);
	ZVAL_UNDEF(&_385$$129);
	ZVAL_UNDEF(&_494$$129);
	ZVAL_UNDEF(&_495$$129);
	ZVAL_UNDEF(&_377$$130);
	ZVAL_UNDEF(&_378$$131);
	ZVAL_UNDEF(&_379$$131);
	ZVAL_UNDEF(&_380$$131);
	ZVAL_UNDEF(&_381$$131);
	ZVAL_UNDEF(&_387$$132);
	ZVAL_UNDEF(&_390$$133);
	ZVAL_UNDEF(&_391$$133);
	ZVAL_UNDEF(&re$$134);
	ZVAL_UNDEF(&_393$$134);
	ZVAL_UNDEF(&_430$$134);
	ZVAL_UNDEF(&_431$$134);
	ZVAL_UNDEF(&_435$$134);
	ZVAL_UNDEF(&_436$$134);
	ZVAL_UNDEF(&_394$$135);
	ZVAL_UNDEF(&_395$$135);
	ZVAL_UNDEF(&_396$$136);
	ZVAL_UNDEF(&_397$$137);
	ZVAL_UNDEF(&_398$$137);
	ZVAL_UNDEF(&_399$$137);
	ZVAL_UNDEF(&_400$$137);
	ZVAL_UNDEF(&_401$$137);
	ZVAL_UNDEF(&_402$$137);
	ZVAL_UNDEF(&_403$$138);
	ZVAL_UNDEF(&_404$$138);
	ZVAL_UNDEF(&_405$$138);
	ZVAL_UNDEF(&_406$$138);
	ZVAL_UNDEF(&_407$$138);
	ZVAL_UNDEF(&_408$$138);
	ZVAL_UNDEF(&_409$$138);
	ZVAL_UNDEF(&_410$$138);
	ZVAL_UNDEF(&_411$$139);
	ZVAL_UNDEF(&_412$$140);
	ZVAL_UNDEF(&_413$$140);
	ZVAL_UNDEF(&_414$$141);
	ZVAL_UNDEF(&_415$$142);
	ZVAL_UNDEF(&_416$$142);
	ZVAL_UNDEF(&_417$$142);
	ZVAL_UNDEF(&_418$$142);
	ZVAL_UNDEF(&_419$$142);
	ZVAL_UNDEF(&_420$$142);
	ZVAL_UNDEF(&_421$$143);
	ZVAL_UNDEF(&_422$$143);
	ZVAL_UNDEF(&_423$$143);
	ZVAL_UNDEF(&_424$$143);
	ZVAL_UNDEF(&_425$$143);
	ZVAL_UNDEF(&_426$$143);
	ZVAL_UNDEF(&_427$$143);
	ZVAL_UNDEF(&_428$$143);
	ZVAL_UNDEF(&_429$$144);
	ZVAL_UNDEF(&_432$$146);
	ZVAL_UNDEF(&_433$$147);
	ZVAL_UNDEF(&_434$$147);
	ZVAL_UNDEF(&_437$$148);
	ZVAL_UNDEF(&_438$$149);
	ZVAL_UNDEF(&_439$$150);
	ZVAL_UNDEF(&_440$$150);
	ZVAL_UNDEF(&_441$$151);
	ZVAL_UNDEF(&_442$$151);
	ZVAL_UNDEF(&re$$152);
	ZVAL_UNDEF(&_444$$152);
	ZVAL_UNDEF(&_481$$152);
	ZVAL_UNDEF(&_482$$152);
	ZVAL_UNDEF(&_486$$152);
	ZVAL_UNDEF(&_487$$152);
	ZVAL_UNDEF(&_445$$153);
	ZVAL_UNDEF(&_446$$153);
	ZVAL_UNDEF(&_447$$154);
	ZVAL_UNDEF(&_448$$155);
	ZVAL_UNDEF(&_449$$155);
	ZVAL_UNDEF(&_450$$155);
	ZVAL_UNDEF(&_451$$155);
	ZVAL_UNDEF(&_452$$155);
	ZVAL_UNDEF(&_453$$155);
	ZVAL_UNDEF(&_454$$156);
	ZVAL_UNDEF(&_455$$156);
	ZVAL_UNDEF(&_456$$156);
	ZVAL_UNDEF(&_457$$156);
	ZVAL_UNDEF(&_458$$156);
	ZVAL_UNDEF(&_459$$156);
	ZVAL_UNDEF(&_460$$156);
	ZVAL_UNDEF(&_461$$156);
	ZVAL_UNDEF(&_462$$157);
	ZVAL_UNDEF(&_463$$158);
	ZVAL_UNDEF(&_464$$158);
	ZVAL_UNDEF(&_465$$159);
	ZVAL_UNDEF(&_466$$160);
	ZVAL_UNDEF(&_467$$160);
	ZVAL_UNDEF(&_468$$160);
	ZVAL_UNDEF(&_469$$160);
	ZVAL_UNDEF(&_470$$160);
	ZVAL_UNDEF(&_471$$160);
	ZVAL_UNDEF(&_472$$161);
	ZVAL_UNDEF(&_473$$161);
	ZVAL_UNDEF(&_474$$161);
	ZVAL_UNDEF(&_475$$161);
	ZVAL_UNDEF(&_476$$161);
	ZVAL_UNDEF(&_477$$161);
	ZVAL_UNDEF(&_478$$161);
	ZVAL_UNDEF(&_479$$161);
	ZVAL_UNDEF(&_480$$162);
	ZVAL_UNDEF(&_483$$164);
	ZVAL_UNDEF(&_484$$165);
	ZVAL_UNDEF(&_485$$165);
	ZVAL_UNDEF(&_488$$166);
	ZVAL_UNDEF(&_489$$167);
	ZVAL_UNDEF(&_490$$168);
	ZVAL_UNDEF(&_491$$168);
	ZVAL_UNDEF(&_492$$169);
	ZVAL_UNDEF(&_131$$5);
	ZVAL_UNDEF(&_251$$46);
	ZVAL_UNDEF(&_373$$88);
	ZVAL_UNDEF(&_493$$129);

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
	ZEPHIR_CALL_FUNCTION(NULL, "array_multisort", NULL, 273, &_1, &_3, &_2);
	ZEPHIR_UNREF(&_1);
	ZEPHIR_UNREF(&_3);
	ZEPHIR_UNREF(&_2);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("routers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "moon/Component/Router/Router.zep", 380);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&router);
			ZVAL_COPY(&router, _4);
			ZEPHIR_OBS_NVAR(&methods);
			zephir_array_fetch_string(&methods, &router, SL("methods"), PH_NOISY, "moon/Component/Router/Router.zep", 276);
			ZEPHIR_OBS_NVAR(&uri);
			zephir_array_fetch_string(&uri, &router, SL("uri"), PH_NOISY, "moon/Component/Router/Router.zep", 277);
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_string(&handler, &router, SL("handler"), PH_NOISY, "moon/Component/Router/Router.zep", 278);
			ZEPHIR_OBS_NVAR(&routeName);
			zephir_array_fetch_string(&routeName, &router, SL("routeName"), PH_NOISY, "moon/Component/Router/Router.zep", 279);
			ZEPHIR_OBS_NVAR(&priority);
			zephir_array_fetch_string(&priority, &router, SL("priority"), PH_NOISY, "moon/Component/Router/Router.zep", 280);
			zephir_is_iterable(&methods, 0, "moon/Component/Router/Router.zep", 379);
			if (Z_TYPE_P(&methods) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _6$$4)
				{
					ZEPHIR_INIT_NVAR(&method$$4);
					ZVAL_COPY(&method$$4, _6$$4);
					zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset(&_8$$5, &method$$4))) {
						ZEPHIR_INIT_NVAR(&_9$$6);
						array_init(&_9$$6);
						zephir_update_property_array(this_ptr, SL("nodes"), &method$$4, &_9$$6);
					}
					if (ZEPHIR_IS_EMPTY(&routeName)) {
						ZEPHIR_INIT_NVAR(&_10$$7);
						ZEPHIR_INIT_NVAR(&_11$$7);
						ZEPHIR_CONCAT_VV(&_11$$7, &method$$4, &uri);
						zephir_md5(&_10$$7, &_11$$7);
						ZVAL_LONG(&_12$$7, 9);
						ZVAL_LONG(&_13$$7, 35);
						ZEPHIR_CALL_FUNCTION(&routeName, "base_convert", &_14, 274, &_10$$7, &_12$$7, &_13$$7);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(&_15$$5);
					ZEPHIR_INIT_NVAR(&_16$$5);
					ZVAL_STRING(&_16$$5, "$nodes = &$this->nodes[$method];");
					zephir_eval_php(&_16$$5, &_15$$5, "moon/Component/Router/Router.zep:294");
					ZEPHIR_INIT_NVAR(&_17$$5);
					zephir_fast_explode_str(&_17$$5, SL("/"), &uri, LONG_MAX);
					ZEPHIR_CALL_FUNCTION(&_18$$5, "array_filter", &_19, 161, &_17$$5);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_20, 98, &_18$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&length);
					ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
					if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
						zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 372);
						if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uriArr), _23$$8, _24$$8, _21$$8)
							{
								ZEPHIR_INIT_NVAR(&i);
								if (_24$$8 != NULL) { 
									ZVAL_STR_COPY(&i, _24$$8);
								} else {
									ZVAL_LONG(&i, _23$$8);
								}
								ZEPHIR_INIT_NVAR(&item);
								ZVAL_COPY(&item, _21$$8);
								zephir_array_fetch_long(&_25$$9, &item, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 302);
								ZEPHIR_INIT_NVAR(&_26$$9);
								ZVAL_STRING(&_26$$9, "{");
								if (ZEPHIR_IS_EQUAL(&_26$$9, &_25$$9)) {
									ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_27, 153, &uriArr, &i);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&regexKey);
									ZVAL_STRING(&regexKey, "");
									zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 324);
									if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _28$$10)
										{
											ZEPHIR_INIT_NVAR(&re$$10);
											ZVAL_COPY(&re$$10, _28$$10);
											zephir_array_fetch_long(&_30$$11, &re$$10, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
											ZEPHIR_INIT_NVAR(&_31$$11);
											ZVAL_STRING(&_31$$11, "{");
											if (ZEPHIR_IS_EQUAL(&_31$$11, &_30$$11)) {
												ZEPHIR_INIT_NVAR(&_32$$12);
												ZVAL_STRING(&_32$$12, "<");
												ZEPHIR_INIT_NVAR(&regexPos);
												zephir_fast_strpos(&regexPos, &re$$10, &_32$$12, 0 );
												ZEPHIR_INIT_NVAR(&formatStr);
												ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
												if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
													ZVAL_LONG(&_33$$13, 1);
													ZVAL_LONG(&_34$$13, -1);
													ZEPHIR_INIT_NVAR(&_35$$13);
													zephir_substr(&_35$$13, &re$$10, 1 , -1 , 0);
													ZEPHIR_INIT_NVAR(&_36$$13);
													ZVAL_STRING(&_36$$13, "___");
													ZEPHIR_INIT_NVAR(&_37$$13);
													ZVAL_STRING(&_37$$13, "[^/]+");
													ZEPHIR_CALL_FUNCTION(&_38$$13, "sprintf", &_39, 3, &formatStr, &_35$$13, &_36$$13, &routeName, &_37$$13);
													zephir_check_call_status();
													zephir_concat_self(&regexKey, &_38$$13);
												} else {
													ZVAL_LONG(&_40$$14, 1);
													ZVAL_LONG(&_41$$14, (zephir_get_numberval(&regexPos) - 1));
													ZEPHIR_INIT_NVAR(&_42$$14);
													zephir_substr(&_42$$14, &re$$10, 1 , zephir_get_intval(&_41$$14), 0);
													ZVAL_LONG(&_43$$14, (zephir_get_numberval(&regexPos) + 1));
													ZVAL_LONG(&_44$$14, -2);
													ZEPHIR_INIT_NVAR(&_45$$14);
													zephir_substr(&_45$$14, &re$$10, zephir_get_intval(&_43$$14), -2 , 0);
													ZEPHIR_INIT_NVAR(&_46$$14);
													ZVAL_STRING(&_46$$14, "___");
													ZEPHIR_CALL_FUNCTION(&_47$$14, "sprintf", &_39, 3, &formatStr, &_42$$14, &_46$$14, &routeName, &_45$$14);
													zephir_check_call_status();
													zephir_concat_self(&regexKey, &_47$$14);
												}
											} else {
												ZEPHIR_INIT_NVAR(&_48$$15);
												ZEPHIR_CONCAT_SV(&_48$$15, "/", &re$$10);
												zephir_concat_self(&regexKey, &_48$$15);
											}
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_29$$10, &regexArr, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_29$$10)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&re$$10, &regexArr, "current", NULL, 0);
											zephir_check_call_status();
												zephir_array_fetch_long(&_49$$16, &re$$10, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
												ZEPHIR_INIT_NVAR(&_50$$16);
												ZVAL_STRING(&_50$$16, "{");
												if (ZEPHIR_IS_EQUAL(&_50$$16, &_49$$16)) {
													ZEPHIR_INIT_NVAR(&_51$$17);
													ZVAL_STRING(&_51$$17, "<");
													ZEPHIR_INIT_NVAR(&regexPos);
													zephir_fast_strpos(&regexPos, &re$$10, &_51$$17, 0 );
													ZEPHIR_INIT_NVAR(&formatStr);
													ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
													if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
														ZVAL_LONG(&_52$$18, 1);
														ZVAL_LONG(&_53$$18, -1);
														ZEPHIR_INIT_NVAR(&_54$$18);
														zephir_substr(&_54$$18, &re$$10, 1 , -1 , 0);
														ZEPHIR_INIT_NVAR(&_55$$18);
														ZVAL_STRING(&_55$$18, "___");
														ZEPHIR_INIT_NVAR(&_56$$18);
														ZVAL_STRING(&_56$$18, "[^/]+");
														ZEPHIR_CALL_FUNCTION(&_57$$18, "sprintf", &_39, 3, &formatStr, &_54$$18, &_55$$18, &routeName, &_56$$18);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_57$$18);
													} else {
														ZVAL_LONG(&_58$$19, 1);
														ZVAL_LONG(&_59$$19, (zephir_get_numberval(&regexPos) - 1));
														ZEPHIR_INIT_NVAR(&_60$$19);
														zephir_substr(&_60$$19, &re$$10, 1 , zephir_get_intval(&_59$$19), 0);
														ZVAL_LONG(&_61$$19, (zephir_get_numberval(&regexPos) + 1));
														ZVAL_LONG(&_62$$19, -2);
														ZEPHIR_INIT_NVAR(&_63$$19);
														zephir_substr(&_63$$19, &re$$10, zephir_get_intval(&_61$$19), -2 , 0);
														ZEPHIR_INIT_NVAR(&_64$$19);
														ZVAL_STRING(&_64$$19, "___");
														ZEPHIR_CALL_FUNCTION(&_65$$19, "sprintf", &_39, 3, &formatStr, &_60$$19, &_64$$19, &routeName, &_63$$19);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_65$$19);
													}
												} else {
													ZEPHIR_INIT_NVAR(&_66$$20);
													ZEPHIR_CONCAT_SV(&_66$$20, "/", &re$$10);
													zephir_concat_self(&regexKey, &_66$$20);
												}
											ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&re$$10);
									zephir_array_fetch_long(&_67$$10, &regexKey, (zephir_fast_strlen_ev(&regexKey) - 1), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 324);
									ZEPHIR_INIT_NVAR(&_68$$10);
									ZVAL_STRING(&_68$$10, ")");
									if (!ZEPHIR_IS_EQUAL(&_68$$10, &_67$$10)) {
										zephir_concat_self_str(&regexKey, SL("\\b"));
									}
									if (!(zephir_array_isset_string(&nodes$$5, SL("$total$")))) {
										ZEPHIR_INIT_NVAR(&_69$$22);
										ZVAL_LONG(&_69$$22, 0);
										zephir_array_update_string(&nodes$$5, SL("$total$"), &_69$$22, PH_COPY | PH_SEPARATE);
									}
									ZEPHIR_INIT_NVAR(&index);
									ZVAL_LONG(&index, 0);
									count = 0;
									if (zephir_array_isset_string(&nodes$$5, SL("$regex$"))) {
										zephir_array_fetch_string(&_70$$23, &nodes$$5, SL("$total$"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 334);
										ZVAL_DOUBLE(&_71$$23, zephir_safe_div_zval_long(&_70$$23, 100));
										ZEPHIR_INIT_NVAR(&index);
										ZVAL_DOUBLE(&index, zephir_floor(&_71$$23));
									}
									ZEPHIR_INIT_NVAR(&_72$$10);
									ZVAL_STRING(&_72$$10, "^%s$");
									ZEPHIR_CALL_FUNCTION(&_73$$10, "sprintf", &_39, 3, &_72$$10, &regexKey);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&regexKey, &_73$$10);
									ZEPHIR_INIT_NVAR(&_72$$10);
									array_init(&_72$$10);
									zephir_array_update_multi(&nodes$$5, &_72$$10, SL("szz"), 4, SL("$regex$"), &index, &regexKey);
									ZEPHIR_INIT_NVAR(&_72$$10);
									ZVAL_LONG(&_72$$10, 1);
									zephir_array_update_string(&nodes$$5, SL("$total$"), &_72$$10, PH_COPY | PH_SEPARATE);
									break;
								}
								if (!(zephir_array_isset(&nodes$$5, &item))) {
									ZEPHIR_INIT_NVAR(&_74$$24);
									array_init(&_74$$24);
									zephir_array_update_zval(&nodes$$5, &item, &_74$$24, PH_COPY | PH_SEPARATE);
								}
								if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
									ZEPHIR_INIT_NVAR(&_75$$25);
									object_init_ex(&_75$$25, moon_component_router_node_ce);
									ZEPHIR_CALL_METHOD(NULL, &_75$$25, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
									zephir_check_call_status();
									zephir_array_update_multi(&nodes$$5, &_75$$25, SL("zs"), 3, &item, SL("$node$"));
								} else {
									ZEPHIR_INIT_NVAR(&_77$$26);
									ZEPHIR_INIT_NVAR(&_78$$26);
									ZVAL_STRING(&_78$$26, "$nodes = &$nodes[$item];");
									zephir_eval_php(&_78$$26, &_77$$26, "moon/Component/Router/Router.zep:369");
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_22$$8, &uriArr, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_22$$8)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&i, &uriArr, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
								zephir_check_call_status();
									zephir_array_fetch_long(&_79$$27, &item, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 302);
									ZEPHIR_INIT_NVAR(&_80$$27);
									ZVAL_STRING(&_80$$27, "{");
									if (ZEPHIR_IS_EQUAL(&_80$$27, &_79$$27)) {
										ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_27, 153, &uriArr, &i);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&regexKey);
										ZVAL_STRING(&regexKey, "");
										zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 324);
										if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _81$$28)
											{
												ZEPHIR_INIT_NVAR(&re$$28);
												ZVAL_COPY(&re$$28, _81$$28);
												zephir_array_fetch_long(&_83$$29, &re$$28, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
												ZEPHIR_INIT_NVAR(&_84$$29);
												ZVAL_STRING(&_84$$29, "{");
												if (ZEPHIR_IS_EQUAL(&_84$$29, &_83$$29)) {
													ZEPHIR_INIT_NVAR(&_85$$30);
													ZVAL_STRING(&_85$$30, "<");
													ZEPHIR_INIT_NVAR(&regexPos);
													zephir_fast_strpos(&regexPos, &re$$28, &_85$$30, 0 );
													ZEPHIR_INIT_NVAR(&formatStr);
													ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
													if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
														ZVAL_LONG(&_86$$31, 1);
														ZVAL_LONG(&_87$$31, -1);
														ZEPHIR_INIT_NVAR(&_88$$31);
														zephir_substr(&_88$$31, &re$$28, 1 , -1 , 0);
														ZEPHIR_INIT_NVAR(&_89$$31);
														ZVAL_STRING(&_89$$31, "___");
														ZEPHIR_INIT_NVAR(&_90$$31);
														ZVAL_STRING(&_90$$31, "[^/]+");
														ZEPHIR_CALL_FUNCTION(&_91$$31, "sprintf", &_39, 3, &formatStr, &_88$$31, &_89$$31, &routeName, &_90$$31);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_91$$31);
													} else {
														ZVAL_LONG(&_92$$32, 1);
														ZVAL_LONG(&_93$$32, (zephir_get_numberval(&regexPos) - 1));
														ZEPHIR_INIT_NVAR(&_94$$32);
														zephir_substr(&_94$$32, &re$$28, 1 , zephir_get_intval(&_93$$32), 0);
														ZVAL_LONG(&_95$$32, (zephir_get_numberval(&regexPos) + 1));
														ZVAL_LONG(&_96$$32, -2);
														ZEPHIR_INIT_NVAR(&_97$$32);
														zephir_substr(&_97$$32, &re$$28, zephir_get_intval(&_95$$32), -2 , 0);
														ZEPHIR_INIT_NVAR(&_98$$32);
														ZVAL_STRING(&_98$$32, "___");
														ZEPHIR_CALL_FUNCTION(&_99$$32, "sprintf", &_39, 3, &formatStr, &_94$$32, &_98$$32, &routeName, &_97$$32);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_99$$32);
													}
												} else {
													ZEPHIR_INIT_NVAR(&_100$$33);
													ZEPHIR_CONCAT_SV(&_100$$33, "/", &re$$28);
													zephir_concat_self(&regexKey, &_100$$33);
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_82$$28, &regexArr, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_82$$28)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&re$$28, &regexArr, "current", NULL, 0);
												zephir_check_call_status();
													zephir_array_fetch_long(&_101$$34, &re$$28, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
													ZEPHIR_INIT_NVAR(&_102$$34);
													ZVAL_STRING(&_102$$34, "{");
													if (ZEPHIR_IS_EQUAL(&_102$$34, &_101$$34)) {
														ZEPHIR_INIT_NVAR(&_103$$35);
														ZVAL_STRING(&_103$$35, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$28, &_103$$35, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_104$$36, 1);
															ZVAL_LONG(&_105$$36, -1);
															ZEPHIR_INIT_NVAR(&_106$$36);
															zephir_substr(&_106$$36, &re$$28, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_107$$36);
															ZVAL_STRING(&_107$$36, "___");
															ZEPHIR_INIT_NVAR(&_108$$36);
															ZVAL_STRING(&_108$$36, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_109$$36, "sprintf", &_39, 3, &formatStr, &_106$$36, &_107$$36, &routeName, &_108$$36);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_109$$36);
														} else {
															ZVAL_LONG(&_110$$37, 1);
															ZVAL_LONG(&_111$$37, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_112$$37);
															zephir_substr(&_112$$37, &re$$28, 1 , zephir_get_intval(&_111$$37), 0);
															ZVAL_LONG(&_113$$37, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_114$$37, -2);
															ZEPHIR_INIT_NVAR(&_115$$37);
															zephir_substr(&_115$$37, &re$$28, zephir_get_intval(&_113$$37), -2 , 0);
															ZEPHIR_INIT_NVAR(&_116$$37);
															ZVAL_STRING(&_116$$37, "___");
															ZEPHIR_CALL_FUNCTION(&_117$$37, "sprintf", &_39, 3, &formatStr, &_112$$37, &_116$$37, &routeName, &_115$$37);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_117$$37);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_118$$38);
														ZEPHIR_CONCAT_SV(&_118$$38, "/", &re$$28);
														zephir_concat_self(&regexKey, &_118$$38);
													}
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&re$$28);
										zephir_array_fetch_long(&_119$$28, &regexKey, (zephir_fast_strlen_ev(&regexKey) - 1), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 324);
										ZEPHIR_INIT_NVAR(&_120$$28);
										ZVAL_STRING(&_120$$28, ")");
										if (!ZEPHIR_IS_EQUAL(&_120$$28, &_119$$28)) {
											zephir_concat_self_str(&regexKey, SL("\\b"));
										}
										if (!(zephir_array_isset_string(&nodes$$5, SL("$total$")))) {
											ZEPHIR_INIT_NVAR(&_121$$40);
											ZVAL_LONG(&_121$$40, 0);
											zephir_array_update_string(&nodes$$5, SL("$total$"), &_121$$40, PH_COPY | PH_SEPARATE);
										}
										ZEPHIR_INIT_NVAR(&index);
										ZVAL_LONG(&index, 0);
										count = 0;
										if (zephir_array_isset_string(&nodes$$5, SL("$regex$"))) {
											zephir_array_fetch_string(&_122$$41, &nodes$$5, SL("$total$"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 334);
											ZVAL_DOUBLE(&_123$$41, zephir_safe_div_zval_long(&_122$$41, 100));
											ZEPHIR_INIT_NVAR(&index);
											ZVAL_DOUBLE(&index, zephir_floor(&_123$$41));
										}
										ZEPHIR_INIT_NVAR(&_124$$28);
										ZVAL_STRING(&_124$$28, "^%s$");
										ZEPHIR_CALL_FUNCTION(&_125$$28, "sprintf", &_39, 3, &_124$$28, &regexKey);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&regexKey, &_125$$28);
										ZEPHIR_INIT_NVAR(&_124$$28);
										array_init(&_124$$28);
										zephir_array_update_multi(&nodes$$5, &_124$$28, SL("szz"), 4, SL("$regex$"), &index, &regexKey);
										ZEPHIR_INIT_NVAR(&_124$$28);
										ZVAL_LONG(&_124$$28, 1);
										zephir_array_update_string(&nodes$$5, SL("$total$"), &_124$$28, PH_COPY | PH_SEPARATE);
										break;
									}
									if (!(zephir_array_isset(&nodes$$5, &item))) {
										ZEPHIR_INIT_NVAR(&_126$$42);
										array_init(&_126$$42);
										zephir_array_update_zval(&nodes$$5, &item, &_126$$42, PH_COPY | PH_SEPARATE);
									}
									if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
										ZEPHIR_INIT_NVAR(&_127$$43);
										object_init_ex(&_127$$43, moon_component_router_node_ce);
										ZEPHIR_CALL_METHOD(NULL, &_127$$43, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
										zephir_check_call_status();
										zephir_array_update_multi(&nodes$$5, &_127$$43, SL("zs"), 3, &item, SL("$node$"));
									} else {
										ZEPHIR_INIT_NVAR(&_128$$44);
										ZEPHIR_INIT_NVAR(&_129$$44);
										ZVAL_STRING(&_129$$44, "$nodes = &$nodes[$item];");
										zephir_eval_php(&_129$$44, &_128$$44, "moon/Component/Router/Router.zep:369");
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
						ZEPHIR_INIT_NVAR(&_130$$45);
						object_init_ex(&_130$$45, moon_component_router_node_ce);
						ZEPHIR_CALL_METHOD(NULL, &_130$$45, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
						zephir_check_call_status();
						zephir_array_update_string(&nodes$$5, SL("$index$"), &_130$$45, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_INIT_NVAR(&_131$$5);
					zephir_create_array(&_131$$5, 5, 0);
					zephir_array_update_string(&_131$$5, SL("method"), &method$$4, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_131$$5, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_131$$5, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_131$$5, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_131$$5, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_132$$5);
					ZVAL_STRING(&_132$$5, "%s_%s");
					ZEPHIR_CALL_FUNCTION(&_133$$5, "sprintf", &_39, 3, &_132$$5, &method$$4, &routeName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("routes"), &_133$$5, &_131$$5);
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
						zephir_read_property(&_134$$46, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
						if (!(zephir_array_isset(&_134$$46, &method$$4))) {
							ZEPHIR_INIT_NVAR(&_135$$47);
							array_init(&_135$$47);
							zephir_update_property_array(this_ptr, SL("nodes"), &method$$4, &_135$$47);
						}
						if (ZEPHIR_IS_EMPTY(&routeName)) {
							ZEPHIR_INIT_NVAR(&_136$$48);
							ZEPHIR_INIT_NVAR(&_137$$48);
							ZEPHIR_CONCAT_VV(&_137$$48, &method$$4, &uri);
							zephir_md5(&_136$$48, &_137$$48);
							ZVAL_LONG(&_138$$48, 9);
							ZVAL_LONG(&_139$$48, 35);
							ZEPHIR_CALL_FUNCTION(&routeName, "base_convert", &_14, 274, &_136$$48, &_138$$48, &_139$$48);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_140$$46);
						ZEPHIR_INIT_NVAR(&_141$$46);
						ZVAL_STRING(&_141$$46, "$nodes = &$this->nodes[$method];");
						zephir_eval_php(&_141$$46, &_140$$46, "moon/Component/Router/Router.zep:294");
						ZEPHIR_INIT_NVAR(&_142$$46);
						zephir_fast_explode_str(&_142$$46, SL("/"), &uri, LONG_MAX);
						ZEPHIR_CALL_FUNCTION(&_143$$46, "array_filter", &_19, 161, &_142$$46);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_20, 98, &_143$$46);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&length);
						ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
						if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
							zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 372);
							if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uriArr), _146$$49, _147$$49, _144$$49)
								{
									ZEPHIR_INIT_NVAR(&i);
									if (_147$$49 != NULL) { 
										ZVAL_STR_COPY(&i, _147$$49);
									} else {
										ZVAL_LONG(&i, _146$$49);
									}
									ZEPHIR_INIT_NVAR(&item);
									ZVAL_COPY(&item, _144$$49);
									zephir_array_fetch_long(&_148$$50, &item, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 302);
									ZEPHIR_INIT_NVAR(&_149$$50);
									ZVAL_STRING(&_149$$50, "{");
									if (ZEPHIR_IS_EQUAL(&_149$$50, &_148$$50)) {
										ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_27, 153, &uriArr, &i);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&regexKey);
										ZVAL_STRING(&regexKey, "");
										zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 324);
										if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _150$$51)
											{
												ZEPHIR_INIT_NVAR(&re$$51);
												ZVAL_COPY(&re$$51, _150$$51);
												zephir_array_fetch_long(&_152$$52, &re$$51, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
												ZEPHIR_INIT_NVAR(&_153$$52);
												ZVAL_STRING(&_153$$52, "{");
												if (ZEPHIR_IS_EQUAL(&_153$$52, &_152$$52)) {
													ZEPHIR_INIT_NVAR(&_154$$53);
													ZVAL_STRING(&_154$$53, "<");
													ZEPHIR_INIT_NVAR(&regexPos);
													zephir_fast_strpos(&regexPos, &re$$51, &_154$$53, 0 );
													ZEPHIR_INIT_NVAR(&formatStr);
													ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
													if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
														ZVAL_LONG(&_155$$54, 1);
														ZVAL_LONG(&_156$$54, -1);
														ZEPHIR_INIT_NVAR(&_157$$54);
														zephir_substr(&_157$$54, &re$$51, 1 , -1 , 0);
														ZEPHIR_INIT_NVAR(&_158$$54);
														ZVAL_STRING(&_158$$54, "___");
														ZEPHIR_INIT_NVAR(&_159$$54);
														ZVAL_STRING(&_159$$54, "[^/]+");
														ZEPHIR_CALL_FUNCTION(&_160$$54, "sprintf", &_39, 3, &formatStr, &_157$$54, &_158$$54, &routeName, &_159$$54);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_160$$54);
													} else {
														ZVAL_LONG(&_161$$55, 1);
														ZVAL_LONG(&_162$$55, (zephir_get_numberval(&regexPos) - 1));
														ZEPHIR_INIT_NVAR(&_163$$55);
														zephir_substr(&_163$$55, &re$$51, 1 , zephir_get_intval(&_162$$55), 0);
														ZVAL_LONG(&_164$$55, (zephir_get_numberval(&regexPos) + 1));
														ZVAL_LONG(&_165$$55, -2);
														ZEPHIR_INIT_NVAR(&_166$$55);
														zephir_substr(&_166$$55, &re$$51, zephir_get_intval(&_164$$55), -2 , 0);
														ZEPHIR_INIT_NVAR(&_167$$55);
														ZVAL_STRING(&_167$$55, "___");
														ZEPHIR_CALL_FUNCTION(&_168$$55, "sprintf", &_39, 3, &formatStr, &_163$$55, &_167$$55, &routeName, &_166$$55);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_168$$55);
													}
												} else {
													ZEPHIR_INIT_NVAR(&_169$$56);
													ZEPHIR_CONCAT_SV(&_169$$56, "/", &re$$51);
													zephir_concat_self(&regexKey, &_169$$56);
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_151$$51, &regexArr, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_151$$51)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&re$$51, &regexArr, "current", NULL, 0);
												zephir_check_call_status();
													zephir_array_fetch_long(&_170$$57, &re$$51, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
													ZEPHIR_INIT_NVAR(&_171$$57);
													ZVAL_STRING(&_171$$57, "{");
													if (ZEPHIR_IS_EQUAL(&_171$$57, &_170$$57)) {
														ZEPHIR_INIT_NVAR(&_172$$58);
														ZVAL_STRING(&_172$$58, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$51, &_172$$58, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_173$$59, 1);
															ZVAL_LONG(&_174$$59, -1);
															ZEPHIR_INIT_NVAR(&_175$$59);
															zephir_substr(&_175$$59, &re$$51, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_176$$59);
															ZVAL_STRING(&_176$$59, "___");
															ZEPHIR_INIT_NVAR(&_177$$59);
															ZVAL_STRING(&_177$$59, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_178$$59, "sprintf", &_39, 3, &formatStr, &_175$$59, &_176$$59, &routeName, &_177$$59);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_178$$59);
														} else {
															ZVAL_LONG(&_179$$60, 1);
															ZVAL_LONG(&_180$$60, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_181$$60);
															zephir_substr(&_181$$60, &re$$51, 1 , zephir_get_intval(&_180$$60), 0);
															ZVAL_LONG(&_182$$60, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_183$$60, -2);
															ZEPHIR_INIT_NVAR(&_184$$60);
															zephir_substr(&_184$$60, &re$$51, zephir_get_intval(&_182$$60), -2 , 0);
															ZEPHIR_INIT_NVAR(&_185$$60);
															ZVAL_STRING(&_185$$60, "___");
															ZEPHIR_CALL_FUNCTION(&_186$$60, "sprintf", &_39, 3, &formatStr, &_181$$60, &_185$$60, &routeName, &_184$$60);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_186$$60);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_187$$61);
														ZEPHIR_CONCAT_SV(&_187$$61, "/", &re$$51);
														zephir_concat_self(&regexKey, &_187$$61);
													}
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&re$$51);
										zephir_array_fetch_long(&_188$$51, &regexKey, (zephir_fast_strlen_ev(&regexKey) - 1), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 324);
										ZEPHIR_INIT_NVAR(&_189$$51);
										ZVAL_STRING(&_189$$51, ")");
										if (!ZEPHIR_IS_EQUAL(&_189$$51, &_188$$51)) {
											zephir_concat_self_str(&regexKey, SL("\\b"));
										}
										if (!(zephir_array_isset_string(&nodes$$46, SL("$total$")))) {
											ZEPHIR_INIT_NVAR(&_190$$63);
											ZVAL_LONG(&_190$$63, 0);
											zephir_array_update_string(&nodes$$46, SL("$total$"), &_190$$63, PH_COPY | PH_SEPARATE);
										}
										ZEPHIR_INIT_NVAR(&index);
										ZVAL_LONG(&index, 0);
										count = 0;
										if (zephir_array_isset_string(&nodes$$46, SL("$regex$"))) {
											zephir_array_fetch_string(&_191$$64, &nodes$$46, SL("$total$"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 334);
											ZVAL_DOUBLE(&_192$$64, zephir_safe_div_zval_long(&_191$$64, 100));
											ZEPHIR_INIT_NVAR(&index);
											ZVAL_DOUBLE(&index, zephir_floor(&_192$$64));
										}
										ZEPHIR_INIT_NVAR(&_193$$51);
										ZVAL_STRING(&_193$$51, "^%s$");
										ZEPHIR_CALL_FUNCTION(&_194$$51, "sprintf", &_39, 3, &_193$$51, &regexKey);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&regexKey, &_194$$51);
										ZEPHIR_INIT_NVAR(&_193$$51);
										array_init(&_193$$51);
										zephir_array_update_multi(&nodes$$46, &_193$$51, SL("szz"), 4, SL("$regex$"), &index, &regexKey);
										ZEPHIR_INIT_NVAR(&_193$$51);
										ZVAL_LONG(&_193$$51, 1);
										zephir_array_update_string(&nodes$$46, SL("$total$"), &_193$$51, PH_COPY | PH_SEPARATE);
										break;
									}
									if (!(zephir_array_isset(&nodes$$46, &item))) {
										ZEPHIR_INIT_NVAR(&_195$$65);
										array_init(&_195$$65);
										zephir_array_update_zval(&nodes$$46, &item, &_195$$65, PH_COPY | PH_SEPARATE);
									}
									if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
										ZEPHIR_INIT_NVAR(&_196$$66);
										object_init_ex(&_196$$66, moon_component_router_node_ce);
										ZEPHIR_CALL_METHOD(NULL, &_196$$66, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
										zephir_check_call_status();
										zephir_array_update_multi(&nodes$$46, &_196$$66, SL("zs"), 3, &item, SL("$node$"));
									} else {
										ZEPHIR_INIT_NVAR(&_197$$67);
										ZEPHIR_INIT_NVAR(&_198$$67);
										ZVAL_STRING(&_198$$67, "$nodes = &$nodes[$item];");
										zephir_eval_php(&_198$$67, &_197$$67, "moon/Component/Router/Router.zep:369");
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_145$$49, &uriArr, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_145$$49)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&i, &uriArr, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
									zephir_check_call_status();
										zephir_array_fetch_long(&_199$$68, &item, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 302);
										ZEPHIR_INIT_NVAR(&_200$$68);
										ZVAL_STRING(&_200$$68, "{");
										if (ZEPHIR_IS_EQUAL(&_200$$68, &_199$$68)) {
											ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_27, 153, &uriArr, &i);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&regexKey);
											ZVAL_STRING(&regexKey, "");
											zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 324);
											if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _201$$69)
												{
													ZEPHIR_INIT_NVAR(&re$$69);
													ZVAL_COPY(&re$$69, _201$$69);
													zephir_array_fetch_long(&_203$$70, &re$$69, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
													ZEPHIR_INIT_NVAR(&_204$$70);
													ZVAL_STRING(&_204$$70, "{");
													if (ZEPHIR_IS_EQUAL(&_204$$70, &_203$$70)) {
														ZEPHIR_INIT_NVAR(&_205$$71);
														ZVAL_STRING(&_205$$71, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$69, &_205$$71, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_206$$72, 1);
															ZVAL_LONG(&_207$$72, -1);
															ZEPHIR_INIT_NVAR(&_208$$72);
															zephir_substr(&_208$$72, &re$$69, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_209$$72);
															ZVAL_STRING(&_209$$72, "___");
															ZEPHIR_INIT_NVAR(&_210$$72);
															ZVAL_STRING(&_210$$72, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_211$$72, "sprintf", &_39, 3, &formatStr, &_208$$72, &_209$$72, &routeName, &_210$$72);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_211$$72);
														} else {
															ZVAL_LONG(&_212$$73, 1);
															ZVAL_LONG(&_213$$73, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_214$$73);
															zephir_substr(&_214$$73, &re$$69, 1 , zephir_get_intval(&_213$$73), 0);
															ZVAL_LONG(&_215$$73, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_216$$73, -2);
															ZEPHIR_INIT_NVAR(&_217$$73);
															zephir_substr(&_217$$73, &re$$69, zephir_get_intval(&_215$$73), -2 , 0);
															ZEPHIR_INIT_NVAR(&_218$$73);
															ZVAL_STRING(&_218$$73, "___");
															ZEPHIR_CALL_FUNCTION(&_219$$73, "sprintf", &_39, 3, &formatStr, &_214$$73, &_218$$73, &routeName, &_217$$73);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_219$$73);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_220$$74);
														ZEPHIR_CONCAT_SV(&_220$$74, "/", &re$$69);
														zephir_concat_self(&regexKey, &_220$$74);
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_202$$69, &regexArr, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_202$$69)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&re$$69, &regexArr, "current", NULL, 0);
													zephir_check_call_status();
														zephir_array_fetch_long(&_221$$75, &re$$69, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
														ZEPHIR_INIT_NVAR(&_222$$75);
														ZVAL_STRING(&_222$$75, "{");
														if (ZEPHIR_IS_EQUAL(&_222$$75, &_221$$75)) {
															ZEPHIR_INIT_NVAR(&_223$$76);
															ZVAL_STRING(&_223$$76, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$69, &_223$$76, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_224$$77, 1);
																ZVAL_LONG(&_225$$77, -1);
																ZEPHIR_INIT_NVAR(&_226$$77);
																zephir_substr(&_226$$77, &re$$69, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_227$$77);
																ZVAL_STRING(&_227$$77, "___");
																ZEPHIR_INIT_NVAR(&_228$$77);
																ZVAL_STRING(&_228$$77, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_229$$77, "sprintf", &_39, 3, &formatStr, &_226$$77, &_227$$77, &routeName, &_228$$77);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_229$$77);
															} else {
																ZVAL_LONG(&_230$$78, 1);
																ZVAL_LONG(&_231$$78, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_232$$78);
																zephir_substr(&_232$$78, &re$$69, 1 , zephir_get_intval(&_231$$78), 0);
																ZVAL_LONG(&_233$$78, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_234$$78, -2);
																ZEPHIR_INIT_NVAR(&_235$$78);
																zephir_substr(&_235$$78, &re$$69, zephir_get_intval(&_233$$78), -2 , 0);
																ZEPHIR_INIT_NVAR(&_236$$78);
																ZVAL_STRING(&_236$$78, "___");
																ZEPHIR_CALL_FUNCTION(&_237$$78, "sprintf", &_39, 3, &formatStr, &_232$$78, &_236$$78, &routeName, &_235$$78);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_237$$78);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_238$$79);
															ZEPHIR_CONCAT_SV(&_238$$79, "/", &re$$69);
															zephir_concat_self(&regexKey, &_238$$79);
														}
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&re$$69);
											zephir_array_fetch_long(&_239$$69, &regexKey, (zephir_fast_strlen_ev(&regexKey) - 1), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 324);
											ZEPHIR_INIT_NVAR(&_240$$69);
											ZVAL_STRING(&_240$$69, ")");
											if (!ZEPHIR_IS_EQUAL(&_240$$69, &_239$$69)) {
												zephir_concat_self_str(&regexKey, SL("\\b"));
											}
											if (!(zephir_array_isset_string(&nodes$$46, SL("$total$")))) {
												ZEPHIR_INIT_NVAR(&_241$$81);
												ZVAL_LONG(&_241$$81, 0);
												zephir_array_update_string(&nodes$$46, SL("$total$"), &_241$$81, PH_COPY | PH_SEPARATE);
											}
											ZEPHIR_INIT_NVAR(&index);
											ZVAL_LONG(&index, 0);
											count = 0;
											if (zephir_array_isset_string(&nodes$$46, SL("$regex$"))) {
												zephir_array_fetch_string(&_242$$82, &nodes$$46, SL("$total$"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 334);
												ZVAL_DOUBLE(&_243$$82, zephir_safe_div_zval_long(&_242$$82, 100));
												ZEPHIR_INIT_NVAR(&index);
												ZVAL_DOUBLE(&index, zephir_floor(&_243$$82));
											}
											ZEPHIR_INIT_NVAR(&_244$$69);
											ZVAL_STRING(&_244$$69, "^%s$");
											ZEPHIR_CALL_FUNCTION(&_245$$69, "sprintf", &_39, 3, &_244$$69, &regexKey);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&regexKey, &_245$$69);
											ZEPHIR_INIT_NVAR(&_244$$69);
											array_init(&_244$$69);
											zephir_array_update_multi(&nodes$$46, &_244$$69, SL("szz"), 4, SL("$regex$"), &index, &regexKey);
											ZEPHIR_INIT_NVAR(&_244$$69);
											ZVAL_LONG(&_244$$69, 1);
											zephir_array_update_string(&nodes$$46, SL("$total$"), &_244$$69, PH_COPY | PH_SEPARATE);
											break;
										}
										if (!(zephir_array_isset(&nodes$$46, &item))) {
											ZEPHIR_INIT_NVAR(&_246$$83);
											array_init(&_246$$83);
											zephir_array_update_zval(&nodes$$46, &item, &_246$$83, PH_COPY | PH_SEPARATE);
										}
										if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
											ZEPHIR_INIT_NVAR(&_247$$84);
											object_init_ex(&_247$$84, moon_component_router_node_ce);
											ZEPHIR_CALL_METHOD(NULL, &_247$$84, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
											zephir_check_call_status();
											zephir_array_update_multi(&nodes$$46, &_247$$84, SL("zs"), 3, &item, SL("$node$"));
										} else {
											ZEPHIR_INIT_NVAR(&_248$$85);
											ZEPHIR_INIT_NVAR(&_249$$85);
											ZVAL_STRING(&_249$$85, "$nodes = &$nodes[$item];");
											zephir_eval_php(&_249$$85, &_248$$85, "moon/Component/Router/Router.zep:369");
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
							ZEPHIR_INIT_NVAR(&_250$$86);
							object_init_ex(&_250$$86, moon_component_router_node_ce);
							ZEPHIR_CALL_METHOD(NULL, &_250$$86, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
							zephir_check_call_status();
							zephir_array_update_string(&nodes$$46, SL("$index$"), &_250$$86, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_INIT_NVAR(&_251$$46);
						zephir_create_array(&_251$$46, 5, 0);
						zephir_array_update_string(&_251$$46, SL("method"), &method$$4, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_251$$46, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_251$$46, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_251$$46, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_251$$46, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_252$$46);
						ZVAL_STRING(&_252$$46, "%s_%s");
						ZEPHIR_CALL_FUNCTION(&_253$$46, "sprintf", &_39, 3, &_252$$46, &method$$4, &routeName);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("routes"), &_253$$46, &_251$$46);
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
				zephir_array_fetch_string(&methods, &router, SL("methods"), PH_NOISY, "moon/Component/Router/Router.zep", 276);
				ZEPHIR_OBS_NVAR(&uri);
				zephir_array_fetch_string(&uri, &router, SL("uri"), PH_NOISY, "moon/Component/Router/Router.zep", 277);
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_string(&handler, &router, SL("handler"), PH_NOISY, "moon/Component/Router/Router.zep", 278);
				ZEPHIR_OBS_NVAR(&routeName);
				zephir_array_fetch_string(&routeName, &router, SL("routeName"), PH_NOISY, "moon/Component/Router/Router.zep", 279);
				ZEPHIR_OBS_NVAR(&priority);
				zephir_array_fetch_string(&priority, &router, SL("priority"), PH_NOISY, "moon/Component/Router/Router.zep", 280);
				zephir_is_iterable(&methods, 0, "moon/Component/Router/Router.zep", 379);
				if (Z_TYPE_P(&methods) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _254$$87)
					{
						ZEPHIR_INIT_NVAR(&method$$87);
						ZVAL_COPY(&method$$87, _254$$87);
						zephir_read_property(&_256$$88, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
						if (!(zephir_array_isset(&_256$$88, &method$$87))) {
							ZEPHIR_INIT_NVAR(&_257$$89);
							array_init(&_257$$89);
							zephir_update_property_array(this_ptr, SL("nodes"), &method$$87, &_257$$89);
						}
						if (ZEPHIR_IS_EMPTY(&routeName)) {
							ZEPHIR_INIT_NVAR(&_258$$90);
							ZEPHIR_INIT_NVAR(&_259$$90);
							ZEPHIR_CONCAT_VV(&_259$$90, &method$$87, &uri);
							zephir_md5(&_258$$90, &_259$$90);
							ZVAL_LONG(&_260$$90, 9);
							ZVAL_LONG(&_261$$90, 35);
							ZEPHIR_CALL_FUNCTION(&routeName, "base_convert", &_14, 274, &_258$$90, &_260$$90, &_261$$90);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_262$$88);
						ZEPHIR_INIT_NVAR(&_263$$88);
						ZVAL_STRING(&_263$$88, "$nodes = &$this->nodes[$method];");
						zephir_eval_php(&_263$$88, &_262$$88, "moon/Component/Router/Router.zep:294");
						ZEPHIR_INIT_NVAR(&_264$$88);
						zephir_fast_explode_str(&_264$$88, SL("/"), &uri, LONG_MAX);
						ZEPHIR_CALL_FUNCTION(&_265$$88, "array_filter", &_19, 161, &_264$$88);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_20, 98, &_265$$88);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&length);
						ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
						if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
							zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 372);
							if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uriArr), _268$$91, _269$$91, _266$$91)
								{
									ZEPHIR_INIT_NVAR(&i);
									if (_269$$91 != NULL) { 
										ZVAL_STR_COPY(&i, _269$$91);
									} else {
										ZVAL_LONG(&i, _268$$91);
									}
									ZEPHIR_INIT_NVAR(&item);
									ZVAL_COPY(&item, _266$$91);
									zephir_array_fetch_long(&_270$$92, &item, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 302);
									ZEPHIR_INIT_NVAR(&_271$$92);
									ZVAL_STRING(&_271$$92, "{");
									if (ZEPHIR_IS_EQUAL(&_271$$92, &_270$$92)) {
										ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_27, 153, &uriArr, &i);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&regexKey);
										ZVAL_STRING(&regexKey, "");
										zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 324);
										if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
											ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _272$$93)
											{
												ZEPHIR_INIT_NVAR(&re$$93);
												ZVAL_COPY(&re$$93, _272$$93);
												zephir_array_fetch_long(&_274$$94, &re$$93, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
												ZEPHIR_INIT_NVAR(&_275$$94);
												ZVAL_STRING(&_275$$94, "{");
												if (ZEPHIR_IS_EQUAL(&_275$$94, &_274$$94)) {
													ZEPHIR_INIT_NVAR(&_276$$95);
													ZVAL_STRING(&_276$$95, "<");
													ZEPHIR_INIT_NVAR(&regexPos);
													zephir_fast_strpos(&regexPos, &re$$93, &_276$$95, 0 );
													ZEPHIR_INIT_NVAR(&formatStr);
													ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
													if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
														ZVAL_LONG(&_277$$96, 1);
														ZVAL_LONG(&_278$$96, -1);
														ZEPHIR_INIT_NVAR(&_279$$96);
														zephir_substr(&_279$$96, &re$$93, 1 , -1 , 0);
														ZEPHIR_INIT_NVAR(&_280$$96);
														ZVAL_STRING(&_280$$96, "___");
														ZEPHIR_INIT_NVAR(&_281$$96);
														ZVAL_STRING(&_281$$96, "[^/]+");
														ZEPHIR_CALL_FUNCTION(&_282$$96, "sprintf", &_39, 3, &formatStr, &_279$$96, &_280$$96, &routeName, &_281$$96);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_282$$96);
													} else {
														ZVAL_LONG(&_283$$97, 1);
														ZVAL_LONG(&_284$$97, (zephir_get_numberval(&regexPos) - 1));
														ZEPHIR_INIT_NVAR(&_285$$97);
														zephir_substr(&_285$$97, &re$$93, 1 , zephir_get_intval(&_284$$97), 0);
														ZVAL_LONG(&_286$$97, (zephir_get_numberval(&regexPos) + 1));
														ZVAL_LONG(&_287$$97, -2);
														ZEPHIR_INIT_NVAR(&_288$$97);
														zephir_substr(&_288$$97, &re$$93, zephir_get_intval(&_286$$97), -2 , 0);
														ZEPHIR_INIT_NVAR(&_289$$97);
														ZVAL_STRING(&_289$$97, "___");
														ZEPHIR_CALL_FUNCTION(&_290$$97, "sprintf", &_39, 3, &formatStr, &_285$$97, &_289$$97, &routeName, &_288$$97);
														zephir_check_call_status();
														zephir_concat_self(&regexKey, &_290$$97);
													}
												} else {
													ZEPHIR_INIT_NVAR(&_291$$98);
													ZEPHIR_CONCAT_SV(&_291$$98, "/", &re$$93);
													zephir_concat_self(&regexKey, &_291$$98);
												}
											} ZEND_HASH_FOREACH_END();
										} else {
											ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
											zephir_check_call_status();
											while (1) {
												ZEPHIR_CALL_METHOD(&_273$$93, &regexArr, "valid", NULL, 0);
												zephir_check_call_status();
												if (!zend_is_true(&_273$$93)) {
													break;
												}
												ZEPHIR_CALL_METHOD(&re$$93, &regexArr, "current", NULL, 0);
												zephir_check_call_status();
													zephir_array_fetch_long(&_292$$99, &re$$93, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
													ZEPHIR_INIT_NVAR(&_293$$99);
													ZVAL_STRING(&_293$$99, "{");
													if (ZEPHIR_IS_EQUAL(&_293$$99, &_292$$99)) {
														ZEPHIR_INIT_NVAR(&_294$$100);
														ZVAL_STRING(&_294$$100, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$93, &_294$$100, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_295$$101, 1);
															ZVAL_LONG(&_296$$101, -1);
															ZEPHIR_INIT_NVAR(&_297$$101);
															zephir_substr(&_297$$101, &re$$93, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_298$$101);
															ZVAL_STRING(&_298$$101, "___");
															ZEPHIR_INIT_NVAR(&_299$$101);
															ZVAL_STRING(&_299$$101, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_300$$101, "sprintf", &_39, 3, &formatStr, &_297$$101, &_298$$101, &routeName, &_299$$101);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_300$$101);
														} else {
															ZVAL_LONG(&_301$$102, 1);
															ZVAL_LONG(&_302$$102, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_303$$102);
															zephir_substr(&_303$$102, &re$$93, 1 , zephir_get_intval(&_302$$102), 0);
															ZVAL_LONG(&_304$$102, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_305$$102, -2);
															ZEPHIR_INIT_NVAR(&_306$$102);
															zephir_substr(&_306$$102, &re$$93, zephir_get_intval(&_304$$102), -2 , 0);
															ZEPHIR_INIT_NVAR(&_307$$102);
															ZVAL_STRING(&_307$$102, "___");
															ZEPHIR_CALL_FUNCTION(&_308$$102, "sprintf", &_39, 3, &formatStr, &_303$$102, &_307$$102, &routeName, &_306$$102);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_308$$102);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_309$$103);
														ZEPHIR_CONCAT_SV(&_309$$103, "/", &re$$93);
														zephir_concat_self(&regexKey, &_309$$103);
													}
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
												zephir_check_call_status();
											}
										}
										ZEPHIR_INIT_NVAR(&re$$93);
										zephir_array_fetch_long(&_310$$93, &regexKey, (zephir_fast_strlen_ev(&regexKey) - 1), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 324);
										ZEPHIR_INIT_NVAR(&_311$$93);
										ZVAL_STRING(&_311$$93, ")");
										if (!ZEPHIR_IS_EQUAL(&_311$$93, &_310$$93)) {
											zephir_concat_self_str(&regexKey, SL("\\b"));
										}
										if (!(zephir_array_isset_string(&nodes$$88, SL("$total$")))) {
											ZEPHIR_INIT_NVAR(&_312$$105);
											ZVAL_LONG(&_312$$105, 0);
											zephir_array_update_string(&nodes$$88, SL("$total$"), &_312$$105, PH_COPY | PH_SEPARATE);
										}
										ZEPHIR_INIT_NVAR(&index);
										ZVAL_LONG(&index, 0);
										count = 0;
										if (zephir_array_isset_string(&nodes$$88, SL("$regex$"))) {
											zephir_array_fetch_string(&_313$$106, &nodes$$88, SL("$total$"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 334);
											ZVAL_DOUBLE(&_314$$106, zephir_safe_div_zval_long(&_313$$106, 100));
											ZEPHIR_INIT_NVAR(&index);
											ZVAL_DOUBLE(&index, zephir_floor(&_314$$106));
										}
										ZEPHIR_INIT_NVAR(&_315$$93);
										ZVAL_STRING(&_315$$93, "^%s$");
										ZEPHIR_CALL_FUNCTION(&_316$$93, "sprintf", &_39, 3, &_315$$93, &regexKey);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&regexKey, &_316$$93);
										ZEPHIR_INIT_NVAR(&_315$$93);
										array_init(&_315$$93);
										zephir_array_update_multi(&nodes$$88, &_315$$93, SL("szz"), 4, SL("$regex$"), &index, &regexKey);
										ZEPHIR_INIT_NVAR(&_315$$93);
										ZVAL_LONG(&_315$$93, 1);
										zephir_array_update_string(&nodes$$88, SL("$total$"), &_315$$93, PH_COPY | PH_SEPARATE);
										break;
									}
									if (!(zephir_array_isset(&nodes$$88, &item))) {
										ZEPHIR_INIT_NVAR(&_317$$107);
										array_init(&_317$$107);
										zephir_array_update_zval(&nodes$$88, &item, &_317$$107, PH_COPY | PH_SEPARATE);
									}
									if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
										ZEPHIR_INIT_NVAR(&_318$$108);
										object_init_ex(&_318$$108, moon_component_router_node_ce);
										ZEPHIR_CALL_METHOD(NULL, &_318$$108, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
										zephir_check_call_status();
										zephir_array_update_multi(&nodes$$88, &_318$$108, SL("zs"), 3, &item, SL("$node$"));
									} else {
										ZEPHIR_INIT_NVAR(&_319$$109);
										ZEPHIR_INIT_NVAR(&_320$$109);
										ZVAL_STRING(&_320$$109, "$nodes = &$nodes[$item];");
										zephir_eval_php(&_320$$109, &_319$$109, "moon/Component/Router/Router.zep:369");
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_267$$91, &uriArr, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_267$$91)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&i, &uriArr, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
									zephir_check_call_status();
										zephir_array_fetch_long(&_321$$110, &item, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 302);
										ZEPHIR_INIT_NVAR(&_322$$110);
										ZVAL_STRING(&_322$$110, "{");
										if (ZEPHIR_IS_EQUAL(&_322$$110, &_321$$110)) {
											ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_27, 153, &uriArr, &i);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&regexKey);
											ZVAL_STRING(&regexKey, "");
											zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 324);
											if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _323$$111)
												{
													ZEPHIR_INIT_NVAR(&re$$111);
													ZVAL_COPY(&re$$111, _323$$111);
													zephir_array_fetch_long(&_325$$112, &re$$111, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
													ZEPHIR_INIT_NVAR(&_326$$112);
													ZVAL_STRING(&_326$$112, "{");
													if (ZEPHIR_IS_EQUAL(&_326$$112, &_325$$112)) {
														ZEPHIR_INIT_NVAR(&_327$$113);
														ZVAL_STRING(&_327$$113, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$111, &_327$$113, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_328$$114, 1);
															ZVAL_LONG(&_329$$114, -1);
															ZEPHIR_INIT_NVAR(&_330$$114);
															zephir_substr(&_330$$114, &re$$111, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_331$$114);
															ZVAL_STRING(&_331$$114, "___");
															ZEPHIR_INIT_NVAR(&_332$$114);
															ZVAL_STRING(&_332$$114, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_333$$114, "sprintf", &_39, 3, &formatStr, &_330$$114, &_331$$114, &routeName, &_332$$114);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_333$$114);
														} else {
															ZVAL_LONG(&_334$$115, 1);
															ZVAL_LONG(&_335$$115, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_336$$115);
															zephir_substr(&_336$$115, &re$$111, 1 , zephir_get_intval(&_335$$115), 0);
															ZVAL_LONG(&_337$$115, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_338$$115, -2);
															ZEPHIR_INIT_NVAR(&_339$$115);
															zephir_substr(&_339$$115, &re$$111, zephir_get_intval(&_337$$115), -2 , 0);
															ZEPHIR_INIT_NVAR(&_340$$115);
															ZVAL_STRING(&_340$$115, "___");
															ZEPHIR_CALL_FUNCTION(&_341$$115, "sprintf", &_39, 3, &formatStr, &_336$$115, &_340$$115, &routeName, &_339$$115);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_341$$115);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_342$$116);
														ZEPHIR_CONCAT_SV(&_342$$116, "/", &re$$111);
														zephir_concat_self(&regexKey, &_342$$116);
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_324$$111, &regexArr, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_324$$111)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&re$$111, &regexArr, "current", NULL, 0);
													zephir_check_call_status();
														zephir_array_fetch_long(&_343$$117, &re$$111, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
														ZEPHIR_INIT_NVAR(&_344$$117);
														ZVAL_STRING(&_344$$117, "{");
														if (ZEPHIR_IS_EQUAL(&_344$$117, &_343$$117)) {
															ZEPHIR_INIT_NVAR(&_345$$118);
															ZVAL_STRING(&_345$$118, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$111, &_345$$118, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_346$$119, 1);
																ZVAL_LONG(&_347$$119, -1);
																ZEPHIR_INIT_NVAR(&_348$$119);
																zephir_substr(&_348$$119, &re$$111, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_349$$119);
																ZVAL_STRING(&_349$$119, "___");
																ZEPHIR_INIT_NVAR(&_350$$119);
																ZVAL_STRING(&_350$$119, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_351$$119, "sprintf", &_39, 3, &formatStr, &_348$$119, &_349$$119, &routeName, &_350$$119);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_351$$119);
															} else {
																ZVAL_LONG(&_352$$120, 1);
																ZVAL_LONG(&_353$$120, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_354$$120);
																zephir_substr(&_354$$120, &re$$111, 1 , zephir_get_intval(&_353$$120), 0);
																ZVAL_LONG(&_355$$120, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_356$$120, -2);
																ZEPHIR_INIT_NVAR(&_357$$120);
																zephir_substr(&_357$$120, &re$$111, zephir_get_intval(&_355$$120), -2 , 0);
																ZEPHIR_INIT_NVAR(&_358$$120);
																ZVAL_STRING(&_358$$120, "___");
																ZEPHIR_CALL_FUNCTION(&_359$$120, "sprintf", &_39, 3, &formatStr, &_354$$120, &_358$$120, &routeName, &_357$$120);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_359$$120);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_360$$121);
															ZEPHIR_CONCAT_SV(&_360$$121, "/", &re$$111);
															zephir_concat_self(&regexKey, &_360$$121);
														}
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&re$$111);
											zephir_array_fetch_long(&_361$$111, &regexKey, (zephir_fast_strlen_ev(&regexKey) - 1), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 324);
											ZEPHIR_INIT_NVAR(&_362$$111);
											ZVAL_STRING(&_362$$111, ")");
											if (!ZEPHIR_IS_EQUAL(&_362$$111, &_361$$111)) {
												zephir_concat_self_str(&regexKey, SL("\\b"));
											}
											if (!(zephir_array_isset_string(&nodes$$88, SL("$total$")))) {
												ZEPHIR_INIT_NVAR(&_363$$123);
												ZVAL_LONG(&_363$$123, 0);
												zephir_array_update_string(&nodes$$88, SL("$total$"), &_363$$123, PH_COPY | PH_SEPARATE);
											}
											ZEPHIR_INIT_NVAR(&index);
											ZVAL_LONG(&index, 0);
											count = 0;
											if (zephir_array_isset_string(&nodes$$88, SL("$regex$"))) {
												zephir_array_fetch_string(&_364$$124, &nodes$$88, SL("$total$"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 334);
												ZVAL_DOUBLE(&_365$$124, zephir_safe_div_zval_long(&_364$$124, 100));
												ZEPHIR_INIT_NVAR(&index);
												ZVAL_DOUBLE(&index, zephir_floor(&_365$$124));
											}
											ZEPHIR_INIT_NVAR(&_366$$111);
											ZVAL_STRING(&_366$$111, "^%s$");
											ZEPHIR_CALL_FUNCTION(&_367$$111, "sprintf", &_39, 3, &_366$$111, &regexKey);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&regexKey, &_367$$111);
											ZEPHIR_INIT_NVAR(&_366$$111);
											array_init(&_366$$111);
											zephir_array_update_multi(&nodes$$88, &_366$$111, SL("szz"), 4, SL("$regex$"), &index, &regexKey);
											ZEPHIR_INIT_NVAR(&_366$$111);
											ZVAL_LONG(&_366$$111, 1);
											zephir_array_update_string(&nodes$$88, SL("$total$"), &_366$$111, PH_COPY | PH_SEPARATE);
											break;
										}
										if (!(zephir_array_isset(&nodes$$88, &item))) {
											ZEPHIR_INIT_NVAR(&_368$$125);
											array_init(&_368$$125);
											zephir_array_update_zval(&nodes$$88, &item, &_368$$125, PH_COPY | PH_SEPARATE);
										}
										if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
											ZEPHIR_INIT_NVAR(&_369$$126);
											object_init_ex(&_369$$126, moon_component_router_node_ce);
											ZEPHIR_CALL_METHOD(NULL, &_369$$126, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
											zephir_check_call_status();
											zephir_array_update_multi(&nodes$$88, &_369$$126, SL("zs"), 3, &item, SL("$node$"));
										} else {
											ZEPHIR_INIT_NVAR(&_370$$127);
											ZEPHIR_INIT_NVAR(&_371$$127);
											ZVAL_STRING(&_371$$127, "$nodes = &$nodes[$item];");
											zephir_eval_php(&_371$$127, &_370$$127, "moon/Component/Router/Router.zep:369");
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
							ZEPHIR_INIT_NVAR(&_372$$128);
							object_init_ex(&_372$$128, moon_component_router_node_ce);
							ZEPHIR_CALL_METHOD(NULL, &_372$$128, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
							zephir_check_call_status();
							zephir_array_update_string(&nodes$$88, SL("$index$"), &_372$$128, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_INIT_NVAR(&_373$$88);
						zephir_create_array(&_373$$88, 5, 0);
						zephir_array_update_string(&_373$$88, SL("method"), &method$$87, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_373$$88, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_373$$88, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_373$$88, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_373$$88, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_374$$88);
						ZVAL_STRING(&_374$$88, "%s_%s");
						ZEPHIR_CALL_FUNCTION(&_375$$88, "sprintf", &_39, 3, &_374$$88, &method$$87, &routeName);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("routes"), &_375$$88, &_373$$88);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_255$$87, &methods, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_255$$87)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&method$$87, &methods, "current", NULL, 0);
						zephir_check_call_status();
							zephir_read_property(&_376$$129, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
							if (!(zephir_array_isset(&_376$$129, &method$$87))) {
								ZEPHIR_INIT_NVAR(&_377$$130);
								array_init(&_377$$130);
								zephir_update_property_array(this_ptr, SL("nodes"), &method$$87, &_377$$130);
							}
							if (ZEPHIR_IS_EMPTY(&routeName)) {
								ZEPHIR_INIT_NVAR(&_378$$131);
								ZEPHIR_INIT_NVAR(&_379$$131);
								ZEPHIR_CONCAT_VV(&_379$$131, &method$$87, &uri);
								zephir_md5(&_378$$131, &_379$$131);
								ZVAL_LONG(&_380$$131, 9);
								ZVAL_LONG(&_381$$131, 35);
								ZEPHIR_CALL_FUNCTION(&routeName, "base_convert", &_14, 274, &_378$$131, &_380$$131, &_381$$131);
								zephir_check_call_status();
							}
							ZEPHIR_INIT_NVAR(&_382$$129);
							ZEPHIR_INIT_NVAR(&_383$$129);
							ZVAL_STRING(&_383$$129, "$nodes = &$this->nodes[$method];");
							zephir_eval_php(&_383$$129, &_382$$129, "moon/Component/Router/Router.zep:294");
							ZEPHIR_INIT_NVAR(&_384$$129);
							zephir_fast_explode_str(&_384$$129, SL("/"), &uri, LONG_MAX);
							ZEPHIR_CALL_FUNCTION(&_385$$129, "array_filter", &_19, 161, &_384$$129);
							zephir_check_call_status();
							ZEPHIR_CALL_FUNCTION(&uriArr, "array_values", &_20, 98, &_385$$129);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&length);
							ZVAL_LONG(&length, zephir_fast_count_int(&uriArr));
							if (!(ZEPHIR_IS_EMPTY(&uriArr))) {
								zephir_is_iterable(&uriArr, 0, "moon/Component/Router/Router.zep", 372);
								if (Z_TYPE_P(&uriArr) == IS_ARRAY) {
									ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&uriArr), _388$$132, _389$$132, _386$$132)
									{
										ZEPHIR_INIT_NVAR(&i);
										if (_389$$132 != NULL) { 
											ZVAL_STR_COPY(&i, _389$$132);
										} else {
											ZVAL_LONG(&i, _388$$132);
										}
										ZEPHIR_INIT_NVAR(&item);
										ZVAL_COPY(&item, _386$$132);
										zephir_array_fetch_long(&_390$$133, &item, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 302);
										ZEPHIR_INIT_NVAR(&_391$$133);
										ZVAL_STRING(&_391$$133, "{");
										if (ZEPHIR_IS_EQUAL(&_391$$133, &_390$$133)) {
											ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_27, 153, &uriArr, &i);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&regexKey);
											ZVAL_STRING(&regexKey, "");
											zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 324);
											if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
												ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _392$$134)
												{
													ZEPHIR_INIT_NVAR(&re$$134);
													ZVAL_COPY(&re$$134, _392$$134);
													zephir_array_fetch_long(&_394$$135, &re$$134, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
													ZEPHIR_INIT_NVAR(&_395$$135);
													ZVAL_STRING(&_395$$135, "{");
													if (ZEPHIR_IS_EQUAL(&_395$$135, &_394$$135)) {
														ZEPHIR_INIT_NVAR(&_396$$136);
														ZVAL_STRING(&_396$$136, "<");
														ZEPHIR_INIT_NVAR(&regexPos);
														zephir_fast_strpos(&regexPos, &re$$134, &_396$$136, 0 );
														ZEPHIR_INIT_NVAR(&formatStr);
														ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
														if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
															ZVAL_LONG(&_397$$137, 1);
															ZVAL_LONG(&_398$$137, -1);
															ZEPHIR_INIT_NVAR(&_399$$137);
															zephir_substr(&_399$$137, &re$$134, 1 , -1 , 0);
															ZEPHIR_INIT_NVAR(&_400$$137);
															ZVAL_STRING(&_400$$137, "___");
															ZEPHIR_INIT_NVAR(&_401$$137);
															ZVAL_STRING(&_401$$137, "[^/]+");
															ZEPHIR_CALL_FUNCTION(&_402$$137, "sprintf", &_39, 3, &formatStr, &_399$$137, &_400$$137, &routeName, &_401$$137);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_402$$137);
														} else {
															ZVAL_LONG(&_403$$138, 1);
															ZVAL_LONG(&_404$$138, (zephir_get_numberval(&regexPos) - 1));
															ZEPHIR_INIT_NVAR(&_405$$138);
															zephir_substr(&_405$$138, &re$$134, 1 , zephir_get_intval(&_404$$138), 0);
															ZVAL_LONG(&_406$$138, (zephir_get_numberval(&regexPos) + 1));
															ZVAL_LONG(&_407$$138, -2);
															ZEPHIR_INIT_NVAR(&_408$$138);
															zephir_substr(&_408$$138, &re$$134, zephir_get_intval(&_406$$138), -2 , 0);
															ZEPHIR_INIT_NVAR(&_409$$138);
															ZVAL_STRING(&_409$$138, "___");
															ZEPHIR_CALL_FUNCTION(&_410$$138, "sprintf", &_39, 3, &formatStr, &_405$$138, &_409$$138, &routeName, &_408$$138);
															zephir_check_call_status();
															zephir_concat_self(&regexKey, &_410$$138);
														}
													} else {
														ZEPHIR_INIT_NVAR(&_411$$139);
														ZEPHIR_CONCAT_SV(&_411$$139, "/", &re$$134);
														zephir_concat_self(&regexKey, &_411$$139);
													}
												} ZEND_HASH_FOREACH_END();
											} else {
												ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
												zephir_check_call_status();
												while (1) {
													ZEPHIR_CALL_METHOD(&_393$$134, &regexArr, "valid", NULL, 0);
													zephir_check_call_status();
													if (!zend_is_true(&_393$$134)) {
														break;
													}
													ZEPHIR_CALL_METHOD(&re$$134, &regexArr, "current", NULL, 0);
													zephir_check_call_status();
														zephir_array_fetch_long(&_412$$140, &re$$134, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
														ZEPHIR_INIT_NVAR(&_413$$140);
														ZVAL_STRING(&_413$$140, "{");
														if (ZEPHIR_IS_EQUAL(&_413$$140, &_412$$140)) {
															ZEPHIR_INIT_NVAR(&_414$$141);
															ZVAL_STRING(&_414$$141, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$134, &_414$$141, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_415$$142, 1);
																ZVAL_LONG(&_416$$142, -1);
																ZEPHIR_INIT_NVAR(&_417$$142);
																zephir_substr(&_417$$142, &re$$134, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_418$$142);
																ZVAL_STRING(&_418$$142, "___");
																ZEPHIR_INIT_NVAR(&_419$$142);
																ZVAL_STRING(&_419$$142, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_420$$142, "sprintf", &_39, 3, &formatStr, &_417$$142, &_418$$142, &routeName, &_419$$142);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_420$$142);
															} else {
																ZVAL_LONG(&_421$$143, 1);
																ZVAL_LONG(&_422$$143, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_423$$143);
																zephir_substr(&_423$$143, &re$$134, 1 , zephir_get_intval(&_422$$143), 0);
																ZVAL_LONG(&_424$$143, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_425$$143, -2);
																ZEPHIR_INIT_NVAR(&_426$$143);
																zephir_substr(&_426$$143, &re$$134, zephir_get_intval(&_424$$143), -2 , 0);
																ZEPHIR_INIT_NVAR(&_427$$143);
																ZVAL_STRING(&_427$$143, "___");
																ZEPHIR_CALL_FUNCTION(&_428$$143, "sprintf", &_39, 3, &formatStr, &_423$$143, &_427$$143, &routeName, &_426$$143);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_428$$143);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_429$$144);
															ZEPHIR_CONCAT_SV(&_429$$144, "/", &re$$134);
															zephir_concat_self(&regexKey, &_429$$144);
														}
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
													zephir_check_call_status();
												}
											}
											ZEPHIR_INIT_NVAR(&re$$134);
											zephir_array_fetch_long(&_430$$134, &regexKey, (zephir_fast_strlen_ev(&regexKey) - 1), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 324);
											ZEPHIR_INIT_NVAR(&_431$$134);
											ZVAL_STRING(&_431$$134, ")");
											if (!ZEPHIR_IS_EQUAL(&_431$$134, &_430$$134)) {
												zephir_concat_self_str(&regexKey, SL("\\b"));
											}
											if (!(zephir_array_isset_string(&nodes$$129, SL("$total$")))) {
												ZEPHIR_INIT_NVAR(&_432$$146);
												ZVAL_LONG(&_432$$146, 0);
												zephir_array_update_string(&nodes$$129, SL("$total$"), &_432$$146, PH_COPY | PH_SEPARATE);
											}
											ZEPHIR_INIT_NVAR(&index);
											ZVAL_LONG(&index, 0);
											count = 0;
											if (zephir_array_isset_string(&nodes$$129, SL("$regex$"))) {
												zephir_array_fetch_string(&_433$$147, &nodes$$129, SL("$total$"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 334);
												ZVAL_DOUBLE(&_434$$147, zephir_safe_div_zval_long(&_433$$147, 100));
												ZEPHIR_INIT_NVAR(&index);
												ZVAL_DOUBLE(&index, zephir_floor(&_434$$147));
											}
											ZEPHIR_INIT_NVAR(&_435$$134);
											ZVAL_STRING(&_435$$134, "^%s$");
											ZEPHIR_CALL_FUNCTION(&_436$$134, "sprintf", &_39, 3, &_435$$134, &regexKey);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&regexKey, &_436$$134);
											ZEPHIR_INIT_NVAR(&_435$$134);
											array_init(&_435$$134);
											zephir_array_update_multi(&nodes$$129, &_435$$134, SL("szz"), 4, SL("$regex$"), &index, &regexKey);
											ZEPHIR_INIT_NVAR(&_435$$134);
											ZVAL_LONG(&_435$$134, 1);
											zephir_array_update_string(&nodes$$129, SL("$total$"), &_435$$134, PH_COPY | PH_SEPARATE);
											break;
										}
										if (!(zephir_array_isset(&nodes$$129, &item))) {
											ZEPHIR_INIT_NVAR(&_437$$148);
											array_init(&_437$$148);
											zephir_array_update_zval(&nodes$$129, &item, &_437$$148, PH_COPY | PH_SEPARATE);
										}
										if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
											ZEPHIR_INIT_NVAR(&_438$$149);
											object_init_ex(&_438$$149, moon_component_router_node_ce);
											ZEPHIR_CALL_METHOD(NULL, &_438$$149, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
											zephir_check_call_status();
											zephir_array_update_multi(&nodes$$129, &_438$$149, SL("zs"), 3, &item, SL("$node$"));
										} else {
											ZEPHIR_INIT_NVAR(&_439$$150);
											ZEPHIR_INIT_NVAR(&_440$$150);
											ZVAL_STRING(&_440$$150, "$nodes = &$nodes[$item];");
											zephir_eval_php(&_440$$150, &_439$$150, "moon/Component/Router/Router.zep:369");
										}
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &uriArr, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_387$$132, &uriArr, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_387$$132)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&i, &uriArr, "key", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&item, &uriArr, "current", NULL, 0);
										zephir_check_call_status();
											zephir_array_fetch_long(&_441$$151, &item, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 302);
											ZEPHIR_INIT_NVAR(&_442$$151);
											ZVAL_STRING(&_442$$151, "{");
											if (ZEPHIR_IS_EQUAL(&_442$$151, &_441$$151)) {
												ZEPHIR_CALL_FUNCTION(&regexArr, "array_slice", &_27, 153, &uriArr, &i);
												zephir_check_call_status();
												ZEPHIR_INIT_NVAR(&regexKey);
												ZVAL_STRING(&regexKey, "");
												zephir_is_iterable(&regexArr, 0, "moon/Component/Router/Router.zep", 324);
												if (Z_TYPE_P(&regexArr) == IS_ARRAY) {
													ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&regexArr), _443$$152)
													{
														ZEPHIR_INIT_NVAR(&re$$152);
														ZVAL_COPY(&re$$152, _443$$152);
														zephir_array_fetch_long(&_445$$153, &re$$152, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
														ZEPHIR_INIT_NVAR(&_446$$153);
														ZVAL_STRING(&_446$$153, "{");
														if (ZEPHIR_IS_EQUAL(&_446$$153, &_445$$153)) {
															ZEPHIR_INIT_NVAR(&_447$$154);
															ZVAL_STRING(&_447$$154, "<");
															ZEPHIR_INIT_NVAR(&regexPos);
															zephir_fast_strpos(&regexPos, &re$$152, &_447$$154, 0 );
															ZEPHIR_INIT_NVAR(&formatStr);
															ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
															if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																ZVAL_LONG(&_448$$155, 1);
																ZVAL_LONG(&_449$$155, -1);
																ZEPHIR_INIT_NVAR(&_450$$155);
																zephir_substr(&_450$$155, &re$$152, 1 , -1 , 0);
																ZEPHIR_INIT_NVAR(&_451$$155);
																ZVAL_STRING(&_451$$155, "___");
																ZEPHIR_INIT_NVAR(&_452$$155);
																ZVAL_STRING(&_452$$155, "[^/]+");
																ZEPHIR_CALL_FUNCTION(&_453$$155, "sprintf", &_39, 3, &formatStr, &_450$$155, &_451$$155, &routeName, &_452$$155);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_453$$155);
															} else {
																ZVAL_LONG(&_454$$156, 1);
																ZVAL_LONG(&_455$$156, (zephir_get_numberval(&regexPos) - 1));
																ZEPHIR_INIT_NVAR(&_456$$156);
																zephir_substr(&_456$$156, &re$$152, 1 , zephir_get_intval(&_455$$156), 0);
																ZVAL_LONG(&_457$$156, (zephir_get_numberval(&regexPos) + 1));
																ZVAL_LONG(&_458$$156, -2);
																ZEPHIR_INIT_NVAR(&_459$$156);
																zephir_substr(&_459$$156, &re$$152, zephir_get_intval(&_457$$156), -2 , 0);
																ZEPHIR_INIT_NVAR(&_460$$156);
																ZVAL_STRING(&_460$$156, "___");
																ZEPHIR_CALL_FUNCTION(&_461$$156, "sprintf", &_39, 3, &formatStr, &_456$$156, &_460$$156, &routeName, &_459$$156);
																zephir_check_call_status();
																zephir_concat_self(&regexKey, &_461$$156);
															}
														} else {
															ZEPHIR_INIT_NVAR(&_462$$157);
															ZEPHIR_CONCAT_SV(&_462$$157, "/", &re$$152);
															zephir_concat_self(&regexKey, &_462$$157);
														}
													} ZEND_HASH_FOREACH_END();
												} else {
													ZEPHIR_CALL_METHOD(NULL, &regexArr, "rewind", NULL, 0);
													zephir_check_call_status();
													while (1) {
														ZEPHIR_CALL_METHOD(&_444$$152, &regexArr, "valid", NULL, 0);
														zephir_check_call_status();
														if (!zend_is_true(&_444$$152)) {
															break;
														}
														ZEPHIR_CALL_METHOD(&re$$152, &regexArr, "current", NULL, 0);
														zephir_check_call_status();
															zephir_array_fetch_long(&_463$$158, &re$$152, 0, PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 309);
															ZEPHIR_INIT_NVAR(&_464$$158);
															ZVAL_STRING(&_464$$158, "{");
															if (ZEPHIR_IS_EQUAL(&_464$$158, &_463$$158)) {
																ZEPHIR_INIT_NVAR(&_465$$159);
																ZVAL_STRING(&_465$$159, "<");
																ZEPHIR_INIT_NVAR(&regexPos);
																zephir_fast_strpos(&regexPos, &re$$152, &_465$$159, 0 );
																ZEPHIR_INIT_NVAR(&formatStr);
																ZVAL_STRING(&formatStr, "/(?P<%s%s%s>%s)");
																if (ZEPHIR_IS_FALSE_IDENTICAL(&regexPos)) {
																	ZVAL_LONG(&_466$$160, 1);
																	ZVAL_LONG(&_467$$160, -1);
																	ZEPHIR_INIT_NVAR(&_468$$160);
																	zephir_substr(&_468$$160, &re$$152, 1 , -1 , 0);
																	ZEPHIR_INIT_NVAR(&_469$$160);
																	ZVAL_STRING(&_469$$160, "___");
																	ZEPHIR_INIT_NVAR(&_470$$160);
																	ZVAL_STRING(&_470$$160, "[^/]+");
																	ZEPHIR_CALL_FUNCTION(&_471$$160, "sprintf", &_39, 3, &formatStr, &_468$$160, &_469$$160, &routeName, &_470$$160);
																	zephir_check_call_status();
																	zephir_concat_self(&regexKey, &_471$$160);
																} else {
																	ZVAL_LONG(&_472$$161, 1);
																	ZVAL_LONG(&_473$$161, (zephir_get_numberval(&regexPos) - 1));
																	ZEPHIR_INIT_NVAR(&_474$$161);
																	zephir_substr(&_474$$161, &re$$152, 1 , zephir_get_intval(&_473$$161), 0);
																	ZVAL_LONG(&_475$$161, (zephir_get_numberval(&regexPos) + 1));
																	ZVAL_LONG(&_476$$161, -2);
																	ZEPHIR_INIT_NVAR(&_477$$161);
																	zephir_substr(&_477$$161, &re$$152, zephir_get_intval(&_475$$161), -2 , 0);
																	ZEPHIR_INIT_NVAR(&_478$$161);
																	ZVAL_STRING(&_478$$161, "___");
																	ZEPHIR_CALL_FUNCTION(&_479$$161, "sprintf", &_39, 3, &formatStr, &_474$$161, &_478$$161, &routeName, &_477$$161);
																	zephir_check_call_status();
																	zephir_concat_self(&regexKey, &_479$$161);
																}
															} else {
																ZEPHIR_INIT_NVAR(&_480$$162);
																ZEPHIR_CONCAT_SV(&_480$$162, "/", &re$$152);
																zephir_concat_self(&regexKey, &_480$$162);
															}
														ZEPHIR_CALL_METHOD(NULL, &regexArr, "next", NULL, 0);
														zephir_check_call_status();
													}
												}
												ZEPHIR_INIT_NVAR(&re$$152);
												zephir_array_fetch_long(&_481$$152, &regexKey, (zephir_fast_strlen_ev(&regexKey) - 1), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 324);
												ZEPHIR_INIT_NVAR(&_482$$152);
												ZVAL_STRING(&_482$$152, ")");
												if (!ZEPHIR_IS_EQUAL(&_482$$152, &_481$$152)) {
													zephir_concat_self_str(&regexKey, SL("\\b"));
												}
												if (!(zephir_array_isset_string(&nodes$$129, SL("$total$")))) {
													ZEPHIR_INIT_NVAR(&_483$$164);
													ZVAL_LONG(&_483$$164, 0);
													zephir_array_update_string(&nodes$$129, SL("$total$"), &_483$$164, PH_COPY | PH_SEPARATE);
												}
												ZEPHIR_INIT_NVAR(&index);
												ZVAL_LONG(&index, 0);
												count = 0;
												if (zephir_array_isset_string(&nodes$$129, SL("$regex$"))) {
													zephir_array_fetch_string(&_484$$165, &nodes$$129, SL("$total$"), PH_NOISY | PH_READONLY, "moon/Component/Router/Router.zep", 334);
													ZVAL_DOUBLE(&_485$$165, zephir_safe_div_zval_long(&_484$$165, 100));
													ZEPHIR_INIT_NVAR(&index);
													ZVAL_DOUBLE(&index, zephir_floor(&_485$$165));
												}
												ZEPHIR_INIT_NVAR(&_486$$152);
												ZVAL_STRING(&_486$$152, "^%s$");
												ZEPHIR_CALL_FUNCTION(&_487$$152, "sprintf", &_39, 3, &_486$$152, &regexKey);
												zephir_check_call_status();
												ZEPHIR_CPY_WRT(&regexKey, &_487$$152);
												ZEPHIR_INIT_NVAR(&_486$$152);
												array_init(&_486$$152);
												zephir_array_update_multi(&nodes$$129, &_486$$152, SL("szz"), 4, SL("$regex$"), &index, &regexKey);
												ZEPHIR_INIT_NVAR(&_486$$152);
												ZVAL_LONG(&_486$$152, 1);
												zephir_array_update_string(&nodes$$129, SL("$total$"), &_486$$152, PH_COPY | PH_SEPARATE);
												break;
											}
											if (!(zephir_array_isset(&nodes$$129, &item))) {
												ZEPHIR_INIT_NVAR(&_488$$166);
												array_init(&_488$$166);
												zephir_array_update_zval(&nodes$$129, &item, &_488$$166, PH_COPY | PH_SEPARATE);
											}
											if (ZEPHIR_IS_LONG(&i, (zephir_get_numberval(&length) - 1))) {
												ZEPHIR_INIT_NVAR(&_489$$167);
												object_init_ex(&_489$$167, moon_component_router_node_ce);
												ZEPHIR_CALL_METHOD(NULL, &_489$$167, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
												zephir_check_call_status();
												zephir_array_update_multi(&nodes$$129, &_489$$167, SL("zs"), 3, &item, SL("$node$"));
											} else {
												ZEPHIR_INIT_NVAR(&_490$$168);
												ZEPHIR_INIT_NVAR(&_491$$168);
												ZVAL_STRING(&_491$$168, "$nodes = &$nodes[$item];");
												zephir_eval_php(&_491$$168, &_490$$168, "moon/Component/Router/Router.zep:369");
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
								ZEPHIR_INIT_NVAR(&_492$$169);
								object_init_ex(&_492$$169, moon_component_router_node_ce);
								ZEPHIR_CALL_METHOD(NULL, &_492$$169, "__construct", &_76, 272, &uri, &handler, &routeName, &priority);
								zephir_check_call_status();
								zephir_array_update_string(&nodes$$129, SL("$index$"), &_492$$169, PH_COPY | PH_SEPARATE);
							}
							ZEPHIR_INIT_NVAR(&_493$$129);
							zephir_create_array(&_493$$129, 5, 0);
							zephir_array_update_string(&_493$$129, SL("method"), &method$$87, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_493$$129, SL("uri"), &uri, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_493$$129, SL("handler"), &handler, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_493$$129, SL("routeName"), &routeName, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_493$$129, SL("priority"), &priority, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_494$$129);
							ZVAL_STRING(&_494$$129, "%s_%s");
							ZEPHIR_CALL_FUNCTION(&_495$$129, "sprintf", &_39, 3, &_494$$129, &method$$87, &routeName);
							zephir_check_call_status();
							zephir_update_property_array(this_ptr, SL("routes"), &_495$$129, &_493$$129);
						ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&method$$87);
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
	ZEPHIR_CALL_METHOD(&_4, &_3, "resolverhandler", NULL, 275, &_5);
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
	ZEPHIR_CALL_METHOD(&_7, &_6, "resolverargument", NULL, 276, &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_4, &_7);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Moon_Component_Router_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("priority"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("priority"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("routers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routers"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("routes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("routes"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("nodes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("nodes"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

