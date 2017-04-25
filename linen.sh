#!/bin/bash 

if [ "$1" == "" ];
then
printf "\nbash linen.sh [input.txt]"
printf "[output.txt]\n\n"
printf "utility to remove line number\n"
exit
fi

sed 's/ *[0-9]*.//' $1 > $2



























