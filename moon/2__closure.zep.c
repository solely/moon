
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(moon_2__closure) {

	ZEPHIR_REGISTER_CLASS(moon, 2__closure, moon, 2__closure, moon_2__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(moon_2__closure_ce, SL("colors"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(moon_2__closure, __invoke) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval colors, *m, m_sub, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&colors);
	ZVAL_UNDEF(&m_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&colors, moon_2__closure_ce, SL("colors"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &m);



	ZEPHIR_INIT_VAR(&_0);
	_1 = zephir_array_isset_long(m, 1);
	if (_1) {
		zephir_array_fetch_long(&_2, m, 1, PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 200);
		_1 = zephir_array_isset(&colors, &_2);
	}
	if (_1) {
		ZEPHIR_OBS_NVAR(&_0);
		ZEPHIR_OBS_VAR(&_3);
		zephir_array_fetch_long(&_3, m, 1, PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 200);
		zephir_array_fetch(&_0, &colors, &_3, PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 200);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "0");
	}
	ZEPHIR_CONCAT_SVS(return_value, "\33[", &_0, "m");
	RETURN_MM();

}

