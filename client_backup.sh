#!/bin/bash

theDate=bak.$(date)
mkdir "$theDate"

cp client.txt "./$theDate/client.txt"

chmod 666 "./$theDate/client.txt"

printf "creat backup name:%s\n" "$theDate" > Date.txt 
zenity --text-info --title="backup created." --filename="Date.txt"
































