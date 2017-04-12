#!/bin/bash

./sub 109 19 sub.txt
out=$(cat sub.txt);
printf "109 - 19 = %s\n" $out

./sub 1009 109 sub.txt
out=$(cat sub.txt);
printf "1009 - 109 = %s\n" $out

./sub 1239 129 sub.txt
out=$(cat sub.txt);
printf "1239 - 129 = %s\n" $out

./sub 1999 -12 sub.txt
out=$(cat sub.txt);
printf "1999 - (-12) = %s\n" $out


















