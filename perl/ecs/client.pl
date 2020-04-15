#!/usr/bin/perl
use IO::Socket;

$sock = IO::Socket::INET->new(Proto=>"tcp", PeerAddr=>"localhost", PeerPort=>"44444")
or die "Connection error\n";

while( true )
{
$fromsock=<$sock>;
print $fromsock;
if ($fromsock eq "Ready for data\n")
	{
		print $sock "Level 4 going up\n";
		while( true )
		{
			$fromsock=<$sock>;
			print $fromsock;
			if( $fromsock eq "Request received. Processing..\n" )
			{
				while( true )
				{
					$fromsock=<$sock>;
					print $fromsock;
					if ($fromsock eq "Ok. Enter new level\n")
					{
						print $sock "Level 8\n";
						while( true )
						{
							$fromsock=<$sock>;
							print $fromsock;
							if( $fromsock eq "Have a nice day!\n" )
							{
								exit;
							}

						}

					}
				}

			}
			print "Waiting for answer\n";
			sleep(1);
		}

	}

print "Trying to connect to controller...\n";
sleep(1);

}

close($sock);
