#!/bin/bash

exits(){
if [ "$1" = "1" ]
then 
exit
fi
}

save(){
printf " %s " "$2" >> "$1"
printf ":" >> "$1"
printf "%s " "$3" >> "$1"
printf ":" >> "$1"
printf "%s " "$4" >> "$1"
printf "\n" >> "$1"

}

reset(){
printf "" > "$1"

}


clientId=$(zenity --entry --title="client id:?")
exits $?
clientName=$(zenity --entry --title="client name:?")
exits $?
clientaddress=$(zenity --entry --title="client address:?")
exits $?

reset "clients.txt"

save "clients.txt" "$clientId" "$clientName" "$clientaddress"

zenity --text-info --title="client entry" --filename="clients.txt" 
exits $?

save "client.txt" "$clientId" "$clientName" "$clientaddress"
 



















