//
// Created by szymon on 3/16/25.
//

#ifndef TILE_H
#define TILE_H
#include <stdexcept>


class Tile {
    int ordinal;

public:
    explicit Tile(const int ordinal): ordinal(ordinal) {
        if (ordinal < 0) throw std::invalid_argument("ordinal must be >= 0");
    }

    virtual ~Tile() {
    }

    int getOrdinal() const {
        return ordinal;
    };
};


#endif //TILE_H
