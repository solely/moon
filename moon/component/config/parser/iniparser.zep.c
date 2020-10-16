
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
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * FileName: INI.php
 * User: solely
 * DateTime: 2019/10/6 18:58
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Config_Parser_INIParser) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Config\\Parser, INIParser, moon, component_config_parser_iniparser, moon_component_config_parser_abstractparser_ce, moon_component_config_parser_iniparser_method_entry, 0);

	return SUCCESS;

}

/**
 *
 [base]
 host=localhost
 user=testuser
 pass=testpass
 database=default
 
 [users:base]
 database=users
 
 [archive : base]
 database=archive
 *  解析了像这样的配置文件，多层继承的配置。
 * @param string $fileName
 * @return array
 */
PHP_METHOD(Moon_Component_Config_Parser_INIParser, parseFile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fileName_param = NULL, __$true, ini;
	zval fileName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileName);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&ini);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fileName_param);

	zephir_get_strval(&fileName, fileName_param);


	ZEPHIR_CALL_FUNCTION(&ini, "parse_ini_file", NULL, 70, &fileName, &__$true);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parse", NULL, 0, &ini);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Config_Parser_INIParser, parseString) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *configString_param = NULL, __$true, ini;
	zval configString;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configString);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&ini);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configString_param);

	zephir_get_strval(&configString, configString_param);


	ZEPHIR_CALL_FUNCTION(&ini, "parse_ini_string", NULL, 71, &configString, &__$true);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parse", NULL, 0, &ini);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Config_Parser_INIParser, getName) {

	zval *this_ptr = getThis();


	RETURN_STRING("ini");

}

PHP_METHOD(Moon_Component_Config_Parser_INIParser, parse) {

	zend_string *_3, *_15$$3, *_11$$5, *_27$$10, *_23$$12;
	zend_ulong _2, _14$$3, _10$$5, _26$$10, _22$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ini_param = NULL, _extends, name, config, _namespace, properties, *_0, _1, namespaceArr$$3, _4$$3, _5$$3, prop_1$$3, val_1$$3, *_12$$3, _13$$3, _6$$4, prop$$5, val$$5, _7$$5, *_8$$5, _9$$5, namespaceArr$$10, _16$$10, _17$$10, prop_1$$10, val_1$$10, *_24$$10, _25$$10, _18$$11, prop$$12, val$$12, _19$$12, *_20$$12, _21$$12;
	zval ini;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ini);
	ZVAL_UNDEF(&_extends);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_namespace);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&namespaceArr$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&prop_1$$3);
	ZVAL_UNDEF(&val_1$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&prop$$5);
	ZVAL_UNDEF(&val$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&namespaceArr$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&prop_1$$10);
	ZVAL_UNDEF(&val_1$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&prop$$12);
	ZVAL_UNDEF(&val$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_21$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ini_param);

	zephir_get_arrval(&ini, ini_param);


	ZEPHIR_INIT_VAR(&config);
	array_init(&config);
	zephir_is_iterable(&ini, 0, "moon/Component/Config/Parser/INIParser.zep", 84);
	if (Z_TYPE_P(&ini) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&ini), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&_namespace);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&_namespace, _3);
			} else {
				ZVAL_LONG(&_namespace, _2);
			}
			ZEPHIR_INIT_NVAR(&properties);
			ZVAL_COPY(&properties, _0);
			ZEPHIR_INIT_NVAR(&namespaceArr$$3);
			zephir_fast_explode_str(&namespaceArr$$3, SL(":"), &_namespace, LONG_MAX);
			zephir_array_fetch_long(&_4$$3, &namespaceArr$$3, 0, PH_NOISY | PH_READONLY, "moon/Component/Config/Parser/INIParser.zep", 63);
			ZEPHIR_INIT_NVAR(&name);
			zephir_fast_trim(&name, &_4$$3, NULL , ZEPHIR_TRIM_BOTH);
			zephir_array_fetch_long(&_5$$3, &namespaceArr$$3, 1, PH_NOISY | PH_READONLY, "moon/Component/Config/Parser/INIParser.zep", 64);
			ZEPHIR_INIT_NVAR(&_extends);
			zephir_fast_trim(&_extends, &_5$$3, NULL , ZEPHIR_TRIM_BOTH);
			if (!(zephir_array_isset(&config, &name))) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				array_init(&_6$$4);
				zephir_array_update_zval(&config, &name, &_6$$4, PH_COPY | PH_SEPARATE);
			}
			if (zephir_array_isset(&ini, &_extends)) {
				zephir_array_fetch(&_7$$5, &ini, &_extends, PH_NOISY | PH_READONLY, "moon/Component/Config/Parser/INIParser.zep", 73);
				zephir_is_iterable(&_7$$5, 0, "moon/Component/Config/Parser/INIParser.zep", 76);
				if (Z_TYPE_P(&_7$$5) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_7$$5), _10$$5, _11$$5, _8$$5)
					{
						ZEPHIR_INIT_NVAR(&prop$$5);
						if (_11$$5 != NULL) { 
							ZVAL_STR_COPY(&prop$$5, _11$$5);
						} else {
							ZVAL_LONG(&prop$$5, _10$$5);
						}
						ZEPHIR_INIT_NVAR(&val$$5);
						ZVAL_COPY(&val$$5, _8$$5);
						zephir_array_update_multi(&config, &val$$5, SL("zz"), 2, &name, &prop$$5);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_7$$5, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_9$$5, &_7$$5, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_9$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&prop$$5, &_7$$5, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&val$$5, &_7$$5, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_update_multi(&config, &val$$5, SL("zz"), 2, &name, &prop$$5);
						ZEPHIR_CALL_METHOD(NULL, &_7$$5, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&val$$5);
				ZEPHIR_INIT_NVAR(&prop$$5);
			}
			zephir_is_iterable(&properties, 0, "moon/Component/Config/Parser/INIParser.zep", 83);
			if (Z_TYPE_P(&properties) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&properties), _14$$3, _15$$3, _12$$3)
				{
					ZEPHIR_INIT_NVAR(&prop_1$$3);
					if (_15$$3 != NULL) { 
						ZVAL_STR_COPY(&prop_1$$3, _15$$3);
					} else {
						ZVAL_LONG(&prop_1$$3, _14$$3);
					}
					ZEPHIR_INIT_NVAR(&val_1$$3);
					ZVAL_COPY(&val_1$$3, _12$$3);
					zephir_array_update_multi(&config, &val_1$$3, SL("zz"), 2, &name, &prop_1$$3);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &properties, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_13$$3, &properties, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&prop_1$$3, &properties, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&val_1$$3, &properties, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_update_multi(&config, &val_1$$3, SL("zz"), 2, &name, &prop_1$$3);
					ZEPHIR_CALL_METHOD(NULL, &properties, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&val_1$$3);
			ZEPHIR_INIT_NVAR(&prop_1$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &ini, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &ini, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_namespace, &ini, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&properties, &ini, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&namespaceArr$$10);
				zephir_fast_explode_str(&namespaceArr$$10, SL(":"), &_namespace, LONG_MAX);
				zephir_array_fetch_long(&_16$$10, &namespaceArr$$10, 0, PH_NOISY | PH_READONLY, "moon/Component/Config/Parser/INIParser.zep", 63);
				ZEPHIR_INIT_NVAR(&name);
				zephir_fast_trim(&name, &_16$$10, NULL , ZEPHIR_TRIM_BOTH);
				zephir_array_fetch_long(&_17$$10, &namespaceArr$$10, 1, PH_NOISY | PH_READONLY, "moon/Component/Config/Parser/INIParser.zep", 64);
				ZEPHIR_INIT_NVAR(&_extends);
				zephir_fast_trim(&_extends, &_17$$10, NULL , ZEPHIR_TRIM_BOTH);
				if (!(zephir_array_isset(&config, &name))) {
					ZEPHIR_INIT_NVAR(&_18$$11);
					array_init(&_18$$11);
					zephir_array_update_zval(&config, &name, &_18$$11, PH_COPY | PH_SEPARATE);
				}
				if (zephir_array_isset(&ini, &_extends)) {
					zephir_array_fetch(&_19$$12, &ini, &_extends, PH_NOISY | PH_READONLY, "moon/Component/Config/Parser/INIParser.zep", 73);
					zephir_is_iterable(&_19$$12, 0, "moon/Component/Config/Parser/INIParser.zep", 76);
					if (Z_TYPE_P(&_19$$12) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_19$$12), _22$$12, _23$$12, _20$$12)
						{
							ZEPHIR_INIT_NVAR(&prop$$12);
							if (_23$$12 != NULL) { 
								ZVAL_STR_COPY(&prop$$12, _23$$12);
							} else {
								ZVAL_LONG(&prop$$12, _22$$12);
							}
							ZEPHIR_INIT_NVAR(&val$$12);
							ZVAL_COPY(&val$$12, _20$$12);
							zephir_array_update_multi(&config, &val$$12, SL("zz"), 2, &name, &prop$$12);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_19$$12, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_21$$12, &_19$$12, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_21$$12)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&prop$$12, &_19$$12, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&val$$12, &_19$$12, "current", NULL, 0);
							zephir_check_call_status();
								zephir_array_update_multi(&config, &val$$12, SL("zz"), 2, &name, &prop$$12);
							ZEPHIR_CALL_METHOD(NULL, &_19$$12, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&val$$12);
					ZEPHIR_INIT_NVAR(&prop$$12);
				}
				zephir_is_iterable(&properties, 0, "moon/Component/Config/Parser/INIParser.zep", 83);
				if (Z_TYPE_P(&properties) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&properties), _26$$10, _27$$10, _24$$10)
					{
						ZEPHIR_INIT_NVAR(&prop_1$$10);
						if (_27$$10 != NULL) { 
							ZVAL_STR_COPY(&prop_1$$10, _27$$10);
						} else {
							ZVAL_LONG(&prop_1$$10, _26$$10);
						}
						ZEPHIR_INIT_NVAR(&val_1$$10);
						ZVAL_COPY(&val_1$$10, _24$$10);
						zephir_array_update_multi(&config, &val_1$$10, SL("zz"), 2, &name, &prop_1$$10);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &properties, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_25$$10, &properties, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_25$$10)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&prop_1$$10, &properties, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&val_1$$10, &properties, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_update_multi(&config, &val_1$$10, SL("zz"), 2, &name, &prop_1$$10);
						ZEPHIR_CALL_METHOD(NULL, &properties, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&val_1$$10);
				ZEPHIR_INIT_NVAR(&prop_1$$10);
			ZEPHIR_CALL_METHOD(NULL, &ini, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&properties);
	ZEPHIR_INIT_NVAR(&_namespace);
	RETURN_CCTOR(&config);

}

