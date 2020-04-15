#!/usr/bin/perl

#hashes is arrays with keys as identifiers instead of numbers.

%myhash=("goodkey","somevalue","otherkey","lastvalue");
print $myhash{"otherkey"}."\n";

#some build in hash-functions:

@keylist=keys %myhash;

foreach (@keylist){
	print $_."\n";
}

#same can be done with the function values.

delete $myhash{"goodkey"};
print $myhash{"goodkey"};
