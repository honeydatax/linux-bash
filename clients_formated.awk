#!/bin/awk
f="client.txt";
FILENAME=f;
rs=":";
fs="\n";
BEGIN {print "File\tOwner"} \
{print $1,"\t",$0,"\t",$2} \
END {print "-DONE-"} \