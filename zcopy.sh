#!/bin/bash

exits(){
if [ "$1" = "1" ]
then 
exit
fi
}



c="select files to copy"
b=$(zenity --file-selection  --title="$c" --text="$c" --multiple --separator=" ")
exits "$?"
c="select directory to copy to"
e=$(zenity --file-selection --directory --title="$c" --text="$c" )
exits "$?"


cp $b "$e"












