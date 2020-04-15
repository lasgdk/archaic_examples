#!/bin/sh

#Shellscript til backup af komplet fungerende OpenBSD
#Af Lars Sommer spam@lasg.dk
#Udgivet under GPL
#20050115 - Ver.0.1 - Virker faktisk udemaerket allerede. Kan dog fint forbedres. 
#20050116 - Ver.0.2 - Nu noejes jeg med ET script, i stedet for tre.

#Variable for brugeren:
#Den fulde sti til tar
STITILTAR="/bin/tar"


#KONTROLLER OM VI MAA/KAN KOERE TAR BOER KOMME IND HER!

#Vi kan fikse kontrollen af parametrene og selve backuppen paa mange maader. 
#Jeg kom umiddelbart paa tre forskellige loesninger med if-then og case, 
# og jeg bruger blot den foerste

#Kontroller om brugeren har indtastet brugbart argument,
# og udskriv hjaelpefil hvis hun ikke har.
if [ ! "$1" = "system_komplet" ]; then
	if [ ! "$1" = "system_konf_og_var" ]; then
		if [ ! "$1" = "home_og_www" ]; then
			echo -e "Du skal bruge et af argumenterne: \n system_komplet \n system_konf_og_var \n home_og_www"
			exit 1
		fi
	fi
fi

#Ser om vi er root (uid=0)
if [ ! "$UID" = "0" ]; then
	echo "Du skal vaere root for at koere dette script!"
	exit 1
fi

#Vi arbejder fra /
cd /home/knoppix/rootsystem

#Fortaeller lige hvor meget plads vi har.
#Hvis DU gider skrive den om saa den foerst beregner hvor meget plads den ialt skal bruge
#f.eks. ved at sammenlaegge alle stoerrelser af alle filer
#og saa brokke sig hvis der ikke er plads nok, maa du meget gerne dette!
FRIROOTPLADS=`df | grep "/"$ | awk '{print $4}'`
echo "Du har ${FRIROOTPLADS}kb plads tilbage i /"

#Nogle flere variable (dem behoever du naeppe aendre)
DATO=`date +%Y%m%d-%H%M`
MAPPE=backup_${1}${DATO}
LOG=${MAPPE}.log

#Hoved til logfilen
echo -e "Dette er en logfil for backup af OpenBSD \nLavet ${DATO} med backupscript af Lars Sommer \n" > $LOG

#Alt efter hvad $1 er sat til, pakker vi forskellige ting. 
#Jeg har ikke gidet goere noget stoerre nummer ud af at spare karakterer og lave 117 smaaargumenter og case-saetninger.

case "$1" in
system_komplet)
	tar --exclude=${LOG} --no-recursion -zcvf root.tar.gz * >> $LOG
	tar --exclude=var/run --exclude=var/www -zcvf var.tar.gz var/ >>$LOG
	tar -zcvf etc.tar.gz etc/ >>$LOG
	tar -zcvf boot.tar.gz boot/ >>$LOG
	tar -zcvf usr.tar.gz usr/ >>$LOG
;;
system_konf_og_var)
	tar --exclude=var/run --exclude=var/www -zcvf var.tar.gz var/ >>$LOG
	tar -zcvf etc.tar.gz etc/ >>$LOG
;;
home_og_www)
	tar -zcvf home.tar.gz home/ >>$LOG
	tar -zcvf www.tar.gz var/www/ >>$LOG
;;
*)
	echo "Der er vist noget galt.. Debug venligst scriptet her manuelt, tak."
	exit 1
;;
esac

#Flere mapper kan indsaettes som de ovenstaaende..


#Saa flytter vi tingene til backupmappen
mkdir $MAPPE
mv $LOG ${MAPPE}/
mv *.tar.gz ${MAPPE}/

