
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * FileName: AbstractProxy.php
 * User: solely
 * DateTime: 2020/9/7 23:41
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Proxy_AbstractProxy) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session\\Storage\\Proxy, AbstractProxy, moon, component_http_message_session_storage_proxy_abstractproxy, moon_component_http_message_session_storage_proxy_abstractproxy_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Flag if handler wraps an internal PHP session handler (using \SessionHandler).
	 *
	 * @var bool
	 */
	zend_declare_property_bool(moon_component_http_message_session_storage_proxy_abstractproxy_ce, SL("wrapper"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_proxy_abstractproxy_ce, SL("saveHandlerName"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Gets the session.save_handler name.
 *
 * @return string|null
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_AbstractProxy, getSaveHandlerName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "saveHandlerName");

}

/**
 * Is this proxy handler and instance of \SessionHandlerInterface.
 *
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_AbstractProxy, isSessionHandlerInterface) {

	zval *this_ptr = getThis();


	RETURN_BOOL(zephir_is_instance_of(this_ptr, SL("SessionHandlerInterface")));

}

/**
 * Returns true if this handler wraps an internal PHP session save handler using \SessionHandler.
 *
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_AbstractProxy, isWrapper) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "wrapper");

}

/**
 * Has a session started?
 *
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_AbstractProxy, isActive) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "session_status", NULL, 57);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 2));

}

/**
 * Gets the session ID.
 *
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_AbstractProxy, getId) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_id", NULL, 60);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the session ID.
 *
 * @param string $id
 * @throws \LogicException
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_AbstractProxy, setId) {

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isactive", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_LogicException, "Cannot change the ID of an active session.", "moon/Component/Http/Message/Session/Storage/Proxy/AbstractProxy.zep", 80);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 60, &id);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the session name.
 *
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_AbstractProxy, getName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_name", NULL, 59);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the session name.
 *
 * @param string $name
 * @throws \LogicException
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Proxy_AbstractProxy, setName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isactive", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_LogicException, "Cannot change the name of an active session.", "moon/Component/Http/Message/Session/Storage/Proxy/AbstractProxy.zep", 104);
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "session_name", NULL, 59, &name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

