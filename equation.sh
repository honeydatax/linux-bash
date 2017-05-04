#!/bin/bash

a=$(zenity --entry --title="put vars and values?" --text="put var and values separete by ; sample: x=0;y=1")
echo "$a" > equation.txt
b=$(zenity --entry --title="put equetion?" --text="put equation sample: x * y")
echo "$b" >> equation.txt

c="{$a ; awk1000 = $b ; print awk1000 ; }"
echo "0" | awk "$c" >> equation.txt
echo "" >> equation.txt
zenity --text-info --title="trying to solve..." --filename="equation.txt"



























