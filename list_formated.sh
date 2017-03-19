#!/bin/sh
clear
awk -F: '{print $2,"\t",$1,"\t",$3}' client.txt
read nnull