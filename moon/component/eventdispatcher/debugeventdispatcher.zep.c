
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
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * FileName: DebugEventDispatcher.php
 * User: solely
 * DateTime: 2019/9/23 23:39
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_DebugEventDispatcher) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\EventDispatcher, DebugEventDispatcher, moon, component_eventdispatcher_debugeventdispatcher, moon_component_eventdispatcher_debugeventdispatcher_method_entry, 0);

	zend_declare_property_null(moon_component_eventdispatcher_debugeventdispatcher_ce, SL("dispatcher"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_eventdispatcher_debugeventdispatcher_ce, SL("logger"), ZEND_ACC_PRIVATE);

	zend_class_implements(moon_component_eventdispatcher_debugeventdispatcher_ce, 1, zephir_get_internal_ce(SL("psrext\\eventdispatcher\\eventdispatcherinterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_EventDispatcher_DebugEventDispatcher, __construct) {

	zval *dispatcher, dispatcher_sub, *logger, logger_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dispatcher_sub);
	ZVAL_UNDEF(&logger_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &dispatcher, &logger);



	zephir_update_property_zval(this_ptr, ZEND_STRL("dispatcher"), dispatcher);
	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), logger);

}

PHP_METHOD(Moon_Component_EventDispatcher_DebugEventDispatcher, dispatch) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_class(&_2, event, 0);
	zephir_array_update_string(&_1, SL("type"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("event"), event, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Processing event of type {type}.");
	ZEPHIR_CALL_METHOD(NULL, &_0, "debug", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("dispatcher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_3, "dispatch", NULL, 0, event);
	zephir_check_call_status();
	RETURN_MM();

}

