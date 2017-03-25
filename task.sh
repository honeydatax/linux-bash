#!/bin/bash


while : 
do 

var1=$(date)
printf '\e[1;1f'
printf '%s ' $var1
sleep 1
printf '\e[10;1f'
cbreak=$(ls /mnt/ramdisk/exit.txt)

if [ "$cbreak" == '/mnt/ramdisk/exit.txt' ];
then break
fi

done


printf '\e[1;1fExiting from clock application on background'
printf "\e[11;1f"







