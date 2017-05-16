#!/bin/bash




exits(){
if [ "$1" = "1" ];
then 
exit
fi
}


pwds="$PWD/out.txt"
pwdss="$PWD"

while :
do
a=$(zenity --file-selection  --title="select file?" --text="select file?" --separator=" ")
exits "$?"
printf "new dir\nnew file\ncopy file\nmove file\nrename\ndelete\nopen" > "$pwds" 
b=$(zenity --list  --title="sudo file"  --text="sudo file" --column="menu" < "$pwds")
exits "$?"

if [ "$b" = "new dir" ];
then 
e=$(zenity --file-selection --directory --title="put new file into?" --text="put new file into?" )
exits "$?"
c=$(zenity --entry  --title="make new dir  name?"  --text="make new dir name?" )
exits "$?"
sudo mkdir "$e/$c"
fi





if [ "$b" = "new file" ];
then 
e=$(zenity --file-selection --directory --title="put new file into?" --text="put new file into?" )
exits "$?"
c=$(zenity --entry  --title="make new file  name?"  --text="make new file name?" )
exits "$?"
printf "" > "$pwdss/$c"
sudo mv "$pwdss/$c" "$e"
sudo xdg-open "$e/$c"
fi



if [ "$b" = "copy file" ];
then 
e=$(zenity --file-selection --directory --title="copy file $a into?" --text="copy file $a into?" )
exits "$?"
sudo cp "$a" "$e"
fi


if [ "$b" = "rename" ];
then 
c=$(zenity --entry  --title="rename file $a"  --text="rename file $a" )
exits "$?"
e=$(zenity --file-selection --directory --title="put file into?" --text="put file into?" )
exits "$?"
sudo mv  "$a" "$e/$c"
fi


if [ "$b" = "move file" ];
then 
e=$(zenity --file-selection --directory --title="move file $a into?" --text="move file $a into?" )
exits "$?"
sudo mv "$a" "$e"
fi

if [ "$b" = "delete" ];
then 
e=$(zenity --question  --title="delete file $a" --text="delete file $a" )
exits "$?"
sudo unlink "$a"
fi

if [ "$b" = "open" ];
then 
sudo xdg-open "$a"
fi


done













