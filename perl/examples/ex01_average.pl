#!/usr/bin/perl

print "\n";
print "Average calculator example by Lars Sommer, lasg\@lasg.dk, 21-07-05\n\n";
print "I calculate the average of numbers you input\n";
print "Input an integer, press enter. Input stop to stop,\n";
print " and calculate. Input exit to instantly exit..\n\n";

$i=0;
while ($number ne "stop"){
	$i++;
	print "Enter number $i: ";
	chomp($number=<STDIN>);
	if ($number eq "exit"){
		print "\nBye bye..\n";
		exit 0;
	}
	push @total,$number;
}

if ($number eq "stop"){
	print "Calculating...\n";
	foreach (@total){
		$average+=$_;
	}
	$average/=($i-1);
	print "The average of your input is $average\n";
}
