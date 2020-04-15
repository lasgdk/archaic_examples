#!/bin/sh

HOST=`hostname`

#extract "inet IPADDR netmask"
IP=`ifconfig fxp0|grep -o "inet .* netmask"| grep -o "[0-9].* "`

#mail it to myself
echo "${HOST} is at ${IP}"|mail -s "${HOST} is at ${IP}" lasg@lasg.dk

#if sendmail is borken, inject in some httpd logfile
fetch http://norst.dk/THIS_IS_${HOST}_REVEALING_MY_IP_${IP}

