#!/usr/bin/perl
print ("Enter your name\n");
$name = <STDIN>;
print ("Enter the temp in celcius");
$cel = <STDIN>;
$farenhiet = $cel *9/5 +32;
print ("Temp in farenhiet is $farenhiet and your name is $name\n");
