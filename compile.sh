#!/bin/bash
g++ -c main.cpp Menu/mainMenu.cpp Menu/button.cpp Menu/cutscenes.cpp Entities/entity.cpp Entities/aliveEntity.cpp Entities/player.cpp
g++ main.o mainMenu.o button.o cutscenes.o entity.o aliveEntity.o player.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
