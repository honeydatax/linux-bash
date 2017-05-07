#!/bin/bash

lastDatabase=""
lastTable=""

exits(){
if [ "$1" != "0" ]
then
exit
fi
}


while :
do

printf "creat database\nopen database\ncreat table\nopen table\n" > out.txt

a=$(zenity --list --title="database select menu" --text="database select menu" --column="menu" < "out.txt"  )		

exits "$?"


if [ "$a" = "creat database" ];
then
b=$(zenity --entry --title="creat database" --text="creat data name?")
if [ "$?" = "0" ]
then
mkdir "$b" 
lastDatabase="$b/"
fi
fi




if [ "$a" = "open database" ];
then
echo "$a"
b=$(zenity --entry --title="open database" --text="open data name?")
if [ "$?" = "0" ]
then
lastDatabase="$b/"
fi
fi

if [ "$a" = "creat table" ];
then
b=$(zenity --entry --title="creat table" --text="creat table name?")
if [ "$?" = "0" ]
then
lastTable="$lastDatabase$b"
files="$lastTable"
lastTable="$lastTable.table"
printf "" > "$files.dat"
printf "" > "$lastTable"
the1="0";

while :
do
b=$(zenity --entry --title="creat colum" --text="creat colum name?")


if [ "$?" != "0" ]
then
break
fi


if [ "$the1" != "0" ]
then
files="$lastTable"
printf ":" >> "$files"
fi

if [ "$?" = "0" ]
then
files="$lastTable"
printf "$b" >> "$files"
fi



the1="1";

done

fi
fi


if [ "$a" = "open table" ];
then
b=$(zenity --entry --title="open table" --text="table to open?")
if [ "$?" = "0" ]
then
lastTable="$lastDatabase$b.table"
files="$lastTable"
zenity --text-info --title="open table" --text="table to open" < "$files"
fi
fi


done









