
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * FileName: Delegator.php
 * User: solely
 * DateTime: 2019/6/9 23:17
 * Description:
 *  
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Delegator) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI, Delegator, moon, component_di_delegator, moon_component_di_delegator_method_entry, 0);

	zend_class_implements(moon_component_di_delegator_ce, 1, moon_component_di_delegatorinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Delegator, get) {

	zval *id, id_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &id);




}

PHP_METHOD(Moon_Component_DI_Delegator, has) {

	zval *id, id_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &id);




}

PHP_METHOD(Moon_Component_DI_Delegator, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *id_param = NULL, *parameters, parameters_sub, *container, container_sub;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &id_param, &parameters, &container);

	zephir_get_strval(&id, id_param);



}

