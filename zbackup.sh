#!/bin/bash

exits(){
if [ "$1" = "1" ]
then 
exit
fi
}



c="select directory to copy from"
e=$(zenity --file-selection --directory --title="$c" --text="$c" )
exits "$?"

c="select directory to copy to"
ee=$(zenity --file-selection --directory --title="$c" --text="$c" )
exits "$?"


cd  "$e"

s=$(ls)


cp $s "$ee"












