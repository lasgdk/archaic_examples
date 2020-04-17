<?php
$size = escapeshellcmd($_GET['size']);
$times =  escapeshellcmd($_GET['times']);
system("./randr_test $size $times");
?>
