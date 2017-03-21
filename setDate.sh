#!/bin/bash

clear

printf "day:?"
read tday
tday=00$tday
tday=${tday: -2}

printf "month:?"
read tmonth
tmonth=00$tmonth
tmonth=${tmonth: -2}


printf "year:?"
read tyear
tyear=0000$tyear
tyear=${tyear: -4}

printf "hors:?"
read thors
thors=00$thors
thors=${thors: -2}

printf "minuts:?"
read tminuts
tminuts=00$tminuts
tminuts=${tminuts: -2}

tsec=00

sudo date +%Y%m%d -s "$tyear$tmonth$tday"
sudo date +%T -s "$thors:$tminuts:$tsec"

date

read nnull












