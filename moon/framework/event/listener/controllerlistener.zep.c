
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * FileName: ControllerListener.php
 * User: solely
 * DateTime: 2020/10/1 11:31
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Event_Listener_ControllerListener) {

	ZEPHIR_REGISTER_CLASS(Moon\\Framework\\Event\\Listener, ControllerListener, moon, framework_event_listener_controllerlistener, moon_framework_event_listener_controllerlistener_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Event_Listener_ControllerListener, handle) {

	zval *event, event_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &event);




}

