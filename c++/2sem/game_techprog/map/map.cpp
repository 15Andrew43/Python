//
// Created by Андрей Боровец on 09.04.2020.
//

#include "map.h"

void Cell::attack(bool is_mine_, const AbstractUnit& unit) {
    for (int i = 0; i < Rival_.size(); ++i) {
        ((unit.isMine()) ? Rival_ : Mine_)[i].getHealthy() -= unit.getPower();
    }
}


Map::Map() {
    array = new Cell* [hight_];
    for (int i = 0; i < hight_; ++i) {
        array[i] = new Cell [width_];
    }
}
Map::~Map() {
    for (int i = 0; i < hight_; ++i) {
        delete[] array[i];
    }
    delete[] array;
}


Cell* Map::operator[] (int i) {
    return array[i];
}