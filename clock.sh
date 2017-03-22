#!/bin/bash

clear
ctrc="";

printf "press crt-c to exit:\n"
stty -icanon min 0 time 0
while : 
do 
theClock=$(date)
printf "%s " $theClock
sleep 1
printf "\r" 
read ctrc
if [ "$ctrc" != "" ];
then break
fi 
done
stty -g
read nnull 
clear











