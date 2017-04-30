#! /usr/bin/bash

dialog --title "enter password?" --passwordbox "you lave is?"  0 0 2> password.txt

clear 

a=$(cat password.txt)

printf "\n%s\n" "$a"
