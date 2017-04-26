#!/bin/bash
# Script 2
if (( $# < 3 )) # if the number of arguments passed into the script less than 3
then #start if  the condition above is true
printf "%b" "Error. Not enough arguments.\n" >&2 #print this to stderr(&2) while parsing backslash escapings
printf "%b" "usage: myscript file1 op file2\n" >&2 #same here
exit 1 #return with value 1
elif (( $# > 3 )) # if condition in line 3 fails jump to here (elif) another condition if number of args greater than 3
then #start of conditional execution block from condition above
printf "%b" "Error. Too many arguments.\n" >&2 #same as line 5 and 6
printf "%b" "usage: myscript file1 op file2\n" >&2 #same
exit 2 #return with value 1
else # if both conditions (line 3 and 8) fail, (means number of args is exactly 3)
printf "%b" "Argument count correct. Proceeding...\n" #print to stdout with backslash escaping
fi #end of if in line 3
# return with value 0 (because of EOF)
