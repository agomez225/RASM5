#!/bin/bash

set -e
test -d ./obj/ || mkdir ./obj/
test -f ./obj/functions.o && rm ./obj/functions.o

as -g -o ./obj/sort.o ./src/*.s
g++ -c -o ./obj/rasm5.o ./src/rasm5.cpp
g++ -o  rasm5 ./obj/rasm5.o ./obj/sort.o


rm -rf ./obj/

