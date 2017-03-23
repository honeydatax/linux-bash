#! /bin/bash



while : 
do 

clear

printf '\e[1;1f menu:                           '
printf '\e[2;1f 1 mousepad                      '
printf '\e[3;1f 2 command                       '
printf '\e[4;1f 3 web                           '
printf '\e[5;1f 4 shutdown                      '
printf '\e[6;1f 5 calculator                    '
printf '\e[7;1f 6 exit                          '
printf '\e[8;1f                                 '
printf '\e[9;1f                                 '
printf '\e[10;1f                                '
printf '\e[11;1f                                '

printf '\e[9;1f                                 '
printf '\e[9;1f'
read tchoice

if [ "$tchoice" == "1" ];
then mousepad & > null
fi

if [ "$tchoice" == "2" ];
then exo-open --launch TerminalEmulator & > null
fi

if [ "$tchoice" == "3" ];
then epiphany-browser %U & > null
fi

if [ "$tchoice" == "4" ];
then sudo shutdown -h now > null
fi

if [ "$tchoice" == "5" ];
then galculator & > null
fi

if [ "$tchoice" == "6" ];
then break 
fi

wait

done









