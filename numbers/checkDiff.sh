#!/bin/bash

SORTED=./sorted/sorted.txt


for f in ./*.txt
do
    echo "diffing $(basename "$f") with $SORTED"
    diff $f $SORTED

done
