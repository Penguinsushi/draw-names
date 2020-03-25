<div style='font-size:14px;'>
<p style='font-size:24px;'>Hello, <?php echo $RF->ParticipantFirstName ?> -</p>

<p>This message is to let you know that <span style='color:green;'><?php echo $P->ParticipantFirstName ?> <?php echo $P->ParticipantLastName ?></span> has updated their info for the <span style='color:navy;'><b><?php echo $D->DrawingName ?></b></span> drawing.</p>

<p><br/><b><?php echo $P->ParticipantFirstName ?>'s Wishlist:</b> <?php if (!empty($P->ParticipantWishlistURL)) {echo "<a style='color:green;' href='".$P->ParticipantWishlistURL."'>".$P->ParticipantFirstName."'s Wishlist</a>";} ?></p>
<p><b><?php echo $P->ParticipantFirstName ?>'s Notes:</b> <i><span style='color:green;'><?php echo nl2br($P->ParticipantNotes); ?></span></i><br/><br/></p>

<p>You can the rest of your drawing info <b><u><a style='color:navy;' href="<?php echo $GLOBALS['config']['base_url'].'drawing/participant/'.$RF->ParticipantToken?>">here</a></u></b>.</p>

<span style='color:gray;font-size:10px;'><p>--</p>
    <p>Message from drawnames.penguinsushi.com</p></span>
</div>