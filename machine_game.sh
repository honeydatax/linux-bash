#!/bin/bash
printf "add record\nlist machine\nlist client\nlist date" > out.txt

a=$(zenity --list --title="game machine gest" --text="select menu" --column="menu" < "out.txt"  )		

if [ "$a" = "add record" ];
then
b=$(zenity --forms --title="game machine gest add record" --text="machine code start m,client start c"  --separator=":" --add-entry="machine id?" --add-entry="date" --add-entry="client id"  )
echo " $b" >> machine_game.dat
fi


if [ "$a" = "list machine" ];
then
echo "" > out.txt
b=$(zenity --entry --title="game machine gest list machine m" --text="list machine id m"  )
printf " %s:" "$b" > finder.txt
fgrep -f finder.txt machine_game.dat > out.txt
zenity --text-info --title="game machine gest list machine m" --text="list machine id m" < out.txt 
fi

if [ "$a" = "list client" ];
then
echo "" > out.txt
b=$(zenity --entry --title="game machine gest list client c" --text="list client id c"  )
printf ":%s" "$b" > finder.txt
fgrep -f finder.txt machine_game.dat > out.txt
zenity --text-info --title="game machine gest list client c" --text="list client id m" < out.txt 
fi

if [ "$a" = "list date" ];
then
echo "" > out.txt
b=$(zenity --entry --title="game machine gest list all move in date" --text="list client all move in date"  )
printf ":%s" "$b" > finder.txt
fgrep -f finder.txt machine_game.dat > out.txt
zenity --text-info --title="game machine gest list date moves" --text="list client date moves" < out.txt 
fi


















