#!/bin/bash
exits(){
if [ "$1" = "1" ];
then
exit
fi
}

a=$(zenity --file-selection --title="files" )
b=$(zenity --text-info --title="file selected" --editable --filename="$a")
exits $?

echo "$b" > "$a"

















