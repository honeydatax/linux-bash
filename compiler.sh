#!/bin/bash




exits(){
if [ "$1" = "1" ];
then 
exit
fi
}


pwds="$PWD/out.txt"
pwds2="$PWD/out2.txt"
pwdss="$PWD"

while :
do
a=$(zenity --file-selection  --title="select file to compile?" --text="select file to compile?" --separator=" " --file-filter="*.c" --file-filter="*.C" --file-filter="*.cpp" --file-filter="*.CPP" )
exits "$?"
zenity --info --title="g++ compile" --text="$a" &
g++ "$a" -o "$a.out" -lSDL -std=gnu++0x -lwiringPi > "$pwds" 2>"$pwds2"
b=$(cat "$pwds" "$pwds2" |zenity --text-info --title="g++ compile" --text="$a")
exits "$?"
a=$(zenity --file-selection  --title="select file to run?" --text="select file to run?" --separator=" ")
exits "$?"
xdg-open "$a"
done













