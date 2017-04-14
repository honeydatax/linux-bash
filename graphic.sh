#!/bin/bash

mkfifo -m 666 ttx0 2> /dev/null
mkfifo -m 666 ttx1 2> /dev/null

./graphic ttx0 ttx1 &

printf "n1 1 300 300 255 0 0\n" > ttx1

printf "pwindows graphics\n" > ttx1

printf "n50 50 300 300 0 255 0\n" > ttx1

printf "n100 100 300 300 0 0 255\n" > ttx1

printf "s5\n" > ttx1
printf "e\n" > ttx1

















