
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_MOON_H
#define PHP_MOON_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_MOON_NAME        "moon"
#define PHP_MOON_VERSION     "0.0.4"
#define PHP_MOON_EXTNAME     "moon"
#define PHP_MOON_AUTHOR      "solely"
#define PHP_MOON_ZEPVERSION  "0.12.19-$Id$"
#define PHP_MOON_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(moon)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(moon)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(moon)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(moon, v)
#else
	#define ZEPHIR_GLOBAL(v) (moon_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_moon_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(moon_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(moon_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def moon_globals
#define zend_zephir_globals_def zend_moon_globals

extern zend_module_entry moon_module_entry;
#define phpext_moon_ptr &moon_module_entry

#endif
