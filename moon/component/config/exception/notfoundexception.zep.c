
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
 * FileName: NotFoundException.php
 * User: solely
 * DateTime: 2019/10/26 22:44
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Config_Exception_NotFoundException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Config\\Exception, NotFoundException, moon, component_config_exception_notfoundexception, spl_ce_RuntimeException, NULL, 0);

	return SUCCESS;

}

