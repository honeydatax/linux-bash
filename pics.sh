#!/bin/bash
picconverter=0

if [ "$1" != "" ];
then 
picconverter=1
fi

if [ "$1" != "" ];
then 
picconverter=1
fi

if [ "picconverter" == "1" ];
then 
printf "pic pic.bmp pic.jpg\n"
exit
fi

cjpeg -quality 100 "$1" > "$2"



























