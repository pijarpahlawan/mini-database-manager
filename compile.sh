#!/bin/bash

read -p "Masukkan nama program: " program
cd ./src
exec g++ *.cpp -o ../$program.sh
exit 0