#!/usr/bin/perl

$fish = "blowfish";

if ($fish eq "blowfish") {
	print "Like Puffy!\n";
}

if (3>1){
	print "3 is greater than 1\n";
}

else {
	print "something is wrong";
}


$i=0;
while ($i<=5){
	print "this is line $i\n";
	$i++;
}

for ($i=0; $i<=5; $i++){
	print "for says \$i is $i\n";
}

foreach ($i=0; $i<=5; $i++){
	print "foreach says \$i is $i\n";
}

#as an opposition to if, we have unless, and to while, we have until
