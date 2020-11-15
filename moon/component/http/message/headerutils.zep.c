
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * FileName: HeaderUtils.php
 * User: solely
 * DateTime: 2020/7/13 23:24
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_HeaderUtils) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Http\\Message, HeaderUtils, moon, component_http_message_headerutils, moon_component_http_message_headerutils_method_entry, 0);

	zephir_declare_class_constant_string(moon_component_http_message_headerutils_ce, SL("DISPOSITION_ATTACHMENT"), "attachment");

	zephir_declare_class_constant_string(moon_component_http_message_headerutils_ce, SL("DISPOSITION_INLINE"), "inline");

	return SUCCESS;

}

/**
 * This class should not be instantiated.
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, __construct) {

	zval *this_ptr = getThis();



}

/**
 * Splits an HTTP header by one or more separators.
 *
 * Example:
 *
 *     HeaderUtils::split("da, en-gb;q=0.8", ",;")
 *     // => ['da'], ['en-gb', 'q=0.8']]
 *
 * @param string $separators List of characters to split on, ordered by
 *                           precedence, e.g. ",", ";=", or ",;="
 *
 * @return array Nested array with as many levels as there are characters in
 *               $separators
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, split) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, *separators_param = NULL, quotedSeparators, matches, _0, _1, _2, _3, _4;
	zval header, separators;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&separators);
	ZVAL_UNDEF(&quotedSeparators);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &header_param, &separators_param);

	zephir_get_strval(&header, header_param);
	zephir_get_strval(&separators, separators_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/");
	ZEPHIR_CALL_FUNCTION(&quotedSeparators, "preg_quote", NULL, 101, &separators, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVSVS(&_1, "\n            /\n                (?!\\s)\n                    (?:\n                        # quoted-string\n                        \"(?:[^\"\\\\]|\\\\.)*(?:\"|\\\\|$)\n                    |\n                        # token\n                        [^\"", &quotedSeparators, "]+\n                    )+\n                (?<!\\s)\n            |\n                # separator\n                \\s*\n                (?<separator>[", &quotedSeparators, "])\n                \\s*\n            /x");
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_trim(&_0, &header, NULL , ZEPHIR_TRIM_BOTH);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_4, 2);
	zephir_preg_match(&_3, &_1, &_0, &matches, 1, zephir_get_intval(&_2) , 0 );
	ZEPHIR_RETURN_CALL_SELF("groupparts", &_5, 102, &matches, &separators);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Combines an array of arrays into one associative array.
 *
 * Each of the nested arrays should have one or two elements. The first
 * value will be used as the keys in the associative array, and the second
 * will be used as the values, or true if the nested array only contains one
 * element. Array keys are lowercased.
 *
 * Example:
 *
 *     HeaderUtils::combine([["foo", "abc"], ["bar"]])
 *     // => ["foo" => "abc", "bar" => true]
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, combine) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parts_param = NULL, value, name, assoc, part, *_0, _1, _2$$3, _3$$4;
	zval parts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&assoc);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &parts_param);

	zephir_get_arrval(&parts, parts_param);


	ZEPHIR_INIT_VAR(&assoc);
	array_init(&assoc);
	zephir_is_iterable(&parts, 0, "moon/Component/Http/Message/HeaderUtils.zep", 68);
	if (Z_TYPE_P(&parts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _0)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _0);
			zephir_array_fetch_long(&_2$$3, &part, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/HeaderUtils.zep", 64);
			ZEPHIR_INIT_NVAR(&name);
			zephir_fast_strtolower(&name, &_2$$3);
			if (zephir_array_isset_long(&part, 1)) {
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_long(&value, &part, 1, PH_NOISY, "moon/Component/Http/Message/HeaderUtils.zep", 65);
			} else {
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_BOOL(&value, 1);
			}
			zephir_array_update_zval(&assoc, &name, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &parts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&part, &parts, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_long(&_3$$4, &part, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/HeaderUtils.zep", 64);
				ZEPHIR_INIT_NVAR(&name);
				zephir_fast_strtolower(&name, &_3$$4);
				if (zephir_array_isset_long(&part, 1)) {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch_long(&value, &part, 1, PH_NOISY, "moon/Component/Http/Message/HeaderUtils.zep", 65);
				} else {
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_BOOL(&value, 1);
				}
				zephir_array_update_zval(&assoc, &name, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &parts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&part);
	RETURN_CCTOR(&assoc);

}

/**
 * Joins an associative array into a string for use in an HTTP header.
 *
 * The key and value of each entry are joined with "=", and all entries
 * are joined with the specified separator and an additional space (for
 * readability). Values are quoted if necessary.
 *
 * Example:
 *
 *     HeaderUtils::toString(["foo" => "abc", "bar" => true, "baz" => "a b c"], ",")
 *     // => 'foo=abc, bar, baz="a b c"'
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, toString) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval separator, _9;
	zval *assoc_param = NULL, *separator_param = NULL, parts, name, value, *_0, _1, _4$$5, _6$$5, _7$$8, _8$$8;
	zval assoc;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&assoc);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &assoc_param, &separator_param);

	zephir_get_arrval(&assoc, assoc_param);
	zephir_get_strval(&separator, separator_param);


	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	zephir_is_iterable(&assoc, 0, "moon/Component/Http/Message/HeaderUtils.zep", 96);
	if (Z_TYPE_P(&assoc) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&assoc), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
				zephir_array_append(&parts, &name, PH_SEPARATE, "moon/Component/Http/Message/HeaderUtils.zep", 91);
			} else {
				ZEPHIR_CALL_SELF(&_4$$5, "quote", &_5, 0, &value);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZEPHIR_CONCAT_VSV(&_6$$5, &name, "=", &_4$$5);
				zephir_array_append(&parts, &_6$$5, PH_SEPARATE, "moon/Component/Http/Message/HeaderUtils.zep", 93);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &assoc, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &assoc, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &assoc, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &assoc, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
					zephir_array_append(&parts, &name, PH_SEPARATE, "moon/Component/Http/Message/HeaderUtils.zep", 91);
				} else {
					ZEPHIR_CALL_SELF(&_7$$8, "quote", &_5, 0, &value);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_8$$8);
					ZEPHIR_CONCAT_VSV(&_8$$8, &name, "=", &_7$$8);
					zephir_array_append(&parts, &_8$$8, PH_SEPARATE, "moon/Component/Http/Message/HeaderUtils.zep", 93);
				}
			ZEPHIR_CALL_METHOD(NULL, &assoc, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_VS(&_9, &separator, " ");
	zephir_fast_join(return_value, &_9, &parts);
	RETURN_MM();

}

/**
 * Encodes a string as a quoted string, if necessary.
 *
 * If a string contains characters not allowed by the "token" construct in
 * the HTTP specification, it is backslash-escaped and enclosed in quotes
 * to match the "quoted-string" construct.
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, quote) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *s_param = NULL, _0, _1, _2, _3, _4, _5;
	zval s;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &s_param);

	zephir_get_strval(&s, s_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/^[a-z0-9!#$%&'*.^_`|~-]+$/i");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/^[a-z0-9!#$%&'*.^_`|~-]+$/i");
	zephir_preg_match(&_2, &_3, &s, &_0, 0, 0 , 0 );
	if (zephir_is_true(&_2)) {
		RETURN_CTOR(&s);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "\"\\\"");
	ZEPHIR_CALL_FUNCTION(&_5, "addcslashes", NULL, 103, &s, &_4);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "\"", &_5, "\"");
	RETURN_MM();

}

/**
 * Decodes a quoted string.
 *
 * If passed an unquoted string that matches the "token" construct (as
 * defined in the HTTP specification), it is passed through verbatimly.
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, unquote) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *s_param = NULL, _0, _1;
	zval s;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &s_param);

	zephir_get_strval(&s, s_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/\\\\(.)|\"/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "$1");
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 28, &_0, &_1, &s);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates a HTTP Content-Disposition field-value.
 *
 * @param string $disposition      One of "inline" or "attachment"
 * @param string $filename         A unicode string
 * @param string $filenameFallback A string containing only ASCII characters that
 *                                 is semantically equivalent to $filename. If the filename is already ASCII,
 *                                 it can be omitted, or just copied from $filename
 *
 * @return string A string suitable for use as a Content-Disposition field-value
 *
 * @throws \InvalidArgumentException
 *
 * @see RFC 6266
 */
PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, makeDisposition) {

	zend_bool _15, _18, _21;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *disposition_param = NULL, *filename_param = NULL, filenameFallback, *filenameFallback_param = NULL, params, _1, _7, _8, _9, _10, _11, _12, _13, _14, _16, _17, _19, _20, _22, _23, _26, _27, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _24$$8, _25$$8;
	zval disposition, filename;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&disposition);
	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&filenameFallback);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &disposition_param, &filename_param, &filenameFallback_param);

	zephir_get_strval(&disposition, disposition_param);
	zephir_get_strval(&filename, filename_param);
	if (!filenameFallback_param) {
		ZEPHIR_INIT_VAR(&filenameFallback);
		ZVAL_STRING(&filenameFallback, "");
	} else {
		zephir_get_strval(&filenameFallback, filenameFallback_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "attachment");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "inline");
	zephir_array_fast_append(&_0, &_1);
	if (!(zephir_fast_in_array(&disposition, &_0))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "The disposition must be either \"%s\" or \"%s\".");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "attachment");
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "inline");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", NULL, 3, &_3$$3, &_4$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 25, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "moon/Component/Http/Message/HeaderUtils.zep", 145);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "");
	if (ZEPHIR_IS_IDENTICAL(&_7, &filenameFallback)) {
		ZEPHIR_CPY_WRT(&filenameFallback, &filename);
	}
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/^[\\x20-\\x7e]*$/");
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "/^[\\x20-\\x7e]*$/");
	zephir_preg_match(&_9, &_10, &filenameFallback, &_8, 0, 0 , 0 );
	if (!zephir_is_true(&_9)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The filename fallback must only contain ASCII characters.", "moon/Component/Http/Message/HeaderUtils.zep", 152);
		return;
	}
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "%");
	ZEPHIR_INIT_VAR(&_12);
	zephir_fast_strpos(&_12, &filenameFallback, &_11, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_12)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The filename fallback cannot contain the \"%\" character.", "moon/Component/Http/Message/HeaderUtils.zep", 156);
		return;
	}
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "/");
	ZEPHIR_INIT_VAR(&_14);
	zephir_fast_strpos(&_14, &filename, &_13, 0 );
	_15 = !ZEPHIR_IS_FALSE_IDENTICAL(&_14);
	if (!(_15)) {
		ZEPHIR_INIT_VAR(&_16);
		ZVAL_STRING(&_16, "\\");
		ZEPHIR_INIT_VAR(&_17);
		zephir_fast_strpos(&_17, &filename, &_16, 0 );
		_15 = !ZEPHIR_IS_FALSE_IDENTICAL(&_17);
	}
	_18 = _15;
	if (!(_18)) {
		ZEPHIR_INIT_VAR(&_19);
		ZVAL_STRING(&_19, "/");
		ZEPHIR_INIT_VAR(&_20);
		zephir_fast_strpos(&_20, &filenameFallback, &_19, 0 );
		_18 = !ZEPHIR_IS_FALSE_IDENTICAL(&_20);
	}
	_21 = _18;
	if (!(_21)) {
		ZEPHIR_INIT_VAR(&_22);
		ZVAL_STRING(&_22, "\\");
		ZEPHIR_INIT_VAR(&_23);
		zephir_fast_strpos(&_23, &filenameFallback, &_22, 0 );
		_21 = !ZEPHIR_IS_FALSE_IDENTICAL(&_23);
	}
	if (_21) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The filename and the fallback cannot contain the \"/\" and \"\\\" characters.", "moon/Component/Http/Message/HeaderUtils.zep", 160);
		return;
	}
	ZEPHIR_INIT_VAR(&params);
	zephir_create_array(&params, 1, 0);
	zephir_array_update_string(&params, SL("filename"), &filenameFallback, PH_COPY | PH_SEPARATE);
	if (!ZEPHIR_IS_IDENTICAL(&filename, &filenameFallback)) {
		ZEPHIR_CALL_FUNCTION(&_24$$8, "rawurlencode", NULL, 91, &filename);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_25$$8);
		ZEPHIR_CONCAT_SV(&_25$$8, "utf-8''", &_24$$8);
		zephir_array_update_string(&params, SL("filename*"), &_25$$8, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_27);
	ZVAL_STRING(&_27, ";");
	ZEPHIR_CALL_SELF(&_26, "tostring", NULL, 0, &params, &_27);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &disposition, "; ", &_26);
	RETURN_MM();

}

PHP_METHOD(Moon_Component_Http_Message_HeaderUtils, groupParts) {

	zend_bool _4$$3, _6$$6;
	unsigned char _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i = 0;
	zval separators;
	zval *matches_param = NULL, *separators_param = NULL, parts, partMatches, partSeparators, separator, _1, _match, *_2, _3, _5$$3, _7$$6, matches$$9, *_8$$9, _9$$9, _10$$10, _12$$11, matches$$12, *_13$$12, _14$$12, _15$$13, _17$$13, _18$$13, _19$$14, _20$$14, _21$$14;
	zval matches;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&partMatches);
	ZVAL_UNDEF(&partSeparators);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_match);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&matches$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&matches$$12);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&separators);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &matches_param, &separators_param);

	zephir_get_arrval(&matches, matches_param);
	zephir_get_strval(&separators, separators_param);


	_0 = ZEPHIR_STRING_OFFSET(&separators, 0);
	ZEPHIR_INIT_VAR(&separator);
	ZVAL_LONG(&separator, _0);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(&partSeparators);
	zephir_substr(&partSeparators, &separators, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	i = 0;
	ZEPHIR_INIT_VAR(&partMatches);
	array_init(&partMatches);
	zephir_is_iterable(&matches, 0, "moon/Component/Http/Message/HeaderUtils.zep", 190);
	if (Z_TYPE_P(&matches) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&matches), _2)
		{
			ZEPHIR_INIT_NVAR(&_match);
			ZVAL_COPY(&_match, _2);
			_4$$3 = zephir_array_isset_string(&_match, SL("separator"));
			if (_4$$3) {
				zephir_array_fetch_string(&_5$$3, &_match, SL("separator"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/HeaderUtils.zep", 183);
				_4$$3 = ZEPHIR_IS_IDENTICAL(&_5$$3, &separator);
			}
			if (_4$$3) {
				i += 1;
			} else {
				zephir_array_update_multi(&partMatches, &_match, SL("la"), 2, i);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &matches, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &matches, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_match, &matches, "current", NULL, 0);
			zephir_check_call_status();
				_6$$6 = zephir_array_isset_string(&_match, SL("separator"));
				if (_6$$6) {
					zephir_array_fetch_string(&_7$$6, &_match, SL("separator"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/HeaderUtils.zep", 183);
					_6$$6 = ZEPHIR_IS_IDENTICAL(&_7$$6, &separator);
				}
				if (_6$$6) {
					i += 1;
				} else {
					zephir_array_update_multi(&partMatches, &_match, SL("la"), 2, i);
				}
			ZEPHIR_CALL_METHOD(NULL, &matches, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_match);
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	if (zephir_is_true(&partSeparators)) {
		zephir_is_iterable(&partMatches, 0, "moon/Component/Http/Message/HeaderUtils.zep", 196);
		if (Z_TYPE_P(&partMatches) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&partMatches), _8$$9)
			{
				ZEPHIR_INIT_NVAR(&matches$$9);
				ZVAL_COPY(&matches$$9, _8$$9);
				ZEPHIR_CALL_SELF(&_10$$10, "groupparts", &_11, 102, &matches$$9, &partSeparators);
				zephir_check_call_status();
				zephir_array_append(&parts, &_10$$10, PH_SEPARATE, "moon/Component/Http/Message/HeaderUtils.zep", 194);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &partMatches, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_9$$9, &partMatches, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_9$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&matches$$9, &partMatches, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_SELF(&_12$$11, "groupparts", &_11, 102, &matches$$9, &partSeparators);
					zephir_check_call_status();
					zephir_array_append(&parts, &_12$$11, PH_SEPARATE, "moon/Component/Http/Message/HeaderUtils.zep", 194);
				ZEPHIR_CALL_METHOD(NULL, &partMatches, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&matches$$9);
	} else {
		zephir_is_iterable(&partMatches, 0, "moon/Component/Http/Message/HeaderUtils.zep", 201);
		if (Z_TYPE_P(&partMatches) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&partMatches), _13$$12)
			{
				ZEPHIR_INIT_NVAR(&matches$$12);
				ZVAL_COPY(&matches$$12, _13$$12);
				zephir_array_fetch_long(&_17$$13, &matches$$12, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/HeaderUtils.zep", 199);
				zephir_array_fetch_long(&_18$$13, &_17$$13, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/HeaderUtils.zep", 199);
				ZEPHIR_CALL_SELF(&_15$$13, "unquote", &_16, 0, &_18$$13);
				zephir_check_call_status();
				zephir_array_append(&parts, &_15$$13, PH_SEPARATE, "moon/Component/Http/Message/HeaderUtils.zep", 199);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &partMatches, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_14$$12, &partMatches, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$12)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&matches$$12, &partMatches, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_fetch_long(&_20$$14, &matches$$12, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/HeaderUtils.zep", 199);
					zephir_array_fetch_long(&_21$$14, &_20$$14, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/HeaderUtils.zep", 199);
					ZEPHIR_CALL_SELF(&_19$$14, "unquote", &_16, 0, &_21$$14);
					zephir_check_call_status();
					zephir_array_append(&parts, &_19$$14, PH_SEPARATE, "moon/Component/Http/Message/HeaderUtils.zep", 199);
				ZEPHIR_CALL_METHOD(NULL, &partMatches, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&matches$$12);
	}
	RETURN_CCTOR(&parts);

}

