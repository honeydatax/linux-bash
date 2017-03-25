#!/bin/bash



while : 
do 

while : 
do

cbreak=$(cat "/mnt/ramdisk/t$1.txt")
if [ "$cbreak" == "exit" ];
then break
fi

ccbreak=$(cat "/mnt/ramdisk/task.txt")
if [ "$ccbreak" == "$1" ];
then break
fi
done

var1=$(date)
printf '\e[%s;1f' $1
printf '%s ' $var1
printf '\e[20;1f'
printf "ready" > /mnt/ramdisk/ready.txt

cbreak=$(cat "/mnt/ramdisk/t$1.txt")
if [ "$cbreak" == "exit" ];
then break
fi
sleep 1
done



printf "\e[%s;1f clock drive %s is quiting living screen drive" $1 $1
printf "\e[21;1f"

rm "/mnt/ramdisk/t$1.txt"





