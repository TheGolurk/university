#!/bin/bash

# Usage ./run.sh file.c {argument2}
# argument2: less || no argument -> shows only the output
#			 full -> time

function compile {
	gcc $1 -o out && ./out
}

if [ "$2" == "full" ]; then

	printf "\n"

	START_TIME=$(date +%s)
	
	compile $1

	END_TIME=$(date +%s)
	printf "\nIt took $(($END_TIME - $START_TIME)) Seconds \n"
	echo "Deleting $1 binary file [out]" 

elif [ "$2" == "less" ]; then
	
	compile $1

else
	
	echo "Cannot make this action"
	exit 2> /dev/null

fi


rm out
