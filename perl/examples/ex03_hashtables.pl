#!/usr/bin/perl

%myhash=("goodkey","somevalue","otherkey","lastvalue");

print "Keys:\tValues:\n";

@keylist=keys %myhash;
@valuelist=values %myhash;

$actkey=0;
while ($keylist[$actkey]){
	print $keylist[$actkey]."\t".$valuelist[$actkey]."\n";
	$actkey++;
}

