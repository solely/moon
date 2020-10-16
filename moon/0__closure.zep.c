
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(moon_0__closure) {

	ZEPHIR_REGISTER_CLASS(moon, 0__closure, moon, 0__closure, moon_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(moon_0__closure, __invoke) {

	zval cn$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *val, val_sub, className$$3, _0$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&val_sub);
	ZVAL_UNDEF(&className$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&cn$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &val);



	if (zephir_instance_of_ev(val, moon_component_di_resolver_unresolvedparam_ce)) {
		ZEPHIR_INIT_VAR(&cn$$3);
		ZVAL_STRING(&cn$$3, "className");
		ZEPHIR_OBS_VAR(&className$$3);
		zephir_read_property_zval(&className$$3, this_ptr, &cn$$3, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2$$3, val, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_0$$3, moon_component_di_exception_ce, "resolvermissingparam", &_1, 0, &className$$3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "moon/Component/DI/Resolver/Medium.zep", 70);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(val, 1, 0);
	RETURN_MM();

}

