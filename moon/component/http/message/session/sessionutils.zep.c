
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * FileName: SessionUtils.php
 * User: solely
 * DateTime: 2020/9/7 0:03
 * Description:
 */
/**
 * Session utility functions.
 * Class SessionUtils
 * @package Moon\Component\Http\Message\Session
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_SessionUtils) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message\\Session, SessionUtils, moon, component_http_message_session_sessionutils, moon_component_http_message_session_sessionutils_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

/**
 * Finds the session header amongst the headers that are to be sent, removes it, and returns
 * it so the caller can process it further.
 *
 * @param string $sessionName
 * @param string $sessionId
 * @return string|null
 */
PHP_METHOD(Moon_Component_Http_Message_Session_SessionUtils, popSessionCookie) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_10 = NULL, *_17 = NULL;
	zval *sessionName_param = NULL, *sessionId_param = NULL, __$false, otherCookies, sessionCookieWithId, sessionCookiePrefix, sessionCookie, _0, _2, _4, h, _5, *_6, _7, *_15, _16, _8$$3, _9$$3, _11$$5, _12$$8, _13$$8, _14$$10;
	zval sessionName, sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionName);
	ZVAL_UNDEF(&sessionId);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&otherCookies);
	ZVAL_UNDEF(&sessionCookieWithId);
	ZVAL_UNDEF(&sessionCookiePrefix);
	ZVAL_UNDEF(&sessionCookie);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&h);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionName_param, &sessionId_param);

	zephir_get_strval(&sessionName, sessionName_param);
	zephir_get_strval(&sessionId, sessionId_param);


	ZEPHIR_INIT_VAR(&sessionCookie);
	ZVAL_NULL(&sessionCookie);
	ZEPHIR_CALL_FUNCTION(&_0, "urlencode", &_1, 207, &sessionName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, " %s=");
	ZEPHIR_CALL_FUNCTION(&sessionCookiePrefix, "sprintf", &_3, 3, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "urlencode", &_1, 207, &sessionId);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "%s%s;");
	ZEPHIR_CALL_FUNCTION(&sessionCookieWithId, "sprintf", &_3, 3, &_2, &sessionCookiePrefix, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&otherCookies);
	array_init(&otherCookies);
	ZEPHIR_CALL_FUNCTION(&_5, "headers_list", NULL, 100);
	zephir_check_call_status();
	zephir_is_iterable(&_5, 0, "moon/Component/Http/Message/Session/SessionUtils.zep", 48);
	if (Z_TYPE_P(&_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
		{
			ZEPHIR_INIT_NVAR(&h);
			ZVAL_COPY(&h, _6);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "Set-Cookie:");
			ZEPHIR_CALL_FUNCTION(&_9$$3, "stripos", &_10, 199, &h, &_8$$3);
			zephir_check_call_status();
			if (!ZEPHIR_IS_LONG_IDENTICAL(&_9$$3, 0)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_8$$3);
			zephir_fast_strpos(&_8$$3, &h, &sessionCookiePrefix, 11 );
			if (ZEPHIR_IS_LONG_IDENTICAL(&_8$$3, 11)) {
				ZEPHIR_CPY_WRT(&sessionCookie, &h);
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_fast_strpos(&_11$$5, &h, &sessionCookieWithId, 11 );
				if (!ZEPHIR_IS_LONG_IDENTICAL(&_11$$5, 11)) {
					zephir_array_append(&otherCookies, &h, PH_SEPARATE, "moon/Component/Http/Message/Session/SessionUtils.zep", 42);
				}
			} else {
				zephir_array_append(&otherCookies, &h, PH_SEPARATE, "moon/Component/Http/Message/Session/SessionUtils.zep", 45);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_5, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &_5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&h, &_5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$8);
				ZVAL_STRING(&_12$$8, "Set-Cookie:");
				ZEPHIR_CALL_FUNCTION(&_13$$8, "stripos", &_10, 199, &h, &_12$$8);
				zephir_check_call_status();
				if (!ZEPHIR_IS_LONG_IDENTICAL(&_13$$8, 0)) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_12$$8);
				zephir_fast_strpos(&_12$$8, &h, &sessionCookiePrefix, 11 );
				if (ZEPHIR_IS_LONG_IDENTICAL(&_12$$8, 11)) {
					ZEPHIR_CPY_WRT(&sessionCookie, &h);
					ZEPHIR_INIT_NVAR(&_14$$10);
					zephir_fast_strpos(&_14$$10, &h, &sessionCookieWithId, 11 );
					if (!ZEPHIR_IS_LONG_IDENTICAL(&_14$$10, 11)) {
						zephir_array_append(&otherCookies, &h, PH_SEPARATE, "moon/Component/Http/Message/Session/SessionUtils.zep", 42);
					}
				} else {
					zephir_array_append(&otherCookies, &h, PH_SEPARATE, "moon/Component/Http/Message/Session/SessionUtils.zep", 45);
				}
			ZEPHIR_CALL_METHOD(NULL, &_5, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&h);
	if (Z_TYPE_P(&sessionCookie) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Set-Cookie");
	ZEPHIR_CALL_FUNCTION(NULL, "header_remove", NULL, 208, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&otherCookies, 0, "moon/Component/Http/Message/Session/SessionUtils.zep", 56);
	if (Z_TYPE_P(&otherCookies) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&otherCookies), _15)
		{
			ZEPHIR_INIT_NVAR(&h);
			ZVAL_COPY(&h, _15);
			ZEPHIR_CALL_FUNCTION(NULL, "header", &_17, 12, &h, &__$false);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &otherCookies, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_16, &otherCookies, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&h, &otherCookies, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "header", &_17, 12, &h, &__$false);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &otherCookies, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&h);
	RETURN_CCTOR(&sessionCookie);

}

