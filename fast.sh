#!/bin/bash

exits(){
if [ "$1" = "1" ]
then 
exit
fi
}


c="select files to view"
b=$(zenity --file-selection  --title="$c" --text="$c" --separator=" " --file-filter="*.html" --file-filter="*.HTML" --file-filter="*.HTM" --file-filter="*.htm" )
exits "$?"


zenity --text-info --title="$b" --text="$b" --filename="$b" --width="600" --height="350" --html 











