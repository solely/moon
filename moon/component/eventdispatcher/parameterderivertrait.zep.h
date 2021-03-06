
extern zend_class_entry *moon_component_eventdispatcher_parameterderivertrait_ce;

ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ParameterDeriverTrait);

PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, getParameterType);
PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, isFunctionCallable);
PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, isClosureCallable);
PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, isObjectCallable);
PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, isClassCallable);
PHP_METHOD(Moon_Component_EventDispatcher_ParameterDeriverTrait, isInvokable);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_getparametertype, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_getparametertype, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _callable)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_isfunctioncallable, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_isfunctioncallable, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _callable)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_isclosurecallable, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_isclosurecallable, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _callable)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_isobjectcallable, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_isobjectcallable, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _callable)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_isclasscallable, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_isclasscallable, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _callable)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_isinvokable, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_eventdispatcher_parameterderivertrait_isinvokable, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _callable)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_eventdispatcher_parameterderivertrait_method_entry) {
	PHP_ME(Moon_Component_EventDispatcher_ParameterDeriverTrait, getParameterType, arginfo_moon_component_eventdispatcher_parameterderivertrait_getparametertype, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_EventDispatcher_ParameterDeriverTrait, isFunctionCallable, arginfo_moon_component_eventdispatcher_parameterderivertrait_isfunctioncallable, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_EventDispatcher_ParameterDeriverTrait, isClosureCallable, arginfo_moon_component_eventdispatcher_parameterderivertrait_isclosurecallable, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_EventDispatcher_ParameterDeriverTrait, isObjectCallable, arginfo_moon_component_eventdispatcher_parameterderivertrait_isobjectcallable, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_EventDispatcher_ParameterDeriverTrait, isClassCallable, arginfo_moon_component_eventdispatcher_parameterderivertrait_isclasscallable, ZEND_ACC_PROTECTED)
	PHP_ME(Moon_Component_EventDispatcher_ParameterDeriverTrait, isInvokable, arginfo_moon_component_eventdispatcher_parameterderivertrait_isinvokable, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
