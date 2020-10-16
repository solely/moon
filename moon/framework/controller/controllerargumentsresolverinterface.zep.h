
extern zend_class_entry *moon_framework_controller_controllerargumentsresolverinterface_ce;

ZEPHIR_INIT_CLASS(Moon_Framework_Controller_ControllerArgumentsResolverInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_framework_controller_controllerargumentsresolverinterface_getarguments, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, request, Moon\\Component\\Http\\Message\\ServerRequest, 0)
	ZEND_ARG_OBJ_INFO(0, node, Moon\\Component\\Router\\Node, 0)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_framework_controller_controllerargumentsresolverinterface_method_entry) {
	PHP_ABSTRACT_ME(Moon_Framework_Controller_ControllerArgumentsResolverInterface, getArguments, arginfo_moon_framework_controller_controllerargumentsresolverinterface_getarguments)
	PHP_FE_END
};
