
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"


/**
 * FileName: ParserFactory.php
 * User: solely
 * DateTime: 2019/10/6 18:12
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Config_Parser_ParserFactory) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Config\\Parser, ParserFactory, moon, component_config_parser_parserfactory, moon_component_config_parser_parserfactory_method_entry, 0);

	zend_declare_property_null(moon_component_config_parser_parserfactory_ce, SL("parserClass"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Config_Parser_ParserFactory, parseFile) {

	zend_class_entry *_20$$3, *_35$$6;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_11 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *files, files_sub, parserClass, ext, file, config, *_1, _2, _3$$3, _4$$3, _5$$3, _12$$3, _17$$3, _18$$3, _19$$3, _21$$3, _7$$4, _9$$4, _10$$4, _14$$5, _15$$5, _16$$5, _22$$6, _23$$6, _24$$6, _28$$6, _32$$6, _33$$6, _34$$6, _36$$6, _25$$7, _26$$7, _27$$7, _29$$8, _30$$8, _31$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files_sub);
	ZVAL_UNDEF(&parserClass);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_32$$6);
	ZVAL_UNDEF(&_33$$6);
	ZVAL_UNDEF(&_34$$6);
	ZVAL_UNDEF(&_36$$6);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &files);



	ZEPHIR_INIT_VAR(&config);
	array_init(&config);
	zephir_get_arrval(&_0, files);
	zephir_is_iterable(&_0, 0, "moon/Component/Config/Parser/ParserFactory.zep", 33);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _1);
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_fast_trim(&_3$$3, &file, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_CPY_WRT(&file, &_3$$3);
			ZVAL_LONG(&_4$$3, 4);
			ZEPHIR_CALL_FUNCTION(&_5$$3, "pathinfo", &_6, 48, &file, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&ext);
			zephir_fast_strtolower(&ext, &_5$$3);
			zephir_read_static_property_ce(&_4$$3, moon_component_config_parser_parserfactory_ce, SL("parserClass"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset(&_4$$3, &ext))) {
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZVAL_STRING(&_9$$4, "Does not support parsing of %s extension files");
				ZEPHIR_CALL_FUNCTION(&_10$$4, "sprintf", &_11, 3, &_9$$4, &ext);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&_7$$4, moon_component_config_exception_ce, "parserexception", &_8, 0, &_10$$4);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$4, "moon/Component/Config/Parser/ParserFactory.zep", 25);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(&_12$$3, "is_file", &_13, 49, &file);
			zephir_check_call_status();
			if (!zephir_is_true(&_12$$3)) {
				ZEPHIR_INIT_NVAR(&_15$$5);
				ZVAL_STRING(&_15$$5, "File %s was not found");
				ZEPHIR_CALL_FUNCTION(&_16$$5, "sprintf", &_11, 3, &_15$$5, &file);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&_14$$5, moon_component_config_exception_ce, "parserexception", &_8, 0, &_16$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$5, "moon/Component/Config/Parser/ParserFactory.zep", 28);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_static_property_ce(&_17$$3, moon_component_config_parser_parserfactory_ce, SL("parserClass"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_18$$3, &_17$$3, &ext, PH_NOISY | PH_READONLY, "moon/Component/Config/Parser/ParserFactory.zep", 30);
			ZEPHIR_CPY_WRT(&parserClass, &_18$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			_20$$3 = zephir_fetch_class(&parserClass);
			ZEPHIR_CALL_CE_STATIC(&_19$$3, _20$$3, "getinstance", NULL, 0, &parserClass);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$3, &_19$$3, "parsefile", NULL, 0, &file);
			zephir_check_call_status();
			zephir_fast_array_merge(&_3$$3, &config, &_21$$3);
			ZEPHIR_CPY_WRT(&config, &_3$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$6);
				zephir_fast_trim(&_22$$6, &file, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CPY_WRT(&file, &_22$$6);
				ZVAL_LONG(&_23$$6, 4);
				ZEPHIR_CALL_FUNCTION(&_24$$6, "pathinfo", &_6, 48, &file, &_23$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&ext);
				zephir_fast_strtolower(&ext, &_24$$6);
				zephir_read_static_property_ce(&_23$$6, moon_component_config_parser_parserfactory_ce, SL("parserClass"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset(&_23$$6, &ext))) {
					ZEPHIR_INIT_NVAR(&_26$$7);
					ZVAL_STRING(&_26$$7, "Does not support parsing of %s extension files");
					ZEPHIR_CALL_FUNCTION(&_27$$7, "sprintf", &_11, 3, &_26$$7, &ext);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_25$$7, moon_component_config_exception_ce, "parserexception", &_8, 0, &_27$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_25$$7, "moon/Component/Config/Parser/ParserFactory.zep", 25);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_FUNCTION(&_28$$6, "is_file", &_13, 49, &file);
				zephir_check_call_status();
				if (!zephir_is_true(&_28$$6)) {
					ZEPHIR_INIT_NVAR(&_30$$8);
					ZVAL_STRING(&_30$$8, "File %s was not found");
					ZEPHIR_CALL_FUNCTION(&_31$$8, "sprintf", &_11, 3, &_30$$8, &file);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_29$$8, moon_component_config_exception_ce, "parserexception", &_8, 0, &_31$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_29$$8, "moon/Component/Config/Parser/ParserFactory.zep", 28);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_static_property_ce(&_32$$6, moon_component_config_parser_parserfactory_ce, SL("parserClass"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_33$$6, &_32$$6, &ext, PH_NOISY | PH_READONLY, "moon/Component/Config/Parser/ParserFactory.zep", 30);
				ZEPHIR_CPY_WRT(&parserClass, &_33$$6);
				ZEPHIR_INIT_NVAR(&_22$$6);
				_35$$6 = zephir_fetch_class(&parserClass);
				ZEPHIR_CALL_CE_STATIC(&_34$$6, _35$$6, "getinstance", NULL, 0, &parserClass);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_36$$6, &_34$$6, "parsefile", NULL, 0, &file);
				zephir_check_call_status();
				zephir_fast_array_merge(&_22$$6, &config, &_36$$6);
				ZEPHIR_CPY_WRT(&config, &_22$$6);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	RETURN_CCTOR(&config);

}

PHP_METHOD(Moon_Component_Config_Parser_ParserFactory, parseString) {

	zend_class_entry *_14$$3, *_24$$5;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *configStringArr_param = NULL, parserClass, key, config, item, *_0, _1, _4$$3, _5$$3, _11$$3, _12$$3, _13$$3, _15$$3, _6$$4, _8$$4, _9$$4, _16$$5, _17$$5, _21$$5, _22$$5, _23$$5, _25$$5, _18$$6, _19$$6, _20$$6;
	zval configStringArr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configStringArr);
	ZVAL_UNDEF(&parserClass);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configStringArr_param);

	zephir_get_arrval(&configStringArr, configStringArr_param);


	ZEPHIR_INIT_VAR(&config);
	array_init(&config);
	zephir_is_iterable(&configStringArr, 0, "moon/Component/Config/Parser/ParserFactory.zep", 52);
	if (Z_TYPE_P(&configStringArr) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&configStringArr), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_fast_trim(&_4$$3, &key, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_CPY_WRT(&key, &_4$$3);
			zephir_read_static_property_ce(&_5$$3, moon_component_config_parser_parserfactory_ce, SL("parserClass"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset(&_5$$3, &key))) {
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZVAL_STRING(&_8$$4, "Does not support parsing of %s extension string");
				ZEPHIR_CALL_FUNCTION(&_9$$4, "sprintf", &_10, 3, &_8$$4, &key);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&_6$$4, moon_component_config_exception_ce, "parserexception", &_7, 0, &_9$$4);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$4, "moon/Component/Config/Parser/ParserFactory.zep", 47);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_static_property_ce(&_11$$3, moon_component_config_parser_parserfactory_ce, SL("parserClass"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_12$$3, &_11$$3, &key, PH_NOISY | PH_READONLY, "moon/Component/Config/Parser/ParserFactory.zep", 49);
			ZEPHIR_CPY_WRT(&parserClass, &_12$$3);
			ZEPHIR_INIT_NVAR(&_4$$3);
			_14$$3 = zephir_fetch_class(&parserClass);
			ZEPHIR_CALL_CE_STATIC(&_13$$3, _14$$3, "getinstance", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_15$$3, &_13$$3, "parsestring", NULL, 0, &item);
			zephir_check_call_status();
			zephir_fast_array_merge(&_4$$3, &config, &_15$$3);
			ZEPHIR_CPY_WRT(&config, &_4$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &configStringArr, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &configStringArr, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &configStringArr, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&item, &configStringArr, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$5);
				zephir_fast_trim(&_16$$5, &key, NULL , ZEPHIR_TRIM_BOTH);
				ZEPHIR_CPY_WRT(&key, &_16$$5);
				zephir_read_static_property_ce(&_17$$5, moon_component_config_parser_parserfactory_ce, SL("parserClass"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset(&_17$$5, &key))) {
					ZEPHIR_INIT_NVAR(&_19$$6);
					ZVAL_STRING(&_19$$6, "Does not support parsing of %s extension string");
					ZEPHIR_CALL_FUNCTION(&_20$$6, "sprintf", &_10, 3, &_19$$6, &key);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_18$$6, moon_component_config_exception_ce, "parserexception", &_7, 0, &_20$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_18$$6, "moon/Component/Config/Parser/ParserFactory.zep", 47);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_static_property_ce(&_21$$5, moon_component_config_parser_parserfactory_ce, SL("parserClass"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_22$$5, &_21$$5, &key, PH_NOISY | PH_READONLY, "moon/Component/Config/Parser/ParserFactory.zep", 49);
				ZEPHIR_CPY_WRT(&parserClass, &_22$$5);
				ZEPHIR_INIT_NVAR(&_16$$5);
				_24$$5 = zephir_fetch_class(&parserClass);
				ZEPHIR_CALL_CE_STATIC(&_23$$5, _24$$5, "getinstance", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_25$$5, &_23$$5, "parsestring", NULL, 0, &item);
				zephir_check_call_status();
				zephir_fast_array_merge(&_16$$5, &config, &_25$$5);
				ZEPHIR_CPY_WRT(&config, &_16$$5);
			ZEPHIR_CALL_METHOD(NULL, &configStringArr, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&config);

}

PHP_METHOD(Moon_Component_Config_Parser_ParserFactory, getParserClass) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, moon_component_config_parser_parserfactory_ce, SL("parserClass"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

PHP_METHOD(Moon_Component_Config_Parser_ParserFactory, setParserClass) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pc_param = NULL, parserClassArr, key, item, *_0, _1, _18, _19, _4$$5, _6$$5, _7$$5, _8$$5, _10$$3, _11$$3, _12$$8, _13$$8, _14$$8, _15$$8, _16$$6, _17$$6;
	zval pc;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pc);
	ZVAL_UNDEF(&parserClassArr);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pc_param);

	zephir_get_arrval(&pc, pc_param);


	ZEPHIR_INIT_VAR(&parserClassArr);
	array_init(&parserClassArr);
	zephir_is_iterable(&pc, 0, "moon/Component/Config/Parser/ParserFactory.zep", 75);
	if (Z_TYPE_P(&pc) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&pc), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			if (!(Z_TYPE_P(&key) == IS_STRING)) {
				continue;
			}
			if (!((zephir_instance_of_ev(&item, moon_component_config_parser_abstractparser_ce)))) {
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZVAL_STRING(&_6$$5, "Class %s must inherit from Class %s");
				ZEPHIR_INIT_NVAR(&_7$$5);
				ZVAL_STRING(&_7$$5, "Moon\\Component\\Config\\Parser\\AbstractParser");
				ZEPHIR_CALL_FUNCTION(&_8$$5, "sprintf", &_9, 3, &_6$$5, &item, &_7$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&_4$$5, moon_component_config_exception_ce, "parserexception", &_5, 0, &_8$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$5, "moon/Component/Config/Parser/ParserFactory.zep", 71);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_10$$3);
			ZEPHIR_INIT_NVAR(&_11$$3);
			zephir_fast_trim(&_11$$3, &key, NULL , ZEPHIR_TRIM_BOTH);
			zephir_fast_strtolower(&_10$$3, &_11$$3);
			zephir_array_update_zval(&parserClassArr, &_10$$3, &item, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &pc, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &pc, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &pc, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&item, &pc, "current", NULL, 0);
			zephir_check_call_status();
				if (!(Z_TYPE_P(&key) == IS_STRING)) {
					continue;
				}
				if (!((zephir_instance_of_ev(&item, moon_component_config_parser_abstractparser_ce)))) {
					ZEPHIR_INIT_NVAR(&_13$$8);
					ZVAL_STRING(&_13$$8, "Class %s must inherit from Class %s");
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZVAL_STRING(&_14$$8, "Moon\\Component\\Config\\Parser\\AbstractParser");
					ZEPHIR_CALL_FUNCTION(&_15$$8, "sprintf", &_9, 3, &_13$$8, &item, &_14$$8);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_12$$8, moon_component_config_exception_ce, "parserexception", &_5, 0, &_15$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$8, "moon/Component/Config/Parser/ParserFactory.zep", 71);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZEPHIR_INIT_NVAR(&_17$$6);
				zephir_fast_trim(&_17$$6, &key, NULL , ZEPHIR_TRIM_BOTH);
				zephir_fast_strtolower(&_16$$6, &_17$$6);
				zephir_array_update_zval(&parserClassArr, &_16$$6, &item, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &pc, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	zephir_read_static_property_ce(&_18, moon_component_config_parser_parserfactory_ce, SL("parserClass"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_19, &_18, "merge", NULL, 0, &parserClassArr);
	zephir_check_call_status();
	zephir_update_static_property_ce(moon_component_config_parser_parserfactory_ce, ZEND_STRL("parserClass"), &_19);
	ZEPHIR_MM_RESTORE();

}

void zephir_init_static_properties_Moon_Component_Config_Parser_ParserFactory(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	add_assoc_stringl_ex(&_0, SL("ini"), SL("\\Moon\\Component\\Config\\Parser\\INIParser"));
	add_assoc_stringl_ex(&_0, SL("php"), SL("\\Moon\\Component\\Config\\Parser\\PHPParser"));
	add_assoc_stringl_ex(&_0, SL("yaml"), SL("\\Moon\\Component\\Config\\Parser\\Yaml"));
	add_assoc_stringl_ex(&_0, SL("yml"), SL("\\Moon\\Component\\Config\\Parser\\Yaml"));
	zephir_update_static_property_ce(moon_component_config_parser_parserfactory_ce, ZEND_STRL("parserClass"), &_0);
	ZEPHIR_MM_RESTORE();

}

