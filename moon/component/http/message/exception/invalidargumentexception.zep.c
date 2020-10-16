
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * FileName: InvalidArgumentException.php
 * User: solely
 * DateTime: 2020/9/30 20:41
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Exception_InvalidArgumentException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Exception, InvalidArgumentException, moon, component_http_message_exception_invalidargumentexception, zend_exception_get_default(TSRMLS_C), NULL, 0);

	return SUCCESS;

}

