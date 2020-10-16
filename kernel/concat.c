
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <php.h>
#include "php_ext.h"
#include <ext/standard/php_string.h>
#include "ext.h"
#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"

void zephir_concat_ss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, int self_var){

	zval result_copy;
	int use_copy = 0;
	size_t offset = 0, length;

	length = op1_len + op2_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_sss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, int self_var){

	zval result_copy;
	int use_copy = 0;
	size_t offset = 0, length;

	length = op1_len + op2_len + op3_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, op3, op3_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_ssss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, int self_var){

	zval result_copy;
	int use_copy = 0;
	size_t offset = 0, length;

	length = op1_len + op2_len + op3_len + op4_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len, op4, op4_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, const char *op5, uint32_t op5_len, const char *op6, uint32_t op6_len, const char *op7, uint32_t op7_len, const char *op8, uint32_t op8_len, const char *op9, uint32_t op9_len, const char *op10, uint32_t op10_len, const char *op11, uint32_t op11_len, const char *op12, uint32_t op12_len, const char *op13, uint32_t op13_len, const char *op14, uint32_t op14_len, const char *op15, uint32_t op15_len, const char *op16, uint32_t op16_len, const char *op17, uint32_t op17_len, const char *op18, uint32_t op18_len, const char *op19, uint32_t op19_len, const char *op20, uint32_t op20_len, const char *op21, uint32_t op21_len, const char *op22, uint32_t op22_len, const char *op23, uint32_t op23_len, const char *op24, uint32_t op24_len, const char *op25, uint32_t op25_len, const char *op26, uint32_t op26_len, const char *op27, uint32_t op27_len, const char *op28, uint32_t op28_len, const char *op29, uint32_t op29_len, const char *op30, uint32_t op30_len, const char *op31, uint32_t op31_len, const char *op32, uint32_t op32_len, const char *op33, uint32_t op33_len, const char *op34, uint32_t op34_len, const char *op35, uint32_t op35_len, const char *op36, uint32_t op36_len, const char *op37, uint32_t op37_len, const char *op38, uint32_t op38_len, const char *op39, uint32_t op39_len, const char *op40, uint32_t op40_len, const char *op41, uint32_t op41_len, const char *op42, uint32_t op42_len, const char *op43, uint32_t op43_len, const char *op44, uint32_t op44_len, const char *op45, uint32_t op45_len, const char *op46, uint32_t op46_len, const char *op47, uint32_t op47_len, const char *op48, uint32_t op48_len, const char *op49, uint32_t op49_len, const char *op50, uint32_t op50_len, const char *op51, uint32_t op51_len, const char *op52, uint32_t op52_len, const char *op53, uint32_t op53_len, const char *op54, uint32_t op54_len, const char *op55, uint32_t op55_len, const char *op56, uint32_t op56_len, const char *op57, uint32_t op57_len, const char *op58, uint32_t op58_len, const char *op59, uint32_t op59_len, const char *op60, uint32_t op60_len, const char *op61, uint32_t op61_len, const char *op62, uint32_t op62_len, const char *op63, uint32_t op63_len, const char *op64, uint32_t op64_len, const char *op65, uint32_t op65_len, const char *op66, uint32_t op66_len, const char *op67, uint32_t op67_len, const char *op68, uint32_t op68_len, const char *op69, uint32_t op69_len, const char *op70, uint32_t op70_len, const char *op71, uint32_t op71_len, const char *op72, uint32_t op72_len, const char *op73, uint32_t op73_len, const char *op74, uint32_t op74_len, const char *op75, uint32_t op75_len, const char *op76, uint32_t op76_len, const char *op77, uint32_t op77_len, const char *op78, uint32_t op78_len, const char *op79, uint32_t op79_len, const char *op80, uint32_t op80_len, const char *op81, uint32_t op81_len, const char *op82, uint32_t op82_len, const char *op83, uint32_t op83_len, const char *op84, uint32_t op84_len, int self_var){

	zval result_copy;
	int use_copy = 0;
	size_t offset = 0, length;

	length = op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len, op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len, op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len, op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len, op7, op7_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len, op8, op8_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len, op9, op9_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len, op10, op10_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len, op11, op11_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len, op12, op12_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len, op13, op13_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len, op14, op14_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len, op15, op15_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len, op16, op16_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len, op17, op17_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len, op18, op18_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len, op19, op19_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len, op20, op20_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len, op21, op21_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len, op22, op22_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len, op23, op23_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len, op24, op24_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len, op25, op25_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len, op26, op26_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len, op27, op27_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len, op28, op28_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len, op29, op29_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len, op30, op30_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len, op31, op31_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len, op32, op32_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len, op33, op33_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len, op34, op34_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len, op35, op35_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len, op36, op36_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len, op37, op37_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len, op38, op38_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len, op39, op39_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len, op40, op40_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len, op41, op41_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len, op42, op42_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len, op43, op43_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len, op44, op44_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len, op45, op45_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len, op46, op46_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len, op47, op47_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len, op48, op48_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len, op49, op49_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len, op50, op50_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len, op51, op51_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len, op52, op52_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len, op53, op53_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len, op54, op54_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len, op55, op55_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len, op56, op56_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len, op57, op57_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len, op58, op58_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len, op59, op59_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len, op60, op60_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len, op61, op61_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len, op62, op62_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len, op63, op63_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len, op64, op64_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len, op65, op65_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len, op66, op66_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len, op67, op67_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len, op68, op68_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len, op69, op69_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len, op70, op70_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len, op71, op71_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len, op72, op72_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len, op73, op73_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len, op74, op74_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len, op75, op75_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len, op76, op76_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len, op77, op77_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len, op78, op78_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len, op79, op79_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len, op80, op80_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len, op81, op81_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len, op82, op82_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len, op83, op83_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len, op84, op84_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, const char *op5, uint32_t op5_len, const char *op6, uint32_t op6_len, const char *op7, uint32_t op7_len, const char *op8, uint32_t op8_len, const char *op9, uint32_t op9_len, const char *op10, uint32_t op10_len, const char *op11, uint32_t op11_len, const char *op12, uint32_t op12_len, const char *op13, uint32_t op13_len, const char *op14, uint32_t op14_len, const char *op15, uint32_t op15_len, const char *op16, uint32_t op16_len, const char *op17, uint32_t op17_len, const char *op18, uint32_t op18_len, const char *op19, uint32_t op19_len, const char *op20, uint32_t op20_len, const char *op21, uint32_t op21_len, const char *op22, uint32_t op22_len, const char *op23, uint32_t op23_len, const char *op24, uint32_t op24_len, const char *op25, uint32_t op25_len, const char *op26, uint32_t op26_len, const char *op27, uint32_t op27_len, const char *op28, uint32_t op28_len, const char *op29, uint32_t op29_len, const char *op30, uint32_t op30_len, const char *op31, uint32_t op31_len, const char *op32, uint32_t op32_len, const char *op33, uint32_t op33_len, const char *op34, uint32_t op34_len, const char *op35, uint32_t op35_len, const char *op36, uint32_t op36_len, const char *op37, uint32_t op37_len, const char *op38, uint32_t op38_len, const char *op39, uint32_t op39_len, const char *op40, uint32_t op40_len, const char *op41, uint32_t op41_len, const char *op42, uint32_t op42_len, const char *op43, uint32_t op43_len, const char *op44, uint32_t op44_len, const char *op45, uint32_t op45_len, const char *op46, uint32_t op46_len, const char *op47, uint32_t op47_len, const char *op48, uint32_t op48_len, const char *op49, uint32_t op49_len, const char *op50, uint32_t op50_len, const char *op51, uint32_t op51_len, const char *op52, uint32_t op52_len, const char *op53, uint32_t op53_len, const char *op54, uint32_t op54_len, const char *op55, uint32_t op55_len, const char *op56, uint32_t op56_len, const char *op57, uint32_t op57_len, const char *op58, uint32_t op58_len, const char *op59, uint32_t op59_len, const char *op60, uint32_t op60_len, const char *op61, uint32_t op61_len, const char *op62, uint32_t op62_len, const char *op63, uint32_t op63_len, const char *op64, uint32_t op64_len, const char *op65, uint32_t op65_len, const char *op66, uint32_t op66_len, const char *op67, uint32_t op67_len, const char *op68, uint32_t op68_len, const char *op69, uint32_t op69_len, const char *op70, uint32_t op70_len, const char *op71, uint32_t op71_len, const char *op72, uint32_t op72_len, const char *op73, uint32_t op73_len, const char *op74, uint32_t op74_len, const char *op75, uint32_t op75_len, const char *op76, uint32_t op76_len, const char *op77, uint32_t op77_len, const char *op78, uint32_t op78_len, const char *op79, uint32_t op79_len, const char *op80, uint32_t op80_len, const char *op81, uint32_t op81_len, const char *op82, uint32_t op82_len, const char *op83, uint32_t op83_len, const char *op84, uint32_t op84_len, const char *op85, uint32_t op85_len, const char *op86, uint32_t op86_len, const char *op87, uint32_t op87_len, const char *op88, uint32_t op88_len, const char *op89, uint32_t op89_len, const char *op90, uint32_t op90_len, const char *op91, uint32_t op91_len, const char *op92, uint32_t op92_len, const char *op93, uint32_t op93_len, const char *op94, uint32_t op94_len, const char *op95, uint32_t op95_len, const char *op96, uint32_t op96_len, const char *op97, uint32_t op97_len, const char *op98, uint32_t op98_len, const char *op99, uint32_t op99_len, const char *op100, uint32_t op100_len, const char *op101, uint32_t op101_len, const char *op102, uint32_t op102_len, const char *op103, uint32_t op103_len, const char *op104, uint32_t op104_len, const char *op105, uint32_t op105_len, const char *op106, uint32_t op106_len, const char *op107, uint32_t op107_len, const char *op108, uint32_t op108_len, const char *op109, uint32_t op109_len, const char *op110, uint32_t op110_len, const char *op111, uint32_t op111_len, const char *op112, uint32_t op112_len, const char *op113, uint32_t op113_len, const char *op114, uint32_t op114_len, const char *op115, uint32_t op115_len, const char *op116, uint32_t op116_len, const char *op117, uint32_t op117_len, const char *op118, uint32_t op118_len, const char *op119, uint32_t op119_len, const char *op120, uint32_t op120_len, const char *op121, uint32_t op121_len, const char *op122, uint32_t op122_len, const char *op123, uint32_t op123_len, const char *op124, uint32_t op124_len, const char *op125, uint32_t op125_len, const char *op126, uint32_t op126_len, const char *op127, uint32_t op127_len, const char *op128, uint32_t op128_len, const char *op129, uint32_t op129_len, const char *op130, uint32_t op130_len, const char *op131, uint32_t op131_len, const char *op132, uint32_t op132_len, const char *op133, uint32_t op133_len, const char *op134, uint32_t op134_len, const char *op135, uint32_t op135_len, const char *op136, uint32_t op136_len, const char *op137, uint32_t op137_len, const char *op138, uint32_t op138_len, const char *op139, uint32_t op139_len, const char *op140, uint32_t op140_len, const char *op141, uint32_t op141_len, const char *op142, uint32_t op142_len, const char *op143, uint32_t op143_len, const char *op144, uint32_t op144_len, const char *op145, uint32_t op145_len, const char *op146, uint32_t op146_len, const char *op147, uint32_t op147_len, const char *op148, uint32_t op148_len, const char *op149, uint32_t op149_len, const char *op150, uint32_t op150_len, const char *op151, uint32_t op151_len, const char *op152, uint32_t op152_len, const char *op153, uint32_t op153_len, const char *op154, uint32_t op154_len, const char *op155, uint32_t op155_len, const char *op156, uint32_t op156_len, const char *op157, uint32_t op157_len, const char *op158, uint32_t op158_len, const char *op159, uint32_t op159_len, const char *op160, uint32_t op160_len, const char *op161, uint32_t op161_len, const char *op162, uint32_t op162_len, const char *op163, uint32_t op163_len, const char *op164, uint32_t op164_len, const char *op165, uint32_t op165_len, const char *op166, uint32_t op166_len, const char *op167, uint32_t op167_len, const char *op168, uint32_t op168_len, const char *op169, uint32_t op169_len, const char *op170, uint32_t op170_len, const char *op171, uint32_t op171_len, const char *op172, uint32_t op172_len, const char *op173, uint32_t op173_len, const char *op174, uint32_t op174_len, const char *op175, uint32_t op175_len, const char *op176, uint32_t op176_len, const char *op177, uint32_t op177_len, const char *op178, uint32_t op178_len, const char *op179, uint32_t op179_len, const char *op180, uint32_t op180_len, const char *op181, uint32_t op181_len, const char *op182, uint32_t op182_len, const char *op183, uint32_t op183_len, const char *op184, uint32_t op184_len, const char *op185, uint32_t op185_len, const char *op186, uint32_t op186_len, const char *op187, uint32_t op187_len, const char *op188, uint32_t op188_len, const char *op189, uint32_t op189_len, const char *op190, uint32_t op190_len, const char *op191, uint32_t op191_len, const char *op192, uint32_t op192_len, const char *op193, uint32_t op193_len, const char *op194, uint32_t op194_len, const char *op195, uint32_t op195_len, const char *op196, uint32_t op196_len, const char *op197, uint32_t op197_len, const char *op198, uint32_t op198_len, const char *op199, uint32_t op199_len, const char *op200, uint32_t op200_len, const char *op201, uint32_t op201_len, const char *op202, uint32_t op202_len, const char *op203, uint32_t op203_len, const char *op204, uint32_t op204_len, const char *op205, uint32_t op205_len, const char *op206, uint32_t op206_len, const char *op207, uint32_t op207_len, const char *op208, uint32_t op208_len, const char *op209, uint32_t op209_len, const char *op210, uint32_t op210_len, const char *op211, uint32_t op211_len, const char *op212, uint32_t op212_len, int self_var){

	zval result_copy;
	int use_copy = 0;
	size_t offset = 0, length;

	length = op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len + op202_len + op203_len + op204_len + op205_len + op206_len + op207_len + op208_len + op209_len + op210_len + op211_len + op212_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len, op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len, op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len, op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len, op7, op7_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len, op8, op8_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len, op9, op9_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len, op10, op10_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len, op11, op11_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len, op12, op12_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len, op13, op13_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len, op14, op14_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len, op15, op15_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len, op16, op16_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len, op17, op17_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len, op18, op18_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len, op19, op19_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len, op20, op20_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len, op21, op21_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len, op22, op22_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len, op23, op23_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len, op24, op24_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len, op25, op25_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len, op26, op26_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len, op27, op27_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len, op28, op28_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len, op29, op29_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len, op30, op30_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len, op31, op31_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len, op32, op32_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len, op33, op33_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len, op34, op34_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len, op35, op35_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len, op36, op36_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len, op37, op37_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len, op38, op38_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len, op39, op39_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len, op40, op40_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len, op41, op41_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len, op42, op42_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len, op43, op43_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len, op44, op44_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len, op45, op45_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len, op46, op46_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len, op47, op47_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len, op48, op48_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len, op49, op49_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len, op50, op50_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len, op51, op51_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len, op52, op52_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len, op53, op53_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len, op54, op54_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len, op55, op55_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len, op56, op56_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len, op57, op57_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len, op58, op58_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len, op59, op59_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len, op60, op60_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len, op61, op61_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len, op62, op62_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len, op63, op63_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len, op64, op64_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len, op65, op65_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len, op66, op66_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len, op67, op67_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len, op68, op68_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len, op69, op69_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len, op70, op70_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len, op71, op71_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len, op72, op72_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len, op73, op73_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len, op74, op74_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len, op75, op75_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len, op76, op76_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len, op77, op77_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len, op78, op78_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len, op79, op79_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len, op80, op80_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len, op81, op81_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len, op82, op82_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len, op83, op83_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len, op84, op84_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len, op85, op85_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len, op86, op86_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len, op87, op87_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len, op88, op88_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len, op89, op89_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len, op90, op90_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len, op91, op91_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len, op92, op92_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len, op93, op93_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len, op94, op94_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len, op95, op95_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len, op96, op96_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len, op97, op97_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len, op98, op98_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len, op99, op99_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len, op100, op100_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len, op101, op101_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len, op102, op102_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len, op103, op103_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len, op104, op104_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len, op105, op105_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len, op106, op106_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len, op107, op107_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len, op108, op108_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len, op109, op109_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len, op110, op110_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len, op111, op111_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len, op112, op112_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len, op113, op113_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len, op114, op114_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len, op115, op115_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len, op116, op116_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len, op117, op117_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len, op118, op118_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len, op119, op119_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len, op120, op120_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len, op121, op121_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len, op122, op122_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len, op123, op123_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len, op124, op124_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len, op125, op125_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len, op126, op126_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len, op127, op127_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len, op128, op128_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len, op129, op129_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len, op130, op130_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len, op131, op131_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len, op132, op132_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len, op133, op133_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len, op134, op134_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len, op135, op135_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len, op136, op136_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len, op137, op137_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len, op138, op138_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len, op139, op139_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len, op140, op140_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len, op141, op141_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len, op142, op142_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len, op143, op143_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len, op144, op144_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len, op145, op145_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len, op146, op146_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len, op147, op147_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len, op148, op148_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len, op149, op149_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len, op150, op150_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len, op151, op151_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len, op152, op152_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len, op153, op153_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len, op154, op154_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len, op155, op155_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len, op156, op156_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len, op157, op157_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len, op158, op158_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len, op159, op159_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len, op160, op160_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len, op161, op161_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len, op162, op162_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len, op163, op163_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len, op164, op164_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len, op165, op165_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len, op166, op166_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len, op167, op167_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len, op168, op168_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len, op169, op169_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len, op170, op170_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len, op171, op171_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len, op172, op172_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len, op173, op173_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len, op174, op174_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len, op175, op175_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len, op176, op176_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len, op177, op177_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len, op178, op178_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len, op179, op179_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len, op180, op180_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len, op181, op181_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len, op182, op182_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len, op183, op183_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len, op184, op184_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len, op185, op185_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len, op186, op186_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len, op187, op187_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len, op188, op188_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len, op189, op189_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len, op190, op190_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len, op191, op191_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len, op192, op192_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len, op193, op193_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len, op194, op194_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len, op195, op195_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len, op196, op196_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len, op197, op197_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len, op198, op198_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len, op199, op199_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len, op200, op200_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len, op201, op201_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len, op202, op202_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len + op202_len, op203, op203_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len + op202_len + op203_len, op204, op204_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len + op202_len + op203_len + op204_len, op205, op205_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len + op202_len + op203_len + op204_len + op205_len, op206, op206_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len + op202_len + op203_len + op204_len + op205_len + op206_len, op207, op207_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len + op202_len + op203_len + op204_len + op205_len + op206_len + op207_len, op208, op208_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len + op202_len + op203_len + op204_len + op205_len + op206_len + op207_len + op208_len, op209, op209_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len + op202_len + op203_len + op204_len + op205_len + op206_len + op207_len + op208_len + op209_len, op210, op210_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len + op202_len + op203_len + op204_len + op205_len + op206_len + op207_len + op208_len + op209_len + op210_len, op211, op211_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len + op33_len + op34_len + op35_len + op36_len + op37_len + op38_len + op39_len + op40_len + op41_len + op42_len + op43_len + op44_len + op45_len + op46_len + op47_len + op48_len + op49_len + op50_len + op51_len + op52_len + op53_len + op54_len + op55_len + op56_len + op57_len + op58_len + op59_len + op60_len + op61_len + op62_len + op63_len + op64_len + op65_len + op66_len + op67_len + op68_len + op69_len + op70_len + op71_len + op72_len + op73_len + op74_len + op75_len + op76_len + op77_len + op78_len + op79_len + op80_len + op81_len + op82_len + op83_len + op84_len + op85_len + op86_len + op87_len + op88_len + op89_len + op90_len + op91_len + op92_len + op93_len + op94_len + op95_len + op96_len + op97_len + op98_len + op99_len + op100_len + op101_len + op102_len + op103_len + op104_len + op105_len + op106_len + op107_len + op108_len + op109_len + op110_len + op111_len + op112_len + op113_len + op114_len + op115_len + op116_len + op117_len + op118_len + op119_len + op120_len + op121_len + op122_len + op123_len + op124_len + op125_len + op126_len + op127_len + op128_len + op129_len + op130_len + op131_len + op132_len + op133_len + op134_len + op135_len + op136_len + op137_len + op138_len + op139_len + op140_len + op141_len + op142_len + op143_len + op144_len + op145_len + op146_len + op147_len + op148_len + op149_len + op150_len + op151_len + op152_len + op153_len + op154_len + op155_len + op156_len + op157_len + op158_len + op159_len + op160_len + op161_len + op162_len + op163_len + op164_len + op165_len + op166_len + op167_len + op168_len + op169_len + op170_len + op171_len + op172_len + op173_len + op174_len + op175_len + op176_len + op177_len + op178_len + op179_len + op180_len + op181_len + op182_len + op183_len + op184_len + op185_len + op186_len + op187_len + op188_len + op189_len + op190_len + op191_len + op192_len + op193_len + op194_len + op195_len + op196_len + op197_len + op198_len + op199_len + op200_len + op201_len + op202_len + op203_len + op204_len + op205_len + op206_len + op207_len + op208_len + op209_len + op210_len + op211_len, op212, op212_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_sssvsvssvssssvsvvvvsvs(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, const char *op8, uint32_t op8_len, zval *op9, const char *op10, uint32_t op10_len, const char *op11, uint32_t op11_len, const char *op12, uint32_t op12_len, const char *op13, uint32_t op13_len, zval *op14, const char *op15, uint32_t op15_len, zval *op16, zval *op17, zval *op18, zval *op19, const char *op20, uint32_t op20_len, zval *op21, const char *op22, uint32_t op22_len, int self_var){

	zval result_copy, op4_copy, op6_copy, op9_copy, op14_copy, op16_copy, op17_copy, op18_copy, op19_copy, op21_copy;
	int use_copy = 0, use_copy4 = 0, use_copy6 = 0, use_copy9 = 0, use_copy14 = 0, use_copy16 = 0, use_copy17 = 0, use_copy18 = 0, use_copy19 = 0, use_copy21 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	if (Z_TYPE_P(op9) != IS_STRING) {
	   use_copy9 = zend_make_printable_zval(op9, &op9_copy);
	   if (use_copy9) {
	       op9 = &op9_copy;
	   }
	}

	if (Z_TYPE_P(op14) != IS_STRING) {
	   use_copy14 = zend_make_printable_zval(op14, &op14_copy);
	   if (use_copy14) {
	       op14 = &op14_copy;
	   }
	}

	if (Z_TYPE_P(op16) != IS_STRING) {
	   use_copy16 = zend_make_printable_zval(op16, &op16_copy);
	   if (use_copy16) {
	       op16 = &op16_copy;
	   }
	}

	if (Z_TYPE_P(op17) != IS_STRING) {
	   use_copy17 = zend_make_printable_zval(op17, &op17_copy);
	   if (use_copy17) {
	       op17 = &op17_copy;
	   }
	}

	if (Z_TYPE_P(op18) != IS_STRING) {
	   use_copy18 = zend_make_printable_zval(op18, &op18_copy);
	   if (use_copy18) {
	       op18 = &op18_copy;
	   }
	}

	if (Z_TYPE_P(op19) != IS_STRING) {
	   use_copy19 = zend_make_printable_zval(op19, &op19_copy);
	   if (use_copy19) {
	       op19 = &op19_copy;
	   }
	}

	if (Z_TYPE_P(op21) != IS_STRING) {
	   use_copy21 = zend_make_printable_zval(op21, &op21_copy);
	   if (use_copy21) {
	       op21 = &op21_copy;
	   }
	}

	length = op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len + op12_len + op13_len + Z_STRLEN_P(op14) + op15_len + Z_STRLEN_P(op16) + Z_STRLEN_P(op17) + Z_STRLEN_P(op18) + Z_STRLEN_P(op19) + op20_len + Z_STRLEN_P(op21) + op22_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6), op7, op7_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len, op8, op8_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len, Z_STRVAL_P(op9), Z_STRLEN_P(op9));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9), op10, op10_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len, op11, op11_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len, op12, op12_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len + op12_len, op13, op13_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len + op12_len + op13_len, Z_STRVAL_P(op14), Z_STRLEN_P(op14));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len + op12_len + op13_len + Z_STRLEN_P(op14), op15, op15_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len + op12_len + op13_len + Z_STRLEN_P(op14) + op15_len, Z_STRVAL_P(op16), Z_STRLEN_P(op16));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len + op12_len + op13_len + Z_STRLEN_P(op14) + op15_len + Z_STRLEN_P(op16), Z_STRVAL_P(op17), Z_STRLEN_P(op17));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len + op12_len + op13_len + Z_STRLEN_P(op14) + op15_len + Z_STRLEN_P(op16) + Z_STRLEN_P(op17), Z_STRVAL_P(op18), Z_STRLEN_P(op18));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len + op12_len + op13_len + Z_STRLEN_P(op14) + op15_len + Z_STRLEN_P(op16) + Z_STRLEN_P(op17) + Z_STRLEN_P(op18), Z_STRVAL_P(op19), Z_STRLEN_P(op19));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len + op12_len + op13_len + Z_STRLEN_P(op14) + op15_len + Z_STRLEN_P(op16) + Z_STRLEN_P(op17) + Z_STRLEN_P(op18) + Z_STRLEN_P(op19), op20, op20_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len + op12_len + op13_len + Z_STRLEN_P(op14) + op15_len + Z_STRLEN_P(op16) + Z_STRLEN_P(op17) + Z_STRLEN_P(op18) + Z_STRLEN_P(op19) + op20_len, Z_STRVAL_P(op21), Z_STRLEN_P(op21));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + op8_len + Z_STRLEN_P(op9) + op10_len + op11_len + op12_len + op13_len + Z_STRLEN_P(op14) + op15_len + Z_STRLEN_P(op16) + Z_STRLEN_P(op17) + Z_STRLEN_P(op18) + Z_STRLEN_P(op19) + op20_len + Z_STRLEN_P(op21), op22, op22_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy9) {
	   zval_dtor(op9);
	}

	if (use_copy14) {
	   zval_dtor(op14);
	}

	if (use_copy16) {
	   zval_dtor(op16);
	}

	if (use_copy17) {
	   zval_dtor(op17);
	}

	if (use_copy18) {
	   zval_dtor(op18);
	}

	if (use_copy19) {
	   zval_dtor(op19);
	}

	if (use_copy21) {
	   zval_dtor(op21);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_ssvs(zval *result, const char *op1, uint32_t op1_len, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, int self_var){

	zval result_copy, op3_copy;
	int use_copy = 0, use_copy3 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = op1_len + op2_len + Z_STRLEN_P(op3) + op4_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_sv(zval *result, const char *op1, uint32_t op1_len, zval *op2, int self_var){

	zval result_copy, op2_copy;
	int use_copy = 0, use_copy2 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, int self_var){

	zval result_copy, op2_copy;
	int use_copy = 0, use_copy2 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svssvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, int self_var){

	zval result_copy, op2_copy, op5_copy;
	int use_copy = 0, use_copy2 = 0, use_copy5 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svssvsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, zval *op7, int self_var){

	zval result_copy, op2_copy, op5_copy, op7_copy;
	int use_copy = 0, use_copy2 = 0, use_copy5 = 0, use_copy7 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + op4_len + Z_STRLEN_P(op5) + op6_len, Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsv(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, int self_var){

	zval result_copy, op2_copy, op4_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, int self_var){

	zval result_copy, op2_copy, op4_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, int self_var){

	zval result_copy, op2_copy, op4_copy, op6_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0, use_copy6 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6), op7, op7_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvsvsvsvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, zval *op8, const char *op9, uint32_t op9_len, zval *op10, const char *op11, uint32_t op11_len, int self_var){

	zval result_copy, op2_copy, op4_copy, op6_copy, op8_copy, op10_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0, use_copy6 = 0, use_copy8 = 0, use_copy10 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	if (Z_TYPE_P(op8) != IS_STRING) {
	   use_copy8 = zend_make_printable_zval(op8, &op8_copy);
	   if (use_copy8) {
	       op8 = &op8_copy;
	   }
	}

	if (Z_TYPE_P(op10) != IS_STRING) {
	   use_copy10 = zend_make_printable_zval(op10, &op10_copy);
	   if (use_copy10) {
	       op10 = &op10_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8) + op9_len + Z_STRLEN_P(op10) + op11_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6), op7, op7_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len, Z_STRVAL_P(op8), Z_STRLEN_P(op8));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8), op9, op9_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8) + op9_len, Z_STRVAL_P(op10), Z_STRLEN_P(op10));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len + Z_STRLEN_P(op6) + op7_len + Z_STRLEN_P(op8) + op9_len + Z_STRLEN_P(op10), op11, op11_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy8) {
	   zval_dtor(op8);
	}

	if (use_copy10) {
	   zval_dtor(op10);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, zval *op5, const char *op6, uint32_t op6_len, int self_var){

	zval result_copy, op2_copy, op4_copy, op5_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0, use_copy5 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5) + op6_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5), op6, op6_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvvvvvs(zval *result, const char *op1, uint32_t op1_len, zval *op2, const char *op3, uint32_t op3_len, zval *op4, zval *op5, zval *op6, zval *op7, zval *op8, const char *op9, uint32_t op9_len, int self_var){

	zval result_copy, op2_copy, op4_copy, op5_copy, op6_copy, op7_copy, op8_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0, use_copy5 = 0, use_copy6 = 0, use_copy7 = 0, use_copy8 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	if (Z_TYPE_P(op8) != IS_STRING) {
	   use_copy8 = zend_make_printable_zval(op8, &op8_copy);
	   if (use_copy8) {
	       op8 = &op8_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5) + Z_STRLEN_P(op6) + Z_STRLEN_P(op7) + Z_STRLEN_P(op8) + op9_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5), Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5) + Z_STRLEN_P(op6), Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5) + Z_STRLEN_P(op6) + Z_STRLEN_P(op7), Z_STRVAL_P(op8), Z_STRLEN_P(op8));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + Z_STRLEN_P(op5) + Z_STRLEN_P(op6) + Z_STRLEN_P(op7) + Z_STRLEN_P(op8), op9, op9_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy8) {
	   zval_dtor(op8);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svv(zval *result, const char *op1, uint32_t op1_len, zval *op2, zval *op3, int self_var){

	zval result_copy, op2_copy, op3_copy;
	int use_copy = 0, use_copy2 = 0, use_copy3 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + Z_STRLEN_P(op3);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vs(zval *result, zval *op1, const char *op2, uint32_t op2_len, int self_var){

	zval result_copy, op1_copy;
	int use_copy = 0, use_copy1 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, int self_var){

	zval result_copy, op1_copy, op3_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvs(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, int self_var){

	zval result_copy, op1_copy, op3_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvssvs(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, const char *op5, uint32_t op5_len, zval *op6, const char *op7, uint32_t op7_len, int self_var){

	zval result_copy, op1_copy, op3_copy, op6_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy6 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + op5_len + Z_STRLEN_P(op6) + op7_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + op5_len, Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + op5_len + Z_STRLEN_P(op6), op7, op7_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsv(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsvs(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, const char *op6, uint32_t op6_len, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsvvs(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, const char *op4, uint32_t op4_len, zval *op5, zval *op6, const char *op7, uint32_t op7_len, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy, op6_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0, use_copy6 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + Z_STRLEN_P(op6) + op7_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5), Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + Z_STRLEN_P(op6), op7, op7_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvvssvs(zval *result, zval *op1, const char *op2, uint32_t op2_len, zval *op3, zval *op4, const char *op5, uint32_t op5_len, const char *op6, uint32_t op6_len, zval *op7, const char *op8, uint32_t op8_len, int self_var){

	zval result_copy, op1_copy, op3_copy, op4_copy, op7_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy4 = 0, use_copy7 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + Z_STRLEN_P(op4) + op5_len + op6_len + Z_STRLEN_P(op7) + op8_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + Z_STRLEN_P(op4), op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + Z_STRLEN_P(op4) + op5_len, op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + Z_STRLEN_P(op4) + op5_len + op6_len, Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + Z_STRLEN_P(op4) + op5_len + op6_len + Z_STRLEN_P(op7), op8, op8_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vv(zval *result, zval *op1, zval *op2, int self_var){

	zval result_copy, op1_copy, op2_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vvs(zval *result, zval *op1, zval *op2, const char *op3, uint32_t op3_len, int self_var){

	zval result_copy, op1_copy, op2_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0;
	size_t offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + op3_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2), op3, op3_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_function(zval *result, zval *op1, zval *op2)
{
	zval tmp;
	SEPARATE_ZVAL_IF_NOT_REF(result);

	/*
		res == op1 == op2: won't leak
		res == op1 != op2: won't leak
		res == op2 != op1: will leak
	 */
	if (result == op2 && result != op1) {
		ZVAL_COPY_VALUE(&tmp, result);
		ZVAL_NULL(result);
		op2 = &tmp;
	}
	else {
		ZVAL_UNDEF(&tmp);
	}

	concat_function(result, op1, op2);
	assert(!Z_REFCOUNTED(tmp) || 1 == Z_REFCOUNT(tmp));
	zval_dtor(&tmp);
}