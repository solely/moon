
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


/**
 * FileName: FinishRequestEvent.php
 * User: solely
 * DateTime: 2020/7/26 0:07
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Framework_Event_Event_FinishRequestEvent) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Framework\\Event\\Event, FinishRequestEvent, moon, framework_event_event_finishrequestevent, moon_framework_event_event_kernelevent_ce, NULL, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

