#!/bin/bash

printf ".....................\n"

printf "info:?"
read tinfo

printf "value:?"
read tvalue

printf "%10s "  $tinfo >> ccalc.txt
printf ":"  $tinfo >> ccalc.txt
printf "%10s "  $tvalue >> ccalc.txt
printf "\n"  >> ccalc.txt

awk -F: 'BEGIN{value=0;}{value = value + $2 ; print $1 , "\t" , $2 , "\t" , value ; }END{print "total:\t",value}' ccalc.txt


printf ".....................\n"












