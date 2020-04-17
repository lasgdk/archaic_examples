#!/bin/sh

FILE_USERLIST=hest.list
FILE_HASHLIST=14numeric.mdlist

LINE_NO=1
LINE_NO_MAX=`tail -n 1 ${FILE_USERLIST}|awk '{ print $1 }'`

while [ ${LINE_NO} -lt ${LINE_NO_MAX} ]; do
	LINE_COMPLETE=`grep "^${LINE_NO} " ${FILE_USERLIST}`
	LINE_HASH=`echo ${LINE_COMPLETE}|awk -F \' '{ print $4 }'`

	SUCCES_HASH=`grep ${LINE_HASH} ${FILE_HASHLIST}|awk '{ print $1 }'`
	if [ ${SUCCES_HASH} ];then
		echo "${LINE_COMPLETE} ${SUCCES_HASH}"
	fi

	LINE_NO=`expr ${LINE_NO} + 1`
done

