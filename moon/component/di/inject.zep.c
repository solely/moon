
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * FileName: Inject.php
 * User: solely
 * DateTime: 2019/4/7 20:53
 * Description:
 *
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Inject) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI, Inject, moon, component_di_inject, moon_component_di_inject_method_entry, 0);

	zend_declare_property_null(moon_component_di_inject_ce, SL("data"), ZEND_ACC_PRIVATE);

	moon_component_di_inject_ce->create_object = zephir_init_properties_Moon_Component_DI_Inject;

	zend_class_implements(moon_component_di_inject_ce, 1, moon_component_di_injectinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Inject, factory) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters, parameters_sub, *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &parameters, &container);



	if (Z_TYPE_P(parameters) == IS_STRING) {
		object_init_ex(return_value, moon_component_di_inject_stringinject_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 79, parameters, container);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(parameters) == IS_ARRAY) {
		object_init_ex(return_value, moon_component_di_inject_arrayinject_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 80, parameters, container);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_is_callable(parameters) == 1) {
		object_init_ex(return_value, moon_component_di_inject_callableinject_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 81, parameters, container);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(parameters) == IS_OBJECT) {
		object_init_ex(return_value, moon_component_di_inject_objectinject_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 82, parameters, container);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Moon_Component_DI_Inject(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("data"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

