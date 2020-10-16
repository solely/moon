
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
 * FileName: RouterException.php
 * User: solely
 * DateTime: 2020/6/17 23:41
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Router_Exception_RouterException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Router\\Exception, RouterException, moon, component_router_exception_routerexception, spl_ce_RuntimeException, NULL, 0);

	return SUCCESS;

}

