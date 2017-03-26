#!/bin/bash

clear

for i in {1..101..1}
do
printf "\e[0;47;30m                   " 
done

ii=1
xx=1

printf "\e[20;0f press crt-c to exit" 

ttt1="010101010101010101010101010101010101010101"
ttt2="111000111000111000111000111000111000111000"
ttt3="111100001111000011110000111100001111000011"
ttt4="111110000011111000001111100000111110000011"


while :
do

sc=${ttt1:$ii:1}

sss1="[1;$xx""f"
sss2="[0;37;44m " 
sss3="[0;37;40m " 

if [ "$sc" == "1" ];
then 
sss1="[1;$xx""f"
sss2="[0;37;41m " 
sss3="[0;37;40m " 
fi

printf "\e%s\e%s\e%s" "$sss1" "$sss2" "$sss3"

sc=${ttt2:$ii:1}

sss1="[5;$xx""f"
sss2="[0;37;44m " 
sss3="[0;37;40m " 

if [ "$sc" == "1" ];
then 
sss1="[5;$xx""f"
sss2="[0;37;41m " 
sss3="[0;37;40m " 
fi

printf "\e%s\e%s\e%s" "$sss1" "$sss2" "$sss3"



sc=${ttt3:$ii:1}

sss1="[10;$xx""f"
sss2="[0;37;44m " 
sss3="[0;37;40m " 

if [ "$sc" == "1" ];
then 
sss1="[10;$xx""f"
sss2="[0;37;41m " 
sss3="[0;37;40m " 
fi

printf "\e%s\e%s\e%s" "$sss1" "$sss2" "$sss3"

sc=${ttt4:$ii:1}

sss1="[15;$xx""f"
sss2="[0;37;44m " 
sss3="[0;37;40m " 

if [ "$sc" == "1" ];
then 
sss1="[15;$xx""f"
sss2="[0;37;41m " 
sss3="[0;37;40m " 
fi

printf "\e%s\e%s\e%s" "$sss1" "$sss2" "$sss3"



ii=$(( $ii + 1 ))
if [ "$ii" == "42" ];
then 
ii=1
fi

xx=$(( $xx + 1 ))
if [ "$xx" == "78" ];
then 
xx=1
fi

sleep 0.01
done














