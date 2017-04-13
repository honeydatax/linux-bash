#!/bin/bash

mkfifo -m 666 ttx0
mkfifo -m 666 ttx1

./bat ttx0 ttx1 &

printf "n15 40 1 1 1\n" > ttx1

printf "p0 1 1 windows 1\n" > ttx1

printf "n15 40 3 2 2\n" > ttx1

printf "p1 1 1 windows 2\n" > ttx1

printf "n15 40 6 4 3\n" > ttx1

printf "p2 1 1 windows 3\n" > ttx1


printf "s2\n" > ttx1
printf "e\n" > ttx1

















