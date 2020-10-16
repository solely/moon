
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
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(moon_6__closure) {

	ZEPHIR_REGISTER_CLASS(moon, 6__closure, moon, 6__closure, moon_6__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(moon_6__closure_ce, SL("serviceName"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	zend_declare_property_null(moon_6__closure_ce, SL("methodName"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	zend_declare_property_null(moon_6__closure_ce, SL("container"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(moon_6__closure, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval serviceName, methodName, container, *event, event_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&container, moon_6__closure_ce, SL("container"), PH_NOISY_CC);
	zephir_read_static_property_ce(&methodName, moon_6__closure_ce, SL("methodName"), PH_NOISY_CC);
	zephir_read_static_property_ce(&serviceName, moon_6__closure_ce, SL("serviceName"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &event);



	ZEPHIR_CALL_METHOD(&_0, &container, "get", NULL, 0, &serviceName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_ZVAL(NULL, &_0, &methodName, NULL, 0, event);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

