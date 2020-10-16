
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: BootstrapInterface.php
 * User: solely
 * DateTime: 2020/5/12 23:35
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_BootstrapInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Framework, BootstrapInterface, moon, framework_bootstrapinterface, moon_framework_bootstrapinterface_method_entry);

	return SUCCESS;

}

/**
 * @return ModulesInterface[]
 */
ZEPHIR_DOC_METHOD(Moon_Framework_BootstrapInterface, registerModules);

ZEPHIR_DOC_METHOD(Moon_Framework_BootstrapInterface, boot);

ZEPHIR_DOC_METHOD(Moon_Framework_BootstrapInterface, shutdown);

ZEPHIR_DOC_METHOD(Moon_Framework_BootstrapInterface, getModules);

ZEPHIR_DOC_METHOD(Moon_Framework_BootstrapInterface, getModule);

ZEPHIR_DOC_METHOD(Moon_Framework_BootstrapInterface, getProjectDir);

ZEPHIR_DOC_METHOD(Moon_Framework_BootstrapInterface, getContainer);

ZEPHIR_DOC_METHOD(Moon_Framework_BootstrapInterface, getLogDir);

ZEPHIR_DOC_METHOD(Moon_Framework_BootstrapInterface, getConfigDir);

ZEPHIR_DOC_METHOD(Moon_Framework_BootstrapInterface, getServicesDir);

ZEPHIR_DOC_METHOD(Moon_Framework_BootstrapInterface, getRoutesFile);

