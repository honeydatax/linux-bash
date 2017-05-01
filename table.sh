#!/usr/bin/bash
x="50"
y="700"
f="50"
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
if [ "$x" = "500" ];
then
break
fi
done

x="50";
while :
do
printf "newpath\n" >> ps.ps
printf "0 %d moveto\n" "$x" >> ps.ps
printf "500 %d lineto\n" "$x" >> ps.ps
printf "1 setlinewidth\n" >> ps.ps
printf "stroke\n" >> ps.ps
x=$(( x + f ))
if [ "$x" = "850" ];
then
break
fi
done



ps2pdf ps.ps ps.pdf
xpdf ps.pdf &















