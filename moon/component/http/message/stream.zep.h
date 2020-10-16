
extern zend_class_entry *moon_component_http_message_stream_ce;

ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Stream);

PHP_METHOD(Moon_Component_Http_Message_Stream, __construct);
PHP_METHOD(Moon_Component_Http_Message_Stream, setResource);
PHP_METHOD(Moon_Component_Http_Message_Stream, getResource);
PHP_METHOD(Moon_Component_Http_Message_Stream, setStream);
PHP_METHOD(Moon_Component_Http_Message_Stream, getStream);
PHP_METHOD(Moon_Component_Http_Message_Stream, __toString);
PHP_METHOD(Moon_Component_Http_Message_Stream, close);
PHP_METHOD(Moon_Component_Http_Message_Stream, detach);
PHP_METHOD(Moon_Component_Http_Message_Stream, eof);
PHP_METHOD(Moon_Component_Http_Message_Stream, getContents);
PHP_METHOD(Moon_Component_Http_Message_Stream, getMetadata);
PHP_METHOD(Moon_Component_Http_Message_Stream, getSize);
PHP_METHOD(Moon_Component_Http_Message_Stream, isReadable);
PHP_METHOD(Moon_Component_Http_Message_Stream, isSeekable);
PHP_METHOD(Moon_Component_Http_Message_Stream, isWritable);
PHP_METHOD(Moon_Component_Http_Message_Stream, read);
PHP_METHOD(Moon_Component_Http_Message_Stream, rewind);
PHP_METHOD(Moon_Component_Http_Message_Stream, seek);
PHP_METHOD(Moon_Component_Http_Message_Stream, tell);
PHP_METHOD(Moon_Component_Http_Message_Stream, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_stream___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_stream_setresource, 0, 0, 1)
	ZEND_ARG_INFO(0, _resource)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_setstream, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_setstream, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_stream_setstream, 0, 0, 1)
#define arginfo_moon_component_http_message_stream_setstream NULL
#endif

	ZEND_ARG_INFO(0, stream)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_close, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_close, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_component_http_message_stream_close NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_eof, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_eof, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_stream_getmetadata, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_getsize, 0, 0, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_getsize, 0, 0, IS_LONG, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_isreadable, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_isreadable, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_isseekable, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_isseekable, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_iswritable, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_iswritable, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_read, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_read, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_rewind, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_rewind, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_moon_component_http_message_stream_rewind NULL
#endif

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_seek, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_seek, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_moon_component_http_message_stream_seek, 0, 0, 1)
#define arginfo_moon_component_http_message_stream_seek NULL
#endif

	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, whence)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_tell, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_tell, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_write, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_moon_component_http_message_stream_write, 0, 1, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_INFO(0, _string)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(moon_component_http_message_stream_method_entry) {
	PHP_ME(Moon_Component_Http_Message_Stream, __construct, arginfo_moon_component_http_message_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Moon_Component_Http_Message_Stream, setResource, arginfo_moon_component_http_message_stream_setresource, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, getResource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, setStream, arginfo_moon_component_http_message_stream_setstream, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, getStream, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, __toString, arginfo_moon_component_http_message_stream___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, close, arginfo_moon_component_http_message_stream_close, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, detach, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, eof, arginfo_moon_component_http_message_stream_eof, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, getContents, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, getMetadata, arginfo_moon_component_http_message_stream_getmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, getSize, arginfo_moon_component_http_message_stream_getsize, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, isReadable, arginfo_moon_component_http_message_stream_isreadable, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, isSeekable, arginfo_moon_component_http_message_stream_isseekable, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, isWritable, arginfo_moon_component_http_message_stream_iswritable, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, read, arginfo_moon_component_http_message_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, rewind, arginfo_moon_component_http_message_stream_rewind, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, seek, arginfo_moon_component_http_message_stream_seek, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, tell, arginfo_moon_component_http_message_stream_tell, ZEND_ACC_PUBLIC)
	PHP_ME(Moon_Component_Http_Message_Stream, write, arginfo_moon_component_http_message_stream_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
