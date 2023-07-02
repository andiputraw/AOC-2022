#!/bin/bash
input="main.c"

flags="-Wextra -Wall" 

gcc $input $flags  -o main 

./main