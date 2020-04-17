#!/usr/bin/perl

use IO::Socket;

$session_id = $ARGV[0];

$host = "api.clickatell.com";
$string = "/http/ping?session_id=${session_id}";

$sock = IO::Socket::INET->new(Proto=>"tcp", PeerAddr=>"$host", PeerPort=>"80")
or die "Connection error\n";

print $sock "GET $string HTTP/1.1\r\nHost: $host\r\nConnection: close\r\n\r\n";

while ($answer = <$sock>) {
	print $answer;
}

close($sock);

