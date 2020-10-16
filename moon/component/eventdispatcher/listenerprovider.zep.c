
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 * FileName: ListenerProvider.php
 * User: solely
 * DateTime: 2019/7/11 23:21
 * Description:
 *
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerProvider) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\EventDispatcher, ListenerProvider, moon, component_eventdispatcher_listenerprovider, moon_component_eventdispatcher_listenerproviderutiltrait_ce, moon_component_eventdispatcher_listenerprovider_method_entry, 0);

	zend_declare_property_null(moon_component_eventdispatcher_listenerprovider_ce, SL("listeners"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_eventdispatcher_listenerprovider_ce, SL("container"), ZEND_ACC_PRIVATE);

	zend_class_implements(moon_component_eventdispatcher_listenerprovider_ce, 1, moon_component_eventdispatcher_listenerproviderinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_eventdispatcher_listenercollection_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("listeners"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, getListenersForEvent) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, iter, listener, _0, *_1, _2, _3$$3, _4$$4, _5$$5, _6$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&iter);
	ZVAL_UNDEF(&listener);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	ZEPHIR_INIT_VAR(&iter);
	array_init(&iter);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("listeners"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "moon/Component/EventDispatcher/ListenerProvider.zep", 33);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&listener);
			ZVAL_COPY(&listener, _1);
			ZEPHIR_OBS_NVAR(&_3$$3);
			zephir_read_property(&_3$$3, &listener, ZEND_STRL("type"), PH_NOISY_CC);
			if (zephir_is_instance_of(event, Z_STRVAL_P(&_3$$3), Z_STRLEN_P(&_3$$3))) {
				zephir_read_property(&_4$$4, &listener, ZEND_STRL("listener"), PH_NOISY_CC | PH_READONLY);
				zephir_array_append(&iter, &_4$$4, PH_SEPARATE, "moon/Component/EventDispatcher/ListenerProvider.zep", 30);
			}
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
			ZEPHIR_CALL_METHOD(&listener, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_5$$5);
				zephir_read_property(&_5$$5, &listener, ZEND_STRL("type"), PH_NOISY_CC);
				if (zephir_is_instance_of(event, Z_STRVAL_P(&_5$$5), Z_STRLEN_P(&_5$$5))) {
					zephir_read_property(&_6$$6, &listener, ZEND_STRL("listener"), PH_NOISY_CC | PH_READONLY);
					zephir_array_append(&iter, &_6$$6, PH_SEPARATE, "moon/Component/EventDispatcher/ListenerProvider.zep", 30);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&listener);
	object_init_ex(return_value, zephir_get_internal_ce(SL("arrayiterator")));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 37, &iter);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param callable $listener
 * @param int $priority
 * @param string|null $id
 * @param string|null $type
 * @return string
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListener) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval id, type;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *listener, listener_sub, *priority_param = NULL, *id_param = NULL, *type_param = NULL, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&listener_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &listener, &priority_param, &id_param, &type_param);

	if (!priority_param) {
		priority = 0;
	} else {
		priority = zephir_get_intval(priority_param);
	}
	if (!id_param) {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_STRING(&id, "");
	} else {
		zephir_get_strval(&id, id_param);
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "");
	} else {
		zephir_get_strval(&type, type_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(ZEPHIR_IS_EMPTY(&type))) {
		ZEPHIR_CPY_WRT(&_0, &type);
	} else {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparametertype", NULL, 0, listener);
		zephir_check_call_status();
	}
	zephir_get_strval(&type, &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (!(ZEPHIR_IS_EMPTY(&id))) {
		ZEPHIR_CPY_WRT(&_1, &id);
	} else {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getlistenerid", NULL, 0, listener);
		zephir_check_call_status();
	}
	zephir_get_strval(&id, &_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("listeners"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, moon_component_eventdispatcher_listenerevententry_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 171, listener, &type);
	zephir_check_call_status();
	ZVAL_LONG(&_4, priority);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "additem", NULL, 0, &_3, &_4, &id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $pivotId
 * @param callable $listener
 * @param string|null $id
 * @param string|null $type
 * @return string
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListenerBefore) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pivotId_param = NULL, *listener, listener_sub, *id_param = NULL, *type_param = NULL, _0, _1, _2, _3;
	zval pivotId, id, type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pivotId);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&listener_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &pivotId_param, &listener, &id_param, &type_param);

	zephir_get_strval(&pivotId, pivotId_param);
	if (!id_param) {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_STRING(&id, "");
	} else {
		zephir_get_strval(&id, id_param);
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "");
	} else {
		zephir_get_strval(&type, type_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(ZEPHIR_IS_EMPTY(&type))) {
		ZEPHIR_CPY_WRT(&_0, &type);
	} else {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparametertype", NULL, 0, listener);
		zephir_check_call_status();
	}
	zephir_get_strval(&type, &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (!(ZEPHIR_IS_EMPTY(&id))) {
		ZEPHIR_CPY_WRT(&_1, &id);
	} else {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getlistenerid", NULL, 0, listener);
		zephir_check_call_status();
	}
	zephir_get_strval(&id, &_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("listeners"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, moon_component_eventdispatcher_listenerevententry_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 171, listener, &type);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_2, "additembefore", NULL, 0, &pivotId, &_3, &id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $pivotId
 * @param callable $listener
 * @param string|null $id
 * @param string|null $type
 * @return string
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListenerAfter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pivotId_param = NULL, *listener, listener_sub, *id_param = NULL, *type_param = NULL, _0, _1, _2, _3;
	zval pivotId, id, type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pivotId);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&listener_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &pivotId_param, &listener, &id_param, &type_param);

	zephir_get_strval(&pivotId, pivotId_param);
	if (!id_param) {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_STRING(&id, "");
	} else {
		zephir_get_strval(&id, id_param);
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "");
	} else {
		zephir_get_strval(&type, type_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(ZEPHIR_IS_EMPTY(&type))) {
		ZEPHIR_CPY_WRT(&_0, &type);
	} else {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparametertype", NULL, 0, listener);
		zephir_check_call_status();
	}
	zephir_get_strval(&type, &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (!(ZEPHIR_IS_EMPTY(&id))) {
		ZEPHIR_CPY_WRT(&_1, &id);
	} else {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getlistenerid", NULL, 0, listener);
		zephir_check_call_status();
	}
	zephir_get_strval(&id, &_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("listeners"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, moon_component_eventdispatcher_listenerevententry_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 171, listener, &type);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_2, "additemafter", NULL, 0, &pivotId, &_3, &id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $serviceName
 * @param string $methodName
 * @param string|null $type
 * @param int $priority
 * @param string|null $id
 * @return string
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListenerService) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *serviceName_param = NULL, *methodName_param = NULL, *type_param = NULL, *priority = NULL, priority_sub, *id_param = NULL, _0, _2;
	zval serviceName, methodName, type, id, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&priority_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &serviceName_param, &methodName_param, &type_param, &priority, &id_param);

	zephir_get_strval(&serviceName, serviceName_param);
	zephir_get_strval(&methodName, methodName_param);
	zephir_get_strval(&type, type_param);
	if (!priority) {
		priority = &priority_sub;
		ZEPHIR_INIT_VAR(priority);
		ZVAL_LONG(priority, 0);
	}
	if (!id_param) {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_STRING(&id, "");
	} else {
		zephir_get_strval(&id, id_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(ZEPHIR_IS_EMPTY(&id))) {
		ZEPHIR_CPY_WRT(&_0, &id);
	} else {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_CONCAT_VSV(&_1, &serviceName, "-", &methodName);
		ZEPHIR_CPY_WRT(&_0, &_1);
	}
	zephir_get_strval(&id, &_0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "makelistenerforservice", NULL, 172, &serviceName, &methodName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addlistener", NULL, 0, &_2, priority, &id, &type);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $pivotId
 * @param string $serviceName
 * @param string $methodName
 * @param string $type
 * @param string|null $id
 * @return string
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListenerServiceBefore) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pivotId_param = NULL, *serviceName_param = NULL, *methodName_param = NULL, *type_param = NULL, *id_param = NULL, _0, _2;
	zval pivotId, serviceName, methodName, type, id, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pivotId);
	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &pivotId_param, &serviceName_param, &methodName_param, &type_param, &id_param);

	zephir_get_strval(&pivotId, pivotId_param);
	zephir_get_strval(&serviceName, serviceName_param);
	zephir_get_strval(&methodName, methodName_param);
	zephir_get_strval(&type, type_param);
	if (!id_param) {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_STRING(&id, "");
	} else {
		zephir_get_strval(&id, id_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(ZEPHIR_IS_EMPTY(&id))) {
		ZEPHIR_CPY_WRT(&_0, &id);
	} else {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_CONCAT_VSV(&_1, &serviceName, "-", &methodName);
		ZEPHIR_CPY_WRT(&_0, &_1);
	}
	zephir_get_strval(&id, &_0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "makelistenerforservice", NULL, 172, &serviceName, &methodName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addlistenerbefore", NULL, 0, &pivotId, &_2, &id, &type);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $pivotId
 * @param string $serviceName
 * @param string $methodName
 * @param string $type
 * @param string|null $id
 * @return string
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addListenerServiceAfter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pivotId_param = NULL, *serviceName_param = NULL, *methodName_param = NULL, *type_param = NULL, *id_param = NULL, _0, _2;
	zval pivotId, serviceName, methodName, type, id, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pivotId);
	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &pivotId_param, &serviceName_param, &methodName_param, &type_param, &id_param);

	zephir_get_strval(&pivotId, pivotId_param);
	zephir_get_strval(&serviceName, serviceName_param);
	zephir_get_strval(&methodName, methodName_param);
	zephir_get_strval(&type, type_param);
	if (!id_param) {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_STRING(&id, "");
	} else {
		zephir_get_strval(&id, id_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(ZEPHIR_IS_EMPTY(&id))) {
		ZEPHIR_CPY_WRT(&_0, &id);
	} else {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_CONCAT_VSV(&_1, &serviceName, "-", &methodName);
		ZEPHIR_CPY_WRT(&_0, &_1);
	}
	zephir_get_strval(&id, &_0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "makelistenerforservice", NULL, 172, &serviceName, &methodName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addlistenerafter", NULL, 0, &pivotId, &_2, &id, &type);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $class
 * @param string $serviceName
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, addSubscriber) {

	zend_bool _9$$5, _22$$8;
	zend_class_entry *_2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_14 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_27 = NULL, *_31 = NULL, *_34 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_class_param = NULL, *serviceName_param = NULL, type, params, methodName, methods, rClass, proxy, _0, _1, e, _32, _3$$4, rMethod$$4, *_4$$4, _5$$4, _7$$5, _10$$5, _11$$5, _12$$5, _13$$5, _15$$7, _16$$7, _17$$7, _21$$8, _23$$8, _24$$8, _25$$8, _26$$8, _28$$10, _29$$10, _30$$10, _33$$11, _35$$11, _36$$11;
	zval _class, serviceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_class);
	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&rClass);
	ZVAL_UNDEF(&proxy);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&rMethod$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_35$$11);
	ZVAL_UNDEF(&_36$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &_class_param, &serviceName_param);

	zephir_get_strval(&_class, _class_param);
	zephir_get_strval(&serviceName, serviceName_param);


	ZEPHIR_INIT_VAR(&proxy);
	object_init_ex(&proxy, moon_component_eventdispatcher_listenerproviderproxy_ce);
	ZEPHIR_CALL_METHOD(NULL, &proxy, "__construct", NULL, 173, this_ptr, &serviceName, &_class);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "class_implements", NULL, 97, &_class);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "SubscriberInterface");
	if (zephir_fast_in_array(&_1, &_0)) {
		_2$$3 = zephir_fetch_class(&_class);
		ZEPHIR_CALL_CE_STATIC(NULL, _2$$3, "registerlisteners", NULL, 0, &proxy);
		zephir_check_call_status();
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&rClass);
		object_init_ex(&rClass, zephir_get_internal_ce(SL("reflectionclass")));
		ZEPHIR_CALL_METHOD(NULL, &rClass, "__construct", NULL, 24, &_class);
		zephir_check_call_status_or_jump(try_end_1);
		ZVAL_LONG(&_3$$4, 256);
		ZEPHIR_CALL_METHOD(&methods, &rClass, "getmethods", NULL, 174, &_3$$4);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(&methods, 0, "moon/Component/EventDispatcher/ListenerProvider.zep", 154);
		if (Z_TYPE_P(&methods) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&methods), _4$$4)
			{
				ZEPHIR_INIT_NVAR(&rMethod$$4);
				ZVAL_COPY(&rMethod$$4, _4$$4);
				ZEPHIR_CALL_METHOD(&methodName, &rMethod$$4, "getname", &_6, 0);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CALL_METHOD(&_7$$5, &proxy, "getregisteredmethods", &_8, 175);
				zephir_check_call_status_or_jump(try_end_1);
				_9$$5 = !(zephir_fast_in_array(&methodName, &_7$$5));
				if (_9$$5) {
					ZEPHIR_INIT_NVAR(&_10$$5);
					ZVAL_LONG(&_11$$5, 0);
					ZVAL_LONG(&_12$$5, 2);
					ZEPHIR_INIT_NVAR(&_13$$5);
					zephir_substr(&_13$$5, &methodName, 0 , 2 , 0);
					zephir_fast_strtolower(&_10$$5, &_13$$5);
					_9$$5 = ZEPHIR_IS_STRING(&_10$$5, "on");
				}
				if (_9$$5) {
					ZEPHIR_CALL_METHOD(&params, &rMethod$$4, "getparameters", &_14, 0);
					zephir_check_call_status_or_jump(try_end_1);
					if (!(ZEPHIR_IS_EMPTY(&params))) {
						zephir_array_fetch_long(&_15$$7, &params, 0, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerProvider.zep", 149);
						ZEPHIR_CALL_METHOD(&_16$$7, &_15$$7, "gettype", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_CALL_METHOD(&type, &_16$$7, "getname", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_CALL_METHOD(&_17$$7, &rMethod$$4, "getname", &_18, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "addlistenerservice", &_19, 0, &serviceName, &_17$$7, &type);
						zephir_check_call_status_or_jump(try_end_1);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &methods, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$4, &methods, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&rMethod$$4, &methods, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&methodName, &rMethod$$4, "getname", &_20, 0);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CALL_METHOD(&_21$$8, &proxy, "getregisteredmethods", &_8, 175);
					zephir_check_call_status_or_jump(try_end_1);
					_22$$8 = !(zephir_fast_in_array(&methodName, &_21$$8));
					if (_22$$8) {
						ZEPHIR_INIT_NVAR(&_23$$8);
						ZVAL_LONG(&_24$$8, 0);
						ZVAL_LONG(&_25$$8, 2);
						ZEPHIR_INIT_NVAR(&_26$$8);
						zephir_substr(&_26$$8, &methodName, 0 , 2 , 0);
						zephir_fast_strtolower(&_23$$8, &_26$$8);
						_22$$8 = ZEPHIR_IS_STRING(&_23$$8, "on");
					}
					if (_22$$8) {
						ZEPHIR_CALL_METHOD(&params, &rMethod$$4, "getparameters", &_27, 0);
						zephir_check_call_status_or_jump(try_end_1);
						if (!(ZEPHIR_IS_EMPTY(&params))) {
							zephir_array_fetch_long(&_28$$10, &params, 0, PH_NOISY | PH_READONLY, "moon/Component/EventDispatcher/ListenerProvider.zep", 149);
							ZEPHIR_CALL_METHOD(&_29$$10, &_28$$10, "gettype", NULL, 0);
							zephir_check_call_status_or_jump(try_end_1);
							ZEPHIR_CALL_METHOD(&type, &_29$$10, "getname", NULL, 0);
							zephir_check_call_status_or_jump(try_end_1);
							ZEPHIR_CALL_METHOD(&_30$$10, &rMethod$$4, "getname", &_31, 0);
							zephir_check_call_status_or_jump(try_end_1);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "addlistenerservice", &_19, 0, &serviceName, &_30$$10, &type);
							zephir_check_call_status_or_jump(try_end_1);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &methods, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&rMethod$$4);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_32);
		ZVAL_OBJ(&_32, EG(exception));
		Z_ADDREF_P(&_32);
		if (zephir_instance_of_ev(&_32, zephir_get_internal_ce(SL("reflectionexception")))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_32);
			ZEPHIR_INIT_VAR(&_35$$11);
			ZVAL_STRING(&_35$$11, "Type error registering subscriber.");
			ZVAL_LONG(&_36$$11, 0);
			ZEPHIR_CALL_CE_STATIC(&_33$$11, moon_component_eventdispatcher_exception_ce, "runtimeexception", &_34, 0, &_35$$11, &_36$$11, &e);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_33$$11, "moon/Component/EventDispatcher/ListenerProvider.zep", 155);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Creates a callable that will proxy to the provided service and method.
 *
 * @param string $serviceName
 *       The name of a service.
 * @param string $methodName
 *      A method on the service.
 * @return callable
 *      A callable that proxies to the the provided method and service.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProvider, makeListenerForService) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *serviceName, serviceName_sub, *methodName, methodName_sub, listener, container, _0, _3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_sub);
	ZVAL_UNDEF(&methodName_sub);
	ZVAL_UNDEF(&listener);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &serviceName, &methodName);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_CALL_CE_STATIC(&_1$$3, moon_component_eventdispatcher_exception_ce, "containermissingexception", &_2, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "moon/Component/EventDispatcher/ListenerProvider.zep", 174);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_3);
	ZEPHIR_INIT_VAR(&listener);
	zephir_create_closure_ex(&listener, NULL, moon_6__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(moon_6__closure_ce, ZEND_STRL("serviceName"), serviceName);
	zephir_update_static_property_ce(moon_6__closure_ce, ZEND_STRL("methodName"), methodName);
	zephir_update_static_property_ce(moon_6__closure_ce, ZEND_STRL("container"), &container);
	RETURN_CCTOR(&listener);

}

