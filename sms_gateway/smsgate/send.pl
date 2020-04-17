#!/usr/bin/perl

use IO::Socket;

#$host = $ARGV[0];
#$forumdir = $ARGV[1];
#$thread = $ARGV[2];

$host = "api.clickatell.com";
$session_id = "2c20f3d136700ba9de0a2348c8d96000";
$string = "/http/ping?session_id=${session_id}";

$sock = IO::Socket::INET->new(Proto=>"tcp", PeerAddr=>"$host", PeerPort=>"80")
or die "Connection error\n";

print $sock "GET $string HTTP/1.1\r\nHost: $host\r\nConnection: close\r\n\r\n";

while ($answer = <$sock>) {
	print $answer;
#	$limitIndex = index $answer, $limiter;
#	if ($limitIndex >= 0) {
#		$succes = 1;
#		$urlIndex = index $answer, "href";
#		if ($urlIndex < 0){
#			$answer = substr($answer, length($limiter));
#			$length = 0;
#			while (length($answer) > 0) {
#				$nex = index($answer, $limiter);
#				if ($nex > 0) {
#					push(@array, substr($answer, 0, $nex));
#					$answer = substr($answer, $nex + length($limiter), length($answer));
#				} else {
#					$answer= "";
#				}
#			}
#		}
#	}
}

close($sock);

}

