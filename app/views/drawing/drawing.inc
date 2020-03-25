<?php if (!empty($ERROR)) { ?>
        <div class='errorbox'><?php echo $ERROR ?></div>
    <?php } ?>

        <?php if (!empty($MESSAGE)) { ?>
        <div class='messagebox'><?php echo $MESSAGE ?></div>
    <?php } ?>
        
<div class="banner" style="font-size:24px;background-color:white; color:black; border:1px solid black;"><?php echo $DRAWING->DrawingName ?></div>
    
    <table class='formtable'>
        
        <tr> 
            <td class='labelcell' style='width:250px;'><i>Coordinator Email Address:</i></td>
            <td class='inputcell'><i><?php echo $DRAWING->DrawingCoordinatorEmailAddress ?></i></td>
        </tr>
        
        <tr> 
            <td class='labelcell' style='width:250px;'><i>Gift Value:</i></td>
            <td class='inputcell'><i>$<?php echo $DRAWING->DrawingGiftValue ?></i></td>
        </tr>
        
        <?php foreach($DRAWING->participants AS $p) { ?>
        
            <tr> 
                <td class='labelcell'>Participant:</td>
                <td class='inputcell'>
                    <b><?php echo $p->ParticipantFirstName ?> <?php echo $p->ParticipantLastName ?></b> (<?php echo $p->ParticipantHouseholdID ?>)<br/>
                    <?php echo $p->ParticipantEmailAddress ?><br/>
                    <?php if (!empty($p->ParticipantNotes)) { echo 'Notes: '.$p->ParticipantNotes.'<br/>'; } ?>
                    <?php if (!empty($p->ParticipantNotes)) { echo 'Wishlist: <a href="'.$p->ParticipantWishlistURL.'">'.$p->ParticipantWishlistURL."</a><br/>"; } ?>
                </td>
            </tr>
        
        <?php } ?>
        
    </table>
    
    <table class='formtable'>
        <tr>
            <td class='labelcell' style='width:250px;'></td>
            <td class='inputcell'>
                <?php new HTMLForm('drawing/'.$DRAWING->DrawingToken, 'POST', NULL, array('onsubmit'=>"")); ?>
                <?php if ($DRAWING->DrawingPerformed) { $label = 'Resend Drawing'; } else {$label = 'Perform Drawing';} HTMLForm::submitButton('drawing_exec_button',$label,array('class'=>'submit_button')); ?>
                <?php HTMLForm::close(); ?>
            </td>
        </tr>
    </table>

