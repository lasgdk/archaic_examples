#!/usr/bin/perl

use strict;
use warnings;
use diagnostics;

my $start=$ARGV[0];
my $stop=$ARGV[1];
if( !$start )
{
	$start=0;
}
if( !$stop )
{
	$stop=10;
}


print "<html><head></head><body>\n";
for (my $i=$start;$i<$stop;$i++){
	if( $i%100==0 ){
		print "<hr />\n";
	}
	print "&#".$i." ".$i."<br />\n";
}
print "</body></html>";
