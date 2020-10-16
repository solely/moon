PHP_ARG_ENABLE(moon, whether to enable moon, [ --enable-moon   Enable Moon])

if test "$PHP_MOON" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, MOON_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_MOON, 1, [Whether you have Moon])
	moon_sources="moon.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c moon/component/http/message/message.zep.c
	moon/component/eventdispatcher/event.zep.c
	moon/component/http/message/session/sessionbaginterface.zep.c
	moon/framework/event/event/kernelevent.zep.c
	moon/component/http/message/response.zep.c
	moon/component/http/message/session/storage/handler/abstractsessionhandler.zep.c
	moon/component/di/inject/inject.zep.c
	moon/component/http/message/session/storage/sessionstorageinterface.zep.c
	moon/component/config/parser/abstractparser.zep.c
	moon/component/di/exception/containerexception.zep.c
	moon/component/eventdispatcher/parameterderivertrait.zep.c
	moon/component/errorhandler/formatter/formatterinterface.zep.c
	moon/component/http/message/parameterbag.zep.c
	moon/component/http/message/request.zep.c
	moon/component/http/message/session/attribute/attributebaginterface.zep.c
	moon/component/http/message/session/flash/flashbaginterface.zep.c
	moon/framework/event/event/requestevent.zep.c
	moon/component/di/delegatorinterface.zep.c
	moon/component/di/injectinterface.zep.c
	moon/component/di/mooncontainerinterface.zep.c
	moon/component/eventdispatcher/listenerproviderinterface.zep.c
	moon/component/eventdispatcher/listenerproviderutiltrait.zep.c
	moon/component/eventdispatcher/subscriberinterface.zep.c
	moon/component/http/message/serverrequest.zep.c
	moon/component/http/message/session/attribute/attributebag.zep.c
	moon/component/http/message/session/sessioninterface.zep.c
	moon/component/http/message/session/storage/mockarraysessionstorage.zep.c
	moon/component/http/message/session/storage/nativesessionstorage.zep.c
	moon/component/http/message/session/storage/proxy/abstractproxy.zep.c
	moon/component/router/routerinterface.zep.c
	moon/framework/bootstrapinterface.zep.c
	moon/framework/controller/controllerargumentsresolverinterface.zep.c
	moon/framework/controller/controllerresolverinterface.zep.c
	moon/framework/exception/httpexceptioninterface.zep.c
	moon/component/config/config.zep.c
	moon/component/config/exception.zep.c
	moon/component/config/exception/notfoundexception.zep.c
	moon/component/config/exception/parserexception.zep.c
	moon/component/config/parser/iniparser.zep.c
	moon/component/config/parser/phpparser.zep.c
	moon/component/config/parser/parserfactory.zep.c
	moon/component/config/parser/yaml.zep.c
	moon/component/config/reader/loader.zep.c
	moon/component/di/container.zep.c
	moon/component/di/delegator.zep.c
	moon/component/di/exception.zep.c
	moon/component/di/exception/containerexistingexception.zep.c
	moon/component/di/exception/notfoundexception.zep.c
	moon/component/di/exception/resolverexception.zep.c
	moon/component/di/inject.zep.c
	moon/component/di/inject/arrayinject.zep.c
	moon/component/di/inject/callableinject.zep.c
	moon/component/di/inject/objectinject.zep.c
	moon/component/di/inject/stringinject.zep.c
	moon/component/di/resolver/autoresolver.zep.c
	moon/component/di/resolver/defaultvalueparam.zep.c
	moon/component/di/resolver/medium.zep.c
	moon/component/di/resolver/reflector.zep.c
	moon/component/di/resolver/resolver.zep.c
	moon/component/di/resolver/stringresolver.zep.c
	moon/component/di/resolver/unresolvedparam.zep.c
	moon/component/errorhandler/bootstrap.zep.c
	moon/component/errorhandler/dumper.zep.c
	moon/component/errorhandler/errorhandler.zep.c
	moon/component/errorhandler/exception/errorexception.zep.c
	moon/component/errorhandler/formatter/callbackformatter.zep.c
	moon/component/errorhandler/formatter/normalformatter.zep.c
	moon/component/errorhandler/handler/errorhandler.zep.c
	moon/component/errorhandler/handler/exceptionhandler.zep.c
	moon/component/errorhandler/helpers.zep.c
	moon/component/errorhandler/panel.zep.c
	moon/component/errorhandler/table.zep.c
	moon/component/eventdispatcher/debugeventdispatcher.zep.c
	moon/component/eventdispatcher/eventdispatcher.zep.c
	moon/component/eventdispatcher/exception.zep.c
	moon/component/eventdispatcher/exception/containermissingexception.zep.c
	moon/component/eventdispatcher/exception/eventdispatcherexception.zep.c
	moon/component/eventdispatcher/exception/runtimeexception.zep.c
	moon/component/eventdispatcher/exception/unimplementedmethodsexception.zep.c
	moon/component/eventdispatcher/listenercollection.zep.c
	moon/component/eventdispatcher/listenerevententry.zep.c
	moon/component/eventdispatcher/listeneritems.zep.c
	moon/component/eventdispatcher/listenerprovider.zep.c
	moon/component/eventdispatcher/listenerproviderproxy.zep.c
	moon/component/http/message/clirequest.zep.c
	moon/component/http/message/cookie.zep.c
	moon/component/http/message/emptyresponse.zep.c
	moon/component/http/message/exception/invalidargumentexception.zep.c
	moon/component/http/message/exception/uploadedfileexception.zep.c
	moon/component/http/message/filebag.zep.c
	moon/component/http/message/headerbag.zep.c
	moon/component/http/message/headerutils.zep.c
	moon/component/http/message/htmlresponse.zep.c
	moon/component/http/message/jsonresponse.zep.c
	moon/component/http/message/redirectresponse.zep.c
	moon/component/http/message/serverbag.zep.c
	moon/component/http/message/session/attribute/namespacedattributebag.zep.c
	moon/component/http/message/session/flash/autoexpireflashbag.zep.c
	moon/component/http/message/session/flash/flashbag.zep.c
	moon/component/http/message/session/session.zep.c
	moon/component/http/message/session/sessionbagproxy.zep.c
	moon/component/http/message/session/sessionutils.zep.c
	moon/component/http/message/session/storage/handler/memcachedsessionhandler.zep.c
	moon/component/http/message/session/storage/handler/migratingsessionhandler.zep.c
	moon/component/http/message/session/storage/handler/nativefilesessionhandler.zep.c
	moon/component/http/message/session/storage/handler/nullsessionhandler.zep.c
	moon/component/http/message/session/storage/handler/pdosessionhandler.zep.c
	moon/component/http/message/session/storage/handler/redissessionhandler.zep.c
	moon/component/http/message/session/storage/handler/sessionhandlerfactory.zep.c
	moon/component/http/message/session/storage/handler/strictsessionhandler.zep.c
	moon/component/http/message/session/storage/metadatabag.zep.c
	moon/component/http/message/session/storage/mockfilesessionstorage.zep.c
	moon/component/http/message/session/storage/phpbridgesessionstorage.zep.c
	moon/component/http/message/session/storage/proxy/sessionhandlerproxy.zep.c
	moon/component/http/message/stream.zep.c
	moon/component/http/message/streamedresponse.zep.c
	moon/component/http/message/uploadedfile.zep.c
	moon/component/http/message/uri.zep.c
	moon/component/router/argument.zep.c
	moon/component/router/exception.zep.c
	moon/component/router/exception/notfoundexception.zep.c
	moon/component/router/exception/routerexception.zep.c
	moon/component/router/handler.zep.c
	moon/component/router/node.zep.c
	moon/component/router/router.zep.c
	moon/framework/bootstrap.zep.c
	moon/framework/controller/abstractcontroller.zep.c
	moon/framework/controller/controllerargumentsresolver.zep.c
	moon/framework/controller/controllerresolver.zep.c
	moon/framework/event/event.zep.c
	moon/framework/event/event/controllerargumentsevent.zep.c
	moon/framework/event/event/controllerevent.zep.c
	moon/framework/event/event/exceptionevent.zep.c
	moon/framework/event/event/finishrequestevent.zep.c
	moon/framework/event/event/responseevent.zep.c
	moon/framework/event/event/viewevent.zep.c
	moon/framework/event/listener/controllerlistener.zep.c
	moon/framework/event/listener/requestlistener.zep.c
	moon/framework/event/listener/routersubscriber.zep.c
	moon/framework/exception/controllerexception.zep.c
	moon/framework/exception/httpexception.zep.c
	moon/framework/kernel.zep.c
	moon/framework/modulesinterface.zep.c
	moon/0__closure.zep.c
	moon/1__closure.zep.c
	moon/2__closure.zep.c
	moon/3__closure.zep.c
	moon/4__closure.zep.c
	moon/5__closure.zep.c
	moon/6__closure.zep.c
	moon/7__closure.zep.c "
	PHP_NEW_EXTENSION(moon, $moon_sources, $ext_shared,, )
	PHP_SUBST(MOON_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([moon], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([moon], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/moon], [php_MOON.h])

fi
