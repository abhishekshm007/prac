#!/bin/bash
# scrpt : a simple script to check arguments
echo " Program : $0
The number of arguments specified is $#
the arguments are $*"
grep "$1" $2
echo "PID of current shell $$"
echo "PID of last backgroud job $!"
echo "\njob Over"
