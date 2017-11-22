#! /bin/bash

while read line
do
    echo $line | cut -d " " -f3,9 | grep " $1"
done
