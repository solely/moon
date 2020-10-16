
extern zend_class_entry *moon_framework_controller_controllerresolver_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Controller_ControllerResolver);

PHP_METHOD(Moon_Framework_Controller_ControllerResolver, getController);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_controller_controllerresolver_getcontroller, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, node, Moon\\Component\\Router\\Node, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_controller_controllerresolver_method_entry) {
	PHP_ME(Moon_Framework_Controller_ControllerResolver, getController, arginfo_moon_framework_controller_controllerresolver_getcontroller, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
