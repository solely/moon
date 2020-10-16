
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/**
 * FileName: UploadedFileException.php
 * User: solely
 * DateTime: 2019/1/14 22:55
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Exception_UploadedFileException) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Exception, UploadedFileException, moon, component_http_message_exception_uploadedfileexception, zend_exception_get_default(TSRMLS_C), moon_component_http_message_exception_uploadedfileexception_method_entry, 0);

	zephir_declare_class_constant_long(moon_component_http_message_exception_uploadedfileexception_ce, SL("UPLOAD_ERR_MOVED"), 101);

	zephir_declare_class_constant_long(moon_component_http_message_exception_uploadedfileexception_ce, SL("UPLOAD_ERR_TARGET_PATH"), 102);

	zephir_declare_class_constant_long(moon_component_http_message_exception_uploadedfileexception_ce, SL("UPLOAD_ERR_NOT_WRITABLE"), 103);

	zephir_declare_class_constant_long(moon_component_http_message_exception_uploadedfileexception_ce, SL("UPLOAD_ERR_FAIL"), 104);

	return SUCCESS;

}

PHP_METHOD(Moon_Component_Http_Message_Exception_UploadedFileException, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code = NULL, code_sub, *message = NULL, message_sub, *previous, previous_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&previous_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &code, &message, &previous);

	if (!code) {
		code = &code_sub;
		ZEPHIR_INIT_VAR(code);
		ZVAL_LONG(code, 0);
	}
	if (!message) {
		message = &message_sub;
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "");
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (ZEPHIR_IS_IDENTICAL(&_0, message)) {
		ZEPHIR_CALL_METHOD(message, this_ptr, "codetomessage", NULL, 182, code);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, moon_component_http_message_exception_uploadedfileexception_ce, getThis(), "__construct", NULL, 0, message, code, previous);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_Http_Message_Exception_UploadedFileException, codeToMessage) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *code, code_sub, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&message);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code);



	do {
		if (ZEPHIR_IS_LONG(code, 1)) {
			ZEPHIR_INIT_VAR(&message);
			ZVAL_STRING(&message, "The uploaded file exceeds the upload_max_filesize directive in php.ini");
			break;
		}
		if (ZEPHIR_IS_LONG(code, 2)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "The uploaded file exceeds the MAX_FILE_SIZE directive that was specified in the HTML form");
			break;
		}
		if (ZEPHIR_IS_LONG(code, 3)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "The uploaded file was only partially uploaded");
			break;
		}
		if (ZEPHIR_IS_LONG(code, 4)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "No file was uploaded");
			break;
		}
		if (ZEPHIR_IS_LONG(code, 6)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "Missing a temporary folder");
			break;
		}
		if (ZEPHIR_IS_LONG(code, 7)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "Failed to write file to disk");
			break;
		}
		if (ZEPHIR_IS_LONG(code, 8)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "File upload stopped by extension");
			break;
		}
		if (ZEPHIR_IS_LONG(code, 101)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "The file has been moved to the target location");
			break;
		}
		if (ZEPHIR_IS_LONG(code, 102)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "The upload destination is not a directory");
			break;
		}
		if (ZEPHIR_IS_LONG(code, 103)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "Upload destination address not writable");
			break;
		}
		if (ZEPHIR_IS_LONG(code, 104)) {
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_STRING(&message, "File upload failed");
			break;
		}
		ZEPHIR_INIT_NVAR(&message);
		ZVAL_STRING(&message, "Unknown upload error");
		break;
	} while(0);

	RETURN_CCTOR(&message);

}

