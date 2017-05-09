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


a=$(unzip -l "$b")
c="files to $b"
echo "$c" > out.txt
echo "$a" >> out.txt
zenity --text-info  --title="$c" --text="$c"  --filename="out.txt" --font="MONOSPACE" --width="600" --height="350"











