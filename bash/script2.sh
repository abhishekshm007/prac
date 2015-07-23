#!/bin/sh
#script2.sh: Inetractive version

echo -e "Enter the patter to be searched : \c"
read pname
echo "Enter the file name to be used : \c"
read fname
echo -e "searching for $pname from file $fname"
grep "$pname" $fname
echo "Selected records shown above"
