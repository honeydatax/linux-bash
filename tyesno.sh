#!/usr/bin/bash



clear
a=$(zenity --question  --title="love..." --text="\nDo mariana love me." )

if [ "$?" = "0" ];
then
printf "\n%s\n" "YES"
fi

if [ "$?" = "1" ];
then
printf "\n%s\n" "NO"
fi

printf "\n%d\n" "$a"












