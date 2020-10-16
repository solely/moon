
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * FileName: Bootstrap.php
 * User: solely
 * DateTime: 2019/11/3 23:12
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\ErrorHandler, Bootstrap, moon, component_errorhandler_bootstrap, moon_component_errorhandler_bootstrap_method_entry, 0);

	zend_declare_property_null(moon_component_errorhandler_bootstrap_ce, SL("instance"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_ErrorHandler_Bootstrap, __construct) {

	zval *this_ptr = getThis();



}

/**
 * @return mixed
 */
PHP_METHOD(Moon_Component_ErrorHandler_Bootstrap, getInstance) {

	zval _0, _2, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, moon_component_errorhandler_bootstrap_ce, SL("instance"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, moon_component_errorhandler_bootstrap_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 99);
		zephir_check_call_status();
		zephir_update_static_property_ce(moon_component_errorhandler_bootstrap_ce, ZEND_STRL("instance"), &_1$$3);
	}
	zephir_read_static_property_ce(&_2, moon_component_errorhandler_bootstrap_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_2);

}

