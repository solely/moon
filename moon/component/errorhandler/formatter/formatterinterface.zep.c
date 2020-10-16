
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: FormatterInterface.php
 * User: solely
 * DateTime: 2019/11/23 19:14
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Formatter_FormatterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\ErrorHandler\\Formatter, FormatterInterface, moon, component_errorhandler_formatter_formatterinterface, moon_component_errorhandler_formatter_formatterinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Moon_Component_ErrorHandler_Formatter_FormatterInterface, format);

