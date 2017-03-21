#!/bin/bash
clear

theDate=bak.$(date)
mkdir "$theDate"

cp client.txt "./$theDate/client.txt"

chmod 777 "./$theDate/client.txt"

printf "creat backup name:%s\n" "$theDate"


read nnull