
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(moon_5__closure) {

	ZEPHIR_REGISTER_CLASS(moon, 5__closure, moon, 5__closure, moon_5__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(moon_5__closure_ce, SL("errnum"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(moon_5__closure, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval errnum, *k, k_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&errnum);
	ZVAL_UNDEF(&k_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&errnum, moon_5__closure_ce, SL("errnum"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &k);



	ZEPHIR_CALL_FUNCTION(&_0, "constant", NULL, 314, k);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&_0, &errnum));

}

