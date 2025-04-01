//
// Created by szymon on 3/16/25.
//

#ifndef VALUETILE_H
#define VALUETILE_H
#include "Tile.h"

/**
 * Base class for tiles that represents tile with associated value like a number or string.
 *
 * @tparam T - Type of value that this tile encapsulates.
 */
template<typename T>
class ValueTile : public Tile {
protected:
    T value;

public:
    ValueTile() = delete;

    /**
     *
     * @param ordinal ordinal of the tile in a board.
     * @param value value that this tile holds
     */
    ValueTile(const int ordinal, const T value): Tile(ordinal), value(value) {
    }

    /**
     *
     * @return value held by this tile.
     */
    virtual T getValue() const = 0;
};

#endif //VALUETILE_H
