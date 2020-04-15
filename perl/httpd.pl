#!/usr/bin/perl

use IO::Socket;
my $sock=new IO::Socket::INET (Listen    => 1,
                                 LocalAddr => 'localhost',
                                 LocalPort => 1338,
                                 Proto     => 'tcp');
die unless $sock;
$huge="A" x 1100000;
$|=1;
print "YAY\n";
$z=$sock->accept();
print "connection!!1!\n";
do
{
	$ln=<$z>;
	print $ln;
	chomp $ln;
	
	if (($ln eq "")||($ln eq "\n")||($ln eq "\r"))
	{
		print "responses\n";
		print $z "HTTP/1.1 200 OK\r\nServer: X3 1.0\r\nContent-Type: $huge\r\nConnection: close\r\n\r\ndone";
		close($z);
		exit;
	}
} while (true);

