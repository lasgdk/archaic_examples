#!/usr/local/bin/perl
# Script by Lars Sommer, <lasg@lasg.dk>

use strict;
use warnings;
use diagnostics;
use POSIX;

my $file = $ARGV[0];

if(!defined($ARGV[0]))
{
	die "Give me a filename as arguement";
}

open (FP,"$file") || die "Cannot open file $file for reading";
while( <FP> )
{
	print $_;
}

close(FP);

