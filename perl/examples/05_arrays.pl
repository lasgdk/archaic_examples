#!/usr/bin/perl

@myarray=("glyp","glop","two",3);

print $myarray[1]."\n";

foreach (@myarray){
	print $_."\n";
}

foreach $copyhere (@myarray){
	print $copyhere."\n";
}
