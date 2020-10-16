
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: SubscriberInterface.php
 * User: solely
 * DateTime: 2019/10/4 18:29
 * Description:
 *
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_SubscriberInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\EventDispatcher, SubscriberInterface, moon, component_eventdispatcher_subscriberinterface, moon_component_eventdispatcher_subscriberinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Moon_Component_EventDispatcher_SubscriberInterface, registerListeners);

