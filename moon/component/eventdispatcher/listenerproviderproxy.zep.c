
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * FileName: ListenerProviderProxy.php
 * User: solely
 * DateTime: 2019/7/16 22:53
 * Description:
 *   此代理类是用于其它组件的 service 监听,可以保留支持 service 。 2019年7月18日22:52:02
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerProviderProxy) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\EventDispatcher, ListenerProviderProxy, moon, component_eventdispatcher_listenerproviderproxy, moon_component_eventdispatcher_parameterderivertrait_ce, moon_component_eventdispatcher_listenerproviderproxy_method_entry, 0);

	/**
	 * @var ListenerProviderInterface
	 */
	zend_declare_property_null(moon_component_eventdispatcher_listenerproviderproxy_ce, SL("listenerProvider"), ZEND_ACC_PRIVATE);

	/**
	 * @var string
	 */
	zend_declare_property_null(moon_component_eventdispatcher_listenerproviderproxy_ce, SL("serviceName"), ZEND_ACC_PRIVATE);

	/**
	 * @var string
	 */
	zend_declare_property_null(moon_component_eventdispatcher_listenerproviderproxy_ce, SL("serviceClass"), ZEND_ACC_PRIVATE);

	/**
	 * @var array 
	 */
	zend_declare_property_null(moon_component_eventdispatcher_listenerproviderproxy_ce, SL("registeredMethods"), ZEND_ACC_PRIVATE);

	moon_component_eventdispatcher_listenerproviderproxy_ce->create_object = zephir_init_properties_Moon_Component_EventDispatcher_ListenerProviderProxy;
	return SUCCESS;

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderProxy, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval serviceName, serviceClass;
	zval *listenerProvider, listenerProvider_sub, *serviceName_param = NULL, *serviceClass_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&listenerProvider_sub);
	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&serviceClass);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &listenerProvider, &serviceName_param, &serviceClass_param);

	zephir_get_strval(&serviceName, serviceName_param);
	zephir_get_strval(&serviceClass, serviceClass_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("listenerProvider"), listenerProvider);
	zephir_update_property_zval(this_ptr, ZEND_STRL("serviceName"), &serviceName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("serviceClass"), &serviceClass);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a method on a service as a listener.
 *
 * @param string $methodName
 *   The method name of the service that is the listener being registered.
 * @param int $priority
 *   The numeric priority of the listener. Higher numbers will trigger before lower numbers.
 * @param string|null $id
 *   The ID of this listener, so it can be referenced by other listeners.
 * @param string|null $type
 *   The class or interface type of events for which this listener will be registered.
 * @return string
 *   The opaque ID of the listener.  This can be used for future reference.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderProxy, addListener) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *methodName_param = NULL, *priority_param = NULL, *id_param = NULL, type, *type_param = NULL, _0, _2, _3, _4, _5;
	zval methodName, id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &methodName_param, &priority_param, &id_param, &type_param);

	zephir_get_strval(&methodName, methodName_param);
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
		ZEPHIR_INIT_VAR(&_1);
		zephir_create_array(&_1, 2, 0);
		ZEPHIR_OBS_VAR(&_2);
		zephir_read_property(&_2, this_ptr, ZEND_STRL("serviceClass"), PH_NOISY_CC);
		zephir_array_fast_append(&_1, &_2);
		zephir_array_fast_append(&_1, &methodName);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparametertype", NULL, 0, &_1);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(&type, &_0);
	zephir_update_property_array_append(this_ptr, SL("registeredMethods"), &methodName);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("listenerProvider"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, priority);
	ZEPHIR_RETURN_CALL_METHOD(&_3, "addlistenerservice", NULL, 0, &_4, &methodName, &type, &_5, &id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a service listener to trigger before another existing listener.
 *
 * Note: The new listener is only guaranteed to come before the specified existing listener. No guarantee is made
 * regarding when it comes relative to any other listener.
 *
 * @param string $pivotId
 *   The ID of an existing listener.
 * @param string $methodName
 *   The method name of the service that is the listener being registered.
 * @param string|null $id
 *   The ID of this listener, so it can be referenced by other listeners.
 * @param string $type
 *   The class or interface type of events for which this listener will be registered.
 * @return string
 *   The opaque ID of the listener.  This can be used for future reference.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderProxy, addListenerBefore) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pivotId_param = NULL, *methodName_param = NULL, *id_param = NULL, type, *type_param = NULL, _0, _2, _3, _4;
	zval pivotId, methodName, id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pivotId);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &pivotId_param, &methodName_param, &id_param, &type_param);

	zephir_get_strval(&pivotId, pivotId_param);
	zephir_get_strval(&methodName, methodName_param);
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
		ZEPHIR_INIT_VAR(&_1);
		zephir_create_array(&_1, 2, 0);
		ZEPHIR_OBS_VAR(&_2);
		zephir_read_property(&_2, this_ptr, ZEND_STRL("serviceClass"), PH_NOISY_CC);
		zephir_array_fast_append(&_1, &_2);
		zephir_array_fast_append(&_1, &methodName);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparametertype", NULL, 0, &_1);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(&type, &_0);
	zephir_update_property_array_append(this_ptr, SL("registeredMethods"), &methodName);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("listenerProvider"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_3, "addlistenerservicebefore", NULL, 0, &pivotId, &_4, &methodName, &type, &id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a service listener to trigger before another existing listener.
 *
 * Note: The new listener is only guaranteed to come before the specified existing listener. No guarantee is made
 * regarding when it comes relative to any other listener.
 *
 * @param string $pivotId
 *   The ID of an existing listener.
 * @param string $methodName
 *   The method name of the service that is the listener being registered.
 * @param string|null $id
 *   The ID of this listener, so it can be referenced by other listeners.
 * @param string $type
 *   The class or interface type of events for which this listener will be registered.
 * @return string
 *   The opaque ID of the listener.  This can be used for future reference.
 */
PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderProxy, addListenerAfter) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pivotId_param = NULL, *methodName_param = NULL, *id_param = NULL, type, *type_param = NULL, _0, _2, _3, _4;
	zval pivotId, methodName, id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pivotId);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &pivotId_param, &methodName_param, &id_param, &type_param);

	zephir_get_strval(&pivotId, pivotId_param);
	zephir_get_strval(&methodName, methodName_param);
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
		ZEPHIR_INIT_VAR(&_1);
		zephir_create_array(&_1, 2, 0);
		ZEPHIR_OBS_VAR(&_2);
		zephir_read_property(&_2, this_ptr, ZEND_STRL("serviceClass"), PH_NOISY_CC);
		zephir_array_fast_append(&_1, &_2);
		zephir_array_fast_append(&_1, &methodName);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getparametertype", NULL, 0, &_1);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(&type, &_0);
	zephir_update_property_array_append(this_ptr, SL("registeredMethods"), &methodName);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("listenerProvider"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_3, "addlistenerserviceafter", NULL, 0, &pivotId, &_4, &methodName, &type, &id);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderProxy, getRegisteredMethods) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "registeredMethods");

}

zend_object *zephir_init_properties_Moon_Component_EventDispatcher_ListenerProviderProxy(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("registeredMethods"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("registeredMethods"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

