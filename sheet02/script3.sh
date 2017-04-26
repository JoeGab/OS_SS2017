#!/bin/bash
# Script 3
INFILE=$1 #sets var INFILE to first argument (first "real" argument, not $0, first arg but name of script)
OUTFILE=$2 #sets var OUTFILE to second arg of script
if [ -e "$INFILE" ] #if a file, link or dir with name or path in var INFILE exists
then
	if [ -w "$OUTFILE" ] # if script-executing-user has writing permission on file OUTFILE
	then
		cat "$INFILE" >> "$OUTFILE" # cat shows content of a file, a >> b appends string a to file b
		# so content of INFILE is being appended to OUTFILE 
	else
		echo "can not write to $OUTFILE" # if executing user has no write permission on OUTFILE
	fi
else
	echo "can not read from $INFILE" # if file INFILE does not exist
fi
