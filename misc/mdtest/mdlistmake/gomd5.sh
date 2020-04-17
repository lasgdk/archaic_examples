#!/bin/sh

password=`mdc ${3} | grep "Collision found" | awk '{ print $5 }'`

echo "User ${2} at ${1}, from ${4} uses ${password}"


