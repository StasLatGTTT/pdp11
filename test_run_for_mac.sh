#!/bin/bash
rm -r /bin/*
qmake -o Makefile pdp11.pro
make all
rm ./Makefile
./bin/pdp11.app/Contents/MacOS/pdp11
