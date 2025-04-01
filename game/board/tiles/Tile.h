//
// Created by szymon on 3/16/25.
//

#ifndef TILE_H
#define TILE_H
#include <stdexcept>

/**
 * Base class representing board tile.
 */
class Tile {
    int ordinal;

public:
    /**
     * @param ordinal ordinal of a tile in a board.
     */
    explicit Tile(const int ordinal): ordinal(ordinal) {
        if (ordinal < 0) throw std::invalid_argument("ordinal must be >= 0");
    }

    virtual ~Tile() {
    }

    /**
     * Returns ordinal of a tile in a board. Ordinal in a 2d board is an index of a tile in a board that is written in a 1d array row-wise.
     * For 3x3 board ordinals are as follows: `[[0, 1, 2], [3, 4, 5], [6, 7, 8]]`, where inner arrays represents subsequent board rows.
     *
     * @return ordinal of a tile in a board.
     */
    int getOrdinal() const {
        return ordinal;
    };
};


#endif //TILE_H
