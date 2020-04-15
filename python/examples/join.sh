#!/bin/sh
#Joining the 0* files together in one file, with file headers

FILES=`ls 0*`
OUT=python_examples.txt

rm ${OUT}

for ACTUAL in ${FILES};do
	echo "" >> ${OUT}
	echo "" >> ${OUT}
	echo "[-----------------------------" >> ${OUT}
	echo "[ \$ cat ${ACTUAL} ]" >> ${OUT}
	echo "" >> ${OUT}

	cat ${ACTUAL} >> ${OUT}
done
