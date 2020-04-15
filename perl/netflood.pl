#!/usr/bin/perl
#lortekode af lasg
use IO::Socket;

$sock = IO::Socket::INET->new(Proto=>"tcp", PeerAddr=>"172.16.17.6", PeerPort=>"445")
or die "Connection error\n";

$count=0;

while ($count < 5000){

print $sock "0x00\r\n\r\n";

$count++;
}

while ($answer = <$sock>) {
	print $answer;
}
close($sock);

