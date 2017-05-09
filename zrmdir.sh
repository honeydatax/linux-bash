#!/bin/bash

exits(){
if [ "$1" = "1" ]
then 
exit
fi
}



c="select directory to copy to"
e=$(zenity --file-selection --directory --title="$c" --text="$c" --multiple --separator=" ")
exits "$?"

for d in $e
do
rmdir "$d"
done











