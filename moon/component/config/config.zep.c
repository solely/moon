
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * FileName: Config.php
 * User: solely
 * DateTime: 2019/10/6 11:39
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Config_Config) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Config, Config, moon, component_config_config, moon_component_config_config_method_entry, 0);

	zend_declare_property_null(moon_component_config_config_ce, SL("data"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_config_config_ce, SL("configDir"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_config_config_ce, SL("instance"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	moon_component_config_config_ce->create_object = zephir_init_properties_Moon_Component_Config_Config;
	return SUCCESS;

}

PHP_METHOD(Moon_Component_Config_Config, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dir = NULL, dir_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dir_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dir);

	if (!dir) {
		dir = &dir_sub;
		dir = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("configDir"), dir);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("configDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loaddir", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Config_Config, loadDir) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_13 = NULL, *_15 = NULL;
	zval *dir = NULL, dir_sub, __$null, pattern, e, ext, d, _0, _1$$3, item$$3, *_3$$3, _4$$3, _9$$3, _10$$3, _11$$3, _12$$3, _14$$3, _16$$3, _5$$4, _6$$4, _7$$5, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dir_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&d);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&item$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dir);

	if (!dir) {
		dir = &dir_sub;
		dir = &__$null;
	}


	if (!(ZEPHIR_IS_EMPTY(dir))) {
		ZEPHIR_CPY_WRT(&d, dir);
	} else {
		ZEPHIR_OBS_VAR(&_0);
		zephir_read_property(&_0, this_ptr, ZEND_STRL("configDir"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(&_0))) {
			ZEPHIR_OBS_NVAR(&d);
			zephir_read_property(&d, this_ptr, ZEND_STRL("configDir"), PH_NOISY_CC);
		} else {
			ZEPHIR_INIT_NVAR(&d);
			ZVAL_NULL(&d);
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&d))) {
		ZEPHIR_CALL_CE_STATIC(&_1$$3, moon_component_config_parser_parserfactory_ce, "getparserclass", &_2, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&ext);
		zephir_array_keys(&ext, &_1$$3);
		ZEPHIR_INIT_VAR(&e);
		array_init(&e);
		zephir_is_iterable(&ext, 0, "moon/Component/Config/Config.zep", 37);
		if (Z_TYPE_P(&ext) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&ext), _3$$3)
			{
				ZEPHIR_INIT_NVAR(&item$$3);
				ZVAL_COPY(&item$$3, _3$$3);
				ZEPHIR_INIT_NVAR(&_5$$4);
				zephir_fast_strtolower(&_5$$4, &item$$3);
				zephir_array_append(&e, &_5$$4, PH_SEPARATE, "moon/Component/Config/Config.zep", 34);
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_fast_strtoupper(&_6$$4, &item$$3);
				zephir_array_append(&e, &_6$$4, PH_SEPARATE, "moon/Component/Config/Config.zep", 35);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &ext, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$3, &ext, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&item$$3, &ext, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_7$$5);
					zephir_fast_strtolower(&_7$$5, &item$$3);
					zephir_array_append(&e, &_7$$5, PH_SEPARATE, "moon/Component/Config/Config.zep", 34);
					ZEPHIR_INIT_NVAR(&_8$$5);
					zephir_fast_strtoupper(&_8$$5, &item$$3);
					zephir_array_append(&e, &_8$$5, PH_SEPARATE, "moon/Component/Config/Config.zep", 35);
				ZEPHIR_CALL_METHOD(NULL, &ext, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&item$$3);
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_fast_join_str(&_9$$3, SL(","), &e);
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "%s/*.{%s}");
		ZEPHIR_CALL_FUNCTION(&pattern, "sprintf", NULL, 3, &_10$$3, dir, &_9$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_10$$3);
		zephir_read_property(&_11$$3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_16$$3, 1024);
		ZEPHIR_CALL_CE_STATIC(&_14$$3, moon_component_config_reader_loader_ce, "glob", &_15, 0, &pattern, &_16$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_12$$3, moon_component_config_parser_parserfactory_ce, "parsefile", &_13, 0, &_14$$3);
		zephir_check_call_status();
		zephir_fast_array_merge(&_10$$3, &_11$$3, &_12$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_10$$3);
	}
	RETURN_THIS();

}

PHP_METHOD(Moon_Component_Config_Config, loadFiles) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *files, files_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &files);



	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_2, moon_component_config_parser_parserfactory_ce, "parsefile", &_3, 0, files);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_0);
	RETURN_THIS();

}

PHP_METHOD(Moon_Component_Config_Config, loadString) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *configStringArr_param = NULL, _0, _1, _2;
	zval configStringArr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configStringArr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configStringArr_param);

	zephir_get_arrval(&configStringArr, configStringArr_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_2, moon_component_config_parser_parserfactory_ce, "parsestring", &_3, 0, &configStringArr);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_0);
	RETURN_THIS();

}

/**
 * 当 $key 为 空字符串 时，返回所有的配置项
 * 支持取多级配置项的值，以 . 号拼接成字符串传入；如： $config->get('aa.bb.cc.dd.ee');
 * @param string $key
 * @param null $default
 * @return array|mixed
 */
PHP_METHOD(Moon_Component_Config_Config, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_default = NULL, _default_sub, __$null, config, keysArr, item, *_0, _1, _2$$5, _3$$7;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_default_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&keysArr);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &_default);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!_default) {
		_default = &_default_sub;
		_default = &__$null;
	}


	if (ZEPHIR_IS_EMPTY(&key)) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	ZEPHIR_INIT_VAR(&keysArr);
	zephir_fast_explode_str(&keysArr, SL("."), &key, LONG_MAX);
	if (ZEPHIR_IS_EMPTY(&keysArr)) {
		RETURN_MM_MEMBER(getThis(), "data");
	}
	ZEPHIR_OBS_VAR(&config);
	zephir_read_property(&config, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	zephir_is_iterable(&keysArr, 0, "moon/Component/Config/Config.zep", 81);
	if (Z_TYPE_P(&keysArr) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keysArr), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			if (!(zephir_array_isset(&config, &item))) {
				RETVAL_ZVAL(_default, 1, 0);
				RETURN_MM();
			}
			zephir_array_fetch(&_2$$5, &config, &item, PH_NOISY | PH_READONLY, "moon/Component/Config/Config.zep", 79);
			ZEPHIR_CPY_WRT(&config, &_2$$5);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &keysArr, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &keysArr, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &keysArr, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_isset(&config, &item))) {
					RETVAL_ZVAL(_default, 1, 0);
					RETURN_MM();
				}
				zephir_array_fetch(&_3$$7, &config, &item, PH_NOISY | PH_READONLY, "moon/Component/Config/Config.zep", 79);
				ZEPHIR_CPY_WRT(&config, &_3$$7);
			ZEPHIR_CALL_METHOD(NULL, &keysArr, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&config);

}

PHP_METHOD(Moon_Component_Config_Config, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param null $dir
 * @return Config
 */
PHP_METHOD(Moon_Component_Config_Config, getInstance) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dir = NULL, dir_sub, __$null, _0, _2, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dir_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dir);

	if (!dir) {
		dir = &dir_sub;
		dir = &__$null;
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, moon_component_config_config_ce, SL("instance"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, moon_component_config_config_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 45, dir);
		zephir_check_call_status();
		zephir_update_static_property_ce(moon_component_config_config_ce, ZEND_STRL("instance"), &_1$$3);
	}
	zephir_read_static_property_ce(&_2, moon_component_config_config_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_2);

}

PHP_METHOD(Moon_Component_Config_Config, resetConfig) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_0);
	RETURN_THIS();

}

zend_object *zephir_init_properties_Moon_Component_Config_Config(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("data"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

