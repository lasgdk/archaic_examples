#!/usr/local/bin/perl

print("\nI calculate distances in inches and centimeters\n");
print("Give me a value to calculate on: ");

#Read from stdin, until newline is entered.
$dist = <STDIN>;

if ( 0 < $dist && $dist < 1000000 ){

	#Remove last char in string, here a newline.
	chop($dist);

	$dist_in = $dist / 2.54;
	$dist_cm = $dist * 2.54;

	print($dist, " inches is ",$dist_cm," centimeters, and\n");
	print($dist, " centimeters is ",$dist_in," inches\n");

}

else {
	print ("Wacky kind of \"number\" for this prog....\n");
}
