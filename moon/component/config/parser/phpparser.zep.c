
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
#include "kernel/memory.h"
#include "kernel/require.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * FileName: PHP.php
 * User: solely
 * DateTime: 2019/10/6 18:53
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Config_Parser_PHPParser) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Config\\Parser, PHPParser, moon, component_config_parser_phpparser, moon_component_config_parser_abstractparser_ce, moon_component_config_parser_phpparser_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Config_Parser_PHPParser, parseFile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *fileName_param = NULL, config, _0;
	zval fileName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fileName_param);

	zephir_get_strval(&fileName, fileName_param);


	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_0);
	if (zephir_require_zval_ret(&_0, &fileName) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(&config, &_0);
	if (Z_TYPE_P(&config) == IS_ARRAY) {
		RETURN_CCTOR(&config);
	}
	array_init(return_value);
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Config_Parser_PHPParser, parseString) {

	zval _1, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *configString_param = NULL, config, _0, _2, _3, _4;
	zval configString;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configString);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configString_param);

	zephir_get_strval(&configString, configString_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "<?php");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "?>");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_fast_str_replace(&_0, &_1, &_2, &configString);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "<?php %s ?>");
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 3, &_3, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&config);
	zephir_eval_php(&_4, &config, "moon/Component/Config/Parser/PHPParser.zep:29");
	zephir_get_arrval(&_5, &config);
	RETURN_CTOR(&_5);

}

PHP_METHOD(Moon_Component_Config_Parser_PHPParser, getName) {

	zval *this_ptr = getThis();


	RETURN_STRING("php");

}

