#! /bin/bash
clear
cal -y > cal.txt
tr "_" " " < cal.txt > calender.txt
a=$(zenity --text-info --title="calandar.sh" --font="monospace" --filename="calender.txt" --width="600" --height="350") 





















