#!/bin/bash



clear
a=$(zenity --question  --title="love..." --text="\nDo mariana love me." )

b="NO"


if [ "$?" = "0" ];
then
b="YES"
fi

if [ "$?" = "1" ];
then
b="NO"
fi

zenity --notification --title="info box" --text="$b" --hint="$b"













