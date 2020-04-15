#!/usr/bin/perl

use strict;
use warnings;
use diagnostics;

use IO::Socket;

my $mailserver="mailhost.tnb.aau.dk";
my $from_adr="j\@test.dk";
my $from_name="Test testeren";
my $to_adr="lasg\@lasg.dk";
my $to_name="Dig selv";
my $subject="Teste teste";
my $message="Hej hej med dig\r\nHilsen mig";

my $sock = IO::Socket::INET->new(Proto=>"tcp", PeerAddr=>$mailserver, PeerPort=>"25")
or die "Connection error\n";

my $count=0;

while ($count < 1){

print $sock "HELO localhost\r\nMAIL FROM: <$from_adr>\r\nRCPT TO: <$to_adr>\r\nDATA\r\nFrom: $from_name <$from_adr>\r\nTo: $to_name <$to_adr>\r\nSubject: $subject\r\nX-Mailer: Microsoft Office Outlook 11\r\nX-MimeOLE: Produced By Microsoft MimeOLE V6.00.2900.2869\r\n$message\r\n.\r\nquit\r\n";

$count++;
}

while (my $answer = <$sock>) {
	print $answer;
}
close($sock);

