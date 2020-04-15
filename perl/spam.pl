#!/usr/bin/perl
#lortekode af lasg
use IO::Socket;

$sock = IO::Socket::INET->new(Proto=>"tcp", PeerAddr=>"zattoo.com", PeerPort=>"80")
or die "Connection error\n";

$count=0;

while ($count < 3){

#print $sock "POST zepcom.dk/order_sa.php HTTP/1.1\r\nHost: zepcom.dk\r\nUser-Agent: Mozilla/5.0\r\nKeep-Alive: 300\r\nConnection: keep-alive\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: 3\r\n\r\nlal";

print $sock "POST zattoo.com/login HTTP/1.1\r\nHost: zattoo.com\r\nUser-Agent: Mozilla/5.0\r\nKeep-Alive: 300\r\nConnection: keep-alive\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: 39\r\n\r\nemail=lasg\@lasg.dk&submitted_forgotpass";

#system "sudo ifconfig fxp0 ether `/home/buf/bin/mac-maker`";

$count++;
}

while ($answer = <$sock>) {
	print $answer;
}
close($sock);

