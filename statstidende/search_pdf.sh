#!/bin/sh

echo "<p>Searching for $1</p><p>"

for A in `ls *.pdf`; do
	RESULTS=`pdftotext $A - 2>/dev/null | fmt -w 180 | grep -C1 -i "${1}"|sed s/^/\<br\>/`
	#RESULTS=`echo $RESULTS | sed s/'\$'/"<br>"/`
	#RESULTS=`echo $RESULTS | tr '\n' '<br><br><br>'`
	if [ "$RESULTS" ] ; then
		echo "<hr />"
		echo "<h3>Fundet i <a href=\"$A\">$A</a>:</h3>"
		echo "<br />"
		echo "<p>$RESULTS</p>"
		echo "<br /><br />"
	fi
done

