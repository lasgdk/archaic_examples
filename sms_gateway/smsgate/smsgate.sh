#!/bin/sh

case $1 in
	(login)
		smsgate_login
	;;
	(ping)
		smsgate_ping
	;;


login_result=`./login.pl`

session_id=`echo ${login_result} | grep -o "[0-9a-f]\{32\}"`

if [ ! ${session_id} ];then
	echo "ERROR: Auth error"
	exit 1
fi
echo "+OK: Auth completed"

ping_result=`./ping.pl ${session_id}`

ping_status=`echo ${ping_result} | grep -c "OK: "`

if [ ${ping_status} = 0 ];then
	echo "ERROR: Ping error"
	exit 1
fi
echo "+OK: Ping completed"

