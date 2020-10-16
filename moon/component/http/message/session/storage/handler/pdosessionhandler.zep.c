
#ifdef HAVE_CONFIG_H
#include "../../../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../../../php_ext.h"
#include "../../../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/time.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * FileName: PdoSessionHandler.php
 * User: solely
 * DateTime: 2020/9/7 0:25
 * Description:
 */
/**
 * Session handler using a PDO connection to read and write data.
 *
 * It works with MySQL, PostgreSQL, Oracle, SQL Server and SQLite and implements
 * different locking strategies to handle concurrent access to the same session.
 * Locking is necessary to prevent loss of data due to race conditions and to keep
 * the session data consistent between read() and write(). With locking, requests
 * for the same session will wait until the other one finished writing. For this
 * reason it's best practice to close a session as early as possible to improve
 * concurrency. PHPs internal files session handler also implements locking.
 *
 * Attention: Since SQLite does not support row level locks but locks the whole database,
 * it means only one session can be accessed at a time. Even different sessions would wait
 * for another to finish. So saving session in SQLite should only be considered for
 * development or prototypes.
 *
 * Session data is a binary string that can contain non-printable characters like the null byte.
 * For this reason it must be saved in a binary column in the database like BLOB in MySQL.
 * Saving it in a character column could corrupt the data. You can use createTable()
 * to initialize a correctly defined table.
 *
 * @see https://php.net/sessionhandlerinterface
 *
 * Class PdoSessionHandler
 * @package Moon\Component\Http\Message\Session\Storage\Handler
 */
ZEPHIR_INIT_CLASS(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler) {

	ZEPHIR_REGISTER_CLASS_EX(Moon\\Component\\Http\\Message\\Session\\Storage\\Handler, PdoSessionHandler, moon, component_http_message_session_storage_handler_pdosessionhandler, moon_component_http_message_session_storage_handler_abstractsessionhandler_ce, moon_component_http_message_session_storage_handler_pdosessionhandler_method_entry, 0);

	/**
	 * @var \PDO|null PDO instance or null when not connected yet
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("pdo"), ZEND_ACC_PRIVATE);

	/**
	 * @var string|false|null DSN string or null for session.save_path or false when lazy connection disabled
	 */
	zend_declare_property_bool(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("dsn"), 0, ZEND_ACC_PRIVATE);

	/**
	 * @var string Database driver
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("driver"), ZEND_ACC_PRIVATE);

	/**
	 * @var string Table name
	 */
	zend_declare_property_string(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("table"), "sessions", ZEND_ACC_PRIVATE);

	/**
	 * @var string Column for session id
	 */
	zend_declare_property_string(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("idCol"), "sess_id", ZEND_ACC_PRIVATE);

	/**
	 * @var string Column for session data
	 */
	zend_declare_property_string(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("dataCol"), "sess_data", ZEND_ACC_PRIVATE);

	/**
	 * @var string Column for lifetime
	 */
	zend_declare_property_string(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("lifetimeCol"), "sess_lifetime", ZEND_ACC_PRIVATE);

	/**
	 * @var string Column for timestamp
	 */
	zend_declare_property_string(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("timeCol"), "sess_time", ZEND_ACC_PRIVATE);

	/**
	 * @var string Username when lazy-connect
	 */
	zend_declare_property_string(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("username"), "", ZEND_ACC_PRIVATE);

	/**
	 * @var string Password when lazy-connect
	 */
	zend_declare_property_string(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("password"), "", ZEND_ACC_PRIVATE);

	/**
	 * @var array Connection options when lazy-connect
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("connectionOptions"), ZEND_ACC_PRIVATE);

	/**
	 * @var int The strategy for locking, see constants
	 */
	zend_declare_property_long(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("lockMode"), 2, ZEND_ACC_PRIVATE);

	/**
	 * It's an array to support multiple reads before closing which is manual, non-standard usage.
	 *
	 * @var \PDOStatement[] An array of statements to release advisory locks
	 */
	zend_declare_property_null(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("unlockStatements"), ZEND_ACC_PRIVATE);

	/**
	 * @var bool True when the current session exists but expired according to session.gc_maxlifetime
	 */
	zend_declare_property_bool(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("sessionExpired"), 0, ZEND_ACC_PRIVATE);

	/**
	 * @var bool Whether a transaction is active
	 */
	zend_declare_property_bool(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("inTransaction"), 0, ZEND_ACC_PRIVATE);

	/**
	 * @var bool Whether gc() has been called
	 */
	zend_declare_property_bool(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("gcCalled"), 0, ZEND_ACC_PRIVATE);

	moon_component_http_message_session_storage_handler_pdosessionhandler_ce->create_object = zephir_init_properties_Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler;
	/**
	 * No locking is done. This means sessions are prone to loss of data due to
	 * race conditions of concurrent requests to the same session. The last session
	 * write will win in this case. It might be useful when you implement your own
	 * logic to deal with this like an optimistic approach.
	 */
	zephir_declare_class_constant_long(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("LOCK_NONE"), 0);

	/**
	 * Creates an application-level lock on a session. The disadvantage is that the
	 * lock is not enforced by the database and thus other, unaware parts of the
	 * application could still concurrently modify the session. The advantage is it
	 * does not require a transaction.
	 * This mode is not available for SQLite and not yet implemented for oci and sqlsrv.
	 */
	zephir_declare_class_constant_long(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("LOCK_ADVISORY"), 1);

	/**
	 * Issues a real row lock. Since it uses a transaction between opening and
	 * closing a session, you have to be careful when you use same database connection
	 * that you also use for your application logic. This mode is the default because
	 * it's the only reliable solution across DBMSs.
	 */
	zephir_declare_class_constant_long(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("LOCK_TRANSACTIONAL"), 2);

	zephir_declare_class_constant_long(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, SL("MAX_LIFETIME"), 315576000);

	return SUCCESS;

}

/**
 * You can either pass an existing database connection as PDO instance or
 * pass a DSN string that will be used to lazy-connect to the database
 * when the session is actually used. Furthermore it's possible to pass null
 * which will then use the session.save_path ini setting as PDO DSN parameter.
 *
 * List of available options:
 *  * db_table: The name of the table [default: sessions]
 *  * db_id_col: The column where to store the session id [default: sess_id]
 *  * db_data_col: The column where to store the session data [default: sess_data]
 *  * db_lifetime_col: The column where to store the lifetime [default: sess_lifetime]
 *  * db_time_col: The column where to store the timestamp [default: sess_time]
 *  * db_username: The username when lazy-connect [default: '']
 *  * db_password: The password when lazy-connect [default: '']
 *  * db_connection_options: An array of driver-specific connection options [default: []]
 *  * lock_mode: The strategy for locking, see constants [default: LOCK_TRANSACTIONAL]
 *
 * @param \PDO|string|null $pdoOrDsn A \PDO instance or DSN string or URL string or null
 * @param array $options
 *
 * @throws \InvalidArgumentException When PDO error mode is not PDO::ERRMODE_EXCEPTION
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, __construct) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *pdoOrDsn = NULL, pdoOrDsn_sub, *options_param = NULL, __$null, _1, _2, _12, _13, _14, _15, _16, _17, _18, _19, _20, _3$$3, _4$$3, _9$$3, _10$$3, _5$$4, _6$$4, _7$$4, _8$$4, _11$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pdoOrDsn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &pdoOrDsn, &options_param);

	if (!pdoOrDsn) {
		pdoOrDsn = &pdoOrDsn_sub;
		pdoOrDsn = &__$null;
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	_0 = Z_TYPE_P(pdoOrDsn) == IS_STRING;
	if (_0) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_STRING(&_1, "://");
		ZEPHIR_INIT_VAR(&_2);
		zephir_fast_strpos(&_2, pdoOrDsn, &_1, 0 );
		_0 = !ZEPHIR_IS_FALSE_IDENTICAL(&_2);
	}
	if (zephir_instance_of_ev(pdoOrDsn, php_pdo_get_dbh_ce())) {
		ZVAL_LONG(&_4$$3, 3);
		ZEPHIR_CALL_METHOD(&_3$$3, pdoOrDsn, "getattribute", NULL, 0, &_4$$3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_LONG_IDENTICAL(&_3$$3, 2)) {
			ZEPHIR_INIT_VAR(&_5$$4);
			object_init_ex(&_5$$4, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "\"%s\" requires PDO error mode attribute be set to throw Exceptions (i.e. $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION)).");
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "Moon\\Component\\Http\\Message\\Session\\Storage\\Handler\\PdoSessionHandler");
			ZEPHIR_CALL_FUNCTION(&_8$$4, "sprintf", NULL, 3, &_6$$4, &_7$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 33, &_8$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$4, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 152);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("pdo"), pdoOrDsn);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_10$$3, 16);
		ZEPHIR_CALL_METHOD(&_9$$3, &_4$$3, "getattribute", NULL, 0, &_10$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("driver"), &_9$$3);
	} else if (_0) {
		ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "builddsnfromurl", NULL, 213, pdoOrDsn);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("dsn"), &_11$$5);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("dsn"), pdoOrDsn);
	}
	ZEPHIR_INIT_VAR(&_12);
	if (zephir_array_isset_string(&options, SL("db_table"))) {
		ZEPHIR_OBS_NVAR(&_12);
		zephir_array_fetch_string(&_12, &options, SL("db_table"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 161);
	} else {
		ZEPHIR_OBS_NVAR(&_12);
		zephir_read_property(&_12, this_ptr, ZEND_STRL("table"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("table"), &_12);
	ZEPHIR_INIT_VAR(&_13);
	if (zephir_array_isset_string(&options, SL("db_id_col"))) {
		ZEPHIR_OBS_NVAR(&_13);
		zephir_array_fetch_string(&_13, &options, SL("db_id_col"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 162);
	} else {
		ZEPHIR_OBS_NVAR(&_13);
		zephir_read_property(&_13, this_ptr, ZEND_STRL("idCol"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("idCol"), &_13);
	ZEPHIR_INIT_VAR(&_14);
	if (zephir_array_isset_string(&options, SL("db_data_col"))) {
		ZEPHIR_OBS_NVAR(&_14);
		zephir_array_fetch_string(&_14, &options, SL("db_data_col"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 163);
	} else {
		ZEPHIR_OBS_NVAR(&_14);
		zephir_read_property(&_14, this_ptr, ZEND_STRL("dataCol"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("dataCol"), &_14);
	ZEPHIR_INIT_VAR(&_15);
	if (zephir_array_isset_string(&options, SL("db_lifetime_col"))) {
		ZEPHIR_OBS_NVAR(&_15);
		zephir_array_fetch_string(&_15, &options, SL("db_lifetime_col"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 164);
	} else {
		ZEPHIR_OBS_NVAR(&_15);
		zephir_read_property(&_15, this_ptr, ZEND_STRL("lifetimeCol"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("lifetimeCol"), &_15);
	ZEPHIR_INIT_VAR(&_16);
	if (zephir_array_isset_string(&options, SL("db_time_col"))) {
		ZEPHIR_OBS_NVAR(&_16);
		zephir_array_fetch_string(&_16, &options, SL("db_time_col"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 165);
	} else {
		ZEPHIR_OBS_NVAR(&_16);
		zephir_read_property(&_16, this_ptr, ZEND_STRL("timeCol"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("timeCol"), &_16);
	ZEPHIR_INIT_VAR(&_17);
	if (zephir_array_isset_string(&options, SL("db_username"))) {
		ZEPHIR_OBS_NVAR(&_17);
		zephir_array_fetch_string(&_17, &options, SL("db_username"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 166);
	} else {
		ZEPHIR_OBS_NVAR(&_17);
		zephir_read_property(&_17, this_ptr, ZEND_STRL("username"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("username"), &_17);
	ZEPHIR_INIT_VAR(&_18);
	if (zephir_array_isset_string(&options, SL("db_password"))) {
		ZEPHIR_OBS_NVAR(&_18);
		zephir_array_fetch_string(&_18, &options, SL("db_password"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 167);
	} else {
		ZEPHIR_OBS_NVAR(&_18);
		zephir_read_property(&_18, this_ptr, ZEND_STRL("password"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("password"), &_18);
	ZEPHIR_INIT_VAR(&_19);
	if (zephir_array_isset_string(&options, SL("db_connection_options"))) {
		ZEPHIR_OBS_NVAR(&_19);
		zephir_array_fetch_string(&_19, &options, SL("db_connection_options"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 168);
	} else {
		ZEPHIR_OBS_NVAR(&_19);
		zephir_read_property(&_19, this_ptr, ZEND_STRL("connectionOptions"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("connectionOptions"), &_19);
	ZEPHIR_INIT_VAR(&_20);
	if (zephir_array_isset_string(&options, SL("lock_mode"))) {
		ZEPHIR_OBS_NVAR(&_20);
		zephir_array_fetch_string(&_20, &options, SL("lock_mode"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 169);
	} else {
		ZEPHIR_OBS_NVAR(&_20);
		zephir_read_property(&_20, this_ptr, ZEND_STRL("lockMode"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("lockMode"), &_20);
	ZEPHIR_MM_RESTORE();

}

/**
 * Creates the table to store sessions which can be called once for setup.
 *
 * Session ID is saved in a column of maximum length 128 because that is enough even
 * for a 512 bit configured session.hash_function like Whirlpool. Session data is
 * saved in a BLOB. One could also use a shorter inlined varbinary column
 * if one was sure the data fits into it.
 *
 * @throws \PDOException    When the table already exists
 * @throws \DomainException When an unsupported PDO driver is used
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, createTable) {

	zval sql, _0, e, _8, _1$$8, _2$$8, _3$$8, _4$$8, _5$$9, _6$$9, _7$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$8);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_STRING(&_0, "mysql")) {
			ZEPHIR_INIT_VAR(&sql);
			ZVAL_STRING(&sql, "CREATE TABLE {this->table} ({this->idCol} VARBINARY(128) NOT NULL PRIMARY KEY, {this->dataCol} BLOB NOT NULL, {this->lifetimeCol} INTEGER UNSIGNED NOT NULL, {this->timeCol} INTEGER UNSIGNED NOT NULL) COLLATE utf8mb4_bin, ENGINE = InnoDB");
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "sqlite")) {
			ZEPHIR_INIT_NVAR(&sql);
			ZVAL_STRING(&sql, "CREATE TABLE {this->table} ({this->idCol} TEXT NOT NULL PRIMARY KEY, {this->dataCol} BLOB NOT NULL, {this->lifetimeCol} INTEGER NOT NULL, {this->timeCol} INTEGER NOT NULL)");
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "pgsql")) {
			ZEPHIR_INIT_NVAR(&sql);
			ZVAL_STRING(&sql, "CREATE TABLE {this->table} ({this->idCol} VARCHAR(128) NOT NULL PRIMARY KEY, {this->dataCol} BYTEA NOT NULL, {this->lifetimeCol} INTEGER NOT NULL, {this->timeCol} INTEGER NOT NULL)");
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "oci")) {
			ZEPHIR_INIT_NVAR(&sql);
			ZVAL_STRING(&sql, "CREATE TABLE {this->table} ({this->idCol} VARCHAR2(128) NOT NULL PRIMARY KEY, {this->dataCol} BLOB NOT NULL, {this->lifetimeCol} INTEGER NOT NULL, {this->timeCol} INTEGER NOT NULL)");
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "sqlsrv")) {
			ZEPHIR_INIT_NVAR(&sql);
			ZVAL_STRING(&sql, "CREATE TABLE {this->table} ({this->idCol} VARCHAR(128) NOT NULL PRIMARY KEY, {this->dataCol} VARBINARY(MAX) NOT NULL, {this->lifetimeCol} INTEGER NOT NULL, {this->timeCol} INTEGER NOT NULL)");
			break;
		}
		ZEPHIR_INIT_VAR(&_1$$8);
		object_init_ex(&_1$$8, spl_ce_DomainException);
		zephir_read_property(&_2$$8, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$8);
		ZVAL_STRING(&_3$$8, "Creating the session table is currently not implemented for PDO driver \"%s\".");
		ZEPHIR_CALL_FUNCTION(&_4$$8, "sprintf", NULL, 3, &_3$$8, &_2$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$8, "__construct", NULL, 214, &_4$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$8, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 210);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);


	/* try_start_1: */

		zephir_read_property(&_5$$9, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_5$$9, "exec", NULL, 0, &sql);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_read_property(&_6$$9, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$9);
		ZVAL_STRING(&_7$$9, "CREATE INDEX EXPIRY ON {this->table} ({this->lifetimeCol})");
		ZEPHIR_CALL_METHOD(NULL, &_6$$9, "exec", NULL, 0, &_7$$9);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_OBJ(&_8, EG(exception));
		Z_ADDREF_P(&_8);
		if (zephir_instance_of_ev(&_8, php_pdo_get_exception())) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_8);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 215);
			zephir_check_call_status();
			zephir_throw_exception_debug(&e, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 218);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns true when the current session exists but expired according to session.gc_maxlifetime.
 *
 * Can be used to distinguish between a new session and one that expired due to inactivity.
 *
 * @return bool Whether current session expired
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, isSessionExpired) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sessionExpired");

}

/**
 * @param string $savePath
 * @param string $sessionName
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, open) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *savePath, savePath_sub, *sessionName, sessionName_sub, __$true, __$false, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &savePath, &sessionName);



	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sessionExpired"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sessionExpired"), &__$false);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("dsn"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_2$$3))) {
			ZEPHIR_CPY_WRT(&_1$$3, savePath);
		} else {
			ZEPHIR_OBS_NVAR(&_1$$3);
			zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("dsn"), PH_NOISY_CC);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 216, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_PARENT(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, getThis(), "open", &_3, 0, savePath, sessionName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $sessionId
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, read) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *sessionId, sessionId_sub, e, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);




	/* try_start_1: */

		ZEPHIR_RETURN_CALL_PARENT(moon_component_http_message_session_storage_handler_pdosessionhandler_ce, getThis(), "read", &_0, 0, sessionId);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		if (zephir_instance_of_ev(&_1, php_pdo_get_exception())) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 215);
			zephir_check_call_status();
			zephir_throw_exception_debug(&e, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 259);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}

}

/**
 * @param int $maxlifetime
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, gc) {

	zval *maxlifetime, maxlifetime_sub, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &maxlifetime);



	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("gcCalled"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("gcCalled"), &__$false);
	}
	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doDestroy) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, stmt, sql, e, _3, _0$$3, _1$$3, _2$$3;
	zval sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&stmt);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(&sessionId, sessionId_param);


	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "DELETE FROM {this->table} WHERE {this->idCol} = :id");

	/* try_start_1: */

		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&stmt, &_0$$3, "prepare", NULL, 0, &sql);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, ":id");
		ZVAL_LONG(&_2$$3, 2);
		ZEPHIR_CALL_METHOD(NULL, &stmt, "bindparam", NULL, 0, &_1$$3, &sessionId, &_2$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, &stmt, "execute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		if (zephir_instance_of_ev(&_3, php_pdo_get_exception())) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 215);
			zephir_check_call_status();
			zephir_throw_exception_debug(&e, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 291);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doWrite) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, maxlifetime = 0;
	zval *sessionId_param = NULL, *data_param = NULL, insertStmt, updateStmt, mergeStmt, _0, _1, e, _2$$3, _3$$3, e$$5, _5$$5, _4$$6, _6$$7, _7$$7, _8$$7;
	zval sessionId, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&insertStmt);
	ZVAL_UNDEF(&updateStmt);
	ZVAL_UNDEF(&mergeStmt);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&e$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId_param, &data_param);

	zephir_get_strval(&sessionId, sessionId_param);
	zephir_get_strval(&data, data_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.gc_maxlifetime");
	ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 13, &_0);
	zephir_check_call_status();
	maxlifetime = zephir_get_intval(&_1);

	/* try_start_1: */

		ZVAL_LONG(&_2$$3, maxlifetime);
		ZEPHIR_CALL_METHOD(&mergeStmt, this_ptr, "getmergestatement", NULL, 217, &sessionId, &data, &_2$$3);
		zephir_check_call_status_or_jump(try_end_1);
		if (Z_TYPE_P(&mergeStmt) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "execute", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM_BOOL(1);
		}
		ZVAL_LONG(&_2$$3, maxlifetime);
		ZEPHIR_CALL_METHOD(&updateStmt, this_ptr, "getupdatestatement", NULL, 218, &sessionId, &data, &_2$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, &updateStmt, "execute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_3$$3, &updateStmt, "rowcount", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (!zephir_is_true(&_3$$3)) {

			/* try_start_2: */

				ZVAL_LONG(&_4$$6, maxlifetime);
				ZEPHIR_CALL_METHOD(&insertStmt, this_ptr, "getinsertstatement", NULL, 219, &sessionId, &data, &_4$$6);
				zephir_check_call_status_or_jump(try_end_2);
				ZEPHIR_CALL_METHOD(NULL, &insertStmt, "execute", NULL, 0);
				zephir_check_call_status_or_jump(try_end_2);

			try_end_2:

			if (EG(exception)) {
				ZEPHIR_INIT_VAR(&_5$$5);
				ZVAL_OBJ(&_5$$5, EG(exception));
				Z_ADDREF_P(&_5$$5);
				if (zephir_instance_of_ev(&_5$$5, php_pdo_get_exception())) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e$$5, &_5$$5);
					ZEPHIR_CALL_METHOD(&_6$$7, &e$$5, "getcode", NULL, 0);
					zephir_check_call_status_or_jump(try_end_2);
					ZEPHIR_INIT_VAR(&_7$$7);
					ZVAL_STRING(&_7$$7, "23");
					ZEPHIR_INIT_VAR(&_8$$7);
					zephir_fast_strpos(&_8$$7, &_6$$7, &_7$$7, 0 );
					if (ZEPHIR_IS_LONG_IDENTICAL(&_8$$7, 0)) {
						ZEPHIR_CALL_METHOD(NULL, &updateStmt, "execute", NULL, 0);
						zephir_check_call_status_or_jump(try_end_2);
					} else {
						zephir_throw_exception_debug(&e$$5, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 331);
						goto try_end_2;

					}
				}
			}
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_OBJ(&_0, EG(exception));
		Z_ADDREF_P(&_0);
		if (zephir_instance_of_ev(&_0, php_pdo_get_exception())) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 215);
			zephir_check_call_status();
			zephir_throw_exception_debug(&e, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 337);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, updateTimestamp) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, *data, data_sub, updateStmt, expiry, _0, _1, _2, e, _3$$3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&updateStmt);
	ZVAL_UNDEF(&expiry);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &data);



	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "session.gc_maxlifetime");
	ZEPHIR_CALL_FUNCTION(&_2, "ini_get", NULL, 13, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&expiry);
	ZVAL_LONG(&expiry, (zephir_get_numberval(&_0) + zephir_get_intval(&_2)));

	/* try_start_1: */

		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "UPDATE {this->table} SET {this->lifetimeCol} = :expiry, {this->timeCol} = :time WHERE {this->idCol} = :id");
		ZEPHIR_CALL_METHOD(&updateStmt, &_3$$3, "prepare", NULL, 0, &_4$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, ":id");
		ZVAL_LONG(&_5$$3, 2);
		ZEPHIR_CALL_METHOD(NULL, &updateStmt, "bindparam", NULL, 0, &_4$$3, sessionId, &_5$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, ":expiry");
		ZVAL_LONG(&_5$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &updateStmt, "bindparam", NULL, 0, &_4$$3, &expiry, &_5$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_time(&_4$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, ":time");
		ZVAL_LONG(&_5$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &updateStmt, "bindvalue", NULL, 0, &_6$$3, &_4$$3, &_5$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, &updateStmt, "execute", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		if (zephir_instance_of_ev(&_1, php_pdo_get_exception())) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 215);
			zephir_check_call_status();
			zephir_throw_exception_debug(&e, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 359);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * @return bool
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, close) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, __$null, legacySql, stmt, sql, unlockStmt, _0, _3, _13, _2$$3, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _11$$4, _12$$4;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&legacySql);
	ZVAL_UNDEF(&stmt);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&unlockStmt);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "commit", NULL, 220);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("unlockStatements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&_0);
	ZEPHIR_CALL_FUNCTION(&unlockStmt, "array_shift", &_1, 169, &_0);
	ZEPHIR_UNREF(&_0);
	zephir_check_call_status();
	while (1) {
		if (!(zephir_is_true(&unlockStmt))) {
			break;
		}
		ZEPHIR_CALL_METHOD(NULL, &unlockStmt, "execute", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("unlockStatements"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_MAKE_REF(&_2$$3);
		ZEPHIR_CALL_FUNCTION(&unlockStmt, "array_shift", &_1, 169, &_2$$3);
		ZEPHIR_UNREF(&_2$$3);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("gcCalled"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("gcCalled"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("gcCalled"), &__$false);
		}
		ZEPHIR_INIT_VAR(&sql);
		ZVAL_STRING(&sql, "DELETE FROM {this->table} WHERE {this->lifetimeCol} < :time AND {this->lifetimeCol} > :min");
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&stmt, &_4$$4, "prepare", NULL, 0, &sql);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_time(&_5$$4);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, ":time");
		ZVAL_LONG(&_7$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_6$$4, &_5$$4, &_7$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$4);
		ZVAL_STRING(&_6$$4, ":min");
		ZVAL_LONG(&_7$$4, 315576000);
		ZVAL_LONG(&_8$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_6$$4, &_7$$4, &_8$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &stmt, "execute", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "mysql");
		ZEPHIR_INIT_VAR(&legacySql);
		if (ZEPHIR_IS_IDENTICAL(&_9$$4, &_7$$4)) {
			ZVAL_STRING(&legacySql, "DELETE FROM {this->table} WHERE {this->lifetimeCol} <= :min AND {this->lifetimeCol} + {this->timeCol} < :time");
		} else {
			ZVAL_STRING(&legacySql, "DELETE FROM {this->table} WHERE {this->lifetimeCol} <= :min AND {this->lifetimeCol} < :time - {this->timeCol}");
		}
		zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&stmt, &_8$$4, "prepare", NULL, 0, &legacySql);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$4);
		zephir_time(&_6$$4);
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, ":time");
		ZVAL_LONG(&_11$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_10$$4, &_6$$4, &_11$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_10$$4);
		ZVAL_STRING(&_10$$4, ":min");
		ZVAL_LONG(&_11$$4, 315576000);
		ZVAL_LONG(&_12$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_10$$4, &_11$$4, &_12$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &stmt, "execute", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_13, this_ptr, ZEND_STRL("dsn"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_13)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("pdo"), &__$null);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Lazy-connects to the database.
 * @param string $dsn
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, connect) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dsn_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zval dsn;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dsn_param);

	zephir_get_strval(&dsn, dsn_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, php_pdo_get_dbh_ce());
	zephir_read_property(&_1, this_ptr, ZEND_STRL("username"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("password"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("connectionOptions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &dsn, &_1, &_2, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("pdo"), &_0);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 3);
	ZVAL_LONG(&_6, 2);
	ZEPHIR_CALL_METHOD(NULL, &_4, "setattribute", NULL, 0, &_5, &_6);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_6, 16);
	ZEPHIR_CALL_METHOD(&_7, &_5, "getattribute", NULL, 0, &_6);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("driver"), &_7);
	ZEPHIR_MM_RESTORE();

}

/**
 * Builds a PDO DSN from a URL-like connection string.
 *
 * @param string $dsnOrUrl
 * @return string
 * @todo implement missing support for oci DSN (which look totally different from other PDO ones)
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, buildDsnFromUrl) {

	zend_bool _7, _12$$8, _17$$8, _29$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dsnOrUrl_param = NULL, dbName, dsn, driver, driverAliasMap, params, url, _0, _1, _2, _5, _6, _8, _9, _3$$4, _4$$5, _10$$7, _11$$7, _13$$8, _14$$8, _18$$8, _19$$8, _15$$9, _16$$9, _20$$10, _21$$10, _22$$11, _23$$11, _24$$11, _25$$12, _26$$12, _27$$12, _28$$14, _30$$13, _31$$13, _32$$15, _33$$15, _34$$16, _35$$16, _36$$16, _37$$17, _38$$17, _39$$17, _40$$17;
	zval dsnOrUrl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dsnOrUrl);
	ZVAL_UNDEF(&dbName);
	ZVAL_UNDEF(&dsn);
	ZVAL_UNDEF(&driver);
	ZVAL_UNDEF(&driverAliasMap);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$15);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_35$$16);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_40$$17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dsnOrUrl_param);

	zephir_get_strval(&dsnOrUrl, dsnOrUrl_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "#^((?:pdo_)?sqlite3?):///#");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "$1://localhost/");
	ZEPHIR_CALL_FUNCTION(&url, "preg_replace", NULL, 36, &_0, &_1, &dsnOrUrl);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&params, "parse_url", NULL, 221, &url);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&params)) {
		RETURN_CTOR(&dsnOrUrl);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "rawurldecode");
	ZEPHIR_CALL_FUNCTION(&_2, "array_map", NULL, 83, &_0, &params);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&params, &_2);
	if (zephir_array_isset_string(&params, SL("user"))) {
		zephir_array_fetch_string(&_3$$4, &params, SL("user"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 441);
		zephir_update_property_zval(this_ptr, ZEND_STRL("username"), &_3$$4);
	}
	if (zephir_array_isset_string(&params, SL("pass"))) {
		zephir_array_fetch_string(&_4$$5, &params, SL("pass"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 444);
		zephir_update_property_zval(this_ptr, ZEND_STRL("password"), &_4$$5);
	}
	if (!(zephir_array_isset_string(&params, SL("scheme")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "URLs without scheme are not supported to configure the PdoSessionHandler.", "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 447);
		return;
	}
	ZEPHIR_INIT_VAR(&driverAliasMap);
	zephir_create_array(&driverAliasMap, 5, 0);
	add_assoc_stringl_ex(&driverAliasMap, SL("mssql"), SL("sqlsrv"));
	add_assoc_stringl_ex(&driverAliasMap, SL("mysql2"), SL("mysql"));
	add_assoc_stringl_ex(&driverAliasMap, SL("postgres"), SL("pgsql"));
	add_assoc_stringl_ex(&driverAliasMap, SL("postgresql"), SL("pgsql"));
	add_assoc_stringl_ex(&driverAliasMap, SL("sqlite3"), SL("sqlite"));
	zephir_array_fetch_string(&_5, &params, SL("scheme"), PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 457);
	if (zephir_array_isset(&driverAliasMap, &_5)) {
		ZEPHIR_OBS_VAR(&driver);
		ZEPHIR_OBS_VAR(&_6);
		zephir_array_fetch_string(&_6, &params, SL("scheme"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 457);
		zephir_array_fetch(&driver, &driverAliasMap, &_6, PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 457);
	} else {
		ZEPHIR_OBS_NVAR(&driver);
		zephir_array_fetch_string(&driver, &params, SL("scheme"), PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 457);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "pdo_");
	ZEPHIR_INIT_NVAR(&_1);
	zephir_fast_strpos(&_1, &driver, &_0, 0 );
	_7 = ZEPHIR_IS_LONG_IDENTICAL(&_1, 0);
	if (!(_7)) {
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_STRING(&_8, "pdo-");
		ZEPHIR_INIT_VAR(&_9);
		zephir_fast_strpos(&_9, &driver, &_8, 0 );
		_7 = ZEPHIR_IS_LONG_IDENTICAL(&_9, 0);
	}
	if (_7) {
		ZVAL_LONG(&_10$$7, 4);
		ZEPHIR_INIT_VAR(&_11$$7);
		zephir_substr(&_11$$7, &driver, 4 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CPY_WRT(&driver, &_11$$7);
	}
	do {
		if (ZEPHIR_IS_STRING(&driver, "mysql") || ZEPHIR_IS_STRING(&driver, "pgsql")) {
			ZEPHIR_INIT_VAR(&dsn);
			ZEPHIR_CONCAT_VS(&dsn, &driver, ":");
			_12$$8 = zephir_array_isset_string(&params, SL("host"));
			if (_12$$8) {
				zephir_array_fetch_string(&_13$$8, &params, SL("host"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 466);
				ZEPHIR_INIT_VAR(&_14$$8);
				ZVAL_STRING(&_14$$8, "");
				_12$$8 = !ZEPHIR_IS_IDENTICAL(&_14$$8, &_13$$8);
			}
			if (_12$$8) {
				zephir_array_fetch_string(&_15$$9, &params, SL("host"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 467);
				ZEPHIR_INIT_VAR(&_16$$9);
				ZEPHIR_CONCAT_SVS(&_16$$9, "host=", &_15$$9, ";");
				zephir_concat_self(&dsn, &_16$$9);
			}
			_17$$8 = zephir_array_isset_string(&params, SL("port"));
			if (_17$$8) {
				zephir_array_fetch_string(&_18$$8, &params, SL("port"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 469);
				ZEPHIR_INIT_VAR(&_19$$8);
				ZVAL_STRING(&_19$$8, "");
				_17$$8 = !ZEPHIR_IS_IDENTICAL(&_19$$8, &_18$$8);
			}
			if (_17$$8) {
				zephir_array_fetch_string(&_20$$10, &params, SL("port"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 470);
				ZEPHIR_INIT_VAR(&_21$$10);
				ZEPHIR_CONCAT_SVS(&_21$$10, "port=", &_20$$10, ";");
				zephir_concat_self(&dsn, &_21$$10);
			}
			if (zephir_array_isset_string(&params, SL("path"))) {
				zephir_array_fetch_string(&_22$$11, &params, SL("path"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 473);
				ZVAL_LONG(&_23$$11, 1);
				ZEPHIR_INIT_VAR(&dbName);
				zephir_substr(&dbName, &_22$$11, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_INIT_VAR(&_24$$11);
				ZEPHIR_CONCAT_SVS(&_24$$11, "dbname=", &dbName, ";");
				zephir_concat_self(&dsn, &_24$$11);
			}
			RETURN_CCTOR(&dsn);
		}
		if (ZEPHIR_IS_STRING(&driver, "sqlite")) {
			zephir_array_fetch_string(&_25$$12, &params, SL("path"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 479);
			ZVAL_LONG(&_26$$12, 1);
			ZEPHIR_INIT_VAR(&_27$$12);
			zephir_substr(&_27$$12, &_25$$12, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CONCAT_SV(return_value, "sqlite:", &_27$$12);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&driver, "sqlsrv")) {
			ZEPHIR_INIT_NVAR(&dsn);
			ZVAL_STRING(&dsn, "sqlsrv:server=");
			if (zephir_array_isset_string(&params, SL("host"))) {
				zephir_array_fetch_string(&_28$$14, &params, SL("host"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 483);
				zephir_concat_self(&dsn, &_28$$14);
			}
			_29$$13 = zephir_array_isset_string(&params, SL("port"));
			if (_29$$13) {
				zephir_array_fetch_string(&_30$$13, &params, SL("port"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 485);
				ZEPHIR_INIT_VAR(&_31$$13);
				ZVAL_STRING(&_31$$13, "");
				_29$$13 = !ZEPHIR_IS_IDENTICAL(&_31$$13, &_30$$13);
			}
			if (_29$$13) {
				zephir_array_fetch_string(&_32$$15, &params, SL("port"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 486);
				ZEPHIR_INIT_VAR(&_33$$15);
				ZEPHIR_CONCAT_SV(&_33$$15, ",", &_32$$15);
				zephir_concat_self(&dsn, &_33$$15);
			}
			if (zephir_array_isset_string(&params, SL("path"))) {
				zephir_array_fetch_string(&_34$$16, &params, SL("path"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 489);
				ZVAL_LONG(&_35$$16, 1);
				ZEPHIR_INIT_NVAR(&dbName);
				zephir_substr(&dbName, &_34$$16, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_INIT_VAR(&_36$$16);
				ZEPHIR_CONCAT_SV(&_36$$16, ";Database=", &dbName);
				zephir_concat_self(&dsn, &_36$$16);
			}
			RETURN_CCTOR(&dsn);
		}
		ZEPHIR_INIT_VAR(&_37$$17);
		object_init_ex(&_37$$17, spl_ce_InvalidArgumentException);
		zephir_array_fetch_string(&_38$$17, &params, SL("scheme"), PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 495);
		ZEPHIR_INIT_VAR(&_39$$17);
		ZVAL_STRING(&_39$$17, "The scheme \"%s\" is not supported by the PdoSessionHandler URL configuration. Pass a PDO DSN directly.");
		ZEPHIR_CALL_FUNCTION(&_40$$17, "sprintf", NULL, 3, &_39$$17, &_38$$17);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_37$$17, "__construct", NULL, 33, &_40$$17);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_37$$17, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 495);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Helper method to begin a transaction.
 *
 * Since SQLite does not support row level locks, we have to acquire a reserved lock
 * on the database immediately. Because of https://bugs.php.net/42766 we have to create
 * such a transaction manually which also means we cannot use PDO::commit or
 * PDO::rollback or PDO::inTransaction for SQLite.
 *
 * Also MySQLs default isolation, REPEATABLE READ, causes deadlock for different sessions
 * due to https://percona.com/blog/2013/12/12/one-more-innodb-gap-lock-to-avoid/ .
 * So we change it to READ COMMITTED.
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, beginTransaction) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _1$$3, _2$$3, _3$$4, _4$$4, _5$$5, _6$$5, _9$$5, _7$$6, _8$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "sqlite");
		if (ZEPHIR_IS_IDENTICAL(&_2$$3, &_1$$3)) {
			zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "BEGIN IMMEDIATE TRANSACTION");
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "exec", NULL, 0, &_4$$4);
			zephir_check_call_status();
		} else {
			zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "mysql");
			if (ZEPHIR_IS_IDENTICAL(&_6$$5, &_5$$5)) {
				zephir_read_property(&_7$$6, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_8$$6);
				ZVAL_STRING(&_8$$6, "SET TRANSACTION ISOLATION LEVEL READ COMMITTED");
				ZEPHIR_CALL_METHOD(NULL, &_7$$6, "exec", NULL, 0, &_8$$6);
				zephir_check_call_status();
			}
			zephir_read_property(&_9$$5, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_9$$5, "begintransaction", NULL, 0);
			zephir_check_call_status();
		}
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("inTransaction"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("inTransaction"), &__$false);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Helper method to commit a transaction.
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, commit) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, e$$3, _6$$3, _1$$4, _2$$4, _3$$5, _4$$5, _5$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&e$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {

		/* try_start_1: */

			zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "sqlite");
			if (ZEPHIR_IS_IDENTICAL(&_2$$4, &_1$$4)) {
				zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_4$$5);
				ZVAL_STRING(&_4$$5, "COMMIT");
				ZEPHIR_CALL_METHOD(NULL, &_3$$5, "exec", NULL, 0, &_4$$5);
				zephir_check_call_status_or_jump(try_end_1);
			} else {
				zephir_read_property(&_5$$6, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_5$$6, "commit", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
			}
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("inTransaction"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("inTransaction"), &__$false);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_6$$3);
			ZVAL_OBJ(&_6$$3, EG(exception));
			Z_ADDREF_P(&_6$$3);
			if (zephir_instance_of_ev(&_6$$3, php_pdo_get_exception())) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e$$3, &_6$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 215);
				zephir_check_call_status();
				zephir_throw_exception_debug(&e$$3, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 543);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Helper method to rollback a transaction.
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, rollback) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, _0, _1$$3, _2$$3, _3$$4, _4$$4, _5$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("inTransaction"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "sqlite");
		if (ZEPHIR_IS_IDENTICAL(&_2$$3, &_1$$3)) {
			zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "ROLLBACK");
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "exec", NULL, 0, &_4$$4);
			zephir_check_call_status();
		} else {
			zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_5$$5, "rollback", NULL, 0);
			zephir_check_call_status();
		}
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("inTransaction"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("inTransaction"), &__$false);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads the session data in respect to the different locking strategies.
 *
 * We need to make sure we do not return session data that is already considered garbage according
 * to the session.gc_maxlifetime setting because gc() is called after read() and only sometimes.
 *
 * @param string $sessionId
 * @return string
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doRead) {

	zend_bool _24$$4, _25$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL, *_18 = NULL, *_21 = NULL, *_23 = NULL, *_30 = NULL, *_31 = NULL, *_36 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, __$true, __$false, expiry, sessionRows, insertStmt, selectStmt, selectSql, _0, _2, _3, _4, _1$$3, _5$$4, _19$$4, _20$$4, _22$$4, _26$$4, _27$$4, _6$$5, _7$$5, _10$$5, _11$$5, _12$$5, _13$$5, _14$$5, _15$$5, _17$$5, _8$$6, _9$$6, e$$9, _32$$9, _28$$10, _29$$10, _33$$11, _34$$11, _35$$11;
	zval sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&expiry);
	ZVAL_UNDEF(&sessionRows);
	ZVAL_UNDEF(&insertStmt);
	ZVAL_UNDEF(&selectStmt);
	ZVAL_UNDEF(&selectSql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_27$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&e$$9);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_34$$11);
	ZVAL_UNDEF(&_35$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(&sessionId, sessionId_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("lockMode"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 1)) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "doadvisorylock", NULL, 222, &sessionId);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("unlockStatements"), &_1$$3);
	}
	ZEPHIR_CALL_METHOD(&selectSql, this_ptr, "getselectsql", NULL, 223);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&selectStmt, &_2, "prepare", NULL, 0, &selectSql);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, ":id");
	ZVAL_LONG(&_4, 2);
	ZEPHIR_CALL_METHOD(NULL, &selectStmt, "bindparam", NULL, 0, &_3, &sessionId, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&insertStmt);
	ZVAL_NULL(&insertStmt);
	do {
		ZEPHIR_CALL_METHOD(NULL, &selectStmt, "execute", NULL, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$4, 3);
		ZEPHIR_CALL_METHOD(&sessionRows, &selectStmt, "fetchall", NULL, 0, &_5$$4);
		zephir_check_call_status();
		if (zephir_is_true(&sessionRows)) {
			zephir_array_fetch_long(&_6$$5, &sessionRows, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 594);
			ZEPHIR_OBS_NVAR(&_7$$5);
			zephir_array_fetch_long(&_7$$5, &_6$$5, 1, PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 594);
			ZEPHIR_INIT_NVAR(&expiry);
			ZVAL_LONG(&expiry, zephir_get_intval(&_7$$5));
			if (ZEPHIR_LE_LONG(&expiry, 315576000)) {
				zephir_array_fetch_long(&_8$$6, &sessionRows, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 596);
				zephir_array_fetch_long(&_9$$6, &_8$$6, 2, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 596);
				ZEPHIR_ADD_ASSIGN(&expiry, &_9$$6);
			}
			ZEPHIR_INIT_NVAR(&_10$$5);
			zephir_time(&_10$$5);
			if (ZEPHIR_LT(&expiry, &_10$$5)) {
				if (1) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("sessionExpired"), &__$true);
				} else {
					zephir_update_property_zval(this_ptr, ZEND_STRL("sessionExpired"), &__$false);
				}
				RETURN_MM_STRING("");
			}
			ZEPHIR_INIT_NVAR(&_11$$5);
			zephir_array_fetch_long(&_12$$5, &sessionRows, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 602);
			zephir_array_fetch_long(&_13$$5, &_12$$5, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 602);
			if (Z_TYPE_P(&_13$$5) == IS_RESOURCE) {
				zephir_array_fetch_long(&_14$$5, &sessionRows, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 602);
				zephir_array_fetch_long(&_15$$5, &_14$$5, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 602);
				ZEPHIR_CALL_FUNCTION(&_11$$5, "stream_get_contents", &_16, 224, &_15$$5);
				zephir_check_call_status();
			} else {
				zephir_array_fetch_long(&_17$$5, &sessionRows, 0, PH_NOISY | PH_READONLY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 602);
				zephir_array_fetch_long(&_11$$5, &_17$$5, 0, PH_NOISY, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 602);
			}
			RETURN_CCTOR(&_11$$5);
		}
		if (Z_TYPE_P(&insertStmt) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", &_18, 215);
			zephir_check_call_status();
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Failed to read session: INSERT reported a duplicate id but next SELECT did not return any data.", "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 606);
			return;
		}
		ZEPHIR_INIT_NVAR(&_19$$4);
		ZVAL_STRING(&_19$$4, "session.use_strict_mode");
		ZEPHIR_CALL_FUNCTION(&_20$$4, "ini_get", &_21, 13, &_19$$4);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$4, 258);
		ZEPHIR_CALL_FUNCTION(&_22$$4, "filter_var", &_23, 17, &_20$$4, &_5$$4);
		zephir_check_call_status();
		_24$$4 = !zephir_is_true(&_22$$4);
		if (_24$$4) {
			zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("lockMode"), PH_NOISY_CC | PH_READONLY);
			_24$$4 = ZEPHIR_IS_LONG_IDENTICAL(&_5$$4, 2);
		}
		_25$$4 = _24$$4;
		if (_25$$4) {
			zephir_read_property(&_26$$4, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_27$$4);
			ZVAL_STRING(&_27$$4, "sqlite");
			_25$$4 = !ZEPHIR_IS_IDENTICAL(&_27$$4, &_26$$4);
		}
		if (_25$$4) {

			/* try_start_1: */

				ZEPHIR_INIT_NVAR(&_28$$10);
				ZVAL_STRING(&_28$$10, "");
				ZVAL_LONG(&_29$$10, 0);
				ZEPHIR_CALL_METHOD(&insertStmt, this_ptr, "getinsertstatement", &_30, 219, &sessionId, &_28$$10, &_29$$10);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CALL_METHOD(NULL, &insertStmt, "execute", &_31, 0);
				zephir_check_call_status_or_jump(try_end_1);

			try_end_1:

			if (EG(exception)) {
				ZEPHIR_INIT_NVAR(&_32$$9);
				ZVAL_OBJ(&_32$$9, EG(exception));
				Z_ADDREF_P(&_32$$9);
				if (zephir_instance_of_ev(&_32$$9, php_pdo_get_exception())) {
					zend_clear_exception(TSRMLS_C);
					ZEPHIR_CPY_WRT(&e$$9, &_32$$9);
					ZEPHIR_CALL_METHOD(&_33$$11, &e$$9, "getcode", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_34$$11);
					ZVAL_STRING(&_34$$11, "23");
					ZEPHIR_INIT_NVAR(&_35$$11);
					zephir_fast_strpos(&_35$$11, &_33$$11, &_34$$11, 0 );
					if (ZEPHIR_IS_LONG_IDENTICAL(&_35$$11, 0)) {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", &_18, 215);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "begintransaction", &_36, 225);
						zephir_check_call_status();
						continue;
					}
					zephir_throw_exception_debug(&e$$9, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 628);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		RETURN_MM_STRING("");
	} while (1);
	RETURN_MM_STRING("");

}

/**
 * Executes an application-level lock on the database.
 *
 * @param string $sessionId
 * @return \PDOStatement The statement that needs to be executed later to release the lock
 *
 * @throws \DomainException When an unsupported PDO driver is used
 *
 * @todo implement missing advisory locks
 *       - for oci using DBMS_LOCK.REQUEST
 *       - for sqlsrv using sp_getapplock with LockOwner = Session
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, doAdvisoryLock) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, sessionBigInt, sessionInt2, sessionInt1, releaseStmt, stmt, lockId, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$4, _9$$5, _10$$5, _11$$5, _12$$5, _13$$5, _14$$5, _15$$5, _16$$6, _17$$6, _18$$6, _19$$6, _20$$8, _21$$8, _22$$8, _23$$8;
	zval sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&sessionBigInt);
	ZVAL_UNDEF(&sessionInt2);
	ZVAL_UNDEF(&sessionInt1);
	ZVAL_UNDEF(&releaseStmt);
	ZVAL_UNDEF(&stmt);
	ZVAL_UNDEF(&lockId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(&sessionId, sessionId_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_STRING(&_0, "mysql")) {
			ZVAL_LONG(&_1$$3, 0);
			ZVAL_LONG(&_2$$3, 64);
			ZEPHIR_INIT_VAR(&lockId);
			zephir_substr(&lockId, &sessionId, 0 , 64 , 0);
			zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "SELECT GET_LOCK(:key, 50)");
			ZEPHIR_CALL_METHOD(&stmt, &_3$$3, "prepare", NULL, 0, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, ":key");
			ZVAL_LONG(&_5$$3, 2);
			ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_4$$3, &lockId, &_5$$3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &stmt, "execute", NULL, 0);
			zephir_check_call_status();
			zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "DO RELEASE_LOCK(:key)");
			ZEPHIR_CALL_METHOD(&releaseStmt, &_5$$3, "prepare", NULL, 0, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, ":key");
			ZVAL_LONG(&_6$$3, 2);
			ZEPHIR_CALL_METHOD(NULL, &releaseStmt, "bindvalue", NULL, 0, &_4$$3, &lockId, &_6$$3);
			zephir_check_call_status();
			RETURN_CCTOR(&releaseStmt);
		}
		if (ZEPHIR_IS_STRING(&_0, "pgsql")) {
			ZEPHIR_INIT_VAR(&_7$$4);
			ZEPHIR_GET_CONSTANT(&_7$$4, "PHP_INT_SIZE");
			if (ZEPHIR_IS_LONG_IDENTICAL(&_7$$4, 4)) {
				ZEPHIR_CALL_METHOD(&sessionInt1, this_ptr, "convertstringtoint", &_8, 226, &sessionId);
				zephir_check_call_status();
				ZVAL_LONG(&_9$$5, 4);
				ZVAL_LONG(&_10$$5, 4);
				ZEPHIR_INIT_VAR(&_11$$5);
				zephir_substr(&_11$$5, &sessionId, 4 , 4 , 0);
				ZEPHIR_CALL_METHOD(&sessionInt2, this_ptr, "convertstringtoint", &_8, 226, &_11$$5);
				zephir_check_call_status();
				zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "SELECT pg_advisory_lock(:key1, :key2)");
				ZEPHIR_CALL_METHOD(&stmt, &_12$$5, "prepare", NULL, 0, &_13$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, ":key1");
				ZVAL_LONG(&_14$$5, 1);
				ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_13$$5, &sessionInt1, &_14$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, ":key2");
				ZVAL_LONG(&_14$$5, 1);
				ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_13$$5, &sessionInt2, &_14$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &stmt, "execute", NULL, 0);
				zephir_check_call_status();
				zephir_read_property(&_14$$5, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, "SELECT pg_advisory_unlock(:key1, :key2)");
				ZEPHIR_CALL_METHOD(&releaseStmt, &_14$$5, "prepare", NULL, 0, &_13$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, ":key1");
				ZVAL_LONG(&_15$$5, 1);
				ZEPHIR_CALL_METHOD(NULL, &releaseStmt, "bindvalue", NULL, 0, &_13$$5, &sessionInt1, &_15$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_STRING(&_13$$5, ":key2");
				ZVAL_LONG(&_15$$5, 1);
				ZEPHIR_CALL_METHOD(NULL, &releaseStmt, "bindvalue", NULL, 0, &_13$$5, &sessionInt2, &_15$$5);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&sessionBigInt, this_ptr, "convertstringtoint", &_8, 226, &sessionId);
				zephir_check_call_status();
				zephir_read_property(&_16$$6, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_17$$6);
				ZVAL_STRING(&_17$$6, "SELECT pg_advisory_lock(:key)");
				ZEPHIR_CALL_METHOD(&stmt, &_16$$6, "prepare", NULL, 0, &_17$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$6);
				ZVAL_STRING(&_17$$6, ":key");
				ZVAL_LONG(&_18$$6, 1);
				ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_17$$6, &sessionBigInt, &_18$$6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &stmt, "execute", NULL, 0);
				zephir_check_call_status();
				zephir_read_property(&_18$$6, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_17$$6);
				ZVAL_STRING(&_17$$6, "SELECT pg_advisory_unlock(:key)");
				ZEPHIR_CALL_METHOD(&releaseStmt, &_18$$6, "prepare", NULL, 0, &_17$$6);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$6);
				ZVAL_STRING(&_17$$6, ":key");
				ZVAL_LONG(&_19$$6, 1);
				ZEPHIR_CALL_METHOD(NULL, &releaseStmt, "bindvalue", NULL, 0, &_17$$6, &sessionBigInt, &_19$$6);
				zephir_check_call_status();
			}
			RETURN_CCTOR(&releaseStmt);
		}
		if (ZEPHIR_IS_STRING(&_0, "sqlite")) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_DomainException, "SQLite does not support advisory locks.", "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 692);
			return;
		}
		ZEPHIR_INIT_VAR(&_20$$8);
		object_init_ex(&_20$$8, spl_ce_DomainException);
		zephir_read_property(&_21$$8, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_22$$8);
		ZVAL_STRING(&_22$$8, "Advisory locks are currently not implemented for PDO driver \"%s\".");
		ZEPHIR_CALL_FUNCTION(&_23$$8, "sprintf", NULL, 3, &_22$$8, &_21$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_20$$8, "__construct", NULL, 214, &_23$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_20$$8, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 694);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Encodes the first 4 (when PHP_INT_SIZE == 4) or 8 characters of the string as an integer.
 *
 * Keep in mind, PHP integers are signed.
 *
 * @param string $string
 * @return int
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, convertStringToInt) {

	unsigned char _11, _14, _16, _18, _20, _22, _24, _26, _1$$3, _5$$3, _7$$3, _9$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *_string_param = NULL, int2, int1, _0, _12, _13, _15, _17, _19, _21, _23, _25, _27, _2$$3, _3$$3, _6$$3, _8$$3, _10$$3;
	zval _string;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_string);
	ZVAL_UNDEF(&int2);
	ZVAL_UNDEF(&int1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_string_param);

	zephir_get_strval(&_string, _string_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_INT_SIZE");
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 4)) {
		_1$$3 = ZEPHIR_STRING_OFFSET(&_string, 3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRINGL(&_2$$3, &_1$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "ord", &_4, 125, &_2$$3);
		zephir_check_call_status();
		_5$$3 = ZEPHIR_STRING_OFFSET(&_string, 2);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRINGL(&_2$$3, &_5$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "ord", &_4, 125, &_2$$3);
		zephir_check_call_status();
		_7$$3 = ZEPHIR_STRING_OFFSET(&_string, 1);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRINGL(&_2$$3, &_7$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_8$$3, "ord", &_4, 125, &_2$$3);
		zephir_check_call_status();
		_9$$3 = ZEPHIR_STRING_OFFSET(&_string, 0);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRINGL(&_2$$3, &_9$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_10$$3, "ord", &_4, 125, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_LONG((((((int) (zephir_get_numberval(&_3$$3)) << 24) + ((int) (zephir_get_numberval(&_6$$3)) << 16)) + ((int) (zephir_get_numberval(&_8$$3)) << 8)) + zephir_get_numberval(&_10$$3)));
	}
	_11 = ZEPHIR_STRING_OFFSET(&_string, 7);
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRINGL(&_12, &_11, 1);
	ZEPHIR_CALL_FUNCTION(&_13, "ord", &_4, 125, &_12);
	zephir_check_call_status();
	_14 = ZEPHIR_STRING_OFFSET(&_string, 6);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRINGL(&_12, &_14, 1);
	ZEPHIR_CALL_FUNCTION(&_15, "ord", &_4, 125, &_12);
	zephir_check_call_status();
	_16 = ZEPHIR_STRING_OFFSET(&_string, 5);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRINGL(&_12, &_16, 1);
	ZEPHIR_CALL_FUNCTION(&_17, "ord", &_4, 125, &_12);
	zephir_check_call_status();
	_18 = ZEPHIR_STRING_OFFSET(&_string, 4);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRINGL(&_12, &_18, 1);
	ZEPHIR_CALL_FUNCTION(&_19, "ord", &_4, 125, &_12);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&int1);
	ZVAL_LONG(&int1, (((((int) (zephir_get_numberval(&_13)) << 24) + ((int) (zephir_get_numberval(&_15)) << 16)) + ((int) (zephir_get_numberval(&_17)) << 8)) + zephir_get_numberval(&_19)));
	_20 = ZEPHIR_STRING_OFFSET(&_string, 3);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRINGL(&_12, &_20, 1);
	ZEPHIR_CALL_FUNCTION(&_21, "ord", &_4, 125, &_12);
	zephir_check_call_status();
	_22 = ZEPHIR_STRING_OFFSET(&_string, 2);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRINGL(&_12, &_22, 1);
	ZEPHIR_CALL_FUNCTION(&_23, "ord", &_4, 125, &_12);
	zephir_check_call_status();
	_24 = ZEPHIR_STRING_OFFSET(&_string, 1);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRINGL(&_12, &_24, 1);
	ZEPHIR_CALL_FUNCTION(&_25, "ord", &_4, 125, &_12);
	zephir_check_call_status();
	_26 = ZEPHIR_STRING_OFFSET(&_string, 0);
	ZEPHIR_INIT_NVAR(&_12);
	ZVAL_STRINGL(&_12, &_26, 1);
	ZEPHIR_CALL_FUNCTION(&_27, "ord", &_4, 125, &_12);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&int2);
	ZVAL_LONG(&int2, (((((int) (zephir_get_numberval(&_21)) << 24) + ((int) (zephir_get_numberval(&_23)) << 16)) + ((int) (zephir_get_numberval(&_25)) << 8)) + zephir_get_numberval(&_27)));
	RETURN_MM_LONG((zephir_get_numberval(&int2) + (((int) (zephir_get_numberval(&int1)) << 16))));

}

/**
 * Return a locking or nonlocking SQL query to read session information.
 *
 * @throws \DomainException When an unsupported PDO driver is used
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getSelectSql) {

	zval _0, _1$$3, _2$$7, _3$$7, _4$$7, _5$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("lockMode"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG_IDENTICAL(&_0, 2)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "begintransaction", NULL, 225);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_STRING(&_1$$3, "mysql") || ZEPHIR_IS_STRING(&_1$$3, "oci") || ZEPHIR_IS_STRING(&_1$$3, "pgsql")) {
				RETURN_MM_STRING("SELECT {this->dataCol}, {this->lifetimeCol}, {this->timeCol} FROM {this->table} WHERE {this->idCol} = :id FOR UPDATE");
			}
			if (ZEPHIR_IS_STRING(&_1$$3, "sqlsrv")) {
				RETURN_MM_STRING("SELECT {this->dataCol}, {this->lifetimeCol}, {this->timeCol} FROM {this->table} WITH (UPDLOCK, ROWLOCK) WHERE {this->idCol} = :id");
			}
			if (ZEPHIR_IS_STRING(&_1$$3, "sqlite")) {
				break;
			}
			ZEPHIR_INIT_VAR(&_2$$7);
			object_init_ex(&_2$$7, spl_ce_DomainException);
			zephir_read_property(&_3$$7, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_4$$7);
			ZVAL_STRING(&_4$$7, "Transactional locks are currently not implemented for PDO driver \"%s\".");
			ZEPHIR_CALL_FUNCTION(&_5$$7, "sprintf", NULL, 3, &_4$$7, &_3$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_2$$7, "__construct", NULL, 214, &_5$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$7, "moon/Component/Http/Message/Session/Storage/Handler/PdoSessionHandler.zep", 740);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

	}
	RETURN_MM_STRING("SELECT {this->dataCol}, {this->lifetimeCol}, {this->timeCol} FROM {this->table} WHERE {this->idCol} = :id");

}

/**
 * Returns an insert statement supported by the database for writing session data.
 *
 * @param string $sessionId
 * @param string $sessionData
 * @param int $maxlifetime
 * @return \PDOStatement
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getInsertStatement) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long maxlifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *sessionData_param = NULL, *maxlifetime_param = NULL, stmt, sql, data, _0, _3, _4, _5, _6, _7, _8, _1$$3, _2$$3;
	zval sessionId, sessionData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&sessionData);
	ZVAL_UNDEF(&stmt);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &sessionId_param, &sessionData_param, &maxlifetime_param);

	zephir_get_strval(&sessionId, sessionId_param);
	zephir_get_strval(&sessionData, sessionData_param);
	maxlifetime = zephir_get_intval(maxlifetime_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_STRING(&_0, "oci")) {
			ZEPHIR_INIT_VAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "php://memory");
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "r+");
			ZEPHIR_CALL_FUNCTION(&data, "fopen", NULL, 140, &_1$$3, &_2$$3);
			zephir_check_call_status();
			zephir_fwrite(NULL, &data, &sessionData);
			ZEPHIR_CALL_FUNCTION(NULL, "rewind", NULL, 227, &data);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&sql);
			ZVAL_STRING(&sql, "INSERT INTO {this->table} ({this->idCol}, {this->dataCol}, {this->lifetimeCol}, {this->timeCol}) VALUES (:id, EMPTY_BLOB(), :expiry, :time) RETURNING {this->dataCol} into :data");
			break;
		}
		ZEPHIR_CPY_WRT(&data, &sessionData);
		ZEPHIR_INIT_NVAR(&sql);
		ZVAL_STRING(&sql, "INSERT INTO {this->table} ({this->idCol}, {this->dataCol}, {this->lifetimeCol}, {this->timeCol}) VALUES (:id, :data, :expiry, :time)");
		break;
	} while(0);

	zephir_read_property(&_3, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&stmt, &_3, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, ":id");
	ZVAL_LONG(&_5, 2);
	ZEPHIR_CALL_METHOD(NULL, &stmt, "bindparam", NULL, 0, &_4, &sessionId, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, ":data");
	ZVAL_LONG(&_5, 3);
	ZEPHIR_CALL_METHOD(NULL, &stmt, "bindparam", NULL, 0, &_4, &data, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	zephir_time(&_4);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, ":expiry");
	ZVAL_LONG(&_5, (zephir_get_numberval(&_4) + maxlifetime));
	ZVAL_LONG(&_7, 1);
	ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_6, &_5, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_6);
	zephir_time(&_6);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, ":time");
	ZVAL_LONG(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_8, &_6, &_5);
	zephir_check_call_status();
	RETURN_CCTOR(&stmt);

}

/**
 * Returns an update statement supported by the database for writing session data.
 *
 * @param string $sessionId
 * @param string $sessionData
 * @param int $maxlifetime
 * @return \PDOStatement
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getUpdateStatement) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long maxlifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *sessionData_param = NULL, *maxlifetime_param = NULL, stmt, sql, data, _0, _3, _4, _5, _6, _7, _8, _1$$3, _2$$3;
	zval sessionId, sessionData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&sessionData);
	ZVAL_UNDEF(&stmt);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &sessionId_param, &sessionData_param, &maxlifetime_param);

	zephir_get_strval(&sessionId, sessionId_param);
	zephir_get_strval(&sessionData, sessionData_param);
	maxlifetime = zephir_get_intval(maxlifetime_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_STRING(&_0, "oci")) {
			ZEPHIR_INIT_VAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "php://memory");
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "r+");
			ZEPHIR_CALL_FUNCTION(&data, "fopen", NULL, 140, &_1$$3, &_2$$3);
			zephir_check_call_status();
			zephir_fwrite(NULL, &data, &sessionData);
			ZEPHIR_CALL_FUNCTION(NULL, "rewind", NULL, 227, &data);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&sql);
			ZVAL_STRING(&sql, "UPDATE {this->table} SET {this->dataCol} = EMPTY_BLOB(), {this->lifetimeCol} = :expiry, {this->timeCol} = :time WHERE {this->idCol} = :id RETURNING {this->dataCol} into :data");
			break;
		}
		ZEPHIR_CPY_WRT(&data, &sessionData);
		ZEPHIR_INIT_NVAR(&sql);
		ZVAL_STRING(&sql, "UPDATE {this->table} SET {this->dataCol} = :data, {this->lifetimeCol} = :expiry, {this->timeCol} = :time WHERE {this->idCol} = :id");
		break;
	} while(0);

	zephir_read_property(&_3, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&stmt, &_3, "prepare", NULL, 0, &sql);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, ":id");
	ZVAL_LONG(&_5, 2);
	ZEPHIR_CALL_METHOD(NULL, &stmt, "bindparam", NULL, 0, &_4, &sessionId, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, ":data");
	ZVAL_LONG(&_5, 3);
	ZEPHIR_CALL_METHOD(NULL, &stmt, "bindparam", NULL, 0, &_4, &data, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	zephir_time(&_4);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, ":expiry");
	ZVAL_LONG(&_5, (zephir_get_numberval(&_4) + maxlifetime));
	ZVAL_LONG(&_7, 1);
	ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_6, &_5, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_6);
	zephir_time(&_6);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, ":time");
	ZVAL_LONG(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &stmt, "bindvalue", NULL, 0, &_8, &_6, &_5);
	zephir_check_call_status();
	RETURN_CCTOR(&stmt);

}

/**
 * Returns a merge/upsert (i.e. insert or update) statement when supported by the database for writing session data.
 *
 * @param string $sessionId
 * @param string $data
 * @param int $maxlifetime
 * @return \PDOStatement|null
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getMergeStatement) {

	zend_bool _0, _6, _18;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long maxlifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *data_param = NULL, *maxlifetime_param = NULL, mergeStmt, mergeSql, _1, _2, _4, _5, _7, _8, _9, _10, _11, _12, _15, _16, _17, _19, _20, _21, _22, _24, _25, _26$$8, _27$$8, _28$$8, _29$$8, _30$$8, _31$$8, _32$$8, _33$$9, _34$$9, _35$$9, _36$$9, _37$$9;
	zval sessionId, data, _3$$3, _14$$4, _23$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&mergeStmt);
	ZVAL_UNDEF(&mergeSql);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_37$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &sessionId_param, &data_param, &maxlifetime_param);

	zephir_get_strval(&sessionId, sessionId_param);
	zephir_get_strval(&data, data_param);
	maxlifetime = zephir_get_intval(maxlifetime_param);


	do {
		_0 = 1;
		zephir_read_property(&_1, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "mysql");
		if (_0 == ZEPHIR_IS_IDENTICAL(&_2, &_1)) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZEPHIR_CONCAT_SS(&_3$$3, "INSERT INTO {this->table} ({this->idCol}, {this->dataCol}, {this->lifetimeCol}, {this->timeCol}) VALUES (:id, :data, :expiry, :time) ", "ON DUPLICATE KEY UPDATE {this->dataCol} = VALUES({this->dataCol}), {this->lifetimeCol} = VALUES({this->lifetimeCol}), {this->timeCol} = VALUES({this->timeCol})");
			ZEPHIR_CPY_WRT(&mergeSql, &_3$$3);
			break;
		}
		zephir_read_property(&_4, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "sqlsrv");
		_6 = ZEPHIR_IS_IDENTICAL(&_5, &_4);
		if (_6) {
			zephir_read_property(&_7, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_9, 4);
			ZEPHIR_CALL_METHOD(&_8, &_7, "getattribute", NULL, 0, &_9);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_10);
			ZVAL_STRING(&_10, "10");
			ZEPHIR_INIT_VAR(&_11);
			ZVAL_STRING(&_11, ">=");
			ZEPHIR_CALL_FUNCTION(&_12, "version_compare", &_13, 228, &_8, &_10, &_11);
			zephir_check_call_status();
			_6 = zephir_is_true(&_12);
		}
		if (_0 == _6) {
			ZEPHIR_INIT_VAR(&_14$$4);
			ZEPHIR_CONCAT_SSS(&_14$$4, "MERGE INTO {this->table} WITH (HOLDLOCK) USING (SELECT 1 AS dummy) AS src ON ({this->idCol} = ?) ", "WHEN NOT MATCHED THEN INSERT ({this->idCol}, {this->dataCol}, {this->lifetimeCol}, {this->timeCol}) VALUES (?, ?, ?, ?) ", "WHEN MATCHED THEN UPDATE SET {this->dataCol} = ?, {this->lifetimeCol} = ?, {this->timeCol} = ?;");
			ZEPHIR_CPY_WRT(&mergeSql, &_14$$4);
			break;
		}
		zephir_read_property(&_9, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_15);
		ZVAL_STRING(&_15, "sqlite");
		if (_0 == ZEPHIR_IS_IDENTICAL(&_15, &_9)) {
			ZEPHIR_INIT_NVAR(&mergeSql);
			ZVAL_STRING(&mergeSql, "INSERT OR REPLACE INTO {this->table} ({this->idCol}, {this->dataCol}, {this->lifetimeCol}, {this->timeCol}) VALUES (:id, :data, :expiry, :time)");
			break;
		}
		zephir_read_property(&_16, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_17);
		ZVAL_STRING(&_17, "pgsql");
		_18 = ZEPHIR_IS_IDENTICAL(&_17, &_16);
		if (_18) {
			zephir_read_property(&_19, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_21, 4);
			ZEPHIR_CALL_METHOD(&_20, &_19, "getattribute", NULL, 0, &_21);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10);
			ZVAL_STRING(&_10, "9.5");
			ZEPHIR_INIT_NVAR(&_11);
			ZVAL_STRING(&_11, ">=");
			ZEPHIR_CALL_FUNCTION(&_22, "version_compare", &_13, 228, &_20, &_10, &_11);
			zephir_check_call_status();
			_18 = zephir_is_true(&_22);
		}
		if (_0 == _18) {
			ZEPHIR_INIT_VAR(&_23$$6);
			ZEPHIR_CONCAT_SS(&_23$$6, "INSERT INTO {this->table} ({this->idCol}, {this->dataCol}, {this->lifetimeCol}, {this->timeCol}) VALUES (:id, :data, :expiry, :time) ", "ON CONFLICT ({this->idCol}) DO UPDATE SET ({this->dataCol}, {this->lifetimeCol}, {this->timeCol}) = (EXCLUDED.{this->dataCol}, EXCLUDED.{this->lifetimeCol}, EXCLUDED.{this->timeCol})");
			ZEPHIR_CPY_WRT(&mergeSql, &_23$$6);
			break;
		}
		RETURN_MM_NULL();
	} while(0);

	zephir_read_property(&_21, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&mergeStmt, &_21, "prepare", NULL, 0, &mergeSql);
	zephir_check_call_status();
	zephir_read_property(&_24, this_ptr, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_25);
	ZVAL_STRING(&_25, "sqlsrv");
	if (ZEPHIR_IS_IDENTICAL(&_25, &_24)) {
		ZVAL_LONG(&_26$$8, 1);
		ZVAL_LONG(&_27$$8, 2);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindparam", NULL, 0, &_26$$8, &sessionId, &_27$$8);
		zephir_check_call_status();
		ZVAL_LONG(&_26$$8, 2);
		ZVAL_LONG(&_27$$8, 2);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindparam", NULL, 0, &_26$$8, &sessionId, &_27$$8);
		zephir_check_call_status();
		ZVAL_LONG(&_26$$8, 3);
		ZVAL_LONG(&_27$$8, 3);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindparam", NULL, 0, &_26$$8, &data, &_27$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_28$$8);
		zephir_time(&_28$$8);
		ZVAL_LONG(&_26$$8, 4);
		ZVAL_LONG(&_27$$8, (zephir_get_numberval(&_28$$8) + maxlifetime));
		ZVAL_LONG(&_29$$8, 1);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindvalue", NULL, 0, &_26$$8, &_27$$8, &_29$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_30$$8);
		zephir_time(&_30$$8);
		ZVAL_LONG(&_26$$8, 5);
		ZVAL_LONG(&_27$$8, 1);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindvalue", NULL, 0, &_26$$8, &_30$$8, &_27$$8);
		zephir_check_call_status();
		ZVAL_LONG(&_26$$8, 6);
		ZVAL_LONG(&_27$$8, 3);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindparam", NULL, 0, &_26$$8, &data, &_27$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_31$$8);
		zephir_time(&_31$$8);
		ZVAL_LONG(&_26$$8, 7);
		ZVAL_LONG(&_27$$8, (zephir_get_numberval(&_31$$8) + maxlifetime));
		ZVAL_LONG(&_29$$8, 1);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindvalue", NULL, 0, &_26$$8, &_27$$8, &_29$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_32$$8);
		zephir_time(&_32$$8);
		ZVAL_LONG(&_26$$8, 8);
		ZVAL_LONG(&_27$$8, 1);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindvalue", NULL, 0, &_26$$8, &_32$$8, &_27$$8);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_33$$9);
		ZVAL_STRING(&_33$$9, ":id");
		ZVAL_LONG(&_34$$9, 2);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindparam", NULL, 0, &_33$$9, &sessionId, &_34$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_33$$9);
		ZVAL_STRING(&_33$$9, ":data");
		ZVAL_LONG(&_34$$9, 3);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindparam", NULL, 0, &_33$$9, &data, &_34$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_33$$9);
		zephir_time(&_33$$9);
		ZEPHIR_INIT_VAR(&_35$$9);
		ZVAL_STRING(&_35$$9, ":expiry");
		ZVAL_LONG(&_34$$9, (zephir_get_numberval(&_33$$9) + maxlifetime));
		ZVAL_LONG(&_36$$9, 1);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindvalue", NULL, 0, &_35$$9, &_34$$9, &_36$$9);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_35$$9);
		zephir_time(&_35$$9);
		ZEPHIR_INIT_VAR(&_37$$9);
		ZVAL_STRING(&_37$$9, ":time");
		ZVAL_LONG(&_34$$9, 1);
		ZEPHIR_CALL_METHOD(NULL, &mergeStmt, "bindvalue", NULL, 0, &_37$$9, &_35$$9, &_34$$9);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&mergeStmt);

}

/**
 * Return a PDO instance.
 *
 * @return \PDO
 */
PHP_METHOD(Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler, getConnection) {

	zval _0, _1$$3, _2$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("pdo"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("dsn"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_is_true(&_2$$3))) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "session.save_path");
			ZEPHIR_CALL_FUNCTION(&_1$$3, "ini_get", NULL, 13, &_3$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_OBS_NVAR(&_1$$3);
			zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("dsn"), PH_NOISY_CC);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL, 216, &_1$$3);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "pdo");

}

zend_object *zephir_init_properties_Moon_Component_Http_Message_Session_Storage_Handler_PdoSessionHandler(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("unlockStatements"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("unlockStatements"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("connectionOptions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("connectionOptions"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

