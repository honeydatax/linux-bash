#!/bin/bash

a=""

(while :
do 
theClock=$(date)
if [ "$a" != "" ];
then  
break 
fi
printf "# %s\n" "$theClock"
sleep 1
done) | a=$(zenity --progress --title="clock")
















