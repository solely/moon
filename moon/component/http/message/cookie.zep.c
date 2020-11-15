
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/time.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * FileName: Cookie.php
 * User: solely
 * DateTime: 2020/9/6 22:35
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Cookie) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message, Cookie, moon, component_http_message_cookie, moon_component_http_message_cookie_method_entry, 0);

	zend_declare_property_null(moon_component_http_message_cookie_ce, SL("name"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_cookie_ce, SL("value"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_cookie_ce, SL("domain"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_cookie_ce, SL("expire"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_cookie_ce, SL("path"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_cookie_ce, SL("secure"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_cookie_ce, SL("httpOnly"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(moon_component_http_message_cookie_ce, SL("raw"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_cookie_ce, SL("sameSite"), ZEND_ACC_PRIVATE);

	zend_declare_property_bool(moon_component_http_message_cookie_ce, SL("secureDefault"), 0, ZEND_ACC_PRIVATE);

	zend_declare_property_string(moon_component_http_message_cookie_ce, SL("reservedCharsList"), "=,; \t\r\n\v\f", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_null(moon_component_http_message_cookie_ce, SL("reservedCharsFrom"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_null(moon_component_http_message_cookie_ce, SL("reservedCharsTo"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zephir_declare_class_constant_string(moon_component_http_message_cookie_ce, SL("SAMESITE_NONE"), "none");

	zephir_declare_class_constant_string(moon_component_http_message_cookie_ce, SL("SAMESITE_LAX"), "lax");

	zephir_declare_class_constant_string(moon_component_http_message_cookie_ce, SL("SAMESITE_STRICT"), "strict");

	return SUCCESS;

}

/**
 * Creates cookie from raw header string.
 *
 * @param string $cookie
 * @param bool $decode
 * @return Cookie
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, fromString) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL, *_6 = NULL;
	zend_bool decode;
	zval *cookie_param = NULL, *decode_param = NULL, __$null, __$false, value, name, part, parts, data, _1, _2, _4, _5, _7, _11, _12, _13, _14, _15, _16, _17, _8$$3, _9$$3, _10$$3;
	zval cookie;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookie);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &cookie_param, &decode_param);

	zephir_get_strval(&cookie, cookie_param);
	if (!decode_param) {
		decode = 0;
	} else {
		decode = zephir_get_boolval(decode_param);
	}


	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 7, 0);
	add_assoc_long_ex(&data, SL("expires"), 0);
	add_assoc_stringl_ex(&data, SL("path"), SL("/"));
	zephir_array_update_string(&data, SL("domain"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("secure"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("httponly"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("raw"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&data, SL("samesite"), &__$null, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ";=");
	ZEPHIR_CALL_CE_STATIC(&parts, moon_component_http_message_headerutils_ce, "split", &_0, 0, &cookie, &_1);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&parts);
	ZEPHIR_CALL_FUNCTION(&part, "array_shift", NULL, 85, &parts);
	ZEPHIR_UNREF(&parts);
	zephir_check_call_status();
	if (decode) {
		zephir_array_fetch_long(&_2, &part, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Cookie.zep", 44);
		ZEPHIR_CALL_FUNCTION(&name, "urldecode", &_3, 86, &_2);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_NVAR(&name);
		zephir_array_fetch_long(&name, &part, 0, PH_NOISY, "moon/Component/Http/Message/Cookie.zep", 44);
	}
	if (zephir_array_isset_long(&part, 1)) {
		if (decode) {
			zephir_array_fetch_long(&_4, &part, 1, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Cookie.zep", 45);
			ZEPHIR_CALL_FUNCTION(&value, "urldecode", &_3, 86, &_4);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch_long(&value, &part, 1, PH_NOISY, "moon/Component/Http/Message/Cookie.zep", 45);
		}
	} else {
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_NULL(&value);
	}
	ZEPHIR_CALL_CE_STATIC(&_5, moon_component_http_message_headerutils_ce, "combine", &_6, 0, &parts);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_add_function(&_7, &_5, &data);
	ZEPHIR_CPY_WRT(&data, &_7);
	if (zephir_array_isset_string(&data, SL("max-age"))) {
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_time(&_8$$3);
		ZEPHIR_OBS_VAR(&_9$$3);
		zephir_array_fetch_string(&_9$$3, &data, SL("max-age"), PH_NOISY, "moon/Component/Http/Message/Cookie.zep", 48);
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_LONG(&_10$$3, (zephir_get_numberval(&_8$$3) + zephir_get_intval(&_9$$3)));
		zephir_array_update_string(&data, SL("expires"), &_10$$3, PH_COPY | PH_SEPARATE);
	}
	object_init_ex(return_value, moon_component_http_message_cookie_ce);
	zephir_array_fetch_string(&_11, &data, SL("expires"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Cookie.zep", 50);
	zephir_array_fetch_string(&_12, &data, SL("path"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Cookie.zep", 50);
	zephir_array_fetch_string(&_13, &data, SL("domain"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Cookie.zep", 50);
	zephir_array_fetch_string(&_14, &data, SL("secure"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Cookie.zep", 50);
	zephir_array_fetch_string(&_15, &data, SL("httponly"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Cookie.zep", 50);
	zephir_array_fetch_string(&_16, &data, SL("raw"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Cookie.zep", 50);
	zephir_array_fetch_string(&_17, &data, SL("samesite"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Cookie.zep", 50);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 87, &name, &value, &_11, &_12, &_13, &_14, &_15, &_16, &_17);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_Cookie, create) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool secure, httpOnly, raw;
	zval *name_param = NULL, *value_param = NULL, *expire = NULL, expire_sub, *path = NULL, path_sub, *domain_param = NULL, *secure_param = NULL, *httpOnly_param = NULL, *raw_param = NULL, *sameSite = NULL, sameSite_sub, _0, _1, _2;
	zval name, value, domain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&sameSite_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 8, &name_param, &value_param, &expire, &path, &domain_param, &secure_param, &httpOnly_param, &raw_param, &sameSite);

	zephir_get_strval(&name, name_param);
	if (!value_param) {
		ZEPHIR_INIT_VAR(&value);
		ZVAL_STRING(&value, "");
	} else {
		zephir_get_strval(&value, value_param);
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}
	if (!path) {
		path = &path_sub;
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/");
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(&domain);
		ZVAL_STRING(&domain, "");
	} else {
		zephir_get_strval(&domain, domain_param);
	}
	if (!secure_param) {
		secure = 0;
	} else {
		secure = zephir_get_boolval(secure_param);
	}
	if (!httpOnly_param) {
		httpOnly = 1;
	} else {
		httpOnly = zephir_get_boolval(httpOnly_param);
	}
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}
	if (!sameSite) {
		sameSite = &sameSite_sub;
		ZEPHIR_INIT_VAR(sameSite);
		ZVAL_STRING(sameSite, "lax");
	}


	object_init_ex(return_value, moon_component_http_message_cookie_ce);
	if (secure) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	if (httpOnly) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	if (raw) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 87, &name, &value, expire, path, &domain, &_0, &_1, &_2, sameSite);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string                        $name     The name of the cookie
 * @param string|null                   $value    The value of the cookie
 * @param int|string|\DateTimeInterface $expire   The time the cookie expires
 * @param string                        $path     The path on the server in which the cookie will be available on
 * @param string|null                   $domain   The domain that the cookie is available to
 * @param bool|null                     $secure   Whether the client should send back the cookie only over HTTPS or null to auto-enable this when the request is already using HTTPS
 * @param bool                          $httpOnly Whether the cookie will be made accessible only through the HTTP protocol
 * @param bool                          $raw      Whether the cookie value should be sent with no url encoding
 * @param string|null                   $sameSite Whether the cookie will be available for cross-site requests
 *
 * @throws \InvalidArgumentException
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, __construct) {

	zval _13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool secure, httpOnly, raw, _0;
	zval *name_param = NULL, *value_param = NULL, *expire = NULL, expire_sub, *path = NULL, path_sub, *domain_param = NULL, *secure_param = NULL, *httpOnly_param = NULL, *raw_param = NULL, *sameSite = NULL, sameSite_sub, __$true, __$false, __$null, _1, _2, _9, _10, _11, _14, _15, _3$$3, _4$$3, _5$$3, _6$$5, _7$$5, _8$$6, _12$$9;
	zval name, value, domain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&sameSite_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 8, &name_param, &value_param, &expire, &path, &domain_param, &secure_param, &httpOnly_param, &raw_param, &sameSite);

	zephir_get_strval(&name, name_param);
	if (!value_param) {
		ZEPHIR_INIT_VAR(&value);
		ZVAL_STRING(&value, "");
	} else {
		zephir_get_strval(&value, value_param);
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	} else {
		ZEPHIR_SEPARATE_PARAM(expire);
	}
	if (!path) {
		path = &path_sub;
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/");
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(&domain);
		ZVAL_STRING(&domain, "");
	} else {
		zephir_get_strval(&domain, domain_param);
	}
	if (!secure_param) {
		secure = 0;
	} else {
		secure = zephir_get_boolval(secure_param);
	}
	if (!httpOnly_param) {
		httpOnly = 1;
	} else {
		httpOnly = zephir_get_boolval(httpOnly_param);
	}
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}
	if (!sameSite) {
		sameSite = &sameSite_sub;
		ZEPHIR_INIT_VAR(sameSite);
		ZVAL_STRING(sameSite, "lax");
	} else {
		ZEPHIR_SEPARATE_PARAM(sameSite);
	}


	_0 = raw;
	if (_0) {
		zephir_read_static_property_ce(&_1, moon_component_http_message_cookie_ce, SL("reservedCharsList"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_2, "strpbrk", NULL, 88, &name, &_1);
		zephir_check_call_status();
		_0 = !ZEPHIR_IS_FALSE_IDENTICAL(&_2);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "The cookie name \"%s\" contains invalid characters.");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", NULL, 3, &_4$$3, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 25, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "moon/Component/Http/Message/Cookie.zep", 75);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EMPTY(&name)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The cookie name cannot be empty.", "moon/Component/Http/Message/Cookie.zep", 78);
		return;
	}
	if (zephir_is_instance_of(expire, SL("DateTimeInterface"))) {
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "U");
		ZEPHIR_CALL_METHOD(&_6$$5, expire, "format", NULL, 0, &_7$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(expire, &_6$$5);
	} else if (!(zephir_is_numeric(expire))) {
		ZEPHIR_CALL_FUNCTION(&_8$$6, "strtotime", NULL, 89, expire);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(expire, &_8$$6);
		if (ZEPHIR_IS_FALSE_IDENTICAL(expire)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The cookie expiration time is not valid.", "moon/Component/Http/Message/Cookie.zep", 86);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), &value);
	zephir_update_property_zval(this_ptr, ZEND_STRL("domain"), &domain);
	ZEPHIR_INIT_VAR(&_9);
	if (ZEPHIR_GT_LONG(expire, 0)) {
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_LONG(&_9, zephir_get_intval(expire));
	} else {
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_LONG(&_9, 0);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("expire"), &_9);
	ZEPHIR_INIT_VAR(&_10);
	if (ZEPHIR_IS_EMPTY(path)) {
		ZEPHIR_INIT_NVAR(&_10);
		ZVAL_STRING(&_10, "/");
	} else {
		ZEPHIR_CPY_WRT(&_10, path);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &_10);
	if (secure) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("secure"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("secure"), &__$false);
	}
	if (httpOnly) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("httpOnly"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("httpOnly"), &__$false);
	}
	if (raw) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("raw"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("raw"), &__$false);
	}
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "");
	if (ZEPHIR_IS_IDENTICAL(&_11, sameSite)) {
		ZEPHIR_INIT_NVAR(sameSite);
		ZVAL_NULL(sameSite);
	} else if (Z_TYPE_P(sameSite) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_12$$9);
		zephir_fast_strtolower(&_12$$9, sameSite);
		ZEPHIR_CPY_WRT(sameSite, &_12$$9);
	}
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 4, 0);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "lax");
	zephir_array_fast_append(&_13, &_14);
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "strict");
	zephir_array_fast_append(&_13, &_14);
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "none");
	zephir_array_fast_append(&_13, &_14);
	zephir_array_fast_append(&_13, &__$null);
	ZEPHIR_CALL_FUNCTION(&_15, "in_array", NULL, 5, sameSite, &_13, &__$true);
	zephir_check_call_status();
	if (!zephir_is_true(&_15)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The \"sameSite\" parameter value is not valid.", "moon/Component/Http/Message/Cookie.zep", 103);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("sameSite"), sameSite);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the cookie as a string.
 *
 * @return string The cookie
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, __toString) {

	zval _7;
	zval str, _0, _5, _8, _25, _29, _33, _34, _35, _2$$4, _3$$4, _4$$4, _9$$5, _10$$5, _11$$5, _12$$5, _14$$5, _15$$6, _16$$6, _17$$6, _18$$6, _20$$7, _21$$7, _22$$7, _23$$7, _24$$7, _27$$8, _28$$8, _31$$9, _32$$9, _37$$12, _38$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL, *_13 = NULL, *_19 = NULL, *_26 = NULL, *_30 = NULL, *_36 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_37$$12);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "israw", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&str, this_ptr, "getname", &_1, 0);
		zephir_check_call_status();
	} else {
		zephir_read_static_property_ce(&_2$$4, moon_component_http_message_cookie_ce, SL("reservedCharsFrom"), PH_NOISY_CC | PH_READONLY);
		zephir_read_static_property_ce(&_3$$4, moon_component_http_message_cookie_ce, SL("reservedCharsTo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "getname", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&str);
		zephir_fast_str_replace(&str, &_2$$4, &_3$$4, &_4$$4);
	}
	zephir_concat_self_str(&str, SL("="));
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getvalue", &_6, 0);
	zephir_check_call_status();
	zephir_get_strval(&_7, &_5);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "");
	if (ZEPHIR_IS_IDENTICAL(&_8, &_7)) {
		ZEPHIR_INIT_VAR(&_9$$5);
		zephir_time(&_9$$5);
		ZEPHIR_INIT_VAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "D, d-M-Y H:i:s T");
		ZVAL_LONG(&_11$$5, (zephir_get_numberval(&_9$$5) - 31536001));
		ZEPHIR_CALL_FUNCTION(&_12$$5, "gmdate", &_13, 90, &_10$$5, &_11$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_14$$5);
		ZEPHIR_CONCAT_SVS(&_14$$5, "deleted; expires=", &_12$$5, "; Max-Age=0");
		zephir_concat_self(&str, &_14$$5);
	} else {
		ZEPHIR_INIT_VAR(&_15$$6);
		ZEPHIR_CALL_METHOD(&_16$$6, this_ptr, "israw", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_16$$6)) {
			ZEPHIR_CALL_METHOD(&_15$$6, this_ptr, "getvalue", &_6, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&_17$$6, this_ptr, "getvalue", &_6, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_15$$6, "rawurlencode", NULL, 91, &_17$$6);
			zephir_check_call_status();
		}
		zephir_concat_self(&str, &_15$$6);
		ZEPHIR_CALL_METHOD(&_18$$6, this_ptr, "getexpirestime", &_19, 0);
		zephir_check_call_status();
		if (!ZEPHIR_IS_LONG_IDENTICAL(&_18$$6, 0)) {
			ZEPHIR_CALL_METHOD(&_20$$7, this_ptr, "getexpirestime", &_19, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_21$$7);
			ZVAL_STRING(&_21$$7, "D, d-M-Y H:i:s T");
			ZEPHIR_CALL_FUNCTION(&_22$$7, "gmdate", &_13, 90, &_21$$7, &_20$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_23$$7, this_ptr, "getmaxage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_24$$7);
			ZEPHIR_CONCAT_SVSV(&_24$$7, "; expires=", &_22$$7, "; Max-Age=", &_23$$7);
			zephir_concat_self(&str, &_24$$7);
		}
	}
	ZEPHIR_CALL_METHOD(&_25, this_ptr, "getpath", &_26, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_25)) {
		ZEPHIR_CALL_METHOD(&_27$$8, this_ptr, "getpath", &_26, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_28$$8);
		ZEPHIR_CONCAT_SV(&_28$$8, "; path=", &_27$$8);
		zephir_concat_self(&str, &_28$$8);
	}
	ZEPHIR_CALL_METHOD(&_29, this_ptr, "getdomain", &_30, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_29)) {
		ZEPHIR_CALL_METHOD(&_31$$9, this_ptr, "getdomain", &_30, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_32$$9);
		ZEPHIR_CONCAT_SV(&_32$$9, "; domain=", &_31$$9);
		zephir_concat_self(&str, &_32$$9);
	}
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "issecure", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_33)) {
		zephir_concat_self_str(&str, SL("; secure"));
	}
	ZEPHIR_CALL_METHOD(&_34, this_ptr, "ishttponly", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_34)) {
		zephir_concat_self_str(&str, SL("; httponly"));
	}
	ZEPHIR_CALL_METHOD(&_35, this_ptr, "getsamesite", &_36, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_35) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&_37$$12, this_ptr, "getsamesite", &_36, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_38$$12);
		ZEPHIR_CONCAT_SV(&_38$$12, "; samesite=", &_37$$12);
		zephir_concat_self(&str, &_38$$12);
	}
	RETURN_CCTOR(&str);

}

/**
 * Gets the name of the cookie.
 *
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * Gets the value of the cookie.
 *
 * @return string|null
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, getValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "value");

}

/**
 * Gets the domain that the cookie is available to.
 *
 * @return string|null
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, getDomain) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "domain");

}

/**
 * Gets the time the cookie expires.
 *
 * @return int
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, getExpiresTime) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "expire");

}

/**
 * Gets the max-age attribute.
 *
 * @return int
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, getMaxAge) {

	zval maxAge, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxAge);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("expire"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_time(&_1);
	ZEPHIR_INIT_VAR(&maxAge);
	zephir_sub_function(&maxAge, &_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	if (ZEPHIR_LE_LONG(&maxAge, 0)) {
		ZVAL_LONG(&_1, 0);
	} else {
		ZEPHIR_CPY_WRT(&_1, &maxAge);
	}
	RETURN_CCTOR(&_1);

}

/**
 * Gets the path on the server in which the cookie will be available on.
 *
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, getPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "path");

}

/**
 * Checks whether the cookie should only be transmitted over a secure HTTPS connection from the client.
 *
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, isSecure) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	if (zephir_isset_property(this_ptr, SL("secure"))) {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("secure"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("secureDefault"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Checks whether the cookie will be made accessible only through the HTTP protocol.
 *
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, isHttpOnly) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "httpOnly");

}

/**
 * Whether this cookie is about to be cleared.
 *
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, isCleared) {

	zend_bool _1;
	zval _0, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("expire"), PH_NOISY_CC | PH_READONLY);
	_1 = !ZEPHIR_IS_LONG_IDENTICAL(&_0, 0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("expire"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3);
		zephir_time(&_3);
		_1 = ZEPHIR_LT(&_2, &_3);
	}
	RETURN_MM_BOOL(_1);

}

/**
 * Checks if the cookie value should be sent with no url encoding.
 *
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, isRaw) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "raw");

}

/**
 * Gets the SameSite attribute.
 *
 * @return string|null
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, getSameSite) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sameSite");

}

/**
 * @param bool $default The default value of the "secure" flag when it is set to null
 */
PHP_METHOD(Moon_Component_Http_Message_Cookie, setSecureDefault) {

	zval *_default_param = NULL, __$true, __$false;
	zend_bool _default;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &_default_param);

	_default = zephir_get_boolval(_default_param);


	if (_default) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("secureDefault"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("secureDefault"), &__$false);
	}

}

void zephir_init_static_properties_Moon_Component_Http_Message_Cookie(TSRMLS_D) {

	zval _1;
	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 9, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "%3D");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "%2C");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "%3B");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "%20");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "%09");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "%0D");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "%0A");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "%0B");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "%0C");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_static_property_ce(moon_component_http_message_cookie_ce, ZEND_STRL("reservedCharsTo"), &_0);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 9, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "=");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, ",");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, ";");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, " ");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\t");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\r");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\n");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\v");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\f");
	zephir_array_fast_append(&_2, &_1);
	zephir_update_static_property_ce(moon_component_http_message_cookie_ce, ZEND_STRL("reservedCharsFrom"), &_2);
	ZEPHIR_MM_RESTORE();

}

