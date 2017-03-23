#! /bin/bash

clear 

printf "list of clients:\n\n"

for i in {0..1000..1}
do
printf "%s \t clients %s:\n" $i $i
done
printf "list of clients is in scroll windows:\npress a key to delete list\n"
read nnull
printf '\033c'
read nnull
