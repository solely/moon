
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/main.h"
#include "kernel/concat.h"


/**
 * FileName: Helpers.php
 * User: solely
 * DateTime: 2019/12/8 21:37
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Helpers) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\ErrorHandler, Helpers, moon, component_errorhandler_helpers, moon_component_errorhandler_helpers_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_ErrorHandler_Helpers, escapeHtml) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *s, s_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&s_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &s);



	zephir_get_strval(&_0, s);
	ZVAL_LONG(&_1, (3 | 8));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "UTF-8");
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 167, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Helpers, getClass) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *obj, obj_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&obj_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, obj, 0);
	zephir_fast_explode_str(&_0, SL("\0"), &_1, LONG_MAX);
	zephir_array_fetch_long(&_2, &_0, 0, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Helpers.zep", 18);
	RETURN_CTOR(&_2);

}

PHP_METHOD(Moon_Component_ErrorHandler_Helpers, formatHtml) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mask_param = NULL, args, maskArr, res, k, v, m, *_0, _1, _4$$3, _6$$3, _7$$4, _8$$4;
	zval mask;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mask);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&maskArr);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mask_param);

	zephir_get_strval(&mask, mask_param);


	ZEPHIR_INIT_VAR(&args);
	zephir_get_args(&args);
	ZEPHIR_INIT_VAR(&maskArr);
	zephir_fast_explode_str(&maskArr, SL("%"), &mask, LONG_MAX);
	ZEPHIR_INIT_VAR(&res);
	ZVAL_STRING(&res, "");
	zephir_is_iterable(&maskArr, 0, "moon/Component/ErrorHandler/Helpers.zep", 41);
	if (Z_TYPE_P(&maskArr) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&maskArr), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&k, _3);
			} else {
				ZVAL_LONG(&k, _2);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _0);
			if (zephir_array_isset(&maskArr, &k)) {
				ZEPHIR_OBS_NVAR(&m);
				zephir_array_fetch(&m, &maskArr, &k, PH_NOISY, "moon/Component/ErrorHandler/Helpers.zep", 37);
			} else {
				ZEPHIR_INIT_NVAR(&m);
				ZVAL_STRING(&m, "");
			}
			ZEPHIR_CALL_SELF(&_4$$3, "escapehtml", &_5, 0, &m);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&m, &_4$$3);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_CONCAT_VV(&_6$$3, &v, &m);
			zephir_concat_self(&res, &_6$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &maskArr, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &maskArr, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &maskArr, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &maskArr, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset(&maskArr, &k)) {
					ZEPHIR_OBS_NVAR(&m);
					zephir_array_fetch(&m, &maskArr, &k, PH_NOISY, "moon/Component/ErrorHandler/Helpers.zep", 37);
				} else {
					ZEPHIR_INIT_NVAR(&m);
					ZVAL_STRING(&m, "");
				}
				ZEPHIR_CALL_SELF(&_7$$4, "escapehtml", &_5, 0, &m);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&m, &_7$$4);
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZEPHIR_CONCAT_VV(&_8$$4, &v, &m);
				zephir_concat_self(&res, &_8$$4);
			ZEPHIR_CALL_METHOD(NULL, &maskArr, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	RETURN_CCTOR(&res);

}

