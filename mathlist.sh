#!/bin/bash

xx="0"
yy="0"
ipt=""
printf "" > list.txt
while :
do
ipt="X$xx?"
dialog --title "list X" --inputbox "$ipt" 0 0 2> x.txt
xxx=$(cat x.txt)
if [ "$xxx" == "" ]
then
break
fi
ipt="Y$yy?"
dialog --title "list Y" --inputbox "$ipt" 0 0 2> y.txt
yyy=$(cat y.txt)
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

dialog  --title "list" --tailbox tail.txt 0 0 

clear













