
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
 * FileName: ObjectInject.php
 * User: solely
 * DateTime: 2020/5/24 19:17
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Inject_ObjectInject) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\DI\\Inject, ObjectInject, moon, component_di_inject_objectinject, moon_component_di_inject_inject_ce, moon_component_di_inject_objectinject_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Inject_ObjectInject, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &parameters, &container);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setobject", NULL, 0, parameters);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

