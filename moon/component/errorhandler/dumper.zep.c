
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "Zend/zend_closures.h"


/**
 * FileName: Dumper.php
 * User: solely
 * DateTime: 2020/4/6 16:44
 * Description: Dumps a variable.
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Dumper) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\ErrorHandler, Dumper, moon, component_errorhandler_dumper, moon_component_errorhandler_dumper_method_entry, 0);

	/** @var array */
	zend_declare_property_null(moon_component_errorhandler_dumper_ce, SL("liveSnapshot"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	/** @var array */
	zend_declare_property_null(moon_component_errorhandler_dumper_ce, SL("terminalColors"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	/** @var array */
	zend_declare_property_null(moon_component_errorhandler_dumper_ce, SL("resources"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	/** @var array */
	zend_declare_property_null(moon_component_errorhandler_dumper_ce, SL("objectExporters"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	/** @var int|null */
	zend_declare_property_long(moon_component_errorhandler_dumper_ce, SL("maxDepth"), 4, ZEND_ACC_PRIVATE);

	/** @var int|null */
	zend_declare_property_long(moon_component_errorhandler_dumper_ce, SL("maxLength"), 150, ZEND_ACC_PRIVATE);

	/** @var int|bool */
	zend_declare_property_long(moon_component_errorhandler_dumper_ce, SL("collapseTop"), 14, ZEND_ACC_PRIVATE);

	/** @var int */
	zend_declare_property_long(moon_component_errorhandler_dumper_ce, SL("collapseSub"), 7, ZEND_ACC_PRIVATE);

	/** @var int */
	zend_declare_property_long(moon_component_errorhandler_dumper_ce, SL("location"), 0, ZEND_ACC_PRIVATE);

	/** @var bool|null  lazy-loading via JavaScript? true=full, false=none, null=collapsed parts */
	zend_declare_property_null(moon_component_errorhandler_dumper_ce, SL("lazy"), ZEND_ACC_PRIVATE);

	/** @var array|null */
	zend_declare_property_null(moon_component_errorhandler_dumper_ce, SL("snapshot"), ZEND_ACC_PRIVATE);

	/** @var bool */
	zend_declare_property_bool(moon_component_errorhandler_dumper_ce, SL("debugInfo"), 0, ZEND_ACC_PRIVATE);

	/** @var array */
	zend_declare_property_null(moon_component_errorhandler_dumper_ce, SL("keysToHide"), ZEND_ACC_PRIVATE);

	/** @var callable[] */
	zend_declare_property_null(moon_component_errorhandler_dumper_ce, SL("resourceDumpers"), ZEND_ACC_PRIVATE);

	/** @var callable[] */
	zend_declare_property_null(moon_component_errorhandler_dumper_ce, SL("objectDumpers"), ZEND_ACC_PRIVATE);

	moon_component_errorhandler_dumper_ce->create_object = zephir_init_properties_Moon_Component_ErrorHandler_Dumper;
	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("DEPTH"), "depth");

	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("TRUNCATE"), "truncate");

	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("COLLAPSE"), "collapse");

	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("COLLAPSE_COUNT"), "collapsecount");

	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("LOCATION"), "location");

	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("OBJECT_EXPORTERS"), "exporters");

	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("LAZY"), "lazy");

	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("LIVE"), "live");

	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("SNAPSHOT"), "snapshot");

	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("DEBUGINFO"), "debuginfo");

	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("KEYS_TO_HIDE"), "keystohide");

	zephir_declare_class_constant_long(moon_component_errorhandler_dumper_ce, SL("LOCATION_SOURCE"), 1);

	zephir_declare_class_constant_long(moon_component_errorhandler_dumper_ce, SL("LOCATION_LINK"), 2);

	zephir_declare_class_constant_long(moon_component_errorhandler_dumper_ce, SL("LOCATION_CLASS"), 4);

	zephir_declare_class_constant_string(moon_component_errorhandler_dumper_ce, SL("HIDDEN_VALUE"), "*****");

	return SUCCESS;

}

/**
 * Dumps variable to the output.
 * @param $var
 * @param array $options
 * @return mixed  variable
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dump) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *_var, _var_sub, *options_param = NULL, _0, _2, _3, _4, _5, _6, _7, _8, _10$$3, _11$$4, _12$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &_var, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_SAPI");
	_1 = !ZEPHIR_IS_STRING_IDENTICAL(&_0, "cli");
	if (_1) {
		ZEPHIR_INIT_VAR(&_2);
		ZEPHIR_INIT_VAR(&_3);
		ZEPHIR_CALL_FUNCTION(&_4, "headers_list", NULL, 100);
		zephir_check_call_status();
		zephir_fast_join_str(&_3, SL("\n"), &_4);
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "#^Content-Type: (?!text/html)#im");
		ZEPHIR_INIT_VAR(&_6);
		ZEPHIR_INIT_VAR(&_7);
		ZVAL_STRING(&_7, "#^Content-Type: (?!text/html)#im");
		zephir_preg_match(&_6, &_7, &_3, &_2, 0, 0 , 0 );
		_1 = !zephir_is_true(&_6);
	}
	ZEPHIR_CALL_SELF(&_8, "detectcolors", &_9, 101);
	zephir_check_call_status();
	if (_1) {
		ZEPHIR_CALL_SELF(&_10$$3, "tohtml", NULL, 0, _var, &options);
		zephir_check_call_status();
		zend_print_zval(&_10$$3, 0);
	} else if (zephir_is_true(&_8)) {
		ZEPHIR_CALL_SELF(&_11$$4, "toterminal", NULL, 0, _var, &options);
		zephir_check_call_status();
		zend_print_zval(&_11$$4, 0);
	} else {
		ZEPHIR_CALL_SELF(&_12$$5, "totext", NULL, 0, _var, &options);
		zephir_check_call_status();
		zend_print_zval(&_12$$5, 0);
	}
	RETVAL_ZVAL(_var, 1, 0);
	RETURN_MM();

}

/**
 * Dumps variable to HTML.
 * @param $var
 * @param array $options
 * @return string
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, toHtml) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *_var, _var_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &_var, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_errorhandler_dumper_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 102, &options);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "ashtml", NULL, 103, _var);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Dumps variable to plain text.
 * @param $var
 * @param array $options
 * @return string
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, toText) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *_var, _var_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &_var, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_errorhandler_dumper_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 102, &options);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "asterminal", NULL, 104, _var);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Dumps variable to x-terminal.
 * @param $var
 * @param array $options
 * @return string
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, toTerminal) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *_var, _var_sub, *options_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &_var, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_errorhandler_dumper_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 102, &options);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_1, moon_component_errorhandler_dumper_ce, SL("terminalColors"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "asterminal", NULL, 104, _var, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, live, _0, _1, _2, _3, _4, _5, _6, _7, _8, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _9$$4;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&live);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_array_isset_string(&options, SL("depth"))) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch_string(&_0, &options, SL("depth"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 113);
	} else {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property(&_0, this_ptr, ZEND_STRL("maxDepth"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("maxDepth"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_array_isset_string(&options, SL("truncate"))) {
		ZEPHIR_OBS_NVAR(&_1);
		zephir_array_fetch_string(&_1, &options, SL("truncate"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 114);
	} else {
		ZEPHIR_OBS_NVAR(&_1);
		zephir_read_property(&_1, this_ptr, ZEND_STRL("maxLength"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("maxLength"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	if (zephir_array_isset_string(&options, SL("collapse"))) {
		ZEPHIR_OBS_NVAR(&_2);
		zephir_array_fetch_string(&_2, &options, SL("collapse"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 115);
	} else {
		ZEPHIR_OBS_NVAR(&_2);
		zephir_read_property(&_2, this_ptr, ZEND_STRL("collapseTop"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("collapseTop"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	if (zephir_array_isset_string(&options, SL("collapsecount"))) {
		ZEPHIR_OBS_NVAR(&_3);
		zephir_array_fetch_string(&_3, &options, SL("collapsecount"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 116);
	} else {
		ZEPHIR_OBS_NVAR(&_3);
		zephir_read_property(&_3, this_ptr, ZEND_STRL("collapseSub"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("collapseSub"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	if (zephir_array_isset_string(&options, SL("location"))) {
		ZEPHIR_OBS_NVAR(&_4);
		zephir_array_fetch_string(&_4, &options, SL("location"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 117);
	} else {
		ZEPHIR_OBS_NVAR(&_4);
		zephir_read_property(&_4, this_ptr, ZEND_STRL("location"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("location"), &_4);
	ZEPHIR_INIT_VAR(&_5);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("location"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_6)) {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_LONG(&_5, ~(0));
	} else {
		ZEPHIR_OBS_VAR(&_7);
		zephir_read_property(&_7, this_ptr, ZEND_STRL("location"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_LONG(&_5, zephir_get_intval(&_7));
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("location"), &_5);
	zephir_array_fetch_string(&_8, &options, SL("snapshot"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 119);
	zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &_8);
	ZEPHIR_INIT_VAR(&live);
	ZVAL_BOOL(&live, 0);
	if (zephir_array_isset_string(&options, SL("live"))) {
		ZEPHIR_OBS_NVAR(&live);
		zephir_array_fetch_string(&live, &options, SL("live"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 122);
	}
	if (zephir_is_true(&live)) {
		ZEPHIR_OBS_VAR(&_9$$4);
		zephir_read_static_property_ce(&_9$$4, moon_component_errorhandler_dumper_ce, SL("liveSnapshot"), PH_NOISY_CC);
		zephir_update_property_zval(this_ptr, ZEND_STRL("snapshot"), &_9$$4);
	}
	ZEPHIR_INIT_VAR(&_10);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_11) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&_10);
		ZVAL_BOOL(&_10, 1);
	} else {
		if (zephir_array_isset_string(&options, SL("lazy"))) {
			ZEPHIR_OBS_NVAR(&_10);
			zephir_array_fetch_string(&_10, &options, SL("lazy"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 127);
		} else {
			ZEPHIR_OBS_NVAR(&_10);
			zephir_read_property(&_10, this_ptr, ZEND_STRL("lazy"), PH_NOISY_CC);
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("lazy"), &_10);
	ZEPHIR_INIT_VAR(&_12);
	if (zephir_array_isset_string(&options, SL("debuginfo"))) {
		ZEPHIR_OBS_NVAR(&_12);
		zephir_array_fetch_string(&_12, &options, SL("debuginfo"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 128);
	} else {
		ZEPHIR_OBS_NVAR(&_12);
		zephir_read_property(&_12, this_ptr, ZEND_STRL("debugInfo"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("debugInfo"), &_12);
	ZEPHIR_INIT_VAR(&_13);
	if (zephir_array_isset_string(&options, SL("keystohide"))) {
		ZEPHIR_OBS_NVAR(&_13);
		zephir_array_fetch_string(&_13, &options, SL("keystohide"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 129);
	} else {
		ZEPHIR_INIT_NVAR(&_13);
		array_init(&_13);
	}
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "strtolower");
	ZEPHIR_CALL_FUNCTION(&_15, "array_map", NULL, 83, &_14, &_13);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_16, "array_flip", NULL, 65, &_15);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("keysToHide"), &_16);
	ZEPHIR_INIT_VAR(&_17);
	if (zephir_array_isset_string(&options, SL("resourceExporters"))) {
		ZEPHIR_OBS_NVAR(&_17);
		zephir_array_fetch_string(&_17, &options, SL("resourceExporters"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 130);
	} else {
		ZEPHIR_INIT_NVAR(&_17);
		array_init(&_17);
	}
	zephir_read_static_property_ce(&_18, moon_component_errorhandler_dumper_ce, SL("resources"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_19);
	zephir_add_function(&_19, &_17, &_18);
	zephir_update_property_zval(this_ptr, ZEND_STRL("resourceDumpers"), &_19);
	ZEPHIR_INIT_NVAR(&_17);
	if (zephir_array_isset_string(&options, SL("exporters"))) {
		ZEPHIR_OBS_NVAR(&_17);
		zephir_array_fetch_string(&_17, &options, SL("exporters"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 131);
	} else {
		ZEPHIR_INIT_NVAR(&_17);
		array_init(&_17);
	}
	zephir_read_static_property_ce(&_18, moon_component_errorhandler_dumper_ce, SL("objectExporters"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_20);
	zephir_add_function(&_20, &_17, &_18);
	zephir_update_property_zval(this_ptr, ZEND_STRL("objectDumpers"), &_20);
	zephir_read_property(&_18, this_ptr, ZEND_STRL("objectDumpers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_14);
	ZEPHIR_INIT_NVAR(&_14);
	zephir_create_closure_ex(&_14, NULL, moon_1__closure_ce, SL("__invoke"));
	ZEPHIR_MAKE_REF(&_18);
	ZEPHIR_CALL_FUNCTION(NULL, "uksort", NULL, 105, &_18, &_14);
	ZEPHIR_UNREF(&_18);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Dumps variable to HTML.
 * @param $var
 * @return string
 * @throws \ReflectionException
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, asHtml) {

	zval _13$$5, _15$$6;
	zend_bool _1, _9, _10, _11, _12, _18, _21, _27;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_var, _var_sub, snapshot, json, html, locAttrs, file, line, code, locationArr, options, _0, _2, _4, _5, _6, _8, _17, _19, _20, _22, _23, _24, _25, _26, _28, _7$$4, _14$$6, _16$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&json);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&locAttrs);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&locationArr);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_var);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("location"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&locationArr, this_ptr, "findlocation", NULL, 106);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&file);
		zephir_array_fetch_long(&file, &locationArr, 0, PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 157);
		ZEPHIR_OBS_VAR(&line);
		zephir_array_fetch_long(&line, &locationArr, 1, PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 158);
		ZEPHIR_OBS_VAR(&code);
		zephir_array_fetch_long(&code, &locationArr, 2, PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 159);
	}
	_1 = zephir_is_true(&file);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("location"), PH_NOISY_CC | PH_READONLY);
		_1 = ((((int) (zephir_get_numberval(&_2)) & 1)) ? 1 : 0);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_4);
		ZEPHIR_CONCAT_VS(&_4, &code, "\n");
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, " title=\"%in file % on line %\" ");
		ZEPHIR_CALL_CE_STATIC(&locAttrs, moon_component_errorhandler_helpers_ce, "formathtml", &_3, 0, &_5, &_4, &file, &line);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&locAttrs);
		ZVAL_NULL(&locAttrs);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_6) == IS_ARRAY) {
		zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&options, SL("snapshot"), &_7$$4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&snapshot);
	zephir_array_fetch_string(&snapshot, &options, SL("snapshot"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 171);
	ZEPHIR_INIT_VAR(&html);
	ZVAL_NULL(&html);
	ZEPHIR_INIT_VAR(&json);
	ZVAL_NULL(&json);
	zephir_read_property(&_8, this_ptr, ZEND_STRL("lazy"), PH_NOISY_CC | PH_READONLY);
	_9 = zephir_is_true(&_8);
	if (_9) {
		_10 = Z_TYPE_P(_var) == IS_ARRAY;
		if (!(_10)) {
			_10 = Z_TYPE_P(_var) == IS_OBJECT;
		}
		_11 = _10;
		if (!(_11)) {
			_11 = Z_TYPE_P(_var) == IS_RESOURCE;
		}
		_9 = _11;
	}
	_12 = _9;
	if (_12) {
		_12 = zephir_is_true(_var);
	}
	if (_12) {
		ZEPHIR_CALL_METHOD(&json, this_ptr, "tojson", NULL, 107, _var, &options);
		zephir_check_call_status();
		zephir_get_arrval(&_13$$5, &snapshot);
		ZEPHIR_CPY_WRT(&snapshot, &_13$$5);
	} else {
		ZEPHIR_INIT_VAR(&_14$$6);
		ZEPHIR_INIT_VAR(&_15$$6);
		zephir_create_array(&_15$$6, 1, 0);
		ZEPHIR_OBS_VAR(&_16$$6);
		zephir_read_property(&_16$$6, this_ptr, ZEND_STRL("lazy"), PH_NOISY_CC);
		zephir_array_update_string(&_15$$6, SL("lazy"), &_16$$6, PH_COPY | PH_SEPARATE);
		zephir_fast_array_merge(&_14$$6, &_15$$6, &options);
		ZEPHIR_CALL_METHOD(&html, this_ptr, "dumpvar", NULL, 108, _var, &_14$$6);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_17);
	_18 = zephir_is_true(&json);
	if (_18) {
		zephir_read_property(&_19, this_ptr, ZEND_STRL("collapseTop"), PH_NOISY_CC | PH_READONLY);
		_18 = ZEPHIR_IS_TRUE_IDENTICAL(&_19);
	}
	if (_18) {
		ZEPHIR_INIT_NVAR(&_17);
		ZVAL_STRING(&_17, " moon-collapsed");
	} else {
		ZEPHIR_INIT_NVAR(&_17);
		ZVAL_STRING(&_17, "");
	}
	ZEPHIR_INIT_VAR(&_20);
	_21 = Z_TYPE_P(&snapshot) == IS_ARRAY;
	if (_21) {
		zephir_read_property(&_22, this_ptr, ZEND_STRL("snapshot"), PH_NOISY_CC | PH_READONLY);
		_21 = !(Z_TYPE_P(&_22) == IS_ARRAY);
	}
	if (_21) {
		ZEPHIR_CALL_METHOD(&_23, this_ptr, "formatsnapshotattribute", NULL, 0, &snapshot);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_20);
		ZEPHIR_CONCAT_SV(&_20, " data-moon-snapshot=", &_23);
	} else {
		ZEPHIR_INIT_NVAR(&_20);
		ZVAL_STRING(&_20, "");
	}
	ZEPHIR_INIT_VAR(&_24);
	if (zephir_is_true(&json)) {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_LONG(&_25, (4 | 2));
		zephir_json_encode(&_5, &json, zephir_get_intval(&_25) );
		ZEPHIR_INIT_NVAR(&_24);
		ZEPHIR_CONCAT_SVS(&_24, " data-moon-dump='", &_5, "'>");
	} else {
		ZEPHIR_INIT_NVAR(&_24);
		ZVAL_STRING(&_24, ">");
	}
	ZEPHIR_INIT_VAR(&_26);
	_27 = zephir_is_true(&file);
	if (_27) {
		zephir_read_property(&_28, this_ptr, ZEND_STRL("location"), PH_NOISY_CC | PH_READONLY);
		_27 = ((((int) (zephir_get_numberval(&_28)) & 2)) ? 1 : 0);
	}
	if (_27) {
		ZEPHIR_INIT_NVAR(&_26);
		ZEPHIR_CONCAT_SVSVS(&_26, "<small>in ", &file, ":", &line, "</small>");
	} else {
		ZEPHIR_INIT_NVAR(&_26);
		ZVAL_STRING(&_26, "");
	}
	ZEPHIR_CONCAT_SVSVVVVVS(return_value, "<pre class=\"moon-dump", &_17, "\"", &locAttrs, &_20, &_24, &html, &_26, "</pre>\n");
	RETURN_MM();

}

/**
 * Dumps variable to x-terminal.
 * @param $var
 * @param array $colors
 * @return string
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, asTerminal) {

	zend_bool _6, _7;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_var, _var_sub, colors, *colors_param = NULL, __$false, s, file, line, locationArr, _4, _5, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&colors);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&locationArr);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &_var, &colors_param);

	if (!colors_param) {
		ZEPHIR_INIT_VAR(&colors);
		array_init(&colors);
	} else {
		zephir_get_arrval(&colors, colors_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	zephir_array_update_string(&_0, SL("lazy"), &__$false, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&s, this_ptr, "dumpvar", NULL, 108, _var, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&colors)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		zephir_create_closure_ex(&_1$$3, NULL, moon_2__closure_ce, SL("__invoke"));
		zephir_update_static_property_ce(moon_2__closure_ce, ZEND_STRL("colors"), &colors);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#<span class=\"moon-dump-(\\w+)\">|</span>#");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "preg_replace_callback", NULL, 109, &_2$$3, &_1$$3, &s);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&s, &_3$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_4, "strip_tags", NULL, 110, &s);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 3);
	ZEPHIR_CALL_FUNCTION(&s, "htmlspecialchars_decode", NULL, 111, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&locationArr, this_ptr, "findlocation", NULL, 106);
	zephir_check_call_status();
	if (zephir_is_true(&locationArr)) {
		zephir_array_fetch_long(&file, &locationArr, 0, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 206);
		zephir_array_fetch_long(&line, &locationArr, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 207);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("location"), PH_NOISY_CC | PH_READONLY);
	_6 = ((((int) (zephir_get_numberval(&_5)) & 2)) ? 1 : 0);
	if (_6) {
		_6 = zephir_is_true(&file);
	}
	_7 = _6;
	if (_7) {
		_7 = zephir_is_true(&line);
	}
	if (_7) {
		zephir_concat_self_str(&s, SL("in {file}:{line}"));
	}
	RETURN_CCTOR(&s);

}

/**
 *  Internal toHtml() dump implementation.
 * @param $var
 * @param array $options
 * @param int $level
 * @return string
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpVar) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *_var, _var_sub, *options_param = NULL, *level_param = NULL, m, _0, _1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &_var, &options_param, &level_param);

	zephir_get_arrval(&options, options_param);
	if (!level_param) {
		level = 0;
	} else {
		level = zephir_get_intval(level_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_gettype(&_0, _var);
	ZEPHIR_INIT_VAR(&m);
	ZEPHIR_CONCAT_SV(&m, "dump", &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Moon\\Component\\ErrorHandler\\Dumper");
	if ((zephir_method_exists(&_1, &m)  == SUCCESS)) {
		ZVAL_LONG(&_2$$3, level);
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &m, NULL, 0, _var, &options, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		RETURN_MM_STRING("<span>unknown type</span>\n");
	}

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpNull) {

	zval *this_ptr = getThis();


	RETURN_STRING("<span class=\"moon-dump-null\">null</span>\n");

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpBoolean) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *_var, _var_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_var);



	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(_var)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "true");
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "false");
	}
	ZEPHIR_CONCAT_SVS(return_value, "<span class=\"moon-dump-bool\">", &_0, "</span>\n");
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpInteger) {

	zval *_var, _var_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &_var);



	RETURN_STRING("<span class=\"moon-dump-number\">{_var}</span>\n");

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpDouble) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_var = NULL, _var_sub, tmp, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_var);

	ZEPHIR_SEPARATE_PARAM(_var);


	ZEPHIR_CALL_FUNCTION(&_0, "is_finite", NULL, 112, _var);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&tmp);
		zephir_json_encode(&tmp, _var, 0 );
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, ".");
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_fast_strpos(&_2$$3, &tmp, &_1$$3, 0 );
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			ZEPHIR_INIT_NVAR(_var);
			ZEPHIR_CONCAT_VS(_var, &tmp, ".0");
		} else {
			ZEPHIR_CPY_WRT(_var, &tmp);
		}
	}
	RETURN_MM_STRING("<span class=\"moon-dump-number\">{_var}</span>\n");

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpString) {

	zval _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *_var, _var_sub, _0, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_var);



	zephir_read_property(&_3, this_ptr, ZEND_STRL("maxLength"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "encodestring", NULL, 0, _var, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, moon_component_errorhandler_helpers_ce, "escapehtml", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	if (zephir_fast_strlen_ev(_var) > 1) {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_LONG(&_5, zephir_fast_strlen_ev(_var));
		ZEPHIR_INIT_VAR(&_6);
		ZEPHIR_CONCAT_SVS(&_6, " (", &_5, ")");
		ZEPHIR_CPY_WRT(&_4, &_6);
	} else {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_STRING(&_4, "");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "<span class=\"moon-dump-string\">\"", &_0, "\"</span>", &_4, "\n");
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpArray) {

	zend_string *_24$$7;
	zend_ulong _23$$7;
	zval _13$$6;
	zend_bool _3, _10$$5, _25$$8, _42$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_31 = NULL, *_33 = NULL, *_35 = NULL, *_39 = NULL, *_40 = NULL;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *_var, _var_sub, options, *options_param = NULL, *level_param = NULL, __$true, hide, span, collapsed, out, _0, _1, _2, _4, _5$$4, _6$$5, _7$$5, _8$$5, _9$$5, _11$$5, _12$$6, _14$$6, _15$$6, _16$$6, _17$$6, _18$$7, _19$$7, _20$$7, k$$7, v$$7, *_21$$7, _22$$7, _54$$7, _26$$8, _27$$8, _28$$8, _29$$8, _30$$8, _32$$8, _34$$8, _36$$8, _37$$8, _38$$8, _41$$8, _43$$9, _44$$9, _45$$9, _46$$9, _47$$9, _48$$9, _49$$9, _50$$9, _51$$9, _52$$9, _53$$9, _55$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&options);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&hide);
	ZVAL_UNDEF(&span);
	ZVAL_UNDEF(&collapsed);
	ZVAL_UNDEF(&out);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&k$$7);
	ZVAL_UNDEF(&v$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_54$$7);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_34$$8);
	ZVAL_UNDEF(&_36$$8);
	ZVAL_UNDEF(&_37$$8);
	ZVAL_UNDEF(&_38$$8);
	ZVAL_UNDEF(&_41$$8);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_44$$9);
	ZVAL_UNDEF(&_45$$9);
	ZVAL_UNDEF(&_46$$9);
	ZVAL_UNDEF(&_47$$9);
	ZVAL_UNDEF(&_48$$9);
	ZVAL_UNDEF(&_49$$9);
	ZVAL_UNDEF(&_50$$9);
	ZVAL_UNDEF(&_51$$9);
	ZVAL_UNDEF(&_52$$9);
	ZVAL_UNDEF(&_53$$9);
	ZVAL_UNDEF(&_55$$10);
	ZVAL_UNDEF(&_13$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &_var, &options_param, &level_param);

	zephir_get_arrval(&options, options_param);
	level = zephir_get_intval(level_param);


	ZEPHIR_INIT_VAR(&out);
	ZVAL_STRING(&out, "<span class=\"moon-dump-array\">array</span> (");
	ZEPHIR_INIT_VAR(&_0);
	if (zephir_array_isset_string(&options, SL("parents"))) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch_string(&_0, &options, SL("parents"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 279);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		array_init(&_0);
	}
	ZEPHIR_CALL_FUNCTION(&_1, "in_array", NULL, 5, _var, &_0, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("maxDepth"), PH_NOISY_CC | PH_READONLY);
	_3 = !zephir_is_true(&_2);
	if (!(_3)) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("maxDepth"), PH_NOISY_CC | PH_READONLY);
		_3 = ZEPHIR_GT_LONG(&_4, level);
	}
	if (ZEPHIR_IS_EMPTY(_var)) {
		ZEPHIR_CONCAT_VS(return_value, &out, ")\n");
		RETURN_MM();
	} else if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_LONG(&_5$$4, ((zephir_fast_count_int(_var) - 1)));
		ZEPHIR_CONCAT_VVS(return_value, &out, &_5$$4, ") [ <i>RECURSION</i> ]\n");
		RETURN_MM();
	} else if (_3) {
		if (level) {
			zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("collapseSub"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&collapsed);
			ZVAL_BOOL(&collapsed, ZEPHIR_LE_LONG(&_6$$5, zephir_fast_count_int(_var)));
		} else {
			zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("collapseTop"), PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_7$$5) == IS_LONG) {
				zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("collapseTop"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&collapsed);
				ZVAL_BOOL(&collapsed, ZEPHIR_LE_LONG(&_8$$5, zephir_fast_count_int(_var)));
			} else {
				ZEPHIR_OBS_NVAR(&collapsed);
				zephir_read_property(&collapsed, this_ptr, ZEND_STRL("collapseTop"), PH_NOISY_CC);
			}
		}
		ZEPHIR_INIT_VAR(&_9$$5);
		if (zephir_is_true(&collapsed)) {
			ZEPHIR_INIT_NVAR(&_9$$5);
			ZVAL_STRING(&_9$$5, " moon-collapsed");
		} else {
			ZEPHIR_INIT_NVAR(&_9$$5);
			ZVAL_STRING(&_9$$5, "");
		}
		ZEPHIR_INIT_VAR(&span);
		ZEPHIR_CONCAT_SVS(&span, "<span class=\"moon-toggle", &_9$$5, "\"");
		_10$$5 = zephir_is_true(&collapsed);
		if (_10$$5) {
			zephir_array_fetch_string(&_11$$5, &options, SL("lazy"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 284);
			_10$$5 = !ZEPHIR_IS_FALSE_IDENTICAL(&_11$$5);
		}
		if (_10$$5) {
			ZEPHIR_OBS_VAR(&_12$$6);
			zephir_array_fetch_string(&_12$$6, &options, SL("snapshot"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 285);
			zephir_get_arrval(&_13$$6, &_12$$6);
			zephir_array_update_string(&options, SL("snapshot"), &_13$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_14$$6);
			ZVAL_LONG(&_16$$6, level);
			ZEPHIR_CALL_METHOD(&_15$$6, this_ptr, "tojson", NULL, 107, _var, &options, &_16$$6);
			zephir_check_call_status();
			ZVAL_LONG(&_16$$6, (4 | 2));
			zephir_json_encode(&_14$$6, &_15$$6, zephir_get_intval(&_16$$6) );
			ZEPHIR_INIT_VAR(&_17$$6);
			ZVAL_LONG(&_17$$6, zephir_fast_count_int(_var));
			ZEPHIR_CONCAT_VSVSVVS(return_value, &span, " data-moon-dump='", &_14$$6, "'>", &out, &_17$$6, ")</span>\n");
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(&_18$$7);
			ZVAL_LONG(&_18$$7, zephir_fast_count_int(_var));
			ZEPHIR_INIT_VAR(&_19$$7);
			if (zephir_is_true(&collapsed)) {
				ZEPHIR_INIT_NVAR(&_19$$7);
				ZVAL_STRING(&_19$$7, " class=\"moon-collapsed\"");
			} else {
				ZEPHIR_INIT_NVAR(&_19$$7);
				ZVAL_STRING(&_19$$7, "");
			}
			ZEPHIR_INIT_VAR(&_20$$7);
			ZEPHIR_CONCAT_VSVVSSVS(&_20$$7, &span, ">", &out, &_18$$7, ")</span>\n", "<div", &_19$$7, ">");
			ZEPHIR_CPY_WRT(&out, &_20$$7);
			zephir_array_update_multi(&options, _var, SL("sa"), 3, SL("parents"));
			zephir_is_iterable(_var, 0, "moon/Component/ErrorHandler/Dumper.zep", 296);
			if (Z_TYPE_P(_var) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_var), _23$$7, _24$$7, _21$$7)
				{
					ZEPHIR_INIT_NVAR(&k$$7);
					if (_24$$7 != NULL) { 
						ZVAL_STR_COPY(&k$$7, _24$$7);
					} else {
						ZVAL_LONG(&k$$7, _23$$7);
					}
					ZEPHIR_INIT_NVAR(&v$$7);
					ZVAL_COPY(&v$$7, _21$$7);
					_25$$8 = Z_TYPE_P(&k$$7) == IS_STRING;
					if (_25$$8) {
						zephir_read_property(&_26$$8, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_27$$8);
						zephir_fast_strtolower(&_27$$8, &k$$7);
						_25$$8 = zephir_array_isset(&_26$$8, &_27$$8);
					}
					ZEPHIR_INIT_NVAR(&hide);
					ZVAL_BOOL(&hide, _25$$8);
					ZEPHIR_INIT_NVAR(&_28$$8);
					ZVAL_STRING(&_28$$8, "|  ");
					ZVAL_LONG(&_29$$8, level);
					ZEPHIR_CALL_FUNCTION(&_30$$8, "str_repeat", &_31, 113, &_28$$8, &_29$$8);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_34$$8, this_ptr, "encodekey", &_35, 114, &k$$7);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_32$$8, moon_component_errorhandler_helpers_ce, "escapehtml", &_33, 0, &_34$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_36$$8);
					if (zephir_is_true(&hide)) {
						ZEPHIR_CALL_SELF(&_38$$8, "hidevalue", &_39, 115, &v$$7);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_37$$8, moon_component_errorhandler_helpers_ce, "escapehtml", &_33, 0, &_38$$8);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_36$$8);
						ZEPHIR_CONCAT_VS(&_36$$8, &_37$$8, "\n");
					} else {
						ZVAL_LONG(&_29$$8, (level + 1));
						ZEPHIR_CALL_METHOD(&_36$$8, this_ptr, "dumpvar", &_40, 108, &v$$7, &options, &_29$$8);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(&_41$$8);
					ZEPHIR_CONCAT_SVSSVSV(&_41$$8, "<span class=\"moon-dump-indent\">   ", &_30$$8, "</span>", "<span class=\"moon-dump-key\">", &_32$$8, "</span> => ", &_36$$8);
					zephir_concat_self(&out, &_41$$8);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _var, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_22$$7, _var, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_22$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&k$$7, _var, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&v$$7, _var, "current", NULL, 0);
					zephir_check_call_status();
						_42$$9 = Z_TYPE_P(&k$$7) == IS_STRING;
						if (_42$$9) {
							zephir_read_property(&_43$$9, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_NVAR(&_44$$9);
							zephir_fast_strtolower(&_44$$9, &k$$7);
							_42$$9 = zephir_array_isset(&_43$$9, &_44$$9);
						}
						ZEPHIR_INIT_NVAR(&hide);
						ZVAL_BOOL(&hide, _42$$9);
						ZEPHIR_INIT_NVAR(&_45$$9);
						ZVAL_STRING(&_45$$9, "|  ");
						ZVAL_LONG(&_46$$9, level);
						ZEPHIR_CALL_FUNCTION(&_47$$9, "str_repeat", &_31, 113, &_45$$9, &_46$$9);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_49$$9, this_ptr, "encodekey", &_35, 114, &k$$7);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_48$$9, moon_component_errorhandler_helpers_ce, "escapehtml", &_33, 0, &_49$$9);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_50$$9);
						if (zephir_is_true(&hide)) {
							ZEPHIR_CALL_SELF(&_52$$9, "hidevalue", &_39, 115, &v$$7);
							zephir_check_call_status();
							ZEPHIR_CALL_CE_STATIC(&_51$$9, moon_component_errorhandler_helpers_ce, "escapehtml", &_33, 0, &_52$$9);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_50$$9);
							ZEPHIR_CONCAT_VS(&_50$$9, &_51$$9, "\n");
						} else {
							ZVAL_LONG(&_46$$9, (level + 1));
							ZEPHIR_CALL_METHOD(&_50$$9, this_ptr, "dumpvar", &_40, 108, &v$$7, &options, &_46$$9);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_53$$9);
						ZEPHIR_CONCAT_SVSSVSV(&_53$$9, "<span class=\"moon-dump-indent\">   ", &_47$$9, "</span>", "<span class=\"moon-dump-key\">", &_48$$9, "</span> => ", &_50$$9);
						zephir_concat_self(&out, &_53$$9);
					ZEPHIR_CALL_METHOD(NULL, _var, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&v$$7);
			ZEPHIR_INIT_NVAR(&k$$7);
			zephir_array_fetch_string(&_54$$7, &options, SL("parents"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 296);
			ZEPHIR_MAKE_REF(&_54$$7);
			ZEPHIR_CALL_FUNCTION(NULL, "array_pop", NULL, 90, &_54$$7);
			ZEPHIR_UNREF(&_54$$7);
			zephir_check_call_status();
			ZEPHIR_CONCAT_VS(return_value, &out, "</div>");
			RETURN_MM();
		}
	} else {
		ZEPHIR_INIT_VAR(&_55$$10);
		ZVAL_LONG(&_55$$10, zephir_fast_count_int(_var));
		ZEPHIR_CONCAT_VVS(return_value, &out, &_55$$10, ") [ ... ]\n");
		RETURN_MM();
	}

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpObject) {

	zend_string *_34$$8;
	zend_ulong _33$$8;
	zend_bool _17, _19, _24$$6, _35$$9, _43$$9, _59$$11, _66$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL, *_8 = NULL, *_41 = NULL, *_49 = NULL, *_52 = NULL, *_56 = NULL, *_57 = NULL;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *_var, _var_sub, options, *options_param = NULL, *level_param = NULL, __$true, hide, vis, span, collapsed, out, rc, editorAttributes, fields, _0, _5, _7, _9, _10, _11, _12, _13, _14, _15, _16, _18, _2$$3, _3$$3, _4$$3, _20$$6, _21$$6, _22$$6, _23$$6, _25$$6, _26$$7, _27$$7, _28$$7, _29$$8, _30$$8, k$$8, v$$8, *_31$$8, _32$$8, _78$$8, _36$$9, _44$$9, _45$$9, _46$$9, _47$$9, _48$$9, _50$$9, _51$$9, _53$$9, _54$$9, _55$$9, _58$$9, _37$$10, _38$$10, _39$$10, _40$$10, _42$$10, _60$$11, _67$$11, _68$$11, _69$$11, _70$$11, _71$$11, _72$$11, _73$$11, _74$$11, _75$$11, _76$$11, _77$$11, _61$$12, _62$$12, _63$$12, _64$$12, _65$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&options);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&hide);
	ZVAL_UNDEF(&vis);
	ZVAL_UNDEF(&span);
	ZVAL_UNDEF(&collapsed);
	ZVAL_UNDEF(&out);
	ZVAL_UNDEF(&rc);
	ZVAL_UNDEF(&editorAttributes);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&k$$8);
	ZVAL_UNDEF(&v$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_78$$8);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_44$$9);
	ZVAL_UNDEF(&_45$$9);
	ZVAL_UNDEF(&_46$$9);
	ZVAL_UNDEF(&_47$$9);
	ZVAL_UNDEF(&_48$$9);
	ZVAL_UNDEF(&_50$$9);
	ZVAL_UNDEF(&_51$$9);
	ZVAL_UNDEF(&_53$$9);
	ZVAL_UNDEF(&_54$$9);
	ZVAL_UNDEF(&_55$$9);
	ZVAL_UNDEF(&_58$$9);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_38$$10);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_42$$10);
	ZVAL_UNDEF(&_60$$11);
	ZVAL_UNDEF(&_67$$11);
	ZVAL_UNDEF(&_68$$11);
	ZVAL_UNDEF(&_69$$11);
	ZVAL_UNDEF(&_70$$11);
	ZVAL_UNDEF(&_71$$11);
	ZVAL_UNDEF(&_72$$11);
	ZVAL_UNDEF(&_73$$11);
	ZVAL_UNDEF(&_74$$11);
	ZVAL_UNDEF(&_75$$11);
	ZVAL_UNDEF(&_76$$11);
	ZVAL_UNDEF(&_77$$11);
	ZVAL_UNDEF(&_61$$12);
	ZVAL_UNDEF(&_62$$12);
	ZVAL_UNDEF(&_63$$12);
	ZVAL_UNDEF(&_64$$12);
	ZVAL_UNDEF(&_65$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &_var, &options_param, &level_param);

	zephir_get_arrval(&options, options_param);
	level = zephir_get_intval(level_param);


	ZEPHIR_CALL_METHOD(&fields, this_ptr, "exportobject", NULL, 116, _var);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&editorAttributes);
	ZVAL_STRING(&editorAttributes, "");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("location"), PH_NOISY_CC | PH_READONLY);
	if (((int) (zephir_get_numberval(&_0)) & 4)) {
		if (zephir_instance_of_ev(_var, zend_ce_closure)) {
			ZEPHIR_INIT_VAR(&rc);
			object_init_ex(&rc, zephir_get_internal_ce(SL("reflectionfunction")));
			ZEPHIR_CALL_METHOD(NULL, &rc, "__construct", NULL, 26, _var);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&rc);
			object_init_ex(&rc, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &rc, "__construct", NULL, 24, _var);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_2$$3, &rc, "getfilename", NULL, 117);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, &rc, "getstartline", NULL, 118);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, " title=\"Declared in file % on line %\" ");
		ZEPHIR_CALL_CE_STATIC(&editorAttributes, moon_component_errorhandler_helpers_ce, "formathtml", &_1, 0, &_4$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_CE_STATIC(&_7, moon_component_errorhandler_helpers_ce, "getclass", &_8, 0, _var);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_5, moon_component_errorhandler_helpers_ce, "escapehtml", &_6, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CALL_FUNCTION(&_10, "spl_object_hash", NULL, 119, _var);
	zephir_check_call_status();
	zephir_md5(&_9, &_10);
	ZVAL_LONG(&_11, 0);
	ZVAL_LONG(&_12, 4);
	ZEPHIR_INIT_VAR(&_13);
	zephir_substr(&_13, &_9, 0 , 4 , 0);
	ZEPHIR_INIT_VAR(&out);
	ZEPHIR_CONCAT_SVSVSVS(&out, "<span class=\"moon-dump-object\"", &editorAttributes, ">", &_5, "</span> <span class=\"moon-dump-hash\">#", &_13, "</span>");
	ZEPHIR_INIT_VAR(&_14);
	if (zephir_array_isset_string(&options, SL("parents"))) {
		ZEPHIR_OBS_NVAR(&_14);
		zephir_array_fetch_string(&_14, &options, SL("parents"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 335);
	} else {
		ZEPHIR_INIT_NVAR(&_14);
		array_init(&_14);
	}
	ZEPHIR_CALL_FUNCTION(&_15, "in_array", NULL, 5, _var, &_14, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_16, this_ptr, ZEND_STRL("maxDepth"), PH_NOISY_CC | PH_READONLY);
	_17 = !zephir_is_true(&_16);
	if (!(_17)) {
		zephir_read_property(&_18, this_ptr, ZEND_STRL("maxDepth"), PH_NOISY_CC | PH_READONLY);
		_17 = ZEPHIR_GT_LONG(&_18, level);
	}
	_19 = _17;
	if (!(_19)) {
		_19 = zephir_instance_of_ev(_var, zend_ce_closure);
	}
	if (ZEPHIR_IS_EMPTY(&fields)) {
		ZEPHIR_CONCAT_VS(return_value, &out, "\n");
		RETURN_MM();
	} else if (zephir_is_true(&_15)) {
		ZEPHIR_CONCAT_VS(return_value, &out, " { <i>RECURSION</i> }\n");
		RETURN_MM();
	} else if (_19) {
		if (level) {
			zephir_read_property(&_20$$6, this_ptr, ZEND_STRL("collapseSub"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&collapsed);
			ZVAL_BOOL(&collapsed, ZEPHIR_LE_LONG(&_20$$6, zephir_fast_count_int(&fields)));
		} else {
			zephir_read_property(&_21$$6, this_ptr, ZEND_STRL("collapseTop"), PH_NOISY_CC | PH_READONLY);
			if (Z_TYPE_P(&_21$$6) == IS_LONG) {
				zephir_read_property(&_22$$6, this_ptr, ZEND_STRL("collapseTop"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&collapsed);
				ZVAL_BOOL(&collapsed, ZEPHIR_LE_LONG(&_22$$6, zephir_fast_count_int(&fields)));
			} else {
				ZEPHIR_OBS_NVAR(&collapsed);
				zephir_read_property(&collapsed, this_ptr, ZEND_STRL("collapseTop"), PH_NOISY_CC);
			}
		}
		ZEPHIR_INIT_VAR(&_23$$6);
		if (zephir_is_true(&collapsed)) {
			ZEPHIR_INIT_NVAR(&_23$$6);
			ZVAL_STRING(&_23$$6, " moon-collapsed");
		} else {
			ZEPHIR_INIT_NVAR(&_23$$6);
			ZVAL_STRING(&_23$$6, "");
		}
		ZEPHIR_INIT_VAR(&span);
		ZEPHIR_CONCAT_SVS(&span, "<span class=\"moon-toggle", &_23$$6, "\"");
		_24$$6 = zephir_is_true(&collapsed);
		if (_24$$6) {
			zephir_array_fetch_string(&_25$$6, &options, SL("lazy"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 340);
			_24$$6 = !ZEPHIR_IS_FALSE_IDENTICAL(&_25$$6);
		}
		if (_24$$6) {
			ZEPHIR_INIT_VAR(&_26$$7);
			ZVAL_LONG(&_28$$7, level);
			ZEPHIR_CALL_METHOD(&_27$$7, this_ptr, "tojson", NULL, 107, _var, &options, &_28$$7);
			zephir_check_call_status();
			ZVAL_LONG(&_28$$7, (4 | 2));
			zephir_json_encode(&_26$$7, &_27$$7, zephir_get_intval(&_28$$7) );
			ZEPHIR_CONCAT_VSVSVS(return_value, &span, " data-moon-dump='", &_26$$7, "'>", &out, "</span>\n");
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(&_29$$8);
			if (zephir_is_true(&collapsed)) {
				ZEPHIR_INIT_NVAR(&_29$$8);
				ZVAL_STRING(&_29$$8, " class=\"moon-collapsed\"");
			} else {
				ZEPHIR_INIT_NVAR(&_29$$8);
				ZVAL_STRING(&_29$$8, "");
			}
			ZEPHIR_INIT_VAR(&_30$$8);
			ZEPHIR_CONCAT_VSVSSVS(&_30$$8, &span, ">", &out, "</span>\n", "<div", &_29$$8, ">");
			ZEPHIR_CPY_WRT(&out, &_30$$8);
			zephir_array_update_multi(&options, _var, SL("sa"), 3, SL("parents"));
			zephir_is_iterable(&fields, 0, "moon/Component/ErrorHandler/Dumper.zep", 356);
			if (Z_TYPE_P(&fields) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _33$$8, _34$$8, _31$$8)
				{
					ZEPHIR_INIT_NVAR(&k$$8);
					if (_34$$8 != NULL) { 
						ZVAL_STR_COPY(&k$$8, _34$$8);
					} else {
						ZVAL_LONG(&k$$8, _33$$8);
					}
					ZEPHIR_INIT_NVAR(&v$$8);
					ZVAL_COPY(&v$$8, _31$$8);
					ZEPHIR_INIT_NVAR(&vis);
					ZVAL_STRING(&vis, "");
					_35$$9 = zephir_array_isset_long(&k$$8, 0);
					if (_35$$9) {
						zephir_array_fetch_long(&_36$$9, &k$$8, 0, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 349);
						_35$$9 = ZEPHIR_IS_STRING_IDENTICAL(&_36$$9, "\0");
					}
					if (_35$$9) {
						ZEPHIR_INIT_NVAR(&_37$$10);
						zephir_array_fetch_long(&_38$$10, &k$$8, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 350);
						if (ZEPHIR_IS_STRING_IDENTICAL(&_38$$10, "*")) {
							ZEPHIR_INIT_NVAR(&_37$$10);
							ZVAL_STRING(&_37$$10, "protected");
						} else {
							ZEPHIR_INIT_NVAR(&_37$$10);
							ZVAL_STRING(&_37$$10, "private");
						}
						ZEPHIR_INIT_NVAR(&vis);
						ZEPHIR_CONCAT_SVS(&vis, " <span class=\"moon-dump-visibility\">", &_37$$10, "</span>");
						ZEPHIR_INIT_NVAR(&_39$$10);
						ZVAL_STRING(&_39$$10, "\0");
						ZEPHIR_CALL_FUNCTION(&_40$$10, "strrpos", &_41, 120, &k$$8, &_39$$10);
						zephir_check_call_status();
						ZVAL_LONG(&_42$$10, (zephir_get_numberval(&_40$$10) + 1));
						ZEPHIR_INIT_NVAR(&_39$$10);
						zephir_substr(&_39$$10, &k$$8, zephir_get_intval(&_42$$10), 0, ZEPHIR_SUBSTR_NO_LENGTH);
						ZEPHIR_CPY_WRT(&k$$8, &_39$$10);
					}
					_43$$9 = Z_TYPE_P(&k$$8) == IS_STRING;
					if (_43$$9) {
						zephir_read_property(&_44$$9, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_45$$9);
						zephir_fast_strtolower(&_45$$9, &k$$8);
						_43$$9 = zephir_array_isset(&_44$$9, &_45$$9);
					}
					ZEPHIR_INIT_NVAR(&hide);
					ZVAL_BOOL(&hide, _43$$9);
					ZEPHIR_INIT_NVAR(&_46$$9);
					ZVAL_STRING(&_46$$9, "|  ");
					ZVAL_LONG(&_47$$9, level);
					ZEPHIR_CALL_FUNCTION(&_48$$9, "str_repeat", &_49, 113, &_46$$9, &_47$$9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_51$$9, this_ptr, "encodekey", &_52, 114, &k$$8);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_50$$9, moon_component_errorhandler_helpers_ce, "escapehtml", &_6, 0, &_51$$9);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_53$$9);
					if (zephir_is_true(&hide)) {
						ZEPHIR_CALL_SELF(&_55$$9, "hidevalue", &_56, 115, &v$$8);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_54$$9, moon_component_errorhandler_helpers_ce, "escapehtml", &_6, 0, &_55$$9);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_53$$9);
						ZEPHIR_CONCAT_VS(&_53$$9, &_54$$9, "\n");
					} else {
						ZVAL_LONG(&_47$$9, (level + 1));
						ZEPHIR_CALL_METHOD(&_53$$9, this_ptr, "dumpvar", &_57, 108, &v$$8, &options, &_47$$9);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(&_58$$9);
					ZEPHIR_CONCAT_SVSSVSV(&_58$$9, "<span class=\"moon-dump-indent\">   ", &_48$$9, "</span>", "<span class=\"moon-dump-key\">", &_50$$9, "</span>{vis} => ", &_53$$9);
					zephir_concat_self(&out, &_58$$9);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_32$$8, &fields, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_32$$8)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&k$$8, &fields, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&v$$8, &fields, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&vis);
						ZVAL_STRING(&vis, "");
						_59$$11 = zephir_array_isset_long(&k$$8, 0);
						if (_59$$11) {
							zephir_array_fetch_long(&_60$$11, &k$$8, 0, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 349);
							_59$$11 = ZEPHIR_IS_STRING_IDENTICAL(&_60$$11, "\0");
						}
						if (_59$$11) {
							ZEPHIR_INIT_NVAR(&_61$$12);
							zephir_array_fetch_long(&_62$$12, &k$$8, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 350);
							if (ZEPHIR_IS_STRING_IDENTICAL(&_62$$12, "*")) {
								ZEPHIR_INIT_NVAR(&_61$$12);
								ZVAL_STRING(&_61$$12, "protected");
							} else {
								ZEPHIR_INIT_NVAR(&_61$$12);
								ZVAL_STRING(&_61$$12, "private");
							}
							ZEPHIR_INIT_NVAR(&vis);
							ZEPHIR_CONCAT_SVS(&vis, " <span class=\"moon-dump-visibility\">", &_61$$12, "</span>");
							ZEPHIR_INIT_NVAR(&_63$$12);
							ZVAL_STRING(&_63$$12, "\0");
							ZEPHIR_CALL_FUNCTION(&_64$$12, "strrpos", &_41, 120, &k$$8, &_63$$12);
							zephir_check_call_status();
							ZVAL_LONG(&_65$$12, (zephir_get_numberval(&_64$$12) + 1));
							ZEPHIR_INIT_NVAR(&_63$$12);
							zephir_substr(&_63$$12, &k$$8, zephir_get_intval(&_65$$12), 0, ZEPHIR_SUBSTR_NO_LENGTH);
							ZEPHIR_CPY_WRT(&k$$8, &_63$$12);
						}
						_66$$11 = Z_TYPE_P(&k$$8) == IS_STRING;
						if (_66$$11) {
							zephir_read_property(&_67$$11, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_NVAR(&_68$$11);
							zephir_fast_strtolower(&_68$$11, &k$$8);
							_66$$11 = zephir_array_isset(&_67$$11, &_68$$11);
						}
						ZEPHIR_INIT_NVAR(&hide);
						ZVAL_BOOL(&hide, _66$$11);
						ZEPHIR_INIT_NVAR(&_69$$11);
						ZVAL_STRING(&_69$$11, "|  ");
						ZVAL_LONG(&_70$$11, level);
						ZEPHIR_CALL_FUNCTION(&_71$$11, "str_repeat", &_49, 113, &_69$$11, &_70$$11);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_73$$11, this_ptr, "encodekey", &_52, 114, &k$$8);
						zephir_check_call_status();
						ZEPHIR_CALL_CE_STATIC(&_72$$11, moon_component_errorhandler_helpers_ce, "escapehtml", &_6, 0, &_73$$11);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_74$$11);
						if (zephir_is_true(&hide)) {
							ZEPHIR_CALL_SELF(&_76$$11, "hidevalue", &_56, 115, &v$$8);
							zephir_check_call_status();
							ZEPHIR_CALL_CE_STATIC(&_75$$11, moon_component_errorhandler_helpers_ce, "escapehtml", &_6, 0, &_76$$11);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_74$$11);
							ZEPHIR_CONCAT_VS(&_74$$11, &_75$$11, "\n");
						} else {
							ZVAL_LONG(&_70$$11, (level + 1));
							ZEPHIR_CALL_METHOD(&_74$$11, this_ptr, "dumpvar", &_57, 108, &v$$8, &options, &_70$$11);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_77$$11);
						ZEPHIR_CONCAT_SVSSVSV(&_77$$11, "<span class=\"moon-dump-indent\">   ", &_71$$11, "</span>", "<span class=\"moon-dump-key\">", &_72$$11, "</span>{vis} => ", &_74$$11);
						zephir_concat_self(&out, &_77$$11);
					ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&v$$8);
			ZEPHIR_INIT_NVAR(&k$$8);
			zephir_array_fetch_string(&_78$$8, &options, SL("parents"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 356);
			ZEPHIR_MAKE_REF(&_78$$8);
			ZEPHIR_CALL_FUNCTION(NULL, "array_pop", NULL, 90, &_78$$8);
			ZEPHIR_UNREF(&_78$$8);
			zephir_check_call_status();
			ZEPHIR_CONCAT_VS(return_value, &out, "</div>");
			RETURN_MM();
		}
	} else {
		ZEPHIR_CONCAT_VS(return_value, &out, " { ... }\n");
		RETURN_MM();
	}

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpResource) {

	zend_string *_9$$3;
	zend_ulong _8$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_13 = NULL, *_16 = NULL;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *_var, _var_sub, *options_param = NULL, *level_param = NULL, out, type, dumper, _0, _2, _3, k$$3, v$$3, _4$$3, _5$$3, *_6$$3, _7$$3, _10$$4, _11$$4, _12$$4, _14$$4, _15$$4, _17$$4, _18$$5, _19$$5, _20$$5, _21$$5, _22$$5, _23$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&out);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&dumper);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&k$$3);
	ZVAL_UNDEF(&v$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &_var, &options_param, &level_param);

	zephir_get_arrval(&options, options_param);
	level = zephir_get_intval(level_param);


	ZEPHIR_CALL_FUNCTION(&type, "get_resource_type", NULL, 121, _var);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, moon_component_errorhandler_helpers_ce, "escapehtml", &_1, 0, &type);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, zephir_get_intval(_var));
	ZEPHIR_INIT_VAR(&out);
	ZEPHIR_CONCAT_SVSSVS(&out, "<span class=\"moon-dump-resource\">", &_0, " resource</span> ", "<span class=\"moon-dump-hash\">#", &_2, "</span>");
	zephir_read_property(&_3, this_ptr, ZEND_STRL("resourceDumpers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_3, &type)) {
		ZEPHIR_INIT_NVAR(&out);
		ZVAL_STRING(&out, "<span class=\"moon-toggle moon-collapsed\">{out}</span>\n<div class=\"moon-collapsed\">");
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("resourceDumpers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&dumper);
		zephir_array_fetch(&dumper, &_4$$3, &type, PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 375);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_5$$3, &dumper, NULL, 0, _var);
		zephir_check_call_status();
		zephir_is_iterable(&_5$$3, 0, "moon/Component/ErrorHandler/Dumper.zep", 379);
		if (Z_TYPE_P(&_5$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_5$$3), _8$$3, _9$$3, _6$$3)
			{
				ZEPHIR_INIT_NVAR(&k$$3);
				if (_9$$3 != NULL) { 
					ZVAL_STR_COPY(&k$$3, _9$$3);
				} else {
					ZVAL_LONG(&k$$3, _8$$3);
				}
				ZEPHIR_INIT_NVAR(&v$$3);
				ZVAL_COPY(&v$$3, _6$$3);
				ZEPHIR_INIT_NVAR(&_10$$4);
				ZVAL_STRING(&_10$$4, "|  ");
				ZVAL_LONG(&_11$$4, level);
				ZEPHIR_CALL_FUNCTION(&_12$$4, "str_repeat", &_13, 113, &_10$$4, &_11$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_CE_STATIC(&_14$$4, moon_component_errorhandler_helpers_ce, "escapehtml", &_1, 0, &k$$3);
				zephir_check_call_status();
				ZVAL_LONG(&_11$$4, (level + 1));
				ZEPHIR_CALL_METHOD(&_15$$4, this_ptr, "dumpvar", &_16, 108, &v$$3, &options, &_11$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$4);
				ZEPHIR_CONCAT_SVSSVSV(&_17$$4, "<span class=\"moon-dump-indent\">   ", &_12$$4, "</span>", "<span class=\"moon-dump-key\">", &_14$$4, "</span> => ", &_15$$4);
				zephir_concat_self(&out, &_17$$4);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_5$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_7$$3, &_5$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&k$$3, &_5$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&v$$3, &_5$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_18$$5);
					ZVAL_STRING(&_18$$5, "|  ");
					ZVAL_LONG(&_19$$5, level);
					ZEPHIR_CALL_FUNCTION(&_20$$5, "str_repeat", &_13, 113, &_18$$5, &_19$$5);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_21$$5, moon_component_errorhandler_helpers_ce, "escapehtml", &_1, 0, &k$$3);
					zephir_check_call_status();
					ZVAL_LONG(&_19$$5, (level + 1));
					ZEPHIR_CALL_METHOD(&_22$$5, this_ptr, "dumpvar", &_16, 108, &v$$3, &options, &_19$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_23$$5);
					ZEPHIR_CONCAT_SVSSVSV(&_23$$5, "<span class=\"moon-dump-indent\">   ", &_20$$5, "</span>", "<span class=\"moon-dump-key\">", &_21$$5, "</span> => ", &_22$$5);
					zephir_concat_self(&out, &_23$$5);
				ZEPHIR_CALL_METHOD(NULL, &_5$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&v$$3);
		ZEPHIR_INIT_NVAR(&k$$3);
		ZEPHIR_CONCAT_VS(return_value, &out, "</div>");
		RETURN_MM();
	}
	RETURN_MM_STRING("{out}\n");

}

/**
 * @param $var
 * @param array $options
 * @param int $level
 * @return array|float|string
 * @throws \ReflectionException
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, toJson) {

	zval _15$$7, _24$$8, _35$$9, _74$$15, _88$$17, _106$$22, _109$$23;
	zend_string *_20$$6, *_63$$14, *_105$$21;
	zend_ulong _19$$6, _62$$14, _104$$21;
	zval _9$$4, _95$$19;
	zend_bool _0, _1, _12$$6, _13$$6, _21$$8, _32$$9, _42$$10, _55$$10, _64$$15, _71$$15, _79$$17, _85$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_26 = NULL, *_29 = NULL, *_31 = NULL, *_49 = NULL, *_69 = NULL;
	zend_long level, ZEPHIR_LAST_CALL_STATUS;
	zval *_var, _var_sub, options, *options_param = NULL, *level_param = NULL, __$true, type, vis, obj, hash, hide, res, rec, tmp, v_varar, _2, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _10$$5, _11$$6, _14$$6, k$$6, v$$6, *_17$$6, _18$$6, _40$$6, _16$$7, _22$$8, _23$$8, _25$$8, _27$$8, _28$$8, _30$$8, _33$$9, _34$$9, _36$$9, _37$$9, _38$$9, _39$$9, _41$$10, _43$$10, _45$$10, _54$$10, _56$$10, _93$$10, _44$$11, _46$$12, _47$$12, _48$$12, _50$$12, _51$$12, _52$$12, _53$$12, _57$$14, _58$$14, k$$14, v$$14, _59$$14, *_60$$14, _61$$14, _65$$15, _72$$15, _73$$15, _75$$15, _76$$15, _77$$15, _78$$15, _66$$16, _67$$16, _68$$16, _70$$16, _80$$17, _86$$17, _87$$17, _89$$17, _90$$17, _91$$17, _92$$17, _81$$18, _82$$18, _83$$18, _84$$18, _94$$19, _112$$19, _96$$20, _97$$20, _98$$20, _99$$20, k$$21, v$$21, dumper$$21, _100$$21, _101$$21, *_102$$21, _103$$21, _107$$22, _108$$22, _110$$23, _111$$23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&options);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&vis);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&hide);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&rec);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&v_varar);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&k$$6);
	ZVAL_UNDEF(&v$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_40$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_39$$9);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_43$$10);
	ZVAL_UNDEF(&_45$$10);
	ZVAL_UNDEF(&_54$$10);
	ZVAL_UNDEF(&_56$$10);
	ZVAL_UNDEF(&_93$$10);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&_46$$12);
	ZVAL_UNDEF(&_47$$12);
	ZVAL_UNDEF(&_48$$12);
	ZVAL_UNDEF(&_50$$12);
	ZVAL_UNDEF(&_51$$12);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_53$$12);
	ZVAL_UNDEF(&_57$$14);
	ZVAL_UNDEF(&_58$$14);
	ZVAL_UNDEF(&k$$14);
	ZVAL_UNDEF(&v$$14);
	ZVAL_UNDEF(&_59$$14);
	ZVAL_UNDEF(&_61$$14);
	ZVAL_UNDEF(&_65$$15);
	ZVAL_UNDEF(&_72$$15);
	ZVAL_UNDEF(&_73$$15);
	ZVAL_UNDEF(&_75$$15);
	ZVAL_UNDEF(&_76$$15);
	ZVAL_UNDEF(&_77$$15);
	ZVAL_UNDEF(&_78$$15);
	ZVAL_UNDEF(&_66$$16);
	ZVAL_UNDEF(&_67$$16);
	ZVAL_UNDEF(&_68$$16);
	ZVAL_UNDEF(&_70$$16);
	ZVAL_UNDEF(&_80$$17);
	ZVAL_UNDEF(&_86$$17);
	ZVAL_UNDEF(&_87$$17);
	ZVAL_UNDEF(&_89$$17);
	ZVAL_UNDEF(&_90$$17);
	ZVAL_UNDEF(&_91$$17);
	ZVAL_UNDEF(&_92$$17);
	ZVAL_UNDEF(&_81$$18);
	ZVAL_UNDEF(&_82$$18);
	ZVAL_UNDEF(&_83$$18);
	ZVAL_UNDEF(&_84$$18);
	ZVAL_UNDEF(&_94$$19);
	ZVAL_UNDEF(&_112$$19);
	ZVAL_UNDEF(&_96$$20);
	ZVAL_UNDEF(&_97$$20);
	ZVAL_UNDEF(&_98$$20);
	ZVAL_UNDEF(&_99$$20);
	ZVAL_UNDEF(&k$$21);
	ZVAL_UNDEF(&v$$21);
	ZVAL_UNDEF(&dumper$$21);
	ZVAL_UNDEF(&_100$$21);
	ZVAL_UNDEF(&_101$$21);
	ZVAL_UNDEF(&_103$$21);
	ZVAL_UNDEF(&_107$$22);
	ZVAL_UNDEF(&_108$$22);
	ZVAL_UNDEF(&_110$$23);
	ZVAL_UNDEF(&_111$$23);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_95$$19);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_74$$15);
	ZVAL_UNDEF(&_88$$17);
	ZVAL_UNDEF(&_106$$22);
	ZVAL_UNDEF(&_109$$23);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &_var, &options_param, &level_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	if (!level_param) {
		level = 0;
	} else {
		level = zephir_get_intval(level_param);
	}


	_0 = (Z_TYPE_P(_var) == IS_TRUE || Z_TYPE_P(_var) == IS_FALSE);
	if (!(_0)) {
		_0 = Z_TYPE_P(_var) == IS_NULL;
	}
	_1 = _0;
	if (!(_1)) {
		_1 = Z_TYPE_P(_var) == IS_LONG;
	}
	ZEPHIR_CALL_FUNCTION(&_2, "is_float", NULL, 122, _var);
	zephir_check_call_status();
	if (_1) {
		RETVAL_ZVAL(_var, 1, 0);
		RETURN_MM();
	} else if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&tmp);
		zephir_json_encode(&tmp, _var, 0 );
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CALL_FUNCTION(&_4$$4, "is_finite", NULL, 112, _var);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$4)) {
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, ".");
			ZEPHIR_INIT_VAR(&_6$$4);
			zephir_fast_strpos(&_6$$4, &tmp, &_5$$4, 0 );
			if (zephir_is_true(&_6$$4)) {
				ZEPHIR_CPY_WRT(&_3$$4, _var);
			} else {
				ZEPHIR_INIT_VAR(&_7$$4);
				zephir_create_array(&_7$$4, 1, 0);
				add_assoc_stringl_ex(&_7$$4, SL("number"), SL("{tmp}.0"));
				ZEPHIR_CPY_WRT(&_3$$4, &_7$$4);
			}
		} else {
			ZEPHIR_INIT_VAR(&_8$$4);
			zephir_create_array(&_8$$4, 1, 0);
			zephir_get_strval(&_9$$4, _var);
			zephir_array_update_string(&_8$$4, SL("type"), &_9$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&_3$$4, &_8$$4);
		}
		RETURN_CCTOR(&_3$$4);
	} else if (Z_TYPE_P(_var) == IS_STRING) {
		zephir_read_property(&_10$$5, this_ptr, ZEND_STRL("maxLength"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "encodestring", NULL, 0, _var, &_10$$5);
		zephir_check_call_status();
		RETURN_MM();
	} else if (Z_TYPE_P(&v_varar) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_11$$6);
		if (zephir_array_isset_string(&options, SL("parents"))) {
			ZEPHIR_OBS_NVAR(&_11$$6);
			zephir_array_fetch_string(&_11$$6, &options, SL("parents"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 411);
		} else {
			ZEPHIR_INIT_NVAR(&_11$$6);
			array_init(&_11$$6);
		}
		ZEPHIR_CALL_FUNCTION(&rec, "in_array", NULL, 5, _var, &_11$$6, &__$true);
		zephir_check_call_status();
		_12$$6 = ((zephir_fast_count_int(_var)) ? 1 : 0);
		if (_12$$6) {
			_13$$6 = zephir_is_true(&rec);
			if (!(_13$$6)) {
				zephir_read_property(&_14$$6, this_ptr, ZEND_STRL("maxDepth"), PH_NOISY_CC | PH_READONLY);
				_13$$6 = ZEPHIR_LE_LONG(&_14$$6, level);
			}
			_12$$6 = _13$$6;
		}
		if (_12$$6) {
			zephir_create_array(return_value, 1, 0);
			ZEPHIR_INIT_VAR(&_15$$7);
			zephir_create_array(&_15$$7, 2, 0);
			ZEPHIR_INIT_VAR(&_16$$7);
			ZVAL_LONG(&_16$$7, zephir_fast_count_int(_var));
			zephir_array_fast_append(&_15$$7, &_16$$7);
			zephir_array_fast_append(&_15$$7, &rec);
			zephir_array_update_string(return_value, SL("stop"), &_15$$7, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&res);
		array_init(&res);
		zephir_array_update_multi(&options, _var, SL("sa"), 3, SL("parents"));
		zephir_is_iterable(_var, 0, "moon/Component/ErrorHandler/Dumper.zep", 423);
		if (Z_TYPE_P(_var) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_var), _19$$6, _20$$6, _17$$6)
			{
				ZEPHIR_INIT_NVAR(&k$$6);
				if (_20$$6 != NULL) { 
					ZVAL_STR_COPY(&k$$6, _20$$6);
				} else {
					ZVAL_LONG(&k$$6, _19$$6);
				}
				ZEPHIR_INIT_NVAR(&v$$6);
				ZVAL_COPY(&v$$6, _17$$6);
				_21$$8 = Z_TYPE_P(&k$$6) == IS_STRING;
				if (_21$$8) {
					zephir_read_property(&_22$$8, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_23$$8);
					zephir_fast_strtolower(&_23$$8, &k$$6);
					_21$$8 = zephir_array_isset(&_22$$8, &_23$$8);
				}
				ZEPHIR_INIT_NVAR(&hide);
				ZVAL_BOOL(&hide, _21$$8);
				ZEPHIR_INIT_NVAR(&_24$$8);
				zephir_create_array(&_24$$8, 2, 0);
				ZEPHIR_CALL_METHOD(&_25$$8, this_ptr, "encodekey", &_26, 114, &k$$6);
				zephir_check_call_status();
				zephir_array_fast_append(&_24$$8, &_25$$8);
				ZEPHIR_INIT_NVAR(&_27$$8);
				if (zephir_is_true(&hide)) {
					ZEPHIR_INIT_NVAR(&_28$$8);
					zephir_create_array(&_28$$8, 1, 0);
					ZEPHIR_CALL_SELF(&_25$$8, "hidevalue", &_29, 115, &v$$6);
					zephir_check_call_status();
					zephir_array_update_string(&_28$$8, SL("type"), &_25$$8, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&_27$$8, &_28$$8);
				} else {
					ZVAL_LONG(&_30$$8, (level + 1));
					ZEPHIR_CALL_METHOD(&_27$$8, this_ptr, "tojson", &_31, 107, &v$$6, &options, &_30$$8);
					zephir_check_call_status();
				}
				zephir_array_fast_append(&_24$$8, &_27$$8);
				zephir_array_append(&res, &_24$$8, PH_SEPARATE, "moon/Component/ErrorHandler/Dumper.zep", 421);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _var, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_18$$6, _var, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_18$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&k$$6, _var, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&v$$6, _var, "current", NULL, 0);
				zephir_check_call_status();
					_32$$9 = Z_TYPE_P(&k$$6) == IS_STRING;
					if (_32$$9) {
						zephir_read_property(&_33$$9, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_34$$9);
						zephir_fast_strtolower(&_34$$9, &k$$6);
						_32$$9 = zephir_array_isset(&_33$$9, &_34$$9);
					}
					ZEPHIR_INIT_NVAR(&hide);
					ZVAL_BOOL(&hide, _32$$9);
					ZEPHIR_INIT_NVAR(&_35$$9);
					zephir_create_array(&_35$$9, 2, 0);
					ZEPHIR_CALL_METHOD(&_36$$9, this_ptr, "encodekey", &_26, 114, &k$$6);
					zephir_check_call_status();
					zephir_array_fast_append(&_35$$9, &_36$$9);
					ZEPHIR_INIT_NVAR(&_37$$9);
					if (zephir_is_true(&hide)) {
						ZEPHIR_INIT_NVAR(&_38$$9);
						zephir_create_array(&_38$$9, 1, 0);
						ZEPHIR_CALL_SELF(&_36$$9, "hidevalue", &_29, 115, &v$$6);
						zephir_check_call_status();
						zephir_array_update_string(&_38$$9, SL("type"), &_36$$9, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&_37$$9, &_38$$9);
					} else {
						ZVAL_LONG(&_39$$9, (level + 1));
						ZEPHIR_CALL_METHOD(&_37$$9, this_ptr, "tojson", &_31, 107, &v$$6, &options, &_39$$9);
						zephir_check_call_status();
					}
					zephir_array_fast_append(&_35$$9, &_37$$9);
					zephir_array_append(&res, &_35$$9, PH_SEPARATE, "moon/Component/ErrorHandler/Dumper.zep", 421);
				ZEPHIR_CALL_METHOD(NULL, _var, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&v$$6);
		ZEPHIR_INIT_NVAR(&k$$6);
		zephir_array_fetch_string(&_40$$6, &options, SL("parents"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 423);
		ZEPHIR_MAKE_REF(&_40$$6);
		ZEPHIR_CALL_FUNCTION(NULL, "array_pop", NULL, 90, &_40$$6);
		ZEPHIR_UNREF(&_40$$6);
		zephir_check_call_status();
		RETURN_CCTOR(&res);
	} else if (Z_TYPE_P(_var) == IS_OBJECT) {
		ZEPHIR_CALL_FUNCTION(&hash, "spl_object_hash", NULL, 119, _var);
		zephir_check_call_status();
		zephir_array_fetch_string(&_41$$10, &options, SL("snapshot"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 427);
		ZEPHIR_OBS_VAR(&obj);
		zephir_array_fetch(&obj, &_41$$10, &hash, PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 427);
		_42$$10 = zephir_is_true(&obj);
		if (_42$$10) {
			zephir_array_fetch_string(&_43$$10, &obj, SL("level"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 428);
			_42$$10 = ZEPHIR_LE_LONG(&_43$$10, level);
		}
		if (_42$$10) {
			zephir_create_array(return_value, 1, 0);
			ZEPHIR_OBS_VAR(&_44$$11);
			zephir_array_fetch_string(&_44$$11, &obj, SL("id"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 429);
			zephir_array_update_string(return_value, SL("object"), &_44$$11, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_45$$10);
		if (!(zephir_is_true(&obj))) {
			ZEPHIR_INIT_VAR(&_46$$12);
			zephir_create_array(&_46$$12, 5, 0);
			zephir_array_fetch_string(&_47$$12, &options, SL("snapshot"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 431);
			add_assoc_long_ex(&_46$$12, SL("id"), zephir_fast_count_int(&_47$$12));
			ZEPHIR_CALL_CE_STATIC(&_48$$12, moon_component_errorhandler_helpers_ce, "getclass", &_49, 0, _var);
			zephir_check_call_status();
			zephir_array_update_string(&_46$$12, SL("name"), &_48$$12, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_50$$12);
			zephir_md5(&_50$$12, &hash);
			ZVAL_LONG(&_51$$12, 0);
			ZVAL_LONG(&_52$$12, 4);
			ZEPHIR_INIT_VAR(&_53$$12);
			zephir_substr(&_53$$12, &_50$$12, 0 , 4 , 0);
			zephir_array_update_string(&_46$$12, SL("hash"), &_53$$12, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_53$$12);
			ZVAL_LONG(&_53$$12, level);
			zephir_array_update_string(&_46$$12, SL("level"), &_53$$12, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_46$$12, SL("object"), _var, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&_45$$10, &_46$$12);
		} else {
			ZEPHIR_CPY_WRT(&_45$$10, &obj);
		}
		ZEPHIR_CPY_WRT(&obj, &_45$$10);
		zephir_read_property(&_54$$10, this_ptr, ZEND_STRL("maxDepth"), PH_NOISY_CC | PH_READONLY);
		_55$$10 = ZEPHIR_GT_LONG(&_54$$10, level);
		if (!(_55$$10)) {
			zephir_read_property(&_56$$10, this_ptr, ZEND_STRL("maxDepth"), PH_NOISY_CC | PH_READONLY);
			_55$$10 = !zephir_is_true(&_56$$10);
		}
		if (_55$$10) {
			ZEPHIR_INIT_VAR(&_57$$14);
			ZVAL_LONG(&_57$$14, level);
			zephir_array_update_string(&obj, SL("level"), &_57$$14, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_58$$14);
			array_init(&_58$$14);
			zephir_array_update_string(&obj, SL("items"), &_58$$14, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_59$$14, this_ptr, "exportobject", NULL, 116, _var);
			zephir_check_call_status();
			zephir_is_iterable(&_59$$14, 0, "moon/Component/ErrorHandler/Dumper.zep", 454);
			if (Z_TYPE_P(&_59$$14) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_59$$14), _62$$14, _63$$14, _60$$14)
				{
					ZEPHIR_INIT_NVAR(&k$$14);
					if (_63$$14 != NULL) { 
						ZVAL_STR_COPY(&k$$14, _63$$14);
					} else {
						ZVAL_LONG(&k$$14, _62$$14);
					}
					ZEPHIR_INIT_NVAR(&v$$14);
					ZVAL_COPY(&v$$14, _60$$14);
					ZEPHIR_INIT_NVAR(&vis);
					ZVAL_LONG(&vis, 0);
					_64$$15 = zephir_array_isset_long(&k$$14, 0);
					if (_64$$15) {
						zephir_array_fetch_long(&_65$$15, &k$$14, 0, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 447);
						_64$$15 = ZEPHIR_IS_STRING_IDENTICAL(&_65$$15, "\0");
					}
					if (_64$$15) {
						zephir_array_fetch_long(&_66$$16, &k$$14, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 448);
						if (ZEPHIR_IS_STRING_IDENTICAL(&_66$$16, "*")) {
							ZEPHIR_INIT_NVAR(&vis);
							ZVAL_LONG(&vis, 1);
						} else {
							ZEPHIR_INIT_NVAR(&vis);
							ZVAL_LONG(&vis, 2);
						}
						ZEPHIR_INIT_NVAR(&_67$$16);
						ZVAL_STRING(&_67$$16, "\0");
						ZEPHIR_CALL_FUNCTION(&_68$$16, "strrpos", &_69, 120, &k$$14, &_67$$16);
						zephir_check_call_status();
						ZVAL_LONG(&_70$$16, (zephir_get_numberval(&_68$$16) + 1));
						ZEPHIR_INIT_NVAR(&_67$$16);
						zephir_substr(&_67$$16, &k$$14, zephir_get_intval(&_70$$16), 0, ZEPHIR_SUBSTR_NO_LENGTH);
						ZEPHIR_CPY_WRT(&k$$14, &_67$$16);
					}
					_71$$15 = Z_TYPE_P(&k$$14) == IS_STRING;
					if (_71$$15) {
						zephir_read_property(&_72$$15, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_NVAR(&_73$$15);
						zephir_fast_strtolower(&_73$$15, &k$$14);
						_71$$15 = zephir_array_isset(&_72$$15, &_73$$15);
					}
					ZEPHIR_INIT_NVAR(&hide);
					ZVAL_BOOL(&hide, _71$$15);
					ZEPHIR_INIT_NVAR(&_74$$15);
					zephir_create_array(&_74$$15, 3, 0);
					ZEPHIR_CALL_METHOD(&_75$$15, this_ptr, "encodekey", &_26, 114, &k$$14);
					zephir_check_call_status();
					zephir_array_fast_append(&_74$$15, &_75$$15);
					ZEPHIR_INIT_NVAR(&_76$$15);
					if (zephir_is_true(&hide)) {
						ZEPHIR_INIT_NVAR(&_77$$15);
						zephir_create_array(&_77$$15, 1, 0);
						ZEPHIR_CALL_SELF(&_75$$15, "hidevalue", &_29, 115, &v$$14);
						zephir_check_call_status();
						zephir_array_update_string(&_77$$15, SL("type"), &_75$$15, PH_COPY | PH_SEPARATE);
						ZEPHIR_CPY_WRT(&_76$$15, &_77$$15);
					} else {
						ZVAL_LONG(&_78$$15, (level + 1));
						ZEPHIR_CALL_METHOD(&_76$$15, this_ptr, "tojson", &_31, 107, &v$$14, &options, &_78$$15);
						zephir_check_call_status();
					}
					zephir_array_fast_append(&_74$$15, &_76$$15);
					zephir_array_fast_append(&_74$$15, &vis);
					zephir_array_update_multi(&obj, &_74$$15, SL("sa"), 3, SL("items"));
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_59$$14, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_61$$14, &_59$$14, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_61$$14)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&k$$14, &_59$$14, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&v$$14, &_59$$14, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&vis);
						ZVAL_LONG(&vis, 0);
						_79$$17 = zephir_array_isset_long(&k$$14, 0);
						if (_79$$17) {
							zephir_array_fetch_long(&_80$$17, &k$$14, 0, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 447);
							_79$$17 = ZEPHIR_IS_STRING_IDENTICAL(&_80$$17, "\0");
						}
						if (_79$$17) {
							zephir_array_fetch_long(&_81$$18, &k$$14, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 448);
							if (ZEPHIR_IS_STRING_IDENTICAL(&_81$$18, "*")) {
								ZEPHIR_INIT_NVAR(&vis);
								ZVAL_LONG(&vis, 1);
							} else {
								ZEPHIR_INIT_NVAR(&vis);
								ZVAL_LONG(&vis, 2);
							}
							ZEPHIR_INIT_NVAR(&_82$$18);
							ZVAL_STRING(&_82$$18, "\0");
							ZEPHIR_CALL_FUNCTION(&_83$$18, "strrpos", &_69, 120, &k$$14, &_82$$18);
							zephir_check_call_status();
							ZVAL_LONG(&_84$$18, (zephir_get_numberval(&_83$$18) + 1));
							ZEPHIR_INIT_NVAR(&_82$$18);
							zephir_substr(&_82$$18, &k$$14, zephir_get_intval(&_84$$18), 0, ZEPHIR_SUBSTR_NO_LENGTH);
							ZEPHIR_CPY_WRT(&k$$14, &_82$$18);
						}
						_85$$17 = Z_TYPE_P(&k$$14) == IS_STRING;
						if (_85$$17) {
							zephir_read_property(&_86$$17, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_INIT_NVAR(&_87$$17);
							zephir_fast_strtolower(&_87$$17, &k$$14);
							_85$$17 = zephir_array_isset(&_86$$17, &_87$$17);
						}
						ZEPHIR_INIT_NVAR(&hide);
						ZVAL_BOOL(&hide, _85$$17);
						ZEPHIR_INIT_NVAR(&_88$$17);
						zephir_create_array(&_88$$17, 3, 0);
						ZEPHIR_CALL_METHOD(&_89$$17, this_ptr, "encodekey", &_26, 114, &k$$14);
						zephir_check_call_status();
						zephir_array_fast_append(&_88$$17, &_89$$17);
						ZEPHIR_INIT_NVAR(&_90$$17);
						if (zephir_is_true(&hide)) {
							ZEPHIR_INIT_NVAR(&_91$$17);
							zephir_create_array(&_91$$17, 1, 0);
							ZEPHIR_CALL_SELF(&_89$$17, "hidevalue", &_29, 115, &v$$14);
							zephir_check_call_status();
							zephir_array_update_string(&_91$$17, SL("type"), &_89$$17, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&_90$$17, &_91$$17);
						} else {
							ZVAL_LONG(&_92$$17, (level + 1));
							ZEPHIR_CALL_METHOD(&_90$$17, this_ptr, "tojson", &_31, 107, &v$$14, &options, &_92$$17);
							zephir_check_call_status();
						}
						zephir_array_fast_append(&_88$$17, &_90$$17);
						zephir_array_fast_append(&_88$$17, &vis);
						zephir_array_update_multi(&obj, &_88$$17, SL("sa"), 3, SL("items"));
					ZEPHIR_CALL_METHOD(NULL, &_59$$14, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&v$$14);
			ZEPHIR_INIT_NVAR(&k$$14);
		}
		zephir_create_array(return_value, 1, 0);
		ZEPHIR_OBS_VAR(&_93$$10);
		zephir_array_fetch_string(&_93$$10, &obj, SL("id"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 455);
		zephir_array_update_string(return_value, SL("object"), &_93$$10, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	} else if (Z_TYPE_P(_var) == IS_RESOURCE) {
		zephir_array_fetch_string(&_94$$19, &options, SL("snapshot"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 457);
		ZEPHIR_OBS_NVAR(&obj);
		zephir_get_strval(&_95$$19, _var);
		zephir_array_fetch(&obj, &_94$$19, &_95$$19, PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 457);
		if (!zephir_is_true(&obj)) {
			ZEPHIR_CALL_FUNCTION(&type, "get_resource_type", NULL, 121, _var);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_96$$20);
			zephir_create_array(&_96$$20, 3, 0);
			zephir_array_fetch_string(&_97$$20, &options, SL("snapshot"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 460);
			add_assoc_long_ex(&_96$$20, SL("id"), zephir_fast_count_int(&_97$$20));
			ZEPHIR_INIT_VAR(&_98$$20);
			ZEPHIR_CONCAT_VS(&_98$$20, &type, " resource");
			zephir_array_update_string(&_96$$20, SL("name"), &_98$$20, PH_COPY | PH_SEPARATE);
			add_assoc_long_ex(&_96$$20, SL("hash"), zephir_get_intval(_var));
			ZEPHIR_CPY_WRT(&obj, &_96$$20);
			zephir_read_property(&_99$$20, this_ptr, ZEND_STRL("resourceDumpers"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_99$$20, &type)) {
				zephir_read_property(&_100$$21, this_ptr, ZEND_STRL("resourceDumpers"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_VAR(&dumper$$21);
				zephir_array_fetch(&dumper$$21, &_100$$21, &type, PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 465);
				ZEPHIR_CALL_ZVAL_FUNCTION(&_101$$21, &dumper$$21, NULL, 0, _var);
				zephir_check_call_status();
				zephir_is_iterable(&_101$$21, 0, "moon/Component/ErrorHandler/Dumper.zep", 469);
				if (Z_TYPE_P(&_101$$21) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_101$$21), _104$$21, _105$$21, _102$$21)
					{
						ZEPHIR_INIT_NVAR(&k$$21);
						if (_105$$21 != NULL) { 
							ZVAL_STR_COPY(&k$$21, _105$$21);
						} else {
							ZVAL_LONG(&k$$21, _104$$21);
						}
						ZEPHIR_INIT_NVAR(&v$$21);
						ZVAL_COPY(&v$$21, _102$$21);
						ZEPHIR_INIT_NVAR(&_106$$22);
						zephir_create_array(&_106$$22, 2, 0);
						zephir_array_fast_append(&_106$$22, &k$$21);
						ZVAL_LONG(&_108$$22, (level + 1));
						ZEPHIR_CALL_METHOD(&_107$$22, this_ptr, "tojson", &_31, 107, &v$$21, &options, &_108$$22);
						zephir_check_call_status();
						zephir_array_fast_append(&_106$$22, &_107$$22);
						zephir_array_update_multi(&obj, &_106$$22, SL("sa"), 3, SL("items"));
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_101$$21, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_103$$21, &_101$$21, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_103$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&k$$21, &_101$$21, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&v$$21, &_101$$21, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_109$$23);
							zephir_create_array(&_109$$23, 2, 0);
							zephir_array_fast_append(&_109$$23, &k$$21);
							ZVAL_LONG(&_111$$23, (level + 1));
							ZEPHIR_CALL_METHOD(&_110$$23, this_ptr, "tojson", &_31, 107, &v$$21, &options, &_111$$23);
							zephir_check_call_status();
							zephir_array_fast_append(&_109$$23, &_110$$23);
							zephir_array_update_multi(&obj, &_109$$23, SL("sa"), 3, SL("items"));
						ZEPHIR_CALL_METHOD(NULL, &_101$$21, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&v$$21);
				ZEPHIR_INIT_NVAR(&k$$21);
			}
		}
		zephir_create_array(return_value, 1, 0);
		ZEPHIR_OBS_VAR(&_112$$19);
		zephir_array_fetch_string(&_112$$19, &obj, SL("id"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 471);
		zephir_array_update_string(return_value, SL("resource"), &_112$$19, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	} else {
		zephir_create_array(return_value, 1, 0);
		add_assoc_stringl_ex(return_value, SL("type"), SL("unknown type"));
		RETURN_MM();
	}

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, formatSnapshotAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval snapshot, *snapshot_param = NULL, id, res, obj, *_0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &snapshot_param);

	zephir_get_arrval(&snapshot, snapshot_param);


	ZEPHIR_INIT_VAR(&res);
	array_init(&res);
	zephir_is_iterable(&snapshot, 0, "moon/Component/ErrorHandler/Dumper.zep", 492);
	if (Z_TYPE_P(&snapshot) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&snapshot), _0)
		{
			ZEPHIR_INIT_NVAR(&obj);
			ZVAL_COPY(&obj, _0);
			ZEPHIR_OBS_NVAR(&id);
			zephir_array_fetch_string(&id, &obj, SL("id"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 485);
			zephir_array_unset_string(&obj, SL("level"), PH_SEPARATE);
			zephir_array_unset_string(&obj, SL("object"), PH_SEPARATE);
			zephir_array_unset_string(&obj, SL("id"), PH_SEPARATE);
			zephir_array_update_zval(&res, &id, &obj, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &snapshot, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &snapshot, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&obj, &snapshot, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&id);
				zephir_array_fetch_string(&id, &obj, SL("id"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 485);
				zephir_array_unset_string(&obj, SL("level"), PH_SEPARATE);
				zephir_array_unset_string(&obj, SL("object"), PH_SEPARATE);
				zephir_array_unset_string(&obj, SL("id"), PH_SEPARATE);
				zephir_array_update_zval(&res, &id, &obj, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &snapshot, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&obj);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_3, (4 | 2));
	zephir_json_encode(&_2, &res, zephir_get_intval(&_3) );
	ZEPHIR_CONCAT_SVS(return_value, "'", &_2, "'");
	RETURN_MM();

}

/**
 * @internal
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, encodeString) {

	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_16 = NULL, *_18 = NULL, *_23 = NULL;
	zend_long maxLength, ZEPHIR_LAST_CALL_STATUS;
	zval s, *s_param = NULL, *maxLength_param = NULL, shortened, tmp, _1, _2, _3, _4, _6, _0$$3, table$$5, _34$$5, ch$$6, _7$$6, _8$$6, _9$$6, _10$$6, _12$$6, *_13$$6, _14$$6, _32$$6, _33$$6, _15$$7, _17$$7, _19$$7, _20$$7, _21$$7, _22$$7, _24$$7, _25$$8, _26$$8, _27$$8, _28$$8, _29$$8, _30$$8, _31$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&shortened);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&table$$5);
	ZVAL_UNDEF(&_34$$5);
	ZVAL_UNDEF(&ch$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_32$$6);
	ZVAL_UNDEF(&_33$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &s_param, &maxLength_param);

	zephir_get_strval(&s, s_param);
	if (!maxLength_param) {
		maxLength = 0;
	} else {
		maxLength = zephir_get_intval(maxLength_param);
	}


	ZEPHIR_INIT_VAR(&shortened);
	ZVAL_STRING(&shortened, "");
	if (maxLength) {
		ZEPHIR_CPY_WRT(&tmp, &s);
		ZVAL_LONG(&_0$$3, maxLength);
		ZEPHIR_CALL_SELF(&s, "truncatestring", NULL, 0, &tmp, &_0$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_IDENTICAL(&s, &tmp)) {
			ZEPHIR_INIT_NVAR(&shortened);
			ZVAL_STRING(&shortened, " ...");
		}
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "#[^\\x09\\x0A\\x0D\\x20-\\x7E\\xA0-\\x{10FFFF}]#u");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "#[^\\x09\\x0A\\x0D\\x20-\\x7E\\xA0-\\x{10FFFF}]#u");
	zephir_preg_match(&_3, &_4, &s, &_1, 0, 0 , 0 );
	_5 = zephir_is_true(&_3);
	if (!(_5)) {
		ZEPHIR_CALL_FUNCTION(&_6, "preg_last_error", NULL, 123);
		zephir_check_call_status();
		_5 = zephir_is_true(&_6);
	}
	if (_5) {
		if (Z_TYPE_P(&table$$5) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			ZEPHIR_INIT_VAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "\x00");
			ZEPHIR_INIT_VAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "\x1F");
			ZEPHIR_CALL_FUNCTION(&_10$$6, "range", &_11, 124, &_8$$6, &_9$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "\x7F");
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "\xFF");
			ZEPHIR_CALL_FUNCTION(&_12$$6, "range", &_11, 124, &_8$$6, &_9$$6);
			zephir_check_call_status();
			zephir_fast_array_merge(&_7$$6, &_10$$6, &_12$$6);
			zephir_is_iterable(&_7$$6, 0, "moon/Component/ErrorHandler/Dumper.zep", 519);
			if (Z_TYPE_P(&_7$$6) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_7$$6), _13$$6)
				{
					ZEPHIR_INIT_NVAR(&ch$$6);
					ZVAL_COPY(&ch$$6, _13$$6);
					ZEPHIR_CALL_FUNCTION(&_15$$7, "ord", &_16, 125, &ch$$6);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_17$$7, "dechex", &_18, 126, &_15$$7);
					zephir_check_call_status();
					ZVAL_LONG(&_19$$7, 2);
					ZEPHIR_INIT_NVAR(&_20$$7);
					ZVAL_STRING(&_20$$7, "0");
					ZVAL_LONG(&_21$$7, 0);
					ZEPHIR_CALL_FUNCTION(&_22$$7, "str_pad", &_23, 127, &_17$$7, &_19$$7, &_20$$7, &_21$$7);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_24$$7);
					ZEPHIR_CONCAT_SV(&_24$$7, "\\x", &_22$$7);
					zephir_array_update_zval(&table$$5, &ch$$6, &_24$$7, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_7$$6, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_14$$6, &_7$$6, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_14$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&ch$$6, &_7$$6, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_25$$8, "ord", &_16, 125, &ch$$6);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_26$$8, "dechex", &_18, 126, &_25$$8);
						zephir_check_call_status();
						ZVAL_LONG(&_27$$8, 2);
						ZEPHIR_INIT_NVAR(&_28$$8);
						ZVAL_STRING(&_28$$8, "0");
						ZVAL_LONG(&_29$$8, 0);
						ZEPHIR_CALL_FUNCTION(&_30$$8, "str_pad", &_23, 127, &_26$$8, &_27$$8, &_28$$8, &_29$$8);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_31$$8);
						ZEPHIR_CONCAT_SV(&_31$$8, "\\x", &_30$$8);
						zephir_array_update_zval(&table$$5, &ch$$6, &_31$$8, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(NULL, &_7$$6, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&ch$$6);
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_STRING(&_8$$6, "\\\\");
			zephir_array_update_string(&table$$5, SL("\\"), &_8$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "\\r");
			zephir_array_update_string(&table$$5, SL("\r"), &_9$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_32$$6);
			ZVAL_STRING(&_32$$6, "\\n");
			zephir_array_update_string(&table$$5, SL("\n"), &_32$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_33$$6);
			ZVAL_STRING(&_33$$6, "\\t");
			zephir_array_update_string(&table$$5, SL("\t"), &_33$$6, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_CALL_FUNCTION(&_34$$5, "strtr", NULL, 128, &s, &table$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&s, &_34$$5);
	}
	ZEPHIR_CONCAT_VV(return_value, &s, &shortened);
	RETURN_MM();

}

/**
 * @internal
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, truncateString) {

	zend_bool _16$$6, _20$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long maxLength, ZEPHIR_LAST_CALL_STATUS, len = 0, i = 0;
	zval s, *s_param = NULL, *maxLength_param = NULL, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3, _7$$4, _8$$4, _9$$4, _10$$4, _11$$6, _12$$6, _14$$6, _15$$6, _17$$6, _18$$6, _19$$6, _21$$7, _22$$7, _23$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &s_param, &maxLength_param);

	zephir_get_strval(&s, s_param);
	maxLength = zephir_get_intval(maxLength_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "##u");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "##u");
	zephir_preg_match(&_2, &_3, &s, &_0, 0, 0 , 0 );
	if (!zephir_is_true(&_2)) {
		ZVAL_LONG(&_4$$3, 0);
		ZVAL_LONG(&_5$$3, maxLength);
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_substr(&_6$$3, &s, 0 , zephir_get_intval(&_5$$3), 0);
		ZEPHIR_CPY_WRT(&s, &_6$$3);
	} else if ((zephir_function_exists_ex(ZEND_STRL("mb_substr")) == SUCCESS)) {
		ZVAL_LONG(&_7$$4, 0);
		ZVAL_LONG(&_8$$4, maxLength);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "UTF-8");
		ZEPHIR_CALL_FUNCTION(&_10$$4, "mb_substr", NULL, 129, &s, &_7$$4, &_8$$4, &_9$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&s, &_10$$4);
	} else {
		i = 0;
		len = 0;
		while (1) {
			if (!(zephir_array_isset_long(&s, i))) {
				break;
			}
			len += 1;
			zephir_array_fetch_long(&_11$$6, &s, i, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 547);
			ZEPHIR_CALL_FUNCTION(&_12$$6, "ord", &_13, 125, &_11$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_14$$6);
			ZVAL_STRING(&_14$$6, "\x80");
			ZEPHIR_CALL_FUNCTION(&_15$$6, "ord", &_13, 125, &_14$$6);
			zephir_check_call_status();
			_16$$6 = ZEPHIR_LT(&_12$$6, &_15$$6);
			if (!(_16$$6)) {
				zephir_array_fetch_long(&_17$$6, &s, i, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 547);
				ZEPHIR_CALL_FUNCTION(&_18$$6, "ord", &_13, 125, &_17$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$6);
				ZVAL_STRING(&_14$$6, "\xC0");
				ZEPHIR_CALL_FUNCTION(&_19$$6, "ord", &_13, 125, &_14$$6);
				zephir_check_call_status();
				_16$$6 = ZEPHIR_GE(&_18$$6, &_19$$6);
			}
			_20$$6 = _16$$6;
			if (_20$$6) {
				_20$$6 = len > maxLength;
			}
			if (_20$$6) {
				ZVAL_LONG(&_21$$7, 0);
				ZVAL_LONG(&_22$$7, i);
				ZEPHIR_INIT_NVAR(&_23$$7);
				zephir_substr(&_23$$7, &s, 0 , zephir_get_intval(&_22$$7), 0);
				ZEPHIR_CPY_WRT(&s, &_23$$7);
				break;
			}
			i += 1;
		}
	}
	RETURN_CCTOR(&s);

}

/**
 * @param $key
 * @return int|string
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, encodeKey) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, _0, _2, _3, _4, _5, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_INIT_VAR(&_0);
	_1 = Z_TYPE_P(key) == IS_LONG;
	if (!(_1)) {
		ZEPHIR_INIT_VAR(&_2);
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "#^[!\\#$%&()*+,./0-9:;<=>?@A-Z[\\]^_`a-z{|}~-]{1,50}$#D");
		ZEPHIR_INIT_VAR(&_4);
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "#^[!\\#$%&()*+,./0-9:;<=>?@A-Z[\\]^_`a-z{|}~-]{1,50}$#D");
		zephir_preg_match(&_4, &_5, key, &_2, 0, 0 , 0 );
		_1 = zephir_is_true(&_4);
	}
	if (_1) {
		ZEPHIR_CPY_WRT(&_0, key);
	} else {
		zephir_read_property(&_7, this_ptr, ZEND_STRL("maxLength"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "encodestring", NULL, 0, key, &_7);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(&_0, "\"", &_6, "\"");
	}
	RETURN_CCTOR(&_0);

}

/**
 * @param $obj
 * @return array
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, exportObject) {

	zval _9;
	zend_bool _8, _5$$3, _6$$5;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *obj, obj_sub, type, dumper, _0, *_1, _2, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&obj_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&dumper);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("objectDumpers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "moon/Component/ErrorHandler/Dumper.zep", 579);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&type);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&type, _4);
			} else {
				ZVAL_LONG(&type, _3);
			}
			ZEPHIR_INIT_NVAR(&dumper);
			ZVAL_COPY(&dumper, _1);
			_5$$3 = !zephir_is_true(&type);
			if (!(_5$$3)) {
				_5$$3 = zephir_is_instance_of(obj, Z_STRVAL_P(&type), Z_STRLEN_P(&type));
			}
			if (_5$$3) {
				ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&dumper, NULL, 0, obj);
				zephir_check_call_status();
				RETURN_MM();
			}
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
			ZEPHIR_CALL_METHOD(&type, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&dumper, &_0, "current", NULL, 0);
			zephir_check_call_status();
				_6$$5 = !zephir_is_true(&type);
				if (!(_6$$5)) {
					_6$$5 = zephir_is_instance_of(obj, Z_STRVAL_P(&type), Z_STRLEN_P(&type));
				}
				if (_6$$5) {
					ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&dumper, NULL, 0, obj);
					zephir_check_call_status();
					RETURN_MM();
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&dumper);
	ZEPHIR_INIT_NVAR(&type);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("debugInfo"), PH_NOISY_CC | PH_READONLY);
	_8 = zephir_is_true(&_7);
	if (_8) {
		_8 = (zephir_method_exists_ex(obj, ZEND_STRL("__debuginfo")) == SUCCESS);
	}
	if (_8) {
		ZEPHIR_RETURN_CALL_METHOD(obj, "__debuginfo", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_get_arrval(&_9, obj);
	RETURN_CTOR(&_9);

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, exportClosure) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *obj, obj_sub, res, rc, param, _0, *_1, _2, _7, _8, _3$$3, _4$$3, _5$$4, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&obj_sub);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&rc);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);



	ZEPHIR_INIT_VAR(&rc);
	object_init_ex(&rc, zephir_get_internal_ce(SL("reflectionfunction")));
	ZEPHIR_CALL_METHOD(NULL, &rc, "__construct", NULL, 26, obj);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&res);
	array_init(&res);
	ZEPHIR_CALL_METHOD(&_0, &rc, "getparameters", NULL, 27);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "moon/Component/ErrorHandler/Dumper.zep", 595);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&param);
			ZVAL_COPY(&param, _1);
			ZEPHIR_CALL_METHOD(&_3$$3, &param, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZEPHIR_CONCAT_SV(&_4$$3, "$", &_3$$3);
			zephir_array_append(&res, &_4$$3, PH_SEPARATE, "moon/Component/ErrorHandler/Dumper.zep", 593);
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
			ZEPHIR_CALL_METHOD(&param, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$4, &param, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZEPHIR_CONCAT_SV(&_6$$4, "$", &_5$$4);
				zephir_array_append(&res, &_6$$4, PH_SEPARATE, "moon/Component/ErrorHandler/Dumper.zep", 593);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&param);
	zephir_create_array(return_value, 4, 0);
	ZEPHIR_CALL_METHOD(&_7, &rc, "getfilename", NULL, 130);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("file"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_7, &rc, "getstartline", NULL, 131);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("line"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_7, &rc, "getstaticvariables", NULL, 132);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("variables"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_8);
	zephir_fast_join_str(&_8, SL(", "), &res);
	zephir_array_update_string(return_value, SL("parameters"), &_8, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, exportSplFileInfo) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *obj, obj_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&obj_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);



	zephir_create_array(return_value, 1, 0);
	ZEPHIR_CALL_METHOD(&_0, obj, "getpathname", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("path"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, exportSplObjectStorage) {

	zval res, _3$$3, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *obj, obj_sub, item, _0, *_1, _2, _4$$3, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&obj_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);



	ZEPHIR_INIT_VAR(&res);
	array_init(&res);
	ZEPHIR_INIT_VAR(&_0);
	if (zephir_clone(&_0, obj) == FAILURE) {
		RETURN_MM();
	}
	zephir_is_iterable(&_0, 0, "moon/Component/ErrorHandler/Dumper.zep", 610);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1);
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_create_array(&_3$$3, 2, 0);
			zephir_array_update_string(&_3$$3, SL("object"), &item, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_4$$3, obj, "offsetget", &_5, 0, &item);
			zephir_check_call_status();
			zephir_array_update_string(&_3$$3, SL("data"), &_4$$3, PH_COPY | PH_SEPARATE);
			zephir_array_append(&res, &_3$$3, PH_SEPARATE, "moon/Component/ErrorHandler/Dumper.zep", 608);
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
			ZEPHIR_CALL_METHOD(&item, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_create_array(&_6$$4, 2, 0);
				zephir_array_update_string(&_6$$4, SL("object"), &item, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_7$$4, obj, "offsetget", &_5, 0, &item);
				zephir_check_call_status();
				zephir_array_update_string(&_6$$4, SL("data"), &_7$$4, PH_COPY | PH_SEPARATE);
				zephir_array_append(&res, &_6$$4, PH_SEPARATE, "moon/Component/ErrorHandler/Dumper.zep", 608);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CTOR(&res);

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, exportPhpIncompleteClass) {

	zend_string *_5;
	zend_ulong _4;
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *obj, obj_sub, __$null, info, _0, name, value, m, *_2, _3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$5, _13$$6, _14$$6, _15$$6, _16$$8, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8, _22$$10, _23$$11, _24$$11, _25$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&obj_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);



	ZEPHIR_INIT_VAR(&info);
	zephir_create_array(&info, 4, 0);
	zephir_array_update_string(&info, SL("className"), &__$null, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&info, SL("private"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&info, SL("protected"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&info, SL("public"), &_0, PH_COPY | PH_SEPARATE);
	zephir_get_arrval(&_1, obj);
	zephir_is_iterable(&_1, 0, "moon/Component/ErrorHandler/Dumper.zep", 631);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&name, _5);
			} else {
				ZVAL_LONG(&name, _4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZVAL_STRING(&_6$$3, "#^\\x0\\*\\x0(.+)$#D");
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "#^\\x0\\*\\x0(.+)$#D");
			zephir_preg_match(&_7$$3, &_8$$3, &name, &m, 0, 0 , 0 );
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "#^\\x0(.+)\\x0(.+)$#D");
			ZEPHIR_INIT_NVAR(&_10$$3);
			ZEPHIR_INIT_NVAR(&_11$$3);
			ZVAL_STRING(&_11$$3, "#^\\x0(.+)\\x0(.+)$#D");
			zephir_preg_match(&_10$$3, &_11$$3, &name, &m, 0, 0 , 0 );
			if (ZEPHIR_IS_STRING_IDENTICAL(&name, "__PHP_Incomplete_Class_Name")) {
				zephir_array_update_string(&info, SL("className"), &value, PH_COPY | PH_SEPARATE);
			} else if (zephir_is_true(&_7$$3)) {
				zephir_array_fetch_long(&_12$$5, &m, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 624);
				zephir_array_update_multi(&info, &value, SL("sz"), 3, SL("protected"), &_12$$5);
			} else if (zephir_is_true(&_10$$3)) {
				zephir_array_fetch_long(&_13$$6, &m, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 626);
				zephir_array_fetch_long(&_14$$6, &m, 2, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 626);
				ZEPHIR_INIT_NVAR(&_15$$6);
				ZEPHIR_CONCAT_VSV(&_15$$6, &_13$$6, "::$", &_14$$6);
				zephir_array_update_multi(&info, &value, SL("sz"), 3, SL("private"), &_15$$6);
			} else {
				zephir_array_update_multi(&info, &value, SL("sz"), 3, SL("public"), &name);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &_1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$8);
				ZVAL_STRING(&_16$$8, "#^\\x0\\*\\x0(.+)$#D");
				ZEPHIR_INIT_NVAR(&_17$$8);
				ZEPHIR_INIT_NVAR(&_18$$8);
				ZVAL_STRING(&_18$$8, "#^\\x0\\*\\x0(.+)$#D");
				zephir_preg_match(&_17$$8, &_18$$8, &name, &m, 0, 0 , 0 );
				ZEPHIR_INIT_NVAR(&_19$$8);
				ZVAL_STRING(&_19$$8, "#^\\x0(.+)\\x0(.+)$#D");
				ZEPHIR_INIT_NVAR(&_20$$8);
				ZEPHIR_INIT_NVAR(&_21$$8);
				ZVAL_STRING(&_21$$8, "#^\\x0(.+)\\x0(.+)$#D");
				zephir_preg_match(&_20$$8, &_21$$8, &name, &m, 0, 0 , 0 );
				if (ZEPHIR_IS_STRING_IDENTICAL(&name, "__PHP_Incomplete_Class_Name")) {
					zephir_array_update_string(&info, SL("className"), &value, PH_COPY | PH_SEPARATE);
				} else if (zephir_is_true(&_17$$8)) {
					zephir_array_fetch_long(&_22$$10, &m, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 624);
					zephir_array_update_multi(&info, &value, SL("sz"), 3, SL("protected"), &_22$$10);
				} else if (zephir_is_true(&_20$$8)) {
					zephir_array_fetch_long(&_23$$11, &m, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 626);
					zephir_array_fetch_long(&_24$$11, &m, 2, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 626);
					ZEPHIR_INIT_NVAR(&_25$$11);
					ZEPHIR_CONCAT_VSV(&_25$$11, &_23$$11, "::$", &_24$$11);
					zephir_array_update_multi(&info, &value, SL("sz"), 3, SL("private"), &_25$$11);
				} else {
					zephir_array_update_multi(&info, &value, SL("sz"), 3, SL("public"), &name);
				}
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&info);

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, hideValue) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *_var, _var_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_var);



	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(_var) == IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&_0, moon_component_errorhandler_helpers_ce, "getclass", &_1, 0, _var);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_gettype(&_0, _var);
	}
	ZEPHIR_CONCAT_SSVS(return_value, "*****", " (", &_0, ")");
	RETURN_MM();

}

/**
 * Finds the location where dump was called. Returns [file, line, code]
 */
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, findLocation) {

	zval _17$$6, _31$$12;
	zend_bool _36, _37, _4$$3, _13$$6, _22$$9, _28$$12;
	zval line, lines, reflection, location, item, m, _0, _1, *_2, _3, _38, _39, _5$$3, e$$5, _21$$5, _6$$6, _7$$6, _9$$6, _11$$6, _14$$6, _15$$6, _18$$6, _19$$6, _20$$6, _23$$9, e$$11, _35$$11, _24$$12, _25$$12, _26$$12, _27$$12, _29$$12, _30$$12, _32$$12, _33$$12, _34$$12, _40$$15, _41$$15, _42$$15, _43$$15, _44$$15, _45$$15, _46$$15, _47$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL, *_12 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&e$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&e$$11);
	ZVAL_UNDEF(&_35$$11);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_40$$15);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_42$$15);
	ZVAL_UNDEF(&_43$$15);
	ZVAL_UNDEF(&_44$$15);
	ZVAL_UNDEF(&_45$$15);
	ZVAL_UNDEF(&_46$$15);
	ZVAL_UNDEF(&_47$$15);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_31$$12);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&_1, "debug_backtrace", NULL, 14, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "moon/Component/ErrorHandler/Dumper.zep", 667);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _2);
			_4$$3 = zephir_array_isset_string(&item, SL("class"));
			if (_4$$3) {
				zephir_array_fetch_string(&_5$$3, &item, SL("class"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 651);
				_4$$3 = ZEPHIR_IS_STRING_IDENTICAL(&_5$$3, "Moon\\Component\\ErrorHandler\\Dumper");
			}
			if (_4$$3) {
				ZEPHIR_CPY_WRT(&location, &item);
				continue;
			} else if (zephir_array_isset_string(&item, SL("function"))) {

				/* try_start_1: */

					if (zephir_array_isset_string(&item, SL("class"))) {
						ZEPHIR_INIT_NVAR(&reflection);
						object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionmethod")));
						zephir_array_fetch_string(&_6$$6, &item, SL("class"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 657);
						zephir_array_fetch_string(&_7$$6, &item, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 657);
						ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", &_8, 31, &_6$$6, &_7$$6);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						ZEPHIR_INIT_NVAR(&reflection);
						object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
						zephir_array_fetch_string(&_9$$6, &item, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 657);
						ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", &_10, 26, &_9$$6);
						zephir_check_call_status_or_jump(try_end_1);
					}
					ZEPHIR_CALL_METHOD(&_11$$6, &reflection, "isinternal", &_12, 133);
					zephir_check_call_status_or_jump(try_end_1);
					_13$$6 = zephir_is_true(&_11$$6);
					if (!(_13$$6)) {
						ZEPHIR_INIT_NVAR(&_14$$6);
						ZEPHIR_CALL_METHOD(&_15$$6, &reflection, "getdoccomment", &_16, 134);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_get_strval(&_17$$6, &_15$$6);
						ZEPHIR_INIT_NVAR(&_18$$6);
						ZVAL_STRING(&_18$$6, "#\\s@tracySkipLocation\\s#");
						ZEPHIR_INIT_NVAR(&_19$$6);
						ZEPHIR_INIT_NVAR(&_20$$6);
						ZVAL_STRING(&_20$$6, "#\\s@tracySkipLocation\\s#");
						zephir_preg_match(&_19$$6, &_20$$6, &_17$$6, &_14$$6, 0, 0 , 0 );
						_13$$6 = zephir_is_true(&_19$$6);
					}
					if (_13$$6) {
						ZEPHIR_CPY_WRT(&location, &item);
						continue;
					}

				try_end_1:

				if (EG(exception)) {
					ZEPHIR_INIT_NVAR(&_21$$5);
					ZVAL_OBJ(&_21$$5, EG(exception));
					Z_ADDREF_P(&_21$$5);
					if (zephir_instance_of_ev(&_21$$5, zephir_get_internal_ce(SL("reflectionexception")))) {
						zend_clear_exception(TSRMLS_C);
						ZEPHIR_CPY_WRT(&e$$5, &_21$$5);
					}
				}
			}
			break;
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &_1, "current", NULL, 0);
			zephir_check_call_status();
				_22$$9 = zephir_array_isset_string(&item, SL("class"));
				if (_22$$9) {
					zephir_array_fetch_string(&_23$$9, &item, SL("class"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 651);
					_22$$9 = ZEPHIR_IS_STRING_IDENTICAL(&_23$$9, "Moon\\Component\\ErrorHandler\\Dumper");
				}
				if (_22$$9) {
					ZEPHIR_CPY_WRT(&location, &item);
					continue;
				} else if (zephir_array_isset_string(&item, SL("function"))) {

					/* try_start_2: */

						if (zephir_array_isset_string(&item, SL("class"))) {
							ZEPHIR_INIT_NVAR(&reflection);
							object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionmethod")));
							zephir_array_fetch_string(&_24$$12, &item, SL("class"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 657);
							zephir_array_fetch_string(&_25$$12, &item, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 657);
							ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", &_10, 26, &_24$$12, &_25$$12);
							zephir_check_call_status_or_jump(try_end_2);
						} else {
							ZEPHIR_INIT_NVAR(&reflection);
							object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
							zephir_array_fetch_string(&_26$$12, &item, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 657);
							ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", &_10, 26, &_26$$12);
							zephir_check_call_status_or_jump(try_end_2);
						}
						ZEPHIR_CALL_METHOD(&_27$$12, &reflection, "isinternal", &_12, 133);
						zephir_check_call_status_or_jump(try_end_2);
						_28$$12 = zephir_is_true(&_27$$12);
						if (!(_28$$12)) {
							ZEPHIR_INIT_NVAR(&_29$$12);
							ZEPHIR_CALL_METHOD(&_30$$12, &reflection, "getdoccomment", &_16, 134);
							zephir_check_call_status_or_jump(try_end_2);
							zephir_get_strval(&_31$$12, &_30$$12);
							ZEPHIR_INIT_NVAR(&_32$$12);
							ZVAL_STRING(&_32$$12, "#\\s@tracySkipLocation\\s#");
							ZEPHIR_INIT_NVAR(&_33$$12);
							ZEPHIR_INIT_NVAR(&_34$$12);
							ZVAL_STRING(&_34$$12, "#\\s@tracySkipLocation\\s#");
							zephir_preg_match(&_33$$12, &_34$$12, &_31$$12, &_29$$12, 0, 0 , 0 );
							_28$$12 = zephir_is_true(&_33$$12);
						}
						if (_28$$12) {
							ZEPHIR_CPY_WRT(&location, &item);
							continue;
						}

					try_end_2:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_35$$11);
						ZVAL_OBJ(&_35$$11, EG(exception));
						Z_ADDREF_P(&_35$$11);
						if (zephir_instance_of_ev(&_35$$11, zephir_get_internal_ce(SL("reflectionexception")))) {
							zend_clear_exception(TSRMLS_C);
							ZEPHIR_CPY_WRT(&e$$11, &_35$$11);
						}
					}
				}
				break;
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	_36 = zephir_array_isset_string(&location, SL("file"));
	if (_36) {
		_36 = zephir_array_isset_string(&location, SL("line"));
	}
	_37 = _36;
	if (_37) {
		zephir_array_fetch_string(&_38, &location, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 667);
		ZEPHIR_CALL_FUNCTION(&_39, "is_file", NULL, 73, &_38);
		zephir_check_call_status();
		_37 = zephir_is_true(&_39);
	}
	if (_37) {
		zephir_array_fetch_string(&_40$$15, &location, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 668);
		ZEPHIR_CALL_FUNCTION(&lines, "file", NULL, 135, &_40$$15);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&line);
		zephir_array_fetch_string(&_41$$15, &location, SL("line"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Dumper.zep", 669);
		zephir_array_fetch_long(&line, &lines, (zephir_get_numberval(&_41$$15) - 1), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 669);
		zephir_create_array(return_value, 3, 0);
		ZEPHIR_OBS_VAR(&_42$$15);
		zephir_array_fetch_string(&_42$$15, &location, SL("file"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 670);
		zephir_array_fast_append(return_value, &_42$$15);
		ZEPHIR_OBS_NVAR(&_42$$15);
		zephir_array_fetch_string(&_42$$15, &location, SL("line"), PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 670);
		zephir_array_fast_append(return_value, &_42$$15);
		ZEPHIR_INIT_VAR(&_43$$15);
		ZEPHIR_INIT_VAR(&_44$$15);
		ZEPHIR_INIT_VAR(&_45$$15);
		ZVAL_STRING(&_45$$15, "#\\w*dump(er::\\w+)?\\(.*\\)#i");
		ZEPHIR_INIT_VAR(&_46$$15);
		ZEPHIR_INIT_VAR(&_47$$15);
		ZVAL_STRING(&_47$$15, "#\\w*dump(er::\\w+)?\\(.*\\)#i");
		zephir_preg_match(&_46$$15, &_47$$15, &line, &m, 0, 0 , 0 );
		if (zephir_is_true(&_46$$15)) {
			ZEPHIR_OBS_NVAR(&_44$$15);
			zephir_array_fetch_long(&_44$$15, &m, 0, PH_NOISY, "moon/Component/ErrorHandler/Dumper.zep", 670);
		} else {
			ZEPHIR_CPY_WRT(&_44$$15, &line);
		}
		zephir_fast_trim(&_43$$15, &_44$$15, NULL , ZEPHIR_TRIM_BOTH);
		zephir_array_fast_append(return_value, &_43$$15);
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, detectColors) {

	zend_bool _1, _5, _7, _9, _11, _12;
	zval _0, _2, _3, _6, _8, _10, _13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_13);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, moon_component_errorhandler_dumper_ce, SL("terminalColors"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "ConEmuANSI");
		ZEPHIR_CALL_FUNCTION(&_3, "getenv", &_4, 136, &_2);
		zephir_check_call_status();
		_5 = ZEPHIR_IS_STRING_IDENTICAL(&_3, "ON");
		if (!(_5)) {
			ZEPHIR_INIT_NVAR(&_2);
			ZVAL_STRING(&_2, "ANSICON");
			ZEPHIR_CALL_FUNCTION(&_6, "getenv", &_4, 136, &_2);
			zephir_check_call_status();
			_5 = !ZEPHIR_IS_FALSE_IDENTICAL(&_6);
		}
		_7 = _5;
		if (!(_7)) {
			ZEPHIR_INIT_NVAR(&_2);
			ZVAL_STRING(&_2, "term");
			ZEPHIR_CALL_FUNCTION(&_8, "getenv", &_4, 136, &_2);
			zephir_check_call_status();
			_7 = ZEPHIR_IS_STRING_IDENTICAL(&_8, "xterm-256color");
		}
		_9 = _7;
		if (!(_9)) {
			ZEPHIR_INIT_NVAR(&_2);
			ZVAL_STRING(&_2, "STDOUT");
			ZEPHIR_CALL_FUNCTION(&_10, "defined", NULL, 137, &_2);
			zephir_check_call_status();
			_11 = zephir_is_true(&_10);
			if (_11) {
				_11 = (zephir_function_exists_ex(ZEND_STRL("posix_isatty")) == SUCCESS);
			}
			_12 = _11;
			if (_12) {
				ZEPHIR_INIT_NVAR(&_2);
				ZEPHIR_GET_CONSTANT(&_2, "STDOUT");
				ZEPHIR_CALL_FUNCTION(&_13, "posix_isatty", NULL, 138, &_2);
				zephir_check_call_status();
				_12 = zephir_is_true(&_13);
			}
			_9 = _12;
		}
		_1 = _9;
	}
	RETURN_MM_BOOL(_1);

}

void zephir_init_static_properties_Moon_Component_ErrorHandler_Dumper(TSRMLS_D) {

	zval _2;
	zval _0, _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Moon\\Component\\ErrorHandler\\Dumper");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "exportClosure");
	zephir_array_fast_append(&_1, &_2);
	zephir_array_update_string(&_0, SL("Closure"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Moon\\Component\\ErrorHandler\\Dumper");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "exportSplFileInfo");
	zephir_array_fast_append(&_1, &_2);
	zephir_array_update_string(&_0, SL("SplFileInfo"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Moon\\Component\\ErrorHandler\\Dumper");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "exportSplObjectStorage");
	zephir_array_fast_append(&_1, &_2);
	zephir_array_update_string(&_0, SL("SplObjectStorage"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Moon\\Component\\ErrorHandler\\Dumper");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "exportPhpIncompleteClass");
	zephir_array_fast_append(&_1, &_2);
	zephir_array_update_string(&_0, SL("__PHP_Incomplete_Class"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(moon_component_errorhandler_dumper_ce, ZEND_STRL("objectExporters"), &_0);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_array(&_1, 3, 0);
	add_assoc_stringl_ex(&_1, SL("stream"), SL("stream_get_meta_data"));
	add_assoc_stringl_ex(&_1, SL("stream-context"), SL("stream_context_get_options"));
	add_assoc_stringl_ex(&_1, SL("curl"), SL("curl_getinfo"));
	zephir_update_static_property_ce(moon_component_errorhandler_dumper_ce, ZEND_STRL("resources"), &_1);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 10, 0);
	add_assoc_stringl_ex(&_3, SL("bool"), SL("1;33"));
	add_assoc_stringl_ex(&_3, SL("null"), SL("1;33"));
	add_assoc_stringl_ex(&_3, SL("number"), SL("1;32"));
	add_assoc_stringl_ex(&_3, SL("string"), SL("1;36"));
	add_assoc_stringl_ex(&_3, SL("array"), SL("1;31"));
	add_assoc_stringl_ex(&_3, SL("key"), SL("1;37"));
	add_assoc_stringl_ex(&_3, SL("object"), SL("1;31"));
	add_assoc_stringl_ex(&_3, SL("visibility"), SL("1;30"));
	add_assoc_stringl_ex(&_3, SL("resource"), SL("1;37"));
	add_assoc_stringl_ex(&_3, SL("indent"), SL("1;30"));
	zephir_update_static_property_ce(moon_component_errorhandler_dumper_ce, ZEND_STRL("terminalColors"), &_3);
	ZEPHIR_INIT_NVAR(&_2);
	array_init(&_2);
	zephir_update_static_property_ce(moon_component_errorhandler_dumper_ce, ZEND_STRL("liveSnapshot"), &_2);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Moon_Component_ErrorHandler_Dumper(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keysToHide"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

