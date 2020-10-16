
#ifdef HAVE_CONFIG_H
#include "../../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../../php_ext.h"
#include "../../../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * FileName: NullSessionHandler.php
 * User: solely
 * DateTime: 2020/9/7 0:24
 * Description:
 */
/**
 * Can be used in unit testing or in a situations where persisted sessions are not desired.
 *
 * Class NullSessionHandler
 * @package Moon\Component\Http\Message\Session\Storage\Handler
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Handler_NullSessionHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Session\\Storage\\Handler, NullSessionHandler, moon, component_http_message_session_storage_handler_nullsessionhandler, moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, moon_component_http_message_session_storage_handler_nullsessionhandler_method_entry, 0);

	return SUCCESS;

}

/**
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_NullSessionHandler, close) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * @param string $sessionId
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_NullSessionHandler, validateId) {

	zval *sessionId, sessionId_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &sessionId);



	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_NullSessionHandler, doRead) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sessionId_param = NULL;
	zval sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(&sessionId, sessionId_param);


	RETURN_MM_STRING("");

}

/**
 * @param string $sessionId
 * @param string $data
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_NullSessionHandler, updateTimestamp) {

	zval *sessionId, sessionId_sub, *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&data_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &sessionId, &data);



	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_NullSessionHandler, doWrite) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sessionId_param = NULL, *data_param = NULL;
	zval sessionId, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId_param, &data_param);

	zephir_get_strval(&sessionId, sessionId_param);
	zephir_get_strval(&data, data_param);


	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_NullSessionHandler, doDestroy) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sessionId_param = NULL;
	zval sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(&sessionId, sessionId_param);


	RETURN_MM_BOOL(1);

}

/**
 * @param int $maxlifetime
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_NullSessionHandler, gc) {

	zval *maxlifetime, maxlifetime_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &maxlifetime);



	RETURN_BOOL(1);

}

