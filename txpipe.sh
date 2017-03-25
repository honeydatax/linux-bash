#!/bin/bash

while :
do

read nnull

if [ "$nnull" == "exit" ];
then break 
fi

done

printf "exit from txpipe.sh\n\n"