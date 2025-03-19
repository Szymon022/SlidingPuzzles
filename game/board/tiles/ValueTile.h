//
// Created by szymon on 3/16/25.
//

#ifndef VALUETILE_H
#define VALUETILE_H
#include "Tile.h"

template<typename T>
class ValueTile : public Tile {
protected:
    T value;

public:
    ValueTile() = delete;

    ValueTile(const int ordinal, const T value): Tile(ordinal), value(value) {
    }

    virtual T getValue() const = 0;
};

#endif //VALUETILE_H
