
extern zend_class_entry *moon_2__closure_ce;

ZEPHIR_INIT_CLASS(moon_2__closure);

PHP_METHOD(moon_2__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_2__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, m)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_2__closure_method_entry) {
	PHP_ME(moon_2__closure, __invoke, arginfo_moon_2__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};