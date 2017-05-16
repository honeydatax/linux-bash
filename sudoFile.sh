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
z="$PWD"
sudo ls > "$pwds" 
a=$(zenity --list  --title="sudo file"  --text="sudo file" --column="$z" < "$pwds")
exits "$?"
printf "dir back\nchange dir\nnew dir\nnew file\ncopy file\nmove file\nrename\ndelete\nopen" > "$pwds" 
b=$(zenity --list  --title="sudo file"  --text="sudo file" --column="$z" < "$pwds")
exits "$?"

if [ "$b" = "dir back" ];
then 
cd ..
fi

if [ "$b" = "change dir" ];
then 
cd "$a"
fi



if [ "$b" = "new dir" ];
then 
c=$(zenity --entry  --title="make dir name"  --text="make dir name" )
exits "$?"
sudo mkdir "$c"
fi

if [ "$b" = "new file" ];
then 
c=$(zenity --entry  --title="make new file"  --text="make new file" )
exits "$?"
printf "" > "$pwdss/$c"
sudo mv "$pwdss/$c" "$PWD/"
sudo xdg-open "$c"
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
sudo mv  "$a" "$c"
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













