
extern zend_class_entry *moon_component_router_treenode_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Router_TreeNode);

PHP_METHOD(Moon_Component_Router_TreeNode, setRegex);
PHP_METHOD(Moon_Component_Router_TreeNode, getRegex);
PHP_METHOD(Moon_Component_Router_TreeNode, getRegexTotal);
PHP_METHOD(Moon_Component_Router_TreeNode, setNode);
PHP_METHOD(Moon_Component_Router_TreeNode, getNode);
PHP_METHOD(Moon_Component_Router_TreeNode, getChildren);
zend_object *zephir_init_properties_Moon_Component_Router_TreeNode(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_treenode_setregex, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_treenode_setregex, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_treenode_setregex, 0, 0, 1)
#define arginfo_moon_component_router_treenode_setregex NULL
#endif

	ZEND_ARG_INFO(0, regex)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_treenode_getregex, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_treenode_getregex, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_treenode_getregextotal, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_treenode_getregextotal, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_treenode_setnode, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_treenode_setnode, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_router_treenode_setnode, 0, 0, 1)
#define arginfo_moon_component_router_treenode_setnode NULL
#endif

	ZEND_ARG_OBJ_INFO(0, node, Moon\\Component\\Router\\Node, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_treenode_getchildren, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_router_treenode_getchildren, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_router_treenode_method_entry) {
	PHP_ME(Moon_Component_Router_TreeNode, setRegex, arginfo_moon_component_router_treenode_setregex, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_TreeNode, getRegex, arginfo_moon_component_router_treenode_getregex, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_TreeNode, getRegexTotal, arginfo_moon_component_router_treenode_getregextotal, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_TreeNode, setNode, arginfo_moon_component_router_treenode_setnode, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_TreeNode, getNode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Router_TreeNode, getChildren, arginfo_moon_component_router_treenode_getchildren, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
