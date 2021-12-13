
extern zend_class_entry *moon_framework_kernel_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Kernel);

PHP_METHOD(Moon_Framework_Kernel, __construct);
PHP_METHOD(Moon_Framework_Kernel, handle);
PHP_METHOD(Moon_Framework_Kernel, finishRequest);
PHP_METHOD(Moon_Framework_Kernel, handleThrowable);
PHP_METHOD(Moon_Framework_Kernel, filterResponse);
PHP_METHOD(Moon_Framework_Kernel, varToString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_kernel___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Psr\\Container\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_kernel_handle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_INFO(0, _catch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_kernel_finishrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_kernel_handlethrowable, 0, 2, Moon\\Component\\Http\\Message\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_kernel_handlethrowable, 0, 2, IS_OBJECT, "Moon\\Component\\Http\\Message\\Response", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, e, Throwable, 0)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_kernel_filterresponse, 0, 3, Moon\\Component\\Http\\Message\\Response, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_kernel_filterresponse, 0, 3, IS_OBJECT, "Moon\\Component\\Http\\Message\\Response", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, response, Moon\\Component\\Http\\Message\\Response, 0)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_OBJ_INFO(0, route, Moon\\Component\\Router\\Node, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_kernel_vartostring, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_kernel_vartostring, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_kernel_method_entry) {
	PHP_ME(Moon_Framework_Kernel, __construct, arginfo_moon_framework_kernel___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Framework_Kernel, handle, arginfo_moon_framework_kernel_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Kernel, finishRequest, arginfo_moon_framework_kernel_finishrequest, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Framework_Kernel, handleThrowable, arginfo_moon_framework_kernel_handlethrowable, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Framework_Kernel, filterResponse, arginfo_moon_framework_kernel_filterresponse, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Framework_Kernel, varToString, arginfo_moon_framework_kernel_vartostring, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
