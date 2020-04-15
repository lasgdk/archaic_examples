FILENAME=.rothmetal.tmp
while true; do 
wget -q http://rothmetal.com/requests.pl -O ${FILENAME}
clear
grep -o "Current Song.*</TD>" ${FILENAME} | sed s/"<\/TH><\/TR><TR><TD>"/": "/ | sed s/"<\/TD>"//
sleep 10
done

