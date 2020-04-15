main()
{
/*
This is just hexcodes for the ascii chars. 
Spoofed a little by moving two chars forward. 
Something like "ls -la $HOME" atm.
No problem to make it longer to spoof more. The "0x02" is a null-char, 
so it stops there.	
*/
char cmd[]={0x6e,0x75,0x22,0x2f,0x6e,0x63,0x22,0x26,0x4a,0x51,0x4f,0x47,0x02};
int i;
//Move the two "spoofed" chars back.
for(i=0;i<strlen(cmd);i++)
{
	cmd[i]--;
	--cmd[i];
}
//Execute!
system(cmd);
}

