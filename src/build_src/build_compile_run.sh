#!/bin/bash
cmake ..
cmake --build .
/usr/bin/clang++ --std c++17 -fdiagnostics-color=always -g /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/main.cpp /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/UserManager/UserHandler.cpp /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/Utils.cpp -lpqxx -lpq -o /Users/alexseres/OwnCplusPlusProjects/ToDoProject/src/main
echo "Lets use the executable"
../main