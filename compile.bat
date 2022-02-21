@echo off
title Compiling source code
set /p program="Masukkan nama program: "
cd ".\src"
g++ *.cpp -o ..\%program%.exe 
exit 0