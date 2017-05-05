#!/bin/bash

dialog --title "chage time clock" --timebox "change clock" 0 0 2> out.txt
tt=$(cat out.txt)
t=$(zenity --calendar --title="change date")
printf "%s" "$t" > out.txt
tr -d "-" < out.txt > out2.txt
t=$(cat out2.txt)
a=${t:4:4}${t:2:2}${t:0:2}

sudo date +%Y%m%d -s "$a"
sudo date +%T -s "$tt"














