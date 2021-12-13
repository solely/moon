
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/require.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * FileName: Bootstrap.php
 * User: solely
 * DateTime: 2020/5/4 23:24
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(Moon\\Framework, Bootstrap, moon, framework_bootstrap, moon_framework_bootstrap_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/** @var ContainerInterface */
	zend_declare_property_null(moon_framework_bootstrap_ce, SL("container"), ZEND_ACC_PRIVATE);

	/** @var ModulesInterface[] */
	zend_declare_property_null(moon_framework_bootstrap_ce, SL("modules"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_framework_bootstrap_ce, SL("projectDir"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_framework_bootstrap_ce, SL("environ"), ZEND_ACC_PRIVATE);

	moon_framework_bootstrap_ce->create_object = zephir_init_properties_Moon_Framework_Bootstrap;
	zephir_declare_class_constant_string(moon_framework_bootstrap_ce, SL("MOON_VERSION"), "0.0.4");

	zephir_declare_class_constant_string(moon_framework_bootstrap_ce, SL("MOON_VERSION_ID"), "4");

	zend_class_implements(moon_framework_bootstrap_ce, 1, moon_framework_bootstrapinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Bootstrap, __construct) {

	zval *environ = NULL, environ_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&environ_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params_without_memory_grow(0, 1, &environ);

	if (!environ) {
		environ = &environ_sub;
		environ = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("environ"), environ);

}

PHP_METHOD(Moon_Framework_Bootstrap, handle) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "boot", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getkernel", NULL, 161);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "handle", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Framework_Bootstrap, boot) {

	zval module, _0, *_1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializemodules", NULL, 162);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializecontainer", NULL, 163);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodules", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "moon/Framework/Bootstrap.zep", 55);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&module);
			ZVAL_COPY(&module, _1);
			ZEPHIR_CALL_METHOD(NULL, &module, "boot", NULL, 0);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&module, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &module, "boot", NULL, 0);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&module);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Bootstrap, getKernel) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "kernel");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Framework_Bootstrap, getRouter) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "router");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Framework_Bootstrap, initializeModules) {

	zval name, _0, module, _1, *_2, _3, _4$$3, _5$$4, _6$$4, _7$$4, _10$$5, _11$$6, _12$$6, _13$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("modules"), &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "registermodules", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "moon/Framework/Bootstrap.zep", 81);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&module);
			ZVAL_COPY(&module, _2);
			ZEPHIR_CALL_METHOD(&name, &module, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_4$$3, &name)) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				object_init_ex(&_5$$4, spl_ce_LogicException);
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZVAL_STRING(&_6$$4, "Trying to register two modules with the same name \"%s\".");
				ZEPHIR_CALL_FUNCTION(&_7$$4, "sprintf", &_8, 3, &_6$$4, &name);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", &_9, 164, &_7$$4);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$4, "moon/Framework/Bootstrap.zep", 77);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_array(this_ptr, SL("modules"), &name, &module);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&module, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&name, &module, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_read_property(&_10$$5, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_10$$5, &name)) {
					ZEPHIR_INIT_NVAR(&_11$$6);
					object_init_ex(&_11$$6, spl_ce_LogicException);
					ZEPHIR_INIT_NVAR(&_12$$6);
					ZVAL_STRING(&_12$$6, "Trying to register two modules with the same name \"%s\".");
					ZEPHIR_CALL_FUNCTION(&_13$$6, "sprintf", &_8, 3, &_12$$6, &name);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_11$$6, "__construct", &_9, 164, &_13$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$6, "moon/Framework/Bootstrap.zep", 77);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_update_property_array(this_ptr, SL("modules"), &name, &module);
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&module);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Bootstrap, initializeContainer) {

	zval provider, container, _1, _2, module, *_3, _4, _5, _6, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_7 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, moon_component_di_inject_ce);
	if (zephir_has_constructor(&_1)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZVAL_NULL(&_2);
	ZEPHIR_CALL_CE_STATIC(&container, moon_component_di_container_ce, "getinstance", &_0, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_2, 0, "moon/Framework/Bootstrap.zep", 98);
	if (Z_TYPE_P(&_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _3)
		{
			ZEPHIR_INIT_NVAR(&module);
			ZVAL_COPY(&module, _3);
			ZEPHIR_CALL_METHOD(NULL, &module, "build", NULL, 0, &container);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_2, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &_2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&module, &_2, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &module, "build", NULL, 0, &container);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_2, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&module);
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &container);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializeconfig", NULL, 165);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializeroutes", NULL, 166);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "bootstrap");
	ZEPHIR_CALL_METHOD(NULL, &_5, "set", NULL, 0, &_6, this_ptr);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&provider, moon_framework_event_event_ce, "registerevent", &_7, 0, &_8);
	zephir_check_call_status();
	zephir_read_property(&_9, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_6);
	object_init_ex(&_6, moon_component_eventdispatcher_eventdispatcher_ce);
	ZVAL_NULL(&_10);
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 167, &provider, &_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "dispatcher");
	ZEPHIR_CALL_METHOD(NULL, &_9, "set", NULL, 0, &_11, &_6);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_11);
	object_init_ex(&_11, moon_framework_controller_controllerresolver_ce);
	if (zephir_has_constructor(&_11)) {
		ZEPHIR_CALL_METHOD(NULL, &_11, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "controller_resolver");
	ZEPHIR_CALL_METHOD(NULL, &_10, "set", NULL, 0, &_12, &_11);
	zephir_check_call_status();
	zephir_read_property(&_13, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_12);
	object_init_ex(&_12, moon_framework_controller_controllerargumentsresolver_ce);
	if (zephir_has_constructor(&_12)) {
		ZEPHIR_CALL_METHOD(NULL, &_12, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "controller_arguments_resolver");
	ZEPHIR_CALL_METHOD(NULL, &_13, "set", NULL, 0, &_14, &_12);
	zephir_check_call_status();
	zephir_read_property(&_15, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_14);
	object_init_ex(&_14, moon_framework_kernel_ce);
	zephir_read_property(&_16, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_14, "__construct", NULL, 168, &_16);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, "kernel");
	ZEPHIR_CALL_METHOD(NULL, &_15, "set", NULL, 0, &_17, &_14);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Bootstrap, initializeConfig) {

	zend_bool _10$$3, _11$$3, _14$$5, _15$$5;
	zend_string *_9;
	zend_ulong _8;
	zval services, config, configInstance, _1, _2, _3, _4, key, item, _5, *_6, _7, _12$$3, _13$$4, _16$$5, _17$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&configInstance);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&configInstance, moon_component_config_config_ce, "getinstance", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getconfigdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&config, &configInstance, "loaddir", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "config");
	ZEPHIR_CALL_METHOD(NULL, &_2, "set", NULL, 0, &_3, &config);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getservicesdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&services, &configInstance, "loaddir", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &services, "get", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_5, 0, "moon/Framework/Bootstrap.zep", 139);
	if (Z_TYPE_P(&_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_5), _8, _9, _6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&key, _9);
			} else {
				ZVAL_LONG(&key, _8);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _6);
			_10$$3 = Z_TYPE_P(&key) == IS_STRING;
			if (_10$$3) {
				_10$$3 = zephir_array_isset_string(&item, SL("type"));
			}
			_11$$3 = _10$$3;
			if (_11$$3) {
				zephir_array_fetch_string(&_12$$3, &item, SL("type"), PH_NOISY | PH_READONLY, "moon/Framework/Bootstrap.zep", 131);
				_11$$3 = ZEPHIR_IS_STRING(&_12$$3, "service");
			}
			if (_11$$3) {
				zephir_read_property(&_13$$4, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_13$$4, "set", NULL, 0, &key, &item);
				zephir_check_call_status();
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
			ZEPHIR_CALL_METHOD(&key, &_5, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&item, &_5, "current", NULL, 0);
			zephir_check_call_status();
				_14$$5 = Z_TYPE_P(&key) == IS_STRING;
				if (_14$$5) {
					_14$$5 = zephir_array_isset_string(&item, SL("type"));
				}
				_15$$5 = _14$$5;
				if (_15$$5) {
					zephir_array_fetch_string(&_16$$5, &item, SL("type"), PH_NOISY | PH_READONLY, "moon/Framework/Bootstrap.zep", 131);
					_15$$5 = ZEPHIR_IS_STRING(&_16$$5, "service");
				}
				if (_15$$5) {
					zephir_read_property(&_17$$6, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_17$$6, "set", NULL, 0, &key, &item);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &_5, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Bootstrap, initializeRoutes) {

	zval routesFn, router, routerFile, _9, _10, _0$$3, _5$$3, _1$$4, _2$$4, _3$$4, _6$$5, _7$$5, _8$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routesFn);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&routerFile);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&routerFile, this_ptr, "getroutesfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&router);
	object_init_ex(&router, moon_component_router_router_ce);
	if (zephir_has_constructor(&router)) {
		ZEPHIR_CALL_METHOD(NULL, &router, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (!(ZEPHIR_IS_EMPTY(&routerFile))) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "is_file", NULL, 49, &routerFile);
		zephir_check_call_status();
		if (!zephir_is_true(&_0$$3)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, spl_ce_RuntimeException);
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "File %s was not found.");
			ZEPHIR_CALL_FUNCTION(&_3$$4, "sprintf", &_4, 3, &_2$$4, &routerFile);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 26, &_3$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "moon/Framework/Bootstrap.zep", 151);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_5$$3);
		if (zephir_require_zval_ret(&_5$$3, &routerFile) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CPY_WRT(&routesFn, &_5$$3);
		if (zephir_is_callable(&routesFn) != 1) {
			ZEPHIR_INIT_VAR(&_6$$5);
			object_init_ex(&_6$$5, spl_ce_RuntimeException);
			ZEPHIR_INIT_VAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "File %s must return an executable function.");
			ZEPHIR_CALL_FUNCTION(&_8$$5, "sprintf", &_4, 3, &_7$$5, &routerFile);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 26, &_8$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$5, "moon/Framework/Bootstrap.zep", 155);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_ZVAL_FUNCTION(NULL, &routesFn, NULL, 0, &router);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &router, "addroutes", NULL, 169);
		zephir_check_call_status();
	}
	zephir_read_property(&_9, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "router");
	ZEPHIR_CALL_METHOD(NULL, &_9, "set", NULL, 0, &_10, &router);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Bootstrap, getModule) {

	zend_bool _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _class, _0, _11, _12, _1$$3, _2$$3, _3$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_class);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_class);
		zephir_get_called_class(&_class);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_array_fetch_long(&_2$$3, &_class, 0, PH_NOISY | PH_READONLY, "moon/Framework/Bootstrap.zep", 168);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "c");
		_4$$3 = ZEPHIR_IS_IDENTICAL(&_3$$3, &_2$$3);
		if (_4$$3) {
			ZEPHIR_INIT_VAR(&_5$$3);
			ZVAL_STRING(&_5$$3, "class@anonymous\0");
			ZEPHIR_INIT_VAR(&_6$$3);
			zephir_fast_strpos(&_6$$3, &_class, &_5$$3, 0 );
			_4$$3 = ZEPHIR_IS_LONG_IDENTICAL(&_6$$3, 0);
		}
		if (_4$$3) {
			ZEPHIR_CALL_FUNCTION(&_7$$3, "get_parent_class", NULL, 66, &_class);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZEPHIR_CONCAT_VS(&_1$$3, &_7$$3, "@anonymous");
		} else {
			ZEPHIR_CPY_WRT(&_1$$3, &_class);
		}
		ZEPHIR_CPY_WRT(&_class, &_1$$3);
		ZEPHIR_INIT_VAR(&_8$$3);
		object_init_ex(&_8$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "Module \"%s\" does not exist or it is not enabled. Maybe you forgot to add it in the \"registerModules()\" method of your \"%s.php\" file?");
		ZEPHIR_CALL_FUNCTION(&_10$$3, "sprintf", NULL, 3, &_9$$3, &name, &_class);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_8$$3, "__construct", NULL, 25, &_10$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$3, "moon/Framework/Bootstrap.zep", 169);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_11, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_12, &_11, &name, PH_NOISY | PH_READONLY, "moon/Framework/Bootstrap.zep", 171);
	RETURN_CTOR(&_12);

}

PHP_METHOD(Moon_Framework_Bootstrap, getModules) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "modules");

}

PHP_METHOD(Moon_Framework_Bootstrap, shutdown) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Moon_Framework_Bootstrap, getProjectDir) {

	zval rootDir, dir, r, _0, _1$$4, _2$$4, _3$$4, _4$$4, _6$$3, _7$$5, _8$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rootDir);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("projectDir"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&r);
		object_init_ex(&r, zephir_get_internal_ce(SL("reflectionobject")));
		ZEPHIR_CALL_METHOD(NULL, &r, "__construct", NULL, 21, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&dir, &r, "getfilename", NULL, 170);
		zephir_check_call_status();
		if (!((zephir_file_exists(&dir) == SUCCESS))) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, spl_ce_LogicException);
			zephir_read_property(&_2$$4, &r, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "Cannot auto-detect project dir for bootstrap of class \"%s\".");
			ZEPHIR_CALL_FUNCTION(&_4$$4, "sprintf", NULL, 3, &_3$$4, &_2$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 164, &_4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "moon/Framework/Bootstrap.zep", 193);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&rootDir, "dirname", &_5, 128, &dir);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&dir, &rootDir);
		while (1) {
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_CONCAT_VS(&_6$$3, &dir, "/composer.json");
			if (!(!((zephir_file_exists(&_6$$3) == SUCCESS)))) {
				break;
			}
			ZEPHIR_CALL_FUNCTION(&_7$$5, "dirname", &_5, 128, &dir);
			zephir_check_call_status();
			if (ZEPHIR_IS_IDENTICAL(&dir, &_7$$5)) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("projectDir"), &rootDir);
				RETURN_CCTOR(&rootDir);
			}
			ZEPHIR_CALL_FUNCTION(&_8$$5, "dirname", &_5, 128, &dir);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&dir, &_8$$5);
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("projectDir"), &dir);
	}
	RETURN_MM_MEMBER(getThis(), "projectDir");

}

PHP_METHOD(Moon_Framework_Bootstrap, getContainer) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

PHP_METHOD(Moon_Framework_Bootstrap, getLogDir) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprojectdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VS(return_value, &_0, "/log");
	RETURN_MM();

}

PHP_METHOD(Moon_Framework_Bootstrap, getConfigDir) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprojectdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VS(return_value, &_0, "/config");
	RETURN_MM();

}

PHP_METHOD(Moon_Framework_Bootstrap, getServicesDir) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconfigdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VS(return_value, &_0, "/services");
	RETURN_MM();

}

PHP_METHOD(Moon_Framework_Bootstrap, getRoutesFile) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconfigdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VS(return_value, &_0, "/routes.php");
	RETURN_MM();

}

PHP_METHOD(Moon_Framework_Bootstrap, getMoonVersion) {

	zval *this_ptr = getThis();


	RETURN_STRING("0.0.4");

}

PHP_METHOD(Moon_Framework_Bootstrap, getMoonVersionId) {

	zval *this_ptr = getThis();


	RETURN_STRING("4");

}

PHP_METHOD(Moon_Framework_Bootstrap, getEnviron) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("environ"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_1))) {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("environ"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "moon.environ");
		ZEPHIR_CALL_FUNCTION(&_0, "ini_get", NULL, 171, &_2);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

zend_object *zephir_init_properties_Moon_Framework_Bootstrap(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("modules"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

