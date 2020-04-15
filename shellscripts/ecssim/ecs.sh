#!/bin/sh

#Copyright Lars Sommer, larss@es.aau.dk
# ECS, Elevator Control System
# A simple elevator simulator implementation

#Documentation: no.

LEVEL=1
DIRECTION=1

while( true );do

RUN_ID=`cat register_id_run.txt`
echo `expr ${RUN_ID} + 1` > register_id_run.txt &&

while [ "`grep -c "^${RUN_ID} " queue_req.txt`" = "0" ]
do
	echo "Waiting at level ${LEVEL} for client to insert data into queue"
	sleep 1
done

ACTUAL=`grep "^${RUN_ID} " queue_req.txt`
sed s/"^${RUN_ID} .*"// queue_req.txt > queue.tmp &&
mv queue.tmp queue_req.txt

echo $ACTUAL
ACTUAL_USER_ID=`echo ${ACTUAL} | cut -d " " -f 1` 
ACTUAL_USER_LEVEL=`echo ${ACTUAL} | cut -d " " -f 2` 
ACTUAL_USER_UPDN=`echo ${ACTUAL} | cut -d " " -f 3` 
ACTUAL_USER_TO=`echo ${ACTUAL} | cut -d " " -f 4` 
ACTUAL_USER_REQTIME=`echo ${ACTUAL} | cut -d " " -f 5` 

#Move elevator to users level:
while [ "${LEVEL}" -ne "${ACTUAL_USER_LEVEL}" ];do
	echo -n "Elevator is at level ${LEVEL} moving "
	if [ "${LEVEL}" -le "${ACTUAL_USER_LEVEL}" ];then
		LEVEL=`expr ${LEVEL} + 1`
		DIRECTION=1
		echo "UP"
	else 
		LEVEL=`expr ${LEVEL} - 1`
		DIRECTION=0
		echo "DOWN"
	fi
	#Check if any user is on this level, and wants to go the same direction
	if [ "`grep -c "^[0-9].* ${LEVEL} ${DIRECTION} " queue_req.txt`" != "0" ];then
		echo "Picking up an user here at level ${LEVEL}"
	fi

	sleep 1
done


sleep 1
done

