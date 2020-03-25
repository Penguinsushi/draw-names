

    <?php if (!empty($ERROR)) { ?>
        <div class='errorbox'><?php echo $ERROR ?></div>
    <?php } ?>
    
     <?php if (!empty($MESSAGE)) { ?>
        <div class='messagebox'><?php echo $MESSAGE ?></div>
    <?php } ?>
        
    <div class="banner" style="font-size:24px;background-color:white; color:black; border:1px solid black;">New Drawing</div>
        
    <?php
    new HTMLForm('home', 'POST', NULL, array('onsubmit'=>""));
    ?>

    <table class='formtable' id='drawingtable'>

        <tr>
            <td class='labelcell'>Drawing Name:</td>
            <td class='inputcell'><?php HTMLForm::textInput('name', '', array('placeholder'=>'e.g. Family Christmas '.date('Y'))); ?></td>
        </tr>

        <?php 
        // drawing date/time: perhaps add the ability to send 'invites' to participants and schedule the drawing - any that confirm/sign-up are included??  
        // for now, the date/time will be time of creation
        ?>

        <tr>
            <td class='labelcell'>Coordinator Email Address:</td>
            <td class='inputcell'><?php HTMLForm::textInput('coord_email', '', array('placeholder'=>'email@address.com')); ?></td>
        </tr>
        
        <tr>
            <td class='labelcell'>Event Date:</td>
            <td class='inputcell'><?php HTMLForm::textInput('event_date', '', array('placeholder'=>'YYYY-MM-DD')); ?></td>
        </tr>
        
        <tr>
            <td class='labelcell'>Event Location:</td>
            <td class='inputcell'><?php HTMLForm::textInput('event_loc', '', array('placeholder'=>"e.g. Mom & Dad's house")); ?></td>
        </tr>
        
        <tr>
            <td class='labelcell'>Suggested Gift Value:</td>
            <td class='inputcell'><?php HTMLForm::textInput('value', '', array('placeholder'=>'e.g. 30.00')); ?></td>
        </tr>

    </table>
    <table class='formtable' id='participants'>
        <tr>
            <td class='labelcell'>Participant:</td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_firstname[]', '', array('placeholder'=>'First Name','style'=>'width:150px;')); ?></td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_lastname[]', '', array('placeholder'=>'Last Name','style'=>'width:150px;')); ?></td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_email[]', '', array('placeholder'=>'Email Address','style'=>'width:150px;')); ?></td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_household[]', '', array('placeholder'=>'Household ID: e.g. 1 or SHOEMAKER','style'=>'width:150px;')); ?></td>
        </tr>
        <tr>
            <td class='labelcell'>Participant:</td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_firstname[]', '', array('placeholder'=>'First Name','style'=>'width:150px;')); ?></td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_lastname[]', '', array('placeholder'=>'Last Name','style'=>'width:150px;')); ?></td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_email[]', '', array('placeholder'=>'Email Address','style'=>'width:150px;')); ?></td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_household[]', '', array('placeholder'=>'Household ID: e.g. 1 or SHOEMAKER','style'=>'width:150px;')); ?></td>
        </tr>
        <tr>
            <td class='labelcell'>Participant:</td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_firstname[]', '', array('placeholder'=>'First Name','style'=>'width:150px;')); ?></td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_lastname[]', '', array('placeholder'=>'Last Name','style'=>'width:150px;')); ?></td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_email[]', '', array('placeholder'=>'Email Address','style'=>'width:150px;')); ?></td>
            <td class='inputcell'><?php HTMLForm::textInput('participants_household[]', '', array('placeholder'=>'Household ID: e.g. 1 or SHOEMAKER','style'=>'width:150px;')); ?></td>
        </tr>
    </table>
    
    <table class='formtable'>
        <tr>
            <td class='labelcell'></td>
            <td class='inputcell'>
                <a href='#' onclick='addParticipant();return false;'>Add Participant</a><br/>
                <?php HTMLForm::submitButton('create_drawing_button','Create Drawing',array('class'=>'submit_button')); ?>
            </td>
        </tr>
    </table>

    <?php
    HTMLForm::close();
    ?>

    <script>
        
       function addParticipant()
       {
           var html = '<tr>';
           html = html + '<td>Participant</td>';
           html = html + '<td><input name="participants_firstname[]" placeholder="First Name" style="width:150px;"></td>';
           html = html + '<td><input name="participants_lastname[]" placeholder="Last Name" style="width:150px;"></td>';
           html = html + '<td><input name="participants_email[]" placeholder="Email Address" style="width:150px;"></td>';
           html = html + '<td><input name="participants_household[]" placeholder="Household ID: e.g. 1 or SHOEMAKER" style="width:150px;"></td>';
           html = html + '</tr>';
           $('#participants').append(html);
       }
        
    </script>
    
