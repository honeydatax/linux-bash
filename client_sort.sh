#!/bin/sh

sort -f -o clientdelete.txt client.txt

zenity --text-info --title="sort client" --filename="clientdelete.txt"

sudo rm clientdelete.txt


