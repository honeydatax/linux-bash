#!/usr/bin/bash
x="25"
y="700"
f="25"
var0="%PS"
printf "%s\n" "$var0" > ps.ps
while :
do
printf "newpath\n" >> ps.ps
printf "%d 850 moveto\n" "$x" >> ps.ps
printf "%d 10 lineto\n" "$x" >> ps.ps
printf "1 setlinewidth\n" >> ps.ps
printf "stroke\n" >> ps.ps
x=$(( x + f ))
if [ "$x" = "600" ];
then
break
fi
done

x="50";
while :
do
printf "newpath\n" >> ps.ps
printf "0 %d moveto\n" "$x" >> ps.ps
printf "700 %d lineto\n" "$x" >> ps.ps
printf "1 setlinewidth\n" >> ps.ps
printf "stroke\n" >> ps.ps
x=$(( x + f ))
if [ "$x" = "850" ];
then
break
fi
done



t="25"
z="-10"
x="25";
while :
do
printf "/Times-Roman findfont\n" >> ps.ps
printf "16 scalefont\n"  >> ps.ps
printf "setfont\n" >> ps.ps
printf "newpath\n" >> ps.ps
printf "%d 805 moveto" "$t" >> ps.ps
printf "(%d) show\n"  "$z" >> ps.ps
z=$(( z + 1 ))
x=$(( x + f ))
t=$(( x + 2 ))
if [ "$z" = "11" ];
then
break
fi
done



z="-10"
x="775"
t="$x"
clear
while :
do
printf "/Times-Roman findfont\n" >> ps.ps
printf "16 scalefont\n"  >> ps.ps
printf "setfont\n" >> ps.ps
printf "newpath\n" >> ps.ps
printf "2 %d moveto" "$t" >> ps.ps
#printf "%d\n" "$z"
printf "(%d) show\n"  "$z" >> ps.ps
z=$(( z + 1 ))
x=$(( x - f ))
t=$(( x + 2 ))
if [ "$z" = "11" ];
then
break
fi
done




ps2pdf ps.ps ps.pdf
xpdf ps.pdf &















