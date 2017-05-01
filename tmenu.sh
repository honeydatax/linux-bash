#!/bin/bash
ls -l  > files.txt
b=$(printf "\n")
a=$(zenity --list --checklist --title="files" --separator="\n" --column="pick" --column="select" < files.txt )
clear
printf "\n%s\n" "$a"













