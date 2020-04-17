#!/usr/bin/perl

#Fjern session_id fra output senere

use strict;
#use noget ala IO::Socket, der gir SSL;

my $host = "api.clickatell.com";
my $api_id = "2220332";
my $user = "leonsoren";
my $count = 0;
my $session_id = 0;
my $ping_result = 1;

while ( $session_id == 0  && $count < 5 )
{
	$session_id = &auth;
	if( $session_id != 0 )
	{
		print "+OK auth $session_id\n";
	}
	else
	{
		print "-ERR Auth failed. Retrying $count of 4....\n";
	}
	$count++;
}
if( $session_id == 0 )
{
	print "-ERR Could not auth. exitting...\n";
	exit 1;
}


while( $ping_result != 0 && $count < 5)
{
	$ping_result = &ping($session_id);
	if( $ping_result == 0 )
	{
		print "+OK ping\n";
	}
	else
	{
		print "-ERR Could not ping. Retrying $count of 4...\n";
	}
	$count++;
}
if( $ping_result != 0 )
{
	print "-ERR Could not ping. exitting...\n";
	exit 1;
}
	
sub auth{
	print "+INFO Trying to login. Returning 0 or 1\n";
#If login works, grep for the session_id. Return this, so we can use it.
	if( "ok" eq "ok" )
	{
		return "1234509876adfecb1230495867";
	}
	else
	{
		return 0;
	}
}


sub ping{
	if( ! $_[0] )
	{
		print "-ERR Session_id not set, auth before pinging.\n";
		return 1;
	}
	print "+INFO Trying to ping with session_id $_[0]\n";
	if( "ok" eq "ok" )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
	


