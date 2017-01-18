#!/bin/bash
qmake -o Makefile pdp11.pro
make all
rm ./Makefile
