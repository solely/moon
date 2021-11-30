
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: DelegatorInterface.php
 * User: solely
 * DateTime: 2019/6/11 22:00
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_DelegatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\DI, DelegatorInterface, moon, component_di_delegatorinterface, moon_component_di_delegatorinterface_method_entry);

	zend_class_implements(moon_component_di_delegatorinterface_ce, 1, zephir_get_internal_ce(SL("psrext\\container\\containerinterface")));
	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Moon_Component_DI_DelegatorInterface, get);

ZEPHIR_DOC_METHOD(Moon_Component_DI_DelegatorInterface, has);

ZEPHIR_DOC_METHOD(Moon_Component_DI_DelegatorInterface, set);

