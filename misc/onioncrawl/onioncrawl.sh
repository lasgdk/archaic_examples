# curl -v --socks5-hostname 127.0.0.1:9050 http://jhiwjjlqpyawmpjx.onion

export http_proxy=127.0.0.1:8118

ONIONURL=$1

INITIALWAITTIME=`expr $$ % 60`
TIME=`date +%Y-%m-%d_%H%M%S`
echo "Waiting $INITIALWAITTIME seconds before crawling $1"
sleep $INITIALWAITTIME

BASEDIR=/home/ls/onioncrawl
DATADIR=${BASEDIR}/data
URLDIR=${DATADIR}/${TIME}_${ONIONURL}
mkdir -p $URLDIR

CRAWLLOG=crawllog.txt

echo "" >>  $CRAWLLOG
echo "${TIME}_${ONIONURL}: Crawling routine initiated with URL: http://${ONIONURL}.onion" >>  $CRAWLLOG
echo "${TIME}_${ONIONURL}: Waiting ${INITIALWAITTIME} seconds before launching" >>  $CRAWLLOG

WAITTIME=`expr $$ % 60`
sleep $WAITTIME

wget --quiet --random-wait --wait=30 -e robots=off --no-check-certificate --user-agent="Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0)" --directory-prefix=${URLDIR} -r http://${ONIONURL}.onion 

TIME=`date +%Y-%m-%d_%H%M%S`
echo "${TIME}_${ONIONURL}: Crawling routine finished." >>  $CRAWLLOG

rmdir --ignore-fail-on-non-empty ${DATADIR}/*
