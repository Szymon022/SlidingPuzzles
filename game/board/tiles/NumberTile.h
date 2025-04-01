//
// Created by szymon on 3/16/25.
//

#ifndef NUMBERTILE_H
#define NUMBERTILE_H
#include "ValueTile.h"

/**
 * Class representing a tile with natural number associated with it. It is a basic tile in a classic version of n-puzzle game.
 */
class NumberTile : public ValueTile<int> {
public:
    NumberTile() = delete;

    /**
     * @param ordinal ordinal of this tile in a board. ordinal is a value from 0 to n^2-1, where n is the size of the board
     * @param number number that this tile holds
     */
    explicit NumberTile(int ordinal, int number);

    /**
     * @return number held by this tile
     */
    int getValue() const override;
};


#endif //NUMBERTILE_H
