
#ifdef HAVE_CONFIG_H
#include "../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../php_ext.h"
#include "../../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: FlashBagInterface.php
 * User: solely
 * DateTime: 2020/9/6 23:57
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Flash_FlashBagInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\Http\\Message\\Session\\Flash, FlashBagInterface, moon, component_http_message_session_flash_flashbaginterface, moon_component_http_message_session_flash_flashbaginterface_method_entry);

	zend_class_implements(moon_component_http_message_session_flash_flashbaginterface_ce, 1, moon_component_http_message_session_sessionbaginterface_ce);
	return SUCCESS;

}

/**
 * Adds a flash message for the given type.
 *
 * @param string $type
 * @param mixed $message
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, add);

/**
 * Registers one or more messages for a given type.
 *
 * @param string $type
 * @param string|array $messages
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, set);

/**
 * Gets flash messages for a given type.
 *
 * @param string $type    Message category type
 * @param array  $default Default value if $type does not exist
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, peek);

/**
 * Gets all flash messages.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, peekAll);

/**
 * Gets and clears flash from the stack.
 *
 * @param string $type
 * @param array $default Default value if $type does not exist
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, get);

/**
 * Gets and clears flashes from the stack.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, all);

/**
 * Sets all flash messages.
 *
 * @param array $messages
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, setAll);

/**
 * Has flash messages for a given type?
 *
 * @param string $type
 * @return bool
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, has);

/**
 * Returns a list of all defined types.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Flash_FlashBagInterface, keys);

