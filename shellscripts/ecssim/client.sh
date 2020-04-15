#!/bin/sh

#Copyright Lars Sommer, larss@es.aau.dk
#Client for ECS

# This script inserts elevator requests in the queue.
# The request line is in this form:
# ID FROM_LEVEL UP/DN(1/0) TO_LEVEL REQUEST_PLACED_TIME


ID=`cat register_id_req.txt` &&
echo `expr ${ID} + 1` > register_id_req.txt &&

DATE=`date -j -f "%a %b %d %T %Z %Y" "\`date\`" "+%s"` &&

#      level direction destination
echo "${ID} $1 $2 $3 ${DATE}"
echo "${ID} $1 $2 $3 ${DATE}" >> queue_req.txt


