#!/usr/bin/perl

print "Enter multiple lines of text, press ctrl+d to end.\n";
@text=<STDIN>;
foreach(@text){
	print $_;
}
