
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: InjectInterface.php
 * User: solely
 * DateTime: 2019/6/11 23:24
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_InjectInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\DI, InjectInterface, moon, component_di_injectinterface, moon_component_di_injectinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Moon_Component_DI_InjectInterface, factory);

