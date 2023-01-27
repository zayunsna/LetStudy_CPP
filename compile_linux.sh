#!/bin/bash

NAME=$1

g++ -std=c++14 -Wall $NAME.cc -o $NAME.out
