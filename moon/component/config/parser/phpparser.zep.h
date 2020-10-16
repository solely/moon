
extern zend_class_entry *moon_component_config_parser_phpparser_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Config_Parser_PHPParser);

PHP_METHOD(Moon_Component_Config_Parser_PHPParser, parseFile);
PHP_METHOD(Moon_Component_Config_Parser_PHPParser, parseString);
PHP_METHOD(Moon_Component_Config_Parser_PHPParser, getName);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_phpparser_parsefile, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_phpparser_parsefile, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fileName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, fileName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_phpparser_parsestring, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_phpparser_parsestring, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, configString, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, configString)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_phpparser_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_phpparser_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_config_parser_phpparser_method_entry) {
	PHP_ME(Moon_Component_Config_Parser_PHPParser, parseFile, arginfo_moon_component_config_parser_phpparser_parsefile, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Config_Parser_PHPParser, parseString, arginfo_moon_component_config_parser_phpparser_parsestring, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Config_Parser_PHPParser, getName, arginfo_moon_component_config_parser_phpparser_getname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
