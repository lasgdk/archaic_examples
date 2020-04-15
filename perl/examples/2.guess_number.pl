#!/usr/local/bin/perl
#Lars Sommer, lasg@lasg.dk

#Set min and max numbers
$min = 1;
$max = 20;

#Gets a random int between 1 and 20
$number = int(rand($max)) + $min;

print("Guess a number between ",$min," and ",$max,"\n");

#the until statement, is like an inversed while. 
#this could as be expressed:
#while( $number != $guess ){
until( $number == $guess ){

	print("\nGuess: ");
	$guess = <STDIN>;

	$guesscount++;

	if ( $guess < $number ){
		print("Too low!\n");
	}
	if ( $guess > $number ){
		print("Too high!\n");
	}
}

print("\nHooray! You guessed the number ",$number," in ",$guesscount," guesses\n");
 

