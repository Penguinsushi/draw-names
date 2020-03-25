<?php

class Model_Participant extends Model
{
    
    // PROPERTIES
    
    public $ParticipantRowID = 0;
    public $DrawingRowID = 0;
    public $ParticipantEmailAddress = '';
    public $ParticipantFirstName = '';
    public $ParticipantLastName = '';
    public $ParticipantHouseholdID = 0;
    public $ParticipantNotes = '';
    public $ParticipantWishlistURL = '';
    public $ParticipantToken = '';
    public $ParticipantBuyForParticipantRowID = 0;
        
    public $buy_for = '';
    
    public static $table = 'tblParticipants';
    
    public static function getByRowID($id)
    {
        $sql = new SQLQuery(self::$table,'ParticipantRowID',$id);
        return $GLOBALS['db']->createDataObjects($sql->query,'Model_Participant',array('setProperties'),NULL,'single');
    }
    
    public static function getByToken($token)
    {
        $sql = new SQLQuery(self::$table,'ParticipantToken',$token);
        return $GLOBALS['db']->createDataObjects($sql->query,'Model_Participant',NULL,array('setProperties'),'single');
    }
    
    public static function getByEmail($email)
    {
        $sql = new SQLQuery(self::$table);
        $sql->WHERE('ParticipantEmailAddress',$email);
        $sql->ORDER_BY('ParticipantRowID DESC'); // get most recent
        return $GLOBALS['db']->createDataObjects($sql->query,'Model_Participant',NULL,array('setProperties'),'single');
    }
    
    public static function getByBuyFor($bf)
    {
        $sql = new SQLQuery(self::$table,'ParticipantBuyForParticipantRowID',$bf);
        return $GLOBALS['db']->createDataObjects($sql->query,'Model_Participant',NULL,array('setProperties'),'single');
    }
    
    public static function getForDrawing($did)
    {
        $sql = new SQLQuery(self::$table);
        $sql->WHERE('DrawingRowID',$did);
        $sql->ORDER_BY('ParticipantRowID'); // get most recent
        return $GLOBALS['db']->createDataObjects($sql->query,'Model_Participant',NULL,array('setProperties'));
    }
    
    public static function getRandomForDrawing($did,$exclude_household=NULL,$exclude_email=NULL)
    {
        $sql = new SQLQuery(self::$table);
        $sql->WHERE('DrawingRowID',$did);
        $sql->WHERE('ParticipantHouseholdID',$exclude_household,'!=');
        if (!empty($exclude_email)) {$sql->WHERE('ParticipantEmailAddress',$exclude_email,'!=');}
        $sql->ORDER_BY('RAND()'); // get most recent
        return $GLOBALS['db']->createDataObjects($sql->query,'Model_Participant',array('setProperties'),NULL,'single');
    }
    
    public static function getPreviousEmailRelationships($not_drawing_id)
    {
        $sql = new SQLQuery(self::$table);
        $sql->WHERE('DrawingRowID',$not_drawing_id,'!=');
        $sql->ORDER_BY('ParticipantRowID');
        $results = $GLOBALS['db']->createDataObjects($sql->query,'Model_Participant',array('setProperties'));
        $emails=array();
        foreach($results AS $r)
        {
            $r->setBuyFor();
            $emails[$r->ParticipantEmailAddress] = $r->buy_for->ParticipantEmailAddress;
        }
        return $emails;
    }
    
    public static function addParticipant($fieldvalues)
    {
        return $GLOBALS['db']->dataInsert(self::$table,$fieldvalues);
    }
    
    
    
    public static function updateParticipant($id,$fieldvalues)
    {
        return $GLOBALS['db']->dataUpdate(self::$table,'ParticipantRowID',$id,$fieldvalues);
    }
    
    public static function deleteParticipant($id)
    {
        return $GLOBALS['db']->dataDelete(self::$table,'ParticipantRowID',$id);
    }
    
    public static function deleteForDrawing($did)
    {
        return $GLOBALS['db']->dataDelete(self::$table,'DrawingRowID',$did);
    }
    
    public function setProperties()
    {
    }
 
    public function setBuyFor()
    {
        $this->buy_for = Model_Participant::getByRowID($this->ParticipantBuyForParticipantRowID);
    }
    
}