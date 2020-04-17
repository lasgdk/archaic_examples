
URLS=`cat onionurls.txt`

MAXCONCURRENT=8

INITIALWAITTIME=`expr $$ % 300`
echo "Waiting initial $INITIALWAITTIME seconds..."
sleep $INITIALWAITTIME

for ACTUAL in $URLS; do
	WAITTIME=`expr $$ % 300` &&
	echo "Waiting $WAITTIME seconds.." &&
	sleep $WAITTIME &&

	NUMCRAWLING=`ps ax | grep -c onioncrawl.sh`
	while [ $NUMCRAWLING -ge $MAXCONCURRENT ]
	do
		WAITTIME=`expr $$ % 300` 
		sleep $WAITTIME 
		echo "Already crawling $MAXCONCURRENT. I will wait $WAITTIME seconds.."
		NUMCRAWLING=`ps ax | grep onioncrawl.sh|grep -c -v grep`
	done

	sh onioncrawl.sh $ACTUAL &
done

