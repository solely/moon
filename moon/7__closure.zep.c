
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(moon_7__closure) {

	ZEPHIR_REGISTER_CLASS(moon, 7__closure, moon, 7__closure, moon_7__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(moon_7__closure_ce, SL("error"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(moon_7__closure, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval error, *e, e_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&e_sub);

	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&error, moon_7__closure_ce, SL("error"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &e);



	if (!ZEPHIR_IS_LONG_IDENTICAL(e, 2)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(&error, e);
	ZEPHIR_MM_RESTORE();

}

