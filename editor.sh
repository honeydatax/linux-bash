#!/usr/bin/bash
x="10"
y="850"
f="16"
var0="%PS"
printf "%s\n" "$var0" > ps.ps
var1="/Times-Roman findfont"
var2="scalefont"
var3="setfont"
var4="newpath"
var5="moveto"
var6="("
var7=") show"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))

a=$(zenity --text-info --filename="out.txt" --editable --title="digit texto to pdf" )
echo "$a" > out.txt
cat out.txt | \
while read var9 ;
do
y=$(( y - f ))
printf "%s\n%s %s %s\n%s%s%s\n"  "$var4" "$x" "$y" "$var5" "$var6" "$var9" "$var7" >> ps.ps
done


ps2pdf ps.ps ps.pdf
xpdf ps.pdf &















