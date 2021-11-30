
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: MoonContainerInterface.php
 * User: solely
 * DateTime: 2019/6/24 23:09
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_MoonContainerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\DI, MoonContainerInterface, moon, component_di_mooncontainerinterface, moon_component_di_mooncontainerinterface_method_entry);

	zend_class_implements(moon_component_di_mooncontainerinterface_ce, 1, zephir_get_internal_ce(SL("psrext\\container\\containerinterface")));
	return SUCCESS;

}

/**
 * @return bool
 */
ZEPHIR_DOC_METHOD(Moon_Component_DI_MoonContainerInterface, getDefaultIsLazy);

