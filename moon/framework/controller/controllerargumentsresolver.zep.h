
extern zend_class_entry *moon_framework_controller_controllerargumentsresolver_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Controller_ControllerArgumentsResolver);

PHP_METHOD(Moon_Framework_Controller_ControllerArgumentsResolver, getArguments);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_controller_controllerargumentsresolver_getarguments, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_OBJ_INFO(0, node, Moon\\Component\\Router\\Node, 0)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_controller_controllerargumentsresolver_method_entry) {
	PHP_ME(Moon_Framework_Controller_ControllerArgumentsResolver, getArguments, arginfo_moon_framework_controller_controllerargumentsresolver_getarguments, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
