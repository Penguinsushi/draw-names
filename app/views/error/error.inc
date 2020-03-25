<h1>
    Error: <?php echo $ERROR->ErrorTitle ?>
</h1>
<div class="content_box"><div class="textbox" style="text-align:center;">
    
        <p>
    <?php 
        echo $ERROR->ErrorTitle;  
        if (!empty($spec))
        {
            echo ": <b>".$spec."</b>";
        }
        ?></p>
        
    <p class="red">
    <?php 
        $ERROR->ErrorMessage = str_replace('Server Replies:','<span style="color:gray;font-weight:normal"><i>Server Replies:</i></span>',$ERROR->ErrorMessage);
        echo $ERROR->ErrorMessage;  
    ?>
    </div></p></div>


<?php 
if ($GLOBALS['uri']->elements[1] == '404x')
{ 
?>
<div class="content_box"><div class="textbox">
        <p><b>Please excuse the orphans</b> - an author's note on lost content.</p>
        <p>This site - the blog in particular - has been up for several years now, and has gone through several different iterations including
        the addition and subtraction of various pages and features.  Most of these redesigns have also reflected an entire structural rebuild, 
        and while I've preserved the basic content of old entries, ports of old definitions such as directory structure were not always 
        possible/practical.  As a result, there are a fair number of resources (images/internal links/etc) mentioned in old content that no 
        longer exist and/or cannot be found.</p>
        <p>Yeah.  Sorry about that.</p>
    </div></div>
<?php 
}
?>