#!/bin/bash

clear
ctrc="";

stty -icanon min 0 time 0
while : 
do 
theClock=$(date)
dialog --title "clock..." --infobox "$theClock" 0 0
sleep 1
read ctrc
if [ "$ctrc" != "" ];
then break
fi 
done
stty -g











