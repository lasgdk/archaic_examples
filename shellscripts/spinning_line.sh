#!/bin/sh

spinline ()
{
I=1
C=0

while :
do
	C=`expr $C + 1`

	case $C in
		"1")
			echo -n "-\b"
			sleep $I
		;;
		"2")
			echo -n "\\ \b\b"
			sleep $I
		;;
		"3")
			echo -n "|\b"
			sleep $I
		;;
		"4")
			echo -n "/\b"
			sleep $I
		;;
		*)
			C="0"
		;;
	esac
done
}

spinline 
