
extern zend_class_entry *moon_component_errorhandler_table_ce;

ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Table);

PHP_METHOD(Moon_Component_ErrorHandler_Table, setTitle);
PHP_METHOD(Moon_Component_ErrorHandler_Table, getTitle);
PHP_METHOD(Moon_Component_ErrorHandler_Table, setContent);
PHP_METHOD(Moon_Component_ErrorHandler_Table, getContent);
zend_object *zephir_init_properties_Moon_Component_ErrorHandler_Table(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_errorhandler_table_settitle, 0, 1, Moon\\Component\\ErrorHandler\\Table, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_table_settitle, 0, 1, IS_OBJECT, "Moon\\Component\\ErrorHandler\\Table", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, title)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_table_gettitle, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_table_gettitle, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_errorhandler_table_setcontent, 0, 1, Moon\\Component\\ErrorHandler\\Table, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_table_setcontent, 0, 1, IS_OBJECT, "Moon\\Component\\ErrorHandler\\Table", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, content, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_table_getcontent, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_table_getcontent, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_errorhandler_table_method_entry) {
	PHP_ME(Moon_Component_ErrorHandler_Table, setTitle, arginfo_moon_component_errorhandler_table_settitle, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Table, getTitle, arginfo_moon_component_errorhandler_table_gettitle, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Table, setContent, arginfo_moon_component_errorhandler_table_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Table, getContent, arginfo_moon_component_errorhandler_table_getcontent, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
