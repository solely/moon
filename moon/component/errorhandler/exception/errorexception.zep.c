
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
 * FileName: ErrorException.php
 * User: solely
 * DateTime: 2019/11/3 22:47
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Exception_ErrorException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\ErrorHandler\\Exception, ErrorException, moon, component_errorhandler_exception_errorexception, zephir_get_internal_ce(SL("errorexception")), NULL, 0);

	return SUCCESS;

}

