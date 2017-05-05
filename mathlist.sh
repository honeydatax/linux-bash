#!/bin/bash
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

line(){
echo "newpath" >> "$1"
echo "$2 $3 moveto" >> "$1"
echo "$4 $5 lineto" >> "$1"
echo "1 setlinewidth" >> "$1"
echo "stroke" >> "$1"
}


file="ps.ps"
fpdf="ps.pdf"

head "$file"


x1=50
y1=720
x2=50
y2=250

tt=$(( 20 * 22 + 50 ))

while :
do 
line "$file" "$x1" "$y1" "$x2" "$y2"
x1=$(( x1 + 20 ))
if [ "$x1" = "$tt" ];
then
break
fi

x2="$x1"

done

x1=40
y1=700
x2="$tt"
y2=700

tt=$(( 20 * 22 ))
tt=$(( 700 - tt ))

while :
do 
line "$file" "$x1" "$y1" "$x2" "$y2"
y1=$(( y1 - 20 ))
if [ "$y1" = "$tt" ];
then
break
fi

y2="$y1"

done


tfonts "$file" "Times-Roman" "11"

x1=52
y1=710
x2=52
y2=0
values=-10

tt=$(( 20 * 20 + 50 ))



while :
do 
tprint "$file" "$x1" "$y1" "$values"
x1=$(( x1 + 20 ))
values=$(( values + 1 ))
if [ "$values" = "11" ];
then
break
fi

done


x1=30
y1=690
x2="$tt"
y2=700
values=-10

tt=$(( 20 * 22 ))
tt=$(( 700 - tt ))

while :
do 
tprint "$file" "$x1" "$y1" "$values"
y1=$(( y1 - 20 ))
values=$(( values + 1 ))

if [ "$values" = "11" ];
then
break
fi

y2="$y1"

done





xx="0"
yy="0"
ipt=""
while :
do
ipt="X$xx?"
xxx=$(zenity --entry --title "list X" --text="$ipt")
if [ "$xxx" == "" ]
then
break
fi
ipt="Y$yy?"

yyy=$(zenity --entry --title "list Y" --text="$ipt")

if [ "$yyy" == "" ]
then
break
fi

x1=$(echo "$xxx" | awk '{ xa = $1 ; xa = (xa + 10) * 20 + 50 ; print xa }' )
x2=$(echo "$xxx" | awk '{ xa = $1 ; xa = (xa + 10) * 20 + 70 ; print xa }' )
y1=$(echo "$yyy" | awk '{ xa = $1 ; xa = 680 - (xa + 10) * 20 ; print xa }' )
y2=$(echo "$yyy" | awk '{ xa = $1 ; xa = 700 - (xa + 10) * 20 g ; print xa }' )
 
line "$file" "$x1" "$y1" "$x2" "$y2"

x1=$(echo "$xxx" | awk '{ xa = $1 ; xa = (xa + 10) * 20 + 50 ; print xa }' )
x2=$(echo "$xxx" | awk '{ xa = $1 ; xa = (xa + 10) * 20 + 70 ; print xa }' )
y1=$(echo "$yyy" | awk '{ xa = $1 ; xa = 700 - (xa + 10) * 20 ; print xa }' )
y2=$(echo "$yyy" | awk '{ xa = $1 ; xa = 680 - (xa + 10) * 20 g ; print xa }' )
 
line "$file" "$x1" "$y1" "$x2" "$y2"


done

opens "$file" "$fpdf"




























