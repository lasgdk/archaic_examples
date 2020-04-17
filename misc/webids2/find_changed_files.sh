#!/bin/sh

BASEDIR=/home/www/lasg.dk/misc/webids2/
CHECKDIR=/home/www/lasg.dk/
TIMESTAMPREFERENCE=${BASEDIR}/timestampreference
EMAIL_ADDRESS=lasg@lasg.dk
EMAIL_SUBJECT="Alert from webids2.0, time stamps has changed"
EMAIL=tmp.email

RESULT=`find ${CHECKDIR} -newer ${TIMESTAMPREFERENCE} -type f`

if [ "$RESULT" ]; then
	echo "The following changes has been seen;" > $EMAIL
	for A in $RESULT; do
		ls -la $A >> $EMAIL
	done
 	echo $EMAIL|mail -s ${EMAIL_SUBJECT} ${EMAIL_ADDRESS}
else
	echo "No timestamp changes since last run"
fi

touch ${TIMESTAMPREFERENCE}

