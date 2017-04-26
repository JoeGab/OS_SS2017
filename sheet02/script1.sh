#!/bin/bash
# Script 1
#
for FN in "$@" #iteration over all arguments $@ with temporary variable FN
do #start of for loop
chmod 0750 "$FN" #change rights of access (chmod) for all arguments (step by step in FN) to:
# all rigths for the user (7), read and execute for group (5=101= r-x), take all rights away for others
# reset the UID bit
done #end of for-loop

# executed with no arguments, nothing happens
# executed with arguments: if argument is a file in same directory, or path to directory, access rights are setted, ohterwise an error (not a file) is being thrown,
