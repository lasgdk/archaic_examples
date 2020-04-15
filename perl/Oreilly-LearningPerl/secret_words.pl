#!/usr/local/bin/perl

# 060728, Lars Sommer, lasg@lasg.dk
# Chapter 1 example

$password_real = "test";

print "Type your username, or \"guest\" for guest-login:\n";
$username = <STDIN>;

#Eat the newline:
chomp($username);

if ($username eq "guest"){
	print "Guest login\n";
}
else {
	print "Okay $username, go input your password: ";
	$password_input=<STDIN>;
	chomp($password_input);
	if($password_input eq $password_real){
		print "Your are now logged in..\n";
	}
	else{
		print "Wrong password..\n";
	}

}


