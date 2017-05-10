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

tab=$(printf "\t")

cd  "$e"

t=$(ls *.sh | zenity --list  --title="select files to turn executable" --multiple --checklist --column="c1"  --column="c2" --separator=" " )

chmod 777 $t











