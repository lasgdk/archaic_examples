#!/bin/sh

#Script til kontrol og lagring af backup
#Lars Sommer, spam@lasg.dk
#Version Dato Note
#0.1 310105 Intet virker, men bygger en masse rod op
#0.2 010205 Nu virker det rent faktisk, til home_og_www

#LICENS: Scriptet er udgivet under GPL

#TODO: De tre ting der sker i scriptet, boer laves til tre funktioner, saa det hele fylder meget mindre.
#Sammenligning og flytning for B2 og B3 skal laves

#Idet home_og_www, system_konf_og_var og system_komplet er langt at skrive
# kalder jeg dem hhv b1, b2 og b3 i stedet.

#Saet nogle variable til eventuelle backupfiler
B1=`ls -l ../backup_indbakke/ | awk '{print $8}' | grep "200[0-9]*_backup_home_og_www.tar.gz" | tail -n 1` 
B2=`ls -l ../backup_indbakke/ | awk '{print $8}' | grep "200[0-9]*_backup_system_konf_og_var.tar.gz" | tail -n 1`
B3=`ls -l ../backup_indbakke/ | awk '{print $8}' | grep "200[0-9]*_backup_system_komplet.tar.gz" | tail -n 1`


#Saet variable med navne paa backup i backup_lager.
#tail er blot med som sikkerhed. Der boer kun eksistere en fil med det navn den soeger
B1_LAGER=`ls -l ../backup_lager/ | awk '{print $8}' | grep "200[0-9]*_backup_home_og_www.tar.gz" | tail -n 1`
B2_LAGER=`ls -l ../backup_lager/ | awk '{print $8}' | grep "200[0-9]*_backup_system_konf_og_var.tar.gz" | tail -n 1`
B3_LAGER=`ls -l ../backup_lager/ | awk '{print $8}' | grep "200[0-9]*_backup_system_komplet.tar.gz" |tail -n 1`

if [ $B1 ]; then
	B1_STOR=`ls -l ../backup_indbakke/${B1} | awk '{print $5}'`
	B1_LAGER_STOR=`ls -l ../backup_lager/${B1_LAGER} | awk '{print $5}'`
	if [ ! $B1_STOR = $B1_LAGER_STOR ]; then
		rm ../backup_lager/200[0-9]*_backup_home_og_www_gammel.tar.gz
		mv ../backup_lager/${B1_LAGER} ../backup_lager/`echo ${B1_LAGER} | grep -o "200[0-9]*_backup_home_og_www"`_gammel.tar.gz
		mv ../backup_indbakke/${B1} ../backup_lager/
	fi
else
	#backup_home_og_www skal vaere der hver uge. hvis ikke, send admin en mail
	#mail -s "Backuppen hos `hostname` fandt ikke home_og_www i denne uge!" lasg@lasg.dk
	echo "TEMPECHO: home_og_www ikke fundet!"
fi

#OVENSTAAENDE PROCDEDURE SKAL GENTAGES FOR B2 OG B3 HER !!

rm -rf ../backup_lager/*

