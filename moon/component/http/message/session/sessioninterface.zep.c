
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: SessionInterface.php
 * User: solely
 * DateTime: 2020/9/13 23:27
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_SessionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\Http\\Message\\Session, SessionInterface, moon, component_http_message_session_sessioninterface, moon_component_http_message_session_sessioninterface_method_entry);

	return SUCCESS;

}

/**
 * Starts the session storage.
 *
 * @return bool
 *
 * @throws \RuntimeException if session fails to start
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, start);

/**
 * Returns the session ID.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, getId);

/**
 * Sets the session ID.
 * @param string $id
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, setId);

/**
 * Returns the session name.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, getName);

/**
 * Sets the session name.
 * @param string $name
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, setName);

/**
 * Invalidates the current session.
 *
 * Clears all session attributes and flashes and regenerates the
 * session and deletes the old session from persistence.
 *
 * @param int $lifetime Sets the cookie lifetime for the session cookie. A null value
 *                      will leave the system settings unchanged, 0 sets the cookie
 *                      to expire with browser session. Time is in seconds, and is
 *                      not a Unix timestamp.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, invalidate);

/**
 * Migrates the current session to a new session id while maintaining all
 * session attributes.
 *
 * @param bool $destroy  Whether to delete the old session or leave it to garbage collection
 * @param int  $lifetime Sets the cookie lifetime for the session cookie. A null value
 *                       will leave the system settings unchanged, 0 sets the cookie
 *                       to expire with browser session. Time is in seconds, and is
 *                       not a Unix timestamp.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, migrate);

/**
 * Force the session to be saved and closed.
 *
 * This method is generally not required for real sessions as
 * the session will be automatically saved at the end of
 * code execution.
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, save);

/**
 * Checks if an attribute is defined.
 *
 * @param string $name
 * @return bool
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, has);

/**
 * Returns an attribute.
 *
 * @param string $name
 * @param mixed $default The default value if not found
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, get);

/**
 * Sets an attribute.
 *
 * @param string $name
 * @param mixed $value
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, set);

/**
 * Returns attributes.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, all);

/**
 * Sets attributes.
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, replace);

/**
 * Removes an attribute.
 *
 * @param string $name
 * @return mixed The removed value or null when it does not exist
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, remove);

/**
 * Clears all attributes.
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, clear);

/**
 * Checks if the session was started.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, isStarted);

/**
 * Registers a SessionBagInterface with the session.
 *
 * @param SessionBagInterface $bag
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, registerBag);

/**
 * Gets a bag instance by name.
 *
 * @param  $name
 * @return SessionBagInterface
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, getBag);

/**
 * Gets session meta.
 *
 * @return MetadataBag
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_SessionInterface, getMetadataBag);

