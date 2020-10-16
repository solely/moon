
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/**
 * FileName: Exception.php
 * User: solely
 * DateTime: 2019/6/13 23:19
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Exception) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI, Exception, moon, component_di_exception, moon_component_di_exception_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Exception, notFoundException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_di_exception_notfoundexception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Service Container %s does not exist");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 3, &_1, container);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 4, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "moon/Component/DI/Exception.zep", 16);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Moon_Component_DI_Exception, resolverException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &exception);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_di_exception_resolverexception_ce);
	ZEPHIR_CALL_METHOD(&_1, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, exception, "getcode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 4, &_1, &_2, exception);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "moon/Component/DI/Exception.zep", 21);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Moon_Component_DI_Exception, resolverNoSuchProperty) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_di_exception_resolverexception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Resolver does not have the class attribute %s");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 3, &_1, key);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 4, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "moon/Component/DI/Exception.zep", 26);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Moon_Component_DI_Exception, resolverMissingParam) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className, className_sub, *param, param_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className, &param);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_di_exception_resolverexception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Class %s parameter %s parsing failure");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 3, &_1, className, param);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 4, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "moon/Component/DI/Exception.zep", 31);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Moon_Component_DI_Exception, resolverCallMethodNotFound) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className, className_sub, *method, method_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className, &method);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_di_exception_resolverexception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Method %s::%s is not found");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 3, &_1, className, method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 4, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "moon/Component/DI/Exception.zep", 36);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Moon_Component_DI_Exception, containerExistingException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_di_exception_containerexistingexception_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "The Service Container %s already exists");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 3, &_1, container);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 4, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "moon/Component/DI/Exception.zep", 41);
	ZEPHIR_MM_RESTORE();
	return;

}

