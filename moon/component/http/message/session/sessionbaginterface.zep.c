
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: SessionBagInterface.php
 * User: solely
 * DateTime: 2020/9/6 23:46
 * Description:
 */
/**
 * Session Bag store.
 *
 * Interface SessionBagInterface
 * @package Moon\Component\Http\Message\Session
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_SessionBagInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\Http\\Message\\Session, SessionBagInterface, moon, component_http_message_session_sessionbaginterface, moon_component_http_message_session_sessionbaginterface_method_entry);

	return SUCCESS;

}

/**
 * Gets this bag's name.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionBagInterface, getName);

/**
 * Initializes the Bag.
 *
 * @param array $array
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionBagInterface, initialize);

/**
 * Gets the storage key for this bag.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionBagInterface, getStorageKey);

/**
 * Clears out data from bag.
 *
 * @return mixed Whatever data was contained
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionBagInterface, clear);

