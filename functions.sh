#!/bin/bash

aadd () {
a=$1
a=$(( a + 1 ))
return $a
}

save () {
printf "%s" "$1" > functions.txt
}


load () {
a=$(cat functions.txt)
return $a
}


reports () {
printf "you visit the web site:\n%s\ntimes" "$1" > out.txt
zenity --text-info --title="Web visit" < out.txt
}

load 
b=$?
aadd $b 
b=$?
save $b 
reports $b 















