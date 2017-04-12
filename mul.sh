#!/bin/bash

./mul 109 109 mul.txt
out=$(cat mul.txt);
printf "109 X 109 = %s\n" $out

./mul 1009 1009 mul.txt
out=$(cat mul.txt);
printf "1009 X 1009 = %s\n" $out

./mul 1239 1239 mul.txt
out=$(cat mul.txt);
printf "1239 X 1239 = %s\n" $out

./mul 1999 -12 mul.txt
out=$(cat mul.txt);
printf "1999 X (-12) = %s\n" $out


















