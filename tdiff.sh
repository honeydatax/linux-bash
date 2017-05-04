#!/bin/bash
y="0"
tprint(){
y=$(echo "$1" "$2" "$3" "$4" "$5" "$6" | awk ' { g1 = $1 ; g2 = $2 ; g3 = $3 ; g4 = $4 ; g5 = $5 ; g6 = $6 ; if ( g3 == "PM" ) g1 = g1 + 12 ; if ( g3 == "pm" ) g1 = g1 + 12 ; if ( g6 == "PM" ) g4 = g4 + 12 ; if ( g6 == "pm" ) g4 = g4 + 12 ; gg1 = g1 * 100 + ( g2 * 1.67 ) ; gg2 = g4 * 100 + ( g5 * 1.67 ) ; gg3 = gg2 - gg1 ; tt1 = int( gg3 / 100 ) ; tt2 = gg3 - ( tt1 * 100 ) ; printf "%d;%d" , tt1 , tt2 ; } ' )
echo "$y" >>  time.txt
}


zenity --entry --title="time?" --text="time start" > time1.txt
zenity --entry --title="time?" --text="time end" > time2.txt

a=$(cat time1.txt)
b=$(cat time2.txt)

echo "$a" > time.txt
echo "$b" >> time.txt

tr -s ":" " "  < time1.txt > time11.txt
tr -s ":" " "  < time2.txt > time22.txt

a=$(cat time11.txt)
b=$(cat time22.txt)

tprint $a $b

zenity --text-info --title="time difference is" --filename="time.txt"


















