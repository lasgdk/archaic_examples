#!/usr/bin/perl

sub subhello{
	print "Hello World!\n";
}
&subhello;


#How to parse vars to a function:

$varone="Stuff";
&greedy($varone,"Morestuff");

sub greedy{
	print $_[0]."\n".$_[1]."\n";
}


#Use my-word to set var private to a function.

$somevar=5;
print $somevar;
&privvar(3);
print $somevar;
sub privvar{
	my $somevar=$_[0];
}


#return value from function

$fromsub=&givesome;
print $fromsub;
sub givesome{
	return "something nice";
}
