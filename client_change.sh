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


toFind=$(zenity --entry --title="name to find:?")
exits $?
printf "%s" "$toFind" > clientfinder.txt
fgrep -f clientfinder.txt client.txt > clientf.txt
zenity --text-info --title="name to find:?" --filename="clientf.txt"
exits $?


toFind=$(zenity --entry --title="id client to find:?")
exits $?
printf "%s" " $toFind :" > clientfinder.txt
fgrep -f clientfinder.txt client.txt > clientf.txt
a=$(cat clientf.txt)
b="change name client:? "
b="$b $a"
zenity --text-info --title="$b" --filename="clientf.txt"
exits $?
zenity --question --title="$b" 
exits $?

grep -i -v "$toFind :"  client.txt > clientdelete.txt

sudo rm client.txt

cp clientdelete.txt client.txt

chmod 666 client.txt

clientId="$toFind"

clientName=$(zenity --entry --title="client name:?")
exits $?
clientaddress=$(zenity --entry --title="client address:?")
exits $?

reset "clients.txt"

save "clients.txt" "$clientId" "$clientName" "$clientaddress"

zenity --text-info --title="client entry" --filename="clients.txt" 
exits $?

save "client.txt" "$clientId" "$clientName" "$clientaddress"
 











