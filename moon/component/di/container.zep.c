
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "Zend/zend_closures.h"
#include "kernel/exception.h"


/**
 * FileName: Container.php
 * User: solely
 * DateTime: 2019/4/7 19:12
 * Description:
 *
 * set()
 * set 方法一般用来设置 service 的。由 Inject 设置 service 。
 * get()
 * get 方法一般用来获取 service 的。由 Delegator 获取 service 。
 * has()
 * has 方法用来判断 service（服务）是否存在。
 * PSR11中的 resolve、Delegator、Inject
 * resolve 由委托（Delegator）调用，就是延迟加载；由注入（Inject）调用，就是预加载。 2019年6月18日22:07:30
 */
ZEPHIR_INIT_CLASS(Moon_Component_DI_Container) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\DI, Container, moon, component_di_container, moon_component_di_container_method_entry, 0);

	zend_declare_property_null(moon_component_di_container_ce, SL("instance"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_null(moon_component_di_container_ce, SL("service"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_di_container_ce, SL("serviceContainer"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_di_container_ce, SL("inject"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_di_container_ce, SL("delegator"), ZEND_ACC_PRIVATE);

	zend_declare_property_bool(moon_component_di_container_ce, SL("defaultIsLazy"), 1, ZEND_ACC_PRIVATE);

	moon_component_di_container_ce->create_object = zephir_init_properties_Moon_Component_DI_Container;
	zephir_declare_class_constant_bool(moon_component_di_container_ce, SL("LAZY_LOADING_ON"), 1);

	zephir_declare_class_constant_bool(moon_component_di_container_ce, SL("LAZY_LOAD_OFF"), 0);

	zend_class_implements(moon_component_di_container_ce, 1, moon_component_di_mooncontainerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_DI_Container, __construct) {

	zval *inject, inject_sub, *delegator, delegator_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inject_sub);
	ZVAL_UNDEF(&delegator_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &inject, &delegator);



	zephir_update_property_zval(this_ptr, ZEND_STRL("inject"), inject);
	zephir_update_property_zval(this_ptr, ZEND_STRL("delegator"), delegator);

}

PHP_METHOD(Moon_Component_DI_Container, get) {

	zval _14$$7;
	zend_bool _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, service, _0, _3, _7, _15, _1$$3, _2$$3, _4$$4, _5$$4, _8$$5, _9$$6, _10$$6, _12$$6, _13$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("serviceContainer"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, id)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("serviceContainer"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, id, PH_NOISY | PH_READONLY, "moon/Component/DI/Container.zep", 43);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("service"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_3, id)) {
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("service"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_5$$4, &_4$$4, id, PH_NOISY | PH_READONLY, "moon/Component/DI/Container.zep", 46);
		ZEPHIR_CPY_WRT(&service, &_5$$4);
	}
	_6 = ZEPHIR_IS_EMPTY(&service);
	if (_6) {
		ZEPHIR_OBS_VAR(&_7);
		zephir_read_property(&_7, this_ptr, ZEND_STRL("delegator"), PH_NOISY_CC);
		_6 = !(ZEPHIR_IS_EMPTY(&_7));
	}
	if (_6) {
		zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("delegator"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&service, &_8$$5, "get", NULL, 0, id);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("service"), id, &service);
	}
	if (zephir_instance_of_ev(&service, moon_component_di_resolver_medium_ce)) {
		ZEPHIR_INIT_VAR(&_9$$6);
		object_init_ex(&_9$$6, moon_component_di_resolver_resolver_ce);
		ZEPHIR_CALL_CE_STATIC(&_10$$6, moon_component_di_resolver_reflector_ce, "getinstance", &_11, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", NULL, 22, &_10$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_12$$6, &_9$$6, "resolve", NULL, 23, &service);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&service, &_12$$6);
	} else if (zephir_instance_of_ev(&service, zend_ce_closure)) {
		ZEPHIR_INIT_VAR(&_13$$7);
		ZEPHIR_INIT_VAR(&_14$$7);
		zephir_create_array(&_14$$7, 1, 0);
		zephir_array_fast_append(&_14$$7, this_ptr);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_13$$7, &service, &_14$$7);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&service, &_13$$7);
	}
	if (!(ZEPHIR_IS_EMPTY(&service))) {
		zephir_update_property_array(this_ptr, SL("serviceContainer"), id, &service);
		RETURN_CCTOR(&service);
	}
	ZEPHIR_CALL_CE_STATIC(&_15, moon_component_di_exception_ce, "notfoundexception", &_16, 0, id);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_15, "moon/Component/DI/Container.zep", 61);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Moon_Component_DI_Container, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, _0, _1, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("service"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, id)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("delegator"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_1))) {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("delegator"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_2$$4, "has", NULL, 0, id);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Moon_Component_DI_Container, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *id_param = NULL, *parameters, parameters_sub, callback, _0, _3, _4, _1$$3;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id_param, &parameters);

	zephir_get_strval(&id, id_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("service"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &id)) {
		ZEPHIR_CALL_CE_STATIC(&_1$$3, moon_component_di_exception_ce, "containerexistingexception", &_2, 0, &id);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "moon/Component/DI/Container.zep", 82);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("inject"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&callback, &_3, "factory", NULL, 0, parameters, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_ZVAL_FUNCTION(&_4, &callback, NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("service"), &id, &_4);
	RETURN_THIS();

}

/**
 * @param InjectInterface $inject
 * @param DelegatorInterface $delegator
 * @return Container
 */
PHP_METHOD(Moon_Component_DI_Container, getInstance) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *inject, inject_sub, *delegator, delegator_sub, _0, _2, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inject_sub);
	ZVAL_UNDEF(&delegator_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &inject, &delegator);



	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, moon_component_di_container_ce, SL("instance"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, moon_component_di_container_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 78, inject, delegator);
		zephir_check_call_status();
		zephir_update_static_property_ce(moon_component_di_container_ce, ZEND_STRL("instance"), &_1$$3);
	}
	zephir_read_static_property_ce(&_2, moon_component_di_container_ce, SL("instance"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTOR(&_2);

}

/**
 * @param bool $defaultIsLazy
 */
PHP_METHOD(Moon_Component_DI_Container, setDefaultIsLazy) {

	zval *defaultIsLazy_param = NULL, __$true, __$false;
	zend_bool defaultIsLazy;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &defaultIsLazy_param);

	defaultIsLazy = zephir_get_boolval(defaultIsLazy_param);


	if (defaultIsLazy) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultIsLazy"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultIsLazy"), &__$false);
	}

}

/**
 * @return bool
 */
PHP_METHOD(Moon_Component_DI_Container, getDefaultIsLazy) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultIsLazy");

}

zend_object *zephir_init_properties_Moon_Component_DI_Container(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("serviceContainer"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("serviceContainer"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("service"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("service"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

