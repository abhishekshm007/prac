#!/usr/bin/perl
print("Enter the name : ");
$name = <STDIN>;
chop($name);
if($name eq ""){
	print("Entrer your name properly\n");
}else {
	print("Welcome, $name and good morning");
}
