#!/bin/sh

clear

sort -f -o clientdelete.txt client.txt

cat clientdelete.txt

sudo rm clientdelete.txt

read nnull
