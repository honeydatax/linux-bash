#!/bin/bash

while :
do

printf "mousepad\ncommand\nweb\nshutdown\ncalculator\nfiles\nnotes\nclock\nexit" > out.txt

a=$(zenity --list --title="shell" --text="shell menu" --column="menu" < "out.txt"  )		

if [ "$a" = "mousepad" ];
then
mousepad &
fi

if [ "$a" = "command" ];
then
exo-open --launch TerminalEmulator &
fi

if [ "$a" = "web" ];
then
epiphany-browser %U &
fi

if [ "$a" = "shutdown" ];
then
sudo shutdown -h now &
fi

if [ "$a" = "calculator" ];
then
sudo galculator  &
fi

if [ "$a" = "notes" ];
then
xfce4-notes
fi

if [ "$a" = "files" ];
then
Thunar 
fi

if [ "$a" = "clock" ];
then
mb-applet-clock
fi

if [ "$a" = "exit" ];
then
break
fi

done












