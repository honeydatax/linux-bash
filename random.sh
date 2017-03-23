#! /bin/bash

clear

awk -F: 'BEGIN{srand();i=0;x=0;for (i=0;i<=11;i++){x=rand()*50+1;printf("%d \n",x);}}'
