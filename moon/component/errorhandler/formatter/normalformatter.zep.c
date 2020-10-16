
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/math.h"


/**
 * FileName: NormalFormatter.php
 * User: solely
 * DateTime: 2019/11/23 19:16
 * Description:
 */
ZEPHIR_INIT_CLASS(Moon_Component_ErrorHandler_Formatter_NormalFormatter) {

	ZEPHIR_REGISTER_CLASS(Moon\\Component\\ErrorHandler\\Formatter, NormalFormatter, moon, component_errorhandler_formatter_normalformatter, moon_component_errorhandler_formatter_normalformatter_method_entry, 0);

	/** @var $exception \Throwable */
	zend_declare_property_null(moon_component_errorhandler_formatter_normalformatter_ce, SL("exception"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_formatter_normalformatter_ce, SL("debug"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_formatter_normalformatter_ce, SL("charset"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_formatter_normalformatter_ce, SL("collapsePaths"), ZEND_ACC_PRIVATE);

	/** @var string[] */
	zend_declare_property_null(moon_component_errorhandler_formatter_normalformatter_ce, SL("keysToHide"), ZEND_ACC_PUBLIC);

	/** @var int */
	zend_declare_property_long(moon_component_errorhandler_formatter_normalformatter_ce, SL("maxDepth"), 3, ZEND_ACC_PUBLIC);

	/** @var int */
	zend_declare_property_long(moon_component_errorhandler_formatter_normalformatter_ce, SL("maxLength"), 150, ZEND_ACC_PUBLIC);

	/** @var array */
	zend_declare_property_null(moon_component_errorhandler_formatter_normalformatter_ce, SL("snapshot"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(moon_component_errorhandler_formatter_normalformatter_ce, SL("panel"), ZEND_ACC_PRIVATE);

	moon_component_errorhandler_formatter_normalformatter_ce->create_object = zephir_init_properties_Moon_Component_ErrorHandler_Formatter_NormalFormatter;

	zend_class_implements(moon_component_errorhandler_formatter_normalformatter_ce, 1, moon_component_errorhandler_formatter_formatterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, format) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, *debug, debug_sub, *charset, charset_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&debug_sub);
	ZVAL_UNDEF(&charset_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &exception, &debug, &charset);



	zephir_update_property_zval(this_ptr, ZEND_STRL("exception"), exception);
	zephir_update_property_zval(this_ptr, ZEND_STRL("debug"), debug);
	zephir_update_property_zval(this_ptr, ZEND_STRL("charset"), charset);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("debug"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_GET_CONSTANT(&_1$$3, "PHP_SAPI");
		if (ZEPHIR_IS_STRING_IDENTICAL(&_1$$3, "cli")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "output", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "render", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, log) {

	zval e, handle, logFile, _0, _1, _2, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&logFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "error_log");
	ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 13, &_0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&_1))) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "error_log");
		ZEPHIR_CALL_FUNCTION(&logFile, "ini_get", NULL, 13, &_0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&_2, "getcwd", NULL, 139);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&logFile);
		ZEPHIR_CONCAT_VS(&logFile, &_2, "/php_error.log");
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "ab");
	ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 140, &logFile, &_0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&handle)) {
		ZEPHIR_OBS_VAR(&e);
		zephir_read_property(&e, this_ptr, ZEND_STRL("exception"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Y-m-d H:i:s");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "date", NULL, 141, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, &e, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$3, &e, "getfile", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, &e, "getline", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "[%s] %s in %s:%d\n");
		ZEPHIR_CALL_FUNCTION(&_8$$3, "sprintf", NULL, 3, &_3$$3, &_4$$3, &_5$$3, &_6$$3, &_7$$3);
		zephir_check_call_status();
		zephir_fwrite(NULL, &handle, &_8$$3);
		ZEPHIR_CALL_METHOD(&_9$$3, &e, "gettraceasstring", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZEPHIR_GET_CONSTANT(&_3$$3, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_10$$3);
		ZEPHIR_CONCAT_VV(&_10$$3, &_9$$3, &_3$$3);
		zephir_fwrite(NULL, &handle, &_10$$3);
	}
	zephir_fclose(&handle);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, output) {

	zval e, _0, _1, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&e);
	zephir_read_property(&e, this_ptr, ZEND_STRL("exception"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 141, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &e, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &e, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &e, "getline", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\33[30;41;1m[%s] %s in %s:%d\33[0m\n");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 3, &_0, &_1, &_2, &_3, &_4);
	zephir_check_call_status();
	zend_print_zval(&_5, 0);
	ZEPHIR_CALL_METHOD(&_6, &e, "gettraceasstring", NULL, 0);
	zephir_check_call_status();
	zend_print_zval(&_6, 0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	zend_print_zval(&_0, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, render) {

	zval html, e, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10$$3, _11$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&e);
	zephir_read_property(&e, this_ptr, ZEND_STRL("exception"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("charset"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &e, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcss", NULL, 142);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "formatmessage", NULL, 143);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getsourcefile", NULL, 144);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcallstack", NULL, 145);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getvariables", NULL, 146);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getpanellist", NULL, 147);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getscript", NULL, 148);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_SSSVSVSSVSSSSVSVVVVSVS(&html, "<html>", "<head>", "<meta charset=", &_0, "><meta name='robots' content='noindex'><meta name='generator' content='Moon'><title>", &_1, "</title>", "<style class='moon-debug'>", &_2, "</style>", "</head> <body> <div id='moon-bs' itemscope> <a id='moon-bs-toggle' href='#' class='moon-toggle'></a>", "<div class='moon-bs-main'> <div id='moon-bs-error' class='panel'>", "<h1>", &_3, "</h1> </div>", &_4, &_5, &_6, &_7, " </div> </div> <script>", &_8, "</script> </body> </html>");
	ZEPHIR_CALL_FUNCTION(&_9, "headers_sent", NULL, 10);
	zephir_check_call_status();
	if (!zephir_is_true(&_9)) {
		zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("charset"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$3);
		ZEPHIR_CONCAT_SV(&_11$$3, "Content-Type: text/html; charset=", &_10$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 12, &_11$$3);
		zephir_check_call_status();
	}
	zend_print_zval(&html, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getCss) {

	zval *this_ptr = getThis();


	ZEPHIR_CONCAT_SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS(return_value, " #moon-bs {", "font: 9pt/1.5 Verdana, sans-serif;", "background: white;", "color: #333;", "position: absolute;", "z-index: 20000;", "left: 0;", "top: 0;", "width: 100%;", "text-align: left;", "}", "#moon-bs a {", "text-decoration: none;", "color: #328ADC;", "padding: 2px 4px;", "margin: -2px -4px;", "}", "#moon-bs a:hover,", "#moon-bs a:focus {", "\tcolor: #085AA3;", "}", "#moon-bs-toggle {", "\tposition: absolute;", "\tright: .5em;", "\ttop: .5em;", "\ttext-decoration: none;", "\tbackground: #CD1818;", "\tcolor: white !important;", "\tpadding: 3px;", "}", ".moon-bs-main {", "\tdisplay: flex;", "\tflex-direction: column;", "\tmin-height: 100vh;", "}", ".moon-bs-main.moon-collapsed {", "\tdisplay: none;", "}", "#moon-bs div.panel:last-of-type {", "\tflex: 1;", "}", "#moon-bs-error {", "\tbackground: #CD1818;", "\tcolor: white;", "\tfont-size: 13pt;", "}", "#moon-bs-error a {", "\tcolor: white !important;", "\topacity: 0;", "\tfont-size: .7em;", "\tborder-bottom: none !important;", "}", "#moon-bs-error:hover a {", "\topacity: .6;", "}", "#moon-bs-error a:hover {", "\topacity: 1;", "}", "#moon-bs-error i {", "\tcolor: #ffefa1;", "\tfont-style: normal;", "}", "#moon-bs h1 {", "\tfont-size: 15pt;", "\tfont-weight: normal;", "\ttext-shadow: 1px 1px 2px rgba(0, 0, 0, .3);", "\tmargin: .7em 0;", "}", "#moon-bs h1 span {", "\twhite-space: pre-wrap;", "}", "#moon-bs h2 {", "\tfont-size: 14pt;", "\tfont-weight: normal;", "\tmargin: .6em 0;", "}", "#moon-bs h3 {", "\tfont-size: 10pt;", "\tfont-weight: bold;", "\tmargin: 1em 0;", "\tpadding: 0;", "}", "#moon-bs p,", "#moon-bs pre {", "\tmargin: .8em 0", "}", "#moon-bs pre,", "#moon-bs code,", "#moon-bs table {", "\tfont: 9pt/1.5 Consolas, monospace !important;", "}", "#moon-bs pre,", "#moon-bs table {", "\tbackground: #FDF5CE;", "\tpadding: .4em .7em;", "\tborder: 1px dotted silver;", "\toverflow: auto;", "}", "#moon-bs table pre {", "\tpadding: 0;", "\tmargin: 0;", "\tborder: none;", "}", "#moon-bs table {", "\tborder-collapse: collapse;", "\twidth: 100%;", "\tmargin-bottom: 1em;", "}", "#moon-bs td,", "#moon-bs th {", "\tvertical-align: top;", "\ttext-align: left;", "\tpadding: 2px 6px;", "\tborder: 1px solid #e6dfbf;", "}", "#moon-bs th {", "\tfont-weight: bold;", "}", "#moon-bs tr > :first-child {", "\twidth: 20%;", "}", "#moon-bs tr:nth-child(2n),", "#moon-bs tr:nth-child(2n) pre {", "\tbackground-color: #F7F0CB;", "}", "#moon-bs ol {", "\tmargin: 1em 0;", "\tpadding-left: 2.5em;", "}", "#moon-bs ul {", "\tfont-size: 7pt;", "\tpadding: 2em 3em;", "\tmargin: 1em 0 0;", "\tcolor: #777;", "\tbackground: #F6F5F3;", "\tborder-top: 1px solid #DDD;", "\tlist-style: none;", "}", "#moon-bs .footer-logo a {", "\tposition: absolute;", "\tbottom: 0;", "\tright: 0;", "\twidth: 100px;", "\theight: 50px;", "\tbackground: url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAFoAAAAUBAMAAAD/1DctAAAAMFBMVEWupZzj39rEvbTy8O3X0sz9/PvGwLu8tavQysHq6OS0rKP5+Pbd2dT29fPMxbzPx8DKErMJAAAACXBIWXMAAAsTAAALEwEAmpwYAAACGUlEQVQoFX3TQWgTQRQA0MWLIJJDYehBTykhG5ERTx56K1u8eEhCYtomE7x5L4iLh0ViF7egewuFFqSIYE6hIHsIYQ6CQSg9CDKn4QsNCRlB59C74J/ZNHW1+An5+bOPyf6/s46oz2P+A0yIeZZ2ieEHi6TOnLKTxvWq+b52mxlVO3xnM1s7xLX1504XQH65OnW2dBqn7cCkYsFsfYsWpyY/2salmFTpEyzeR8zosYqMdiPDXdyU52K1wgEa/SjGpdEwUAxqvRfckQCDOyFearsEHe2grvkh/cFAHKvdtI3lcVceKQIOFpv+FOZaNPQBwJZLPp+hfrvT5JZXaUFsR8zqQc9qSgAharkfS5M/5F6nGJJAtXq/eLr3ucZpHccSxOOIPaQhtHohpCH2Xu6rLmQ0djnr4/+J3C6v+AW8/XWYxwYNdlhWj/P5fPSTQwVr0T9lGxdaBCqErNZaqYnEwbkjEB3NasGF3lPdrHa1nnxNOMgj0+neePUPjd2v/qVvUv29ifvc19huQ48qwXShy/9o8o3OSk0cs37mOFd0Ydgvsf/oZEnPVtggfd66lORn9mDyyzXU13SRtH2L6aR5T/snGAcZPfAXz5J1YlJWBEuxdMYqQecpBrlM49xAbmqyHA+xlA1FxBtqT2xmJoNXZlIt74ZBLeJ9ZGDqByNI7p543idzJ23vXEv7IgnsxiS+eNtwNbFdLq7+Bi4wQ0I4SVb9AAAAAElFTkSuQmCC') no-repeat;", "\topacity: .6;", "\tpadding: 0;", "\tmargin: 0;", "}", "#moon-bs .footer-logo a:hover,", "#moon-bs .footer-logo a:focus {", "\topacity: 1;", "\ttransition: opacity 0.1s;", "}", "#moon-bs div.panel {", "\tpadding: 1px 25px;", "}", "#moon-bs div.inner {", "\tbackground: #F4F3F1;", "\tpadding: .1em 1em 1em;", "\tborder-radius: 8px;", "}", "#moon-bs .outer {", "\toverflow: auto;", "}", "#moon-bs.mac .outer {", "\tpadding-bottom: 12px;", "}", "#moon-bs pre.code > div {", "\tmin-width: 100%;", "\tfloat: left;", "\twhite-space: pre;", "}", "#moon-bs .highlight {", "\tbackground: #CD1818;", "\tcolor: white;", "\tfont-weight: bold;", "\tfont-style: normal;", "\tdisplay: block;", "\tpadding: 0 .4em;", "\tmargin: 0 -.4em;", "}", "#moon-bs .line { \tcolor: #9F9C7F; \tfont-weight: normal; \tfont-style: normal; }", "#moon-bs pre:hover span[title] { \tborder-bottom: 1px solid rgba(0, 0, 0, 0.2); }", "#moon-bs a[href^=editor\\:] { \tcolor: inherit; \tborder-bottom: 1px dotted rgba(0, 0, 0, .3); }", "#moon-bs span[data-moon-href] { \tborder-bottom: 1px dotted rgba(0, 0, 0, .3); }", "#moon-bs .moon-dump-whitespace { \tcolor: #0003; }", "#moon-bs .caused { \tfloat: right; \tpadding: .3em .6em; \tbackground: #df8075; \tborder-radius: 0 0 0 8px; \twhite-space: nowrap; }", "#moon-bs .caused a { \tcolor: white; }", "#moon-bs .args tr:first-child > * { position: relative; }", "#moon-bs .args tr:first-child td:before { \tposition: absolute; \tright: .3em; \tcontent: 'may not be true'; \topacity: .4; }", ".moon-collapsed { \tdisplay: none; }", ".moon-toggle.moon-collapsed { display: inline; }", ".moon-toggle { cursor: pointer; -webkit-user-select: none; \t-moz-user-select: none; \t-khtml-user-select: none; \t-ms-user-select: none; \tuser-select: none; }", ".moon-toggle:after { \t/*content: '\\A0\25BC';*/ \tcontent: ' ▼'; \topacity: .4; }", ".moon-toggle.moon-collapsed:after { \t/*content: \"\\A0\25BA\";*/ \tcontent: \" ▶\"; }", ".moon-sortable tr:first-child > * { \tposition: relative; }", ".moon-sortable tr:first-child > *:hover:before { position: absolute; right: .3em; content: '\21C5'; opacity: .4; font-weight: normal; }", "pre.moon-dump { \ttext-align: left; \tcolor: #444; \tbackground: white; }", "pre.moon-dump div { \tpadding-left: 3ex; }", "pre.moon-dump div div { \tborder-left: 1px solid rgba(0, 0, 0, .1); \tmargin-left: .5ex; }", "pre.moon-dump a { \tcolor: #125EAE; \ttext-decoration: none; }", "pre.moon-dump a:hover, pre.moon-dump a:focus { \tbackground-color: #125EAE; \tcolor: white; }", ".moon-dump-array, .moon-dump-object { color: #C22; }", ".moon-dump-string { color: #35D; }", ".moon-dump-number { color: #090; }", ".moon-dump-null, .moon-dump-bool { color: #850; }", ".moon-dump-visibility, .moon-dump-hash { font-size: 85%; color: #999; }", ".moon-dump-indent { display: none; }", "span[data-moon-href] { border-bottom: 1px dotted rgba(0, 0, 0, .2); }", ".moon-dump-flash { animation: moon-dump-flash .2s ease; }", "@keyframes moon-dump-flash { 0% { background: #c0c0c033; } }");
	return;

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getScript) {

	zval *this_ptr = getThis();


	ZEPHIR_CONCAT_SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS(return_value, "'use strict';", "(function() {", "let Toggle =", "{", "\t    init: function() {", "\t\t\tdocument.documentElement.addEventListener('click', (e) => {", "\t\t\t\tlet el = e.target.closest('.moon-toggle');", "\t\t\t\tif (el && !e.shiftKey && !e.altKey && !e.ctrlKey && !e.metaKey) {", "\t\t\t\t\tToggle.toggle(el);", "\t\t\t\t\te.stopImmediatePropagation();", "\t\t\t\t}", "\t\t\t});", "\t\t\tToggle.init = function() {};", "\t\t},", "\t\ttoggle: function(el, show) {", "\t\t\tlet collapsed = el.classList.contains('moon-collapsed'),", "\t\t\t\tref = el.getAttribute('data-moon-ref') || el.getAttribute('href', 2),", "\t\t\t\tdest = el;", "\t\t\tif (typeof show === 'undefined') {", "\t\t\t\tshow = collapsed;", "\t\t\t} else if (!show === collapsed) {", "\t\t\t\treturn;", "\t\t\t}", "\t\t\tif (!ref || ref === '#') {", "\t\t\t\tref = '+';", "\t\t\t} else if (ref.substr(0, 1) === '#') {", "\t\t\t\tdest = document;", "\t\t\t}", "\t\t\tref = ref.match(/(\\^\\s*([^+\\s]*)\\s*)?(\\+\\s*(\\S*)\\s*)?(.*)/);", "\t\t\tdest = ref[1] ? dest.parentNode : dest;", "\t\t\tdest = ref[2] ? dest.closest(ref[2]) : dest;", "\t\t\tdest = ref[3] ? Toggle.nextElement(dest.nextElementSibling, ref[4]) : dest;", "\t\t\tdest = ref[5] ? dest.querySelector(ref[5]) : dest;", "\t\t\tel.classList.toggle('moon-collapsed', !show);", "\t\t\tdest.classList.toggle('moon-collapsed', !show);", "\t\t\tel.dispatchEvent(new CustomEvent('moon-toggle', {", "\t\t\t\tbubbles: true,", "\t\t\t\tdetail: {relatedTarget: dest, collapsed: !show}", "\t\t\t}));", "\t\t},", "\t\tpersist: function(baseEl, restore) {", "\t\t\tlet saved = [];", "\t\t\tbaseEl.addEventListener('moon-toggle', (e) => {", "\t\t\t\tif (saved.indexOf(e.target) < 0) {", "\t\t\t\t\tsaved.push(e.target);", "\t\t\t\t}", "\t\t\t});", "\t\t\tlet toggles = JSON.parse(sessionStorage.getItem('moon-toggles-' + baseEl.id));", "\t\t\tif (toggles && restore !== false) {", "\t\t\t\ttoggles.forEach((item) => {", "\t\t\t\t\tlet el = baseEl;", "\t\t\t\t\tfor (let i in item.path) {", "\t\t\t\t\t\tif (!(el = el.children[item.path[i]])) {", "\t\t\t\t\t\t\treturn;", "\t\t\t\t\t\t}", "\t\t\t\t\t}", "\t\t\t\t\tif (el.textContent === item.text) {", "\t\t\t\t\t\tToggle.toggle(el, item.show);", "\t\t\t\t\t}", "\t\t\t\t});", "\t\t\t}", "\t\t\twindow.addEventListener('unload', () => {", "\t\t\t\ttoggles = saved.map((el) => {", "\t\t\t\t\tlet item = {path: [], text: el.textContent, show: !el.classList.contains('moon-collapsed')};", "\t\t\t\t\tdo {", "\t\t\t\t\t\titem.path.unshift(Array.from(el.parentNode.children).indexOf(el));", "\t\t\t\t\t\tel = el.parentNode;", "\t\t\t\t\t} while (el && el !== baseEl);", "\t\t\t\t\treturn item;", "\t\t\t\t});", "\t\t\t\tsessionStorage.setItem('moon-toggles-' + baseEl.id, JSON.stringify(toggles));", "\t\t\t});", "\t\t},", "\t\tnextElement: function(el, selector) {", "\t\t\twhile (el && selector && !el.matches(selector)) {", "\t\t\t\tel = el.nextElementSibling;", "\t\t\t}", "\t\t\treturn el;", "\t\t}", "\t}", "\tlet Moon = window.Moon = window.Moon || {};", "\tMoon.Toggle = Moon.Toggle || Toggle;", "\tMoon.Toggle.init();", "})();");
	return;

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, formatMessage) {

	zval h1, message, _0, item, _1, *_2, _3, _4$$3, _5$$3, _7$$4, _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&h1);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("exception"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&message, &_0, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&h1);
	ZVAL_STRING(&h1, "");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_explode_str(&_1, SL("\n"), &message, LONG_MAX);
	zephir_is_iterable(&_1, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 519);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _2);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "<p>%s</p>");
			ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", &_6, 3, &_4$$3, &item);
			zephir_check_call_status();
			zephir_concat_self(&h1, &_5$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_STRING(&_7$$4, "<p>%s</p>");
				ZEPHIR_CALL_FUNCTION(&_8$$4, "sprintf", &_6, 3, &_7$$4, &item);
				zephir_check_call_status();
				zephir_concat_self(&h1, &_8$$4);
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&h1);

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getSourceFile) {

	zend_string *_7$$3;
	zend_ulong _6$$3;
	zend_bool _0, _8$$4, _11$$6;
	zval collapsed, expanded, stack, e, _1, _2, _14, _15, _16, _17, _18, _19, _20, _21, key$$3, row$$3, *_4$$3, _5$$3, _9$$4, _10$$4, _12$$6, _13$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collapsed);
	ZVAL_UNDEF(&expanded);
	ZVAL_UNDEF(&stack);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&key$$3);
	ZVAL_UNDEF(&row$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&e);
	zephir_read_property(&e, this_ptr, ZEND_STRL("exception"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&stack, &e, "gettrace", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&expanded);
	ZVAL_NULL(&expanded);
	_0 = !((zephir_instance_of_ev(&e, moon_component_errorhandler_exception_errorexception_ce)));
	if (_0) {
		ZEPHIR_CALL_METHOD(&_2, &e, "getfile", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "iscollapsed", &_3, 0, &_2);
		zephir_check_call_status();
		_0 = zephir_is_true(&_1);
	}
	if (_0) {
		zephir_is_iterable(&stack, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 540);
		if (Z_TYPE_P(&stack) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&stack), _6$$3, _7$$3, _4$$3)
			{
				ZEPHIR_INIT_NVAR(&key$$3);
				if (_7$$3 != NULL) { 
					ZVAL_STR_COPY(&key$$3, _7$$3);
				} else {
					ZVAL_LONG(&key$$3, _6$$3);
				}
				ZEPHIR_INIT_NVAR(&row$$3);
				ZVAL_COPY(&row$$3, _4$$3);
				_8$$4 = zephir_array_isset_string(&row$$3, SL("file"));
				if (_8$$4) {
					zephir_array_fetch_string(&_10$$4, &row$$3, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 535);
					ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "iscollapsed", &_3, 0, &_10$$4);
					zephir_check_call_status();
					_8$$4 = !zephir_is_true(&_9$$4);
				}
				if (_8$$4) {
					ZEPHIR_CPY_WRT(&expanded, &key$$3);
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &stack, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$3, &stack, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key$$3, &stack, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&row$$3, &stack, "current", NULL, 0);
				zephir_check_call_status();
					_11$$6 = zephir_array_isset_string(&row$$3, SL("file"));
					if (_11$$6) {
						zephir_array_fetch_string(&_13$$6, &row$$3, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 535);
						ZEPHIR_CALL_METHOD(&_12$$6, this_ptr, "iscollapsed", &_3, 0, &_13$$6);
						zephir_check_call_status();
						_11$$6 = !zephir_is_true(&_12$$6);
					}
					if (_11$$6) {
						ZEPHIR_CPY_WRT(&expanded, &key$$3);
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, &stack, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&row$$3);
		ZEPHIR_INIT_NVAR(&key$$3);
	}
	if (Z_TYPE_P(&expanded) != IS_NULL) {
		ZEPHIR_INIT_VAR(&collapsed);
		ZVAL_STRING(&collapsed, " moon-collapsed");
	} else {
		ZEPHIR_INIT_NVAR(&collapsed);
		ZVAL_STRING(&collapsed, "");
	}
	ZEPHIR_CALL_METHOD(&_14, &e, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_15, &e, "getline", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_17, &e, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_18, &e, "getline", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_19);
	array_init(&_19);
	zephir_read_property(&_20, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_21, 15);
	ZEPHIR_CALL_METHOD(&_16, this_ptr, "highlightfile", NULL, 0, &_17, &_18, &_21, &_19, &_20);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVSVSVSVS(return_value, "<div class=\"panel\"><h2><a data-moon-ref=\"^+\" class=\"moon-toggle ", &collapsed, "\">Source file</a></h2><div class=\"inner ", &collapsed, "\"><p><b>File:</b>", &_14, ":", &_15, "</p>", &_16, "</div></div>");
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getCallStack) {

	zend_bool _4$$4, _20$$4, _60$$17, _74$$17;
	zend_string *_3$$3, *_43$$12, *_93$$25;
	zend_ulong _2$$3, _42$$12, _92$$25;
	zval params, r, li, dump, stack, e, key$$3, row$$3, *_0$$3, _1$$3, _110$$3, _5$$4, _6$$4, _16$$4, _17$$4, _18$$4, _19$$4, _21$$4, _22$$4, _31$$4, _8$$5, _9$$5, _10$$5, _11$$7, _13$$7, _14$$7, _15$$7, _23$$10, _24$$10, _25$$10, _27$$10, _28$$11, _29$$11, _30$$11, exception$$12, _38$$12, k$$12, v$$12, _39$$12, *_40$$12, _41$$12, _32$$13, _33$$13, _35$$13, _44$$15, _45$$15, _46$$15, _47$$15, _48$$15, _49$$15, _50$$15, _51$$15, _52$$16, _53$$16, _54$$16, _55$$16, _56$$16, _57$$16, _58$$16, _59$$16, _61$$17, _62$$17, _70$$17, _71$$17, _72$$17, _73$$17, _75$$17, _76$$17, _84$$17, _63$$18, _64$$18, _65$$18, _66$$20, _67$$20, _68$$20, _69$$20, _77$$23, _78$$23, _79$$23, _80$$23, _81$$24, _82$$24, _83$$24, exception$$25, _88$$25, k$$25, v$$25, _89$$25, *_90$$25, _91$$25, _85$$26, _86$$26, _87$$26, _94$$28, _95$$28, _96$$28, _97$$28, _98$$28, _99$$28, _100$$28, _101$$28, _102$$29, _103$$29, _104$$29, _105$$29, _106$$29, _107$$29, _108$$29, _109$$29, _111$$30;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_12 = NULL, *_26 = NULL, *_34 = NULL, *_36 = NULL, *_37 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&li);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&stack);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&key$$3);
	ZVAL_UNDEF(&row$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_110$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_31$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&exception$$12);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&k$$12);
	ZVAL_UNDEF(&v$$12);
	ZVAL_UNDEF(&_39$$12);
	ZVAL_UNDEF(&_41$$12);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_44$$15);
	ZVAL_UNDEF(&_45$$15);
	ZVAL_UNDEF(&_46$$15);
	ZVAL_UNDEF(&_47$$15);
	ZVAL_UNDEF(&_48$$15);
	ZVAL_UNDEF(&_49$$15);
	ZVAL_UNDEF(&_50$$15);
	ZVAL_UNDEF(&_51$$15);
	ZVAL_UNDEF(&_52$$16);
	ZVAL_UNDEF(&_53$$16);
	ZVAL_UNDEF(&_54$$16);
	ZVAL_UNDEF(&_55$$16);
	ZVAL_UNDEF(&_56$$16);
	ZVAL_UNDEF(&_57$$16);
	ZVAL_UNDEF(&_58$$16);
	ZVAL_UNDEF(&_59$$16);
	ZVAL_UNDEF(&_61$$17);
	ZVAL_UNDEF(&_62$$17);
	ZVAL_UNDEF(&_70$$17);
	ZVAL_UNDEF(&_71$$17);
	ZVAL_UNDEF(&_72$$17);
	ZVAL_UNDEF(&_73$$17);
	ZVAL_UNDEF(&_75$$17);
	ZVAL_UNDEF(&_76$$17);
	ZVAL_UNDEF(&_84$$17);
	ZVAL_UNDEF(&_63$$18);
	ZVAL_UNDEF(&_64$$18);
	ZVAL_UNDEF(&_65$$18);
	ZVAL_UNDEF(&_66$$20);
	ZVAL_UNDEF(&_67$$20);
	ZVAL_UNDEF(&_68$$20);
	ZVAL_UNDEF(&_69$$20);
	ZVAL_UNDEF(&_77$$23);
	ZVAL_UNDEF(&_78$$23);
	ZVAL_UNDEF(&_79$$23);
	ZVAL_UNDEF(&_80$$23);
	ZVAL_UNDEF(&_81$$24);
	ZVAL_UNDEF(&_82$$24);
	ZVAL_UNDEF(&_83$$24);
	ZVAL_UNDEF(&exception$$25);
	ZVAL_UNDEF(&_88$$25);
	ZVAL_UNDEF(&k$$25);
	ZVAL_UNDEF(&v$$25);
	ZVAL_UNDEF(&_89$$25);
	ZVAL_UNDEF(&_91$$25);
	ZVAL_UNDEF(&_85$$26);
	ZVAL_UNDEF(&_86$$26);
	ZVAL_UNDEF(&_87$$26);
	ZVAL_UNDEF(&_94$$28);
	ZVAL_UNDEF(&_95$$28);
	ZVAL_UNDEF(&_96$$28);
	ZVAL_UNDEF(&_97$$28);
	ZVAL_UNDEF(&_98$$28);
	ZVAL_UNDEF(&_99$$28);
	ZVAL_UNDEF(&_100$$28);
	ZVAL_UNDEF(&_101$$28);
	ZVAL_UNDEF(&_102$$29);
	ZVAL_UNDEF(&_103$$29);
	ZVAL_UNDEF(&_104$$29);
	ZVAL_UNDEF(&_105$$29);
	ZVAL_UNDEF(&_106$$29);
	ZVAL_UNDEF(&_107$$29);
	ZVAL_UNDEF(&_108$$29);
	ZVAL_UNDEF(&_109$$29);
	ZVAL_UNDEF(&_111$$30);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&e);
	zephir_read_property(&e, this_ptr, ZEND_STRL("exception"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&stack, &e, "gettrace", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dump, this_ptr, "getdumper", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&li);
	ZVAL_STRING(&li, "");
	do {
		zephir_array_unset_long(&stack, 0, PH_SEPARATE);
		zephir_is_iterable(&stack, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 616);
		if (Z_TYPE_P(&stack) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&stack), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key$$3);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key$$3, _3$$3);
				} else {
					ZVAL_LONG(&key$$3, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&row$$3);
				ZVAL_COPY(&row$$3, _0$$3);
				zephir_concat_self_str(&li, SL("<li><p>"));
				_4$$4 = zephir_array_isset_string(&row$$3, SL("file"));
				if (_4$$4) {
					zephir_array_fetch_string(&_5$$4, &row$$3, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 571);
					ZEPHIR_CALL_FUNCTION(&_6$$4, "is_file", &_7, 73, &_5$$4);
					zephir_check_call_status();
					_4$$4 = zephir_is_true(&_6$$4);
				}
				if (_4$$4) {
					zephir_array_fetch_string(&_8$$5, &row$$3, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 572);
					zephir_array_fetch_string(&_9$$5, &row$$3, SL("line"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 572);
					ZEPHIR_INIT_NVAR(&_10$$5);
					ZEPHIR_CONCAT_VSV(&_10$$5, &_8$$5, ":", &_9$$5);
					zephir_concat_self(&li, &_10$$5);
					zephir_concat_self_str(&li, SL("<a data-moon-ref=\"^p + .file\" class=\"moon-toggle moon-collapsed\">source</a>&nbsp;"));
				}
				if (zephir_array_isset_string(&row$$3, SL("object"))) {
					zephir_concat_self_str(&li, SL("<a data-moon-ref=\"^p + .object\" class=\"moon-toggle moon-collapsed\">"));
				}
				if (zephir_array_isset_string(&row$$3, SL("class"))) {
					zephir_array_fetch_string(&_13$$7, &row$$3, SL("class"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 579);
					zephir_array_fetch_string(&_14$$7, &row$$3, SL("type"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 579);
					ZEPHIR_INIT_NVAR(&_15$$7);
					ZEPHIR_CONCAT_VV(&_15$$7, &_13$$7, &_14$$7);
					ZEPHIR_CALL_CE_STATIC(&_11$$7, moon_component_errorhandler_helpers_ce, "escapehtml", &_12, 0, &_15$$7);
					zephir_check_call_status();
					zephir_concat_self(&li, &_11$$7);
				}
				if (zephir_array_isset_string(&row$$3, SL("object"))) {
					zephir_concat_self_str(&li, SL("</a>"));
				}
				zephir_array_fetch_string(&_17$$4, &row$$3, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 584);
				ZEPHIR_CALL_CE_STATIC(&_16$$4, moon_component_errorhandler_helpers_ce, "escapehtml", &_12, 0, &_17$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$4);
				ZEPHIR_CONCAT_VS(&_18$$4, &_16$$4, "(");
				zephir_concat_self(&li, &_18$$4);
				ZEPHIR_OBS_NVAR(&_19$$4);
				zephir_array_fetch_string(&_19$$4, &row$$3, SL("args"), PH_NOISY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 585);
				if (!(ZEPHIR_IS_EMPTY(&_19$$4))) {
					zephir_concat_self_str(&li, SL("<a data-moon-ref=\"^p + .args\" class=\"moon-toggle moon-collapsed\">arguments</a>"));
				}
				zephir_concat_self_str(&li, SL(")</p>"));
				_20$$4 = zephir_array_isset_string(&row$$3, SL("file"));
				if (_20$$4) {
					zephir_array_fetch_string(&_21$$4, &row$$3, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 589);
					ZEPHIR_CALL_FUNCTION(&_22$$4, "is_file", &_7, 73, &_21$$4);
					zephir_check_call_status();
					_20$$4 = zephir_is_true(&_22$$4);
				}
				if (_20$$4) {
					zephir_array_fetch_string(&_24$$10, &row$$3, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 590);
					zephir_array_fetch_string(&_25$$10, &row$$3, SL("line"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 590);
					ZEPHIR_CALL_METHOD(&_23$$10, this_ptr, "highlightfile", &_26, 0, &_24$$10, &_25$$10);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_27$$10);
					ZEPHIR_CONCAT_SVS(&_27$$10, "<div class=\"file  moon-collapsed\">", &_23$$10, "</div>");
					zephir_concat_self(&li, &_27$$10);
				}
				if (zephir_array_isset_string(&row$$3, SL("object"))) {
					zephir_array_fetch_string(&_28$$11, &row$$3, SL("object"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 593);
					ZEPHIR_CALL_ZVAL_FUNCTION(&_29$$11, &dump, NULL, 0, &_28$$11);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_30$$11);
					ZEPHIR_CONCAT_SVS(&_30$$11, "<div class=\"moon-collapsed outer object\">", &_29$$11, "</div>");
					zephir_concat_self(&li, &_30$$11);
				}
				ZEPHIR_OBS_NVAR(&_31$$4);
				zephir_array_fetch_string(&_31$$4, &row$$3, SL("args"), PH_NOISY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 595);
				if (!(ZEPHIR_IS_EMPTY(&_31$$4))) {
					zephir_concat_self_str(&li, SL("<div class=\"moon-collapsed outer args\"><table>"));

					/* try_start_1: */

						if (zephir_array_isset_string(&row$$3, SL("class"))) {
							ZEPHIR_INIT_NVAR(&r);
							object_init_ex(&r, zephir_get_internal_ce(SL("reflectionmethod")));
							zephir_array_fetch_string(&_32$$13, &row$$3, SL("class"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 599);
							zephir_array_fetch_string(&_33$$13, &row$$3, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 599);
							ZEPHIR_CALL_METHOD(NULL, &r, "__construct", &_34, 31, &_32$$13, &_33$$13);
							zephir_check_call_status_or_jump(try_end_1);
						} else {
							ZEPHIR_INIT_NVAR(&r);
							object_init_ex(&r, zephir_get_internal_ce(SL("reflectionfunction")));
							zephir_array_fetch_string(&_35$$13, &row$$3, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 599);
							ZEPHIR_CALL_METHOD(NULL, &r, "__construct", &_36, 26, &_35$$13);
							zephir_check_call_status_or_jump(try_end_1);
						}
						ZEPHIR_CALL_METHOD(&params, &r, "getparameters", &_37, 27);
						zephir_check_call_status_or_jump(try_end_1);

					try_end_1:

					if (EG(exception)) {
						ZEPHIR_INIT_NVAR(&_38$$12);
						ZVAL_OBJ(&_38$$12, EG(exception));
						Z_ADDREF_P(&_38$$12);
						if (zephir_instance_of_ev(&_38$$12, zend_exception_get_default(TSRMLS_C))) {
							zend_clear_exception(TSRMLS_C);
							ZEPHIR_CPY_WRT(&exception$$12, &_38$$12);
							ZEPHIR_INIT_NVAR(&params);
							array_init(&params);
						}
					}
					zephir_array_fetch_string(&_39$$12, &row$$3, SL("args"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 606);
					zephir_is_iterable(&_39$$12, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 611);
					if (Z_TYPE_P(&_39$$12) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_39$$12), _42$$12, _43$$12, _40$$12)
						{
							ZEPHIR_INIT_NVAR(&k$$12);
							if (_43$$12 != NULL) { 
								ZVAL_STR_COPY(&k$$12, _43$$12);
							} else {
								ZVAL_LONG(&k$$12, _42$$12);
							}
							ZEPHIR_INIT_NVAR(&v$$12);
							ZVAL_COPY(&v$$12, _40$$12);
							ZEPHIR_INIT_NVAR(&_45$$15);
							if (zephir_array_isset(&params, &k$$12)) {
								zephir_array_fetch(&_46$$15, &params, &k$$12, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 607);
								ZEPHIR_CALL_METHOD(&_47$$15, &_46$$15, "getname", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_45$$15);
								ZEPHIR_CONCAT_SV(&_45$$15, "$", &_47$$15);
							} else {
								ZEPHIR_INIT_NVAR(&_45$$15);
								ZVAL_STRING(&_45$$15, "#{k}");
							}
							ZEPHIR_CALL_CE_STATIC(&_44$$15, moon_component_errorhandler_helpers_ce, "escapehtml", &_12, 0, &_45$$15);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_48$$15);
							ZEPHIR_CONCAT_SVS(&_48$$15, "<tr><th>", &_44$$15, "</th><td>");
							zephir_concat_self(&li, &_48$$15);
							ZEPHIR_INIT_NVAR(&_49$$15);
							if (zephir_array_isset(&params, &k$$12)) {
								zephir_array_fetch(&_50$$15, &params, &k$$12, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 608);
								ZEPHIR_CALL_METHOD(&_49$$15, &_50$$15, "getname", NULL, 0);
								zephir_check_call_status();
							} else {
								ZEPHIR_INIT_NVAR(&_49$$15);
								ZVAL_NULL(&_49$$15);
							}
							ZEPHIR_CALL_ZVAL_FUNCTION(&_51$$15, &dump, NULL, 0, &v$$12, &_49$$15);
							zephir_check_call_status();
							zephir_concat_self(&li, &_51$$15);
							zephir_concat_self_str(&li, SL("</td></tr>\n"));
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_39$$12, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_41$$12, &_39$$12, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_41$$12)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&k$$12, &_39$$12, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&v$$12, &_39$$12, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_53$$16);
								if (zephir_array_isset(&params, &k$$12)) {
									zephir_array_fetch(&_54$$16, &params, &k$$12, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 607);
									ZEPHIR_CALL_METHOD(&_55$$16, &_54$$16, "getname", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_53$$16);
									ZEPHIR_CONCAT_SV(&_53$$16, "$", &_55$$16);
								} else {
									ZEPHIR_INIT_NVAR(&_53$$16);
									ZVAL_STRING(&_53$$16, "#{k}");
								}
								ZEPHIR_CALL_CE_STATIC(&_52$$16, moon_component_errorhandler_helpers_ce, "escapehtml", &_12, 0, &_53$$16);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_56$$16);
								ZEPHIR_CONCAT_SVS(&_56$$16, "<tr><th>", &_52$$16, "</th><td>");
								zephir_concat_self(&li, &_56$$16);
								ZEPHIR_INIT_NVAR(&_57$$16);
								if (zephir_array_isset(&params, &k$$12)) {
									zephir_array_fetch(&_58$$16, &params, &k$$12, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 608);
									ZEPHIR_CALL_METHOD(&_57$$16, &_58$$16, "getname", NULL, 0);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&_57$$16);
									ZVAL_NULL(&_57$$16);
								}
								ZEPHIR_CALL_ZVAL_FUNCTION(&_59$$16, &dump, NULL, 0, &v$$12, &_57$$16);
								zephir_check_call_status();
								zephir_concat_self(&li, &_59$$16);
								zephir_concat_self_str(&li, SL("</td></tr>\n"));
							ZEPHIR_CALL_METHOD(NULL, &_39$$12, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&v$$12);
					ZEPHIR_INIT_NVAR(&k$$12);
					zephir_concat_self_str(&li, SL("</table></div>"));
				}
				zephir_concat_self_str(&li, SL("</li>"));
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &stack, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &stack, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key$$3, &stack, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&row$$3, &stack, "current", NULL, 0);
				zephir_check_call_status();
					zephir_concat_self_str(&li, SL("<li><p>"));
					_60$$17 = zephir_array_isset_string(&row$$3, SL("file"));
					if (_60$$17) {
						zephir_array_fetch_string(&_61$$17, &row$$3, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 571);
						ZEPHIR_CALL_FUNCTION(&_62$$17, "is_file", &_7, 73, &_61$$17);
						zephir_check_call_status();
						_60$$17 = zephir_is_true(&_62$$17);
					}
					if (_60$$17) {
						zephir_array_fetch_string(&_63$$18, &row$$3, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 572);
						zephir_array_fetch_string(&_64$$18, &row$$3, SL("line"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 572);
						ZEPHIR_INIT_NVAR(&_65$$18);
						ZEPHIR_CONCAT_VSV(&_65$$18, &_63$$18, ":", &_64$$18);
						zephir_concat_self(&li, &_65$$18);
						zephir_concat_self_str(&li, SL("<a data-moon-ref=\"^p + .file\" class=\"moon-toggle moon-collapsed\">source</a>&nbsp;"));
					}
					if (zephir_array_isset_string(&row$$3, SL("object"))) {
						zephir_concat_self_str(&li, SL("<a data-moon-ref=\"^p + .object\" class=\"moon-toggle moon-collapsed\">"));
					}
					if (zephir_array_isset_string(&row$$3, SL("class"))) {
						zephir_array_fetch_string(&_67$$20, &row$$3, SL("class"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 579);
						zephir_array_fetch_string(&_68$$20, &row$$3, SL("type"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 579);
						ZEPHIR_INIT_NVAR(&_69$$20);
						ZEPHIR_CONCAT_VV(&_69$$20, &_67$$20, &_68$$20);
						ZEPHIR_CALL_CE_STATIC(&_66$$20, moon_component_errorhandler_helpers_ce, "escapehtml", &_12, 0, &_69$$20);
						zephir_check_call_status();
						zephir_concat_self(&li, &_66$$20);
					}
					if (zephir_array_isset_string(&row$$3, SL("object"))) {
						zephir_concat_self_str(&li, SL("</a>"));
					}
					zephir_array_fetch_string(&_71$$17, &row$$3, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 584);
					ZEPHIR_CALL_CE_STATIC(&_70$$17, moon_component_errorhandler_helpers_ce, "escapehtml", &_12, 0, &_71$$17);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_72$$17);
					ZEPHIR_CONCAT_VS(&_72$$17, &_70$$17, "(");
					zephir_concat_self(&li, &_72$$17);
					ZEPHIR_OBS_NVAR(&_73$$17);
					zephir_array_fetch_string(&_73$$17, &row$$3, SL("args"), PH_NOISY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 585);
					if (!(ZEPHIR_IS_EMPTY(&_73$$17))) {
						zephir_concat_self_str(&li, SL("<a data-moon-ref=\"^p + .args\" class=\"moon-toggle moon-collapsed\">arguments</a>"));
					}
					zephir_concat_self_str(&li, SL(")</p>"));
					_74$$17 = zephir_array_isset_string(&row$$3, SL("file"));
					if (_74$$17) {
						zephir_array_fetch_string(&_75$$17, &row$$3, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 589);
						ZEPHIR_CALL_FUNCTION(&_76$$17, "is_file", &_7, 73, &_75$$17);
						zephir_check_call_status();
						_74$$17 = zephir_is_true(&_76$$17);
					}
					if (_74$$17) {
						zephir_array_fetch_string(&_78$$23, &row$$3, SL("file"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 590);
						zephir_array_fetch_string(&_79$$23, &row$$3, SL("line"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 590);
						ZEPHIR_CALL_METHOD(&_77$$23, this_ptr, "highlightfile", &_26, 0, &_78$$23, &_79$$23);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_80$$23);
						ZEPHIR_CONCAT_SVS(&_80$$23, "<div class=\"file  moon-collapsed\">", &_77$$23, "</div>");
						zephir_concat_self(&li, &_80$$23);
					}
					if (zephir_array_isset_string(&row$$3, SL("object"))) {
						zephir_array_fetch_string(&_81$$24, &row$$3, SL("object"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 593);
						ZEPHIR_CALL_ZVAL_FUNCTION(&_82$$24, &dump, NULL, 0, &_81$$24);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_83$$24);
						ZEPHIR_CONCAT_SVS(&_83$$24, "<div class=\"moon-collapsed outer object\">", &_82$$24, "</div>");
						zephir_concat_self(&li, &_83$$24);
					}
					ZEPHIR_OBS_NVAR(&_84$$17);
					zephir_array_fetch_string(&_84$$17, &row$$3, SL("args"), PH_NOISY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 595);
					if (!(ZEPHIR_IS_EMPTY(&_84$$17))) {
						zephir_concat_self_str(&li, SL("<div class=\"moon-collapsed outer args\"><table>"));

						/* try_start_2: */

							if (zephir_array_isset_string(&row$$3, SL("class"))) {
								ZEPHIR_INIT_NVAR(&r);
								object_init_ex(&r, zephir_get_internal_ce(SL("reflectionmethod")));
								zephir_array_fetch_string(&_85$$26, &row$$3, SL("class"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 599);
								zephir_array_fetch_string(&_86$$26, &row$$3, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 599);
								ZEPHIR_CALL_METHOD(NULL, &r, "__construct", &_36, 26, &_85$$26, &_86$$26);
								zephir_check_call_status_or_jump(try_end_2);
							} else {
								ZEPHIR_INIT_NVAR(&r);
								object_init_ex(&r, zephir_get_internal_ce(SL("reflectionfunction")));
								zephir_array_fetch_string(&_87$$26, &row$$3, SL("function"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 599);
								ZEPHIR_CALL_METHOD(NULL, &r, "__construct", &_36, 26, &_87$$26);
								zephir_check_call_status_or_jump(try_end_2);
							}
							ZEPHIR_CALL_METHOD(&params, &r, "getparameters", &_37, 27);
							zephir_check_call_status_or_jump(try_end_2);

						try_end_2:

						if (EG(exception)) {
							ZEPHIR_INIT_NVAR(&_88$$25);
							ZVAL_OBJ(&_88$$25, EG(exception));
							Z_ADDREF_P(&_88$$25);
							if (zephir_instance_of_ev(&_88$$25, zend_exception_get_default(TSRMLS_C))) {
								zend_clear_exception(TSRMLS_C);
								ZEPHIR_CPY_WRT(&exception$$25, &_88$$25);
								ZEPHIR_INIT_NVAR(&params);
								array_init(&params);
							}
						}
						zephir_array_fetch_string(&_89$$25, &row$$3, SL("args"), PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 606);
						zephir_is_iterable(&_89$$25, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 611);
						if (Z_TYPE_P(&_89$$25) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_89$$25), _92$$25, _93$$25, _90$$25)
							{
								ZEPHIR_INIT_NVAR(&k$$25);
								if (_93$$25 != NULL) { 
									ZVAL_STR_COPY(&k$$25, _93$$25);
								} else {
									ZVAL_LONG(&k$$25, _92$$25);
								}
								ZEPHIR_INIT_NVAR(&v$$25);
								ZVAL_COPY(&v$$25, _90$$25);
								ZEPHIR_INIT_NVAR(&_95$$28);
								if (zephir_array_isset(&params, &k$$25)) {
									zephir_array_fetch(&_96$$28, &params, &k$$25, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 607);
									ZEPHIR_CALL_METHOD(&_97$$28, &_96$$28, "getname", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_95$$28);
									ZEPHIR_CONCAT_SV(&_95$$28, "$", &_97$$28);
								} else {
									ZEPHIR_INIT_NVAR(&_95$$28);
									ZVAL_STRING(&_95$$28, "#{k}");
								}
								ZEPHIR_CALL_CE_STATIC(&_94$$28, moon_component_errorhandler_helpers_ce, "escapehtml", &_12, 0, &_95$$28);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_98$$28);
								ZEPHIR_CONCAT_SVS(&_98$$28, "<tr><th>", &_94$$28, "</th><td>");
								zephir_concat_self(&li, &_98$$28);
								ZEPHIR_INIT_NVAR(&_99$$28);
								if (zephir_array_isset(&params, &k$$25)) {
									zephir_array_fetch(&_100$$28, &params, &k$$25, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 608);
									ZEPHIR_CALL_METHOD(&_99$$28, &_100$$28, "getname", NULL, 0);
									zephir_check_call_status();
								} else {
									ZEPHIR_INIT_NVAR(&_99$$28);
									ZVAL_NULL(&_99$$28);
								}
								ZEPHIR_CALL_ZVAL_FUNCTION(&_101$$28, &dump, NULL, 0, &v$$25, &_99$$28);
								zephir_check_call_status();
								zephir_concat_self(&li, &_101$$28);
								zephir_concat_self_str(&li, SL("</td></tr>\n"));
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_89$$25, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_91$$25, &_89$$25, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_91$$25)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&k$$25, &_89$$25, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&v$$25, &_89$$25, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_103$$29);
									if (zephir_array_isset(&params, &k$$25)) {
										zephir_array_fetch(&_104$$29, &params, &k$$25, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 607);
										ZEPHIR_CALL_METHOD(&_105$$29, &_104$$29, "getname", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_103$$29);
										ZEPHIR_CONCAT_SV(&_103$$29, "$", &_105$$29);
									} else {
										ZEPHIR_INIT_NVAR(&_103$$29);
										ZVAL_STRING(&_103$$29, "#{k}");
									}
									ZEPHIR_CALL_CE_STATIC(&_102$$29, moon_component_errorhandler_helpers_ce, "escapehtml", &_12, 0, &_103$$29);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_106$$29);
									ZEPHIR_CONCAT_SVS(&_106$$29, "<tr><th>", &_102$$29, "</th><td>");
									zephir_concat_self(&li, &_106$$29);
									ZEPHIR_INIT_NVAR(&_107$$29);
									if (zephir_array_isset(&params, &k$$25)) {
										zephir_array_fetch(&_108$$29, &params, &k$$25, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 608);
										ZEPHIR_CALL_METHOD(&_107$$29, &_108$$29, "getname", NULL, 0);
										zephir_check_call_status();
									} else {
										ZEPHIR_INIT_NVAR(&_107$$29);
										ZVAL_NULL(&_107$$29);
									}
									ZEPHIR_CALL_ZVAL_FUNCTION(&_109$$29, &dump, NULL, 0, &v$$25, &_107$$29);
									zephir_check_call_status();
									zephir_concat_self(&li, &_109$$29);
									zephir_concat_self_str(&li, SL("</td></tr>\n"));
								ZEPHIR_CALL_METHOD(NULL, &_89$$25, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&v$$25);
						ZEPHIR_INIT_NVAR(&k$$25);
						zephir_concat_self_str(&li, SL("</table></div>"));
					}
					zephir_concat_self_str(&li, SL("</li>"));
				ZEPHIR_CALL_METHOD(NULL, &stack, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&row$$3);
		ZEPHIR_INIT_NVAR(&key$$3);
		ZEPHIR_CALL_METHOD(&_110$$3, &e, "getprevious", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&_110$$3))) {
			ZEPHIR_CALL_METHOD(&_111$$30, &e, "getprevious", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&e, &_111$$30);
			ZEPHIR_CALL_METHOD(&stack, &e, "gettrace", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&stack);
			ZVAL_NULL(&stack);
		}
	} while (zephir_is_true(&stack));
	ZEPHIR_CONCAT_SVS(return_value, " <div class=\"panel\"> <h2><a data-moon-ref=\"^+\" class=\"moon-toggle\">Call stack</a></h2> <div class=\"inner\"> <ol> ", &li, " </ol> </div> </div> ");
	RETURN_MM();

}

/**
 * 支持扩展展示的 PANEL 信息
 * @return string
 */
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getPanelList) {

	zend_string *_19$$5, *_35$$8, *_57$$12, *_72$$15;
	zend_ulong _18$$5, _34$$8, _56$$12, _71$$15;
	zval html, dump, _0, item$$3, _1$$3, *_2$$3, _3$$3, _4$$4, _6$$4, table$$4, _7$$4, *_9$$4, _10$$4, _11$$5, _13$$5, k$$5, tc$$5, _14$$5, *_16$$5, _17$$5, _20$$6, _22$$6, _23$$6, _24$$7, _25$$7, _26$$7, _27$$8, _29$$8, k$$8, tc$$8, _30$$8, *_32$$8, _33$$8, _36$$9, _37$$9, _38$$9, _39$$10, _40$$10, _41$$10, _42$$11, _44$$11, table$$11, _45$$11, *_47$$11, _48$$11, _49$$12, _51$$12, k$$12, tc$$12, _52$$12, *_54$$12, _55$$12, _58$$13, _59$$13, _60$$13, _61$$14, _62$$14, _63$$14, _64$$15, _66$$15, k$$15, tc$$15, _67$$15, *_69$$15, _70$$15, _73$$16, _74$$16, _75$$16, _76$$17, _77$$17, _78$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_12 = NULL, *_15 = NULL, *_21 = NULL, *_28 = NULL, *_31 = NULL, *_43 = NULL, *_46 = NULL, *_50 = NULL, *_53 = NULL, *_65 = NULL, *_68 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&item$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&table$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&k$$5);
	ZVAL_UNDEF(&tc$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&k$$8);
	ZVAL_UNDEF(&tc$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_37$$9);
	ZVAL_UNDEF(&_38$$9);
	ZVAL_UNDEF(&_39$$10);
	ZVAL_UNDEF(&_40$$10);
	ZVAL_UNDEF(&_41$$10);
	ZVAL_UNDEF(&_42$$11);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&table$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&_49$$12);
	ZVAL_UNDEF(&_51$$12);
	ZVAL_UNDEF(&k$$12);
	ZVAL_UNDEF(&tc$$12);
	ZVAL_UNDEF(&_52$$12);
	ZVAL_UNDEF(&_55$$12);
	ZVAL_UNDEF(&_58$$13);
	ZVAL_UNDEF(&_59$$13);
	ZVAL_UNDEF(&_60$$13);
	ZVAL_UNDEF(&_61$$14);
	ZVAL_UNDEF(&_62$$14);
	ZVAL_UNDEF(&_63$$14);
	ZVAL_UNDEF(&_64$$15);
	ZVAL_UNDEF(&_66$$15);
	ZVAL_UNDEF(&k$$15);
	ZVAL_UNDEF(&tc$$15);
	ZVAL_UNDEF(&_67$$15);
	ZVAL_UNDEF(&_70$$15);
	ZVAL_UNDEF(&_73$$16);
	ZVAL_UNDEF(&_74$$16);
	ZVAL_UNDEF(&_75$$16);
	ZVAL_UNDEF(&_76$$17);
	ZVAL_UNDEF(&_77$$17);
	ZVAL_UNDEF(&_78$$17);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("panel"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_CALL_METHOD(&dump, this_ptr, "getdumper", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&html);
		ZVAL_STRING(&html, "");
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("panel"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 660);
		if (Z_TYPE_P(&_1$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
			{
				ZEPHIR_INIT_NVAR(&item$$3);
				ZVAL_COPY(&item$$3, _2$$3);
				ZEPHIR_CALL_METHOD(&_4$$4, &item$$3, "gettitle", &_5, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZEPHIR_CONCAT_SVS(&_6$$4, "<div class=\"panel\"><h2><a data-moon-ref=\"^+\" class=\"moon-toggle moon-collapsed\">", &_4$$4, "</a></h2>");
				zephir_concat_self(&html, &_6$$4);
				zephir_concat_self_str(&html, SL("<div class=\"moon-collapsed inner\">"));
				ZEPHIR_CALL_METHOD(&_7$$4, &item$$3, "getcontent", &_8, 0);
				zephir_check_call_status();
				zephir_is_iterable(&_7$$4, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 658);
				if (Z_TYPE_P(&_7$$4) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_7$$4), _9$$4)
					{
						ZEPHIR_INIT_NVAR(&table$$4);
						ZVAL_COPY(&table$$4, _9$$4);
						ZEPHIR_CALL_METHOD(&_11$$5, &table$$4, "gettitle", &_12, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_13$$5);
						ZEPHIR_CONCAT_SVS(&_13$$5, "<h3><a data-moon-ref=\"^+\" class=\"moon-toggle\">", &_11$$5, "</a></h3><div class=\"outer\"><table class=\"moon-sortable\">");
						zephir_concat_self(&html, &_13$$5);
						ZEPHIR_CALL_METHOD(&_14$$5, &table$$4, "getcontent", &_15, 0);
						zephir_check_call_status();
						zephir_is_iterable(&_14$$5, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 656);
						if (Z_TYPE_P(&_14$$5) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_14$$5), _18$$5, _19$$5, _16$$5)
							{
								ZEPHIR_INIT_NVAR(&k$$5);
								if (_19$$5 != NULL) { 
									ZVAL_STR_COPY(&k$$5, _19$$5);
								} else {
									ZVAL_LONG(&k$$5, _18$$5);
								}
								ZEPHIR_INIT_NVAR(&tc$$5);
								ZVAL_COPY(&tc$$5, _16$$5);
								ZEPHIR_CALL_CE_STATIC(&_20$$6, moon_component_errorhandler_helpers_ce, "escapehtml", &_21, 0, &k$$5);
								zephir_check_call_status();
								ZEPHIR_CALL_ZVAL_FUNCTION(&_22$$6, &dump, NULL, 0, &tc$$5);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_23$$6);
								ZEPHIR_CONCAT_SVSVS(&_23$$6, "<tr><th>", &_20$$6, "</th><td>", &_22$$6, "</td></tr>\n");
								zephir_concat_self(&html, &_23$$6);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_14$$5, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_17$$5, &_14$$5, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_17$$5)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&k$$5, &_14$$5, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&tc$$5, &_14$$5, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_CE_STATIC(&_24$$7, moon_component_errorhandler_helpers_ce, "escapehtml", &_21, 0, &k$$5);
									zephir_check_call_status();
									ZEPHIR_CALL_ZVAL_FUNCTION(&_25$$7, &dump, NULL, 0, &tc$$5);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_26$$7);
									ZEPHIR_CONCAT_SVSVS(&_26$$7, "<tr><th>", &_24$$7, "</th><td>", &_25$$7, "</td></tr>\n");
									zephir_concat_self(&html, &_26$$7);
								ZEPHIR_CALL_METHOD(NULL, &_14$$5, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&tc$$5);
						ZEPHIR_INIT_NVAR(&k$$5);
						zephir_concat_self_str(&html, SL("</table></div>"));
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_7$$4, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_10$$4, &_7$$4, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_10$$4)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&table$$4, &_7$$4, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_27$$8, &table$$4, "gettitle", &_28, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_29$$8);
							ZEPHIR_CONCAT_SVS(&_29$$8, "<h3><a data-moon-ref=\"^+\" class=\"moon-toggle\">", &_27$$8, "</a></h3><div class=\"outer\"><table class=\"moon-sortable\">");
							zephir_concat_self(&html, &_29$$8);
							ZEPHIR_CALL_METHOD(&_30$$8, &table$$4, "getcontent", &_31, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_30$$8, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 656);
							if (Z_TYPE_P(&_30$$8) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_30$$8), _34$$8, _35$$8, _32$$8)
								{
									ZEPHIR_INIT_NVAR(&k$$8);
									if (_35$$8 != NULL) { 
										ZVAL_STR_COPY(&k$$8, _35$$8);
									} else {
										ZVAL_LONG(&k$$8, _34$$8);
									}
									ZEPHIR_INIT_NVAR(&tc$$8);
									ZVAL_COPY(&tc$$8, _32$$8);
									ZEPHIR_CALL_CE_STATIC(&_36$$9, moon_component_errorhandler_helpers_ce, "escapehtml", &_21, 0, &k$$8);
									zephir_check_call_status();
									ZEPHIR_CALL_ZVAL_FUNCTION(&_37$$9, &dump, NULL, 0, &tc$$8);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_38$$9);
									ZEPHIR_CONCAT_SVSVS(&_38$$9, "<tr><th>", &_36$$9, "</th><td>", &_37$$9, "</td></tr>\n");
									zephir_concat_self(&html, &_38$$9);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_30$$8, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_33$$8, &_30$$8, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_33$$8)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&k$$8, &_30$$8, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&tc$$8, &_30$$8, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_CE_STATIC(&_39$$10, moon_component_errorhandler_helpers_ce, "escapehtml", &_21, 0, &k$$8);
										zephir_check_call_status();
										ZEPHIR_CALL_ZVAL_FUNCTION(&_40$$10, &dump, NULL, 0, &tc$$8);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_41$$10);
										ZEPHIR_CONCAT_SVSVS(&_41$$10, "<tr><th>", &_39$$10, "</th><td>", &_40$$10, "</td></tr>\n");
										zephir_concat_self(&html, &_41$$10);
									ZEPHIR_CALL_METHOD(NULL, &_30$$8, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&tc$$8);
							ZEPHIR_INIT_NVAR(&k$$8);
							zephir_concat_self_str(&html, SL("</table></div>"));
						ZEPHIR_CALL_METHOD(NULL, &_7$$4, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&table$$4);
				zephir_concat_self_str(&html, SL("</div></div>"));
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &_1$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&item$$3, &_1$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_42$$11, &item$$3, "gettitle", &_43, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_44$$11);
					ZEPHIR_CONCAT_SVS(&_44$$11, "<div class=\"panel\"><h2><a data-moon-ref=\"^+\" class=\"moon-toggle moon-collapsed\">", &_42$$11, "</a></h2>");
					zephir_concat_self(&html, &_44$$11);
					zephir_concat_self_str(&html, SL("<div class=\"moon-collapsed inner\">"));
					ZEPHIR_CALL_METHOD(&_45$$11, &item$$3, "getcontent", &_46, 0);
					zephir_check_call_status();
					zephir_is_iterable(&_45$$11, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 658);
					if (Z_TYPE_P(&_45$$11) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_45$$11), _47$$11)
						{
							ZEPHIR_INIT_NVAR(&table$$11);
							ZVAL_COPY(&table$$11, _47$$11);
							ZEPHIR_CALL_METHOD(&_49$$12, &table$$11, "gettitle", &_50, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_51$$12);
							ZEPHIR_CONCAT_SVS(&_51$$12, "<h3><a data-moon-ref=\"^+\" class=\"moon-toggle\">", &_49$$12, "</a></h3><div class=\"outer\"><table class=\"moon-sortable\">");
							zephir_concat_self(&html, &_51$$12);
							ZEPHIR_CALL_METHOD(&_52$$12, &table$$11, "getcontent", &_53, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_52$$12, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 656);
							if (Z_TYPE_P(&_52$$12) == IS_ARRAY) {
								ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_52$$12), _56$$12, _57$$12, _54$$12)
								{
									ZEPHIR_INIT_NVAR(&k$$12);
									if (_57$$12 != NULL) { 
										ZVAL_STR_COPY(&k$$12, _57$$12);
									} else {
										ZVAL_LONG(&k$$12, _56$$12);
									}
									ZEPHIR_INIT_NVAR(&tc$$12);
									ZVAL_COPY(&tc$$12, _54$$12);
									ZEPHIR_CALL_CE_STATIC(&_58$$13, moon_component_errorhandler_helpers_ce, "escapehtml", &_21, 0, &k$$12);
									zephir_check_call_status();
									ZEPHIR_CALL_ZVAL_FUNCTION(&_59$$13, &dump, NULL, 0, &tc$$12);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_60$$13);
									ZEPHIR_CONCAT_SVSVS(&_60$$13, "<tr><th>", &_58$$13, "</th><td>", &_59$$13, "</td></tr>\n");
									zephir_concat_self(&html, &_60$$13);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_52$$12, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_55$$12, &_52$$12, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_55$$12)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&k$$12, &_52$$12, "key", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&tc$$12, &_52$$12, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_CE_STATIC(&_61$$14, moon_component_errorhandler_helpers_ce, "escapehtml", &_21, 0, &k$$12);
										zephir_check_call_status();
										ZEPHIR_CALL_ZVAL_FUNCTION(&_62$$14, &dump, NULL, 0, &tc$$12);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_63$$14);
										ZEPHIR_CONCAT_SVSVS(&_63$$14, "<tr><th>", &_61$$14, "</th><td>", &_62$$14, "</td></tr>\n");
										zephir_concat_self(&html, &_63$$14);
									ZEPHIR_CALL_METHOD(NULL, &_52$$12, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&tc$$12);
							ZEPHIR_INIT_NVAR(&k$$12);
							zephir_concat_self_str(&html, SL("</table></div>"));
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_45$$11, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_48$$11, &_45$$11, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_48$$11)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&table$$11, &_45$$11, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&_64$$15, &table$$11, "gettitle", &_65, 0);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_66$$15);
								ZEPHIR_CONCAT_SVS(&_66$$15, "<h3><a data-moon-ref=\"^+\" class=\"moon-toggle\">", &_64$$15, "</a></h3><div class=\"outer\"><table class=\"moon-sortable\">");
								zephir_concat_self(&html, &_66$$15);
								ZEPHIR_CALL_METHOD(&_67$$15, &table$$11, "getcontent", &_68, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_67$$15, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 656);
								if (Z_TYPE_P(&_67$$15) == IS_ARRAY) {
									ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_67$$15), _71$$15, _72$$15, _69$$15)
									{
										ZEPHIR_INIT_NVAR(&k$$15);
										if (_72$$15 != NULL) { 
											ZVAL_STR_COPY(&k$$15, _72$$15);
										} else {
											ZVAL_LONG(&k$$15, _71$$15);
										}
										ZEPHIR_INIT_NVAR(&tc$$15);
										ZVAL_COPY(&tc$$15, _69$$15);
										ZEPHIR_CALL_CE_STATIC(&_73$$16, moon_component_errorhandler_helpers_ce, "escapehtml", &_21, 0, &k$$15);
										zephir_check_call_status();
										ZEPHIR_CALL_ZVAL_FUNCTION(&_74$$16, &dump, NULL, 0, &tc$$15);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_75$$16);
										ZEPHIR_CONCAT_SVSVS(&_75$$16, "<tr><th>", &_73$$16, "</th><td>", &_74$$16, "</td></tr>\n");
										zephir_concat_self(&html, &_75$$16);
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_67$$15, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_70$$15, &_67$$15, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_70$$15)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&k$$15, &_67$$15, "key", NULL, 0);
										zephir_check_call_status();
										ZEPHIR_CALL_METHOD(&tc$$15, &_67$$15, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_CALL_CE_STATIC(&_76$$17, moon_component_errorhandler_helpers_ce, "escapehtml", &_21, 0, &k$$15);
											zephir_check_call_status();
											ZEPHIR_CALL_ZVAL_FUNCTION(&_77$$17, &dump, NULL, 0, &tc$$15);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_78$$17);
											ZEPHIR_CONCAT_SVSVS(&_78$$17, "<tr><th>", &_76$$17, "</th><td>", &_77$$17, "</td></tr>\n");
											zephir_concat_self(&html, &_78$$17);
										ZEPHIR_CALL_METHOD(NULL, &_67$$15, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&tc$$15);
								ZEPHIR_INIT_NVAR(&k$$15);
								zephir_concat_self_str(&html, SL("</table></div>"));
							ZEPHIR_CALL_METHOD(NULL, &_45$$11, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&table$$11);
					zephir_concat_self_str(&html, SL("</div></div>"));
				ZEPHIR_CALL_METHOD(NULL, &_1$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&item$$3);
		RETURN_CCTOR(&html);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getVariables) {

	zend_string *_7$$3;
	zend_ulong _6$$3;
	zend_bool _0, _1;
	zval table, dump, e, _2, k$$3, v$$3, _3$$3, *_4$$3, _5$$3, _8$$4, _10$$4, _11$$4, _12$$4, _13$$5, _14$$5, _15$$5, _16$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&k$$3);
	ZVAL_UNDEF(&v$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&e);
	zephir_read_property(&e, this_ptr, ZEND_STRL("exception"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&dump, this_ptr, "getdumper", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_instance_of_ev(&e, zephir_get_internal_ce(SL("errorexception")));
	if (_0) {
		_0 = zephir_isset_property(&e, SL("context"));
	}
	_1 = _0;
	if (_1) {
		zephir_read_property(&_2, &e, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
		_1 = Z_TYPE_P(&_2) == IS_ARRAY;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_STRING(&table, "<table class=\"moon-sortable\">");
		zephir_read_property(&_3$$3, &e, ZEND_STRL("context"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_3$$3, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 679);
		if (Z_TYPE_P(&_3$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3$$3), _6$$3, _7$$3, _4$$3)
			{
				ZEPHIR_INIT_NVAR(&k$$3);
				if (_7$$3 != NULL) { 
					ZVAL_STR_COPY(&k$$3, _7$$3);
				} else {
					ZVAL_LONG(&k$$3, _6$$3);
				}
				ZEPHIR_INIT_NVAR(&v$$3);
				ZVAL_COPY(&v$$3, _4$$3);
				ZEPHIR_CALL_CE_STATIC(&_8$$4, moon_component_errorhandler_helpers_ce, "escapehtml", &_9, 0, &k$$3);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$4);
				ZEPHIR_CONCAT_SVS(&_10$$4, "<tr><th>", &_8$$4, "</th><td>");
				zephir_concat_self(&table, &_10$$4);
				ZEPHIR_CALL_ZVAL_FUNCTION(&_11$$4, &dump, NULL, 0, &v$$3, &k$$3);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZEPHIR_CONCAT_VS(&_12$$4, &_11$$4, "</td></tr>\n");
				zephir_concat_self(&table, &_12$$4);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_3$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$3, &_3$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&k$$3, &_3$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&v$$3, &_3$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_13$$5, moon_component_errorhandler_helpers_ce, "escapehtml", &_9, 0, &k$$3);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_14$$5);
					ZEPHIR_CONCAT_SVS(&_14$$5, "<tr><th>", &_13$$5, "</th><td>");
					zephir_concat_self(&table, &_14$$5);
					ZEPHIR_CALL_ZVAL_FUNCTION(&_15$$5, &dump, NULL, 0, &v$$3, &k$$3);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_16$$5);
					ZEPHIR_CONCAT_VS(&_16$$5, &_15$$5, "</td></tr>\n");
					zephir_concat_self(&table, &_16$$5);
				ZEPHIR_CALL_METHOD(NULL, &_3$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&v$$3);
		ZEPHIR_INIT_NVAR(&k$$3);
		zephir_concat_self_str(&table, SL("</table>"));
		ZEPHIR_CONCAT_SVS(return_value, " <div class=\"panel\"> <h2><a data-moon-ref=\"^+\" class=\"moon-toggle moon-collapsed\">Variables</a></h2> <div class=\"moon-collapsed inner\"> <div class=\"outer\"> ", &table, " </div> </div> </div> ");
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Should a file be collapsed in stack trace?
 * @param string $file
 * @return bool
 */
PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, isCollapsed) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_14 = NULL;
	zval file, *file_param = NULL, _0, _1, _2, _4, path, _5, *_6, _7, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$3, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(&file, file_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", &_3, 128, &file, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &_2, "/");
	ZEPHIR_CPY_WRT(&file, &_4);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("collapsePaths"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_5, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 703);
	if (Z_TYPE_P(&_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
		{
			ZEPHIR_INIT_NVAR(&path);
			ZVAL_COPY(&path, _6);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "\\");
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZVAL_STRING(&_9$$3, "/");
			ZEPHIR_CALL_FUNCTION(&_10$$3, "strtr", &_3, 128, &path, &_8$$3, &_9$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_11$$3);
			ZEPHIR_CONCAT_VS(&_11$$3, &_10$$3, "/");
			ZEPHIR_CPY_WRT(&path, &_11$$3);
			ZVAL_LONG(&_12$$3, zephir_fast_strlen_ev(&path));
			ZEPHIR_CALL_FUNCTION(&_13$$3, "strncmp", &_14, 149, &file, &path, &_12$$3);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG_IDENTICAL(&_13$$3, 0)) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_5, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &_5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&path, &_5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$5);
				ZVAL_STRING(&_15$$5, "\\");
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZVAL_STRING(&_16$$5, "/");
				ZEPHIR_CALL_FUNCTION(&_17$$5, "strtr", &_3, 128, &path, &_15$$5, &_16$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$5);
				ZEPHIR_CONCAT_VS(&_18$$5, &_17$$5, "/");
				ZEPHIR_CPY_WRT(&path, &_18$$5);
				ZVAL_LONG(&_19$$5, zephir_fast_strlen_ev(&path));
				ZEPHIR_CALL_FUNCTION(&_20$$5, "strncmp", &_14, 149, &file, &path, &_19$$5);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG_IDENTICAL(&_20$$5, 0)) {
					RETURN_MM_BOOL(1);
				}
			ZEPHIR_CALL_METHOD(NULL, &_5, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&path);
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, highlightFile) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval vars, keysToHide;
	zend_long line, lines, ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *line_param = NULL, *lines_param = NULL, *vars_param = NULL, *keysToHide_param = NULL, source, _0, _1$$3, _2$$3, _3$$3;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&keysToHide);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &file_param, &line_param, &lines_param, &vars_param, &keysToHide_param);

	zephir_get_strval(&file, file_param);
	line = zephir_get_intval(line_param);
	if (!lines_param) {
		lines = 15;
	} else {
		lines = zephir_get_intval(lines_param);
	}
	if (!vars_param) {
		ZEPHIR_INIT_VAR(&vars);
		array_init(&vars);
	} else {
		zephir_get_arrval(&vars, vars_param);
	}
	if (!keysToHide_param) {
		ZEPHIR_INIT_VAR(&keysToHide);
		array_init(&keysToHide);
	} else {
		zephir_get_arrval(&keysToHide, keysToHide_param);
	}


	ZEPHIR_INIT_VAR(&source);
	ZVAL_STRING(&source, "");
	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 73, &file);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_NVAR(&source);
		zephir_file_get_contents(&source, &file);
		ZVAL_LONG(&_2$$3, line);
		ZVAL_LONG(&_3$$3, lines);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "highlightphp", NULL, 0, &source, &_2$$3, &_3$$3, &vars, &keysToHide);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&source, &_1$$3);
	}
	RETURN_CCTOR(&source);

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, highlightPhp) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval vars, keysToHide, _4;
	zend_long line, lines, ZEPHIR_LAST_CALL_STATUS;
	zval source, *source_param = NULL, *line_param = NULL, *lines_param = NULL, *vars_param = NULL, *keysToHide_param = NULL, __$true, out, _3, _5, _6, _7, _8, _9, _10, _11, _15, _16, _17, _0$$3, _1$$3, _12$$4, _13$$4, _14$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&out);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&keysToHide);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &source_param, &line_param, &lines_param, &vars_param, &keysToHide_param);

	zephir_get_strval(&source, source_param);
	line = zephir_get_intval(line_param);
	if (!lines_param) {
		lines = 15;
	} else {
		lines = zephir_get_intval(lines_param);
	}
	if (!vars_param) {
		ZEPHIR_INIT_VAR(&vars);
		array_init(&vars);
	} else {
		zephir_get_arrval(&vars, vars_param);
	}
	if (!keysToHide_param) {
		ZEPHIR_INIT_VAR(&keysToHide);
		array_init(&keysToHide);
	} else {
		zephir_get_arrval(&keysToHide, keysToHide_param);
	}


	if ((zephir_function_exists_ex(ZEND_STRL("ini_set")) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "highlight.comment");
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#998; font-style: italic");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_2, 61, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "highlight.default");
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#000");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_2, 61, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "highlight.html");
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#06B");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_2, 61, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "highlight.keyword");
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#D24; font-weight: bold");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_2, 61, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "highlight.string");
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "#080");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_2, 61, &_0$$3, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "\r\n");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "\r");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "\n");
	zephir_fast_str_replace(&_3, &_4, &_5, &source);
	ZEPHIR_CPY_WRT(&source, &_3);
	ZEPHIR_CALL_FUNCTION(&_6, "highlight_string", NULL, 150, &source, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&source);
	zephir_fast_explode_str(&source, SL("\n"), &_6, LONG_MAX);
	ZEPHIR_OBS_VAR(&out);
	zephir_array_fetch_long(&out, &source, 0, PH_NOISY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 730);
	zephir_array_fetch_long(&_7, &source, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 732);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "<br />");
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "\n");
	ZEPHIR_INIT_NVAR(&source);
	zephir_fast_str_replace(&source, &_3, &_8, &_7);
	ZVAL_LONG(&_10, line);
	ZVAL_LONG(&_11, lines);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "highlightline", NULL, 0, &source, &_10, &_11);
	zephir_check_call_status();
	zephir_concat_self(&out, &_9);
	if (!(ZEPHIR_IS_EMPTY(&vars))) {
		ZEPHIR_INIT_VAR(&_12$$4);
		ZEPHIR_INIT_NVAR(&_12$$4);
		zephir_create_closure_ex(&_12$$4, NULL, moon_3__closure_ce, SL("__invoke"));
		zephir_update_static_property_ce(moon_3__closure_ce, ZEND_STRL("vars"), &vars);
		zephir_update_static_property_ce(moon_3__closure_ce, ZEND_STRL("keysToHide"), &keysToHide);
		ZEPHIR_INIT_VAR(&_13$$4);
		ZVAL_STRING(&_13$$4, "#\">\\$(\\w+)(&nbsp;)?</span>#");
		ZEPHIR_CALL_FUNCTION(&_14$$4, "preg_replace_callback", NULL, 109, &_13$$4, &_12$$4, &out);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&out, &_14$$4);
	}
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_INIT_VAR(&_16);
	ZVAL_STRING(&_16, "&nbsp;");
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, " ");
	zephir_fast_str_replace(&_15, &_16, &_17, &out);
	ZEPHIR_CPY_WRT(&out, &_15);
	ZEPHIR_CONCAT_SVS(return_value, "<pre class='code'><div>", &out, "</div></pre>");
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, highlightLine) {

	zval _27$$6, _29$$6, _44$$9, _46$$9;
	zend_string *_21;
	zend_ulong _20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_24 = NULL, *_33 = NULL, *_37 = NULL;
	zend_long line, lines, ZEPHIR_LAST_CALL_STATUS;
	zval *html_param = NULL, *line_param = NULL, *lines_param = NULL, __$true, numWidth, i, start, spans, out, source, _0, _1, _2, _3, _4, _5, _6, _7, _8, _16, n, s, tags, *_18, _19, _55, _56, _57, m$$3, _9$$3, _10$$3, _11$$3, _12$$3, _15$$3, _13$$4, _14$$5, _22$$6, _23$$6, _25$$6, _26$$6, _28$$6, _30$$6, _31$$7, _32$$7, _34$$7, _35$$7, _36$$7, _38$$8, _39$$8, _40$$9, _41$$9, _42$$9, _43$$9, _45$$9, _47$$9, _48$$10, _49$$10, _50$$10, _51$$10, _52$$10, _53$$11, _54$$11;
	zval html, _17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_17);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&numWidth);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&spans);
	ZVAL_UNDEF(&out);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&tags);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_56);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&m$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_30$$6);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_32$$7);
	ZVAL_UNDEF(&_34$$7);
	ZVAL_UNDEF(&_35$$7);
	ZVAL_UNDEF(&_36$$7);
	ZVAL_UNDEF(&_38$$8);
	ZVAL_UNDEF(&_39$$8);
	ZVAL_UNDEF(&_40$$9);
	ZVAL_UNDEF(&_41$$9);
	ZVAL_UNDEF(&_42$$9);
	ZVAL_UNDEF(&_43$$9);
	ZVAL_UNDEF(&_45$$9);
	ZVAL_UNDEF(&_47$$9);
	ZVAL_UNDEF(&_48$$10);
	ZVAL_UNDEF(&_49$$10);
	ZVAL_UNDEF(&_50$$10);
	ZVAL_UNDEF(&_51$$10);
	ZVAL_UNDEF(&_52$$10);
	ZVAL_UNDEF(&_53$$11);
	ZVAL_UNDEF(&_54$$11);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_44$$9);
	ZVAL_UNDEF(&_46$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &html_param, &line_param, &lines_param);

	zephir_get_strval(&html, html_param);
	line = zephir_get_intval(line_param);
	if (!lines_param) {
		lines = 15;
	} else {
		lines = zephir_get_intval(lines_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\r\n");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\n");
	zephir_fast_str_replace(&_0, &_1, &_2, &html);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "\n", &_0);
	ZEPHIR_INIT_VAR(&source);
	zephir_fast_explode_str(&source, SL("\n"), &_3, LONG_MAX);
	ZEPHIR_INIT_VAR(&out);
	ZVAL_STRING(&out, "");
	ZEPHIR_INIT_VAR(&spans);
	ZVAL_LONG(&spans, 1);
	ZVAL_LONG(&_4, line);
	ZVAL_LONG(&_5, (zephir_fast_count_int(&source) - 1));
	ZEPHIR_CALL_FUNCTION(&_6, "min", NULL, 151, &_4, &_5);
	zephir_check_call_status();
	ZVAL_DOUBLE(&_4, zephir_safe_div_long_long((lines * 2), 3));
	ZVAL_LONG(&_5, 1);
	ZVAL_LONG(&_7, (zephir_get_numberval(&_6) - (int) zephir_floor(&_4)));
	ZEPHIR_CALL_FUNCTION(&i, "max", NULL, 152, &_5, &_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&start, &i);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_LONG(&_8, 1);
	ZEPHIR_SUB_ASSIGN(&i, &_8);
	while (1) {
		if (!(ZEPHIR_GE_LONG(&i, 1))) {
			break;
		}
		zephir_array_fetch(&_9$$3, &source, &i, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 770);
		ZEPHIR_INIT_NVAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "#.*(</?span[^>]*>)#");
		ZEPHIR_INIT_NVAR(&_11$$3);
		ZEPHIR_INIT_NVAR(&_12$$3);
		ZVAL_STRING(&_12$$3, "#.*(</?span[^>]*>)#");
		zephir_preg_match(&_11$$3, &_12$$3, &_9$$3, &m$$3, 0, 0 , 0 );
		if (zephir_is_true(&_11$$3)) {
			zephir_array_fetch_long(&_13$$4, &m$$3, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 771);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_13$$4, "</span>")) {
				ZEPHIR_SEPARATE(&spans);
				zephir_increment(&spans);
				zephir_array_fetch_long(&_14$$5, &m$$3, 1, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 773);
				zephir_concat_self(&out, &_14$$5);
			}
			break;
		}
		ZEPHIR_INIT_NVAR(&_15$$3);
		ZVAL_LONG(&_15$$3, 1);
		ZEPHIR_SUB_ASSIGN(&i, &_15$$3);
	}
	ZVAL_LONG(&_5, lines);
	ZEPHIR_CALL_FUNCTION(&_16, "array_slice", NULL, 153, &source, &start, &_5, &__$true);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&source, &_16);
	ZEPHIR_MAKE_REF(&source);
	ZEPHIR_CALL_FUNCTION(NULL, "end", NULL, 154, &source);
	ZEPHIR_UNREF(&source);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_16, "key", NULL, 155, &source);
	zephir_check_call_status();
	zephir_get_strval(&_17, &_16);
	ZEPHIR_INIT_VAR(&numWidth);
	ZVAL_LONG(&numWidth, zephir_fast_strlen_ev(&_17));
	zephir_is_iterable(&source, 0, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 795);
	if (Z_TYPE_P(&source) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&source), _20, _21, _18)
		{
			ZEPHIR_INIT_NVAR(&n);
			if (_21 != NULL) { 
				ZVAL_STR_COPY(&n, _21);
			} else {
				ZVAL_LONG(&n, _20);
			}
			ZEPHIR_INIT_NVAR(&s);
			ZVAL_COPY(&s, _18);
			ZEPHIR_INIT_NVAR(&_22$$6);
			ZVAL_STRING(&_22$$6, "<span");
			ZEPHIR_CALL_FUNCTION(&_23$$6, "substr_count", &_24, 156, &s, &_22$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_22$$6);
			ZVAL_STRING(&_22$$6, "</span");
			ZEPHIR_CALL_FUNCTION(&_25$$6, "substr_count", &_24, 156, &s, &_22$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_26$$6);
			zephir_sub_function(&_26$$6, &_23$$6, &_25$$6);
			ZEPHIR_ADD_ASSIGN(&spans, &_26$$6);
			ZEPHIR_INIT_NVAR(&_22$$6);
			ZEPHIR_INIT_NVAR(&_27$$6);
			zephir_create_array(&_27$$6, 2, 0);
			ZEPHIR_INIT_NVAR(&_28$$6);
			ZVAL_STRING(&_28$$6, "\r");
			zephir_array_fast_append(&_27$$6, &_28$$6);
			ZEPHIR_INIT_NVAR(&_28$$6);
			ZVAL_STRING(&_28$$6, "\n");
			zephir_array_fast_append(&_27$$6, &_28$$6);
			ZEPHIR_INIT_NVAR(&_29$$6);
			zephir_create_array(&_29$$6, 2, 0);
			ZEPHIR_INIT_NVAR(&_28$$6);
			ZVAL_STRING(&_28$$6, "");
			zephir_array_fast_append(&_29$$6, &_28$$6);
			ZEPHIR_INIT_NVAR(&_28$$6);
			ZVAL_STRING(&_28$$6, "");
			zephir_array_fast_append(&_29$$6, &_28$$6);
			zephir_fast_str_replace(&_22$$6, &_27$$6, &_29$$6, &s);
			ZEPHIR_CPY_WRT(&s, &_22$$6);
			ZEPHIR_INIT_NVAR(&_22$$6);
			ZVAL_STRING(&_22$$6, "#<[^>]+>#");
			ZEPHIR_INIT_NVAR(&_28$$6);
			ZEPHIR_INIT_NVAR(&_30$$6);
			ZVAL_STRING(&_30$$6, "#<[^>]+>#");
			zephir_preg_match(&_28$$6, &_30$$6, &s, &tags, 1, 0 , 0 );
			if (ZEPHIR_IS_LONG(&n, line)) {
				ZEPHIR_INIT_NVAR(&_31$$7);
				ZEPHIR_CONCAT_SVS(&_31$$7, "<span class='highlight'>%", &numWidth, "s:    %s\n</span>%s");
				ZEPHIR_CALL_FUNCTION(&_32$$7, "strip_tags", &_33, 110, &s);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_34$$7);
				zephir_array_fetch_long(&_35$$7, &tags, 0, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 790);
				zephir_fast_join_str(&_34$$7, SL(""), &_35$$7);
				ZEPHIR_CALL_FUNCTION(&_36$$7, "sprintf", &_37, 3, &_31$$7, &n, &_32$$7, &_34$$7);
				zephir_check_call_status();
				zephir_concat_self(&out, &_36$$7);
			} else {
				ZEPHIR_INIT_NVAR(&_38$$8);
				ZEPHIR_CONCAT_SVS(&_38$$8, "<span class='line'>%", &numWidth, "s:</span>    %s\n");
				ZEPHIR_CALL_FUNCTION(&_39$$8, "sprintf", &_37, 3, &_38$$8, &n, &s);
				zephir_check_call_status();
				zephir_concat_self(&out, &_39$$8);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &source, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_19, &source, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_19)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&n, &source, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&s, &source, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$9);
				ZVAL_STRING(&_40$$9, "<span");
				ZEPHIR_CALL_FUNCTION(&_41$$9, "substr_count", &_24, 156, &s, &_40$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_40$$9);
				ZVAL_STRING(&_40$$9, "</span");
				ZEPHIR_CALL_FUNCTION(&_42$$9, "substr_count", &_24, 156, &s, &_40$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_43$$9);
				zephir_sub_function(&_43$$9, &_41$$9, &_42$$9);
				ZEPHIR_ADD_ASSIGN(&spans, &_43$$9);
				ZEPHIR_INIT_NVAR(&_40$$9);
				ZEPHIR_INIT_NVAR(&_44$$9);
				zephir_create_array(&_44$$9, 2, 0);
				ZEPHIR_INIT_NVAR(&_45$$9);
				ZVAL_STRING(&_45$$9, "\r");
				zephir_array_fast_append(&_44$$9, &_45$$9);
				ZEPHIR_INIT_NVAR(&_45$$9);
				ZVAL_STRING(&_45$$9, "\n");
				zephir_array_fast_append(&_44$$9, &_45$$9);
				ZEPHIR_INIT_NVAR(&_46$$9);
				zephir_create_array(&_46$$9, 2, 0);
				ZEPHIR_INIT_NVAR(&_45$$9);
				ZVAL_STRING(&_45$$9, "");
				zephir_array_fast_append(&_46$$9, &_45$$9);
				ZEPHIR_INIT_NVAR(&_45$$9);
				ZVAL_STRING(&_45$$9, "");
				zephir_array_fast_append(&_46$$9, &_45$$9);
				zephir_fast_str_replace(&_40$$9, &_44$$9, &_46$$9, &s);
				ZEPHIR_CPY_WRT(&s, &_40$$9);
				ZEPHIR_INIT_NVAR(&_40$$9);
				ZVAL_STRING(&_40$$9, "#<[^>]+>#");
				ZEPHIR_INIT_NVAR(&_45$$9);
				ZEPHIR_INIT_NVAR(&_47$$9);
				ZVAL_STRING(&_47$$9, "#<[^>]+>#");
				zephir_preg_match(&_45$$9, &_47$$9, &s, &tags, 1, 0 , 0 );
				if (ZEPHIR_IS_LONG(&n, line)) {
					ZEPHIR_INIT_NVAR(&_48$$10);
					ZEPHIR_CONCAT_SVS(&_48$$10, "<span class='highlight'>%", &numWidth, "s:    %s\n</span>%s");
					ZEPHIR_CALL_FUNCTION(&_49$$10, "strip_tags", &_33, 110, &s);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_50$$10);
					zephir_array_fetch_long(&_51$$10, &tags, 0, PH_NOISY | PH_READONLY, "moon/Component/ErrorHandler/Formatter/NormalFormatter.zep", 790);
					zephir_fast_join_str(&_50$$10, SL(""), &_51$$10);
					ZEPHIR_CALL_FUNCTION(&_52$$10, "sprintf", &_37, 3, &_48$$10, &n, &_49$$10, &_50$$10);
					zephir_check_call_status();
					zephir_concat_self(&out, &_52$$10);
				} else {
					ZEPHIR_INIT_NVAR(&_53$$11);
					ZEPHIR_CONCAT_SVS(&_53$$11, "<span class='line'>%", &numWidth, "s:</span>    %s\n");
					ZEPHIR_CALL_FUNCTION(&_54$$11, "sprintf", &_37, 3, &_53$$11, &n, &s);
					zephir_check_call_status();
					zephir_concat_self(&out, &_54$$11);
				}
			ZEPHIR_CALL_METHOD(NULL, &source, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&s);
	ZEPHIR_INIT_NVAR(&n);
	ZEPHIR_INIT_VAR(&_55);
	ZVAL_STRING(&_55, "</span>");
	ZEPHIR_CALL_FUNCTION(&_56, "str_repeat", NULL, 113, &_55, &spans);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_57);
	ZEPHIR_CONCAT_VS(&_57, &_56, "</code>");
	zephir_concat_self(&out, &_57);
	RETURN_CCTOR(&out);

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, toHtml) {

	zend_bool _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_var, _var_sub, json, html, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&json);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_var);



	ZEPHIR_INIT_VAR(&html);
	ZVAL_NULL(&html);
	ZEPHIR_INIT_VAR(&json);
	ZVAL_NULL(&json);
	_0 = Z_TYPE_P(_var) == IS_ARRAY;
	if (!(_0)) {
		_0 = Z_TYPE_P(_var) == IS_OBJECT;
	}
	_1 = _0;
	if (!(_1)) {
		_1 = Z_TYPE_P(_var) == IS_RESOURCE;
	}
	_2 = _1;
	if (_2) {
		_2 = zephir_is_true(_var);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&json, this_ptr, "tojson", NULL, 0, _var);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&html, this_ptr, "dumpvar", NULL, 0, _var);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	if (zephir_is_true(&json)) {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, " moon-collapsed");
	} else {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, "");
	}
	ZEPHIR_INIT_VAR(&_4);
	if (zephir_is_true(&json)) {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_LONG(&_6, (4 | 2));
		zephir_json_encode(&_5, &json, zephir_get_intval(&_6) );
		ZEPHIR_INIT_NVAR(&_4);
		ZEPHIR_CONCAT_SVS(&_4, " data-moon-dump='", &_5, "'>");
	} else {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_STRING(&_4, ">");
	}
	ZEPHIR_CONCAT_SVSVVS(return_value, "<pre class=\"moon-dump", &_3, "\"", &_4, &html, "</pre>\n");
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, toJson) {

	zval *val, val_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&val_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &val);



	RETURN_BOOL(0);

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, dumpVar) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_var, _var_sub, m, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_var_sub);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_var);



	ZEPHIR_INIT_VAR(&_0);
	zephir_gettype(&_0, _var);
	ZEPHIR_INIT_VAR(&m);
	ZEPHIR_CONCAT_SV(&m, "dump", &_0);
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &m, NULL, 0, _var);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, getDumper) {

	zval keysToHide, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keysToHide);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "strtolower");
	ZEPHIR_CALL_FUNCTION(&_2, "array_map", NULL, 83, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&keysToHide, "array_flip", NULL, 65, &_2);
	zephir_check_call_status();
	zephir_create_closure_ex(return_value, NULL, moon_4__closure_ce, SL("__invoke"));
	zephir_update_static_property_ce(moon_4__closure_ce, ZEND_STRL("keysToHide"), &keysToHide);
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, addPanel) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *title_param = NULL, *table, table_sub, _0, _1, _2;
	zval title;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title);
	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &title_param, &table);

	zephir_get_strval(&title, title_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_errorhandler_panel_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, &_0, "settitle", NULL, 157, &title);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "setcontent", NULL, 0, table);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("panel"), &_2);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, addPanelTable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval content;
	zval *title_param = NULL, *content_param = NULL, _0, _1;
	zval title;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&content);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &title_param, &content_param);

	zephir_get_strval(&title, title_param);
	zephir_get_arrval(&content, content_param);


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, moon_component_errorhandler_table_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, &_0, "settitle", NULL, 158, &title);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "setcontent", NULL, 0, &content);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Moon_Component_ErrorHandler_Formatter_NormalFormatter, __call) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, *arg, arg_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&arg_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method, &arg);



	if ((zephir_method_exists(this_ptr, method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, method, NULL, 0, arg);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_STRING("<span>unknown type</span>\n");

}

zend_object *zephir_init_properties_Moon_Component_ErrorHandler_Formatter_NormalFormatter(zend_class_entry *class_type TSRMLS_DC) {

		zval _3$$4;
	zval _0, _2, _5, _1$$3, _4$$4, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("panel"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("panel"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("keysToHide"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 8, 0);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "password");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "passwd");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "pass");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "pwd");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "creditcard");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "credit card");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "cc");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "pin");
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("keysToHide"), &_3$$4);
		}
		zephir_read_property_ex(&_5, this_ptr, ZEND_STRL("collapsePaths"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_5) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_6$$5);
			array_init(&_6$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("collapsePaths"), &_6$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

