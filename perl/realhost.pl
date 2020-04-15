#!/usr/bin/perl -w

use strict;
use Socket;
	
if (!defined($ARGV[0])) {
	use File::Basename;
	my $scriptname = basename($0);
	print "Real hostname lookup\n";
	print "--------------------\n";
	print "\n";
	print "Usage:\n";
	print "$scriptname <host>\n";
	print "\n";
	print "<host>   - The hostname to lookup (eg. www.chanoandersen.dk)\n";
	print "\n";
	print "Copyright 2004 - Chano Andersen.\n";
	exit(0);
}

my $hostname = $ARGV[0];
print "Hostname: $hostname\n";
$| = 1;
my $ip = inet_ntoa(inet_aton($hostname));
print "Host IP: $ip\n";
my $realhost = gethostbyaddr(inet_aton($ip),AF_INET);
	print "Real hostname: ";
if (!defined($realhost)) {
	print "[Not available]"
} else {
	print "$realhost";
}
print "\n";

