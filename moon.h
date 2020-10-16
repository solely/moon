
/* This file was generated automatically by Zephir do not modify it! */

#ifndef ZEPHIR_CLASS_ENTRIES_H
#define ZEPHIR_CLASS_ENTRIES_H

#include "moon/component/http/message/message.zep.h"
#include "moon/component/eventdispatcher/event.zep.h"
#include "moon/component/http/message/session/sessionbaginterface.zep.h"
#include "moon/framework/event/event/kernelevent.zep.h"
#include "moon/component/http/message/response.zep.h"
#include "moon/component/http/message/session/storage/handler/abstractsessionhandler.zep.h"
#include "moon/component/di/inject/inject.zep.h"
#include "moon/component/http/message/session/storage/sessionstorageinterface.zep.h"
#include "moon/component/config/parser/abstractparser.zep.h"
#include "moon/component/di/exception/containerexception.zep.h"
#include "moon/component/eventdispatcher/parameterderivertrait.zep.h"
#include "moon/component/errorhandler/formatter/formatterinterface.zep.h"
#include "moon/component/http/message/parameterbag.zep.h"
#include "moon/component/http/message/request.zep.h"
#include "moon/component/http/message/session/attribute/attributebaginterface.zep.h"
#include "moon/component/http/message/session/flash/flashbaginterface.zep.h"
#include "moon/framework/event/event/requestevent.zep.h"
#include "moon/component/di/delegatorinterface.zep.h"
#include "moon/component/di/injectinterface.zep.h"
#include "moon/component/di/mooncontainerinterface.zep.h"
#include "moon/component/eventdispatcher/listenerproviderinterface.zep.h"
#include "moon/component/eventdispatcher/listenerproviderutiltrait.zep.h"
#include "moon/component/eventdispatcher/subscriberinterface.zep.h"
#include "moon/component/http/message/serverrequest.zep.h"
#include "moon/component/http/message/session/attribute/attributebag.zep.h"
#include "moon/component/http/message/session/sessioninterface.zep.h"
#include "moon/component/http/message/session/storage/mockarraysessionstorage.zep.h"
#include "moon/component/http/message/session/storage/nativesessionstorage.zep.h"
#include "moon/component/http/message/session/storage/proxy/abstractproxy.zep.h"
#include "moon/component/router/routerinterface.zep.h"
#include "moon/framework/bootstrapinterface.zep.h"
#include "moon/framework/controller/controllerargumentsresolverinterface.zep.h"
#include "moon/framework/controller/controllerresolverinterface.zep.h"
#include "moon/framework/exception/httpexceptioninterface.zep.h"
#include "moon/component/config/config.zep.h"
#include "moon/component/config/exception.zep.h"
#include "moon/component/config/exception/notfoundexception.zep.h"
#include "moon/component/config/exception/parserexception.zep.h"
#include "moon/component/config/parser/iniparser.zep.h"
#include "moon/component/config/parser/phpparser.zep.h"
#include "moon/component/config/parser/parserfactory.zep.h"
#include "moon/component/config/parser/yaml.zep.h"
#include "moon/component/config/reader/loader.zep.h"
#include "moon/component/di/container.zep.h"
#include "moon/component/di/delegator.zep.h"
#include "moon/component/di/exception.zep.h"
#include "moon/component/di/exception/containerexistingexception.zep.h"
#include "moon/component/di/exception/notfoundexception.zep.h"
#include "moon/component/di/exception/resolverexception.zep.h"
#include "moon/component/di/inject.zep.h"
#include "moon/component/di/inject/arrayinject.zep.h"
#include "moon/component/di/inject/callableinject.zep.h"
#include "moon/component/di/inject/objectinject.zep.h"
#include "moon/component/di/inject/stringinject.zep.h"
#include "moon/component/di/resolver/autoresolver.zep.h"
#include "moon/component/di/resolver/defaultvalueparam.zep.h"
#include "moon/component/di/resolver/medium.zep.h"
#include "moon/component/di/resolver/reflector.zep.h"
#include "moon/component/di/resolver/resolver.zep.h"
#include "moon/component/di/resolver/stringresolver.zep.h"
#include "moon/component/di/resolver/unresolvedparam.zep.h"
#include "moon/component/errorhandler/bootstrap.zep.h"
#include "moon/component/errorhandler/dumper.zep.h"
#include "moon/component/errorhandler/errorhandler.zep.h"
#include "moon/component/errorhandler/exception/errorexception.zep.h"
#include "moon/component/errorhandler/formatter/callbackformatter.zep.h"
#include "moon/component/errorhandler/formatter/normalformatter.zep.h"
#include "moon/component/errorhandler/handler/errorhandler.zep.h"
#include "moon/component/errorhandler/handler/exceptionhandler.zep.h"
#include "moon/component/errorhandler/helpers.zep.h"
#include "moon/component/errorhandler/panel.zep.h"
#include "moon/component/errorhandler/table.zep.h"
#include "moon/component/eventdispatcher/debugeventdispatcher.zep.h"
#include "moon/component/eventdispatcher/eventdispatcher.zep.h"
#include "moon/component/eventdispatcher/exception.zep.h"
#include "moon/component/eventdispatcher/exception/containermissingexception.zep.h"
#include "moon/component/eventdispatcher/exception/eventdispatcherexception.zep.h"
#include "moon/component/eventdispatcher/exception/runtimeexception.zep.h"
#include "moon/component/eventdispatcher/exception/unimplementedmethodsexception.zep.h"
#include "moon/component/eventdispatcher/listenercollection.zep.h"
#include "moon/component/eventdispatcher/listenerevententry.zep.h"
#include "moon/component/eventdispatcher/listeneritems.zep.h"
#include "moon/component/eventdispatcher/listenerprovider.zep.h"
#include "moon/component/eventdispatcher/listenerproviderproxy.zep.h"
#include "moon/component/http/message/clirequest.zep.h"
#include "moon/component/http/message/cookie.zep.h"
#include "moon/component/http/message/emptyresponse.zep.h"
#include "moon/component/http/message/exception/invalidargumentexception.zep.h"
#include "moon/component/http/message/exception/uploadedfileexception.zep.h"
#include "moon/component/http/message/filebag.zep.h"
#include "moon/component/http/message/headerbag.zep.h"
#include "moon/component/http/message/headerutils.zep.h"
#include "moon/component/http/message/htmlresponse.zep.h"
#include "moon/component/http/message/jsonresponse.zep.h"
#include "moon/component/http/message/redirectresponse.zep.h"
#include "moon/component/http/message/serverbag.zep.h"
#include "moon/component/http/message/session/attribute/namespacedattributebag.zep.h"
#include "moon/component/http/message/session/flash/autoexpireflashbag.zep.h"
#include "moon/component/http/message/session/flash/flashbag.zep.h"
#include "moon/component/http/message/session/session.zep.h"
#include "moon/component/http/message/session/sessionbagproxy.zep.h"
#include "moon/component/http/message/session/sessionutils.zep.h"
#include "moon/component/http/message/session/storage/handler/memcachedsessionhandler.zep.h"
#include "moon/component/http/message/session/storage/handler/migratingsessionhandler.zep.h"
#include "moon/component/http/message/session/storage/handler/nativefilesessionhandler.zep.h"
#include "moon/component/http/message/session/storage/handler/nullsessionhandler.zep.h"
#include "moon/component/http/message/session/storage/handler/pdosessionhandler.zep.h"
#include "moon/component/http/message/session/storage/handler/redissessionhandler.zep.h"
#include "moon/component/http/message/session/storage/handler/sessionhandlerfactory.zep.h"
#include "moon/component/http/message/session/storage/handler/strictsessionhandler.zep.h"
#include "moon/component/http/message/session/storage/metadatabag.zep.h"
#include "moon/component/http/message/session/storage/mockfilesessionstorage.zep.h"
#include "moon/component/http/message/session/storage/phpbridgesessionstorage.zep.h"
#include "moon/component/http/message/session/storage/proxy/sessionhandlerproxy.zep.h"
#include "moon/component/http/message/stream.zep.h"
#include "moon/component/http/message/streamedresponse.zep.h"
#include "moon/component/http/message/uploadedfile.zep.h"
#include "moon/component/http/message/uri.zep.h"
#include "moon/component/router/argument.zep.h"
#include "moon/component/router/exception.zep.h"
#include "moon/component/router/exception/notfoundexception.zep.h"
#include "moon/component/router/exception/routerexception.zep.h"
#include "moon/component/router/handler.zep.h"
#include "moon/component/router/node.zep.h"
#include "moon/component/router/router.zep.h"
#include "moon/framework/bootstrap.zep.h"
#include "moon/framework/controller/abstractcontroller.zep.h"
#include "moon/framework/controller/controllerargumentsresolver.zep.h"
#include "moon/framework/controller/controllerresolver.zep.h"
#include "moon/framework/event/event.zep.h"
#include "moon/framework/event/event/controllerargumentsevent.zep.h"
#include "moon/framework/event/event/controllerevent.zep.h"
#include "moon/framework/event/event/exceptionevent.zep.h"
#include "moon/framework/event/event/finishrequestevent.zep.h"
#include "moon/framework/event/event/responseevent.zep.h"
#include "moon/framework/event/event/viewevent.zep.h"
#include "moon/framework/event/listener/controllerlistener.zep.h"
#include "moon/framework/event/listener/requestlistener.zep.h"
#include "moon/framework/event/listener/routersubscriber.zep.h"
#include "moon/framework/exception/controllerexception.zep.h"
#include "moon/framework/exception/httpexception.zep.h"
#include "moon/framework/kernel.zep.h"
#include "moon/framework/modulesinterface.zep.h"
#include "moon/0__closure.zep.h"
#include "moon/1__closure.zep.h"
#include "moon/2__closure.zep.h"
#include "moon/3__closure.zep.h"
#include "moon/4__closure.zep.h"
#include "moon/5__closure.zep.h"
#include "moon/6__closure.zep.h"
#include "moon/7__closure.zep.h"

#endif