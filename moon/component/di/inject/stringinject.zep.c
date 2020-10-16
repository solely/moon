
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
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * FileName: StringInject.php
 * User: solely
 * DateTime: 2019/6/18 23:34
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Inject_StringInject) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\DI\\Inject, StringInject, moon, component_di_inject_stringinject, moon_component_di_inject_inject_ce, moon_component_di_inject_stringinject_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Inject_StringInject, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *container, container_sub, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &parameters_param, &container);

	zephir_get_strval(&parameters, parameters_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setclassname", NULL, 0, &parameters);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, container, "getdefaultislazy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setislazy", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

