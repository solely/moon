
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: ControllerArgumentsResolverInterface.php
 * User: solely
 * DateTime: 2020/8/23 23:19
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Controller_ControllerArgumentsResolverInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Framework\\Controller, ControllerArgumentsResolverInterface, moon, framework_controller_controllerargumentsresolverinterface, moon_framework_controller_controllerargumentsresolverinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Moon_Framework_Controller_ControllerArgumentsResolverInterface, getArguments);

