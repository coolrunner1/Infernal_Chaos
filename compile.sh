#!/bin/bash
g++ -c main.cpp mainMenu.cpp button.cpp cutscenes.cpp
g++ main.o mainMenu.o button.o cutscenes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system