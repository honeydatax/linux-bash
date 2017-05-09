#!/bin/bash

exits(){
if [ "$1" = "1" ]
then 
exit
fi
}


c="select files to unzip"
b=$(zenity --file-selection  --title="$c" --text="$c" --separator=" " --file-filter="*.zip" --file-filter="*.ZIP")
exits "$?"


unzip "$b"












