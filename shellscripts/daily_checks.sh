#!/bin/sh

# Daily check script for miscellaneous system checks on my servers.
# Lars Sommer, lasg@lasg.dk, 2010-01-27, revision 1

# It can probably all be done in Nagios or such, but this was plain and simple.
# Please inform me if you have any nice additions. :)


### General reporting function used by the other checks
func_report()
{
	echo "Reporting: $REPORT"
	echo $REPORT|mail -s "Important info from $HOSTNAME daily checkscripts!" -c "lasgdk@gmail.com" info@lasg.dk
	echo $REPORT|logger
	echo "Possible important failure message from $HOSTNAME. Check your email." | /usr/local/bin/gnokii --sendsms 23966300
}


### Check SMART status of harddrives:
#List devices as ad0, ad10, ad11, but not partitions like ad0s1 and so forth..
DEVICES=`ls /dev/ad*|grep -v s` 
for ACTUAL in $DEVICES; do
	STATUS=`smartctl -H ${ACTUAL} |grep -c PASSWD`
	if [ $STATUS != "1" ]; then
		REPORT=`smartctl -a ${ACTUAL}` &&
		func_report &&
		unset REPORT
	fi
done


### Check geom mirror status:
GMIRROR_STATUS=`gmirror status -s`
GMIRROR_COUNT=`echo ${GMIRROR_STATUS}|wc -l`
GMIRROR_COMPLETE=`echo  ${GMIRROR_STATUS}| grep -c "COMPLETE"`
if [ $GMIRROR_COUNT != $GMIRROR_COMPLETE ]; then
	REPORT=`gmirror status` &&
	func_report &&
	unset REPORT
fi


### Check for over filled partitions:
#Counting number of partitions with negative remaining diskspace
ANY_MINUS=`df -h | grep -c "-"`
if [ $ANY_MINUS != "0" ]; then
	REPORT=`df -h` &&
	func_report &&
	unset REPORT
fi




