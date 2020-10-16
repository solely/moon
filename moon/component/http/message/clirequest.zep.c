
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"


/**
 * FileName: CLIRequest.php
 * User: solely
 * DateTime: 2020/7/14 0:24
 * Description:  这里专门用来处理 CLI 命令行的请求
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_CLIRequest) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message, CLIRequest, moon, component_http_message_clirequest, moon_component_http_message_serverrequest_ce, moon_component_http_message_clirequest_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_CLIRequest, create) {

	zval *this_ptr = getThis();



}

