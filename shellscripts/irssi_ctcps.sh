#!/bin/sh
#irssi ctcp-replies changer.
#lasg@lasg.dk, 2005-04-09

#This script is very simple. It changes two values in the source code for irssi-0.8.9
#It is very possible it works with other versions, but I needed it only for this one.
#You can fuck the source up, by making strange replies, so keep it in normal text.
#After running this, compile and use irssi as normal.

#After fooling around in the src, I found out how to handle it in the config file, so this script is useless ...

#Set this to whatever you want your client to reply for VERSION and USERINFO
VERSION='"Ask me if you need to know."'
USERINFO='"I am a real user."'

#Replace the VERSION, store in a temp file
sed s/'PACKAGE" v$J - running on $sysname $sysarch"'/"$VERSION"/ irssi-0.8.9/src/irc/core/ctcp.c > ctcp.c.temp

#Move the temp file
mv ctcp.c.temp irssi-0.8.9/src/irc/core/ctcp.c

#Replace the USERINFO, store in a temp file
sed s/'"misc", "ctcp_userinfo_reply", "$Y"'/'"misc", "ctcp_userinfo_reply", '"$USERINFO"''/ irssi-0.8.9/src/irc/core/ctcp.c > ctcp.c.temp

#Move the temp file
mv ctcp.c.temp irssi-0.8.9/src/irc/core/ctcp.c

