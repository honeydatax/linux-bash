#!/bin/bash

exits(){
if [ "$1" = "1" ]
then 
exit
fi
}


a=$(zenity --entry --title="zip name" --text="zip name?")
exits "$?"
a="$a.zip"
c="select files to $a"
b=$(zenity --file-selection  --title="$c" --text="$c" --multiple --separator=" ")
exits "$?"


zip "$a" $b












