<table>
    <tr>
    <?php $x=0; while($x < 7) {$x++; ?>
    
        <td><img src='<?php echo $GLOBALS['config']['app_dir'] ?>views/drawing/images/az<?php echo $x ?>.jpg' style='border:1px solid green;' /></td>
        <?php if ($x != 7) { ?><td style="font-size:36px;padding:20px;color:green;">&raquo;</td><?php } ?>
    
    <?php } ?>
        </tr>
</table>