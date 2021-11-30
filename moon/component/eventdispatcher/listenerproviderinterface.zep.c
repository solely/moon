
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * FileName: ListenerProviderInterface.php
 * User: solely
 * DateTime: 2019/7/16 22:32
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_EventDispatcher_ListenerProviderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Moon\\Component\\EventDispatcher, ListenerProviderInterface, moon, component_eventdispatcher_listenerproviderinterface, moon_component_eventdispatcher_listenerproviderinterface_method_entry);

	zend_class_implements(moon_component_eventdispatcher_listenerproviderinterface_ce, 1, zephir_get_internal_ce(SL("psrext\\eventdispatcher\\listenerproviderinterface")));
	return SUCCESS;

}

/**
 * Adds a listener to the provider.
 *
 * @param callable $listener
 *   The listener to register.
 * @param int $priority
 *   The numeric priority of the listener. Higher numbers will trigger before lower numbers.
 * @param string $id
 *   The identifier by which this listener should be known. If not specified one will be generated.
 * @param string|null $type
 *   The class or interface type of events for which this listener will be registered. If not provided
 *   it will be derived based on the type hint of the listener.
 * @return string
 *   The opaque ID of the listener.  This can be used for future reference.
 */
ZEPHIR_DOC_METHOD(Moon_Component_EventDispatcher_ListenerProviderInterface, addListener);

/**
 * Adds a listener to trigger before another existing listener.
 *
 * Note: The new listener is only guaranteed to come before the specified existing listener. No guarantee is made
 * regarding when it comes relative to any other listener.
 *
 * @param string $pivotId
 *   The ID of an existing listener.
 * @param callable $listener
 *   The listener to register.
 * @param string $id
 *   The identifier by which this listener should be known. If not specified one will be generated.
 * @param string|null $type
 *   The class or interface type of events for which this listener will be registered. If not provided
 *   it will be derived based on the type hint of the listener.
 * @return string
 *   The opaque ID of the listener.  This can be used for future reference.
 */
ZEPHIR_DOC_METHOD(Moon_Component_EventDispatcher_ListenerProviderInterface, addListenerBefore);

/**
 * Adds a listener to trigger after another existing listener.
 *
 * Note: The new listener is only guaranteed to come after the specified existing listener. No guarantee is made
 * regarding when it comes relative to any other listener.
 *
 * @param string $pivotId
 *   The ID of an existing listener.
 * @param callable $listener
 *   The listener to register.
 * @param string $id
 *   The identifier by which this listener should be known. If not specified one will be generated.
 * @param string|null $type
 *   The class or interface type of events for which this listener will be registered. If not provided
 *   it will be derived based on the type hint of the listener.
 * @return string
 *   The opaque ID of the listener.  This can be used for future reference.
 */
ZEPHIR_DOC_METHOD(Moon_Component_EventDispatcher_ListenerProviderInterface, addListenerAfter);

/**
 * Adds a method on a service as a listener.
 *
 * @param string $serviceName
 *   The name of a service on which this listener lives.
 * @param string $methodName
 *   The method name of the service that is the listener being registered.
 * @param string|null $type
 *   The class or interface type of events for which this listener will be registered.
 * @param int $priority
 *   The numeric priority of the listener. Higher numbers will trigger before lower numbers.
 * @param string $id
 *   The identifier by which this listener should be known. If not specified one will be generated.
 * @return string
 *   The opaque ID of the listener.  This can be used for future reference.
 */
ZEPHIR_DOC_METHOD(Moon_Component_EventDispatcher_ListenerProviderInterface, addListenerService);

/**
 * Adds a service listener to trigger before another existing listener.
 *
 * Note: The new listener is only guaranteed to come before the specified existing listener. No guarantee is made
 * regarding when it comes relative to any other listener.
 *
 * @param string $pivotId
 *   The ID of an existing listener.
 * @param string $serviceName
 *   The name of a service on which this listener lives.
 * @param string $methodName
 *   The method name of the service that is the listener being registered.
 * @param string $type
 *   The class or interface type of events for which this listener will be registered.
 * @param string $id
 *   The identifier by which this listener should be known. If not specified one will be generated.
 * @return string
 *   The opaque ID of the listener.  This can be used for future reference.
 */
ZEPHIR_DOC_METHOD(Moon_Component_EventDispatcher_ListenerProviderInterface, addListenerServiceBefore);

/**
 * Adds a service listener to trigger before another existing listener.
 *
 * Note: The new listener is only guaranteed to come before the specified existing listener. No guarantee is made
 * regarding when it comes relative to any other listener.
 *
 * @param string $pivotId
 *   The ID of an existing listener.
 * @param string $serviceName
 *   The name of a service on which this listener lives.
 * @param string $methodName
 *   The method name of the service that is the listener being registered.
 * @param string $type
 *   The class or interface type of events for which this listener will be registered.
 * @param string $id
 *   The identifier by which this listener should be known. If not specified one will be generated.
 * @return string
 *   The opaque ID of the listener.  This can be used for future reference.
 */
ZEPHIR_DOC_METHOD(Moon_Component_EventDispatcher_ListenerProviderInterface, addListenerServiceAfter);

/**
 * Registers all listener methods on a service as listeners.
 *
 * A method on the specified class is a listener if:
 * - It is public.
 * - It's name is in the form on*.  onUpdate(), onUserLogin(), onHammerTime() will all be registered.
 *
 * The event type the listener is for will be derived from the type hint in the method signature.
 *
 * @param string $class
 *   The class name to be registered as a subscriber.
 * @param string $serviceName
 *   The name of a service in the container.
 */
ZEPHIR_DOC_METHOD(Moon_Component_EventDispatcher_ListenerProviderInterface, addSubscriber);

