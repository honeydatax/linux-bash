#!/bin/bash

./div 109 19 div.txt
out=$(cat div.txt);
printf "109 : 19 = %s\n" $out

./div 1009 109 div.txt
out=$(cat div.txt);
printf "1009 : 109 = %s\n" $out

./div 1239 129 div.txt
out=$(cat div.txt);
printf "1239 : 129 = %s\n" $out

./div 1999 -12 div.txt
out=$(cat div.txt);
printf "1999 : (-12) = %s\n" $out


















