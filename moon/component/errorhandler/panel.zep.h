
extern zend_class_entry *moon_component_errorhandler_panel_ce;

ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Panel);

PHP_METHOD(Moon_Component_ErrorHandler_Panel, setTitle);
PHP_METHOD(Moon_Component_ErrorHandler_Panel, getTitle);
PHP_METHOD(Moon_Component_ErrorHandler_Panel, setContent);
PHP_METHOD(Moon_Component_ErrorHandler_Panel, getContent);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_errorhandler_panel_settitle, 0, 1, Moon\\Component\\ErrorHandler\\Panel, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_panel_settitle, 0, 1, IS_OBJECT, "Moon\\Component\\ErrorHandler\\Panel", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, title)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_panel_gettitle, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_panel_gettitle, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_errorhandler_panel_setcontent, 0, 1, Moon\\Component\\ErrorHandler\\Panel, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_panel_setcontent, 0, 1, IS_OBJECT, "Moon\\Component\\ErrorHandler\\Panel", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, content, Moon\\Component\\ErrorHandler\\Table, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_errorhandler_panel_method_entry) {
	PHP_ME(Moon_Component_ErrorHandler_Panel, setTitle, arginfo_moon_component_errorhandler_panel_settitle, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Panel, getTitle, arginfo_moon_component_errorhandler_panel_gettitle, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Panel, setContent, arginfo_moon_component_errorhandler_panel_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Panel, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
