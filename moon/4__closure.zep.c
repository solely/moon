
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(moon_4__closure) {

	ZEPHIR_REGISTER_CLASS(moon, 4__closure, moon, 4__closure, moon_4__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(moon_4__closure_ce, SL("keysToHide"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(moon_4__closure, __invoke) {

	zval _3;
	zval md, ml, ss, kh;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval keysToHide, *v = NULL, v_sub, *k, k_sub, _1, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keysToHide);
	ZVAL_UNDEF(&v_sub);
	ZVAL_UNDEF(&k_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&md);
	ZVAL_UNDEF(&ml);
	ZVAL_UNDEF(&ss);
	ZVAL_UNDEF(&kh);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_read_static_property_ce(&keysToHide, moon_4__closure_ce, SL("keysToHide"), PH_NOISY_CC);
	zephir_fetch_params(1, 2, 0, &v, &k);

	ZEPHIR_SEPARATE_PARAM(v);


	_0 = Z_TYPE_P(k) == IS_STRING;
	if (_0) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_fast_strtolower(&_1, k);
		_0 = zephir_array_isset(&keysToHide, &_1);
	}
	if (_0) {
		ZEPHIR_INIT_NVAR(v);
		ZVAL_STRING(v, "*****");
	}
	ZEPHIR_INIT_VAR(&md);
	ZVAL_STRING(&md, "maxDepth");
	ZEPHIR_INIT_VAR(&ml);
	ZVAL_STRING(&ml, "maxLength");
	ZEPHIR_INIT_VAR(&ss);
	ZVAL_STRING(&ss, "snapshot");
	ZEPHIR_INIT_VAR(&kh);
	ZVAL_STRING(&kh, "keysToHide");
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 5, 0);
	ZEPHIR_OBS_VAR(&_4);
	zephir_read_property_zval(&_4, this_ptr, &md, PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("depth"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_read_property_zval(&_4, this_ptr, &ml, PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("truncate"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_read_property_zval(&_4, this_ptr, &ss, PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("snapshot"), &_4, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_3, SL("location"), 4);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_read_property_zval(&_4, this_ptr, &kh, PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("keystohide"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_CE_STATIC(moon_component_errorhandler_dumper_ce, "tohtml", &_2, 0, v, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

