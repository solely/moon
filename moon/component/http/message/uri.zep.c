
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * FileName: Uri.php
 * User: solely
 * DateTime: 2018/12/16 15:37
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Uri) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message, Uri, moon, component_http_message_uri, moon_component_http_message_uri_method_entry, 0);

	zend_declare_property_string(moon_component_http_message_uri_ce, SL("scheme"), "", ZEND_ACC_PRIVATE);

	zend_declare_property_string(moon_component_http_message_uri_ce, SL("host"), "", ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_uri_ce, SL("port"), ZEND_ACC_PRIVATE);

	zend_declare_property_string(moon_component_http_message_uri_ce, SL("userInfo"), "", ZEND_ACC_PRIVATE);

	zend_declare_property_string(moon_component_http_message_uri_ce, SL("path"), "", ZEND_ACC_PRIVATE);

	zend_declare_property_string(moon_component_http_message_uri_ce, SL("query"), "", ZEND_ACC_PRIVATE);

	zend_declare_property_string(moon_component_http_message_uri_ce, SL("fragment"), "", ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_http_message_uri_ce, SL("uriString"), ZEND_ACC_PRIVATE);

	zephir_declare_class_constant_string(moon_component_http_message_uri_ce, SL("CHAR_UNRESERVED"), "a-zA-Z0-9_\\-\\.~\\pL");

	zephir_declare_class_constant_string(moon_component_http_message_uri_ce, SL("CHAR_SUB_DELIMS"), "!\\$&'\\(\\)\\*\\+,;=");

	zend_class_implements(moon_component_http_message_uri_ce, 1, zephir_get_internal_ce(SL("psr\\http\\message\\uriinterface")));
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Uri, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
		zephir_get_strval(&uri, uri_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&uri))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "parseuri", NULL, 255, &uri);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Uri, getAuthority) {

	zval authority, _0, _1, _2, _5, _3$$4, _4$$4, _6$$5, _7$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&authority);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("host"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_OBS_VAR(&authority);
	zephir_read_property(&authority, this_ptr, ZEND_STRL("host"), PH_NOISY_CC);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("userInfo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	if (!ZEPHIR_IS_IDENTICAL(&_2, &_1)) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("userInfo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_VSV(&_4$$4, &_3$$4, "@", &authority);
		ZEPHIR_CPY_WRT(&authority, &_4$$4);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_5) != IS_NULL) {
		zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZEPHIR_CONCAT_SV(&_7$$5, ":", &_6$$5);
		zephir_concat_self(&authority, &_7$$5);
	}
	RETURN_CCTOR(&authority);

}

PHP_METHOD(Moon_Component_Http_Message_Uri, withFragment) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fragment = NULL, fragment_sub, _new, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fragment_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fragment);

	ZEPHIR_SEPARATE_PARAM(fragment);


	if (!(Z_TYPE_P(fragment) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The argument must be a string", "moon/Component/Http/Message/Uri.zep", 50);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterfragment", NULL, 256, fragment);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(fragment, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("fragment"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(&_1, fragment)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_new, ZEND_STRL("fragment"), fragment);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Uri, getFragment) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "fragment");

}

PHP_METHOD(Moon_Component_Http_Message_Uri, withHost) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *host = NULL, host_sub, _new, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &host);

	ZEPHIR_SEPARATE_PARAM(host);


	if (!(Z_TYPE_P(host) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The argument must be a string", "moon/Component/Http/Message/Uri.zep", 70);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterhost", NULL, 257, host);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(host, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("host"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(&_1, host)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_new, ZEND_STRL("host"), host);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Uri, getHost) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "host");

}

PHP_METHOD(Moon_Component_Http_Message_Uri, withPath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path = NULL, path_sub, _new, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);

	ZEPHIR_SEPARATE_PARAM(path);


	if (!(Z_TYPE_P(path) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The argument must be a string", "moon/Component/Http/Message/Uri.zep", 90);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "?");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, path, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter values is not a valid URI and contains characters ?", "moon/Component/Http/Message/Uri.zep", 93);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "#");
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_strpos(&_3, path, &_2, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter values is not a valid URI and contains anchor points", "moon/Component/Http/Message/Uri.zep", 96);
		return;
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "filterpath", NULL, 258, path);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(path, &_4);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(&_5, path)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_new, ZEND_STRL("path"), path);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Uri, getPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "path");

}

PHP_METHOD(Moon_Component_Http_Message_Uri, withPort) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *port, port_sub, _new, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&port_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port);



	if (!(Z_TYPE_P(port) == IS_LONG)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The parameter must be an integer", "moon/Component/Http/Message/Uri.zep", 116);
		return;
	}
	_0 = ZEPHIR_LT_LONG(port, 1);
	if (!(_0)) {
		_0 = ZEPHIR_GT_LONG(port, 65535);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter values is not a valid TCP/UDP port", "moon/Component/Http/Message/Uri.zep", 119);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(&_1, port)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_new, ZEND_STRL("port"), port);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Uri, getPort) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "port");

}

PHP_METHOD(Moon_Component_Http_Message_Uri, withQuery) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query = NULL, query_sub, _new, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query);

	ZEPHIR_SEPARATE_PARAM(query);


	if (!(Z_TYPE_P(query) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The argument must be a string", "moon/Component/Http/Message/Uri.zep", 138);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "#");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, query, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter values cannot contain anchor points", "moon/Component/Http/Message/Uri.zep", 141);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "filterquery", NULL, 259, query);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(query, &_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("query"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(&_3, query)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_new, ZEND_STRL("query"), query);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Uri, getQuery) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "query");

}

PHP_METHOD(Moon_Component_Http_Message_Uri, withScheme) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *scheme = NULL, scheme_sub, _new, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme_sub);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme);

	ZEPHIR_SEPARATE_PARAM(scheme);


	if (!(Z_TYPE_P(scheme) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The argument must be a string", "moon/Component/Http/Message/Uri.zep", 161);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filterscheme", NULL, 260, scheme);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(scheme, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("scheme"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(&_1, scheme)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_new, ZEND_STRL("scheme"), scheme);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Uri, getScheme) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "scheme");

}

PHP_METHOD(Moon_Component_Http_Message_Uri, withUserInfo) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user = NULL, user_sub, *password = NULL, password_sub, __$null, _new, _1, _5, _3$$5, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&password_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_new);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &user, &password);

	ZEPHIR_SEPARATE_PARAM(user);
	if (!password) {
		password = &password_sub;
		password = &__$null;
	}


	if (!(Z_TYPE_P(user) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The first argument must be a string", "moon/Component/Http/Message/Uri.zep", 181);
		return;
	}
	_0 = !(Z_TYPE_P(password) == IS_NULL);
	if (_0) {
		_0 = !(Z_TYPE_P(password) == IS_STRING);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The second argument must be either a string or null", "moon/Component/Http/Message/Uri.zep", 184);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "filteruser", &_2, 261, user);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(user, &_1);
	if (!(Z_TYPE_P(password) == IS_NULL)) {
		ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "filteruser", &_2, 261, password);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_CONCAT_SV(&_4$$5, ":", &_3$$5);
		zephir_concat_self(user, &_4$$5);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("userInfo"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_IDENTICAL(&_5, user)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_new);
	if (zephir_clone(&_new, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&_new, ZEND_STRL("userInfo"), user);
	RETURN_CCTOR(&_new);

}

PHP_METHOD(Moon_Component_Http_Message_Uri, getUserInfo) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "userInfo");

}

PHP_METHOD(Moon_Component_Http_Message_Uri, __toString) {

	zval _0, _1, _3, _4, _5, _6, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("uriString"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "uriString");
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("scheme"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getauthority", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getpath", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, ZEND_STRL("query"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("fragment"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_STATIC(&_1, "createuristring", &_2, 262, &_3, &_4, &_5, &_6, &_7);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("uriString"), &_1);
	RETURN_MM_MEMBER(getThis(), "uriString");

}

PHP_METHOD(Moon_Component_Http_Message_Uri, parseUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, result, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _0$$3, _1$$3, _2$$3;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(&uri, uri_param);


	ZEPHIR_CALL_FUNCTION(&result, "parse_url", NULL, 221, &uri);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Parsing the URI failed and \"%s\" could be a seriously unqualified URL");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", NULL, 3, &_1$$3, &uri);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 33, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "moon/Component/Http/Message/Uri.zep", 217);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	if (zephir_array_isset_string(&result, SL("scheme"))) {
		zephir_array_fetch_string(&_4, &result, SL("scheme"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Uri.zep", 219);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "filterscheme", NULL, 260, &_4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, "");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("scheme"), &_3);
	ZEPHIR_INIT_VAR(&_5);
	if (zephir_array_isset_string(&result, SL("host"))) {
		zephir_array_fetch_string(&_6, &result, SL("host"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Uri.zep", 220);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "filterhost", NULL, 257, &_6);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_STRING(&_5, "");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("host"), &_5);
	ZEPHIR_INIT_VAR(&_7);
	if (zephir_array_isset_string(&result, SL("port"))) {
		ZEPHIR_OBS_NVAR(&_7);
		zephir_array_fetch_string(&_7, &result, SL("port"), PH_NOISY, "moon/Component/Http/Message/Uri.zep", 221);
	} else {
		zephir_read_property(&_8, this_ptr, ZEND_STRL("scheme"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "filterport", NULL, 263, &_8);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("port"), &_7);
	ZEPHIR_INIT_VAR(&_9);
	if (zephir_array_isset_string(&result, SL("user"))) {
		zephir_array_fetch_string(&_10, &result, SL("user"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Uri.zep", 222);
		ZEPHIR_CALL_METHOD(&_9, this_ptr, "filteruser", NULL, 261, &_10);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_STRING(&_9, "");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("userInfo"), &_9);
	ZEPHIR_INIT_VAR(&_11);
	if (zephir_array_isset_string(&result, SL("path"))) {
		zephir_array_fetch_string(&_12, &result, SL("path"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Uri.zep", 223);
		ZEPHIR_CALL_METHOD(&_11, this_ptr, "filterpath", NULL, 258, &_12);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_11);
		ZVAL_STRING(&_11, "");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &_11);
	ZEPHIR_INIT_VAR(&_13);
	if (zephir_array_isset_string(&result, SL("query"))) {
		zephir_array_fetch_string(&_14, &result, SL("query"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Uri.zep", 224);
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "filterquery", NULL, 259, &_14);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_13);
		ZVAL_STRING(&_13, "");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("query"), &_13);
	ZEPHIR_INIT_VAR(&_15);
	if (zephir_array_isset_string(&result, SL("fragment"))) {
		zephir_array_fetch_string(&_16, &result, SL("fragment"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Uri.zep", 225);
		ZEPHIR_CALL_METHOD(&_15, this_ptr, "filterfragment", NULL, 256, &_16);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_15);
		ZVAL_STRING(&_15, "");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("fragment"), &_15);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Uri, filterScheme) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *scheme_param = NULL, _0, _1, _2;
	zval scheme;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme_param);

	zephir_get_strval(&scheme, scheme_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/(?=:\\/\\/).*/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 36, &_0, &_1, &scheme);
	zephir_check_call_status();
	zephir_get_strval(&scheme, &_2);
	zephir_fast_strtolower(return_value, &scheme);
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_Uri, filterUser) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user_param = NULL, _2;
	zval user, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &user_param);

	zephir_get_strval(&user, user_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SSSS(&_0, "/(?:[^%", "a-zA-Z0-9_\\-\\.~\\pL", "!\\$&'\\(\\)\\*\\+,;=", "]+|%(?![A-Fa-f0-9]{2}))/u");
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	zephir_array_fast_append(&_1, this_ptr);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "urlEncode");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace_callback", NULL, 109, &_0, &_1, &user);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_Uri, filterHost) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *host_param = NULL;
	zval host;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &host_param);

	zephir_get_strval(&host, host_param);


	zephir_fast_strtolower(return_value, &host);
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_Uri, filterPort) {

	zend_long port = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *scheme_param = NULL;
	zval scheme;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &scheme_param);

	zephir_get_strval(&scheme, scheme_param);


	do {
		if (ZEPHIR_IS_STRING(&scheme, "http")) {
			port = 80;
			break;
		}
		if (ZEPHIR_IS_STRING(&scheme, "https")) {
			port = 443;
			break;
		}
		if (ZEPHIR_IS_STRING(&scheme, "ftp")) {
			port = 21;
			break;
		}
		if (ZEPHIR_IS_STRING(&scheme, "ftps")) {
			port = 990;
			break;
		}
		port = 0;
		break;
	} while(0);

	RETURN_MM_LONG(port);

}

PHP_METHOD(Moon_Component_Http_Message_Uri, filterPath) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _2, _3;
	zval path, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SSS(&_0, "/(?:[^", "a-zA-Z0-9_\\-\\.~\\pL", ")(:@&=\\+\\$,\\/;%]+|%(?![A-Fa-f0-9]{2}))/u");
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	zephir_array_fast_append(&_1, this_ptr);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "urlEncode");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace_callback", NULL, 109, &_0, &_1, &path);
	zephir_check_call_status();
	zephir_get_strval(&path, &_3);
	RETURN_CTOR(&path);

}

PHP_METHOD(Moon_Component_Http_Message_Uri, filterQuery) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *query_param = NULL, result, queryArr, _0, _1, item, *_2, _3, _4$$3, _5$$3, _6$$3, _8$$3, _9$$3, _10$$3, _12$$4, _13$$4, _14$$4, _15$$4, _16$$4, _17$$4;
	zval query;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&queryArr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &query_param);

	zephir_get_strval(&query, query_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "?");
	zephir_fast_trim(&_0, &query, &_1, ZEPHIR_TRIM_LEFT);
	zephir_get_strval(&query, &_0);
	ZEPHIR_INIT_VAR(&queryArr);
	zephir_fast_explode_str(&queryArr, SL("&"), &query, LONG_MAX);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&queryArr, 0, "moon/Component/Http/Message/Uri.zep", 291);
	if (Z_TYPE_P(&queryArr) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queryArr), _2)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _2);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_fast_explode_str(&_4$$3, SL("="), &item, LONG_MAX);
			ZEPHIR_CPY_WRT(&item, &_4$$3);
			zephir_array_fetch_long(&_6$$3, &item, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Uri.zep", 289);
			ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "filterparams", &_7, 264, &_6$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$3);
			if (zephir_array_isset_long(&item, 1)) {
				zephir_array_fetch_long(&_9$$3, &item, 1, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Uri.zep", 289);
				ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "filterparams", &_7, 264, &_9$$3);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&_8$$3);
				ZVAL_STRING(&_8$$3, "");
			}
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "%s=%s");
			ZEPHIR_CALL_FUNCTION(&_10$$3, "sprintf", &_11, 3, &_4$$3, &_5$$3, &_8$$3);
			zephir_check_call_status();
			zephir_array_append(&result, &_10$$3, PH_SEPARATE, "moon/Component/Http/Message/Uri.zep", 289);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &queryArr, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &queryArr, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &queryArr, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$4);
				zephir_fast_explode_str(&_12$$4, SL("="), &item, LONG_MAX);
				ZEPHIR_CPY_WRT(&item, &_12$$4);
				zephir_array_fetch_long(&_14$$4, &item, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Uri.zep", 289);
				ZEPHIR_CALL_METHOD(&_13$$4, this_ptr, "filterparams", &_7, 264, &_14$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$4);
				if (zephir_array_isset_long(&item, 1)) {
					zephir_array_fetch_long(&_16$$4, &item, 1, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Uri.zep", 289);
					ZEPHIR_CALL_METHOD(&_15$$4, this_ptr, "filterparams", &_7, 264, &_16$$4);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(&_15$$4);
					ZVAL_STRING(&_15$$4, "");
				}
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZVAL_STRING(&_12$$4, "%s=%s");
				ZEPHIR_CALL_FUNCTION(&_17$$4, "sprintf", &_11, 3, &_12$$4, &_13$$4, &_15$$4);
				zephir_check_call_status();
				zephir_array_append(&result, &_17$$4, PH_SEPARATE, "moon/Component/Http/Message/Uri.zep", 289);
			ZEPHIR_CALL_METHOD(NULL, &queryArr, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	if (!(ZEPHIR_IS_EMPTY(&result))) {
		zephir_fast_join_str(return_value, SL("&"), &result);
		RETURN_MM();
	}
	RETURN_MM_STRING("");

}

PHP_METHOD(Moon_Component_Http_Message_Uri, filterFragment) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fragment_param = NULL;
	zval fragment;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fragment);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fragment_param);

	zephir_get_strval(&fragment, fragment_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filterparams", NULL, 264, &fragment);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_Uri, urlEncode) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *matches_param = NULL, _0;
	zval matches;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches_param);

	zephir_get_arrval(&matches, matches_param);


	zephir_array_fetch_long(&_0, &matches, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Uri.zep", 304);
	ZEPHIR_RETURN_CALL_FUNCTION("rawurlencode", NULL, 181, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_Uri, filterParams) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, _2;
	zval params, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_strval(&params, params_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SSSS(&_0, "/(?:[^", "a-zA-Z0-9_\\-\\.~\\pL", "!\\$&'\\(\\)\\*\\+,;=", "%:@\\/\\?]+|%(?![A-Fa-f0-9]{2}))/u");
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	zephir_array_fast_append(&_1, this_ptr);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "urlEncode");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace_callback", NULL, 109, &_0, &_1, &params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_Uri, createUriString) {

	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *scheme_param = NULL, *authority_param = NULL, *path_param = NULL, *query_param = NULL, *fragment_param = NULL, uri, _0, _4, _6, _8, _9, _10, _11, _13, _16, _1$$3, _2$$3, _14$$6, _15$$6, _17$$7, _18$$7;
	zval scheme, authority, path, query, fragment, _5$$4, _12$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&authority);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&fragment);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &scheme_param, &authority_param, &path_param, &query_param, &fragment_param);

	zephir_get_strval(&scheme, scheme_param);
	zephir_get_strval(&authority, authority_param);
	zephir_get_strval(&path, path_param);
	zephir_get_strval(&query, query_param);
	zephir_get_strval(&fragment, fragment_param);


	ZEPHIR_INIT_VAR(&uri);
	ZVAL_STRING(&uri, "");
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (!ZEPHIR_IS_IDENTICAL(&_0, &scheme)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "%s:");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", &_3, 3, &_1$$3, &scheme);
		zephir_check_call_status();
		zephir_concat_self(&uri, &_2$$3);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "");
	if (!ZEPHIR_IS_IDENTICAL(&_4, &authority)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SV(&_5$$4, "//", &authority);
		zephir_concat_self(&uri, &_5$$4);
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "");
	_7 = !ZEPHIR_IS_IDENTICAL(&_6, &path);
	if (_7) {
		ZVAL_LONG(&_8, 0);
		ZVAL_LONG(&_9, 1);
		ZEPHIR_INIT_VAR(&_10);
		zephir_substr(&_10, &path, 0 , 1 , 0);
		ZEPHIR_INIT_VAR(&_11);
		ZVAL_STRING(&_11, "/");
		_7 = !ZEPHIR_IS_IDENTICAL(&_11, &_10);
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&_12$$5);
		ZEPHIR_CONCAT_SV(&_12$$5, "/", &path);
		ZEPHIR_CPY_WRT(&path, &_12$$5);
	}
	zephir_concat_self(&uri, &path);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "");
	if (!ZEPHIR_IS_IDENTICAL(&_13, &query)) {
		ZEPHIR_INIT_VAR(&_14$$6);
		ZVAL_STRING(&_14$$6, "?%s");
		ZEPHIR_CALL_FUNCTION(&_15$$6, "sprintf", &_3, 3, &_14$$6, &query);
		zephir_check_call_status();
		zephir_concat_self(&uri, &_15$$6);
	}
	ZEPHIR_INIT_VAR(&_16);
	ZVAL_STRING(&_16, "");
	if (!ZEPHIR_IS_IDENTICAL(&_16, &fragment)) {
		ZEPHIR_INIT_VAR(&_17$$7);
		ZVAL_STRING(&_17$$7, "#%s");
		ZEPHIR_CALL_FUNCTION(&_18$$7, "sprintf", &_3, 3, &_17$$7, &fragment);
		zephir_check_call_status();
		zephir_concat_self(&uri, &_18$$7);
	}
	RETURN_CCTOR(&uri);

}

PHP_METHOD(Moon_Component_Http_Message_Uri, __clone) {

	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);


	zephir_update_property_zval(this_ptr, ZEND_STRL("uriString"), &__$null);

}

