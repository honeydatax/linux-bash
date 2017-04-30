#! /usr/bin/bash

dialog --title "select file" --fselect "" 0 0 2> fileselect.txt

clear 

a=$(cat fileselect.txt)

printf "\n%s\n" "$a"