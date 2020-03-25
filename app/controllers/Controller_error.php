<?php 

class Controller_error extends Controller
{
    
    // METHODS
    
    public function __construct()
    {
        parent::__construct();
        include('app/controllers/_common/init.inc');
    }
    
    public function index($vars=array())
    {
        $display_vars['ERROR'] = Error::getError($vars[0],TRUE);
        header($display_vars['ERROR']->ErrorHTTPCode);
        if (!empty($vars[1])) {$display_vars['spec'] = urldecode($vars[1]);}
        $display_vars['CANONICAL'] = "error/".$vars[0];
        $display_vars['TITLE'] = "Oops, you broke it - Error: ".$display_vars['ERROR']->ErrorTitle;
        $display_vars['OVERLAY_TEXT'] = strtoupper(str_replace(' ','-',$display_vars['ERROR']->ErrorTitle));
        if (isset($GLOBALS['log'])) {$GLOBALS['log']->writeEntry('ERROR - '.$display_vars['ERROR']->ErrorTitle.' - '.$display_vars['ERROR']->ErrorMessage.' ('.$display_vars['ERROR']->ErrorHTTPCode.')');}
        $this->render_page('error/error.inc', $display_vars);
    }
    
}

?>