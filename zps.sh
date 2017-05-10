#!/bin/bash 

a=$(ps -all)
echo "$a" > out.txt

zenity --text-info --title="gdi ps" --text="gdi ps" --width="600" --height="350" --filename="out.txt" --font="MONOSPACE"
 
