#!/usr/bin/perl

use IO::Socket;

while( true )
{


my $sock=new IO::Socket::INET (Listen    => 1,
                                 LocalAddr => 'localhost',
                                 LocalPort => 44444,
                                 Proto     => 'tcp');
die unless $sock;
print "Ready...\n";


$z=$sock->accept();
print "Connection from client\n";

	print $z "Ready for data\n";

	$sz=<$z>;
	print $sz;	
	if( $sz =~ /^Level . going ../ )
	{
		print $z "Request received. Processing..\n";
		sleep(1);
		#call external script
		$in_elevator="1";
		print $z "Ok. Enter new level\n";
		while( $in_elevator eq "1" )
		{
			$sz=<$z>;
			print $sz;	
			if(  $sz =~ /^Level ./ ) 
			{
				print $z "moving...\n";
				sleep(1);
				print $z "moving more...\n";
				sleep(1);
				print $z "At level 8\n";
			        print $z "Have a nice day!\n";
				sleep(1);
				$in_elevator="0";
				close($z);
			}
		}
	}
}

