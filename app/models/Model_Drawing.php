<?php

class Model_Drawing extends Model
{
    
    // PROPERTIES
    
    public $DrawingRowID = 0;
    public $DrawingName = '';
    public $DrawingGiftValue = 0.00;
    public $DrawingDateTime = '';
    public $DrawingEventDate = '';
    public $DrawingEventLocation = '';
    public $DrawingToken = '';
    public $DrawingCoordinatorEmailAddress = '';
    public $DrawingPerformed = 0;
    
    public $participants = array();
    
    public static $table = 'tblDrawings';
    
    public static function getByRowID($id)
    {
        $sql = new SQLQuery(self::$table,'DrawingRowID',$id);
        return $GLOBALS['db']->createDataObjects($sql->query,'Model_Drawing',NULL,array('setProperties'),'single');
    }
    
    public static function getByToken($token)
    {
        $sql = new SQLQuery(self::$table,'DrawingToken',$token);
        return $GLOBALS['db']->createDataObjects($sql->query,'Model_Drawing',NULL,array('setProperties'),'single');
    }
    
    public static function createDrawing($fieldvalues)
    {
        return $GLOBALS['db']->dataInsert(self::$table,$fieldvalues);
    }
    
    public static function updateDrawing($id,$fieldvalues)
    {
        return $GLOBALS['db']->dataUpdate(self::$table,'DrawingRowID',$id,$fieldvalues);
    }
    
    public static function deleteDrawing($id)
    {
        Model_Participant::deleteForDrawing($id);
        return $GLOBALS['db']->dataDelete(self::$table,'DrawingRowID',$id);
    }
    
    public function performDrawing($retries=0)
    {
        if ($retries > 99) {return FALSE;}
        $assigned = array();
        shuffle($this->participants);
        $email_r = Model_Participant::getPreviousEmailRelationships($this->DrawingRowID);
        foreach($this->participants AS $k => $p)
        {
            $pick=NULL;
            $tries=0;
            while(empty($assigned[$p->ParticipantRowID]))
            {
                $tries++;
                if (!empty($email_r[$p->ParticipantEmailAddress])) {$not_email = $email_r[$p->ParticipantEmailAddress];} else {$not_email=NULL;}
                $pick = Model_Participant::getRandomForDrawing($this->DrawingRowID,$p->ParticipantHouseholdID,$not_email);
                if (!in_array($pick->ParticipantRowID, $assigned))
                {
                    $this->participants[$k]->ParticipantBuyForParticipantRowID = $assigned[$p->ParticipantRowID] = $pick->ParticipantRowID;
                }
                elseif($tries > count($this->participants))
                {
                    return $this->performDrawing($retries++);
                }
            }
        }
        foreach($assigned AS $pid => $has)
        {
            Model_Participant::updateParticipant($pid, array('ParticipantBuyForParticipantRowID'=>$has));
        }
        if (empty($_SESSION['dev'])) {Model_Drawing::updateDrawing($this->DrawingRowID,array('DrawingPerformed'=>1));}
        $this->DrawingPerformed=1;
        $this->sendParticipantEmails();
        return TRUE;
    }
    
    public function sendCoordinatorEmail()
    {
           $mail = new Email();
            $mail->to = $this->DrawingCoordinatorEmailAddress;
//            $mail->to = 'shoe@penguinsushi.com'; // FOR TESTING
            $mail->from = 'drawnames@penguinsushi.com';
            $mail->subject = $this->DrawingName.' Setup';
            $DRAWING = $this;
            ob_start();
            include($GLOBALS['config']['app_dir'].'views/drawing/coord_email_template.inc');
            $message = ob_get_clean();
            $mail->message = $message;
            $mail->sendMail();
    }
    
    public function sendParticipantEmails()
    {
        foreach($this->participants AS $P)
        {
            $BF = Model_Participant::getByRowID($P->ParticipantBuyForParticipantRowID);
            $mail = new Email();
            if (!empty($_SESSION['dev']))
            {
                $mail->to = 'shoe@penguinsushi.com'; // FOR TESTING
            }
            else
            {    
                $mail->to = $P->ParticipantEmailAddress;
            }
            $mail->from = 'drawnames@penguinsushi.com';
            $mail->subject = $this->DrawingName.' Name Drawing';
            $DRAWING = $this;
            ob_start();
            include($GLOBALS['config']['app_dir'].'views/drawing/email_template.inc');
            $message = ob_get_clean();
            $mail->message = $message;
            $mail->sendMail();
        }
    }
    
    public function setProperties()
    {
        $this->setParticipants();
    }
    
    public function setParticipants()
    {
        $this->participants = Model_Participant::getForDrawing($this->DrawingRowID);
    }
    
}