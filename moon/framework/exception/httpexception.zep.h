
extern zend_class_entry *moon_framework_exception_httpexception_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Exception_HttpException);

PHP_METHOD(Moon_Framework_Exception_HttpException, __construct);
PHP_METHOD(Moon_Framework_Exception_HttpException, getStatusCode);
PHP_METHOD(Moon_Framework_Exception_HttpException, getHeaders);
PHP_METHOD(Moon_Framework_Exception_HttpException, setHeaders);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_exception_httpexception___construct, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statusCode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, statusCode)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_OBJ_INFO(0, previous, Throwable, 0)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_exception_httpexception_getstatuscode, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_exception_httpexception_getstatuscode, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_exception_httpexception_getheaders, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_exception_httpexception_getheaders, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_exception_httpexception_setheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_exception_httpexception_method_entry) {
	PHP_ME(Moon_Framework_Exception_HttpException, __construct, arginfo_moon_framework_exception_httpexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Framework_Exception_HttpException, getStatusCode, arginfo_moon_framework_exception_httpexception_getstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Exception_HttpException, getHeaders, arginfo_moon_framework_exception_httpexception_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Exception_HttpException, setHeaders, arginfo_moon_framework_exception_httpexception_setheaders, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
