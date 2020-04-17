#!/bin/sh

NUM=$1
MSG=$2

LEN=`echo $MSG|wc -c`

echo "$MSG" | sudo gnokii --sendsms 45${NUM} -l $LEN 2>sms.log &&

rm sms.log

