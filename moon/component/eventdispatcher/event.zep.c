
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


/**
 * FileName: Event.php
 * User: solely
 * DateTime: 2019/7/11 23:22
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_Event) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\EventDispatcher, Event, moon, component_eventdispatcher_event, moon_component_eventdispatcher_event_method_entry, 0);

	zend_declare_property_bool(moon_component_eventdispatcher_event_ce, SL("stopPropagation"), 0, ZEND_ACC_PRIVATE);

	zend_class_implements(moon_component_eventdispatcher_event_ce, 1, zephir_get_internal_ce(SL("psrext\\eventdispatcher\\stoppableeventinterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_EventDispatcher_Event, isPropagationStopped) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "stopPropagation");

}

PHP_METHOD(Moon_Component_EventDispatcher_Event, stopPropagation) {

	zval __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);


	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("stopPropagation"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("stopPropagation"), &__$false);
	}

}

