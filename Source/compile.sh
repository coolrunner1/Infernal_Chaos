#!/bin/bash
g++ -c main.cpp Functions/randomFloat.cpp Functions/randomInt.cpp Menu/mainMenu.cpp Menu/button.cpp Menu/cutscenes.cpp Entities/entity.cpp Entities/enemyMobile.cpp Entities/enemy.cpp  Entities/aliveEntity.cpp Entities/player.cpp Entities/bullet.cpp Entities/pickup.cpp Entities/ammoPack.cpp Levels/levelPattern.cpp
g++ main.o mainMenu.o button.o cutscenes.o entity.o aliveEntity.o player.o levelPattern.o enemyMobile.o bullet.o randomFloat.o randomInt.o pickup.o enemy.o ammoPack.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
