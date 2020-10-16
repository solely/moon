
extern zend_class_entry *moon_6__closure_ce;

ZEPHIR_INIT_CLASS(moon_6__closure);

PHP_METHOD(moon_6__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_6__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_6__closure_method_entry) {
	PHP_ME(moon_6__closure, __invoke, arginfo_moon_6__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
