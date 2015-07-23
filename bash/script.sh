#!/bin/sh
# schript.sh : Sample shell sript
echo "Today's date is : `date`"
echo "This month's calendar:"
cal `date "+%m 20%y"`
echo "My shel : $SHELL"
