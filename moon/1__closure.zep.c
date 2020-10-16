
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(moon_1__closure) {

	ZEPHIR_REGISTER_CLASS(moon, 1__closure, moon, 1__closure, moon_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(moon_1__closure, __invoke) {

	zend_bool _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *a, a_sub, *b, b_sub, __$false, _0, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&a_sub);
	ZVAL_UNDEF(&b_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a, &b);



	ZEPHIR_INIT_VAR(&_0);
	_1 = ZEPHIR_IS_STRING_IDENTICAL(b, "");
	if (!(_1)) {
		_2 = zephir_class_exists(a, zephir_is_true(&__$false) );
		if (_2) {
			ZEPHIR_CALL_FUNCTION(&_3, "is_subclass_of", NULL, 268, a, b);
			zephir_check_call_status();
			_2 = zephir_is_true(&_3);
		}
		_1 = _2;
	}
	if (_1) {
		ZVAL_LONG(&_0, -1);
	} else {
		ZVAL_LONG(&_0, 1);
	}
	RETURN_CCTOR(&_0);

}

