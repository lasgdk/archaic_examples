#!/bin/sh

#Simpelt script der giver en rapport over diskquota paa en openbsd-maskine
# der har brugerkonti i /home og /var/www
#geitsjalf
#ver.0.1 100205 det virker fint, og jeg gider ikke goere mere ud af det.

BRUGERE_WWW=`ls -l /var/www/htdocs/ | grep ^d | awk '{print $3 }' | grep -v root`
BRUGERE_HOME=`ls -l /home/ | grep ^d | awk '{print $3 }'`

echo "OVERSIGT OVER DISKQUOTA FOR SYSTEMETS BRUGERE"
echo "`date`"
echo ""
echo "BRUGERE I /HOME/ :"
quota -v $BRUGERE_HOME
echo ""
echo "BRUGERE I /VAR/WWW :"
quota -v $BRUGERE_WWW
echo ""
echo "QUOTAOVERSIGT SLUT"
