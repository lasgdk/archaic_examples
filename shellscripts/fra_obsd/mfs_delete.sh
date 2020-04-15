#!/bin/sh

#Lars Sommer, lasg@lasg.dk, 31-07-04
#MFS-slette-program. Afmonterer og sletter monteringspunktet. Som standard /mnt/mfs
#Al data bliver naturligvis tabt, da det kører i RAM. Brug derfor evt. mfs_backup.sh først.

MNTPOINT="/mnt/mfs"

if [ "$2" ]; then
   MNTPOINT=$2
fi

sudo umount $MNTPOINT
sudo rm -rfi $MNTPOINT

echo
echo "MFS-slette-programmet afsluttet."
echo
