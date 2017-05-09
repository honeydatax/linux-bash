#!/bin/bash

exits(){
if [ "$1" = "1" ]
then 
exit
fi
}



c="select files to delete"
b=$(zenity --file-selection  --title="$c" --text="$c" --multiple --separator=" ")
exits "$?"


rm $b 












