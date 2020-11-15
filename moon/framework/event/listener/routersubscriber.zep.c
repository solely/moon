
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * FileName: RouterSubscriber.php
 * User: solely
 * DateTime: 2020/7/26 16:51
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Event_Listener_RouterSubscriber) {

	ZEPHIR_REGISTER_CLASS(Moon\\Framework\\Event\\Listener, RouterSubscriber, moon, framework_event_listener_routersubscriber, moon_framework_event_listener_routersubscriber_method_entry, 0);

	zend_class_implements(moon_framework_event_listener_routersubscriber_ce, 1, moon_component_eventdispatcher_subscriberinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Framework_Event_Listener_RouterSubscriber, onKernelRequest) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, router, request, _0, _1, _2$$3, _3$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, event, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Moon\\Framework\\Event\\Event\\RequestEvent");
	if (ZEPHIR_IS_EQUAL(&_1, &_0)) {
		ZEPHIR_CALL_METHOD(&request, event, "getrequest", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&router, event, "getrouter", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, &request, "getmethod", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &request, "geturi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, &_4$$3, "getpath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, &router, "match", NULL, 0, &_3$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, event, "setroute", NULL, 0, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Event_Listener_RouterSubscriber, onKernelException) {

	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, path, _0, _1, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	ZEPHIR_CALL_METHOD(&_0, event, "getrequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&path, &_1, "getpath", NULL, 0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_STRING(&path, "");
	if (!(_2)) {
		_2 = ZEPHIR_IS_STRING(&path, "/");
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(NULL, event, "allowcustomresponsecode", NULL, 177);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, event, "getcontainer", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "bootstrap");
		ZEPHIR_CALL_METHOD(&_5$$3, &_4$$3, "get", NULL, 0, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, &_5$$3, "getmoonversion", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "createnormalresponse", NULL, 178, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, event, "setresponse", NULL, 0, &_3$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, event, "stoppropagation", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Event_Listener_RouterSubscriber, onKernelFinishRequest) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	ZEPHIR_CALL_METHOD(NULL, event, "stoppropagation", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Event_Listener_RouterSubscriber, registerListeners) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *proxy, proxy_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&proxy_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &proxy);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "onKernelRequest");
	ZVAL_LONG(&_1, 32);
	ZEPHIR_CALL_METHOD(NULL, proxy, "addlistener", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "onKernelFinishRequest");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, proxy, "addlistener", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "onKernelException");
	ZVAL_LONG(&_1, -32);
	ZEPHIR_CALL_METHOD(NULL, proxy, "addlistener", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Framework_Event_Listener_RouterSubscriber, createNormalResponse) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *version, version_sub, html, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version_sub);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &version);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "<div style=\"text-align: center\"><h2>hello，Moon！</h2> <p>version：%s</p></div>");
	ZEPHIR_CALL_FUNCTION(&html, "sprintf", NULL, 3, &_0, version);
	zephir_check_call_status();
	object_init_ex(return_value, moon_component_http_message_htmlresponse_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 179, &html);
	zephir_check_call_status();
	RETURN_MM();

}

