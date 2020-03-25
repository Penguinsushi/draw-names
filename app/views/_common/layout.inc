<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
<!--
    ____  _______   __________  _______   _______ __  _______ __  ______ __________  __  ___
   / __ \/ ____/ | / / ____/ / / /  _/ | / / ___// / / / ___// / / /  _// ____/ __ \/  |/  /
  / /_/ / __/ /  |/ / / __/ / / // //  |/ /\__ \/ / / /\__ \/ /_/ // / / /   / / / / /|_/ / 
 / ____/ /___/ /|  / /_/ / /_/ // // /|  /___/ / /_/ /___/ / __  // /_/ /___/ /_/ / /  / /  
/_/   /_____/_/ |_/\____/\____/___/_/ |_//____/\____//____/_/ /_/___(_)____/\____/_/  /_/ 

Version: 12.1.4 | Copyright <?php echo date('Y') ?>

Powered By PenguinIgniter v<?php echo $GLOBALS['pi_version'] ?> [http://pi-core.penguinsushi.com]

-->
<title><?php echo $TITLE; if (!empty($_SESSION['dev'])) {echo " DEV";} ?> | Penguinsushi.com</title>
<?php if (!empty($METADESC)) { ?>
    <META NAME="Description" CONTENT="<?php echo $METADESC ?>">
<?php } ?>
<base href="<?php echo $GLOBALS['config']['base_url'] ?>" />
<?php
if (!empty($CANONICAL))
{
    echo "<link rel=\"canonical\" href=\"".$GLOBALS['config']['base_url']."$CANONICAL\"/>";
}
?>
<LINK REL=StyleSheet HREF="<?php echo $GLOBALS['config']['app_dir'] ?>views/<?php echo $GLOBALS['config']['views_theme_dir'] ?>_common/style.css" TYPE="text/css" MEDIA=all />
<script type="text/javascript" src="//cdnjs.cloudflare.com/ajax/libs/jquery/2.0.2/jquery.min.js"></script>
<script type="text/javascript" src="//cdnjs.cloudflare.com/ajax/libs/jqueryui/1.10.3/jquery-ui.min.js"></script>
<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
    
</head>
<body id="site_body">
    
    <div id="content">
            <?php include($GLOBALS['config']['app_dir'].'views/'.$GLOBALS['config']['views_theme_dir'].$CONTENT); ?>
    </div>
    
</body>
</html>