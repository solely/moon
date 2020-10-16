
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(moon_3__closure) {

	ZEPHIR_REGISTER_CLASS(moon, 3__closure, moon, 3__closure, moon_3__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(moon_3__closure_ce, SL("vars"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	zend_declare_property_null(moon_3__closure_ce, SL("keysToHide"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(moon_3__closure, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval m, _2$$3;
	zval vars, keysToHide, *m_param = NULL, kv, dump, _0, _9, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&keysToHide);
	ZVAL_UNDEF(&kv);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&keysToHide, moon_3__closure_ce, SL("keysToHide"), PH_NOISY_CC);
	zephir_read_static_property_ce(&vars, moon_3__closure_ce, SL("vars"), PH_NOISY_CC);
	zephir_fetch_params(1, 1, 0, &m_param);

	zephir_get_arrval(&m, m_param);


	ZEPHIR_OBS_VAR(&kv);
	zephir_array_fetch_long(&_0, &m, 1, PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 740);
	if (zephir_array_isset_fetch(&kv, &vars, &_0, 0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 2, 0);
		add_assoc_long_ex(&_2$$3, SL("depth"), 1);
		zephir_array_update_string(&_2$$3, SL("keystohide"), &keysToHide, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_CE_STATIC(&dump, moon_component_errorhandler_dumper_ce, "tohtml", &_1, 0, &kv, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "strip_tags", NULL, 110, &dump);
		zephir_check_call_status();
		zephir_fast_trim(&_4$$3, &_5$$3, NULL , ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "\"");
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "&quot;");
		zephir_fast_str_replace(&_3$$3, &_6$$3, &_7$$3, &_4$$3);
		zephir_array_fetch_long(&_8$$3, &m, 0, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 743);
		ZEPHIR_CONCAT_SVV(return_value, "\" title=\"", &_3$$3, &_8$$3);
		RETURN_MM();
	}
	zephir_array_fetch_long(&_9, &m, 0, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 745);
	RETURN_CTOR(&_9);

}

