
#ifdef HAVE_CONFIG_H
#include "../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../php_ext.h"
#include "../../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: SessionStorageInterface.php
 * User: solely
 * DateTime: 2020/9/7 23:47
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\Http\\Message\\Session\\Storage, SessionStorageInterface, moon, component_http_message_session_storage_sessionstorageinterface, moon_component_http_message_session_storage_sessionstorageinterface_method_entry);

	return SUCCESS;

}

/**
 * Starts the session.
 *
 * @return bool True if started
 *
 * @throws \RuntimeException if something goes wrong starting the session
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, start);

/**
 * Checks if the session is started.
 *
 * @return bool True if started, false otherwise
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, isStarted);

/**
 * Returns the session ID.
 *
 * @return string The session ID or empty
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, getId);

/**
 * Sets the session ID.
 * @param string $id
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, setId);

/**
 * Returns the session name.
 *
 * @return string The session name
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, getName);

/**
 * Sets the session name.
 * @param string $name
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, setName);

/**
 * Regenerates id that represents this storage.
 *
 * This method must invoke session_regenerate_id($destroy) unless
 * this interface is used for a storage object designed for unit
 * or functional testing where a real PHP session would interfere
 * with testing.
 *
 * Note regenerate+destroy should not clear the session data in memory
 * only delete the session data from persistent storage.
 *
 * Care: When regenerating the session ID no locking is involved in PHP's
 * session design. See https://bugs.php.net/61470 for a discussion.
 * So you must make sure the regenerated session is saved BEFORE sending the
 * headers with the new ID. Symfony's HttpKernel offers a listener for this.
 * See Symfony\Component\HttpKernel\EventListener\SaveSessionListener.
 * Otherwise session data could get lost again for concurrent requests with the
 * new ID. One result could be that you get logged out after just logging in.
 *
 * @param bool $destroy  Destroy session when regenerating?
 * @param int  $lifetime Sets the cookie lifetime for the session cookie. A null value
 *                       will leave the system settings unchanged, 0 sets the cookie
 *                       to expire with browser session. Time is in seconds, and is
 *                       not a Unix timestamp.
 *
 * @return bool True if session regenerated, false if error
 *
 * @throws \RuntimeException If an error occurs while regenerating this storage
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, regenerate);

/**
 * Force the session to be saved and closed.
 *
 * This method must invoke session_write_close() unless this interface is
 * used for a storage object design for unit or functional testing where
 * a real PHP session would interfere with testing, in which case
 * it should actually persist the session data if required.
 *
 * @throws \RuntimeException if the session is saved without being started, or if the session
 *                           is already closed
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, save);

/**
 * Clear all session data in memory.
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, clear);

/**
 * Gets a SessionBagInterface by name.
 *
 * @param string $name
 * @return SessionBagInterface
 *
 * @throws \InvalidArgumentException If the bag does not exist
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, getBag);

/**
 * @param SessionBagInterface $bag
 * Registers a SessionBagInterface for use.
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, registerBag);

/**
 * @return MetadataBag
 */
ZEPHIR_DOC_METHOD(Moon_Component_Http_Message_Session_Storage_SessionStorageInterface, getMetadataBag);

