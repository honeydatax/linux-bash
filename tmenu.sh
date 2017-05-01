#!/bin/bash
a=$(zenity --list --checklist --title="files" --separator="|" --column="pick" --column="select"   < list.txt)
clear
printf "\n%s\n" "$a"













