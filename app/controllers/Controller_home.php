<?php

class Controller_home extends Controller
{

    // PROPERTIES
    
    
    // PAGE METHODS
    
    public function __construct() {
        parent::__construct();
        include('app/controllers/_common/init.inc');
    }
    
    public function index($vars=array())
    {
        
        if (!empty($_POST['create_drawing_button']))
        {
            if (!empty($_POST['name']) AND !empty($_POST['coord_email']))
            {
                $name = $_POST['name'];
                $datetime = date('Y-m-d H:i:s');
                $token = hash('sha256',time().$_POST['name'].$_POST['coord_email']);
                $coord_email = $_POST['coord_email'];
                $date = $_POST['event_date'];
                $value = $_POST['value'];
                $loc = $_POST['event_loc'];
                $id = Model_Drawing::createDrawing(array('DrawingName'=>$name,'DrawingDateTime'=>$datetime,'DrawingToken'=>$token,'DrawingCoordinatorEmailAddress'=>$coord_email,'DrawingEventDate'=>$date,'DrawingEventLocation'=>$loc,'DrawingGiftValue'=>$value));
                if (!empty($id))
                {
                    $num=0;
                    foreach($_POST['participants_email'] AS $key => $email)
                    {
                        if (!empty($email))
                        {
                            $num++;
                            $exists = Model_Participant::getByEmail($email);
                            $p=array();
                            $p['DrawingRowID']=$id;
                            $p['ParticipantEmailAddress']=$email;
                            $p['ParticipantToken'] = hash('sha256',time().$email);
                            if (!empty($_POST['participants_firstname'][$key])) {$p['ParticipantFirstName'] = $_POST['participants_firstname'][$key];} elseif(!empty($exists)) {$p['ParticipantFirstName']=$exists->ParticipantFirstName;}
                            if (!empty($_POST['participants_lastname'][$key])) {$p['ParticipantLastName'] = $_POST['participants_lastname'][$key];} elseif(!empty($exists)) {$p['ParticipantLastName']=$exists->ParticipantLastName;}
                            if (!empty($_POST['participants_household'][$key])) {$p['ParticipantHouseholdID'] = strtoupper(preg_replace("/[^A-Za-z0-9 ]/", '', $_POST['participants_household'][$key]));} elseif(!empty($exists)) {$p['ParticipantHouseholdID']=$exists->ParticipantHouseholdID;}
                            if(!empty($exists)) {$p['ParticipantNotes']=$exists->ParticipantNotes;$p['ParticipantWishlistURL']=$exists->ParticipantWishlistURL;}
                            $pid = Model_Participant::addParticipant($p);
                        }
                    }
                    if ($num >= 3)
                    {
                        $drawing = Model_Drawing::getByRowID($id);
                        $drawing->sendCoordinatorEmail();
                        $display_vars['MESSAGE'] = 'Your drawing has been created.  You should receive a confirmation email shortly.  This email will contain a link to view the drawing and to actually perform it and send emails.'; // resend option?
                    }
                    else
                    {
                        Model_Drawing::deleteDrawing($id);
                        $display_vars['ERROR'] = 'Drawing must have at least 3 participants.';
                    }
                }
                else
                {
                    $display_vars['ERROR'] = 'Drawing creation database error.';
                }
            }
            else
            {
                $display_vars['ERROR'] = 'Must define Drawing Name and Coordinator Email Address.';
            }
        }
        $display_vars['CANONICAL'] = "home";        
        $display_vars['TITLE'] = "Home";
        $display_vars['METADESC'] = "";
        $this->render_page("home/home.inc",$display_vars);
        
    }
    
}