<div style='font-size:14px;'>
<p style='font-size:24px;'>Hello, <?php echo $P->ParticipantFirstName ?> -</p>

<p>We've completed name drawing for <span style='color:navy;'><b><?php echo $DRAWING->DrawingName ?></b></span>!  You got:</p>

<p style='font-size:18px;color:green;'><?php echo $BF->ParticipantFirstName ?> <?php echo $BF->ParticipantLastName ?></p>

<?php if (!empty($DRAWING->DrawingCustomMessage)) { ?>
<p><span style="color:maroon;font-weight:bold;"><?php echo $DRAWING->DrawingCustomMessage ?></span></p>
<?php } ?>

<p>Suggested gift value for this drawing has been set at <span style='color:navy;'>$<?php echo $DRAWING->DrawingGiftValue ?></span>.</p>

<p>The event is scheduled to take place at <span style='color:navy;'><?php echo $DRAWING->DrawingEventLocation ?></span> on <span style='color:navy;'><?php $eventtime = strtotime($DRAWING->DrawingEventDate); echo date('F j, Y',$eventtime) ?></span> - you've got <b><?php echo ceil((((($eventtime - time())/60)/60)/24)) ?> days</b>!</p>

<p><br/><br/>The button below will take you to your info page for this drawing.  You'll need to <span style='color:maroon;'>add some hobbies/interests notes and/or wishlist info for whoever has <i>your</i> name</span>.  This is especially helpful - even necessary - if that person doesn't really know what you're into these days.</p>
    
<p>You'll <i>also</i> be able to <span style='color:green;'>view the interests/wishlist info <i><?php echo $BF->ParticipantFirstName ?></i> has added</span>.  Of course, if the drawing was only recently performed they may not have had time to add anything yet.  Don't worry, <span style='color:green;'>you'll be automatically notified via email any time <?php echo $BF->ParticipantFirstName ?> adds or changes their interests/wishlist info.</span>.</p>

<p>In addition, you can use this page to <span style='color:maroon;'>send messages <i>blindly</i> to whoever has your name</span>, and <span style='color:green;'><i>anonymously</i> to <?php echo $BF->ParticipantFirstName ?></span>.  This feature allows participants in the drawing to communicate and ask questions without giving away who has whose name.  Keep that in mind when sending messages to <?php echo $BF->ParticipantFirstName ?> - don't say anything that could give away who you are!</p>

<p><br/><a style='padding:10px;border-radius:3px;background-color:navy;color:white;font-weight:bold;font-size:14px;text-align:center;' href="<?php echo $GLOBALS['config']['base_url'].'drawing/participant/'.$P->ParticipantToken ?>">My <?php echo $DRAWING->DrawingName ?> Drawing Info</a><br/><br/></p>

<p><i>You'll want to <b>bookmark the page</b> or <b>save this email</b></i>.  The info page doesn't use a login system and instead relies on a url token embedded in the link - so this is the only way to access your info!</p>

<p><br/>That's it!  Thanks for participating with us!</p>

<span style='color:gray;font-size:10px;'><p>--</p>
    <p>Message from drawnames.penguinsushi.com</p></span>
</div>