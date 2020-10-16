
extern zend_class_entry *moon_framework_controller_abstractcontroller_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Controller_AbstractController);

PHP_METHOD(Moon_Framework_Controller_AbstractController, setContainer);
PHP_METHOD(Moon_Framework_Controller_AbstractController, getContainer);
PHP_METHOD(Moon_Framework_Controller_AbstractController, has);
PHP_METHOD(Moon_Framework_Controller_AbstractController, get);
PHP_METHOD(Moon_Framework_Controller_AbstractController, generateUrl);
PHP_METHOD(Moon_Framework_Controller_AbstractController, forward);
PHP_METHOD(Moon_Framework_Controller_AbstractController, redirect);
PHP_METHOD(Moon_Framework_Controller_AbstractController, redirectToRoute);
PHP_METHOD(Moon_Framework_Controller_AbstractController, json);
PHP_METHOD(Moon_Framework_Controller_AbstractController, getRequest);
PHP_METHOD(Moon_Framework_Controller_AbstractController, getConfig);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_setcontainer, 0, 1, Psr\\Container\\ContainerInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_setcontainer, 0, 1, IS_OBJECT, "Psr\\Container\\ContainerInterface", 1)
#endif
	ZEND_ARG_OBJ_INFO(0, container, Psr\\Container\\ContainerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_getcontainer, 0, 0, Psr\\Container\\ContainerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_getcontainer, 0, 0, IS_OBJECT, "Psr\\Container\\ContainerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_get, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_get, 0, 1, IS_OBJECT, "NULL", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_redirect, 0, 1, Moon\\Component\\Http\\Message\\RedirectResponse, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_redirect, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\RedirectResponse", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statusCode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, statusCode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_json, 0, 1, Moon\\Component\\Http\\Message\\JsonResponse, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_framework_controller_abstractcontroller_json, 0, 1, IS_OBJECT, "Moon\\Component\\Http\\Message\\JsonResponse", 0)
#endif
	ZEND_ARG_INFO(0, data)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statusCode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, statusCode)
#endif
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_controller_abstractcontroller_method_entry) {
	PHP_ME(Moon_Framework_Controller_AbstractController, setContainer, arginfo_moon_framework_controller_abstractcontroller_setcontainer, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Controller_AbstractController, getContainer, arginfo_moon_framework_controller_abstractcontroller_getcontainer, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Framework_Controller_AbstractController, has, arginfo_moon_framework_controller_abstractcontroller_has, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Framework_Controller_AbstractController, get, arginfo_moon_framework_controller_abstractcontroller_get, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Framework_Controller_AbstractController, generateUrl, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Framework_Controller_AbstractController, forward, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Framework_Controller_AbstractController, redirect, arginfo_moon_framework_controller_abstractcontroller_redirect, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Framework_Controller_AbstractController, redirectToRoute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Framework_Controller_AbstractController, json, arginfo_moon_framework_controller_abstractcontroller_json, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Framework_Controller_AbstractController, getRequest, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Framework_Controller_AbstractController, getConfig, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
