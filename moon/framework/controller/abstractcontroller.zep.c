
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * FileName: AbstractController.php
 * User: solely
 * DateTime: 2020/8/24 23:46
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Controller_AbstractController) {

	ZEPHIR_REGISTER_CLASS(Moon\\Framework\\Controller, AbstractController, moon, framework_controller_abstractcontroller, moon_framework_controller_abstractcontroller_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/** @var ContainerInterface */
	zend_declare_property_null(moon_framework_controller_abstractcontroller_ce, SL("container"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * @internal
 * @required
 */
PHP_METHOD(Moon_Framework_Controller_AbstractController, setContainer) {

	zval *container, container_sub, previous;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&previous);

	zephir_fetch_params_without_memory_grow(1, 0, &container);



	zephir_read_property(&previous, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	RETURN_CTORW(&previous);

}

/**
 * @return ContainerInterface
 */
PHP_METHOD(Moon_Framework_Controller_AbstractController, getContainer) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Returns true if the service id is defined.
 *
 * @param string $id
 * @return bool
 */
PHP_METHOD(Moon_Framework_Controller_AbstractController, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, _0;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, &id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a container service by its id.
 *
 * @param string $id
 * @return object
 */
PHP_METHOD(Moon_Framework_Controller_AbstractController, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, _0;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &id);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates a URL from the given parameters.
 * @throws \Exception
 */
PHP_METHOD(Moon_Framework_Controller_AbstractController, generateUrl) {

	zval *this_ptr = getThis();


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "Temporarily unrealized.", "moon/Framework/Controller/AbstractController.zep", 66);
	return;

}

/**
 *  Forwards the request to another controller.
 * @throws \Exception
 */
PHP_METHOD(Moon_Framework_Controller_AbstractController, forward) {

	zval *this_ptr = getThis();


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "Temporarily unrealized.", "moon/Framework/Controller/AbstractController.zep", 76);
	return;

}

PHP_METHOD(Moon_Framework_Controller_AbstractController, redirect) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long statusCode, ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *statusCode_param = NULL, _0;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &statusCode_param);

	zephir_get_strval(&url, url_param);
	if (!statusCode_param) {
		statusCode = 302;
	} else {
		statusCode = zephir_get_intval(statusCode_param);
	}


	object_init_ex(return_value, moon_component_http_message_redirectresponse_ce);
	ZVAL_LONG(&_0, statusCode);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 286, &url, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a RedirectResponse to the given route with the given parameters.
 * @throws \Exception
 */
PHP_METHOD(Moon_Framework_Controller_AbstractController, redirectToRoute) {

	zval *this_ptr = getThis();


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "Temporarily unrealized.", "moon/Framework/Controller/AbstractController.zep", 90);
	return;

}

/**
 * @param $data
 * @param int $statusCode
 * @param array $headers
 * @return JsonResponse
 * @throws \Exception
 */
PHP_METHOD(Moon_Framework_Controller_AbstractController, json) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval headers;
	zend_long statusCode, ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, *statusCode_param = NULL, *headers_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &data, &statusCode_param, &headers_param);

	if (!statusCode_param) {
		statusCode = 200;
	} else {
		statusCode = zephir_get_intval(statusCode_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	object_init_ex(return_value, moon_component_http_message_jsonresponse_ce);
	ZVAL_LONG(&_0, statusCode);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 287, data, &_0, &headers);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Framework_Controller_AbstractController, getRequest) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "request");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Framework_Controller_AbstractController, getConfig) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "config");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

