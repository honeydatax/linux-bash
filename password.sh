#!/bin/bash

printf "crypt\ndecript\n" > "list.txt"
a=$(zenity --list --title="files" --separator=" " --column="menu" < "list.txt")



if [ "$a" = "crypt" ]
then 
a=$(zenity --password --title="enter password" --text="enter password")
b=$(zenity --password --title="confirme password" --text="enter password")
c=$(zenity --file-selection --title="select a file to crypt?" --file-filter="*.*")
printf "$a\n$b\ny\n" > password.txt
gpg -c "$c" < password.txt
sudo rm password.txt
exit
fi


if [  "$a" == "decript" ]
then 
a=$(zenity --password --title="enter password" --text="enter password")
b=$(zenity --password --title="confirme password" --text="enter password")
c=$(zenity --file-selection --title="select a file to crypt?" --file-filter="*.gpg")
printf "$a\n$b\ny\n" > password.txt
gpg -d "$c" > "$c.out" < password.txt
sudo rm password.txt
exit
fi































