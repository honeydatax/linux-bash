#!/bin/bash

xx="0"
yy="0"
ipt=""
printf "" > list.txt
while :
do
ipt="X$xx?"
xxx=$(zenity --entry --title "list X" --text="$ipt")
if [ "$xxx" == "" ]
then
break
fi
ipt="Y$yy?"
yyy=$(zenity --entry --title "list Y" --text="$ipt")

if [ "$yyy" == "" ]
then
break
fi




printf "%d %d\n" "$xxx" "$yyy" >> list.txt

xx=$(( xx + 1 ))
yy=$(( yy + 1 ))

done

xx="0"
yy="0"
printf "" > tail.txt

cat list.txt | \
while read tx ty;do 
printf "\nX%d=%d,Y%d=%d" "$xx" "$tx" "$yy" "$ty" >> tail.txt
xx=$(( xx + 1 ))
yy=$(( yy + 1 ))
done 

printf "\n" >> tail.txt
cat tail.txt | zenity  --text-info --title "list XY" --width 575 

clear













