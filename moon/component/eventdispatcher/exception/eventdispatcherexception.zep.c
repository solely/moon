
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


/**
 * FileName: EventDispatcherException.php
 * User: solely
 * DateTime: 2019/7/14 23:25
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_Exception_EventDispatcherException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\EventDispatcher\\Exception, EventDispatcherException, moon, component_eventdispatcher_exception_eventdispatcherexception, zend_exception_get_default(TSRMLS_C), NULL, 0);

	return SUCCESS;

}

