
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
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * FileName: Table.php
 * User: solely
 * DateTime: 2020/4/13 23:16
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Table) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\ErrorHandler, Table, moon, component_errorhandler_table, moon_component_errorhandler_table_method_entry, 0);

	/** @var string */
	zend_declare_property_null(moon_component_errorhandler_table_ce, SL("title"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_table_ce, SL("content"), ZEND_ACC_PRIVATE);

	moon_component_errorhandler_table_ce->create_object = zephir_init_properties_Moon_Component_ErrorHandler_Table;
	return SUCCESS;

}

/**
 * @param string $title
 * @return Table
 */
PHP_METHOD(Moon_Component_ErrorHandler_Table, setTitle) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *title_param = NULL;
	zval title;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_strval(&title, title_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("title"), &title);
	RETURN_THIS();

}

/**
 * @return string
 */
PHP_METHOD(Moon_Component_ErrorHandler_Table, getTitle) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "title");

}

/**
 * @param array $content
 * @return Table
 */
PHP_METHOD(Moon_Component_ErrorHandler_Table, setContent) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *content_param = NULL;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_arrval(&content, content_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("content"), &content);
	RETURN_THIS();

}

/**
 * @return array
 */
PHP_METHOD(Moon_Component_ErrorHandler_Table, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "content");

}

zend_object *zephir_init_properties_Moon_Component_ErrorHandler_Table(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("content"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("content"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

