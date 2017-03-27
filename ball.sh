#!/bin/bash

printf "\007\033c"
tput civis
x=2
y=2
xx=1
yy=1

for i in {0..100..1}
do
printf "\e[0;47;30m                    " 
done

printf "\e[24;1f press ctr-c to exit"

while :
do

x=$((x + xx))
y=$((y + yy))

if [ "$x" == 78 ];
then 
xx=-1
printf "\007"
fi

if [ "$x" == 1 ];
then 
xx=1
printf "\007"
fi

if [ "$y" == 1 ];
then 
yy=1
printf "\007"
fi

if [ "$y" == 22 ];
then 
yy=-1
printf "\007"
fi

printf "\e[%s;%sfo" $y $x
sleep 0.03
printf "\e[%s;%sf " $y $x

done










