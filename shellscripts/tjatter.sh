#!/bin/sh 

#tjatter.sh, simpelt tjatscript i stedet for programmerne talk og write.
#Af Lars Sommer, lasg@lasg.dk
#Ver. Dato Note
#0.1 100205 Det koerer, men kan ikke bruges til noget af vaerdi.
#0.2 110205 Nu opdaterer det skaermen hver gang man skriver noget. Det er bedre.

#TODO
#Med funktionen "sleep <n secs>" kan man faa den til automatisk at opdatere skaermen 
# f.eks. hvert 3. sekund.
#Naar man joiner og parter, boer den skrive mere end kun username.


TID=`date +%H:%M:%S`
echo "${TID} --- ${USER} STARTER SIN TJATTER.SH --- " >> tjatter.log

while [ ! $SLUT ]
do
clear
echo "Simpel flerbrugertekstfilskriver og -laeser, af Lars Sommer, lasg@lasg.dk"
echo "Skriv /exit for at afslutte"
echo ""

tail -n 15 tjatter.log
echo ""
echo "Skriv linje i tekstfilen: "
read BESKED
TID=`date +%H:%M:%S`
echo "${TID} ${USER}:        ${BESKED}" >> tjatter.log


if [ `echo $BESKED | grep -c "^/exit"` = "1" ]; then
	TID=`date +%H:%M:%S`
	echo "${TID} --- ${USER} STOPPER SIN TJATTER.SH --- " >> tjatter.log
	echo "Afslutter..."
	exit 1;
fi
done
