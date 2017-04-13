#!/bin/bash

mkfifo -m 666 ttx0 2> /dev/null
mkfifo -m 666 ttx1 2> /dev/null

./tprint ttx0 ttx1 &


printf "s\n" > ttx1
printf "c1 7\n" > ttx1
printf "g1 1\n" > ttx1

printf "pim love marina\n" > ttx1

printf "c2 7\n" > ttx1
printf "g2 2\n" > ttx1

printf "pim love marina\n" > ttx1

printf "c3 7\n" > ttx1
printf "g3 3\n" > ttx1

printf "pim love marina\n" > ttx1

printf "c4 7\n" > ttx1
printf "g4 4\n" > ttx1

printf "pim love marina\n" > ttx1

printf "c5 7\n" > ttx1
printf "g5 5\n" > ttx1

printf "pim love marina\n" > ttx1

printf "c6 7\n" > ttx1
printf "g6 6\n" > ttx1

printf "pim love marina\n" > ttx1


printf "c7 0\n" > ttx1

printf "g10 10\n" > ttx1
printf "e\n" > ttx1

















