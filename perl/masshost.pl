#!/usr/bin/perl -w

use strict;
use Socket;
	
if (!defined($ARGV[0])) {
	use File::Basename;
	my $scriptname = basename($0);
	print "Mass hostname lookup\n";
	print "--------------------\n";
	print "\n";
	print "Usage:\n";
	print "$scriptname <ip_base> <start_host> <end_host>\n";
	print "\n";
	print "<ip_base>    - The first 3 octets of every address in the\n";
	print "               range to be looked up. (Eg. 127.0.0)\n";
	print "<start_host> - The host to start from. (Eg. 1)\n";
	print "<end_host>   - The last host in the range (Eg. 255)\n";
	print "\n";
	print "Copyright 2004 - Chano Andersen.\n";
	exit(0);
}

my $base = $ARGV[0];
my $host = $ARGV[1];
my $last = $ARGV[2];

print "Address base: $base\n";
print "Starting host: $host\n";
print "Ending host: $last\n";
print "\n";
$| = 1;

while ($host < $last+1) {
	print "Looking up $base.$host..... ";
	print "Waiting...";
 	my $hostname = gethostbyaddr(inet_aton("$base.$host"),AF_INET);
	if (!defined($hostname)) {
 		$hostname = "No RDNS";
 	}
 	print "\b\b\b\b\b\b\b\b\b\b          \b\b\b\b\b\b\b\b\b\b";
 	print "$hostname\n";
 	$host = $host + 1;
}

