#!/bin/bash
g++ -c main.cpp Menu/mainMenu.cpp Menu/button.cpp Menu/cutscenes.cpp Menu/Levels/Entities/entity.cpp Menu/Levels/Entities/aliveEntity.cpp Menu/Levels/Entities/player.cpp Menu/Levels/levelPattern.cpp
g++ main.o mainMenu.o button.o cutscenes.o entity.o aliveEntity.o player.o levelPattern.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
