#!/usr/bin/bash

dialog --title "love..." --yesno "\nIm love mariana." 0 0

clear

a="$?"

printf "\n%d\n" "$a"


if [ "$a" = "0" ];
then
printf "\nYES\n" 
fi

if [ "$a" = "1" ];
then
printf "\nNO\n" 
fi










