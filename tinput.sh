#! /usr/bin/bash


dialog --title "client" --inputbox "client name?" 0 0 2> input.txt

clear

a=$(cat input.txt)

printf "\n%s\n" "$a"