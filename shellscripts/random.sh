#!/bin/sh
RANDOM=$$
MAX=10
NUMBER=$(($RANDOM % MAX + 1))
echo $NUMBER
