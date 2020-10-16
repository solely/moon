
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
 * FileName: Panel.php
 * User: solely
 * DateTime: 2020/4/13 23:12
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Panel) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\ErrorHandler, Panel, moon, component_errorhandler_panel, moon_component_errorhandler_panel_method_entry, 0);

	/** @var string */
	zend_declare_property_null(moon_component_errorhandler_panel_ce, SL("title"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_panel_ce, SL("content"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

/**
 * @param string $title
 * @return Panel
 */
PHP_METHOD(Moon_Component_ErrorHandler_Panel, setTitle) {

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
PHP_METHOD(Moon_Component_ErrorHandler_Panel, getTitle) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "title");

}

/**
 * @param Table $content
 * @return Panel
 */
PHP_METHOD(Moon_Component_ErrorHandler_Panel, setContent) {

	zval *content, content_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &content);



	zephir_update_property_array_append(this_ptr, SL("content"), content);
	RETURN_THISW();

}

/**
 * @return mixed
 */
PHP_METHOD(Moon_Component_ErrorHandler_Panel, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "content");

}

