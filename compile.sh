#!/bin/bash
g++ -c main.cpp Menu/mainMenu.cpp Menu/button.cpp Menu/cutscenes.cpp
g++ main.o mainMenu.o button.o cutscenes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
