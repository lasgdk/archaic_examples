#!/bin/sh
#2006-01-27 Lars Sommer, lasg@lasg.dk
#Tester om indtastede CPR-nummer er gyldigt.

if [ ! ${10} ];then
	echo "Syntax: ./prog d d m m y y a b c d"
	exit 1
fi

sum=`expr $1 \* 4 + $2 \* 3 + $3 \* 2 + $4 \* 7 + $5 \* 6 \
 + $6 \* 5 + $7 \* 4 + $8 \* 3 + $9 \* 2 + ${10} `
mod=`expr $sum % 11`

if [ "$mod" = "0" ]; then 
	echo "Valid"
	exit 0
fi
exit 1
