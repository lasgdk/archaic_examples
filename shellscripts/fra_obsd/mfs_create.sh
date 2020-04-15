#!/bin/sh

#Lars Sommer, lasg@lasg.dk, 31-07-04
#MFS-danner. Som standard laves et 10MB dir i /mnt/mfs. Størrelse kan ændres med $2 og sted med $3
#SIZE er målt i 512b blokke
SIZE="20480" 
MNTPOINT="/mnt/mfs"

if [ "$2" ]; then
    SIZE=$2
fi

if [ "$3" ]; then
   MNTPOINT=$3
fi

if [ ! -e "$MNTPOINT" ]; then
	sudo mkdir $MNTPOINT
fi

sudo mount_mfs -s $SIZE swap $MNTPOINT

echo
echo "MFS-danner afsluttet."
echo
