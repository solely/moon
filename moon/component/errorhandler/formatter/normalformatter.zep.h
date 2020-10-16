
extern zend_class_entry *moon_component_errorhandler_formatter_normalformatter_ce;

ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Formatter_NormalFormatter);

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, format);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, log);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, output);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, render);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getCss);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getScript);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, formatMessage);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getSourceFile);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getCallStack);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getPanelList);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getVariables);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, isCollapsed);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, highlightFile);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, highlightPhp);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, highlightLine);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, toHtml);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, toJson);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, dumpVar);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getDumper);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, addPanel);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, addPanelTable);
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, __call);
zend_object *zephir_init_properties_Moon_Component_ErrorHandler_Formatter_NormalFormatter(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_format, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, exception, Throwable, 0)
	ZEND_ARG_INFO(0, debug)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_iscollapsed, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_iscollapsed, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, file)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_highlightfile, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_highlightfile, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, file)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, line, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, line)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lines, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, lines)
#endif
	ZEND_ARG_ARRAY_INFO(0, vars, 0)
	ZEND_ARG_ARRAY_INFO(0, keysToHide, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_highlightphp, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_highlightphp, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, source)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, line, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, line)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lines, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, lines)
#endif
	ZEND_ARG_ARRAY_INFO(0, vars, 0)
	ZEND_ARG_ARRAY_INFO(0, keysToHide, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_highlightline, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_highlightline, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, html, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, html)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, line, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, line)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lines, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, lines)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_tohtml, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_tohtml, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_tojson, 0, 0, 1)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_dumpvar, 0, 0, 1)
	ZEND_ARG_INFO(0, _var)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_addpanel, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, title)
#endif
	ZEND_ARG_OBJ_INFO(0, table, Moon\\Component\\ErrorHandler\\Table, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_addpaneltable, 0, 2, Moon\\Component\\ErrorHandler\\Table, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter_addpaneltable, 0, 2, IS_OBJECT, "Moon\\Component\\ErrorHandler\\Table", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, title)
#endif
	ZEND_ARG_ARRAY_INFO(0, content, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_formatter_normalformatter___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_errorhandler_formatter_normalformatter_method_entry) {
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, format, arginfo_moon_component_errorhandler_formatter_normalformatter_format, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, log, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, output, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, render, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getCss, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getScript, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, formatMessage, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getSourceFile, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getCallStack, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getPanelList, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getVariables, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, isCollapsed, arginfo_moon_component_errorhandler_formatter_normalformatter_iscollapsed, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, highlightFile, arginfo_moon_component_errorhandler_formatter_normalformatter_highlightfile, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, highlightPhp, arginfo_moon_component_errorhandler_formatter_normalformatter_highlightphp, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, highlightLine, arginfo_moon_component_errorhandler_formatter_normalformatter_highlightline, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, toHtml, arginfo_moon_component_errorhandler_formatter_normalformatter_tohtml, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, toJson, arginfo_moon_component_errorhandler_formatter_normalformatter_tojson, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, dumpVar, arginfo_moon_component_errorhandler_formatter_normalformatter_dumpvar, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getDumper, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, addPanel, arginfo_moon_component_errorhandler_formatter_normalformatter_addpanel, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, addPanelTable, arginfo_moon_component_errorhandler_formatter_normalformatter_addpaneltable, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_ErrorHandler_Formatter_NormalFormatter, __call, arginfo_moon_component_errorhandler_formatter_normalformatter___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
