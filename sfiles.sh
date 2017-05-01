#!/bin/bash
ls > list.txt
printf "\n" >> tail.txt

printf "\n" > line.txt
line=$(cat line.txt)
a=$(zenity --list --title="files" --separator=" " --column="files" < list.txt)


clear


printf "\n%s\n" "$a"













