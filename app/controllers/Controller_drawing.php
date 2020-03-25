<?php

class Controller_drawing extends Controller
{

    // PROPERTIES
    
    
    // PAGE METHODS
    
    public function __construct() {
        parent::__construct();
        include('app/controllers/_common/init.inc');
    }
    
    public function index($vars=array())
    {
        if (!empty($vars[0]))
        {
            $display_vars['DRAWING'] = Model_Drawing::getByToken($vars[0]);
            
        }
        if (!empty($display_vars['DRAWING']))
        {
            if (!empty($_POST['drawing_exec_button'])) 
            {
                if($display_vars['DRAWING']->DrawingPerformed)
                {
                    $display_vars['DRAWING']->sendParticipantEmails();
                    $display_vars['MESSAGE'] = 'Emails Sent!';
                }
                else
                {
                    $result = $display_vars['DRAWING']->performDrawing();
                    if ($result)
                    {
                        $display_vars['MESSAGE'] = 'Drawing Performed and Emails Sent!';
                    }
                    else
                    {
                        $display_vars['ERROR'] = 'Drawing Failed.';
                    }
                }
            }
            $display_vars['CANONICAL'] = "drawing";        
            $display_vars['TITLE'] = "Drawing";
            $display_vars['METADESC'] = "";
            $this->render_page("drawing/drawing.inc",$display_vars);
        }
        else
        {
            header('Location: /home');die;
        }
        
        
    }
    
    public function participant($vars=array())
    {
        if (!empty($_POST['token'])) 
        {
            $P = Model_Participant::getByToken($_POST['token']);
            $P->setBuyFor();
            $D = Model_Drawing::getByRowID($P->DrawingRowID);
            $vars[0] = $_POST['token'];
            if (!empty($_POST['bf_message']) OR !empty($_POST['rf_message']))
            {
                $mail = new Email();
                if (!empty($_POST['bf_message']))
                {
                    $MESSAGE = $_POST['bf_message'];
                    $mail->to = $P->buy_for->ParticipantEmailAddress;
//                    $mail->to = 'shoe@penguinsushi.com'; // FOR TESTING
                }
                else
                {
                    $MESSAGE = $_POST['rf_message'];
                    $RF = Model_Participant::getByBuyFor($P->ParticipantRowID);
                    $mail->to = $RF->ParticipantEmailAddress;
//                    $mail->to = 'shoe@penguinsushi.com'; // FOR TESTING
                }
                $subtag='';
                if (!empty($_POST['bf_message'])) {$subtag = ' from ???';} elseif (!empty($_POST['rf_message'])) {$subtag = ' from '.$P->ParticipantFirstName;}
                $mail->from = 'drawnames@penguinsushi.com';
                $mail->subject = $D->DrawingName.' - Message '.$subtag;
                ob_start();
                include($GLOBALS['config']['app_dir'].'views/drawing/message_template.inc');
                $message = ob_get_clean();
                $mail->message = $message;
                $mail->sendMail();
                header('Location: /drawing/participant/'.$vars[0].'?msg=sent');die;
            }
            elseif(!empty($_POST['info_button']))
            {
//                $fv['ParticipantFirstName'] = $_POST['firstname'];
//                $fv['ParticipantLastName'] = $_POST['lastname'];
                $fv['ParticipantEmailAddress'] = $_POST['email'];
                $fv['ParticipantNotes'] = $_POST['notes'];
                $fv['ParticipantWishlistURL'] = $_POST['wishlist'];
                Model_Participant::updateParticipant($P->ParticipantRowID, $fv);
                if ($fv['ParticipantNotes'] != $P->ParticipantNotes OR $fv['ParticipantWishlistURL'] != $P->ParticipantWishlistURL)
                {
                    $mail = new Email();
                    $P = Model_Participant::getByToken($_POST['token']);
                    $RF = Model_Participant::getByBuyFor($P->ParticipantRowID);
                    $mail->to = $RF->ParticipantEmailAddress;
//                    $mail->to = 'shoe@penguinsushi.com'; // FOR TESTING
                    $mail->from = 'drawnames@penguinsushi.com';
                    $mail->subject = $D->DrawingName.' - '.$P->ParticipantFirstName.' updated their info';
                    ob_start();
                    include($GLOBALS['config']['app_dir'].'views/drawing/notify_template.inc');
                    $message = ob_get_clean();
                    $mail->message = $message;
                    $mail->sendMail();
                    $not='notified';
                }
                else
                {
                    $not='';
                }
                    header('Location: /drawing/participant/'.$vars[0].'?msg=updated'.$not);die;
            }
        }
        if (!empty($vars[0]))
        {
            $display_vars['token'] = $vars[0];
            $display_vars['P'] = Model_Participant::getByToken($vars[0]);
            $display_vars['P']->setBuyFor();
            $display_vars['D'] = Model_Drawing::getByRowID($display_vars['P']->DrawingRowID);
        }
        if (!empty($display_vars['P']))
        {
            if (!empty($_GET['msg'])) {$display_vars['msg']=$_GET['msg'];}
            $display_vars['CANONICAL'] = "drawing/participant";        
            $display_vars['TITLE'] = $display_vars['P']->ParticipantFirstName."'s Drawing Portal";
            $display_vars['METADESC'] = "";
            $this->render_page("drawing/participant.inc",$display_vars);
        }
        else
        {
            header('Location: /home');die;
        }
    }
    
    public function awl_howto()
    {
        $display_vars['CANONICAL'] = "drawing/awl_howto";        
        $display_vars['TITLE'] = "How To Share Amazon Wishlist";
        $display_vars['METADESC'] = "";
        $this->render_page("drawing/awl_howto.inc",$display_vars);
    }
    
}