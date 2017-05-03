#!/bin/bash
a=$(zenity --file-selection --title="select a pdf to append" --file-filter="*.pdf")
b=$(zenity --file-selection --title="select other pdf to append" --file-filter="*.pdf")
d=$(( (RANDOM % 126 ) ))
c="book$d.pdf"
zenity --notification --title="$c" --text="$c" --hint="$c" &
gs -dNOPAUSE -sDEVICE=pdfwrite -sOUTPUTFILE="$c" -dBATCH "$a" "$b"
xpdf "$c" &



















