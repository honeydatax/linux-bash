#!/bin/bash
ls > list.txt
a=$(zenity --list --title="files" --separator=" " --column="files" < "list.txt")

zenity --warning --title="files selected" --text="$a"












