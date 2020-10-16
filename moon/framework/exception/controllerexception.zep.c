
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
#include "ext/spl/spl_exceptions.h"


/**
 * FileName: ControllerException.php
 * User: solely
 * DateTime: 2020/8/23 23:58
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Exception_ControllerException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Framework\\Exception, ControllerException, moon, framework_exception_controllerexception, spl_ce_RuntimeException, NULL, 0);

	return SUCCESS;

}

