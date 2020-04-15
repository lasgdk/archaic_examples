#!/bin/sh

#Lars Sommer, lasg@lasg, 31-07-04

KRYPTFIL=$HOME/test.kfs
KRYPTMNT=/mnt/kryptfs
KRYPTDEV=/dev/svnd0c

sudo /usr/sbin/vnconfig -ck -v $KRYPTDEV $KRYPTFIL &&
sudo /sbin/mount -f $KRYPTDEV $KRYPTMNT &&
df -h | grep $KRYPTMNT &&
echo "Nu er $KRYPTFIL korrekt monteret i $KRYPTMNT"
echo

