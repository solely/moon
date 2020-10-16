
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * FileName: DefaultValueParam.php
 * User: solely
 * DateTime: 2019/7/4 23:26
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_DefaultValueParam) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI\\Resolver, DefaultValueParam, moon, component_di_resolver_defaultvalueparam, moon_component_di_resolver_defaultvalueparam_method_entry, 0);

	zend_declare_property_null(moon_component_di_resolver_defaultvalueparam_ce, SL("name"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_di_resolver_defaultvalueparam_ce, SL("value"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Resolver_DefaultValueParam, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), value);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Moon_Component_DI_Resolver_DefaultValueParam, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * @return mixed
 */
PHP_METHOD(Moon_Component_DI_Resolver_DefaultValueParam, getValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "value");

}

