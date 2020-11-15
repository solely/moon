
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
#include "kernel/math.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * FileName: TreeNode.php
 * User: solely
 * DateTime: 2020/10/25 17:15
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Router_TreeNode) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\Router, TreeNode, moon, component_router_treenode, moon_component_router_treenode_method_entry, 0);

	zend_declare_property_null(moon_component_router_treenode_ce, SL("regex"), ZEND_ACC_PRIVATE);

	zend_declare_property_long(moon_component_router_treenode_ce, SL("regexTotal"), 0, ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_router_treenode_ce, SL("node"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_router_treenode_ce, SL("children"), ZEND_ACC_PUBLIC);

	moon_component_router_treenode_ce->create_object = zephir_init_properties_Moon_Component_Router_TreeNode;
	return SUCCESS;

}

/**
 * @param $regex
 */
PHP_METHOD(Moon_Component_Router_TreeNode, setRegex) {

	zend_long index = 0;
	zval *regex, regex_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&regex_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	zephir_fetch_params_without_memory_grow(1, 0, &regex);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("regexTotal"), PH_NOISY_CC | PH_READONLY);
	ZVAL_DOUBLE(&_1, zephir_safe_div_zval_long(&_0, 100));
	index = (int) zephir_floor(&_1);
	zephir_update_property_array_multi(this_ptr, SL("regex"), regex, SL("la"), 2, index);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("regexTotal")));

}

/**
 * @return array
 */
PHP_METHOD(Moon_Component_Router_TreeNode, getRegex) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "regex");

}

/**
 * @return int
 */
PHP_METHOD(Moon_Component_Router_TreeNode, getRegexTotal) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "regexTotal");

}

/**
 * @param Node $node
 */
PHP_METHOD(Moon_Component_Router_TreeNode, setNode) {

	zval *node, node_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&node_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &node);



	zephir_update_property_zval(this_ptr, ZEND_STRL("node"), node);

}

/**
 * @return Mixed
 */
PHP_METHOD(Moon_Component_Router_TreeNode, getNode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "node");

}

/**
 * @return array
 */
PHP_METHOD(Moon_Component_Router_TreeNode, getChildren) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "children");

}

zend_object *zephir_init_properties_Moon_Component_Router_TreeNode(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("children"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("children"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("regex"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("regex"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

