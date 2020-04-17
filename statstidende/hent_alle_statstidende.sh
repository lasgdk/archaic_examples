#!/bin/sh
START_YEAR=2010
STOP_YEAR=2012
STOP_COUNT=256

echo "Hent alle numre af Statstidende fra statstidende.dk"
echo "Copyright 2010, Dataministeriet.dk"
echo "Dette maa frit bruges, kopieres og aendres,"
echo " men notitsen om copyright bedes forblive."
echo "Da Statstidende kun er offentligt tilgaengeligt i 5 aar efter"
echo " udgivelsen paa statstidende.dk, er det vigtigt at gemme paa"
echo " aeldre numre selv."
echo "Dette script henter alle numre ned paa din computer. "
echo "Det vil optage cirka 3 GB diskplads (pr maj 2010),"
echo " og dermed ogsaa give en del trafik til statstidende.dk."
echo "Skriv 'ja' for at fortsaette."
read ANS
if [  "$ANS" != "ja" ];then
	echo "Du skrev ikke 'ja', saa vi afslutter her."
	exit 1
fi


YEAR=$START_YEAR
while [ $YEAR -le $STOP_YEAR ];do
	COUNT=0
	while [ $COUNT -le $STOP_COUNT ];do
		echo "Henter nummer $COUNT fra $YEAR"
		wget --user-agent="Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0)" --no-check-certificate --quiet https://www.statstidende.dk/Public/PublicationPDF/Statstidende_${YEAR}_${COUNT}.pdf
		COUNT=`expr $COUNT + 1`
	done
	YEAR=`expr $YEAR + 1`
done

echo "Fjerner tomme numre / fejlsider..."
TO_BE_DELETED=`grep -l "Siden du s&amp;oslash;gte efter kunne ikke findes" *.pdf`
rm -f $TO_BE_DELETED


