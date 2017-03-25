#! /bin/bash 

sleep 120



printf "exit" > "/mnt/ramdisk/main.txt"

for i in {1..18..1}
do
printf "exit" > "/mnt/ramdisk/t$i.txt"
done

printf '\e[15;1fkeyb drive is exiting'
printf "\e[11;1f"
