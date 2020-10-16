
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * FileName: StringResolver.php
 * User: solely
 * DateTime: 2019/6/18 23:30
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_StringResolver) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI\\Resolver, StringResolver, moon, component_di_resolver_stringresolver, moon_component_di_resolver_stringresolver_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Resolver_StringResolver, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *parameters_param = NULL;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parameters_param);

	zephir_get_strval(&parameters, parameters_param);



}

