#!/bin/sh

USERS=`cat accounts_to_follow.txt`
RSSLINK="http://api.twitter.com/1/statuses/user_timeline.rss?screen_name="
USERDIR="following"
GLOBALLOG="logfile.txt"
touch $GLOBALLOG

INITIALWAITTIME=`expr $$ % 60`
TIME=`date +%Y-%m-%d_%H%M%S`
echo "" >>  $GLOBALLOG
echo "${TIME}: Crawling routine initiated." >>  $GLOBALLOG
echo "${TIME}: Waiting ${INITIALWAITTIME} seconds before launching" >>  $GLOBALLOG
sleep $INITIALWAITTIME

for ACTUAL in $USERS; do
	TIME=`date +%Y-%m-%d_%H%M%S`
	CURRENTDIR=${USERDIR}/${ACTUAL}
	TWEETLOG="${USERDIR}/${ACTUAL}/tweets_log_${ACTUAL}.txt"
	FETCHEDLOG="${USERDIR}/${ACTUAL}/fetched_log_${ACTUAL}.txt"
	mkdir -p $CURRENTDIR
	touch $FETCHEDLOG
	RSSFILE=RSS_${TIME}_${ACTUAL}.xml
	echo "$TIME: Fetching RSS for $ACTUAL" >> $GLOBALLOG
	wget -q -O ${CURRENTDIR}/${RSSFILE} ${RSSLINK}${ACTUAL}

	LINKURL="http://twitter.com/${ACTUAL}/statuses/"
	CURRENTSTATUSES=`grep -o "<link>.*</link>" ${CURRENTDIR}/${RSSFILE} |grep -o "statuses.*[0-9]"|cut -d "/" -f 2`
	for CURRENTSTATUS in $CURRENTSTATUSES; do
#		if ! [ -f ${CURRENTDIR}/${CURRENTSTATUS} ]; then
		ISFETCHED=`grep -c ${CURRENTSTATUS} ${FETCHEDLOG}`
		if ! [ "$ISFETCHED" -eq "1" ]; then
			sleep 2

			echo "$TIME: Fetching from user ${ACTUAL}, twit ID: ${CURRENTSTATUS}" >> $GLOBALLOG
			CURTIME=`date +%Y-%m-%d_%H%M%S`
			wget -q -O ${CURRENTDIR}/${CURRENTSTATUS} ${LINKURL}${CURRENTSTATUS}
			
			TWEETTEXT=`cat ${CURRENTDIR}/${CURRENTSTATUS} | grep "js-tweet-text\"" |sed s/"<p class=\"js-tweet-text\">"//`
			TEXTTOLOG="${CURTIME} - ${CURRENTSTATUS} - ${TWEETTEXT}"
			echo $TEXTTOLOG >> $TWEETLOG
			echo "" >> $TWEETLOG
			echo "${CURTIME}: Tweet ${CURRENTSTATUS} logged OK" >> $GLOBALLOG
			echo ${CURRENTSTATUS} >> ${FETCHEDLOG}
			rm ${CURRENTDIR}/${CURRENTSTATUS}
		#else
		#	echo "Already got twit ID ${CURRENTSTATUS}, skipping"
		fi
	done
done

TIME=`date +%Y-%m-%d_%H%M%S`
echo "${TIME}: Crawling routine finished." >>  $GLOBALLOG

