
#ifdef HAVE_CONFIG_H
#include "../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../php_ext.h"
#include "../../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: AttributeBagInterface.php
 * User: solely
 * DateTime: 2020/9/6 23:48
 * Description:
 */
/**
 * Attributes store.
 *
 * Interface AttributeBagInterface
 * @package Moon\Component\Http\Message\Session\Attribute
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\Http\\Message\\Session\\Attribute, AttributeBagInterface, moon, component_http_message_session_attribute_attributebaginterface, moon_component_http_message_session_attribute_attributebaginterface_method_entry);

	zend_class_implements(moon_component_http_message_session_attribute_attributebaginterface_ce, 1, moon_component_http_message_session_sessionbaginterface_ce);
	return SUCCESS;

}

/**
 * Checks if an attribute is defined.
 *
 * @param string $name
 * @return bool        true if the attribute is defined, false otherwise
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, has);

/**
 * Returns an attribute.
 *
 * @param string $name
 * @param null $default     The default value if not found
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, get);

/**
 * Sets an attribute.
 *
 * @param string $name
 * @param $value
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, set);

/**
 * Returns attributes.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, all);

ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, replace);

/**
 * Removes an attribute.
 *
 * @param string $name
 * @return mixed        The removed value or null when it does not exist
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Attribute_AttributeBagInterface, remove);

