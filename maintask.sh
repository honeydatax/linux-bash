#! /bin/bash


sudo mkdir /mnt/ramdisk > /dev/null
sudo mount -t tmpfs -o size=8m tmpfs /mnt/ramdisk

sudo chmod 777 /mnt/ramdisk/exit.txt
sudo rm /mnt/ramdisk/exit.txt

printf "." > /mnt/ramdisk/task.txt
printf "." > /mnt/ramdisk/ready.txt
printf "." > /mnt/ramdisk/main.txt
i="0"

for i in {1..18..1}
do
printf "." > "/mnt/ramdisk/t$i.txt"
bash task1.sh $i &
done

bash keybs.sh $i &

clear

while :
do
i="0"
for i in {1..18..1}
do
printf "\e[19;1ftask clock:%s   " $i
printf "%s" $i > "/mnt/ramdisk/task.txt"
printf "." > "/mnt/ramdisk/ready.txt"

while :
do
rready=$(cat "/mnt/ramdisk/ready.txt")
if [ "$rready" == "ready" ]
then break
fi
rrready=$(cat "/mnt/ramdisk/main.txt")
if [ "$rrready" == "exit" ]
then break
fi
done
rrready=$(cat "/mnt/ramdisk/main.txt")
if [ "$rrready" == "exit" ]
then break
fi

done
sleep 1

rready=$(cat "/mnt/ramdisk/main.txt")
if [ "$rready" == "exit" ]
then break
fi

printf "." > "/mnt/ramdisk/ready.txt"

done

rm /mnt/ramdisk/main.txt
rm /mnt/ramdisk/ready.txt
rm /mnt/ramdisk/task.txt



