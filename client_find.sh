#!/bin/sh

clear 
printf "name to find:?" 
read toFind
printf "%s" $toFind > clientfinder.txt
fgrep -f clientfinder.txt client.txt
read nnull