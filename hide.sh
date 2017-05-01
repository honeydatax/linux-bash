#!/bin/bs

if [ "$1" == "" ]
then 
printf "%s cript %s decript\n\n" "-c" "-d" > out.txt
zenity --text-info --filename="out.txt" --title="cript decript" &
exit
fi

if [ "$1" == "-c" ]
then 
nnull=$(zenity --entry --title="enter string to cript")
printf "" > hide.txt
printf "%s" "$nnull" >> hide.txt
xxd -p hide.txt > out.txt
zenity --text-info --filename="out.txt" --title="string cript" &
exit
fi


if [ "$1" == "-d" ]
then 
nnull=$(zenity --entry --title="enter string to cript")
printf "" > hide.txt
printf "%s" "$nnull" >> hide.txt
xxd -p -r hide.txt > out.txt
zenity --text-info --filename="out.txt" --title="string decript" &
exit
fi































