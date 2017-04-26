#!/bin/bash
if [ $# != 1 ] 
then
	echo "usage: ./my_back_up.sh backupdir"
	exit 1
fi

FILES=`ls`
if [ -e $1 ]
then
	#copy only not existing or newer
	for FILE in $FILES
	do
		cp -ru $FILE $1
	done
else
	#copy all
	mkdir "$1"
	for FILE in $FILES
	do
		cp -r $FILE $1
	done
fi

#it fails if backupdir is in .
