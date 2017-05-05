#!/bin/bash
printf "add record\nlist machine" > out.txt

a=$(zenity --list --title="game machine gest" --text="select menu" --column="menu" < "out.txt"  )		

if [ "$a" = "add record" ];
then
b=$(zenity --forms --title="game machine gest add record" --text="machine code start m,client start c"  --separator=":" --add-entry="machine id?" --add-entry="date" --add-entry="client id"  )
echo "$b" >> machine_game.dat
fi


if [ "$a" = "list machine" ];
then
echo "" > out.txt
b=$(zenity --entry --title="game machine gest list machine m" --text="list machine id m"  )
printf "%s:" "$b" > finder.txt
fgrep -f finder.txt machine_game.dat > out.txt
zenity --text-info --title="game machine gest list machine m" --text="list machine id m" < out.txt 
fi



















