#!/bin/sh


for ACTUAL in \
	"archivers/bzip2"\
	"archivers/zip"\
       	"editors/vim"\
	"ftp/wget"\
	"security/mdcrack"\
	"sysutils/screen"\
	"www/lynx"\
	"www/links"\
	;do

	cd /usr/ports/${ACTUAL} &&
	make install clean &&
	echo "Done installing ${ACTUAL}"

done

