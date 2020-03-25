<div style='font-size:14px;'>

<?php if (!empty($RF)) { $msgcolor = 'green';?>

<p style='font-size:24px;'>Hello, <?php echo $RF->ParticipantFirstName ?> -</p>

<p><span style='color:green;'><?php echo $P->ParticipantFirstName ?> <?php echo $P->ParticipantLastName ?></span> blindly sent you the following message concerning the <span style='color:navy;'><b><?php echo $D->DrawingName ?></b></span> drawing:</p>

<?php } else { $msgcolor = 'maroon';?>

<p style='font-size:24px;'>Hello, <?php echo $P->buy_for->ParticipantFirstName ?> -</p>

<p><span style='color:maroon;'>Whoever</span> has your name in the <span style='color:navy;'><b><?php echo $D->DrawingName ?></b></span> drawing sent you the following message:</p>

<?php } ?>

<p>--</p>

<p><i><span style='color:<?php echo $msgcolor ?>;'><?php echo nl2br($MESSAGE) ?></span></i></p>

<p>--</p>

<p>You can reply
    
    <?php if (!empty($RF)) {echo 'anonymously to <span style="color:green;">'.$P->ParticipantFirstName.'</span>'; $token = $RF->ParticipantToken;} else {$token = $P->buy_for->ParticipantToken;} ?>
    
    <b><u><a style='color:navy;' href="<?php echo $GLOBALS['config']['base_url'].'drawing/participant/'.$token ?>">here</a></u></b>.</p>

<span style='color:gray;font-size:10px;'><p>--</p>
    <p>Message from drawnames.penguinsushi.com</p></span>
</div>