#!/bin/sh

#Henter post fra alle postkasser med fetchmail.
fetchmail && echo "Post hentet for lasg"
fetchmail -f /home/lasg/.fetchmailrc.spam && echo "Post hentet for spam"
fetchmail -f /home/lasg/.fetchmailrc.jollymonk && echo "Post hentet for jollymonk"
