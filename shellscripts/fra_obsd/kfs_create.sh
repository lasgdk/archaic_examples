#!/bin/sh

#Lars Sommer, lasg@lasg.dk, 31-07-04

#Med mindre du har en bedre idé til enheden, skal du ikke ændre VNODE.
#KRYPTFIL er self. der hvor selve filsystemets fil skal ligge.
#SIZE er størrelsen af filsystemet målt i kilobytes.
VNODE=/dev/svnd0c
KRYPTFIL=$HOME/test.kfs
SIZE=15000

/bin/dd if=/dev/zero of=$KRYPTFIL bs=1024 count=$SIZE &&
sudo /usr/sbin/vnconfig -ck -v $VNODE $KRYPTFIL &&
RVNODE=`/bin/echo $VNODE | /usr/bin/sed s/svnd/rsvnd/` &&
sudo /sbin/newfs $RVNODE &&
sudo /usr/sbin/vnconfig -u -v $VNODE &&
echo "Færdig. Alt gik godt." &&
echo "Du kan nu montere dit $SIZE kb store filsystem med kryptfs_mount.sh"
