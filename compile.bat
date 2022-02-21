@echo off
title Compiling source code
set /p file="Masukkan nama program: "
cd ".\src"
g++ *.cpp -o ..\%file%.exe 
exit 0