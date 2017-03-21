#!/bin/sh

clear 
printf "name to find:?" 
read toFind
printf "%s" $toFind > clientfinder.txt
fgrep -f clientfinder.txt client.txt

printf "change client y:?" 
read toFind
if [ "$toFind" = "n" ] ;
then exit
fi
if [ "$toFind" = "N" ] ;
then exit
fi
printf "client id to change:?" 
read toFind
printf "%s" " $toFind :" > clientfinder.txt
fgrep -f clientfinder.txt client.txt
printf "change client y:?" 
read toFinds
if [ "$toFinds" = "n" ] ;
then exit
fi 

if [ "$toFinds" = "N" ] ;
then exit
fi

printf ". $toFind :.\n"
grep -i -v " $toFind :"  client.txt > clientdelete.txt


printf "client change:\n" 
printf "$toFind" 

rm client.txt

cp clientdelete.txt client.txt

chmod 777 client.txt

clientId="$toFind"
printf "client name:?%s" " "
read clientName
printf "client address:?%s" " "
read clientaddress
chr=:;

printf "append client y:?" 
read toFind
if [ "$toFind" = "n" ] ;
then exit
fi
if [ "$toFind" = "N" ] ;
then exit
fi




clear
printf "%s " $clientId
printf "%s\n" 
printf "%s " $clientName
printf "%s\n" 
printf "%s " $clientaddress
printf "%s\n" ""

printf "%s " $clientName >> client.txt
printf "%s" $chr >> client.txt
printf "%10s " $clientId >> client.txt
printf "%s" $chr >> client.txt
printf "%s " $clientaddress >> client.txt
printf "%s\n" "" >> client.txt

 
read nulln












