
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * FileName: AbstractParser.php
 * User: solely
 * DateTime: 2019/10/6 18:34
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Config_Parser_AbstractParser) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Config\\Parser, AbstractParser, moon, component_config_parser_abstractparser, moon_component_config_parser_abstractparser_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(moon_component_config_parser_abstractparser_ce, SL("instance"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Config_Parser_AbstractParser, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @return static
 */
PHP_METHOD(Moon_Component_Config_Parser_AbstractParser, getInstance) {

	zend_class_entry *_6$$3;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, _0, _2, _3, _7, _8, _4$$3, _5$$3;
	zval className;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(&className, className_param);


	zephir_read_static_property_ce(&_0, moon_component_config_parser_abstractparser_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	_1 = !(zephir_array_isset(&_0, &className));
	if (!(_1)) {
		zephir_read_static_property_ce(&_2, moon_component_config_parser_abstractparser_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_3);
		zephir_array_fetch(&_3, &_2, &className, PH_NOISY, "moon/Component/Config/Parser/AbstractParser.zep", 24);
		_1 = ZEPHIR_IS_EMPTY(&_3);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_fetch_safe_class(&_5$$3, &className);
		_6$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_5$$3), Z_STRLEN_P(&_5$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_6$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_4$$3, _6$$3);
		if (zephir_has_constructor(&_4$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_static_property_array_multi_ce(moon_component_config_parser_abstractparser_ce, SL("instance"), &_4$$3, SL("z"), 1, &className);
	}
	zephir_read_static_property_ce(&_7, moon_component_config_parser_abstractparser_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_8, &_7, &className, PH_NOISY | PH_READONLY, "moon/Component/Config/Parser/AbstractParser.zep", 27);
	RETURN_CTOR(&_8);

}

PHP_METHOD(Moon_Component_Config_Parser_AbstractParser, init) {

	zval *this_ptr = getThis();



}

PHP_METHOD(Moon_Component_Config_Parser_AbstractParser, parseFile) {

}

PHP_METHOD(Moon_Component_Config_Parser_AbstractParser, parseString) {

}

void zephir_init_static_properties_Moon_Component_Config_Parser_AbstractParser(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(moon_component_config_parser_abstractparser_ce, ZEND_STRL("instance"), &_0);
	ZEPHIR_MM_RESTORE();

}

