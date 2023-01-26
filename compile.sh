#!/bin/bash

NAME=$1

gcc -framework Security -std=c++14 -Wall $NAME -o solve.out
