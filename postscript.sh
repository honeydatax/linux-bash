#!/usr/bin/bash
x="10"
y="700"
f="56"
var0="%PS"
printf "%s\n" "$var0" > ps.ps
var1="/Times-Roman findfont"
var2="scalefont"
var3="setfont"
var4="newpath"
var5="moveto"
var6="(im love marina"
var7=") show"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="48"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="40"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="32"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="24"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="18"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="15"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="12"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="8"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="7"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="6"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="5"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps
y=$(( y - f ))
f="4"
printf "%s\n%s %s\n%s\n%s\n%s %s %s\n%s%s\n" "$var1" "$f" "$var2" "$var3" "$var4" "$x" "$y" "$var5" "$var6" "$var7" >> ps.ps



ps2pdf ps.ps ps.pdf
xpdf ps.pdf &















