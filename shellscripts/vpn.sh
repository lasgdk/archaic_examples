#!/bin/sh

#Til linux til ciscos vpn client for linux.
#Lavet til brug paa AAU i debian 3.1

echo "Opstarter VPN-klient til AAU..." &&
sudo /etc/init.d/vpnclient_init start 
echo "Klientprogram opstartet. Forbinder..." &&
vpnclient connect but-1-nov04 user larss &&
echo "Færdig."


