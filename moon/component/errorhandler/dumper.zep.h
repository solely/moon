
extern zend_class_entry *moon_component_errorhandler_dumper_ce;

ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Dumper);

PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dump);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, toHtml);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, toText);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, toTerminal);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, __construct);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, asHtml);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, asTerminal);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpVar);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpNull);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpBoolean);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpInteger);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpDouble);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpString);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpArray);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpObject);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, dumpResource);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, toJson);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, formatSnapshotAttribute);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, encodeString);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, truncateString);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, encodeKey);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, exportObject);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, exportClosure);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, exportSplFileInfo);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, exportSplObjectStorage);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, exportPhpIncompleteClass);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, hideValue);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, findLocation);
PHP_METHOD(Moon_Component_ErrorHandler_Dumper, detectColors);
void zephir_init_static_properties_Moon_Component_ErrorHandler_Dumper(TSRMLS_D);
zend_object *zephir_init_properties_Moon_Component_ErrorHandler_Dumper(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_dumper_dump, 0, 0, 1)
	ZEND_ARG_INFO(0, _var)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_tohtml, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_tohtml, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_totext, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_totext, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_toterminal, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_toterminal, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_dumper___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_ashtml, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_ashtml, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_asterminal, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_asterminal, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
	ZEND_ARG_ARRAY_INFO(0, colors, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpvar, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpvar, 0, 2, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpnull, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpnull, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpboolean, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpboolean, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpinteger, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpinteger, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpdouble, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpdouble, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpstring, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpstring, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumparray, 0, 3, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumparray, 0, 3, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpobject, 0, 3, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpobject, 0, 3, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpresource, 0, 3, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_dumpresource, 0, 3, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_dumper_tojson, 0, 0, 1)
	ZEND_ARG_INFO(0, _var)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_formatsnapshotattribute, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_formatsnapshotattribute, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, snapshot, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_encodestring, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_encodestring, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, s, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, s)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, maxLength, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, maxLength)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_truncatestring, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_truncatestring, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, s, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, s)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, maxLength, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, maxLength)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_errorhandler_dumper_encodekey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_exportobject, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_exportobject, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_exportclosure, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_exportclosure, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, obj, Closure, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_exportsplfileinfo, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_exportsplfileinfo, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, obj, SplFileInfo, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_exportsplobjectstorage, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_exportsplobjectstorage, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, obj, SplObjectStorage, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_exportphpincompleteclass, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_exportphpincompleteclass, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, obj, __PHP_Incomplete_Class, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_hidevalue, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_hidevalue, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _var)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_findlocation, 0, 0, IS_ARRAY, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_findlocation, 0, 0, IS_ARRAY, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_detectcolors, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_errorhandler_dumper_detectcolors, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_errorhandler_dumper_method_entry) {
	PHP_ME(Moon_Component_ErrorHandler_Dumper, dump, arginfo_moon_component_errorhandler_dumper_dump, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, toHtml, arginfo_moon_component_errorhandler_dumper_tohtml, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, toText, arginfo_moon_component_errorhandler_dumper_totext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, toTerminal, arginfo_moon_component_errorhandler_dumper_toterminal, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, __construct, arginfo_moon_component_errorhandler_dumper___construct, ZEND_ACC_PRIVATE|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, asHtml, arginfo_moon_component_errorhandler_dumper_ashtml, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, asTerminal, arginfo_moon_component_errorhandler_dumper_asterminal, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, dumpVar, arginfo_moon_component_errorhandler_dumper_dumpvar, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, dumpNull, arginfo_moon_component_errorhandler_dumper_dumpnull, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, dumpBoolean, arginfo_moon_component_errorhandler_dumper_dumpboolean, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, dumpInteger, arginfo_moon_component_errorhandler_dumper_dumpinteger, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, dumpDouble, arginfo_moon_component_errorhandler_dumper_dumpdouble, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, dumpString, arginfo_moon_component_errorhandler_dumper_dumpstring, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, dumpArray, arginfo_moon_component_errorhandler_dumper_dumparray, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, dumpObject, arginfo_moon_component_errorhandler_dumper_dumpobject, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, dumpResource, arginfo_moon_component_errorhandler_dumper_dumpresource, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, toJson, arginfo_moon_component_errorhandler_dumper_tojson, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, formatSnapshotAttribute, arginfo_moon_component_errorhandler_dumper_formatsnapshotattribute, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, encodeString, arginfo_moon_component_errorhandler_dumper_encodestring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, truncateString, arginfo_moon_component_errorhandler_dumper_truncatestring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, encodeKey, arginfo_moon_component_errorhandler_dumper_encodekey, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, exportObject, arginfo_moon_component_errorhandler_dumper_exportobject, ZEND_ACC_PRIVATE)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, exportClosure, arginfo_moon_component_errorhandler_dumper_exportclosure, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, exportSplFileInfo, arginfo_moon_component_errorhandler_dumper_exportsplfileinfo, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, exportSplObjectStorage, arginfo_moon_component_errorhandler_dumper_exportsplobjectstorage, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, exportPhpIncompleteClass, arginfo_moon_component_errorhandler_dumper_exportphpincompleteclass, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, hideValue, arginfo_moon_component_errorhandler_dumper_hidevalue, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, findLocation, arginfo_moon_component_errorhandler_dumper_findlocation, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Moon_Component_ErrorHandler_Dumper, detectColors, arginfo_moon_component_errorhandler_dumper_detectcolors, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
