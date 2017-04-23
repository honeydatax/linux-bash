#!/bin/bash

if [ "$1" == "" ]
then 
printf "%s cript %s decript\n\n" "-c" "-d"
exit
fi

if [ "$1" == "-c" ]
then 
printf "\nstring to cript: "
read nnull
printf "\n"
printf "" > password.txt
printf "%s" "$nnull" >> password.txt
gpg -c password.txt
printf "\n" 
cat password.txt.gpg 
exit
fi


if [ "$1" == "-d" ]
then 
printf "\nfile password.txt.gpg: "
gpg -d password.txt.gpg
printf "\n" 
exit
fi































