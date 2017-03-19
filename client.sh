#!/bin/sh

printf "client id:?%s" " "
read clientId
printf "client name:?%s" " "
read clientName
printf "client address:?%s" " "
read clientaddress
chr=:;

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





