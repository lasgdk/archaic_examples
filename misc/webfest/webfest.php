<?php

# Website input to speech script by Lars Sommer, lasg@lasg.dk, 2007-07-11

# Get info about the current time and IP address of the user
$date = date("d-m-Y H:i");
$ip = getenv("REMOTE_ADDR");

$file = "webfest.log";

# Do a check to see if something just have been said (flood protection)
$lastuse = date("d-m-Y H:i",filemtime($file));
if( $date == $lastuse) 
die("You can only say a line once per minute. Please try again in a moment.");

# Substr takes the first 256 chars from the 'say' variable, posted from the html
#  file. Escapeshellcmd puts preceeding backslashes before shell critical 
#  characters like $,&,|
$say = escapeshellcmd(substr($_POST['say'],0,256));

# Append time, IP and text message to a log file
$filehandler = fopen($file,'a') or die("Cannot access file");
$towrite = "DATE: $date IP: $ip MSG: $say\n";
fwrite($filehandler,$towrite);
fclose($filehandler);

system("echo message from the internet.. $say|festival --tts");
echo("I just said: $say<br>");
echo("Thank you for using webfest, and for telling me random things :)");

?>
