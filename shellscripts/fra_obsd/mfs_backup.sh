#!/bin/sh

#Lars Sommer, lasg@lasg.dk, 31-07-04
#MFS-backup-script. Som standard backes /mnt/mfs op til $HOME/mfs_backup.tar.gz
#Du kan angive andet med brug af $2 og $3. M�ske burde der byttes om p� dem, da man oftere �ndrer backup-navn end mountdir. Det m� du selv g�re.

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
