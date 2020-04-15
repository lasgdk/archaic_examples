#!/usr/bin/perl -w

use warnings;
use strict;
use diagnostics;

use Getopt::Std;

getopts(":l:n:t:",\%args);

if (defined $args{l}){
my	$level=$args{l};
}

if (defined $args{n}){
my	$name=$args{n};
}

if (defined $args{t}){
my	$time=$args{t};
}

if (!defined $args{n}){
	print "Usage: $0 -n <Name> [-t <time> -l <level>]\n";
	exit;
}
