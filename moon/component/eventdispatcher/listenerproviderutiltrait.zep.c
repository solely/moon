
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * FileName: ListenerProviderUtilTrait.php
 * User: solely
 * DateTime: 2019/7/15 23:53
 * Description:
 *
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerProviderUtilTrait) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\EventDispatcher, ListenerProviderUtilTrait, moon, component_eventdispatcher_listenerproviderutiltrait, moon_component_eventdispatcher_parameterderivertrait_ce, moon_component_eventdispatcher_listenerproviderutiltrait_method_entry, 0);

	return SUCCESS;

}

/**
 * @param callable $listener
 * @return string|null
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderUtilTrait, getListenerId) {

	zval _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *listener, listener_sub, _0, _2, _5, _3$$4, _4$$4, _6$$5, _7$$5, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&listener_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &listener);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isfunctioncallable", NULL, 0, listener);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_get_strval(&_1$$3, listener);
		RETURN_CTOR(&_1$$3);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "isclasscallable", NULL, 0, listener);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		zephir_array_fetch_long(&_3$$4, listener, 0, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerProviderUtilTrait.zep", 26);
		zephir_array_fetch_long(&_4$$4, listener, 1, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerProviderUtilTrait.zep", 26);
		ZEPHIR_CONCAT_VSV(return_value, &_3$$4, "::", &_4$$4);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "isobjectcallable", NULL, 0, listener);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_array_fetch_long(&_7$$5, listener, 0, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerProviderUtilTrait.zep", 29);
		zephir_get_class(&_6$$5, &_7$$5, 0);
		zephir_array_fetch_long(&_8$$5, listener, 1, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerProviderUtilTrait.zep", 29);
		ZEPHIR_CONCAT_VSV(return_value, &_6$$5, "::", &_8$$5);
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

