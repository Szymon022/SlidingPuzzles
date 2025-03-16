//
// Created by szymon on 3/16/25.
//

#include "NumberTile.h"

NumberTile::NumberTile(const int ordinal, const int number): ValueTile(ordinal, number) {
}

int NumberTile::getValue() const{
    return value;
}
