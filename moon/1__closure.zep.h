
extern zend_class_entry *moon_1__closure_ce;

ZEPHIR_INIT_CLASS(moon_1__closure);

PHP_METHOD(moon_1__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_1__closure___invoke, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_1__closure_method_entry) {
	PHP_ME(moon_1__closure, __invoke, arginfo_moon_1__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
