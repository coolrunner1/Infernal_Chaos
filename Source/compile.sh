#!/bin/bash
g++ -c main.cpp Functions/randomFloat.cpp Functions/randomInt.cpp Menu/mainMenu.cpp Menu/button.cpp Menu/cutscenes.cpp Menu/Levels/Entities/entity.cpp Menu/Levels/Entities/enemyMobile.cpp Menu/Levels/Entities/aliveEntity.cpp Menu/Levels/Entities/player.cpp Menu/Levels/Entities/bullet.cpp Menu/Levels/levelPattern.cpp
g++ main.o mainMenu.o button.o cutscenes.o entity.o aliveEntity.o player.o levelPattern.o enemyMobile.o bullet.o randomFloat.o randomInt.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
