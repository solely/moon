
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: HttpExceptionInterface.php
 * User: solely
 * DateTime: 2020/8/19 23:28
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Exception_HttpExceptionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Framework\\Exception, HttpExceptionInterface, moon, framework_exception_httpexceptioninterface, moon_framework_exception_httpexceptioninterface_method_entry);

	zend_class_implements(moon_framework_exception_httpexceptioninterface_ce, 1, zephir_get_internal_ce(SL("throwable")));
	return SUCCESS;

}

/**
 * Returns the status code.
 *
 * @return int An HTTP response status code
 */
ZEPHIR_DOC_METHOD(Moon_Framework_Exception_HttpExceptionInterface, getStatusCode);

/**
 * Returns response headers.
 *
 * @return array Response headers
 */
ZEPHIR_DOC_METHOD(Moon_Framework_Exception_HttpExceptionInterface, getHeaders);

