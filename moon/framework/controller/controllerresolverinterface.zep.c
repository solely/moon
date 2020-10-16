
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: ControllerResolverInterface.php
 * User: solely
 * DateTime: 2020/8/20 23:34
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Controller_ControllerResolverInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Framework\\Controller, ControllerResolverInterface, moon, framework_controller_controllerresolverinterface, moon_framework_controller_controllerresolverinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the Controller instance associated with a Request.
 *
 * As several resolvers can exist for a single application, a resolver must
 * return false when it is not able to determine the controller.
 *
 * The resolver must only throw an exception when it should be able to load a
 * controller but cannot because of some errors made by the developer.
 *
 * @param Node $node
 * @return callable|false A PHP callable representing the Controller,
 *                        or false if this resolver is not able to determine the controller
 *
 * @throws \LogicException If a controller was found based on the request but it is not callable
 */
ZEPHIR_DOC_METHOD(Moon_Framework_Controller_ControllerResolverInterface, getController);

