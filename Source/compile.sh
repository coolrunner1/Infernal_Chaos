#!/bin/bash
g++ -c main.cpp Menu/mainMenu.cpp Menu/button.cpp Menu/cutscenes.cpp Menu/Entities/entity.cpp Menu/Entities/aliveEntity.cpp Menu/Entities/player.cpp
g++ main.o mainMenu.o button.o cutscenes.o entity.o aliveEntity.o player.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
