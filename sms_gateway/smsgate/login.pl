#!/usr/bin/perl

use IO::Socket;

$host = "api.clickatell.com";
$api_id = "2220332";
$user = "leonsoren";
$password = "insertsecretpassword";
$string = "/http/auth?api_id=${api_id}&user=${user}&password=${password}";

$sock = IO::Socket::INET->new(Proto=>"tcp", PeerAddr=>"$host", PeerPort=>"80")
or die "Connection error\n";

print $sock "GET $string HTTP/1.1\r\nHost: $host\r\nConnection: close\r\n\r\n";

while ($answer = <$sock>) {
	print $answer;
}
close($sock);

