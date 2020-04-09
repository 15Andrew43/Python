//
// Created by Андрей Боровец on 09.04.2020.
//

#ifndef GAME_TECHPROG_UNIT_H
#define GAME_TECHPROG_UNIT_H

#include "../map/map.h"


class AbstractUnit {

public:
    virtual void attack() = 0;
    virtual void go() = 0;
    virtual int getPower() const = 0;
    virtual int& getHealthy() = 0;
    virtual bool isMine() const = 0;
};

class Swordsman : public AbstractUnit {
    bool is_mine_;
    int radius_ = 0;
    int healthy_ = 100;
    Destination destination_ = {-1, -1};
    int power_ = 20;


public:
    virtual void attack() override;
    virtual void go() override;
    virtual int getPower() const override;
    virtual int& getHealthy() override;
    virtual bool isMine() const override;

};


#endif //GAME_TECHPROG_UNIT_H
