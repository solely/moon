
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "moon.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *moon_component_di_delegatorinterface_ce;
zend_class_entry *moon_component_di_injectinterface_ce;
zend_class_entry *moon_component_di_mooncontainerinterface_ce;
zend_class_entry *moon_component_eventdispatcher_listenerproviderinterface_ce;
zend_class_entry *moon_component_eventdispatcher_subscriberinterface_ce;
zend_class_entry *moon_component_router_routerinterface_ce;
zend_class_entry *moon_framework_bootstrapinterface_ce;
zend_class_entry *moon_framework_controller_controllerargumentsresolverinterface_ce;
zend_class_entry *moon_framework_controller_controllerresolverinterface_ce;
zend_class_entry *moon_framework_exception_httpexceptioninterface_ce;
zend_class_entry *moon_framework_modulesinterface_ce;
zend_class_entry *moon_component_http_message_message_ce;
zend_class_entry *moon_component_eventdispatcher_event_ce;
zend_class_entry *moon_framework_event_event_kernelevent_ce;
zend_class_entry *moon_component_http_message_response_ce;
zend_class_entry *moon_component_di_inject_inject_ce;
zend_class_entry *moon_component_config_parser_abstractparser_ce;
zend_class_entry *moon_component_di_exception_containerexception_ce;
zend_class_entry *moon_component_eventdispatcher_parameterderivertrait_ce;
zend_class_entry *moon_component_http_message_parameterbag_ce;
zend_class_entry *moon_component_http_message_request_ce;
zend_class_entry *moon_framework_event_event_requestevent_ce;
zend_class_entry *moon_component_eventdispatcher_listenerproviderutiltrait_ce;
zend_class_entry *moon_component_http_message_serverrequest_ce;
zend_class_entry *moon_0__closure_ce;
zend_class_entry *moon_1__closure_ce;
zend_class_entry *moon_component_config_config_ce;
zend_class_entry *moon_component_config_exception_ce;
zend_class_entry *moon_component_config_exception_notfoundexception_ce;
zend_class_entry *moon_component_config_exception_parserexception_ce;
zend_class_entry *moon_component_config_parser_iniparser_ce;
zend_class_entry *moon_component_config_parser_parserfactory_ce;
zend_class_entry *moon_component_config_parser_phpparser_ce;
zend_class_entry *moon_component_config_parser_yaml_ce;
zend_class_entry *moon_component_config_reader_loader_ce;
zend_class_entry *moon_component_di_container_ce;
zend_class_entry *moon_component_di_delegator_ce;
zend_class_entry *moon_component_di_exception_ce;
zend_class_entry *moon_component_di_exception_containerexistingexception_ce;
zend_class_entry *moon_component_di_exception_notfoundexception_ce;
zend_class_entry *moon_component_di_exception_resolverexception_ce;
zend_class_entry *moon_component_di_inject_arrayinject_ce;
zend_class_entry *moon_component_di_inject_callableinject_ce;
zend_class_entry *moon_component_di_inject_ce;
zend_class_entry *moon_component_di_inject_objectinject_ce;
zend_class_entry *moon_component_di_inject_stringinject_ce;
zend_class_entry *moon_component_di_resolver_autoresolver_ce;
zend_class_entry *moon_component_di_resolver_defaultvalueparam_ce;
zend_class_entry *moon_component_di_resolver_medium_ce;
zend_class_entry *moon_component_di_resolver_reflector_ce;
zend_class_entry *moon_component_di_resolver_resolver_ce;
zend_class_entry *moon_component_di_resolver_stringresolver_ce;
zend_class_entry *moon_component_di_resolver_unresolvedparam_ce;
zend_class_entry *moon_component_eventdispatcher_debugeventdispatcher_ce;
zend_class_entry *moon_component_eventdispatcher_eventdispatcher_ce;
zend_class_entry *moon_component_eventdispatcher_exception_ce;
zend_class_entry *moon_component_eventdispatcher_exception_containermissingexception_ce;
zend_class_entry *moon_component_eventdispatcher_exception_eventdispatcherexception_ce;
zend_class_entry *moon_component_eventdispatcher_exception_runtimeexception_ce;
zend_class_entry *moon_component_eventdispatcher_exception_unimplementedmethodsexception_ce;
zend_class_entry *moon_component_eventdispatcher_listenercollection_ce;
zend_class_entry *moon_component_eventdispatcher_listenerevententry_ce;
zend_class_entry *moon_component_eventdispatcher_listeneritems_ce;
zend_class_entry *moon_component_eventdispatcher_listenerprovider_ce;
zend_class_entry *moon_component_eventdispatcher_listenerprovidercallback_ce;
zend_class_entry *moon_component_eventdispatcher_listenerproviderproxy_ce;
zend_class_entry *moon_component_http_message_clirequest_ce;
zend_class_entry *moon_component_http_message_cookie_ce;
zend_class_entry *moon_component_http_message_emptyresponse_ce;
zend_class_entry *moon_component_http_message_exception_invalidargumentexception_ce;
zend_class_entry *moon_component_http_message_exception_uploadedfileexception_ce;
zend_class_entry *moon_component_http_message_filebag_ce;
zend_class_entry *moon_component_http_message_headerbag_ce;
zend_class_entry *moon_component_http_message_headerutils_ce;
zend_class_entry *moon_component_http_message_htmlresponse_ce;
zend_class_entry *moon_component_http_message_jsonresponse_ce;
zend_class_entry *moon_component_http_message_redirectresponse_ce;
zend_class_entry *moon_component_http_message_serverbag_ce;
zend_class_entry *moon_component_http_message_stream_ce;
zend_class_entry *moon_component_http_message_streamedresponse_ce;
zend_class_entry *moon_component_http_message_uploadedfile_ce;
zend_class_entry *moon_component_http_message_uri_ce;
zend_class_entry *moon_component_router_argument_ce;
zend_class_entry *moon_component_router_exception_ce;
zend_class_entry *moon_component_router_exception_notfoundexception_ce;
zend_class_entry *moon_component_router_exception_routerexception_ce;
zend_class_entry *moon_component_router_handler_ce;
zend_class_entry *moon_component_router_node_ce;
zend_class_entry *moon_component_router_router_ce;
zend_class_entry *moon_component_router_treenode_ce;
zend_class_entry *moon_framework_bootstrap_ce;
zend_class_entry *moon_framework_controller_abstractcontroller_ce;
zend_class_entry *moon_framework_controller_controllerargumentsresolver_ce;
zend_class_entry *moon_framework_controller_controllerresolver_ce;
zend_class_entry *moon_framework_event_event_ce;
zend_class_entry *moon_framework_event_event_controllerargumentsevent_ce;
zend_class_entry *moon_framework_event_event_controllerevent_ce;
zend_class_entry *moon_framework_event_event_exceptionevent_ce;
zend_class_entry *moon_framework_event_event_finishrequestevent_ce;
zend_class_entry *moon_framework_event_event_responseevent_ce;
zend_class_entry *moon_framework_event_event_viewevent_ce;
zend_class_entry *moon_framework_event_listener_controllerlistener_ce;
zend_class_entry *moon_framework_event_listener_requestlistener_ce;
zend_class_entry *moon_framework_event_listener_routersubscriber_ce;
zend_class_entry *moon_framework_exception_controllerexception_ce;
zend_class_entry *moon_framework_exception_httpexception_ce;
zend_class_entry *moon_framework_kernel_ce;

ZEND_DECLARE_MODULE_GLOBALS(moon)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(moon)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Moon_Component_DI_DelegatorInterface);
	ZEPHIR_INIT(Moon_Component_DI_InjectInterface);
	ZEPHIR_INIT(Moon_Component_DI_MoonContainerInterface);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_ListenerProviderInterface);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_SubscriberInterface);
	ZEPHIR_INIT(Moon_Component_Router_RouterInterface);
	ZEPHIR_INIT(Moon_Framework_BootstrapInterface);
	ZEPHIR_INIT(Moon_Framework_Controller_ControllerArgumentsResolverInterface);
	ZEPHIR_INIT(Moon_Framework_Controller_ControllerResolverInterface);
	ZEPHIR_INIT(Moon_Framework_Exception_HttpExceptionInterface);
	ZEPHIR_INIT(Moon_Framework_ModulesInterface);
	ZEPHIR_INIT(Moon_Component_Http_Message_Message);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_Event);
	ZEPHIR_INIT(Moon_Framework_Event_Event_KernelEvent);
	ZEPHIR_INIT(Moon_Component_Http_Message_Response);
	ZEPHIR_INIT(Moon_Component_DI_Inject_Inject);
	ZEPHIR_INIT(Moon_Component_Config_Parser_AbstractParser);
	ZEPHIR_INIT(Moon_Component_DI_Exception_ContainerException);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_ParameterDeriverTrait);
	ZEPHIR_INIT(Moon_Component_Http_Message_ParameterBag);
	ZEPHIR_INIT(Moon_Component_Http_Message_Request);
	ZEPHIR_INIT(Moon_Framework_Event_Event_RequestEvent);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_ListenerProviderUtilTrait);
	ZEPHIR_INIT(Moon_Component_Http_Message_ServerRequest);
	ZEPHIR_INIT(Moon_Component_Config_Config);
	ZEPHIR_INIT(Moon_Component_Config_Exception);
	ZEPHIR_INIT(Moon_Component_Config_Exception_NotFoundException);
	ZEPHIR_INIT(Moon_Component_Config_Exception_ParserException);
	ZEPHIR_INIT(Moon_Component_Config_Parser_INIParser);
	ZEPHIR_INIT(Moon_Component_Config_Parser_PHPParser);
	ZEPHIR_INIT(Moon_Component_Config_Parser_ParserFactory);
	ZEPHIR_INIT(Moon_Component_Config_Parser_Yaml);
	ZEPHIR_INIT(Moon_Component_Config_Reader_Loader);
	ZEPHIR_INIT(Moon_Component_DI_Container);
	ZEPHIR_INIT(Moon_Component_DI_Delegator);
	ZEPHIR_INIT(Moon_Component_DI_Exception);
	ZEPHIR_INIT(Moon_Component_DI_Exception_ContainerExistingException);
	ZEPHIR_INIT(Moon_Component_DI_Exception_NotFoundException);
	ZEPHIR_INIT(Moon_Component_DI_Exception_ResolverException);
	ZEPHIR_INIT(Moon_Component_DI_Inject);
	ZEPHIR_INIT(Moon_Component_DI_Inject_ArrayInject);
	ZEPHIR_INIT(Moon_Component_DI_Inject_CallableInject);
	ZEPHIR_INIT(Moon_Component_DI_Inject_ObjectInject);
	ZEPHIR_INIT(Moon_Component_DI_Inject_StringInject);
	ZEPHIR_INIT(Moon_Component_DI_Resolver_AutoResolver);
	ZEPHIR_INIT(Moon_Component_DI_Resolver_DefaultValueParam);
	ZEPHIR_INIT(Moon_Component_DI_Resolver_Medium);
	ZEPHIR_INIT(Moon_Component_DI_Resolver_Reflector);
	ZEPHIR_INIT(Moon_Component_DI_Resolver_Resolver);
	ZEPHIR_INIT(Moon_Component_DI_Resolver_StringResolver);
	ZEPHIR_INIT(Moon_Component_DI_Resolver_UnresolvedParam);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_DebugEventDispatcher);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_EventDispatcher);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_Exception);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_Exception_ContainerMissingException);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_Exception_EventDispatcherException);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_Exception_RuntimeException);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_Exception_UnimplementedMethodsException);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_ListenerCollection);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_ListenerEventEntry);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_ListenerItems);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_ListenerProvider);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_ListenerProviderCallback);
	ZEPHIR_INIT(Moon_Component_EventDispatcher_ListenerProviderProxy);
	ZEPHIR_INIT(Moon_Component_Http_Message_CLIRequest);
	ZEPHIR_INIT(Moon_Component_Http_Message_Cookie);
	ZEPHIR_INIT(Moon_Component_Http_Message_EmptyResponse);
	ZEPHIR_INIT(Moon_Component_Http_Message_Exception_InvalidArgumentException);
	ZEPHIR_INIT(Moon_Component_Http_Message_Exception_UploadedFileException);
	ZEPHIR_INIT(Moon_Component_Http_Message_FileBag);
	ZEPHIR_INIT(Moon_Component_Http_Message_HeaderBag);
	ZEPHIR_INIT(Moon_Component_Http_Message_HeaderUtils);
	ZEPHIR_INIT(Moon_Component_Http_Message_HtmlResponse);
	ZEPHIR_INIT(Moon_Component_Http_Message_JsonResponse);
	ZEPHIR_INIT(Moon_Component_Http_Message_RedirectResponse);
	ZEPHIR_INIT(Moon_Component_Http_Message_ServerBag);
	ZEPHIR_INIT(Moon_Component_Http_Message_Stream);
	ZEPHIR_INIT(Moon_Component_Http_Message_StreamedResponse);
	ZEPHIR_INIT(Moon_Component_Http_Message_UploadedFile);
	ZEPHIR_INIT(Moon_Component_Http_Message_Uri);
	ZEPHIR_INIT(Moon_Component_Router_Argument);
	ZEPHIR_INIT(Moon_Component_Router_Exception);
	ZEPHIR_INIT(Moon_Component_Router_Exception_NotFoundException);
	ZEPHIR_INIT(Moon_Component_Router_Exception_RouterException);
	ZEPHIR_INIT(Moon_Component_Router_Handler);
	ZEPHIR_INIT(Moon_Component_Router_Node);
	ZEPHIR_INIT(Moon_Component_Router_Router);
	ZEPHIR_INIT(Moon_Component_Router_TreeNode);
	ZEPHIR_INIT(Moon_Framework_Bootstrap);
	ZEPHIR_INIT(Moon_Framework_Controller_AbstractController);
	ZEPHIR_INIT(Moon_Framework_Controller_ControllerArgumentsResolver);
	ZEPHIR_INIT(Moon_Framework_Controller_ControllerResolver);
	ZEPHIR_INIT(Moon_Framework_Event_Event);
	ZEPHIR_INIT(Moon_Framework_Event_Event_ControllerArgumentsEvent);
	ZEPHIR_INIT(Moon_Framework_Event_Event_ControllerEvent);
	ZEPHIR_INIT(Moon_Framework_Event_Event_ExceptionEvent);
	ZEPHIR_INIT(Moon_Framework_Event_Event_FinishRequestEvent);
	ZEPHIR_INIT(Moon_Framework_Event_Event_ResponseEvent);
	ZEPHIR_INIT(Moon_Framework_Event_Event_ViewEvent);
	ZEPHIR_INIT(Moon_Framework_Event_Listener_ControllerListener);
	ZEPHIR_INIT(Moon_Framework_Event_Listener_RequestListener);
	ZEPHIR_INIT(Moon_Framework_Event_Listener_RouterSubscriber);
	ZEPHIR_INIT(Moon_Framework_Exception_ControllerException);
	ZEPHIR_INIT(Moon_Framework_Exception_HttpException);
	ZEPHIR_INIT(Moon_Framework_Kernel);
	ZEPHIR_INIT(moon_0__closure);
	ZEPHIR_INIT(moon_1__closure);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(moon)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_moon_globals *moon_globals TSRMLS_DC)
{
	moon_globals->initialized = 0;

	/* Cache Enabled */
	moon_globals->cache_enabled = 1;

	/* Recursive Lock */
	moon_globals->recursive_lock = 0;

	/* Static cache */
	memset(moon_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_moon_globals *moon_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(moon)
{
	zend_moon_globals *moon_globals_ptr;
	moon_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(moon_globals_ptr);
	zephir_initialize_memory(moon_globals_ptr);

		zephir_init_static_properties_Moon_Component_Http_Message_Response(TSRMLS_C);
		zephir_init_static_properties_Moon_Component_Config_Parser_AbstractParser(TSRMLS_C);
		zephir_init_static_properties_Moon_Component_Config_Parser_ParserFactory(TSRMLS_C);
		zephir_init_static_properties_Moon_Component_Http_Message_Cookie(TSRMLS_C);
		zephir_init_static_properties_Moon_Component_Http_Message_FileBag(TSRMLS_C);
	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(moon)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(moon)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_MOON_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_MOON_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_MOON_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_MOON_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_MOON_ZEPVERSION);
	php_info_print_table_end();
		php_info_print_table_start();
	php_info_print_table_header(2, "Directive", "Value");
	php_info_print_table_row(2, "Version", "0.0.1");
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(moon)
{
#if defined(COMPILE_DL_MOON) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(moon_globals);
	php_zephir_init_module_globals(moon_globals);
}

static PHP_GSHUTDOWN_FUNCTION(moon)
{
	
}


zend_function_entry php_moon_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_moon_deps[] = {
	ZEND_MOD_REQUIRED("psr")
	ZEND_MOD_END
};

zend_module_entry moon_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_moon_deps,
	PHP_MOON_EXTNAME,
	php_moon_functions,
	PHP_MINIT(moon),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(moon),
#else
	NULL,
#endif
	PHP_RINIT(moon),
	PHP_RSHUTDOWN(moon),
	PHP_MINFO(moon),
	PHP_MOON_VERSION,
	ZEND_MODULE_GLOBALS(moon),
	PHP_GINIT(moon),
	PHP_GSHUTDOWN(moon),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(moon),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_MOON
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(moon)
#endif
