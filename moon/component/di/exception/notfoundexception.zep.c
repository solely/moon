
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
 * FileName: NotFoundException.php
 * User: solely
 * DateTime: 2019/4/7 11:59
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Exception_NotFoundException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\DI\\Exception, NotFoundException, moon, component_di_exception_notfoundexception, moon_component_di_exception_containerexception_ce, NULL, 0);

	zend_class_implements(moon_component_di_exception_notfoundexception_ce, 1, zephir_get_internal_ce(SL("psrext\\container\\notfoundexceptioninterface")));
	return SUCCESS;

}

