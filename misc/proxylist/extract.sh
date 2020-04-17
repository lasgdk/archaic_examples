#!/bin/sh

#This script searches for ip-adresses in files, and puts these into one file.
#Then it sorts and uniqes them.

#Made for running on FreeBSD. Tested on OpenBSD, failing on the sort. Should be fixed easy.

#TODO: Perhaps an idea to timestamp the list.txt in the filename...

grep -o "[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}" * | cut -d : -f 2 > list.total &&

sort -g list.total | uniq > list.txt &&

rm *.shtml
rm list.total
