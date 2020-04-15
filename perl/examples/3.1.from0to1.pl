#!/usr/local/bin/perl

#Quest: 
#Print the numbers from 0 to 1,
# which have only one digit after the decimal place.

until ( $count == 10 ){
	$num = $count / 10;
	print($num,"\n");
	$count++;
}


