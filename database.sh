#!/bin/bash

lastDatabase=""
lastTable=""
workfile=""
outputtxt=""
u=""
z=""
colums[0]=""
a=""

emulador(){
a="add records"
lastDatabase="data1"
lastTable="data1/table1.table"
workfile="data1/table1.dat"

return 0
}

input1(){
echo "ok"
}


rdelete(){
b=$(zenity --entry --title="to find a list to delete" --text="to delete find?")
if [ "$?" = "0" ]
then
printf "%s" "$b" > out2.txt
fgrep -f out2.txt "$workfile" > "out.txt"
b=$(zenity --list --title="client to find?" --separator=":" --column="delete" < "out.txt")

if [ "$?" = "0" ]
then 

grep -i -v "$b"  "$workfile" > "out.txt"

sudo rm "$workfile"

cp "out.txt" "$workfile"

chmod 666 "$workfile"


fi

fi

}


rfinder(){
b=$(zenity --entry --title="to find" --text="to find?")
if [ "$?" = "0" ]
then
printf "%s" "$b" > out2.txt
fgrep -f out2.txt "$workfile" > out.txt
zenity --text-info --title="client to find?" --filename="out.txt"
fi

}


lrecords(){
zenity --text-info --title="open table" --text="table to open" < "$workfile"

}


addrec(){
u="0"
z=""
cat "$lastTable" | awk 'BEGIN{c=0}{c=c+1}END{print c}' > out.txt
i=$(cat out.txt)
mm=$(awk '{a=$0;gsub(" ","_",a) ;printf "%s " , a }' "$lastTable" );
while :
do
z=""
t1="0"
for m in $mm
do
if [ "$t1" == "1" ]
then 
z="$z:"
fi

if [ "$u" = "0" ]
then
b=$(zenity --entry --title="add record?" --text="$m")
u="$?"
z="$z$b"
fi
t1="1"
done

if [ "$u" == "0" ]
then 
echo "$z" >> "$workfile"
fi



if [ "$u" == "1" ]
then 
break
fi



done


}


openTable(){

b=$(zenity --entry --title="open table" --text="table to open?")
if [ "$?" = "0" ]
then
lastTable="$lastDatabase$b.table"
workfile="$lastDatabase$b.dat"
files="$lastTable"
zenity --text-info --title="open table" --text="table to open" < "$files"
fi

}


creatTable(){

b=$(zenity --entry --title="creat table" --text="creat table name?")
if [ "$?" = "0" ]
then
lastTable="$lastDatabase$b"
files="$lastTable"
workfile="$lastTable.dat"
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


if [ "$?" = "0" ]
then
files="$lastTable"
echo "$b" >> "$files"
fi



the1="1";

done
printf "" >> "$files"
fi

}


openDatabase(){

b=$(zenity --entry --title="open database" --text="open data name?")
if [ "$?" = "0" ]
then
lastDatabase="$b/"
fi


}

creatDatabase(){
b=$(zenity --entry --title="creat database" --text="creat data name?")
if [ "$?" = "0" ]
then
mkdir "$b" 
lastDatabase="$b/"
fi
}

exits(){
if [ "$1" != "0" ]
then
exit
fi
}


while :
do

printf "creat database\nopen database\ncreat table\nopen table\nadd records\nlist records\nfind\ndelete\n" > out.txt

a=$(zenity --list --title="database select menu" --text="database select menu" --column="menu" < "out.txt"  )		

exits "$?"

#emulador


if [ "$a" = "creat database" ];
then
creatDatabase
fi




if [ "$a" = "open database" ];
then
openDatabase
fi

if [ "$a" = "creat table" ];
then
creatTable
fi


if [ "$a" = "open table" ];
then
openTable
fi


if [ "$a" = "add records" ];
then
addrec
fi

if [ "$a" = "list records" ];
then
lrecords
fi

if [ "$a" = "find" ];
then
rfinder
fi

if [ "$a" = "delete" ];
then
rdelete
fi


done









