#!/bin/bash

exits(){
if [ "$1" = "1" ]
then 
exit
fi
}



c="select files to copy"
b=$(zenity --file-selection  --title="$c" --text="$c" --multiple --separator=" " --file-filter="*.pdf" --file-filter="*.PDF" )
exits "$?"


for m in $b
do
pdftohtml $m "$m.html"
done
















