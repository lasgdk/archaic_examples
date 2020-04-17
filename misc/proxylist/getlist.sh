#!/bin/sh

#This script downloads lists of proxyservers from proxy.org
#They try to protect against automated downloads, so we fake the user agent.

#The faked user agent idea is considered beerware.
#lasg@lasg.dk

docroot="http://proxy.org/"
ext=".shtml"
pages="\
       tor \
       port80 \
       port443 \
       port444 \
       port1080 \
       port2301 \
       port3124 \
       port3127 \
       port3128 \
       port3382 \
       port6588 \
       port8000 \
       port8080 \
       port8081 \
       port8086 \
       port8888 \
       portx"

for actual in ${pages}; do
 	/usr/local/bin/wget --user-agent="Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)" ${docroot}${actual}${ext}
done

