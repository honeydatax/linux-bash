#!/bin/bash

sudo mkfifo /dev/tx

sudo chmod 777 /dev/tx

clear

bash txpipe.sh < /dev/tx &

printf "press enter to exit.:"

read nnull

printf "exit\n" > /dev/tx