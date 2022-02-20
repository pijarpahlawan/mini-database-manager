#!/bin/bash

cd src
exec g++ Buy.cpp CheckDB.cpp Create.cpp Delete.cpp FetchData.cpp GetPaid.cpp\
 GetReceipt.cpp Helpers.cpp Main.cpp Read.cpp Reset.cpp ShowDetails.cpp\
 Update.cpp UpdateDB.cpp -o ../mgmt
cd ..