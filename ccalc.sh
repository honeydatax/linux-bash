#!/bin/bash
clear
tinfo=$(zenity --entry --title="info:?" )
tvalue=$(zenity --entry --title="value:?" )

printf "%10s "  $tinfo >> ccalc.txt
printf ":"  $tinfo >> ccalc.txt
printf "%10s "  $tvalue >> ccalc.txt
printf "\n"  >> ccalc.txt

awk -F: 'BEGIN{value=0;}{value = value + $2 ; print $1 , "\t" , $2 , "\t" , value ; }END{print "total:\t",value}' ccalc.txt > ucalc.txt
printf ".....................\n" >> ucalc.txt
zenity --text-info --title="ccalc.sh" --font="monospace" --filename="ucalc.txt" --width="600" --height="350"











