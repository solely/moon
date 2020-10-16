
extern zend_class_entry *moon_component_config_parser_parserfactory_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Config_Parser_ParserFactory);

PHP_METHOD(Moon_Component_Config_Parser_ParserFactory, parseFile);
PHP_METHOD(Moon_Component_Config_Parser_ParserFactory, parseString);
PHP_METHOD(Moon_Component_Config_Parser_ParserFactory, getParserClass);
PHP_METHOD(Moon_Component_Config_Parser_ParserFactory, setParserClass);
void zephir_init_static_properties_Moon_Component_Config_Parser_ParserFactory(TSRMLS_D);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_parserfactory_parsefile, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_parserfactory_parsefile, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, files)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_parserfactory_parsestring, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_parserfactory_parsestring, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, configStringArr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_config_parser_parserfactory_setparserclass, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, pc, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_config_parser_parserfactory_method_entry) {
	PHP_ME(Moon_Component_Config_Parser_ParserFactory, parseFile, arginfo_moon_component_config_parser_parserfactory_parsefile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Config_Parser_ParserFactory, parseString, arginfo_moon_component_config_parser_parserfactory_parsestring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Config_Parser_ParserFactory, getParserClass, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Config_Parser_ParserFactory, setParserClass, arginfo_moon_component_config_parser_parserfactory_setparserclass, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
