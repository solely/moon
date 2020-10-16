
extern zend_class_entry *moon_component_errorhandler_bootstrap_ce;

ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Bootstrap);

PHP_METHOD(Moon_Component_ErrorHandler_Bootstrap, __construct);
PHP_METHOD(Moon_Component_ErrorHandler_Bootstrap, getInstance);

ZEPHIR_INIT_FUNCS(moon_component_errorhandler_bootstrap_method_entry) {
	PHP_ME(Moon_Component_ErrorHandler_Bootstrap, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_ErrorHandler_Bootstrap, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
