#!/bin/sh
awk -F: '{print $2,"\t",$1,"\t",$3}' client.txt > clients.txt
zenity --text-info --title="formated list clients" --filename="clients.txt"