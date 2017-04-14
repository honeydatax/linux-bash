#!/bin/bash

clear

n=0;

printf "Append to maths.txt YN ?"
read nnul
if [ "$nnul" == "N" ]
then printf "s10\n" > maths.txt
fi

if [ "$nnul" == "n" ]
then printf "s10\n" > maths.txt
fi

printf "\n"

while : 
do 

printf "\nX%s: ?" $n 

read nnulx

if [ "$nnulx" == "" ]
then break
fi

printf "\nY%s: ?" $n 

read nnuly

printf "\nCOLOR%s: rgb?" $n 

read nnulc

printf "n%s %s %s\n" $nnulx $nnuly $nnulc >> maths.txt

n=$(( n + 1 ));

done

./maths maths.txt















