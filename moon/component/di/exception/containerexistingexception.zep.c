
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
 * FileName: ContainerExistingException.php
 * User: solely
 * DateTime: 2019/7/7 23:19
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Exception_ContainerExistingException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\DI\\Exception, ContainerExistingException, moon, component_di_exception_containerexistingexception, moon_component_di_exception_containerexception_ce, NULL, 0);

	return SUCCESS;

}

