#!/bin/sh

#Lars Sommer, lasg@lasg.dk, 31-07-04

KRYPTFIL=$HOME/kryptfs
KRYPTMNT=/mnt/kryptfs
KRYPTDEV=/dev/svnd0c

sudo /sbin/umount $KRYPTMNT
sleep 1 
sudo /usr/sbin/vnconfig -u -v $KRYPTDEV &&
echo "Nu er $KRYPTFIL korrekt afmonteret fra $KRYPTMNT"
echo

