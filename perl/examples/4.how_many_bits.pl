#!/usr/local/bin/perl

print("\nHow much is x bit?\n");
print("Give me a value to calculate on: ");

#Read from stdin, until newline is entered.
$bits = <STDIN>;

if ( 0 < $bits && $bits < 33 ){

	#Remove last char in string, here a newline.
	chop($bits);

	$answer = 2 ** $bits ;

	print($bits, " bit is ",$answer,"\n");
}

else {
	print ("Wacky kind of \"number\" for this prog....\n");
}
