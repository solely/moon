
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


/**
 * FileName: ListenerProviderCallback.php
 * User: solely
 * DateTime: 2020/11/1 0:36
 * Description:
 *      
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerProviderCallback) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\EventDispatcher, ListenerProviderCallback, moon, component_eventdispatcher_listenerprovidercallback, moon_component_eventdispatcher_listenerprovidercallback_method_entry, 0);

	zend_declare_property_null(moon_component_eventdispatcher_listenerprovidercallback_ce, SL("container"), ZEND_ACC_PUBLIC);

	zend_declare_property_null(moon_component_eventdispatcher_listenerprovidercallback_ce, SL("serviceName"), ZEND_ACC_PUBLIC);

	zend_declare_property_null(moon_component_eventdispatcher_listenerprovidercallback_ce, SL("methodName"), ZEND_ACC_PUBLIC);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderCallback, __construct) {

	zval *container, container_sub, *serviceName, serviceName_sub, *methodName, methodName_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&serviceName_sub);
	ZVAL_UNDEF(&methodName_sub);

	zephir_fetch_params_without_memory_grow(3, 0, &container, &serviceName, &methodName);



	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	zephir_update_property_zval(this_ptr, ZEND_STRL("serviceName"), serviceName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("methodName"), methodName);

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerProviderCallback, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, methodName, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("methodName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&methodName, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("serviceName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_ZVAL(NULL, &_1, &methodName, NULL, 0, event);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

