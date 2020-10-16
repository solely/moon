
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: RouterInterface.php
 * User: solely
 * DateTime: 2020/6/25 23:27
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Router_RouterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\Router, RouterInterface, moon, component_router_routerinterface, moon_component_router_routerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Moon_Component_Router_RouterInterface, addRoutes);

ZEPHIR_DOC_METHOD(Moon_Component_Router_RouterInterface, dispatch);

