#!/bin/bash 

exits(){
if [ "$1" = "1" ];
then
exit 0
fi
}


while :
do

a=$(zenity --entry --title="zcommand" --text="zcommand" --width="600" --height="350" )
exits "$?"


$a > out.txt

zenity --text-info --title="zcommand" --text="zcommand" --width="600" --height="350" --filename="out.txt" --font="MONOSPACE"
exits "$?" 
done
















