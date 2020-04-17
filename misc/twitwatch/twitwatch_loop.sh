#!/bin/sh

#while [ true ]; do
	ISITRUNNING=`ps ax|grep twitwatch_crawler|grep -c sh`
	if [ "$ISITRUNNING" -eq "0" ]; then
		sh twitwatch_crawler.sh &
	fi
#	sleep 300
#done

