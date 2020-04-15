#!/usr/local/bin/perl
use IO::Socket;

$nicknamerand = int(rand(8999)) + 1000;

$server = "chanoandersen.dk";
$port = "6667";
$nickname = "perlebot"; #."${nicknamerand}";
$username = "perlebot";
$realname = "Perl example by Lars Sommer";

$channel = "#frihed";

$sock = new IO::Socket::INET(PeerAddr => $server, PeerPort => $port, Proto => 'tcp') or die "Can't connect\n";

print $sock "NICK ${nickname}\r\n";
print $sock "USER ${username} 8 * :${realname}\r\n";

while ($input = <$sock>) {
    # Check the numerical responses from the server.
    if ($input =~ /004/) {
        # We are now logged in.
        last;
    }
    elsif ($input =~ /433/) {
        die "Nickname is already in use.";
    }
}

# Join the channel.
print $sock "JOIN $channel\r\n";

# Keep reading lines from the server.
while ($input = <$sock>) {
    chop $input;
    if ($input =~ /^PING(.*)$/i) {
        print $sock "PONG $1\r\n";
    }
    else {
        # Print the raw line received by the bot.
        print "$input\n";
    }
	if ($input =~ /PRIVMSG ${nickname} :cmd die/) {
		print $sock "QUIT :I got killed\r\n";
	}
	if ($input =~ /PRIVMSG ${nickname} :cmd op/) {
		print $sock "MODE #frihed +o lasg\r\n";
	}
	if ($input =~ /lasg!~emanresu@staff.dkirc.org JOIN :#frihed/) {
		print $sock "MODE #frihed +o lasg\r\n";
	}
	if ($input =~ /PRIVMSG ${nickname} :cmd say/) {
		print $sock "PRIVMSG #frihed :Hej verden!\r\n";
	}
}

