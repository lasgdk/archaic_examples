#!/bin/sh

#fixsms is a couple of small utils to ease the sms features of gnokii
#Lars Sommer, lasg@lasg.dk, 2007-10-08

#TODO: This is just alpha stage.. Vars, names and such sucks.
#It should name the sms by its date and/or sender
#It should check the sender number in a central phone book 
#  fetched from the phone e.g.
#It should run as a daemon, checking often. 
#  But should be runable for a user as well, cause
#  I cant wait 5 mins, when I hear my phone beeps :) 

#The sending part.. is missing... Syntax:
# echo "my msg" |  sudo gnokii --sendsms 4512345678 -l 900

sudo gnokii --getsms IN 1 2> sms.log > sms.hentet

ANTAL=`grep 'Linked' sms.hentet | grep -o '\/[0-9]' | grep -o '[0-9]'`

if [ $ANTAL ]; then
	echo "Multiple parted SMS. Fetching all ${ANTAL} parts.."
	sudo gnokii --getsms IN 1 ${ANTAL} 2> sms.log > sms.hentet
fi

head -n 3 sms.hentet | tail -n 2 >  sms.tekst
echo " " >> sms.tekst
grep -v '\(Inbox Message\|Date\/time\|Linked \|Sender:.*Center\)' sms.hentet |tail -r>> sms.tekst

#This is really dirty. Please give me a book on regexp.. :)
NUMBER=`grep 'Sender: +45' sms.tekst | sed s/"Sender: +45"// | sed s/" Msg.*"//`
DATE=`grep 'Date\/time: ' sms.tekst`
DATEPART1=`echo $DATE|grep -o '200.'`
DATEPART2=`echo $DATE| grep -o '\/..\/' | sed s/"\/"//g`
DATEPART3=`echo $DATE| grep -o ' ..\/' | sed s/"\/"// | sed s/" "//`
DATEPART4=`echo $DATE| grep -o ' ..\:' | sed s/"\:"// | sed s/" "//`
DATEPART5=`echo $DATE| grep -o '\:..\:' | sed s/"\:"//g`
DATE="${DATEPART1}${DATEPART2}${DATEPART3}-${DATEPART4}${DATEPART5}"

mv sms.tekst ${DATE}_${NUMBER}

rm sms.log sms.hentet

cat sms.tekst

