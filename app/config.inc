<?php
// =============================================================================================================
// PenguinIgniter (simplistic, CodeIgniter-inspired site framework)
// global configuration file
// =============================================================================================================

// =============================================================================================================
// CORE SYSTEM CONFIG
// these config options must be defined for the system to function

// site's base url (with trailing slash) - if you're not using a url rewrite to hide index.php, this needs to end in 'index.php/'
$GLOBALS['config']['base_url'] = "https://drawnames.penguinsushi.com/";
$GLOBALS['config']['base_domain'] = "https://drawnames.penguinsushi.com/";
$GLOBALS['config']['base_dir'] = "";

// core directory path (with trailing slash)
$GLOBALS['config']['core_dir'] = "../pi-core/";

// app directory path (with trailing slash)
$GLOBALS['config']['app_dir'] = "app/";

// development key, used to trigger dev code (path/to/page?dev=[dev_key])
$GLOBALS['config']['dev_key'] = 'ps_dev';

// default/home [page] -> must have controller at app/controllers/Controller_[page]
$GLOBALS['config']['home_page'] = 'home';
    $GLOBALS['config']['redirect_empty'] = TRUE;

// error [page] -> must have controller at app/controllers/Controller_[page]
$GLOBALS['config']['error_page'] = "error";
// error pages used by core
$GLOBALS['config']['404'] = $GLOBALS['config']['base_url'].$GLOBALS['config']['error_page'].'/404'.'/'.urlencode($GLOBALS['config']['base_domain'].substr($_SERVER['REQUEST_URI'],1));
$GLOBALS['config']['content_error'] = $GLOBALS['config']['base_url'].$GLOBALS['config']['error_page'].'/content_error';
//$GLOBALS['config']['invalid_login'] = $GLOBALS['config']['base_url'].$GLOBALS['config']['error_page'].'/invalid_login';
//$GLOBALS['config']['access_restricted'] = $GLOBALS['config']['base_url'].$GLOBALS['config']['error_page'].'/access_restricted';

// views theme dir
$GLOBALS['config']['views_theme_dir'] = '';
// default base layout template in views/
$GLOBALS['config']['default_layout'] = "_common/layout.inc";

// primary database info
$GLOBALS['config']['db_autoconnect'] = TRUE;
$GLOBALS['config']['db_type'] = "mysql"; // DatabaseConnection core class coded for mysql, mssql theoretically supported, others potentially - core/classes/DatabaseConnection.php will probably need modifying for others
$GLOBALS['config']['db_host'] = "localhost"; // database host/ip/port/socket
$GLOBALS['config']['db_port'] = "3307";
$GLOBALS['config']['db_socket'] = "/tmp/mysql5.sock";
$GLOBALS['config']['db_user'] = "penguins"; // db username
$GLOBALS['config']['db_pass'] = "ayanami01"; // db password
$GLOBALS['config']['db_name'] = "penguins_drawnames_db"; // database name

// cache type to instantiate
$GLOBALS['config']['cachetype'] = ''; // see core/classes/Cache.php

// instantiate global Log
$GLOBALS['config']['log'] =  "app/logs/drawnames".date('Y-m-d').'.log'; // file/path.txt see core/classes/Log.php
    $GLOBALS['config']['log_pageloads'] = TRUE; // TRUE|FALSE|strstr(POST|QUERY|SESSION) if log set, write page loads (with POST if present) to this file

// fake file extension (trailing url characters to ignore) (must not contain slashes)
$GLOBALS['config']['fake_ext'] = '';
$GLOBALS['config']['force_fake'] = FALSE; // append and redirect if not present

// redirect uris
// keys must include full path (no leading/trailing slashes) 
// values must be absolute (w/ leading slashes) can be prefixed by '301=' to tell the agent the redirect is permanent
$GLOBALS['config']['redirects'] = array(
                                    
                                    );

// rewrite uris
// keys must include full path (no leading/trailing slashes)
// values must be relative (no base dir, no leading slashes)
$GLOBALS['config']['rewrites'] = array(
                                    );

// =============================================================================================================
// USER/SITE CONFIG
// these config options are for custom or app-specific functionality and are not necessary for the core system

// additional error pages
//$GLOBALS['config']['spam'] = $GLOBALS['config']['base_url'].$GLOBALS['config']['error_page'].'/spam';

// =============================================================================================================
?>