//
// Created by Андрей Боровец on 09.04.2020.
//

#ifndef GAME_TECHPROG_UNIT_H
#define GAME_TECHPROG_UNIT_H

#include "../destination.h"

class AbstractUnit {
public:
    virtual do() = 0;
    virtual go() = 0;
};

class Swordsman : public AbstractUnit {
    int radius_ = 0;
    int live_ = 100;
    Destination destination_ = {-1, -1};

public:
    virtual do() override;
    virtual go() override;
};


#endif //GAME_TECHPROG_UNIT_H
