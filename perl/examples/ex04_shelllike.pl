#!/usr/bin/perl
while ($c ne "exit"){
	print "Command me> ";
	chomp($c=<STDIN>);
	system $c;
}
