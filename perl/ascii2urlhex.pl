#!/usr/bin/perl

#Convert ascii to URLish hex. (http://en.wikipedia.org/wiki/Percent-encoding)
#Lars Sommer, lasg@lasg.dk, 2008-06-12, BEERWARE

use warnings;
use strict;

if ($#ARGV<0){
	print "Give an URL or part of an URL as an arguement.\n";
	exit(1);
}

my $hex = unpack("H*",$ARGV[0]);
$hex =~ tr/a-z/A-Z/;

for (my $i = 0; $i < length($hex); $i += 2) {
        print "\%".substr($hex,$i,2);
}
print "\n"; 

