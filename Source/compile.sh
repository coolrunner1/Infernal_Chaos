#!/bin/bash
g++ -c main.cpp Functions/randomFloat.cpp Functions/randomInt.cpp Menu/mainMenu.cpp Menu/button.cpp Menu/cutscenes.cpp Entities/entity.cpp Entities/healthPack.cpp Entities/enemyMobile.cpp Entities/enemy.cpp  Entities/aliveEntity.cpp Entities/player.cpp Entities/bullet.cpp Entities/ammoPack.cpp Entities/armorPack.cpp Levels/levelPattern.cpp
g++ main.o mainMenu.o button.o cutscenes.o entity.o healthPack.o aliveEntity.o player.o levelPattern.o enemyMobile.o bullet.o randomFloat.o randomInt.o enemy.o ammoPack.o armorPack.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
