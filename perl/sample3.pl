#!/usr/bin/perl
print("Enter your name : ");
chop($name = <STDIN>);
$last = chop($name);
print("your name is $name and $last\n");
