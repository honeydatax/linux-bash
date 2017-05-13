#!/bin/bash

lastDatabase=""
lastTable=""
workfile=""
outputtxt=""
u=""
z=""
colums[0]=""
a=""


exits(){
if [ "$1" != "0" ]
then
exit
fi
}


while :
do

printf "creat database\nopen database\ncreat table\nopen table\nadd text colum\nadd integer colum\nadd number colum\nadd records\nlist records\nfind\nnumber finder\n" > out.txt

a=$(zenity --list --title="database select menu" --text="database select menu" --column="menu" < "out.txt"  )		

exits "$?"


if [ "$a" = "creat database" ];
then
echo "creat Database"
b=$(zenity --entry --title="creat database" --text="creat data name?")
exits "$?"
./database creat database "$b"
fi

if [ "$a" = "open database" ];
then
echo "open Database"
b=$(zenity --entry --title="open database" --text="open data name?")
exits "$?"
./database creat database "$b"
fi


if [ "$a" = "creat table" ];
then
echo "creat Table"
b=$(zenity --entry --title="creat Table" --text="creat Table name?")
exits "$?"
./database creat table "$b"
fi


if [ "$a" = "open table" ];
then
echo "openTable"
b=$(zenity --entry --title="open Table" --text="open Table name?")
exits "$?"
./database creat table "$b"
fi


if [ "$a" = "add text colum" ];
then
echo "add text colum"
b=$(zenity --entry --title="creat text colum" --text="creat text colum?")
exits "$?"
c=$(zenity --entry --title="text colum text size" --text="text colum text size?")
exits "$?"
./database add value "$b" txt "$c"
fi

if [ "$a" = "add integer colum" ];
then
echo "add integer colum"
b=$(zenity --entry --title="creat integer colum" --text="creat integer colum?")
exits "$?"
./database add value "$b" integer
fi

if [ "$a" = "add number colum" ];
then
echo "add number colum"
b=$(zenity --entry --title="creat number colum" --text="creat number colum?")
exits "$?"
./database add value "$b" number
fi


if [ "$a" = "add records" ];
then
echo "add records"
./database table | zenity --text-info --title="table" --text="table" --font="MONOSPACE" --width="600" --height="100" &
./database value count > out1.txt
enter=$(printf "\n")
d=$(tr -d "$enter" < out1.txt)
g="0"
h="0 "
i=""
while :
do
if [ "$d" == "$g" ];
then
break
fi

 
g=$(( g + 1 ))
h="colum $g"
j=$(zenity --entry --title="$h" --text="$h")
exits "$?"
printf "%s" "$j" > out4.txt
jj=$(tr -s " " "_" < out4.txt)
i="$i $jj"
done

echo $i

./database add record $i


fi

if [ "$a" = "list records" ];
then
echo "list records"
./database table > out.txt
./database select | zenity --text-info --title="select" --text="select" 
exits "$?"
fi



if [ "$a" = "find" ];
then
echo "finder"
./database table | zenity --text-info --title="table" --text="table" --font="MONOSPACE" --width="600" --height="100" &
exits "$?"
b=$(zenity --entry --title="colum number" --text="colum number?")
exits "$?"
c=$(zenity --entry --title="text to find" --text="text to find?")
exits "$?"
./database value count > out1.txt
enter=$(printf "\n")
d=$(tr -d "$enter" < out1.txt)
g="0"
h="0 "
while :
do
if [ "$d" == "$g" ];
then
break
fi

 
g=$(( g + 1 ))
h="$h $g"
done
echo "./database find $b $c $h"
./database find "$b" "$c" $h | zenity --text-info --title="select" --text="select" 
exits "$?"
fi


if [ "$a" = "number finder" ];
then
echo "number finder"
./database table | zenity --text-info --title="table" --text="table" --font="MONOSPACE" --width="600" --height="100" &
exits "$?"
b=$(zenity --entry --title="colum number" --text="colum number?")
exits "$?"
c=$(zenity --entry --title="number id to find" --text="number id to find?")
exits "$?"
./database value count > out1.txt
enter=$(printf "\n")
d=$(tr -d "$enter" < out1.txt)
g="0"
h="0 "
while :
do
if [ "$d" == "$g" ];
then
break
fi

 
g=$(( g + 1 ))
h="$h $g"
done
echo "./database where $b $c $h"
./database where "$b" "$c" $h | zenity --text-info --title="select" --text="select" 
exits "$?"
fi



done
























