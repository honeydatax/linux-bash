#! /bin/bash

clear

cal > cal.txt

sudo chmod 777 /dev/usb/lp0

sudo cat cal.txt > /dev/usb/lp0

mousepad cal.txt
