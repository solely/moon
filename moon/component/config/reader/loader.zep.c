
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * FileName: Loader.php
 * User: solely
 * DateTime: 2019/10/8 0:07
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Config_Reader_Loader) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Config\\Reader, Loader, moon, component_config_reader_loader, moon_component_config_reader_loader_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Config_Reader_Loader, glob) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *flags_param = NULL, _0;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &flags_param);

	zephir_get_strval(&pattern, pattern_param);
	if (!flags_param) {
		flags = 0;
	} else {
		flags = zephir_get_intval(flags_param);
	}


	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("glob", NULL, 54, &pattern, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

