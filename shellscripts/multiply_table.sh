#!/bin/sh

#Table of multiplication
#Lars Sommer, 2005-04-08

#Go make this check better, if you think it sucks.
if [ ! $1 ]; then 
	echo "Please give me a not too high positive integer..."
	exit 1
fi

echo "Here you got a multiplication table with $1 rows and cols.."

x=1
while [ $x -le $1 ]; do
	y=1
	while [ $y -le $1 ]; do
		echo -ne `expr $x \* $y ` "\t"
		y=`expr $y + 1`
	done
	echo
	x=`expr $x + 1`
done
