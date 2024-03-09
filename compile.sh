#!/bin/bash
g++ -c main.cpp mainMenu.cpp button.cpp
g++ main.o mainMenu.o button.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system