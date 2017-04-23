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
printf "" > hide.txt
printf "%s" "$nnull" >> hide.txt
xxd -p hide.txt
printf "\n"
exit
fi


if [ "$1" == "-d" ]
then 
printf "\nstring to decript: "
read nnull
printf "\n"
printf "" > hide.txt
printf "%s" "$nnull" >> hide.txt
xxd -p -r hide.txt
printf "\n"
exit
fi































