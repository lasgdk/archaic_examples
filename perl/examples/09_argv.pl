#!/usr/bin/perl

print $ARGV[0];
print $ARGV[1];

foreach (@ARGV){
	print $_."\n";
}
