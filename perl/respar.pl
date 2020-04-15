#!/usr/bin/perl

#Lars Sommer, lasg@lasg.dk, 2006-10-20

#Perl example for calculating electronic resistors in parallel
#Not very useful, but just an example made 'cause someone asked howto 
# use "||" as delimiters.

use strict;
use warnings;
use diagnostics;

my @resistors=split(/\|\|/,$ARGV[0]);
my $antal=@resistors;
my $result=0;

for (my $i=0; $i<$antal; $i++){
	$result+=1/$resistors[$i];
}

$result=1/$result;

print $result ."\n";
