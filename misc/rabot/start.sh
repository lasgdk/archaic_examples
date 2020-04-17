#!/bin/sh

#Start script for Rabot 0.1
#Go read the rabot.pl

# Syntax for rabot.pl:
# ./rabot.pl <server> <port> <nickname> <username> <realname> <channel> <controlchannel> <startcode> <writetimes> <message>
# ./rabot.pl irc.idiots.com 6667 Rabot rabot "Real Rabot" #rabot #rabotcontrol startfun 5 "Hello World!"

c=0
while [ "$c" != "100" ];do
torify perl rabot.pl 89.150.126.234 6667 rabot rabot rabot \#rabot \#rabotcontrol start 100 "Hello world!" &
# Use torify to tunnel rabot through TOR
#	torify ./rabot.pl irc.idiots.com 6667 rabot rabot rabot \#rabot \#rabotcontrol start 10 "Hello world!" &
	sleep 10
	c=`expr $c + 1`
done


