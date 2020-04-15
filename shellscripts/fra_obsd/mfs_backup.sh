#!/bin/sh

#Lars Sommer, lasg@lasg.dk, 31-07-04
#MFS-backup-script. Som standard backes /mnt/mfs op til $HOME/mfs_backup.tar.gz
#Du kan angive andet med brug af $2 og $3. Måske burde der byttes om på dem, da man oftere ændrer backup-navn end mountdir. Det må du selv gøre.

MNTPOINT="/mnt/mfs"
DESTPOINT="$HOME/mfs_backup.tar.gz"

if [ "$2" ]; then
   MNTPOINT=$2
fi

if [ "$3" ]; then
	DESTPOINT=$3
fi

tar -zcvf $DESTPOINT $MNTPOINT

echo
echo "MFS-Backup programmet er afsluttet."
echo
