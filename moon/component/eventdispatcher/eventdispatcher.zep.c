
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/**
 * FileName: EventDispatcher.php
 * User: solely
 * DateTime: 2019/7/11 23:14
 * Description:
 *
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_EventDispatcher) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\EventDispatcher, EventDispatcher, moon, component_eventdispatcher_eventdispatcher, moon_component_eventdispatcher_eventdispatcher_method_entry, 0);

	zend_declare_property_null(moon_component_eventdispatcher_eventdispatcher_ce, SL("provider"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_eventdispatcher_eventdispatcher_ce, SL("logger"), ZEND_ACC_PRIVATE);

	zend_class_implements(moon_component_eventdispatcher_eventdispatcher_ce, 1, zephir_get_internal_ce(SL("psrext\\eventdispatcher\\eventdispatcherinterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_EventDispatcher_EventDispatcher, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *listenerProvider, listenerProvider_sub, *logger, logger_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&listenerProvider_sub);
	ZVAL_UNDEF(&logger_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &listenerProvider, &logger);



	zephir_update_property_zval(this_ptr, ZEND_STRL("provider"), listenerProvider);
	ZEPHIR_INIT_VAR(&_0);
	if (!(ZEPHIR_IS_EMPTY(logger))) {
		ZEPHIR_CPY_WRT(&_0, logger);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		object_init_ex(&_0, zephir_get_internal_ce(SL("psr\\log\\nulllogger")));
		if (zephir_has_constructor(&_0)) {
			ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
			zephir_check_call_status();
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("logger"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param object $event
 * @return object
 * @throws Exception\EventDispatcherException
 */
PHP_METHOD(Moon_Component_EventDispatcher_EventDispatcher, dispatch) {

	zval _12$$9;
	zend_bool _0, _6$$5, _8$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, _1, exception, _10, listener$$4, _2$$4, _3$$4, *_4$$4, _5$$4, _7$$5, _9$$7, _11$$9, _13$$9, _14$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&listener$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_12$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	_0 = zephir_is_instance_of(event, SL("Psr\\EventDispatcher\\StoppableEventInterface"));
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1, event, "ispropagationstopped", NULL, 0);
		zephir_check_call_status();
		_0 = zephir_is_true(&_1);
	}
	if (_0) {
		RETVAL_ZVAL(event, 1, 0);
		RETURN_MM();
	}

	/* try_start_1: */

		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("provider"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3$$4, &_2$$4, "getlistenersforevent", NULL, 0, event);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(&_3$$4, 0, "moon/Component/EventDispatcher/EventDispatcher.zep", 45);
		if (Z_TYPE_P(&_3$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3$$4), _4$$4)
			{
				ZEPHIR_INIT_NVAR(&listener$$4);
				ZVAL_COPY(&listener$$4, _4$$4);
				ZEPHIR_CALL_ZVAL_FUNCTION(NULL, &listener$$4, NULL, 0, event);
				zephir_check_call_status_or_jump(try_end_1);
				_6$$5 = zephir_is_instance_of(event, SL("Psr\\EventDispatcher\\StoppableEventInterface"));
				if (_6$$5) {
					ZEPHIR_CALL_METHOD(&_7$$5, event, "ispropagationstopped", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
					_6$$5 = zephir_is_true(&_7$$5);
				}
				if (_6$$5) {
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$4, &_3$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&listener$$4, &_3$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_ZVAL_FUNCTION(NULL, &listener$$4, NULL, 0, event);
					zephir_check_call_status_or_jump(try_end_1);
					_8$$7 = zephir_is_instance_of(event, SL("Psr\\EventDispatcher\\StoppableEventInterface"));
					if (_8$$7) {
						ZEPHIR_CALL_METHOD(&_9$$7, event, "ispropagationstopped", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						_8$$7 = zephir_is_true(&_9$$7);
					}
					if (_8$$7) {
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, &_3$$4, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&listener$$4);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_10);
		ZVAL_OBJ(&_10, EG(exception));
		Z_ADDREF_P(&_10);
		if (zephir_instance_of_ev(&_10, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&exception, &_10);
			zephir_read_property(&_11$$9, this_ptr, ZEND_STRL("logger"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_12$$9);
			zephir_create_array(&_12$$9, 2, 0);
			zephir_array_update_string(&_12$$9, SL("event"), event, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_12$$9, SL("exception"), &exception, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_13$$9);
			ZVAL_STRING(&_13$$9, "There is an event exception unhandled.");
			ZEPHIR_CALL_METHOD(NULL, &_11$$9, "warning", NULL, 0, &_13$$9, &_12$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_CE_STATIC(&_14$$9, moon_component_eventdispatcher_exception_ce, "eventdispatcherexception", &_15, 0, event, &exception);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_14$$9, "moon/Component/EventDispatcher/EventDispatcher.zep", 47);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETVAL_ZVAL(event, 1, 0);
	RETURN_MM();

}

/**
 * @param ListenerProviderInterface $provider
 */
PHP_METHOD(Moon_Component_EventDispatcher_EventDispatcher, setProvider) {

	zval *provider, provider_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &provider);



	zephir_update_property_zval(this_ptr, ZEND_STRL("provider"), provider);

}

/**
 * @return ListenerProviderInterface
 */
PHP_METHOD(Moon_Component_EventDispatcher_EventDispatcher, getProvider) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "provider");

}

