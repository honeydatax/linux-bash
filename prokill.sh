#!/bin/bash

clear 

galculator &
mousepad &

sleep 3

clear 

jobs -l

while : 
do 

printf "press 1 close galculator\n"
printf "press 2 close mousepad\n"
printf "press 3 exit\n"

read lineA

if [ "$lineA" == "1" ];
then killall galculator
fi

if [ "$lineA" == "2" ];
then killall mousepad
fi

if [ "$lineA" == "3" ];
then break
fi

done



