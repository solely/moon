
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: ModulesInterface.php
 * User: solely
 * DateTime: 2020/5/13 23:34
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_ModulesInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Framework, ModulesInterface, moon, framework_modulesinterface, moon_framework_modulesinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Moon_Framework_ModulesInterface, boot);

ZEPHIR_DOC_METHOD(Moon_Framework_ModulesInterface, shutdown);

ZEPHIR_DOC_METHOD(Moon_Framework_ModulesInterface, getName);

/**
 * Gets the Module directory path.
 *
 * The path should always be returned as a Unix path (with /).
 *
 * @return string The Module absolute path
 */
ZEPHIR_DOC_METHOD(Moon_Framework_ModulesInterface, getPath);

/**
 * Builds the module.
 *
 * @param Container $container
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Moon_Framework_ModulesInterface, build);

