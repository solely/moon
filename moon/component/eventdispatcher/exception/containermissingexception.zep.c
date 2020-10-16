
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
#include "ext/spl/spl_exceptions.h"


/**
 * FileName: ContainerMissingException.php
 * User: solely
 * DateTime: 2019/10/5 11:11
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_Exception_ContainerMissingException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\EventDispatcher\\Exception, ContainerMissingException, moon, component_eventdispatcher_exception_containermissingexception, spl_ce_RuntimeException, NULL, 0);

	return SUCCESS;

}

