//
// Created by Андрей Боровец on 09.04.2020.
//

#ifndef GAME_TECHPROG_MAP_H
#define GAME_TECHPROG_MAP_H

//#include <iostream>
#include <vector>
#include "../unit/unit.h"
//#include "../buildings/buildings.h"


struct Destination {
    int x_;
    int y_;
};

class Cell {
    std::vector<AbstractUnit> Mine_;
    std::vector<AbstractUnit> Rival_;
public:
    void attack(bool is_mine_, const AbstractUnit& unit);
};

class Map {
    Cell** array;
    const int width_ = 20;
    const int hight_ = 20;
public:
    Map();
    ~Map();

    Cell* operator[] (int i); //     чтобы можно было писать - map[i][j]

};


#endif //GAME_TECHPROG_MAP_H
