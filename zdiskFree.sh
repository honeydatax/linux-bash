#!/bin/bash 

a=$(df)
echo "$a" > out.txt

zenity --text-info --title="gdi free disk" --text="gdi free disk" --width="600" --height="350" --filename="out.txt" --font="MONOSPACE"
 
