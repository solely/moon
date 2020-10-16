
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * FileName: Event.php
 * User: solely
 * DateTime: 2020/7/20 23:57
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event) {

	ZEPHIR_REGISTER_CLASS(Moon\\Framework\\Event, Event, moon, framework_event_event, moon_framework_event_event_method_entry, 0);

	zephir_declare_class_constant_long(moon_framework_event_event_ce, SL("EVENT_TYPE_LISTENER"), 0);

	zephir_declare_class_constant_long(moon_framework_event_event_ce, SL("EVENT_TYPE_SUBSCRIBER"), 1);

	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Event_Event, registerEvent) {

	zend_class_entry *_9$$5, *_19$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_12 = NULL, *_22 = NULL;
	zval *container, container_sub, provider, item, eventList, itemClass, *_1, _2, _3$$3, _4$$4, _5$$4, _10$$4, _11$$4, _6$$5, _7$$5, _8$$5, _13$$7, _14$$8, _15$$8, _20$$8, _21$$8, _16$$9, _17$$9, _18$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&eventList);
	ZVAL_UNDEF(&itemClass);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_CALL_SELF(&provider, "registersubscriber", &_0, 288, container);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&eventList, "geteventlist", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&eventList, 0, "moon/Framework/Event/Event.zep", 42);
	if (Z_TYPE_P(&eventList) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&eventList), _1)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1);
			ZEPHIR_OBS_NVAR(&_3$$3);
			zephir_array_fetch_string(&_3$$3, &item, SL("type"), PH_NOISY, "moon/Framework/Event/Event.zep", 30);
			do {
				if (ZEPHIR_IS_LONG(&_3$$3, 0)) {
					zephir_array_fetch_string(&_4$$4, &item, SL("listener"), PH_NOISY | PH_READONLY, "moon/Framework/Event/Event.zep", 32);
					zephir_array_fetch_long(&_5$$4, &_4$$4, 0, PH_NOISY | PH_READONLY, "moon/Framework/Event/Event.zep", 32);
					if (!(Z_TYPE_P(&_5$$4) == IS_OBJECT)) {
						zephir_array_fetch_string(&_6$$5, &item, SL("listener"), PH_NOISY | PH_READONLY, "moon/Framework/Event/Event.zep", 33);
						ZEPHIR_OBS_NVAR(&itemClass);
						zephir_array_fetch_long(&itemClass, &_6$$5, 0, PH_NOISY, "moon/Framework/Event/Event.zep", 33);
						ZEPHIR_INIT_NVAR(&_7$$5);
						zephir_fetch_safe_class(&_8$$5, &itemClass);
						_9$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_8$$5), Z_STRLEN_P(&_8$$5), ZEND_FETCH_CLASS_AUTO);
						if(!_9$$5) {
							RETURN_MM_NULL();
						}
						object_init_ex(&_7$$5, _9$$5);
						if (zephir_has_constructor(&_7$$5)) {
							ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", NULL, 0);
							zephir_check_call_status();
						}
						zephir_array_update_multi(&item, &_7$$5, SL("sl"), 3, SL("listener"), 0);
					}
					zephir_array_fetch_string(&_10$$4, &item, SL("listener"), PH_NOISY | PH_READONLY, "moon/Framework/Event/Event.zep", 36);
					zephir_array_fetch_string(&_11$$4, &item, SL("priority"), PH_NOISY | PH_READONLY, "moon/Framework/Event/Event.zep", 36);
					ZEPHIR_CALL_METHOD(NULL, &provider, "addlistener", &_12, 0, &_10$$4, &_11$$4);
					zephir_check_call_status();
					break;
				}
				break;
			} while(0);

		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &eventList, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &eventList, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &eventList, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_13$$7);
				zephir_array_fetch_string(&_13$$7, &item, SL("type"), PH_NOISY, "moon/Framework/Event/Event.zep", 30);
				do {
					if (ZEPHIR_IS_LONG(&_13$$7, 0)) {
						zephir_array_fetch_string(&_14$$8, &item, SL("listener"), PH_NOISY | PH_READONLY, "moon/Framework/Event/Event.zep", 32);
						zephir_array_fetch_long(&_15$$8, &_14$$8, 0, PH_NOISY | PH_READONLY, "moon/Framework/Event/Event.zep", 32);
						if (!(Z_TYPE_P(&_15$$8) == IS_OBJECT)) {
							zephir_array_fetch_string(&_16$$9, &item, SL("listener"), PH_NOISY | PH_READONLY, "moon/Framework/Event/Event.zep", 33);
							ZEPHIR_OBS_NVAR(&itemClass);
							zephir_array_fetch_long(&itemClass, &_16$$9, 0, PH_NOISY, "moon/Framework/Event/Event.zep", 33);
							ZEPHIR_INIT_NVAR(&_17$$9);
							zephir_fetch_safe_class(&_18$$9, &itemClass);
							_19$$9 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_18$$9), Z_STRLEN_P(&_18$$9), ZEND_FETCH_CLASS_AUTO);
							if(!_19$$9) {
								RETURN_MM_NULL();
							}
							object_init_ex(&_17$$9, _19$$9);
							if (zephir_has_constructor(&_17$$9)) {
								ZEPHIR_CALL_METHOD(NULL, &_17$$9, "__construct", NULL, 0);
								zephir_check_call_status();
							}
							zephir_array_update_multi(&item, &_17$$9, SL("sl"), 3, SL("listener"), 0);
						}
						zephir_array_fetch_string(&_20$$8, &item, SL("listener"), PH_NOISY | PH_READONLY, "moon/Framework/Event/Event.zep", 36);
						zephir_array_fetch_string(&_21$$8, &item, SL("priority"), PH_NOISY | PH_READONLY, "moon/Framework/Event/Event.zep", 36);
						ZEPHIR_CALL_METHOD(NULL, &provider, "addlistener", &_22, 0, &_20$$8, &_21$$8);
						zephir_check_call_status();
						break;
					}
					break;
				} while(0);

			ZEPHIR_CALL_METHOD(NULL, &eventList, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&provider);

}

PHP_METHOD(Moon_Framework_Event_Event, registerSubscriber) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, provider, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_framework_event_listener_routersubscriber_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "router_subscriber");
	ZEPHIR_CALL_METHOD(NULL, container, "set", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&provider);
	object_init_ex(&provider, moon_component_eventdispatcher_listenerprovider_ce);
	ZEPHIR_CALL_METHOD(NULL, &provider, "__construct", NULL, 289, container);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\\Moon\\Framework\\Event\\Listener\\RouterSubscriber");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "router_subscriber");
	ZEPHIR_CALL_METHOD(NULL, &provider, "addsubscriber", NULL, 290, &_1, &_2);
	zephir_check_call_status();
	RETURN_CCTOR(&provider);

}

PHP_METHOD(Moon_Framework_Event_Event, getEventList) {

	zval _2;
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 1, 0);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\Moon\\Framework\\Event\\Listener\\RequestListener");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "handle");
	zephir_array_fast_append(&_1, &_2);
	zephir_array_update_string(&_0, SL("listener"), &_1, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_0, SL("type"), 0);
	add_assoc_long_ex(&_0, SL("priority"), 0);
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

