#!/bin/sh
c=0

while [ "$c" != "255" ]
do
	sudo ./par $c 0
echo $c
	sleep 0.01
	c=`expr $c + 1`
done
