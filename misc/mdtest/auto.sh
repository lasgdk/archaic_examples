#!/bin/sh

file=hest.list

line_no=0

while true
do
proccount=`ps ax | grep "/bin/sh ./gomd5.sh" | grep -v -c grep`
if [ $proccount -lt 7 ]; then 
	line_complete=`grep "^$line_no " ${file}`
	line_user=`echo ${line_complete}|awk -F \' '{ print $2 }'`
	line_mail=`echo ${line_complete}|awk -F \' '{ print $6 }'`
	line_hash=`echo ${line_complete}|awk -F \' '{ print $4 }'`
	line_user=`grep \^${line_no} ${file}|awk -F \' '{ print $2 }'`
#	echo $line_user $line_mail $line_hash
	./gomd5.sh $line_no $line_user $line_hash $line_mail &
	line_no=`expr $line_no + 1`
fi
done

