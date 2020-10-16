
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
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * FileName: CallableInject.php
 * User: solely
 * DateTime: 2019/6/23 16:39
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Inject_CallableInject) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\DI\\Inject, CallableInject, moon, component_di_inject_callableinject, moon_component_di_inject_inject_ce, moon_component_di_inject_callableinject_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Inject_CallableInject, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &parameters, &container);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcallable", NULL, 0, parameters);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

