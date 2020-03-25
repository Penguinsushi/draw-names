     <div class="banner" style="font-size:24px;background-color:white; color:#343434; border:1px solid #343434;">Welcome, <?php echo $P->ParticipantFirstName ?></div>

      <?php if (!empty($msg)) { ?>
        <script>
            $( document ).ready(function() {
                setTimeout(function() { $("#msg").fadeOut(2000); }, 2000);
            });
        </script>
        <div class='messagebox' id='msg'><?php if ($msg == 'sent') {echo "Message Sent.";} elseif($msg == 'updated') {echo "Your info has been updated.";} elseif ($msg == 'updatednotified') {echo "Your info has been updated. Whoever has your name has been notified.";} ?></div>
    <?php } ?>
     
    <div class="banner">Drawing Info:</div>
    
    <table class='formtable' >
        
        <tr>
            <td class='labelcell'>Drawing:</td>
            <td class='inputcell' style='color:navy;'><?php echo $D->DrawingName; ?></td>
        </tr>
        
        <tr>
            <td class='labelcell'>Suggested Gift Value:</td>
            <td class='inputcell' style='color:navy;'>$<?php echo $D->DrawingGiftValue; ?></td>
        </tr>
        
        <tr>
            <td class='labelcell'>Event Date:</td>
            <td class='inputcell' style='color:navy;'><?php $eventtime = strtotime($D->DrawingEventDate); $daysleft = ceil((((($eventtime - time())/60)/60)/24)); echo date('F j, Y',$eventtime).' - <b><span style="'.($daysleft < 10 ? 'color:red;' : '').'">'.$daysleft.' days remaining</span></b>' ?></td>
        </tr>
        
        <tr>
            <td class='labelcell'>Event Location:</td>
            <td class='inputcell' style='color:navy;'><?php echo $D->DrawingEventLocation ?></td>
        </tr>
        
    </table>
    
    <div class="banner" style="background-color:green;">You need a gift for:</div>
        
    <table class='formtable' >
        
        <tr>
            <td class='labelcell'>Name:</td>
            <td class='inputcell' style='color:green;'><?php echo $P->buy_for->ParticipantFirstName ?> <?php echo $P->buy_for->ParticipantLastName ?></td>
        </tr>
        
        <tr>
            <td class='labelcell'>Notes:</td>
            <td class='inputcell'><i><?php if (!empty($P->buy_for->ParticipantNotes)) {echo '<span style="color:green;">'.nl2br($P->buy_for->ParticipantNotes)."</span>";} else {echo "no notes yet";} ?></i></td>
        </tr>
        
        <tr>
            <td class='labelcell'>Wishlist:</td>
            <td class='inputcell'><?php if (!empty($P->buy_for->ParticipantWishlistURL)) {?> <a target='_blank' style='color:green;' href="<?php echo $P->buy_for->ParticipantWishlistURL ?>"><?php echo $P->buy_for->ParticipantFirstName ?>'s Wishlist</a> <?php } else {echo "<i>no wishlist url</i>";} ?></td>
        </tr>
        
    </table>
    
    <div style="border-top:1px solid green;margin:10px 0 10px 0;"></div>
    
    <table class='formtable' >   
                
        <tr>
            <td class='inputcell'>
                Send <span style='color:green;'><?php echo $P->buy_for->ParticipantFirstName ?></span> a Message:<br/>
                <?php new HTMLForm('', 'POST', NULL, array('onsubmit'=>"if(confirm('Are you sure you want to send this message to ".$P->buy_for->ParticipantFirstName."?\\n\\nThis message is meant to be anonymous - ".$P->buy_for->ParticipantFirstName." will not know who sent it, so make sure there is nothing in your message or wording that will give away your identity.\\n\\nClick OK to send, Cancel to cancel sending.')){return true;}else{return false;}"));    ?>
                <?php HTMLForm::hiddenInput('token', $token) ?>
                    <?php HTMLForm::textArea('bf_message', NULL, array('placeholder'=>'e.g. What size shirt do you wear?')) ?><br/>
                <?php HTMLForm::submitButton('message_button','Send anonymous message to '.$P->buy_for->ParticipantFirstName,array('class'=>'submit_button','style'=>'background-color:green;')); ?>
                <?php HTMLForm::close(); ?>
            </td>
        </tr>

    </table>
                
        
    <div class="banner" style="background-color:maroon;">Your Info (for whoever has your name):</div>
    
    <?php new HTMLForm('', 'POST', NULL, array('onsubmit'=>""));    ?>
    <?php HTMLForm::hiddenInput('token', $token) ?>
    
    <table class='formtable' >

        <tr>
            <td class='labelcell'>Name:</td>
            <td class='inputcell' style='color:maroon;'><?php echo $P->ParticipantFirstName; ?> <?php echo $P->ParticipantLastName; ?></td>
        </tr>
        
        <tr>
            <td class='labelcell'>Email Address:</td>
            <td class='inputcell'><?php HTMLForm::textInput('email', $P->ParticipantEmailAddress, array()); ?><br/><span style='font-size:12px;color:maroon;'><i>Your email address is not visible to anyone else, but it determines where your messages/notifications from this system are sent</i></span></td>
        </tr>
        
        <tr>
            <td class='labelcell'>Wishlist URL:</td>
            <td class='inputcell'><?php HTMLForm::textInput('wishlist', $P->ParticipantWishlistURL, array('placeholder'=>'http://wishlist.somewebsite.com?v=sometoken-etc')); ?><br/><span style='font-size:12px;color:maroon;'><i>Make sure this is publicly accessible</i></span><br/><span style='font-size:12px;'><i>&raquo; <a href='drawing/awl_howto' target='_blank' style='color:black;'>How to share my Amazon.com Wishlist</a></i></span></td>
        </tr>
        
        <tr>
            <td class='labelcell'>Additional Notes:</td>
            <td class='inputcell'><?php HTMLForm::textArea('notes', $P->ParticipantNotes, array('placeholder'=>"Interests, hobbies, clothing sizes, I like this kind of stuff, I've always wanted one of these, etc.")) ?><br/><span style='font-size:12px;color:maroon;'><i>If you don't have a web-based wishlist to supply above, put that info here</i></span></td>
        </tr>
        
        <tr>
            <td class='inputcell' colspan='2'>
                <?php HTMLForm::submitButton('info_button','Update Your Info',array('class'=>'submit_button','style'=>'background-color:maroon;')); ?>
            </td>
        </tr>
        
    </table>
    
    <?php HTMLForm::close(); ?>
    
    <div style="border-top:1px solid maroon;margin:0 0 10px 0;"></div>
    
    <table class='formtable' style="" >
        <tr>
            <td class='inputcell'>
                Send <span style='color:maroon;'>???</span> a Message:<br/>
                <?php new HTMLForm('', 'POST', NULL, array('onsubmit'=>"if (confirm('Are you sure you want to send this message to whoever has your name?\\n\\nClick OK to send, Cancel to cancel sending.')) {return true;} else {return false;}"));    ?>
                <?php HTMLForm::hiddenInput('token', $token) ?>
                    <?php HTMLForm::textArea('rf_message', NULL, array('placeholder'=>"e.g. You asked about my shirt size. It's medium.")) ?><br/>
                <?php HTMLForm::submitButton('message_button','Send message to whoever has your name',array('class'=>'submit_button','style'=>'background-color:maroon;')); ?>
                <?php HTMLForm::close(); ?>
            </td>
        </tr>
    </table>
    
    

    