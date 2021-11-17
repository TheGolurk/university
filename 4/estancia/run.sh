#!/bin/bash

echo "Running..."

sleep 1

cd src

gcc -c -Wall -Werror -Wextra *.c

ar -rc libname.a *.o

ranlib libname.a

ar -rcs libname.a *.o

gcc proyecto.c -L. -lname -o a.out

./a.out && rm *.o *.a *.out
