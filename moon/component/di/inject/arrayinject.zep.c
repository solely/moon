
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * FileName: ArrayInject.php
 * User: solely
 * DateTime: 2019/6/18 23:36
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Inject_ArrayInject) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\DI\\Inject, ArrayInject, moon, component_di_inject_arrayinject, moon_component_di_inject_inject_ce, moon_component_di_inject_arrayinject_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Inject_ArrayInject, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *container, container_sub, _0, _1, _2, _3;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &parameters_param, &container);

	zephir_get_arrval(&parameters, parameters_param);


	zephir_array_fetch_string(&_0, &parameters, SL("class"), PH_NOISY | PH_READONLY, "moon/Component/DI/Inject/ArrayInject.zep", 14);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setclassname", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &parameters, SL("arguments"), PH_NOISY | PH_READONLY, "moon/Component/DI/Inject/ArrayInject.zep", 15);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setarguments", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &parameters, SL("callMethods"), PH_NOISY | PH_READONLY, "moon/Component/DI/Inject/ArrayInject.zep", 16);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcallmethods", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	if (zephir_array_isset_string(&parameters, SL("isLazy"))) {
		ZEPHIR_OBS_NVAR(&_3);
		zephir_array_fetch_string(&_3, &parameters, SL("isLazy"), PH_NOISY, "moon/Component/DI/Inject/ArrayInject.zep", 17);
	} else {
		ZEPHIR_CALL_METHOD(&_3, container, "getdefaultislazy", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setislazy", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

