#!/bin/bash
y="780"

opens(){
ps2pdf "$1" "$2"
xpdf "$2" &
}

head(){
echo "%PS" > "$1"
}

tfonts(){
echo "/$2 findfont" >> "$1"
echo "$3 scalefont" >> "$1"
echo "setfont" >> "$1"
}

tprint(){
echo "newpath" >> "$1"
echo "$2 $3 moveto" >> "$1"
echo "($4) show" >> "$1"
printf "%s : %s" "$3" "$5" > ccalc.txt
y=$(awk -F: 'BEGIN{v=0;}{v = $1 - $2 ; print v ; }END{v = 0}' "ccalc.txt" )
}


file="ps.ps"
fpdf="ps.pdf"
ffont="Times-Roman"
ssize="76"
x="10"
ttext="im love marina."

head "$file"

while :
do
ssize=$(( ssize - 10 ))
tfonts "$file" "$ffont" "$ssize"
tprint "$file" "$x" "$y" "$ttext" "$ssize"

if [ "$ssize" = "36" ];
then
ffont="MONOSPACE"
fi 

if [ "$ssize" = "6" ];
then
break
fi 
done


 
opens "$file" "$fpdf"















