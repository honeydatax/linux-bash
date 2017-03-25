#! /bin/bash


sudo mkdir /mnt/ramdisk > /dev/null
sudo mount -t tmpfs -o size=8m tmpfs /mnt/ramdisk

sudo chmod 777 /mnt/ramdisk/exit.txt
sudo rm /mnt/ramdisk/exit.txt

clear

bash task.sh &

printf '\e[8;1fPress a key on this program to stop the other'

read nnull

printf "exit" > /mnt/ramdisk/exit.txt

printf '\e[9;1fPress a key to exit'

read nnull

sudo chmod 777 /mnt/ramdisk/exit.txt
sudo rm /mnt/ramdisk/exit.txt














