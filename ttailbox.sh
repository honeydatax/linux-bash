#! /usr/bin/bash

ls > tail.txt

cat tail.txt | zenity  --title "files" --text-info  

clear

a=$(cat tail.txt)

printf "\n%s\n" "$a" 














