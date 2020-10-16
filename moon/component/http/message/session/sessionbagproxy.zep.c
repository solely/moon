
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * FileName: SessionBagProxy.php
 * User: solely
 * DateTime: 2020/9/13 23:25
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_SessionBagProxy) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session, SessionBagProxy, moon, component_http_message_session_sessionbagproxy, moon_component_http_message_session_sessionbagproxy_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(moon_component_http_message_session_sessionbagproxy_ce, SL("bag"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_sessionbagproxy_ce, SL("data"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_session_sessionbagproxy_ce, SL("usageIndex"), ZEND_ACC_PRIVATE);

	zend_class_implements(moon_component_http_message_session_sessionbagproxy_ce, 1, moon_component_http_message_session_sessionbaginterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval data;
	zval *bag, bag_sub, *data_param = NULL, *usageIndex, usageIndex_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bag_sub);
	ZVAL_UNDEF(&usageIndex_sub);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &bag, &data_param, &usageIndex);

	zephir_get_arrval(&data, data_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("bag"), bag);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	zephir_update_property_zval(this_ptr, ZEND_STRL("usageIndex"), usageIndex);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, getBag) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("usageIndex"), PH_NOISY_CC);
	ZEPHIR_ADD_ASSIGN(&_0, &_1)
	zephir_update_property_zval(this_ptr, ZEND_STRL("usageIndex"), &_0);
	RETURN_MM_MEMBER(getThis(), "bag");

}

PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, isEmpty) {

	zval _0, _1, _2, _3, _4, _5, _6, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("bag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getstoragekey", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_array_isset(&_0, &_2))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_LONG(&_4, 1);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("usageIndex"), PH_NOISY_CC);
	ZEPHIR_ADD_ASSIGN(&_3, &_4)
	zephir_update_property_zval(this_ptr, ZEND_STRL("usageIndex"), &_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("bag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_7, &_6, "getstoragekey", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch(&_5, &_3, &_7, PH_NOISY, "moon/Component/Http/Message/Session/SessionBagProxy.zep", 33);
	RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(&_5));

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, getName) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("bag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getname", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, initialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_array_param = NULL, _0, _1, _2, _3;
	zval _array;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_array);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_array_param);

	zephir_get_arrval(&_array, _array_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("usageIndex"), PH_NOISY_CC);
	ZEPHIR_ADD_ASSIGN(&_0, &_1)
	zephir_update_property_zval(this_ptr, ZEND_STRL("usageIndex"), &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("bag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_0, "getstoragekey", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("data"), &_2, &_array);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("bag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "initialize", NULL, 0, &_array);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, getStorageKey) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("bag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getstoragekey", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_SessionBagProxy, clear) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("bag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "clear", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

