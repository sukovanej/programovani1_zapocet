#!/bin/bash
mkdir __build
cd __build
cmake ../
make
./programovani1_zapocet
cd ..
#rm -rf __build
