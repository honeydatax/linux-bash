#!/bin/bash

./add 109 109 add.txt
out=$(cat add.txt);
printf "109 + 109 = %s\n" $out

./add 1009 1009 add.txt
out=$(cat add.txt);
printf "1009 + 1009 = %s\n" $out

./add 1239 1239 add.txt
out=$(cat add.txt);
printf "1239 + 1239 = %s\n" $out

./add 1999 -12 add.txt
out=$(cat add.txt);
printf "1999 + (-12) = %s\n" $out


















