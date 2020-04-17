
WORKDIR=/home/ls/OSINT/onioncrawl
URLFILE=onionurls.txt
TMPFILE=${URLFILE}.tmp
OLDFILE=${URLFILE}.old

cp $URLFILE $OLDFILE

 grep -R -o "http://.*.onion" data/* |cut -d":" -f3|cut -d "." -f1|cut -d "/" -f3 | grep -i "................"|grep -o "[[:alnum:]]\{16\}"|sort -T $WORKDIR |uniq >> $URLFILE

cat $URLFILE | sort -T $WORKDIR |uniq > $TMPFILE

mv $TMPFILE $URLFILE


