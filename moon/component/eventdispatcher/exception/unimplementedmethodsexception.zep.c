
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
 * FileName: UnimplementedMethodsException.php
 * User: solely
 * DateTime: 2019/7/18 22:57
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_Exception_UnimplementedMethodsException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\EventDispatcher\\Exception, UnimplementedMethodsException, moon, component_eventdispatcher_exception_unimplementedmethodsexception, zend_exception_get_default(TSRMLS_C), NULL, 0);

	return SUCCESS;

}

