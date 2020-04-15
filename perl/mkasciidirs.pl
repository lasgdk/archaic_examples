#!/usr/bin/perl

#lasg@lasg.dk
#04-09-05
#Someone asked me how to make dirs with letters from a to z.

#If we want capitals, let small_letters be 0, if we want small letters, 
# let it be 32.
#$small_letters=0;
$small_letters=32;

$i=0;
while ($i<=25){
	$char=$i +65 + $small_letters;
        mkdir pack('C',$char);
        $i++;
}
