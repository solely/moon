
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
 * FileName: ListenerEventEntry.php
 * User: solely
 * DateTime: 2019/10/5 11:00
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerEventEntry) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\EventDispatcher, ListenerEventEntry, moon, component_eventdispatcher_listenerevententry, moon_component_eventdispatcher_listenerevententry_method_entry, 0);

	/** @var callable */
	zend_declare_property_null(moon_component_eventdispatcher_listenerevententry_ce, SL("listener"), ZEND_ACC_PUBLIC);

	/** @var string */
	zend_declare_property_null(moon_component_eventdispatcher_listenerevententry_ce, SL("type"), ZEND_ACC_PUBLIC);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_EventDispatcher_ListenerEventEntry, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval type;
	zval *listener, listener_sub, *type_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&listener_sub);
	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &listener, &type_param);

	zephir_get_strval(&type, type_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("listener"), listener);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
	ZEPHIR_MM_RESTORE();

}

