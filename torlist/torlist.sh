#!/bin/sh

# Torlist maker v.1.0 2006-01-25

# <lasg@lasg.dk> wrote this file.

#This script is used for making a list of TOR-nodes. 
#It takes two big lists, formats, concatenates and sorts them.
#Designed for FreeBSD6.0. If YOU do a Linux-version, please mail me.


#Download two different lists of tor-servers to torlist1.txt and torlist2.txt
wget "http://serifos.eecs.harvard.edu/cgi-bin/exit.pl?textonly=1&addr=1" \
 -O torlist1.txt &&
wget http://proxy.org/tor.shtml -O torlist2.txt &&
echo "+OK Downloads done"

#In the first list, ip's are located in coloum 5. 
#After the awk, we also got some empty lines to grep away.
#We store the results in torlist_all.txt
awk '{ print $5 }' torlist1.txt | grep -v \^\$ > torlist_all.txt &&

#The second list is html. We grep for ip-addresses, 
# and appends the results to torlist_all.txt
grep -o "[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}\.[0-9]\{1,3\}" torlist2.txt \
 >> torlist_all.txt &&

#We sort the torlist_all.txt numerical,
# and take all unique values into torlist_finish_raw.txt
sort -g torlist_all.txt | uniq > torlist_finish_raw.txt &&
echo "+OK Raw list done" &&

#We want a list usable in php-applications,
# so we append some " ", to the entries.
cat torlist_finish_raw.txt | sed s/^/\"/ | sed s/\$/\",/ > \
 torlist_finish_usable.txt &&
echo "+OK Formatted list done" &&

#And at last some cleaning up
rm torlist1.txt torlist2.txt torlist_all.txt &&
echo "+OK Done"

