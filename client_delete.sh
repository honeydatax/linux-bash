#!/bin/sh

clear 
printf "name to find:?" 
read toFind
printf "%s" $toFind > clientfinder.txt
fgrep -f clientfinder.txt client.txt

printf "delete client y:?" 
read toFind
if [ "$toFind" = "n" ] ;
then exit
fi
if [ "$toFind" = "N" ] ;
then exit
fi
printf "client id to delete:?" 
read toFind
printf "%s" " $toFind :" > clientfinder.txt
fgrep -f clientfinder.txt client.txt
printf "delete client y:?" 
read toFinds
if [ "$toFinds" = "n" ] ;
then exit
fi 

if [ "$toFinds" = "N" ] ;
then exit
fi

printf ". $toFind :.\n"
grep -i -v " $toFind :"  client.txt > clientdelete.txt


printf "client delete:\n" 
printf "$toFind" 

rm client.txt

cp clientdelete.txt client.txt

chmod 777 client.txt

read nnull







