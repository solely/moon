
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"


/**
 * FileName: Yaml.php
 * User: solely
 * DateTime: 2019/10/6 18:59
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Config_Parser_Yaml) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Config\\Parser, Yaml, moon, component_config_parser_yaml, moon_component_config_parser_abstractparser_ce, moon_component_config_parser_yaml_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Config_Parser_Yaml, parseFile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fileName_param = NULL, yaml;
	zval fileName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&yaml);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fileName_param);

	zephir_get_strval(&fileName, fileName_param);


	ZEPHIR_CALL_FUNCTION(&yaml, "yaml_parse_file", NULL, 50, &fileName);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parse", NULL, 51, &yaml);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Config_Parser_Yaml, parseString) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *configString_param = NULL, yaml;
	zval configString;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configString);
	ZVAL_UNDEF(&yaml);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configString_param);

	zephir_get_strval(&configString, configString_param);


	ZEPHIR_CALL_FUNCTION(&yaml, "yaml_parse", NULL, 52, &configString);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parse", NULL, 51, &yaml);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Config_Parser_Yaml, init) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "yaml");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 53, &_0);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(moon_component_config_exception_ce, "Failed to load yaml extension", "moon/Component/Config/Parser/Yaml.zep", 32);
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, moon_component_config_parser_yaml_ce, getThis(), "init", &_2, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Config_Parser_Yaml, parse) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *yaml_param = NULL;
	zval yaml;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&yaml);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &yaml_param);

	zephir_get_arrval(&yaml, yaml_param);


	RETURN_CTOR(&yaml);

}

PHP_METHOD(Moon_Component_Config_Parser_Yaml, getName) {

	zval *this_ptr = getThis();


	RETURN_STRING("yaml");

}

