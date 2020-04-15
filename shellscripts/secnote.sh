#!/bin/sh

DATE=`date +%y%m%d-%H%M%S`
MYKEY=1337684F
CRYPTFILE=$1
PLAINFILE=$HOME/.tmp.pgp.file
if [ "$1" = "secure" ]; then
	PLAINFILE=$2
	CRYPTFILE=$2.pgp
fi

decrypt(){
	rm -f $PLAINFILE
	touch $PLAINFILE &&
	chmod 600 $PLAINFILE &&
	cp $CRYPTFILE ${CRYPTFILE}_backup_${DATE}
	gpg --decrypt $CRYPTFILE > $PLAINFILE ||
	(echo "Error!" && exit 1)
}


encrypt(){
	gpg --encrypt --armor --sign --default-recipient $MYKEY  -u $MYKEY < $PLAINFILE > $CRYPTFILE || ( echo "Warning! You must encrypt your file now!" && encrypt )
	rm -f $PLAINFILE 
}


if [ "$1" = "secure" ]; then
	echo "Secure file $2 by PGP encrypting it, and deleting the plain text file? y/N"
	read ANS
	if [ "$ANS" = "y" ];then
		encrypt
	fi
	exit;
else
	decrypt &&
	vi -n $PLAINFILE &&
	encrypt
fi


