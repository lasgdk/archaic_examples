#!/bin/sh
#Lars Sommer, lasg@lasg.dk

VALG=`xmessage -print -center -buttons Fortryde,'Lukke maskinen ned','Genstarte maskinen','Lukke X' -default Fortryde "Velkommen til maskinnedlukker for X  -  Hvad vil du?"`


case $VALG in
	("Lukke maskinen ned")
		sudo /sbin/shutdown -p now
		;;
	("Genstarte maskinen")
		sudo /sbin/reboot
		;;
	("Lukke X")
		kill `ps ax | grep "X :0" | awk '{print $1}'`
		;;
	(*)
		exit 0
		;;
esac
