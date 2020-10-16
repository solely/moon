
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
 * FileName: UnresolvedParam.php
 * User: solely
 * DateTime: 2019/7/4 23:29
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Resolver_UnresolvedParam) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI\\Resolver, UnresolvedParam, moon, component_di_resolver_unresolvedparam, moon_component_di_resolver_unresolvedparam_method_entry, 0);

	zend_declare_property_null(moon_component_di_resolver_unresolvedparam_ce, SL("name"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Resolver_UnresolvedParam, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return string
 */
PHP_METHOD(Moon_Component_DI_Resolver_UnresolvedParam, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

