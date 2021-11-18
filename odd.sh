#!/bin/bash
#odd lines counting script

file=$1
counter=0
{
flock 3 #lock file by filedescriptor
echo $$ working with lock

if [ $# -eq 0 ]
then
    echo "$(basename $0) file"
    exit 1
fi

if [ ! -f $file ]
then
    echo "$file not a file"
    exit 2
fi

while read line
do
    # find out odd or even line number
    isEvenNo=$( expr $counter % 2 )

    if [ $isEvenNo -ne 1 ]
    then
        # even match
        echo $line
   # else
        # odd match
      #  echo $line
    fi
    # increase counter by 1
    (( counter ++ ))
done < $file
echo $$ done with lock
} 3<lock
