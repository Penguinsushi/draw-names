<?php

if (!empty($_GET['dev'])) 
{
    if ($_GET['dev'] == 'on') {$_SESSION['dev']=TRUE;} else {$_SESSION['dev']=FALSE;}
}

// dev views
if (!empty($_SESSION['dev']))
{
    echo "DEV ENVIRONMENT";
}
error_reporting(E_ALL);

?>