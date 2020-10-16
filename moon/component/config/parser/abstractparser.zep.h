
extern zend_class_entry *moon_component_config_parser_abstractparser_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Config_Parser_AbstractParser);

PHP_METHOD(Moon_Component_Config_Parser_AbstractParser, __construct);
PHP_METHOD(Moon_Component_Config_Parser_AbstractParser, getInstance);
PHP_METHOD(Moon_Component_Config_Parser_AbstractParser, init);
PHP_METHOD(Moon_Component_Config_Parser_AbstractParser, parseFile);
PHP_METHOD(Moon_Component_Config_Parser_AbstractParser, parseString);
void zephir_init_static_properties_Moon_Component_Config_Parser_AbstractParser(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_config_parser_abstractparser_getinstance, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, className)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_abstractparser_parsefile, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_abstractparser_parsefile, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fileName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, fileName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_abstractparser_parsestring, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_config_parser_abstractparser_parsestring, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, configString, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, configString)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_config_parser_abstractparser_method_entry) {
	PHP_ME(Moon_Component_Config_Parser_AbstractParser, __construct, NULL, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Config_Parser_AbstractParser, getInstance, arginfo_moon_component_config_parser_abstractparser_getinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_Config_Parser_AbstractParser, init, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Config_Parser_AbstractParser, parseFile, arginfo_moon_component_config_parser_abstractparser_parsefile, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(Moon_Component_Config_Parser_AbstractParser, parseString, arginfo_moon_component_config_parser_abstractparser_parsestring, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_FE_END
};
