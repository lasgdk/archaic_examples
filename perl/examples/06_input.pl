#!/usr/bin/perl

$instuff=<STDIN>;
print $instuff;

#perhaps you want to remove trailing newline...

chomp($instuff=<STDIN>);
print $instuff;
