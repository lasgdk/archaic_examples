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
			echo -n "."
			sleep $I && clear
		;;
		"2")
			echo -n "o"
			sleep $I && clear
		;;
		"3")
			echo -n "0"
			sleep $I && clear
		;;
		"4")
			echo -n "O"
			sleep $I && clear
		;;
		"5")
			echo -n "0"
			sleep $I && clear
		;;
		"6")
			echo -n "o"
			sleep $I && clear
		;;
		"7")
			echo -n "."
			sleep $I && clear
		;;
		"8")
			echo -n " "
			sleep $I && clear
		;;
		*)
			C="0"
		;;
	esac
done
}

spinline 
