
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
 * FileName: AutoResolver.php
 * User: solely
 * DateTime: 2019/6/23 16:52
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_AutoResolver) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI\\Resolver, AutoResolver, moon, component_di_resolver_autoresolver, NULL, 0);

	return SUCCESS;

}

